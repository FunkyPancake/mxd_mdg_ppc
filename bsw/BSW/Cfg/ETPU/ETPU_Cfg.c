#ifndef ETPU_Cfg_C_
#define ETPU_Cfg_C_
#endif

/*
 * ETPU_Cfg.c
 *
 *  Created on: Dec 26, 2018
 *      Author: Mati
 */
#include "Std_Types.h"
#include "ETPU_Cfg.h"
#include "BSW/eTPU/util/etpu_util.h"     /* General C Functions for the eTPU */
#include "BSW/eTPU/util/MPC5644A_vars.h" /* eTPU module addresses */
#include "BSW/eTPU/etpu_set/etpu_set.h"  /* eTPU function set code binary image */
#include "BSW/eTPU/crank/etpu_crank.h"   /* eTPU function CRANK API */
#include "BSW/eTPU/cam/etpu_cam.h"       /* eTPU function CAM API */
#include "BSW/eTPU/fuel/etpu_fuel.h"     /* eTPU function FUEL API */
#include "BSW/eTPU/spark/etpu_spark.h"   /* eTPU function SPARK API */
#include "BSW/eTPU/knock/etpu_knock.h"   /* eTPU function KNOCK API */
#include "BSW/eTPU/tg/etpu_tg.h"         /* eTPU function TG API */

/*******************************************************************************
* Global variables
*******************************************************************************/
/** @brief   Pointer to the first free parameter in eTPU DATA RAM */
uint32 *fs_free_param;

/*******************************************************************************
 * Global eTPU settings - etpu_config structure
 ******************************************************************************/
/** @brief   Structure handling configuration of all global settings */
struct etpu_config_t my_etpu_config =
    {
        /* etpu_config.mcr - Module Configuration Register */
        FS_ETPU_GLOBAL_TIMEBASE_DISABLE /* keep time-bases stopped during intialization (GTBE=0) */
            | FS_ETPU_MISC_DISABLE,     /* SCM operation disabled (SCMMISEN=0) */

        /* etpu_config.misc - MISC Compare Register*/
        FS_ETPU_MISC, /* MISC compare value from etpu_set.h */

        /* etpu_config.ecr_a - Engine A Configuration Register */
        FS_ETPU_ENTRY_TABLE_ADDR              /* entry table base address = shifted FS_ETPU_ENTRY_TABLE from etpu_set.h */
            | FS_ETPU_CHAN_FILTER_2SAMPLE     /* channel filter mode = three-sample mode (CDFC=0) */
            | FS_ETPU_FCSS_DIV2               /* filter clock source selection = div 2 (FSCC=0) */
            | FS_ETPU_FILTER_CLOCK_DIV2       /* filter prescaler clock control = div 2 (FPSCK=0) */
            | FS_ETPU_PRIORITY_PASSING_ENABLE /* scheduler priority passing is enabled (SPPDIS=0) */
            | FS_ETPU_ENGINE_ENABLE,          /* engine is enabled (MDIS=0) */

        /* etpu_config.tbcr_a - Time Base Configuration Register A */
        FS_ETPU_TCRCLK_MODE_2SAMPLE          /* TCRCLK signal filter control mode = two-sample mode (TCRCF=0x) */
            | FS_ETPU_TCRCLK_INPUT_DIV2CLOCK /* TCRCLK signal filter control clock = div 2 (TCRCF=x0) */
            | FS_ETPU_TCR1CS_DIV1            /* TCR1 clock source = div 1 (TCR1CS=1)*/
            | FS_ETPU_TCR1CTL_DIV2           /* TCR1 source = div 2 (TCR1CTL=2) */
            | FS_ETPU_TCR1_PRESCALER(1)      /* TCR1 prescaler = 1 (TCR1P=0) */
            | FS_ETPU_TCR2CTL_RISE           /* TCR2 source = falling external (TCR2CTL=2) */
            | FS_ETPU_TCR2_PRESCALER(1)      /* TCR2 prescaler = 1 (TCR2P=0) */
            | FS_ETPU_ANGLE_MODE_ENABLE_CH1, /* TCR2 angle mode is enabled (AM=3) */

        /* etpu_config.stacr_a - Shared Time And Angle Count Register A */
        FS_ETPU_TCR1_STAC_DISABLE           /* TCR1 on STAC bus = disabled (REN1=0) */
            | FS_ETPU_TCR1_STAC_CLIENT      /* TCR1 resource control = client (RSC1=0) */
            | FS_ETPU_TCR1_STAC_SRVSLOT(0)  /* TCR1 server slot = 0 (SRV1=0) */
            | FS_ETPU_TCR2_STAC_DISABLE     /* TCR2 on STAC bus = disabled (REN2=0) */
            | FS_ETPU_TCR1_STAC_CLIENT      /* TCR2 resource control = client (RSC2=0) */
            | FS_ETPU_TCR2_STAC_SRVSLOT(0), /* TCR2 server slot = 0 (SRV2=0) */

        /* etpu_config.ecr_b - Engine B Configuration Register */
        FS_ETPU_ENTRY_TABLE_ADDR              /* entry table base address = shifted FS_ETPU_ENTRY_TABLE from etpu_set.h */
            | FS_ETPU_CHAN_FILTER_2SAMPLE     /* channel filter mode = three-sample mode (CDFC=0) */
            | FS_ETPU_FCSS_DIV2               /* filter clock source selection = div 2 (FSCC=0) */
            | FS_ETPU_FILTER_CLOCK_DIV2       /* filter prescaler clock control = div 2 (FPSCK=0) */
            | FS_ETPU_PRIORITY_PASSING_ENABLE /* scheduler priority passing is enabled (SPPDIS=0) */
            | FS_ETPU_ENGINE_ENABLE,          /* engine is enabled (MDIS=0) */

        /* etpu_config.tbcr_b - Time Base Configuration Register B */
        FS_ETPU_TCRCLK_MODE_2SAMPLE          /* TCRCLK signal filter control mode = two-sample mode (TCRCF=0x) */
            | FS_ETPU_TCRCLK_INPUT_DIV2CLOCK /* TCRCLK signal filter control clock = div 2 (TCRCF=x0) */
            | FS_ETPU_TCR1CS_DIV2            /* TCR1 clock source = div 2 (TCR1CS=0)*/
            | FS_ETPU_TCR1CTL_DIV2           /* TCR1 source = div 2 (TCR1CTL=2) */
            | FS_ETPU_TCR1_PRESCALER(1)      /* TCR1 prescaler = 1 (TCR1P=0) */
            | FS_ETPU_TCR2CTL_DIV8           /* TCR2 source = etpuclk div 8 (TCR2CTL=4) */
            | FS_ETPU_TCR2_PRESCALER(1)      /* TCR2 prescaler = 1 (TCR2P=0) */
            | FS_ETPU_ANGLE_MODE_DISABLE,    /* TCR2 angle mode is disabled (AM=0) */

        /* etpu_config.stacr_b - Shared Time And Angle Count Register B */
        FS_ETPU_TCR1_STAC_DISABLE           /* TCR1 on STAC bus = disabled (REN1=0) */
            | FS_ETPU_TCR1_STAC_CLIENT      /* TCR1 resource control = client (RSC1=0) */
            | FS_ETPU_TCR1_STAC_SRVSLOT(0)  /* TCR1 server slot = 0 (SRV1=0) */
            | FS_ETPU_TCR2_STAC_DISABLE     /* TCR2 on STAC bus = disabled (REN2=0) */
            | FS_ETPU_TCR1_STAC_CLIENT      /* TCR2 resource control = client (RSC2=0) */
            | FS_ETPU_TCR2_STAC_SRVSLOT(0), /* TCR2 server slot = 0 (SRV2=0) */

        /* etpu_config.wdtr_a - Watchdog Timer Register A(eTPU2 only) */
        FS_ETPU_WDM_DISABLED         /* watchdog mode = disabled */
            | FS_ETPU_WDTR_WDCNT(0), /* watchdog count = 0 */

        /* etpu_config.wdtr_b - Watchdog Timer Register B (eTPU2 only) */
        FS_ETPU_WDM_DISABLED        /* watchdog mode = disabled */
            | FS_ETPU_WDTR_WDCNT(0) /* watchdog count = 0 */
};

/*******************************************************************************
 * eTPU channel settings - CRANK
 ******************************************************************************/
/** @brief   Initialization of CRANK structures */
struct crank_instance_t crank_instance =
    {
        ETPU_CRANK_CHAN,                        /* chan_num */
        FS_ETPU_PRIORITY_HIGH,                  /* priority */
        FS_ETPU_CRANK_FM0_USE_TRANS_RISING,     /* polarity */
        TEETH_TILL_GAP,                         /* teeth_till_gap */
        TEETH_IN_GAP,                           /* teeth_in_gap */
        TEETH_PER_CYCLE,                        /* teeth_per_cycle */
        TCR2_TICKS_PER_TOOTH,                   /* tcr2_ticks_per_tooth */
        FS_ETPU_CRANK_FM1_TOOTH_PERIODS_LOG_ON, /* log_tooth_periods */
        ((ETPU_CAM_CHAN << 0) +
         (ETPU_CAM_CHAN << 8) +
         (ETPU_CAM_CHAN << 16) +
         (ETPU_CAM_CHAN << 24)), /* link_cam */
        ((ETPU_SPARK_1_CHAN << 0) +
         (ETPU_SPARK_2_CHAN << 8) +
         (ETPU_SPARK_3_CHAN << 16) +
         (ETPU_SPARK_4_CHAN << 24)), /* link_1 - sparks */
        ((ETPU_FUEL_1_CHAN << 0) +
         (ETPU_FUEL_2_CHAN << 8) +
         (ETPU_FUEL_3_CHAN << 16) +
         (ETPU_FUEL_4_CHAN << 24)), /* link_2 - fuels */
        ((ETPU_KNOCK_1_CHAN << 0)), /* link_4 - injs */
        0,
        0, /* *cpba */                 /* 0 for automatic allocation */
        0 /* *cpba_tooth_period_log */ /* automatic allocation */
};

struct crank_config_t crank_config =
    {
        1 * (TEETH_TILL_GAP + TEETH_IN_GAP), /* teeth_per_sync */
        MSEC2TCR1(10),                       /* blank_time */
        5,                                   /* blank_teeth */
        UFRACT24(0.6f),                      /* gap_ratio */
        UFRACT24(0.4f),                      /* win_ratio_normal */
        UFRACT24(0.5f),                      /* win_ratio_across_gap */
        UFRACT24(0.4f),                      /* win_ratio_after_gap */
        UFRACT24(0.5f),                      /* win_ratio_after_timeout */
        MSEC2TCR1(50)                        /* first_tooth_timeout */
};

struct crank_states_t crank_states;

/*******************************************************************************
 * eTPU channel settings - CAM
 ******************************************************************************/
/** @brief   Initialization of CAM structures */
struct cam_instance_t cam_instance =
    {
        ETPU_CAM_CHAN,        /* chan_num */
        FS_ETPU_PRIORITY_LOW, /* priority */
        CAM_LOG_SIZE,         /* log_size */
        0, /* *cpba */        /* 0 for automatic allocation */
        0 /* *cpba_log */     /* 0 for automatic allocation */
};

struct cam_config_t cam_config =
    {
        FS_ETPU_CAM_LOG_BOTH /* mode */
};

struct cam_states_t cam_states;

/*******************************************************************************
 * eTPU channel settings - SPARKs
 ******************************************************************************/
/** @brief   Initialization of SPARK structures */
struct spark_instance_t spark_1_instance =
    {
        ETPU_SPARK_1_CHAN,             /* chan_num */
        FS_ETPU_PRIORITY_MIDDLE,       /* priority */
        FS_ETPU_SPARK_FM0_ACTIVE_HIGH, /* polarity */
        DEG2TCR2(ALIGNED_TDC1),        /* tdc_angle */
        0, /* *cpba */                 /* 0 for automatic allocation */
        0 /* *cpba_single_spark */     /* 0 for automatic allocation */
};

struct spark_instance_t spark_2_instance =
    {
        ETPU_SPARK_2_CHAN,             /* chan_num */
        FS_ETPU_PRIORITY_MIDDLE,       /* priority */
        FS_ETPU_SPARK_FM0_ACTIVE_HIGH, /* polarity */
        DEG2TCR2(ALIGNED_TDC2),        /* tdc_angle */
        0, /* *cpba */                 /* 0 for automatic allocation */
        0 /* *cpba_single_spark */     /* 0 for automatic allocation */
};

struct single_spark_config_t single_spark_config[2] =
    {
        {
            DEG2TCR2(0),     /* end_angle */
            USEC2TCR1(2000), /* dwell_time */
            0                /* multi_pulse_count */
        },
        {
            DEG2TCR2(360),   /* end_angle */
            USEC2TCR1(2000), /* dwell_time */
            0                /* multi_pulse_count */
        }};
struct single_spark_config_t *single_spark_ptr = &single_spark_config[0];
struct spark_config_t spark_config =
    {
        DEG2TCR2(30),                     /* angle_offset_recalc */
        USEC2TCR1(1000),                  /* dwell_time_min */
        USEC2TCR1(5000),                  /* dwell_time_max */
        USEC2TCR1(100),                   /* multi_on_time */
        USEC2TCR1(100),                   /* multi_off_time */
        2,                                /* spark_count */
        &single_spark_config[0],          /* p_single_spark_config */
        FS_ETPU_SPARK_GENERATION_DISABLED /* generation_disable */
};

struct spark_states_t spark_1_states;
struct spark_states_t spark_2_states;

/*******************************************************************************
 * eTPU channel settings - FUELs
 ******************************************************************************/
/** @brief   Initialization of FUEL structures */
struct fuel_instance_t fuel_1_instance =
    {
        ETPU_FUEL_1_CHAN,             /* chan_num */
        FS_ETPU_PRIORITY_MIDDLE,      /* priority */
        FS_ETPU_FUEL_FM0_ACTIVE_HIGH, /* polarity */
        DEG2TCR2(ALIGNED_TDC1),       /* tdc_angle */
        0 /* *cpba */                 /* 0 for automatic allocation */
};

struct fuel_instance_t fuel_2_instance =
    {
        ETPU_FUEL_2_CHAN,             /* chan_num */
        FS_ETPU_PRIORITY_MIDDLE,      /* priority */
        FS_ETPU_FUEL_FM0_ACTIVE_HIGH, /* polarity */
        DEG2TCR2(ALIGNED_TDC2),       /* tdc_angle */
        0 /* *cpba */                 /* 0 for automatic allocation */
};

struct fuel_instance_t fuel_3_instance =
    {
        ETPU_FUEL_3_CHAN,             /* chan_num */
        FS_ETPU_PRIORITY_MIDDLE,      /* priority */
        FS_ETPU_FUEL_FM0_ACTIVE_HIGH, /* polarity */
        DEG2TCR2(ALIGNED_TDC3),       /* tdc_angle */
        0 /* *cpba */                 /* 0 for automatic allocation */
};

struct fuel_instance_t fuel_4_instance =
    {
        ETPU_FUEL_4_CHAN,             /* chan_num */
        FS_ETPU_PRIORITY_MIDDLE,      /* priority */
        FS_ETPU_FUEL_FM0_ACTIVE_HIGH, /* polarity */
        DEG2TCR2(ALIGNED_TDC4),       /* tdc_angle */
        0 /* *cpba */                 /* 0 for automatic allocation */
};

struct fuel_config_t fuel_config =
    {
        DEG2TCR2(220),   /* angle_normal_end */
        DEG2TCR2(180),   /* angle_stop */
        DEG2TCR2(60),    /* angle_offset_recalc */
        USEC2TCR1(0),    /* injection_time */
        USEC2TCR1(750),  /* compensation_time */
        USEC2TCR1(1350), /* injection_time_minimum */
        USEC2TCR1(750),  /* off_time_minimum */
        FS_ETPU_FUEL_GENERATION_DISABLED};

struct fuel_states_t fuel_1_states;
struct fuel_states_t fuel_2_states;
struct fuel_states_t fuel_3_states;
struct fuel_states_t fuel_4_states;
struct fuel_instance_t *fuel_instance_array[4] = {
    &fuel_1_instance,
    &fuel_2_instance,
    &fuel_3_instance,
    &fuel_4_instance};
/*******************************************************************************
 * eTPU channel settings - KNOCKs
 ******************************************************************************/
/** @brief   Initialization of KNOCK structures */
struct knock_instance_t knock_1_instance =
    {
        ETPU_KNOCK_1_CHAN,             /* chan_num */
        FS_ETPU_PRIORITY_MIDDLE,       /* priority */
        FS_ETPU_KNOCK_FM0_ACTIVE_HIGH, /* polarity */
        DEG2TCR2(ALIGNED_TDC1),        /* tdc_angle */
        0, /* *cpba */                 /* 0 for automatic allocation */
        0 /* *cpba_windows */          /* 0 for automatic allocation */
};

struct knock_window_config_t knock_window_config[8] =
    {
        {
            DEG2TCR2(30), /* angle_start */
            DEG2TCR2(20)  /* angle_width */
        },
        {
            DEG2TCR2(-10), /* angle_start */
            DEG2TCR2(20)   /* angle_width */
        },
        {
            DEG2TCR2(30 - 180), /* angle_start */
            DEG2TCR2(20)        /* angle_width */
        },
        {
            DEG2TCR2(-10 - 180), /* angle_start */
            DEG2TCR2(20)         /* angle_width */
        },
        {
            DEG2TCR2(30 - 360), /* angle_start */
            DEG2TCR2(20)        /* angle_width */
        },
        {
            DEG2TCR2(-10 - 360), /* angle_start */
            DEG2TCR2(20)         /* angle_width */
        },
        {
            DEG2TCR2(30 - 540), /* angle_start */
            DEG2TCR2(20)        /* angle_width */
        },
        {
            DEG2TCR2(-10 - 360), /* angle_start */
            DEG2TCR2(20)         /* angle_width */
        },
};

struct knock_config_t knock_config =
    {
        FS_ETPU_KNOCK_FM1_MODE_TRIGGER, /* mode */
        8,                              /* window_count */
        &knock_window_config[0],        /* p_knock_window_config */
        USEC2TCR1(10),                  /* trigger_period */
        FS_ETPU_KNOCK_IRQ_AT_WINDOW_END /* irq_dma_options */
};

/*******************************************************************************
 * eTPU channel settings - TG
 ******************************************************************************/
/** @brief   Initialization of TG structures */
uint8 cam_edge_teeth[] = {
    3, 5};

struct tg_instance_t tg_instance =
    {
        ETPU_TG_CRANK_CHAN,           /* chan_num_crank */
        ETPU_TG_CAM_CHAN,             /* chan_num_cam */
        FS_ETPU_PRIORITY_LOW,         /* priority */
        FS_ETPU_TG_FM0_POLARITY_HIGH, /* polarity_crank */
        FS_ETPU_TG_FM0_POLARITY_HIGH, /* polarity_cam */
        TEETH_TILL_GAP,               /* teeth_till_gap */
        TEETH_IN_GAP,                 /* teeth_in_gap */
        TEETH_PER_CYCLE,              /* teeth_per_cycle */
        sizeof(cam_edge_teeth),       /* cam_edge_count */
        &cam_edge_teeth[0],           /* *p_cam_edge_tooth */
        0, /* *cpba */                /* 0 for automatic allocation */
        0                             /* *cpba_cam_edge_tooth */
};

struct tg_config_t tg_config =
    {
        RPM2TP(1500),  /* tooth_period_target */
        UFRACT24(0.1), /* accel_rate */
#ifdef DEBUG
        FS_ETPU_TG_GENERATION_ALLOWED /* generation_disable */
#else
        FS_ETPU_TG_GENERATION_DISABLED
#endif
};

struct tg_states_t tg_states;

/*******************************************************************************
* FUNCTION: my_system_etpu_init
****************************************************************************/
/*!
* @brief   This function initialize the eTPU module:
*          -# Initialize global setting using fs_etpu_init function
*             and the my_etpu_config structure
*          -# On eTPU2, initialize the additional eTPU2 setting using
*             fs_etpu2_init function
*          -# Initialize channel setting using channel function APIs
*
* @return  Zero or an error code is returned.
*******************************************************************************/
sint32 my_system_etpu_init(void)
{
  sint32 err_code;
  uint8 i;
  /* Clear eTPU DATA RAM to make debugging easier */
  fs_memset32((uint32 *)fs_etpu_data_ram_start, 0, fs_etpu_data_ram_end - fs_etpu_data_ram_start);

  /* Initialization of eTPU global settings */
  err_code = fs_etpu_init(
      my_etpu_config,
      (uint32 *)etpu_code, sizeof(etpu_code),
      (uint32 *)etpu_globals, sizeof(etpu_globals));
  if (err_code != FS_ETPU_ERROR_NONE)
    return (err_code);
#ifdef FS_ETPU_ARCHITECTURE
#if FS_ETPU_ARCHITECTURE == ETPU2
  /* Initialization of additional eTPU2-only global settings */
  err_code = fs_etpu2_init(
      my_etpu_config,
#ifdef FS_ETPU_ENGINE_MEM_SIZE
      FS_ETPU_ENGINE_MEM_SIZE);
#else
      0);
#endif
  if (err_code != FS_ETPU_ERROR_NONE)
    return (err_code);
#endif
#endif
  /*
   * Adjust TDC by TDC offset
   */

  /* Initialization of eTPU channel settings */
  err_code = fs_etpu_crank_init(
      &crank_instance,
      &crank_config);
  if (err_code != FS_ETPU_ERROR_NONE)
    return (err_code + (ETPU_CRANK_CHAN << 16));

  err_code = fs_etpu_cam_init(
      &cam_instance,
      &cam_config);
  if (err_code != FS_ETPU_ERROR_NONE)
    return (err_code + (ETPU_CAM_CHAN << 16));

  err_code = fs_etpu_spark_init(
      &spark_1_instance,
      &spark_config);
  if (err_code != FS_ETPU_ERROR_NONE)
    return (err_code + (ETPU_SPARK_1_CHAN << 16));

  err_code = fs_etpu_spark_init(
      &spark_2_instance,
      &spark_config);
  if (err_code != FS_ETPU_ERROR_NONE)
    return (err_code + (ETPU_SPARK_2_CHAN << 16));

  err_code = fs_etpu_fuel_init(
      &fuel_1_instance,
      &fuel_config);
  if (err_code != FS_ETPU_ERROR_NONE)
    return (err_code + (ETPU_FUEL_1_CHAN << 16));

  err_code = fs_etpu_fuel_init(
      &fuel_2_instance,
      &fuel_config);
  if (err_code != FS_ETPU_ERROR_NONE)
    return (err_code + (ETPU_FUEL_2_CHAN << 16));

  err_code = fs_etpu_fuel_init(
      &fuel_3_instance,
      &fuel_config);
  if (err_code != FS_ETPU_ERROR_NONE)
    return (err_code + (ETPU_FUEL_3_CHAN << 16));

  err_code = fs_etpu_fuel_init(
      &fuel_4_instance,
      &fuel_config);
  if (err_code != FS_ETPU_ERROR_NONE)
    return (err_code + (ETPU_FUEL_4_CHAN << 16));

  err_code = fs_etpu_knock_init(
      &knock_1_instance,
      &knock_config);
  if (err_code != FS_ETPU_ERROR_NONE)
    return (err_code + (ETPU_KNOCK_1_CHAN << 16));

  err_code = fs_etpu_tg_init(
      &tg_instance,
      &tg_config);
  if (err_code != FS_ETPU_ERROR_NONE)
    return (err_code + (ETPU_TG_CRANK_CHAN << 16));

  return (FS_ETPU_ERROR_NONE);
}

/*******************************************************************************
* FUNCTION: my_system_etpu_start
****************************************************************************/
/*!
* @brief   This function enables channel interrupts, DMA requests and "output
*          disable" feature on selected channels and starts TCR time bases using
*          Global Timebase Enable (GTBE) bit.
* @warning This function should be called after all device modules, including
*          the interrupt and DMA controller, are configured.
*******************************************************************************/
void my_system_etpu_start(void)
{
  /* Initialization of Interrupt Enable, DMA Enable
     and Output Disable channel options */
  fs_etpu_set_interrupt_mask_a(ETPU_CIE_A);
  fs_etpu_set_dma_mask_a(ETPU_DTRE_A);
  fs_etpu_set_output_disable_mask_a(ETPU_ODIS_A, ETPU_OPOL_A);

  /* Synchronous start of all TCR time bases */
  fs_timer_start();
}

#ifdef ETPU_Cfg_C_
#undef ETPU_Cfg_C_
#endif
