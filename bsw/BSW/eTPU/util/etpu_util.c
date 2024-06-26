/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2012 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
****************************************************************************/
/*!
*
* @file    etpu_util.c
*
* @author  Milan Brejl [r54529]
* 
* @version 3.2
* 
* @date    21-Mar-2014
*
* @brief   This file contains useful functions for using the eTPU and eTPU2.
* 
****************************************************************************/
/*!
*
* 
*
* The eTPU Utilities @ref etpu_util.c/.h includes low-level functions for
* using the eTPU and eTPU2 module. The upper software levels should prevent
* from direct access to eTPU registers by using these utilities.
*
* The included routines can be divided into several groups by application usage:
* -# eTPU Module Initialization
*    - @ref fs_etpu_init
*    - @ref fs_etpu2_init (eTPU2-only)
* -# eTPU Channel Initialization
*    - @ref fs_etpu_chan_init
*    - @ref fs_etpu_malloc
*    - @ref fs_etpu_malloc2
* -# Run-Time eTPU Module Control
*    - @ref fs_timer_start
*    - @ref fs_etpu_get_global_exceptions, @ref fs_etpu_clear_global_exceptions
*    - @ref fs_etpu_get_global_error
*    - @ref fs_etpu_set_interrupt_mask_a, @ref fs_etpu_set_interrupt_mask_b
*    - @ref fs_etpu_set_dma_mask_a, @ref fs_etpu_set_dma_mask_b
*    - @ref fs_etpu_set_output_disable_mask_a, @ref fs_etpu_set_output_disable_mask_b
* -# Run-Time eTPU Channel Control
*    - @ref fs_etpu_get_hsr, @ref fs_etpu_set_hsr
*    - @ref fs_etpu_enable, @ref fs_etpu_disable
*    - @ref fs_etpu_interrupt_enable, @ref fs_etpu_interrupt_disable
*    - @ref fs_etpu_get_chan_interrupt_flag, @ref fs_etpu_clear_chan_interrupt_flag
*    - @ref fs_etpu_dma_enable, @ref fs_etpu_dma_disable
*    - @ref fs_etpu_get_chan_dma_flag, @ref fs_etpu_clear_chan_dma_flag
* -# eTPU DATA RAM Access
*    - @ref fs_etpu_data_ram
*    - @ref fs_etpu_get_chan_local_32, @ref fs_etpu_get_chan_local_24, @ref fs_etpu_get_chan_local_24s, @ref fs_etpu_get_chan_local_16, @ref fs_etpu_get_chan_local_8
*    - @ref fs_etpu_set_chan_local_32, @ref fs_etpu_set_chan_local_24, @ref fs_etpu_set_chan_local_16, @ref fs_etpu_set_chan_local_8
*    - @ref fs_etpu_get_global_32, @ref fs_etpu_get_global_24, @ref fs_etpu_get_global_24s, @ref fs_etpu_get_global_16, @ref fs_etpu_get_global_8
*    - @ref fs_etpu_set_global_32, @ref fs_etpu_set_global_24, @ref fs_etpu_set_global_16, @ref fs_etpu_set_global_8
*    - @ref fs_etpu_coherent_read_32, @ref fs_etpu_coherent_read_24
*    - @ref fs_etpu_coherent_write_32, @ref fs_etpu_coherent_write_24
* -# eTPU Load Evaluation
*    - @ref fs_etpu_get_idle_cnt_a, @ref fs_etpu_clear_idle_cnt_a (eTPU2-only)
*    - @ref fs_etpu_get_idle_cnt_b, @ref fs_etpu_clear_idle_cnt_b (eTPU2-only)
* -# Others
*    - @ref fs_memcpy32, @ref fs_memset32
*
*******************************************************************************/
/*******************************************************************************
* Includes
*******************************************************************************/
#include "etpu_util.h" /* prototypes and useful defines */

/*******************************************************************************
* Global variables
*******************************************************************************/
extern uint32 fs_etpu_code_start;
extern uint32 fs_etpu_data_ram_start;
extern uint32 fs_etpu_data_ram_end;
extern uint32 fs_etpu_data_ram_ext;

/*******************************************************************************
* FUNCTION: fs_etpu_init
****************************************************************************/
/*!
* @brief   This function initializes the eTPU module.
*
* @note    The following actions are performed in order:
*          -# Load eTPU code into code RAM
*          -# Initialize global registers:
*             - Module Control Register
*             - MISC value
*             - Engine Control Registers
*             - TCR pre-scalers
*          -# Copy initial values of global variables to data RAM
*
* @param   p_etpu_config - This is the structure used to initialize the eTPU
* @param   *code - This is a pointer to an image of the eTPU code.
* @param   code_size - This is the size of the eTPU code in bytes.
* @param   *globals - This is a pointer to the global eTPU data that needs
*          to be initialized.
* @param   globals_size - This is the size of the global data in bytes.
*
* @return  Zero or an error code. Error codes that can be returned are:
*          - @ref FS_ETPU_ERROR_CODESIZE - When the code is too big for the
*            available memory
*          - @ref FS_ETPU_ERROR_VIS_BIT_NOT_SET - When the SCM Visibility cannot
*            be set and SCM cannot be written.
*
* @warning This function does not configure the pins, only the eTPU.
*******************************************************************************/
uint32 fs_etpu_init(
    struct etpu_config_t p_etpu_config,
    uint32 *code,
    uint32 code_size,
    uint32 *globals,
    uint32 globals_size)
{
  uint32 *code_end;
  sint32 unused_code_ram;
  sint8 x;

  unused_code_ram = ((eTPU->MCR.B.SCMSIZE + 1) * 2048) - code_size;
  if (unused_code_ram < 0)
    return ((uint32)FS_ETPU_ERROR_CODESIZE);

  /* 1. Load microcode */
  /* In order for the MISC function to work with code that is small than
   * the code memory any unused locations must be set to zero. */
  eTPU->ECR_A.B.MDIS = 1; /* stop eTPU_A */
  eTPU->ECR_B.B.MDIS = 1; /* stop eTPU_B */
  eTPU->MCR.B.VIS = 1;    /* enable CPU writes to eTPU code memory */

  x = 0;
  while (x < 5)
  {
    if (eTPU->MCR.B.VIS == 1)
      break;
    x++;
  }

  if (x > 4)
    return (FS_ETPU_ERROR_VIS_BIT_NOT_SET);

  /* Copy microcode */
  code_end = fs_memcpy32((uint32 *)fs_etpu_code_start, code, code_size);

  /* Clear rest of program memory */
  fs_memset32(code_end, 0, unused_code_ram);

  eTPU->MCR.B.VIS = 0; /* disable CPU writes to eTPU code memory */

  /* Configure MISC */
  eTPU->MISCCMPR.R = p_etpu_config.misc; /*write MISC value before enabled in MCR */
  eTPU->MCR.R = p_etpu_config.mcr;

  /* Configure Engine 1 */
  eTPU->ECR_A.R = p_etpu_config.ecr_a;
  if (eTPU->ECR_A.B.MDIS == 0)
  {
    eTPU->TBCR_A.R = p_etpu_config.tbcr_a;
    eTPU->REDCR_A.R = p_etpu_config.stacr_a;
  }

  /* Configure Engine 2 */
  /* Not all parts have a second eTPU engine, if yes, these write are ignored. */
  eTPU->ECR_B.R = p_etpu_config.ecr_b;
  if (eTPU->ECR_B.B.MDIS == 0)
  {
    eTPU->TBCR_B.R = p_etpu_config.tbcr_b;
    eTPU->REDCR_B.R = p_etpu_config.stacr_b;
  }

  /* 3. Copy initial global values to parameter RAM. */
  fs_free_param = fs_memcpy32((uint32 *)fs_etpu_data_ram_start, globals, globals_size);
  fs_free_param = (uint32 *)((((uint32)fs_free_param + 7) >> 3) << 3); /* round up to 8s */

  return (0);
}

/*******************************************************************************
* FUNCTION: fs_etpu2_init
****************************************************************************/
/*!
* @brief   This function initializes the eTPU2-only setting of an eTPU2 module.
*
* @note    For eTPU2, this function should be called after fs_etpu_init(...).
*          The following actions are performed in order:
*          -# Initialize Watchdog Timer
*          -# Allocate engine-relative data memory for each engine
*
* @param   p_etpu_config - This is the structure used to initialize the eTPU2
*          watchdog timer on both engines.
* @param   engine_mem_size - This is the size of the engine relative data
*          in bytes.
*
* @return  Zero or an error code. Error code that can be returned is:
*          - @ref FS_ETPU_ERROR_MALLOC - When the available free eTPU DATA RAM
*            is not big enough for the engine-relative data.
*
* @warning This function is applicable to eTPU2 only.
*******************************************************************************/
uint32 fs_etpu2_init(
    struct etpu_config_t p_etpu_config,
    uint32 engine_mem_size)
{
  /* 1. Initialize Watchdog Timer. */
  /* Engine A Watchdog */
  eTPU->WDTR_A.R = 0; /* disable first before a new mode is configured */
  eTPU->WDTR_A.R = p_etpu_config.wdtr_a;

  /* Engine B Watchdog */
  /* Not all parts have a second eTPU engine, if don't these writes are ignored. */
  eTPU->WDTR_B.R = 0; /* disable first before a new mode is configured */
  eTPU->WDTR_B.R = p_etpu_config.wdtr_b;

  /* 2. Allocate engine-relative data memory space for each engine. */
  if (engine_mem_size > 0)
  {
    /* Engine A */
    if (eTPU->ECR_A.B.MDIS == 0)
    {
      fs_free_param = (uint32 *)((((uint32)fs_free_param + 511) >> 9) << 9); /* round up to 512s */
      eTPU->ECR_A.B.ERBA = ((uint32)fs_free_param) >> 9;
      fs_memset32(fs_free_param, 0, engine_mem_size);
      fs_free_param = (uint32 *)((uint32)fs_free_param + engine_mem_size);
    }
    /* Engine B */
    if (eTPU->ECR_B.B.MDIS == 0)
    {
      fs_free_param = (uint32 *)((((uint32)fs_free_param + 511) >> 9) << 9); /* round up to 512s */
      eTPU->ECR_B.B.ERBA = ((uint32)fs_free_param) >> 9;
      fs_memset32(fs_free_param, 0, engine_mem_size);
      fs_free_param = (uint32 *)((uint32)fs_free_param + engine_mem_size);
    }
  }
  fs_free_param = (uint32 *)((((uint32)fs_free_param + 7) >> 3) << 3); /* round up to 8s */

  if ((uint32)fs_free_param > fs_etpu_data_ram_end)
    return (FS_ETPU_ERROR_MALLOC);
  else
    return (0);
}

/*******************************************************************************
* FUNCTION: fs_etpu_chan_init
****************************************************************************/
/*!
* @brief   This function initializes an eTPU channel.
*
* @param   channel - The eTPU channel number
* @param   functions - The eTPU function number
* @param   mode - The eTPU function mode (FM bits)
* @param   hsr - The eTPU function initialization Host Service Request
* @param   num_param - The number of 32-bit eTPU function parameters
* @param   config - The eTPU function configuration register settings, e.g.
*          - @ref FS_ETPU_ENTRY_TABLE_STANDARD (default) or
*          - @ref FS_ETPU_ENTRY_TABLE_ALTERNATE
*          - @ref FS_ETPU_ENTRY_TABLE_PIN_INPUT (default) or
*          - @ref FS_ETPU_ENTRY_TABLE_PIN_OUTPUT (N/A on MCF523x and MPC5554)
* @param   *func_frame - The base address of the allocated eTPU channel DATA RAM.
*          If assigned by 0, the DATA RAM of num_param size is allocated.
*
* @return  A pointer to the start of the eTPU DATA RAM allocated for the channel
*          or an error code. Error code that can be returned is:
*          - @ref FS_ETPU_ERROR_MALLOC - When the available DATA RAM
*              is not big enough for the channel data.
*******************************************************************************/
uint32 *fs_etpu_chan_init(
    uint8 channel,
    uint8 function,
    uint8 mode,
    uint8 hsr,
    uint8 num_param,
    uint32 config,
    uint32 *func_frame)
{
  if (func_frame == 0)
  {
    func_frame = fs_etpu_malloc((uint16)(num_param << 2));
    if (func_frame == 0)
      return ((uint32 *)FS_ETPU_ERROR_MALLOC);
  }

  eTPU->CHAN[channel].CR.R = config + (function << 16) + (((uint32)func_frame - fs_etpu_data_ram_start) >> 3);
  eTPU->CHAN[channel].SCR.R = mode;
  eTPU->CHAN[channel].HSRR.R = hsr;

  return (func_frame);
}

/*******************************************************************************
* FUNCTION: fs_etpu_data_ram
****************************************************************************/
/*!
* @brief   This function returns a pointer to the start of the data RAM for
*            the specified channel.
*
* @param   channel - The eTPU channel number
*
* @return  A pointer to the start of the eTPU DATA RAM allocated for the channel
*
* @warning This function does no error checking. If the channel has not been
*          initialized then an undefined value will be returned (normally 0).
******************************************************************************/
uint32 *fs_etpu_data_ram(
    uint8 channel)
{
  return ((uint32 *)((uint8 *)fs_etpu_data_ram_start + (eTPU->CHAN[channel].CR.B.CPBA << 3)));
}

/*******************************************************************************
* FUNCTION: fs_etpu_set_hsr
****************************************************************************/
/*!
* @brief   This function sets the Host Service Request (HSR) register of the
*          specified eTPU channel.
*
* @param   channel - The eTPU channel number
* @param   hsr - The HSR value to send to the channel
*
* @warning The application should check that the HSR field is 0 before calling
*          this routine. If the HSR field is not 0 then the 2 values will be
*          ORed together.
*******************************************************************************/
void fs_etpu_set_hsr(
    uint8 channel,
    uint8 hsr)
{
  eTPU->CHAN[channel].HSRR.R = hsr;
}

/*******************************************************************************
* FUNCTION: fs_etpu_get_hsr
****************************************************************************/
/*!
* @brief   This function returns the current value of the Host Service Request
*          (HSR) register of the specified eTPU channel.
*
* @param   channel - The eTPU channel number
*
* @return  The value of HSR register
*******************************************************************************/
uint8 fs_etpu_get_hsr(
    uint8 channel)
{
  return ((uint8)eTPU->CHAN[channel].HSRR.R);
}

/*******************************************************************************
* FUNCTION: fs_etpu_enable
****************************************************************************/
/*!
* @brief   This function enables or changes the priority of an eTPU channel.
*
* @param   channel - The eTPU channel number
* @param   priority - The priority to be assigned to the channel. This should
*            be assigned a value of
*            - @ref FS_ETPU_PRIORITY_HIGH,
*            - @ref FS_ETPU_PRIORITY_MIDDLE, or
*            - @ref FS_ETPU_PRIORITY_LOW
*******************************************************************************/
void fs_etpu_enable(
    uint8 channel,
    uint8 priority)
{
  eTPU->CHAN[channel].CR.B.CPR = priority;
}

/*******************************************************************************
* FUNCTION: fs_etpu_disable
****************************************************************************/
/*!
* @brief   This function disables an eTPU channel.
*
* @param   channel - The eTPU channel number
*
* @warning If the channel is currently being serviced then the service will
*          complete.
*******************************************************************************/
void fs_etpu_disable(
    uint8 channel)
{
  eTPU->CHAN[channel].CR.B.CPR = FS_ETPU_PRIORITY_DISABLE;
}

/*******************************************************************************
* FUNCTION: fs_etpu_interrupt_enable
****************************************************************************/
/*!
* @brief   This function enables an eTPU channel to generate interrupts.
*
* @param   channel - The eTPU channel number
*
* @warning This enables the eTPU to send interrupts to an interrupt
*          controller. Additional configuration may be required for
*          the CPU to receive the interrupts.
*******************************************************************************/
void fs_etpu_interrupt_enable(
    uint8 channel)
{
  eTPU->CHAN[channel].CR.B.CIE = TRUE;
}

/*******************************************************************************
* FUNCTION: fs_etpu_interrupt_disable
****************************************************************************/
/*!
* @brief   This function disables an eTPU channel from generating interrupts.
*
* @param   channel - The eTPU channel number
*
* @warning When interrupts are disabled the eTPU interrupt status bits are
*          still set and can be used to poll the interrupt status.
*******************************************************************************/
void fs_etpu_interrupt_disable(
    uint8 channel)
{
  eTPU->CHAN[channel].CR.B.CIE = FALSE;
}

/*******************************************************************************
* FUNCTION: fs_etpu_dma_enable
****************************************************************************/
/*!
* @brief   This function enables an eTPU channel to request DMA service.
*
* @param   channel - The eTPU channel number
*
* @warning In a given device not all of the DMA requests may be connected
*          to DMA channels.
*******************************************************************************/
void fs_etpu_dma_enable(
    uint8 channel)
{
  eTPU->CHAN[channel].CR.B.DTRE = TRUE;
}

/*******************************************************************************
* FUNCTION: fs_etpu_dma_disable
****************************************************************************/
/*!
* @brief   This function disables an eTPU channel from generating DMA requests.
*
* @param   channel - The eTPU channel number
*
* @warning When DMA requests are disabled the eTPU DMA request status bits are
*          still set and can be used to poll the DMA request status.
*******************************************************************************/
void fs_etpu_dma_disable(
    uint8 channel)
{
  eTPU->CHAN[channel].CR.B.DTRE = FALSE;
}

/*******************************************************************************
* FUNCTION: fs_timer_start
****************************************************************************/
/*!
* @brief   This function starts the timebases.
*
* @note    This functions synchronously starts the timebases of all timer
*          modules on a device.
*
* @param   channel - The eTPU channel number
*******************************************************************************/
void fs_timer_start(void)
{
  eTPU->MCR.B.GTBE = TRUE;
}

/*******************************************************************************
* FUNCTION: fs_etpu_malloc
****************************************************************************/
/*!
* @brief   This function allocates DATA RAM (parameter RAM) for a channel.
*
* @param   num_bytes - this is the number of bytes that is required to
*          allocate in DATA RAM.
*
* @return  A pointer to allocated DATA RAM. If the requested amount of memory
*          is larger than the available amount of memory then 0 is returned.
*
* @warning This function is non-reentrant and uses the @ref fs_free_param global.
*          The granularity of eTPU DATA RAM allocation for channel parameters
*          is 8 bytes. The requested size is enlarged to a multiple of 8 bytes.
*******************************************************************************/
uint32 *fs_etpu_malloc(
    uint16 num_bytes)
{
  uint32 *pba;

  pba = fs_free_param;
  fs_free_param += (((num_bytes + 7) >> 3) << 1);

  if (fs_free_param > (uint32 *)fs_etpu_data_ram_end)
    return (0);
  else
    return (pba);
}

/*******************************************************************************
* FUNCTION: fs_etpu_malloc2
****************************************************************************/
/*!
* @brief   This function allocates DATA RAM for a channel if it has not been
*          allocated before.
*
* @note    This function is similar to fs_etpu_malloc. The difference is
*          that this function first checks to see if the CPBA is not zero.
*          If it is not zero then it assumes the channel has already been
*          initialized and does not allocate more data RAM to the channel.
*
* @param   channel - The eTPU channel number
* @param   num_bytes - this is the number of bytes that is required to
*          allocate in DATA RAM.
*
* @return  A pointer to allocated DATA RAM. If the requested amount of memory
*          is larger than the available amount of memory then 0 is returned.
*
* @warning The granularity of eTPU DATA RAM allocation for channel parameters
*          is 8 bytes. The requested size is enlarged to a multiple of 8 bytes.
*******************************************************************************/
uint32 *fs_etpu_malloc2(
    uint8 channel,
    uint16 num_bytes)
{
  uint32 *pba;

  if (eTPU->CHAN[channel].CR.B.CPBA == 0)
  {
    pba = fs_free_param;
    fs_free_param += (((num_bytes + 7) >> 3) << 1);

    if (fs_free_param > (uint32 *)fs_etpu_data_ram_end)
      return (0);
    else
      return (pba);
  }
  else
  {
    return (fs_etpu_data_ram(channel));
  }
}

/* set local variables */
/*******************************************************************************
* FUNCTION: fs_etpu_set_chan_local_32
****************************************************************************/
/*!
* @brief   This function sets a 32-bit parameter for an eTPU channel.
*
* @param   channel - The eTPU channel number
* @param   offset - The byte offset to the parameter. This must be a 32-bit
*          aligned value. This value is normally provided by the eTPU compiler.
* @param   value - The value to write to the parameter
*******************************************************************************/
void fs_etpu_set_chan_local_32(
    uint8 channel,
    uint32 offset,
    uint32 value)
{
  *(uint32 *)((uint32)fs_etpu_data_ram_start + (eTPU->CHAN[channel].CR.B.CPBA << 3) + offset) = value;
}

/*******************************************************************************
* FUNCTION: fs_etpu_set_chan_local_24
****************************************************************************/
/*!
* @brief   This function sets a 24-bit parameter for an eTPU channel.
*
* @note    This function uses the sign extended location of the data memory
*          to write only 24 bits to the data memory. This 24 bit write is
*          an atomic operation and does not effect the upper 8 bits of the
*          32 bit value associated with the 24 bits
*
* @param   channel - The eTPU channel number
* @param   offset - The byte offset to the parameter. This must be a 24-bit
*          aligned value. This value is normally provided by the eTPU compiler.
* @param   value - The value to write to the parameter
*******************************************************************************/
void fs_etpu_set_chan_local_24(
    uint8 channel,
    uint32 offset,
    uint24_t value)
{
  *(uint32 *)((uint32)fs_etpu_data_ram_ext + (eTPU->CHAN[channel].CR.B.CPBA << 3) + offset - 1) = value;
}

/*******************************************************************************
* FUNCTION: fs_etpu_set_chan_local_16
****************************************************************************/
/*!
* @brief   This function sets a 16-bit parameter for an eTPU channel.
*
* @param   channel - The eTPU channel number
* @param   offset - The byte offset to the parameter. This must be a 16-bit
*          aligned value. This value is normally provided by the eTPU compiler.
* @param   value - The value to write to the parameter
*******************************************************************************/
void fs_etpu_set_chan_local_16(
    uint8 channel,
    uint32 offset,
    uint16 value)
{
  *(uint16 *)((uint32)fs_etpu_data_ram_start + (eTPU->CHAN[channel].CR.B.CPBA << 3) + offset) = value;
}

/*******************************************************************************
* FUNCTION: fs_etpu_set_chan_local_8
****************************************************************************/
/*!
* @brief   This function sets an 8-bit parameter for an eTPU channel.
*
* @param   channel - The eTPU channel number
* @param   offset - The byte offset to the parameter. This value is normally
*          provided by the eTPU compiler.
* @param   value - The value to write to the parameter
*******************************************************************************/
void fs_etpu_set_chan_local_8(
    uint8 channel,
    uint32 offset,
    uint8 value)
{
  *(uint8 *)((uint32)fs_etpu_data_ram_start + (eTPU->CHAN[channel].CR.B.CPBA << 3) + offset) = value;
}

/* get local variables */
/*******************************************************************************
* FUNCTION: fs_etpu_get_chan_local_32
****************************************************************************/
/*!
* @brief   This function reads a 32-bit parameter from an eTPU channel..
*
* @param   channel - The eTPU channel number
* @param   offset - The byte offset to the parameter. This must be a 32-bit
*          aligned value. This value is normally provided by the eTPU compiler.
*
* @return  The 32-bit value of the parameter.
*******************************************************************************/
uint32 fs_etpu_get_chan_local_32(
    uint8 channel,
    uint32 offset)
{
  return (*(uint32 *)((uint32)fs_etpu_data_ram_start + (eTPU->CHAN[channel].CR.B.CPBA << 3) + offset));
}

/*******************************************************************************
* FUNCTION: fs_etpu_get_chan_local_24s
****************************************************************************/
/*!
* @brief   This function reads a signed 24-bit parameter from an eTPU channel.
*
* @note    This function uses the sign extended area of the DATA RAM.
*
* @param   channel - The eTPU channel number
* @param   offset - The byte offset to the parameter. This must be a 24-bit
*          aligned value. This value is normally provided by the eTPU compiler.
*
* @return  The signed 24-bit value of the parameter.
*******************************************************************************/
int24_t fs_etpu_get_chan_local_24s(
    uint8 channel,
    uint32 offset)
{
  return (*(sint32 *)((uint32)fs_etpu_data_ram_ext + (eTPU->CHAN[channel].CR.B.CPBA << 3) + offset - 1));
}

/*******************************************************************************
* FUNCTION: fs_etpu_get_chan_local_24
****************************************************************************/
/*!
* @brief   This function reads a unsigned 24-bit parameter from an eTPU channel.
*
* @param   channel - The eTPU channel number
* @param   offset - The byte offset to the parameter. This must be a 24-bit
*          aligned value. This value is normally provided by the eTPU compiler.
*
* @return  The unsigned 24-bit value of the parameter.
*******************************************************************************/
uint24_t fs_etpu_get_chan_local_24(
    uint8 channel,
    uint32 offset)
{
  return (0x00FFFFFF & (*(uint32 *)((uint32)fs_etpu_data_ram_start + (eTPU->CHAN[channel].CR.B.CPBA << 3) + offset - 1)));
}

/*******************************************************************************
* FUNCTION: fs_etpu_get_chan_local_16
****************************************************************************/
/*!
* @brief   This function reads a 16-bit parameter from an eTPU channel.
*
* @param   channel - The eTPU channel number
* @param   offset - The byte offset to the parameter. This must be a 16-bit
*          aligned value. This value is normally provided by the eTPU compiler.
*
* @return  The 16-bit value of the parameter.
*******************************************************************************/
uint16 fs_etpu_get_chan_local_16(
    uint8 channel,
    uint32 offset)
{
  return (*(uint16 *)((uint32)fs_etpu_data_ram_start + (eTPU->CHAN[channel].CR.B.CPBA << 3) + offset));
}

/*******************************************************************************
* FUNCTION: fs_etpu_get_chan_local_8
****************************************************************************/
/*!
* @brief   This function reads an 8-bit parameter from an eTPU channel.
*
* @param   channel - The eTPU channel number
* @param   offset - The byte offset to the parameter. This value is normally
*          provided by the eTPU compiler.
*
* @return  The 8-bit value of the parameter.
*******************************************************************************/
uint8 fs_etpu_get_chan_local_8(
    uint8 channel,
    uint32 offset)
{
  return (*(uint8 *)((uint32)fs_etpu_data_ram_start + (eTPU->CHAN[channel].CR.B.CPBA << 3) + offset));
}

/* set global variables */
/*******************************************************************************
* FUNCTION: fs_etpu_set_global_32
****************************************************************************/
/*!
* @brief   This function writes to a 32-bit global variable.
*
* @param   offset - The byte offset to the variable. This must be a 32-bit
*          aligned value. This value is normally provided by the eTPU compiler.
* @param   value - The value to write to the parameter
*******************************************************************************/
void fs_etpu_set_global_32(
    uint32 offset,
    uint32 value)
{
  *(uint32 *)((uint32)fs_etpu_data_ram_start + offset) = value;
}

/*******************************************************************************
* FUNCTION: fs_etpu_set_global_24
****************************************************************************/
/*!
* @brief   This function writes to a 24-bit global variable.
*
* @param   offset - The byte offset to the variable. This must be a 24-bit
*          aligned value. This value is normally provided by the eTPU compiler.
* @param   value - The value to write to the parameter
*******************************************************************************/
void fs_etpu_set_global_24(
    uint32 offset,
    uint24_t value)
{
  *(uint32 *)((uint32)fs_etpu_data_ram_ext + offset - 1) = value;
}

/*******************************************************************************
* FUNCTION: fs_etpu_set_global_16
****************************************************************************/
/*!
* @brief   This function writes to a 16-bit global variable.
*
* @param   offset - The byte offset to the variable. This must be a 16-bit
*          aligned value. This value is normally provided by the eTPU compiler.
* @param   value - The value to write to the parameter
*******************************************************************************/
void fs_etpu_set_global_16(
    uint32 offset,
    uint16 value)
{
  *(uint16 *)((uint32)fs_etpu_data_ram_start + offset) = value;
}

/*******************************************************************************
* FUNCTION: fs_etpu_set_global_8
****************************************************************************/
/*!
* @brief   This function writes to an 8-bit global variable.
*
* @param   offset - The byte offset to the variable. This value is normally
*          provided by the eTPU compiler.
* @param   value - The value to write to the parameter
*******************************************************************************/
void fs_etpu_set_global_8(
    uint32 offset,
    uint8 value)
{
  *(uint8 *)((uint32)fs_etpu_data_ram_start + offset) = value;
}

/* get global variables */
/*******************************************************************************
* FUNCTION: fs_etpu_get_global_32
****************************************************************************/
/*!
* @brief   This function reads a 32-bit global variable.
*
* @param   offset - The byte offset to the variable. This must be a 32-bit
*          aligned value. This value is normally provided by the eTPU compiler.
*
* @return  The 32-bit value of the variable.
*******************************************************************************/
uint32 fs_etpu_get_global_32(
    uint32 offset)
{
  return (*(uint32 *)((uint32)fs_etpu_data_ram_start + offset));
}

/*******************************************************************************
* FUNCTION: fs_etpu_get_global_24s
****************************************************************************/
/*!
* @brief   This function reads a signed 24-bit global variable.
*
* @note    This function uses the sign extended area of the DATA RAM.
*
* @param   offset - The byte offset to the variable. This must be a 24-bit
*          aligned value. This value is normally provided by the eTPU compiler.
*
* @return  The signed 24-bit value of the variable.
*******************************************************************************/
int24_t fs_etpu_get_global_24s(
    uint32 offset)
{
  return (*(sint32 *)((uint32)fs_etpu_data_ram_ext + offset - 1));
}

/*******************************************************************************
* FUNCTION: fs_etpu_get_global_24
****************************************************************************/
/*!
* @brief   This function reads an unsigned 24-bit global variable.
*
* @param   offset - The byte offset to the variable. This must be a 24-bit
*          aligned value. This value is normally provided by the eTPU compiler.
*
* @return  The unsigned 24-bit value of the variable.
*******************************************************************************/
uint24_t fs_etpu_get_global_24(
    uint32 offset)
{
  return (0x00FFFFFF & (*(uint32 *)((uint32)fs_etpu_data_ram_start + offset - 1)));
}

/*******************************************************************************
* FUNCTION: fs_etpu_get_global_16
****************************************************************************/
/*!
* @brief   This function reads a 16-bit global variable.
*
* @param   offset - The byte offset to the variable. This must be a 16-bit
*          aligned value. This value is normally provided by the eTPU compiler.
*
* @return  The 16-bit value of the variable.
*******************************************************************************/
uint16 fs_etpu_get_global_16(
    uint32 offset)
{
  return (*(uint16 *)((uint32)fs_etpu_data_ram_start + offset));
}

/*******************************************************************************
* FUNCTION: fs_etpu_get_global_8
****************************************************************************/
/*!
* @brief   This function reads an 8-bit global variable.
*
* @param   offset - The byte offset to the variable. This value is normally
*          provided by the eTPU compiler.
*
* @return  The 8-bit value of the variable.
*******************************************************************************/
uint8 fs_etpu_get_global_8(
    uint32 offset)
{
  return (*(uint8 *)((uint32)fs_etpu_data_ram_start + offset));
}

/*******************************************************************************
* FUNCTION: fs_memcpy32
****************************************************************************/
/*!
* @brief   This function is similar to the standard C memset() function
*          however it sets 32-bit words rather than bytes.
*
* @param   *dest - The pointer to the destination location
* @param   *source - The pointer to the source location
* @param   size - The size of the data to copy in bytes
*
* @return  A pointer to the end of the copied data.
*
* @warning The *dest and *source pointers should be aligned to a 32-bit
*          address. If they are not it may cause memory exceptions. Moving
*          data to the eTPU code memory that is not 32-bit aligned is
*          undefined. The size should be a multiple of 4. If it is not
*          it is rounded down.
*******************************************************************************/
uint32 *fs_memcpy32(
    uint32 *dest,
    uint32 *source,
    uint32 size)
{
  uint32 *p = dest;
  uint32 *q = source;

  size = size >> 2;

  while (size--)
  {
    *p++ = *q++;
  }

  return (p);
}

/*******************************************************************************
* FUNCTION: fs_memset32
****************************************************************************/
/*!
* @brief   This function is similar to the standard C memcpy() function
*          however it copies 32-bit words rather than bytes.
*
* @param   *start - The pointer to the start location
* @param   *value - The value to write to memory
* @param   size - The size of the data to set in bytes
*
* @warning The *start pointers should be aligned to a 32-bit address.
*          If it is not it may cause memory exceptions. Writing
*          data to the eTPU code memory that is not 32-bit aligned is
*          undefined. The size should be a multiple of 4. If it is not
*          it is rounded down.
*******************************************************************************/
void fs_memset32(
    uint32 *start,
    uint32 value,
    sint32 size)
{
  uint32 *p = start;

  size = size >> 2;

  while (size--)
  {
    *p++ = value;
  }
}

/*******************************************************************************
* FUNCTION: fs_etpu_set_interrupt_mask_a
****************************************************************************/
/*!
* @brief   This function enables or disables channel interrupt for each engine A
*          channel according to the given mask.
*
* @param   mask - The interrupt enable mask. A value of: 
*          - 0x00000001 enables interrupt on channel 0 only,
*          - 0x80000000 enables interrupt on channel 31 only
*******************************************************************************/
void fs_etpu_set_interrupt_mask_a(
    uint32 mask)
{
  eTPU->CIER_A.R = mask;
}

/*******************************************************************************
* FUNCTION: fs_etpu_set_interrupt_mask_b
****************************************************************************/
/*!
* @brief   This function enables or disables channel interrupt for each engine B
*          channel according to the given mask.
*
* @param   mask - The interrupt enable mask. A value of: 
*          - 0x00000001 enables interrupt on channel 64 only,
*          - 0x80000000 enables interrupt on channel 95 only
*******************************************************************************/
void fs_etpu_set_interrupt_mask_b(
    uint32 mask)
{
  eTPU->CIER_B.R = mask;
}

/*******************************************************************************
* FUNCTION: fs_etpu_set_dma_mask_a
****************************************************************************/
/*!
* @brief   This function enables or disables channel DMA request for each engine
*          A channel according to the given mask.
*
* @param   mask - The DMA enable mask. A value of: 
*          - 0x00000001 enables DMA requests on channel 0 only,
*          - 0x80000000 enables DMA requests on channel 31 only
*******************************************************************************/
void fs_etpu_set_dma_mask_a(
    uint32 mask)
{
  eTPU->CDTRER_A.R = mask;
}

/*******************************************************************************
* FUNCTION: fs_etpu_set_dma_mask_b
****************************************************************************/
/*!
* @brief   This function enables or disables channel DMA request for each engine
*          B channel according to the given mask.
*
* @param   mask - The DMA enable mask. A value of: 
*          - 0x00000001 enables DMA requests on channel 64 only,
*          - 0x80000000 enables DMA requests on channel 95 only
*******************************************************************************/
void fs_etpu_set_dma_mask_b(
    uint32 mask)
{
  eTPU->CDTRER_B.R = mask;
}

/*******************************************************************************
* FUNCTION: fs_etpu_set_output_disable_mask_a
****************************************************************************/
/*!
* @brief   This function enables or disables the channel "output disable"
*          feature for each engine A channel according to the given mask and 
*          polarity.
*
* @param   mask - The "output disable" enable mask. A value of: 
*          - 0x00000001 enables the "output disable" feature on channel 0 only,
*          - 0x80000000 enables the "output disable" feature on channel 31 only
* @param   polarity - The "output disable" polarity mask. A value of: 
*          - 0x00000001 sets the high polarity of disabled output on channel 0
*            and low polarity of disabled output on all other channels 
*******************************************************************************/
void fs_etpu_set_output_disable_mask_a(
    uint32 mask,
    uint32 polarity)
{
  uint8 i;

  for (i = 0; i < 32; i++)
  {
    eTPU->CHAN[i].CR.B.ODIS = mask & 0x00000001;
    eTPU->CHAN[i].CR.B.OPOL = polarity & 0x00000001;
    mask >>= 1;
    polarity >>= 1;
  }
}

/*******************************************************************************
* FUNCTION: fs_etpu_set_output_disable_mask_b
****************************************************************************/
/*!
* @brief   This function enables or disables the channel "output disable"
*          feature for each engine B channel according to the given mask and 
*          polarity.
*
* @param   mask - The "output disable" enable mask. A value of: 
*          - 0x00000001 enables the "output disable" feature on channel 64 only,
*          - 0x80000000 enables the "output disable" feature on channel 95 only
* @param   polarity - The "output disable" polarity mask. A value of: 
*          - 0x00000001 sets the high polarity of disabled output on channel 64
*            and low polarity of disabled output on all other channels 
*******************************************************************************/
void fs_etpu_set_output_disable_mask_b(
    uint32 mask,
    uint32 polarity)
{
  uint8 i;

  for (i = 64; i < 96; i++)
  {
    eTPU->CHAN[i].CR.B.ODIS = mask & 0x00000001;
    eTPU->CHAN[i].CR.B.OPOL = polarity & 0x00000001;
    mask >>= 1;
    polarity >>= 1;
  }
}

/*******************************************************************************
* FUNCTION: fs_etpu_get_chan_interrupt_flag
****************************************************************************/
/*!
* @brief   This function returns the current value of the Channel Interrupt
*          Status bit of the specified eTPU channel.
*
* @param   channel - The eTPU channel number
*
* @return  Value of CIS bit of the specified channel SCR register.
*******************************************************************************/
uint8 fs_etpu_get_chan_interrupt_flag(
    uint8 channel)
{
  return ((uint8)eTPU->CHAN[channel].SCR.B.CIS);
}

/*******************************************************************************
* FUNCTION: fs_etpu_clear_chan_interrupt_flag
****************************************************************************/
/*!
* @brief   This function clears the channel interrupt flag.
*
* @param   channel - The eTPU channel number
*******************************************************************************/
void fs_etpu_clear_chan_interrupt_flag(
    uint8 channel)
{
  if (channel < 32)
  {
    eTPU->CISR_A.R = 1 << channel;
  }
  else
  {
    eTPU->CISR_B.R = 1 << (channel - 64);
  }
}

/*******************************************************************************
* FUNCTION: fs_etpu_get_chan_interrupt_oveflow_flag
****************************************************************************/
/*!
* @brief   This function returns the current value of the Channel Interrupt
*          Overflow Status bit of the specified eTPU channel.
*
* @param   channel - The eTPU channel number
*
* @return  Value of CIOS bit of the specified channel SCR register.
*******************************************************************************/
uint8 fs_etpu_get_chan_interrupt_oveflow_flag(
    uint8 channel)
{
  return ((uint8)eTPU->CHAN[channel].SCR.B.CIOS);
}

/*******************************************************************************
* FUNCTION: fs_etpu_clear_chan_interrupt_overflow_flag
****************************************************************************/
/*!
* @brief   This function clears the channel interrupt oveflow flag.
*
* @param   channel - The eTPU channel number
*******************************************************************************/
void fs_etpu_clear_chan_interrupt_overflow_flag(
    uint8 channel)
{
  if (channel < 32)
  {
    eTPU->CIOSR_A.R = 1 << channel;
  }
  else
  {
    eTPU->CIOSR_B.R = 1 << (channel - 64);
  }
}

/*******************************************************************************
* FUNCTION: fs_etpu_get_chan_dma_flag
****************************************************************************/
/*!
* @brief   This function returns the current value of the Data Transfer Request
*          Status bit of the specified eTPU channel.
*
* @param   channel - The eTPU channel number
*
* @return  Value of DTRS bit of the specified channel SCR register.
*******************************************************************************/
uint8 fs_etpu_get_chan_dma_flag(
    uint8 channel)
{
  return ((uint8)eTPU->CHAN[channel].SCR.B.DTRS);
}

/*******************************************************************************
* FUNCTION: fs_etpu_clear_chan_dma_flag
****************************************************************************/
/*!
* @brief   This function clears the channel data transfer request flag.
*
* @param   channel - The eTPU channel number
*******************************************************************************/
void fs_etpu_clear_chan_dma_flag(
    uint8 channel)
{
  if (channel < 32)
  {
    eTPU->CDTRSR_A.R = 1 << channel;
  }
  else
  {
    eTPU->CDTRSR_B.R = 1 << (channel - 64);
  }
}

/*******************************************************************************
* FUNCTION: fs_etpu_get_chan_dma_oveflow_flag
****************************************************************************/
/*!
* @brief   This function returns the current value of the Data Transfer Request
*          Oveflow Status bit of the specified eTPU channel.
*
* @param   channel - The eTPU channel number
*
* @return  Value of DTROS bit of the specified channel SCR register.
*******************************************************************************/
uint8 fs_etpu_get_chan_dma_oveflow_flag(
    uint8 channel)
{
  return ((uint8)eTPU->CHAN[channel].SCR.B.DTROS);
}

/*******************************************************************************
* FUNCTION: fs_etpu_clear_chan_dma_oveflow_flag
****************************************************************************/
/*!
* @brief   This function clears the channel data transfer request oveflow flag.
*
* @param   channel - The eTPU channel number
*******************************************************************************/
void fs_etpu_clear_chan_dma_oveflow_flag(
    uint8 channel)
{
  if (channel < 32)
  {
    eTPU->CDTROSR_A.R = 1 << channel;
  }
  else
  {
    eTPU->CDTROSR_B.R = 1 << (channel - 64);
  }
}

/*******************************************************************************
* FUNCTION: fs_etpu_get_global_exceptions
****************************************************************************/
/*!
* @brief   This function returns the global exception flags.
*
* @note    This function can be used after eTPU global exception interrupt.
*          This function enables to decode the source of the global exception.
*
* @param   channel - The eTPU channel number
*
* @return  The returned value can include the following exception bits:
*          - @ref FS_ETPU_SDM_READ_ERROR
*          - @ref FS_ETPU_WATCHDOG_TIMEOUT_A
*          - @ref FS_ETPU_WATCHDOG_TIMEOUT_B
*          - @ref FS_ETPU_MICROCODE_GLOBAL_EX_A
*          - @ref FS_ETPU_MICROCODE_GLOBAL_EX_B
*          - @ref FS_ETPU_ILLEGAL_INSTRUCTION_A
*          - @ref FS_ETPU_ILLEGAL_INSTRUCTION_B
*          - @ref FS_ETPU_SHARED_SUBSYS_ACC_ERR
*          - @ref FS_ETPU_SCM_MISC_FLAG
*          - @ref FS_ETPU_SCM_READ_ERROR
*******************************************************************************/
uint32 fs_etpu_get_global_exceptions(void)
{
  return (eTPU->MCR.R & (FS_ETPU_SDM_READ_ERROR | FS_ETPU_WATCHDOG_TIMEOUT_A | FS_ETPU_WATCHDOG_TIMEOUT_B | FS_ETPU_MICROCODE_GLOBAL_EX_A | FS_ETPU_MICROCODE_GLOBAL_EX_B | FS_ETPU_ILLEGAL_INSTRUCTION_A | FS_ETPU_ILLEGAL_INSTRUCTION_B | FS_ETPU_SHARED_SUBSYS_ACC_ERR | FS_ETPU_SCM_MISC_FLAG | FS_ETPU_SCM_READ_ERROR));
}

/*******************************************************************************
* FUNCTION: fs_etpu_clear_global_exceptions
****************************************************************************/
/*!
* @brief   This function clears all eTPU global exceptions.
*******************************************************************************/
void fs_etpu_clear_global_exceptions(void)
{
  eTPU->MCR.B.GEC = 1;
}

/*******************************************************************************
* FUNCTION: fs_etpu_get_global_error
****************************************************************************/
/*!
* @brief   This function reads the Global Error value from eTPU DATA RAM,
*          which is used by Freescale eTPU functions to reports unhandled
*          events.
*
* @return  The 32-bit value of the Global Error is returned.
*          The Global Error value includes 2 fields.
*          Under @ref FS_ETPU_GLOBAL_ERROR_CHANNEL_MASK there is the channel
*          number of the channel where the unhandled event occurred.
*          Under FS_ETPU_GLOBAL_ERROR_EVENT_MASK there is the event condition
*          which may include one or more the following bits:
*          - @ref FS_ETPU_GLOBAL_ERROR_EVENT_LSR
*          - @ref FS_ETPU_GLOBAL_ERROR_EVENT_MRLA
*          - @ref FS_ETPU_GLOBAL_ERROR_EVENT_MRLB
*          - @ref FS_ETPU_GLOBAL_ERROR_EVENT_TDLA
*          - @ref FS_ETPU_GLOBAL_ERROR_EVENT_TDLB
*          - @ref FS_ETPU_GLOBAL_ERROR_EVENT_PSS
*          - @ref and for eTPU2 only also
*          - @ref FS_ETPU_GLOBAL_ERROR_EVENT_FLAG0
*          - @ref FS_ETPU_GLOBAL_ERROR_EVENT_FLAG1
*******************************************************************************/
uint32 fs_etpu_get_global_error(void)
{
#ifdef FS_ETPU_OFFSET_GLOBAL_ERROR
  return (*(uint32 *)((uint32)fs_etpu_data_ram_start + FS_ETPU_OFFSET_GLOBAL_ERROR));
#else /* presume the Global Error is at address 0, which is the case of all set1-set4 */
  return (*(uint32 *)((uint32)fs_etpu_data_ram_start));
#endif
}

/*******************************************************************************
* FUNCTION: fs_etpu_get_idle_cnt_a
****************************************************************************/
/*!
* @brief   This function returns the current value of engine A Idle Count
*          Register.
*
* @return  The 32-bit number of the idle microinstruction cycles is returned.
*
* @warning This function is applicable to eTPU2 only.
*******************************************************************************/
uint24_t fs_etpu_get_idle_cnt_a(void)
{
  return (eTPU->IDLE_A.R);
}

/*******************************************************************************
* FUNCTION: fs_etpu_get_idle_cnt_b
****************************************************************************/
/*!
* @brief   This function returns the current value of engine B Idle Count
*          Register.
*
* @return  The 32-bit number of the idle microinstruction cycles is returned.
*
* @warning This function is applicable to eTPU2 only.
*******************************************************************************/
uint24_t fs_etpu_get_idle_cnt_b(void)
{
  return (eTPU->IDLE_B.R);
}

/*******************************************************************************
* FUNCTION: fs_etpu_clear_idle_cnt_a
****************************************************************************/
/*!
* @brief   This function clears the engine A Idle Count Register.
*
* @warning This function is applicable to eTPU2 only.
*******************************************************************************/
void fs_etpu_clear_idle_cnt_a(void)
{
  eTPU->IDLE_A.B.ICLR = 1;
}

/*******************************************************************************
* FUNCTION: fs_etpu_clear_idle_cnt_b
****************************************************************************/
/*!
* @brief   This function clears the engine B Idle Count Register.
*
* @warning This function is applicable to eTPU2 only.
*******************************************************************************/
void fs_etpu_clear_idle_cnt_b(void)
{
  eTPU->IDLE_B.B.ICLR = 1;
}

/*******************************************************************************
* FUNCTION: fs_etpu_coherent_read_24
****************************************************************************/
/*!
* @brief   This function coherently reads two 24-bit variables from the eTPU
*          DATA RAM, using the Coherent Dual-Parameter Controller (CDC).
*
* @param   channel - The eTPU channel number
* @param   offset1 - The offset to the first 24-bit variable to be read
* @param   offset2 - The offset to the second 24-bit variable to be read
* @param   *value1 - A pointer to where the first variable value will be stored
* @param   *value2 - A pointer to where the second variable value will be stored
*
* @return  Zero or an error code. Error codes that can be returned are:
*          - @ref FS_ETPU_ERROR_MALLOC - When there is not enough available
*            memory for the temporally buffer in eTPU DATA RAM
*          - @ref FS_ETPU_ERROR_ADDRESS - When the variable offsets do not allow
*            the CDC operation.
*******************************************************************************/
uint32 fs_etpu_coherent_read_24(
    uint8 channel,
    uint32 offset1,
    uint32 offset2,
    sint32 *value1,
    sint32 *value2)
{
  uint32 addr1, addr2, ctbase1, ctbase2;
  uint32 addr_b;
  uint32 err_code = 0;

  /* check there is a DATA RAM space for the temporally buffer */
  if ((uint32)fs_free_param + 8 > fs_etpu_data_ram_end)
  {
    err_code = FS_ETPU_ERROR_MALLOC;
  }
  else
  {
    /* SDM-relative word addresses of parameters (4 byte granularity) */
    addr1 = ((eTPU->CHAN[channel].CR.B.CPBA << 3) + offset1 - 1) >> 2;
    addr2 = ((eTPU->CHAN[channel].CR.B.CPBA << 3) + offset2 - 1) >> 2;
    ctbase1 = addr1 >> 7;
    ctbase2 = addr2 >> 7;

    if (ctbase1 != ctbase2)
    {
      err_code = FS_ETPU_ERROR_ADDRESS;
    }
    else
    {
      /* SDM-relative doubleword address of buffer (8 byte granularity) */
      addr_b = ((uint32)fs_free_param - fs_etpu_data_ram_start) >> 3;

      /* CDC Register - configure and start the coherent transfer
           CTBASE = ctbase1;
           PARAM0 = addr1 & 0x7F;
           PARAM1 = addr2 & 0x7F;
           PBASE  = addr_b;
           WR     = 0;  - read
           PWIDTH = 0;  - 24-bit
           STS    = 1;  - start */
      eTPU->CDCR.R = (1 << 31) + (ctbase1 << 26) + (addr_b << 16) + ((addr1 & 0x7F) << 8) + (addr2 & 0x7F);

      /* now host receives wait states untill the transfer is done */

      /* read values from temporary buffer */
      *value1 = ((*(fs_free_param)) << 8) >> 8;
      *value2 = ((*(fs_free_param + 1)) << 8) >> 8;
    }
  }
  return (err_code);
}

/*******************************************************************************
* FUNCTION: fs_etpu_coherent_read_32
****************************************************************************/
/*!
* @brief   This function coherently reads two 32-bit variables from the eTPU
*          DATA RAM, using the Coherent Dual-Parameter Controller (CDC).
*
* @param   channel - The eTPU channel number
* @param   offset1 - The offset to the first 32-bit variable to be read
* @param   offset2 - The offset to the second 32-bit variable to be read
* @param   *value1 - A pointer to where the first variable value will be stored
* @param   *value2 - A pointer to where the second variable value will be stored
*
* @return  Zero or an error code. Error codes that can be returned are:
*          - @ref FS_ETPU_ERROR_MALLOC - When there is not enough available
*            memory for the temporally buffer in eTPU DATA RAM
*          - @ref FS_ETPU_ERROR_ADDRESS - When the variable offsets do not allow
*            the CDC operation.
*******************************************************************************/
uint32 fs_etpu_coherent_read_32(
    uint8 channel,
    uint32 offset1,
    uint32 offset2,
    uint32 *value1,
    uint32 *value2)
{
  uint32 addr1, addr2, ctbase1, ctbase2;
  uint32 addr_b;
  uint32 err_code = 0;

  /* check there is a DATA RAM space for the temporally buffer */
  if ((uint32)fs_free_param + 8 > fs_etpu_data_ram_end)
  {
    err_code = FS_ETPU_ERROR_MALLOC;
  }
  else
  {
    /* SDM-relative word addresses of parameters (4 byte granularity) */
    addr1 = ((eTPU->CHAN[channel].CR.B.CPBA << 3) + offset1) >> 2;
    addr2 = ((eTPU->CHAN[channel].CR.B.CPBA << 3) + offset2) >> 2;
    ctbase1 = addr1 >> 7;
    ctbase2 = addr2 >> 7;

    if (ctbase1 != ctbase2)
    {
      err_code = FS_ETPU_ERROR_ADDRESS;
    }
    else
    {
      /* SDM-relative doubleword address of buffer (8 byte granularity) */
      addr_b = ((uint32)fs_free_param - fs_etpu_data_ram_start) >> 3;

      /* CDC Register - configure and start the coherent transfer
           CTBASE = ctbase1;
           PARAM0 = addr1 & 0x7F;
           PARAM1 = addr2 & 0x7F;
           PBASE  = addr_b;
           WR     = 0;  - read
           PWIDTH = 1;  - 32-bit
           STS    = 1;  - start */
      eTPU->CDCR.R = (1 << 31) + (ctbase1 << 26) + (addr_b << 16) + (1 << 15) + ((addr1 & 0x7F) << 8) + (addr2 & 0x7F);

      /* now host receives wait states untill the transfer is done */

      /* read values from temporary buffer */
      *value1 = *(fs_free_param);
      *value2 = *(fs_free_param + 1);
    }
  }
  return (err_code);
}

/*******************************************************************************
* FUNCTION: fs_etpu_coherent_write_24
****************************************************************************/
/*!
* @brief   This function coherently writes two 24-bit variables into the eTPU
*          DATA RAM, using the Coherent Dual-Parameter Controller (CDC).
*
* @param   channel - The eTPU channel number
* @param   offset1 - The offset to the first 24-bit variable to be written
* @param   offset2 - The offset to the second 24-bit variable to be written
* @param   value1 - The first variable value
* @param   value2 - The second variable value
*
* @return  Zero or an error code. Error codes that can be returned are:
*          - @ref FS_ETPU_ERROR_MALLOC - When there is not enough available
*            memory for the temporally buffer in eTPU DATA RAM
*          - @ref FS_ETPU_ERROR_ADDRESS - When the variable offsets do not allow
*            the CDC operation.
*******************************************************************************/
uint32 fs_etpu_coherent_write_24(
    uint8 channel,
    uint32 offset1,
    uint32 offset2,
    sint32 value1,
    sint32 value2)
{
  uint32 addr1, addr2, ctbase1, ctbase2;
  uint32 addr_b;
  uint32 err_code = 0;

  /* check there is a DATA RAM space for the temporally buffer */
  if ((uint32)fs_free_param + 8 > fs_etpu_data_ram_end)
  {
    err_code = FS_ETPU_ERROR_MALLOC;
  }
  else
  {
    /* write values to the temporary buffer */
    *(fs_free_param) = value1;
    *(fs_free_param + 1) = value2;

    /* SDM-relative word addresses of parameters (4 byte granularity) */
    addr1 = ((eTPU->CHAN[channel].CR.B.CPBA << 3) + offset1 - 1) >> 2;
    addr2 = ((eTPU->CHAN[channel].CR.B.CPBA << 3) + offset2 - 1) >> 2;
    ctbase1 = addr1 >> 7;
    ctbase2 = addr2 >> 7;

    if (ctbase1 != ctbase2)
    {
      err_code = FS_ETPU_ERROR_ADDRESS;
    }
    else
    {
      /* SDM-relative doubleword address of buffer (8 byte granularity) */
      addr_b = ((uint32)fs_free_param - fs_etpu_data_ram_start) >> 3;

      /* CDC Register - configure and start the coherent transfer
           CTBASE = ctbase1;
           PARAM0 = addr1 & 0x7F;
           PARAM1 = addr2 & 0x7F;
           PBASE  = addr_b;
           WR     = 1;  - read
           PWIDTH = 0;  - 24-bit
           STS    = 1;  - start */
      eTPU->CDCR.R = (1 << 31) + (ctbase1 << 26) + (addr_b << 16) + (1 << 7) + ((addr1 & 0x7F) << 8) + (addr2 & 0x7F);

      /* now host receives wait states untill the transfer is done */
    }
  }
  return (err_code);
}

/*******************************************************************************
* FUNCTION: fs_etpu_coherent_write_32
****************************************************************************/
/*!
* @brief   This function coherently writes two 32-bit variables into the eTPU
*          DATA RAM, using the Coherent Dual-Parameter Controller (CDC).
*
* @param   channel - The eTPU channel number
* @param   offset1 - The offset to the first 32-bit variable to be written
* @param   offset2 - The offset to the second 32-bit variable to be written
* @param   value1 - The first variable value
* @param   value2 - The second variable value
*
* @return  Zero or an error code. Error codes that can be returned are:
*          - @ref FS_ETPU_ERROR_MALLOC - When there is not enough available
*            memory for the temporally buffer in eTPU DATA RAM
*          - @ref FS_ETPU_ERROR_ADDRESS - When the variable offsets do not allow
*            the CDC operation.
*******************************************************************************/
uint32 fs_etpu_coherent_write_32(
    uint8 channel,
    uint32 offset1,
    uint32 offset2,
    uint32 value1,
    uint32 value2)
{
  uint32 addr1, addr2, ctbase1, ctbase2;
  uint32 addr_b;
  uint32 err_code = 0;

  /* check there is a DATA RAM space for the temporally buffer */
  if ((uint32)fs_free_param + 8 > fs_etpu_data_ram_end)
  {
    err_code = FS_ETPU_ERROR_MALLOC;
  }
  else
  {
    /* write values to the temporary buffer */
    *(fs_free_param) = value1;
    *(fs_free_param + 1) = value2;

    /* SDM-relative word addresses of parameters (4 byte granularity) */
    addr1 = ((eTPU->CHAN[channel].CR.B.CPBA << 3) + offset1) >> 2;
    addr2 = ((eTPU->CHAN[channel].CR.B.CPBA << 3) + offset2) >> 2;
    ctbase1 = addr1 >> 7;
    ctbase2 = addr2 >> 7;

    if (ctbase1 != ctbase2)
    {
      err_code = FS_ETPU_ERROR_ADDRESS;
    }
    else
    {
      /* SDM-relative doubleword address of buffer (8 byte granularity) */
      addr_b = ((uint32)fs_free_param - fs_etpu_data_ram_start) >> 3;

      /* CDC Register - configure and start the coherent transfer
           CTBASE = ctbase1;
           PARAM0 = addr1 & 0x7F;
           PARAM1 = addr2 & 0x7F;
           PBASE  = addr_b;
           WR     = 1;  - read
           PWIDTH = 1;  - 32-bit
           STS    = 1;  - start */
      eTPU->CDCR.R = (1 << 31) + (ctbase1 << 26) + (addr_b << 16) + (1 << 15) + (1 << 7) + ((addr1 & 0x7F) << 8) + (addr2 & 0x7F);

      /* now host receives wait states untill the transfer is done */
    }
  }
  return (err_code);
}

/*******************************************************************************
 *
 * Copyright:
 *  Freescale Semiconductor, INC. All Rights Reserved.
 *  You are hereby granted a copyright license to use, modify, and
 *  distribute the SOFTWARE so long as this entire notice is
 *  retained without alteration in any modified and/or redistributed
 *  versions, and that such modified versions are clearly identified
 *  as such. No licenses are granted by implication, estoppel or
 *  otherwise under any patents or trademarks of Freescale
 *  Semiconductor, Inc. This software is provided on an "AS IS"
 *  basis and without warranty.
 *
 *  To the maximum extent permitted by applicable law, Freescale
 *  Semiconductor DISCLAIMS ALL WARRANTIES WHETHER EXPRESS OR IMPLIED,
 *  INCLUDING IMPLIED WARRANTIES OF MERCHANTABILITY OR FITNESS FOR A
 *  PARTICULAR PURPOSE AND ANY WARRANTY AGAINST INFRINGEMENT WITH
 *  REGARD TO THE SOFTWARE (INCLUDING ANY MODIFIED VERSIONS THEREOF)
 *  AND ANY ACCOMPANYING WRITTEN MATERIALS.
 *
 *  To the maximum extent permitted by applicable law, IN NO EVENT
 *  SHALL Freescale Semiconductor BE LIABLE FOR ANY DAMAGES WHATSOEVER
 *  (INCLUDING WITHOUT LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS,
 *  BUSINESS INTERRUPTION, LOSS OF BUSINESS INFORMATION, OR OTHER
 *  PECUNIARY LOSS) ARISING OF THE USE OR INABILITY TO USE THE SOFTWARE.
 *
 *  Freescale Semiconductor assumes no responsibility for the
 *  maintenance and support of this software
 ******************************************************************************/
/*******************************************************************************
 *
 * REVISION HISTORY:
 *
 * FILE OWNER: Milan Brejl [r54529]
 * 
 * Revision 3.2  2014/03/21  r54529
 * fs_etpu_clear_chan_interrupt_flag and fs_etpu_clear_chan_dma_flag bug fix
 * - the overflow flag was cleared as well.
 * fs_etpu_get/clear_chan_interrupt_oveflow_flag and 
 * fs_etpu_get/clear_chan_dma_overflow_flag added.
 *
 * Revision 3.1  2013/07/16  r54529
 * fs_etpu_coherent_read/write_32 bug (offset - 1) fixed (offset) .
 *
 * Revision 3.0  2012/05/17  r54529
 * fs_etpu2_init bug fix - engine-relative memory granularity is 512 bytes.
 *
 * Revision 2.9  2012/05/12  r54529
 * fs_etpu2_init bug fix
 *  
 * Revision 2.8  2012/04/10  r54529
 * fs_etpu2_init reworked - engine memory allocated but not initialized, becuase
 * the compiler never generated staticly allocated engine variables.   
 *  
 * Revision 2.7  2012/03/13  r54529
 * Usage of new macros FS_ETPU_ENTRY_TABLE_PIN_INPUT/OUTPUT added to 
 * fs_etpu_chan_init() comment.
 *   
 * Revision 2.6  2012/02/21  r54529
 * New functions added:
 *  - fs_etpu_set_interrupt_mask_a/b
 *  - fs_etpu_set_dma_mask_a/b
 *  - fs_etpu_set_output_disable_mask_a/b 
 *   
 * Revision 2.5  2012/02/10 13:52:15  r54529
 * Spelling and format edits.
 *
 * Revision 2.4  2012/02/10 08:27:49  r54529
 * New functions added:
 *  - get_global_error
 *  - fs_etpu_get/clear_idle_count_a/b
 * Modified (optimized) functions:
 *  - fs_etpu_coherent_read/write_24/32
 * Code formating cleared.
 * All code comments reformated for DoxyGen support.
 *
 * Revision 2.3  2011/07/11 13:22:15  r54529
 * New functions added:
 *  - fs_etpu_get/clear_chan_interrupt_flag
 *  - fs_etpu_get/clear_chan_dma_flag
 *  - fs_etpu_get/clear_global_exceptions
 *  - fs_etpu_coherent_read/write_24/32
 * Engine TBCR registers written only when ECR.MDIS = 0.
 * The eTPU2 supported by adding etpu watchdog initialization into etpu_config_t structure, fs_etpu2_init function and definitions of new eTPU2 register bits.
 *
 * Revision 2.2  2009/12/17 20:31:07  r54529
 * function fs_etpu_chan_init added (restored) - because used by eTPU GCT
 *
 * Revision 2.1  2009/10/28 14:46:51  r47354
 * Added code to make sure VIS bit is set before writing SCM.
 *
 * Revision 2.0  2004/11/30 16:10:32  r12110
 * -Updated functions to remove requirement for etpu_config.h file.
 * -Added new memset32 function to clear eTPU code memory.
 *
 * Revision 1.1  2004/11/12 10:39:23  r12110
 * Initial version checked into CVS.
 *..............................................................................
 * 0.01  J. Loeliger  13/Jun/03  Initial version of file.
 * 0.02  J. Loeliger  19/Mar/04  Change function prefix to fs_ for
 *                                Freescale semiconductor.
 * 0.03  J. Loeliger  26/Mar/04  Updated after debug.
 * 0.04  J. Loeliger  26/May/04  Updated comments.
 *       M. Brejl                Fixed problem with *fs_etpu_data_ram.
 *       M.Princ                 Renamed fs_mpc5500_timer_start to
 *                                fs_timer_start.
 *                               Added new functions to access parameter
 *                                Ram using different data sizes.
 * 0.05  J. Loeliger  16/Jul/04  Updated to match new mpc5554 header files
 * 0.06  J. Loeliger  16/Aug/04  Updated malloc to round correctly.
 * 0.1   J. Loeliger  01/Sep/04  Added fs_etpu_malloc2 function.
 ******************************************************************************/
