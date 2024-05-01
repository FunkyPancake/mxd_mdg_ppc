/* ###*B*###
 * ERIKA Enterprise - a tiny RTOS for small microcontrollers
 *
 * Copyright (C) 2002-2013 Evidence Srl
 *
 * This file is part of ERIKA Enterprise.
 *
 * ERIKA Enterprise is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation,
 * (with a special exception described below).
 *
 * Linking this code statically or dynamically with other modules is
 * making a combined work based on this code.  Thus, the terms and
 * conditions of the GNU General Public License cover the whole
 * combination.
 *
 * As a special exception, the copyright holders of this library give you
 * permission to link this code with independent modules to produce an
 * executable, regardless of the license terms of these independent
 * modules, and to copy and distribute the resulting executable under
 * terms of your choice, provided that you also meet, for each linked
 * independent module, the terms and conditions of the license of that
 * module.  An independent module is a module which is not derived from
 * or based on this library.  If you modify this code, you may extend
 * this exception to your version of the code, but you are not
 * obligated to do so.  If you do not wish to do so, delete this
 * exception statement from your version.
 *
 * ERIKA Enterprise is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License version 2 for more details.
 *
 * You should have received a copy of the GNU General Public License
 * version 2 along with ERIKA Enterprise; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 * ###*E*### */

 /** @file   MemMap.h
  *  @brief  Project memory mapping file obtained by preprocessing starting
             from $(EEBASE)/pkg/mcu/mcu/infineon_tc27x/cfg/MemMap.gnu.h.tmpl.
  *  @author Errico Guidieri
  *  @date 2012
  */
/*******************************************************************************
                            INFORMATION MACROS
 ******************************************************************************/

#undef MEM_VENDOR_ID
#undef MEM_AR_MAJOR_VERSION
#undef MEM_AR_MINOR_VERSION
#undef MEM_AR_PATCH_VERSION
#undef MEM_SW_MAJOR_VERSION
#undef MEM_SW_MINOR_VERSION
#undef MEM_SW_PATCH_VERSION

#define MEM_VENDOR_ID        /* Do we have a vendor ID ? */

/* AUTOSAR Software Specification Version Information */
#define MEM_AR_MAJOR_VERSION        /* ? */
#define MEM_AR_MINOR_VERSION        /* ? */
#define MEM_AR_PATCH_VERSION        /* ? */

#define MEM_SW_MAJOR_VERSION        /* ? */
#define MEM_SW_MINOR_VERSION        /* ? */
#define MEM_SW_PATCH_VERSION        /* ? */

/* MUST NOT be guards here because this file is supposed to be included
   multiple time in a single compilation unit */

/* Flag Error until we are sure that we are correct */
#define MEMMAP_ERROR

/******************************************************************************
                  ERIKA OS memory mapping code section
 ******************************************************************************/
#ifdef OS_START_SEC_CODE
  #undef OS_START_SEC_CODE
  #ifdef EE_OPEN_CODE_SECTION
    #error Starting a "ee_kernel_text" section while a section is already started
  #else
    #undef MEMMAP_ERROR
    #pragma section "ee_kernel_text" ax
    #define EE_OPEN_CODE_SECTION
  #endif
#endif

#ifdef OS_STOP_SEC_CODE
  #undef OS_STOP_SEC_CODE
  #ifdef EE_OPEN_CODE_SECTION
    #undef MEMMAP_ERROR
    #undef EE_OPEN_CODE_SECTION
    #pragma section
  #else
    #error No section "ee_kernel_text" started
  #endif
#endif

#ifdef OS_START_SEC_CODE
#ifdef EE_OPEN_CODE_SECTION
    #error Starting a "ee_kernel_text" section while a section is already started
  #else
    #undef MEMMAP_ERROR
    #define START_SEC_CODE
    #include "MemMap.h"
    //#pragma section "ee_kernel_text" ax
    #define EE_OPEN_CODE_SECTION
  #endif  	
#endif

#ifdef OS_STOP_SEC_CODE
  #undef OS_STOP_SEC_CODE
  #ifdef EE_OPEN_CODE_SECTION
    #undef MEMMAP_ERROR
    #undef EE_OPEN_CODE_SECTION
    #define STOP_SEC_CODE
    #include "MemMap.h"
    //#pragma section
  #else
    #error No section "ee_kernel_text" started
  #endif
#endif

#ifdef MEMMAP_NODEF
    #error "Memmap error"
#endif

/******************************************************************************
              ERIKA OS memory mapping not initialized data section
 ******************************************************************************/

#ifdef OS_START_SEC_VAR_NOINIT
  #undef OS_START_SEC_VAR_NOINIT
  #ifdef EE_OPEN_DATA_SECTION
    #error Starting a "ee_kernel_bss" data section while a section is already started
  #else
    #undef MEMMAP_ERROR
    #pragma section "ee_kernel_bss" awB
    #define EE_OPEN_DATA_SECTION
  #endif
#endif
#ifdef OS_STOP_SEC_VAR_NOINIT
  #undef OS_STOP_SEC_VAR_NOINIT
  #ifdef EE_OPEN_DATA_SECTION
    #undef MEMMAP_ERROR
    #undef EE_OPEN_DATA_SECTION
    #pragma section
  #else
    #error No section "ee_kernel_bss" started
  #endif
#endif

/******************************************************************************
              ERIKA OS memory mapping initialized data section
 ******************************************************************************/

#ifdef OS_START_SEC_VAR_DATA
  #undef OS_START_SEC_VAR_DATA
  #ifdef EE_OPEN_DATA_SECTION
    #error Starting a "ee_kernel_data" data section while a section is already started
  #else
    #undef MEMMAP_ERROR
    #pragma section "ee_kernel_data" aw
    #define EE_OPEN_DATA_SECTION
  #endif
#endif
#ifdef OS_STOP_SEC_VAR_DATA
  #undef OS_STOP_SEC_VAR_DATA
  #ifdef EE_OPEN_DATA_SECTION
    #undef MEMMAP_ERROR
    #undef EE_OPEN_DATA_SECTION
    #pragma section
  #else
    #error No section "ee_kernel_data" started
  #endif
#endif

/******************************************************************************
              ERIKA OS memory mapping stack section
 ******************************************************************************/

#ifdef OS_START_SEC_STACK
  #undef OS_START_SEC_STACK
  #ifdef EE_OPEN_DATA_SECTION
    #error Starting a "ee_kernel_stack" data section while a section is already started
  #else
    #undef MEMMAP_ERROR
    #pragma section "ee_kernel_stack" aw
    #define EE_OPEN_DATA_SECTION
  #endif
#endif
#ifdef OS_STOP_SEC_STACK
  #undef OS_STOP_SEC_STACK
  #ifdef EE_OPEN_DATA_SECTION
    #undef MEMMAP_ERROR
    #undef EE_OPEN_DATA_SECTION
    #pragma section
  #else
    #error No section "ee_kernel_stack" started
  #endif
#endif

/******************************************************************************
                  ERIKA API memory mapping code section
 ******************************************************************************/
#ifdef API_START_SEC_CODE
  #undef API_START_SEC_CODE
  #ifdef EE_OPEN_CODE_SECTION
    #error Starting a "ee_api_text" section while a section is already started
  #else
    #undef MEMMAP_ERROR
    #pragma section "ee_api_text" ax
    #define EE_OPEN_CODE_SECTION
  #endif
#endif

#ifdef API_STOP_SEC_CODE
  #undef API_STOP_SEC_CODE
  #ifdef EE_OPEN_CODE_SECTION
    #undef MEMMAP_ERROR
    #undef EE_OPEN_CODE_SECTION
    #pragma section
  #else
    #error No section "ee_api_text" started
  #endif
#endif

/******************************************************************************
              ERIKA API memory mapping not initialized data section
 ******************************************************************************/

#ifdef API_START_SEC_VAR_NOINIT
  #undef API_START_SEC_VAR_NOINIT
  #ifdef EE_OPEN_DATA_SECTION
    #error Starting a "ee_api_bss" data section while a section is already started
  #else
    #undef MEMMAP_ERROR
    #pragma section "ee_api_bss" awB
    #define EE_OPEN_DATA_SECTION
  #endif
#endif
#ifdef API_STOP_SEC_VAR_NOINIT
  #undef API_STOP_SEC_VAR_NOINIT
  #ifdef EE_OPEN_DATA_SECTION
    #undef MEMMAP_ERROR
    #undef EE_OPEN_DATA_SECTION
    #pragma section
  #else
    #error "No section "ee_api_bss" started"
  #endif
#endif

/******************************************************************************
                ERIKA API memory mapping inizializated data section
 ******************************************************************************/
#ifdef API_START_SEC_DATA
  #undef API_START_SEC_DATA
  #ifdef EE_OPEN_DATA_SECTION
    #error Starting a "ee_api_data" section while a section is already started
  #else
    #undef MEMMAP_ERROR
    #pragma section "ee_api_data" aw
    #define EE_OPEN_DATA_SECTION
  #endif
#endif

#ifdef API_STOP_SEC_DATA
  #undef API_STOP_SEC_DATA
  #ifdef EE_OPEN_DATA_SECTION
    #undef MEMMAP_ERROR
    #undef EE_OPEN_DATA_SECTION
    #pragma section
  #else
    #error No section "ee_api_data" started
  #endif
#endif

/* GENERATED APPLICATION CODE SECTIONS - BEGIN */
FOR_EACH_APP
/******************************************************************************
                  ${APP_NAME} memory mapping code section
 ******************************************************************************/
#ifdef APP_${APP_NAME}_START_SEC_CODE
  #undef APP_${APP_NAME}_START_SEC_CODE
  #ifdef EE_OPEN_CODE_SECTION
    #error Starting a "ee_${APP_NAME}_text" section while a section is already started
  #else
    #undef MEMMAP_ERROR
    #pragma section "ee_${APP_NAME}_text" ax
    #define EE_OPEN_CODE_SECTION
  #endif
#endif

#ifdef APP_${APP_NAME}_STOP_SEC_CODE
  #undef APP_${APP_NAME}_STOP_SEC_CODE
  #ifdef EE_OPEN_CODE_SECTION
    #undef MEMMAP_ERROR
    #undef EE_OPEN_CODE_SECTION
    #pragma section
  #else
    #error No section "ee_${APP_NAME}_text" started
  #endif
#endif

 /******************************************************************************
          ${APP_NAME} memory mapping uinizializated data section
 ******************************************************************************/
#ifdef APP_${APP_NAME}_START_SEC_VAR_NOINIT
  #undef APP_${APP_NAME}_START_SEC_VAR_NOINIT
  #ifdef EE_OPEN_DATA_SECTION
    #error Starting a "ee_${APP_NAME}_bss" data section while a section is already started
  #else
    #undef MEMMAP_ERROR
    #pragma section "ee_${APP_NAME}_bss" awB
    #define EE_OPEN_DATA_SECTION
  #endif
#endif

#ifdef APP_${APP_NAME}_STOP_SEC_VAR_NOINIT
  #undef APP_${APP_NAME}_STOP_SEC_VAR_NOINIT
  #ifdef EE_OPEN_DATA_SECTION
    #undef MEMMAP_ERROR
    #undef EE_OPEN_DATA_SECTION
    #pragma section
  #else
    #error "No section "ee_${APP_NAME}_bss" started"
  #endif
#endif 

/******************************************************************************
          ${APP_NAME} memory mapping inizializated data section
 ******************************************************************************/
#ifdef APP_${APP_NAME}_START_SEC_DATA
  #undef APP_${APP_NAME}_START_SEC_DATA
  #ifdef EE_OPEN_DATA_SECTION
    #error Starting a "ee_${APP_NAME}_data" section while a section is already started
  #else
    #undef MEMMAP_ERROR
    #pragma section "ee_${APP_NAME}_data" aw
    #define EE_OPEN_DATA_SECTION
  #endif
#endif

#ifdef APP_${APP_NAME}_STOP_SEC_DATA
  #undef APP_${APP_NAME}_STOP_SEC_DATA
  #ifdef EE_OPEN_DATA_SECTION
    #undef MEMMAP_ERROR
    #undef EE_OPEN_DATA_SECTION
    #pragma section
  #else
    #error No section "ee_${APP_NAME}_data" started
  #endif
#endif

END_EACH_APP
/* GENERATED APPLICATION CODE SECTIONS - END */

/******************************************************************************
              ERIKA Multicore Shared not initialized data section
 ******************************************************************************/
#ifdef SHARED_START_SEC_VAR_NOINIT
  #undef SHARED_START_SEC_VAR_NOINIT
  #ifdef EE_OPEN_DATA_SECTION
    #error Starting a "ee_mcglobald" data section while a section is already started
  #else
    #undef MEMMAP_ERROR
    /* B Flag should be present, but section shared with section below */
    #pragma section "ee_mcglobald" aw /* EG: It should have had B flag (unitialized), but it's the same section of shared data */
    #define EE_OPEN_DATA_SECTION
  #endif
#endif
#ifdef SHARED_STOP_SEC_VAR_NOINIT
  #undef SHARED_STOP_SEC_VAR_NOINIT
  #ifdef EE_OPEN_DATA_SECTION
    #undef MEMMAP_ERROR
    #undef EE_OPEN_DATA_SECTION
    #pragma section
  #else
    #error No section "ee_mcglobald" started
  #endif
#endif

/******************************************************************************
              ERIKA Multicore Shared initialized data section
 ******************************************************************************/
#ifdef SHARED_START_SEC_VAR_DATA
  #undef SHARED_START_SEC_VAR_DATA
  #ifdef EE_OPEN_DATA_SECTION
    #error Starting a "ee_mcglobald" data section while a section is already started
  #else
    #undef MEMMAP_ERROR
    #pragma section "ee_mcglobald" aw
    #define EE_OPEN_DATA_SECTION
  #endif
#endif
#ifdef SHARED_STOP_SEC_VAR_DATA
  #undef SHARED_STOP_SEC_VAR_DATA
  #ifdef EE_OPEN_DATA_SECTION
    #undef MEMMAP_ERROR
    #undef EE_OPEN_DATA_SECTION
    #pragma section
  #else
    #error No section "ee_mcglobald" started
  #endif
#endif

/******************************************************************************
              ERIKA Multicore Shared constant initialized data section
 ******************************************************************************/
#ifdef SHARED_START_SEC_CONST_DATA
  #undef SHARED_START_SEC_CONST_DATA
  #ifdef EE_OPEN_DATA_SECTION
    #error Starting a "ee_mcglobalc" data section while a data section is already started
  #else
    #undef MEMMAP_ERROR
    #pragma section "ee_mcglobalc" a
    #define EE_OPEN_DATA_SECTION
  #endif
#endif
#ifdef SHARED_STOP_SEC_CONST_DATA
  #undef SHARED_STOP_SEC_CONST_DATA
  #ifdef EE_OPEN_DATA_SECTION
    #undef MEMMAP_ERROR
    #undef EE_OPEN_DATA_SECTION
    #pragma section
  #else
    #error No section "ee_mcglobalc" started
  #endif
#endif

/* Check if the "command macro" has been acknowledged */
#ifdef MEMMAP_ERROR
#error Wrong MemMap.h inclusion command macro!
#endif
