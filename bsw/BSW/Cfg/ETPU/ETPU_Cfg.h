/*
 * ETPU_Cfg.h
 *
 *  Created on: Dec 26, 2018
 *      Author: Mati
 */

#ifndef ETPU_CFG_H_
#define ETPU_CFG_H_

#ifdef ETPU_Cfg_C_
#define EXTERNAL_ extern
#else
#define EXTERNAL_
#endif

/******************************************************************************
* General Macros
******************************************************************************/

#define ETPU_ENGINE_A_CHANNEL(x) (x)
#define ETPU_ENGINE_B_CHANNEL(x) ((x) + 64)

#define FS_ETPU_ENTRY_TABLE_ADDR (((FS_ETPU_ENTRY_TABLE) >> 11) & 0x1F)

/******************************************************************************
* Application Constants and Macros
******************************************************************************/
#define SYS_FREQ_HZ 120E6
//#define TCR1_FREQ_HZ                                            (SYS_FREQ_HZ/4)
#define TCR1_FREQ_HZ (SYS_FREQ_HZ)
#define TEETH_TILL_GAP 23
#define TEETH_IN_GAP 1
#define TEETH_PER_CYCLE 48
#define TEETH_PER_REV (TEETH_TILL_GAP + TEETH_IN_GAP)
#define TCR2_TICKS_PER_TOOTH 150

#define TCR2_TICKS_PER_CYCLE ((TEETH_PER_CYCLE) * (TCR2_TICKS_PER_TOOTH))
#define MSEC2TCR1(x) (uint24_t)(TCR1_FREQ_HZ / 1E3 * (x) / 1E0)
#define USEC2TCR1(x) (uint24_t)(TCR1_FREQ_HZ / 1E3 * (x) / 1E3)
#define NSEC2TCR1(x) (uint24_t)(TCR1_FREQ_HZ / 1E3 * (x) / 1E6)
#define DEG2TCR2(x) (int24_t)((x)*TCR2_TICKS_PER_CYCLE / 720)
#define DEG012TCR2(x) (int24_t)((x)*TCR2_TICKS_PER_CYCLE / 7200)
#define UFRACT24(x) ((x)*0xFFFFFF)

/* Tooth Period [TCR1] and RPM */
#define RPM2TP(x) (int24_t)(TCR1_FREQ_HZ / (x)*60 / (TEETH_PER_CYCLE / 2))
#define TP2RPM(x) (sint16)(TCR1_FREQ_HZ / (x)*60 / (TEETH_PER_CYCLE / 2))

#define TDC1 (0)
#define TDC2 (180)
#define TDC3 (360)
#define TDC4 (540)

#define EngTdcOff_Deg 82
//#define EngTdcOff_Deg 2
#define ALIGNED_TDC1 (TDC1 + EngTdcOff_Deg)
#define ALIGNED_TDC2 (TDC2 + EngTdcOff_Deg)
#define ALIGNED_TDC3 (TDC3 + EngTdcOff_Deg)
#define ALIGNED_TDC4 (TDC4 + EngTdcOff_Deg)

/* Cam log */
#define CAM_LOG_SIZE 2

/******************************************************************************
* Define Functions to Channels
******************************************************************************/
#define ETPU_CAM_CHAN ETPU_ENGINE_A_CHANNEL(22)
#define ETPU_TG_CAM_CHAN ETPU_ENGINE_A_CHANNEL(25)
#define ETPU_CRANK_CHAN ETPU_ENGINE_A_CHANNEL(1)
#define ETPU_TG_CRANK_CHAN ETPU_ENGINE_A_CHANNEL(26)
#define ETPU_SPARK_1_CHAN ETPU_ENGINE_A_CHANNEL(13)
#define ETPU_SPARK_2_CHAN ETPU_ENGINE_A_CHANNEL(12)
#define ETPU_SPARK_3_CHAN ETPU_ENGINE_A_CHANNEL(11)
#define ETPU_SPARK_4_CHAN ETPU_ENGINE_A_CHANNEL(10)
#define ETPU_FUEL_1_CHAN ETPU_ENGINE_A_CHANNEL(7)
#define ETPU_FUEL_2_CHAN ETPU_ENGINE_A_CHANNEL(8)
#define ETPU_FUEL_3_CHAN ETPU_ENGINE_A_CHANNEL(5)
#define ETPU_FUEL_4_CHAN ETPU_ENGINE_A_CHANNEL(6)
#define ETPU_KNOCK_1_CHAN ETPU_ENGINE_A_CHANNEL(30)

/******************************************************************************
* Define Interrupt Enable, DMA Enable and Output Disable
******************************************************************************/
#define ETPU_CIE_A ((1 << ETPU_CRANK_CHAN) + (1 << ETPU_CAM_CHAN) + (1 << ETPU_KNOCK_1_CHAN))
#define ETPU_DTRE_A 0x00000000
#define ETPU_ODIS_A 0x00000000
#define ETPU_OPOL_A 0x00000000
#define ETPU_CIE_B 0x00000000
#define ETPU_DTRE_B 0x00000000
#define ETPU_ODIS_B 0x00000000
#define ETPU_OPOL_B 0x00000000

/******************************************************************************
* Global Variables Access
******************************************************************************/
/* Global CRANK structures defined in etpu_gct.c */
extern struct crank_instance_t crank_instance;
extern struct crank_config_t crank_config;
extern struct crank_states_t crank_states;

/* Global CAM structures defined in etpu_gct.c */
extern struct cam_instance_t cam_instance;
extern struct cam_config_t cam_config;
extern struct cam_states_t cam_states;

/* Global SPARK structures defined in etpu_gct.c */
extern struct spark_instance_t spark_1_instance;
extern struct spark_instance_t spark_2_instance;
extern struct spark_config_t spark_config;
extern struct spark_states_t spark_1_states;
extern struct spark_states_t spark_2_states;
extern struct spark_instance_t *spark_instance_array[2];
extern struct single_spark_config_t *single_spark_ptr;
/* Global FUEL structures defined in etpu_gct.c */
extern struct fuel_instance_t fuel_1_instance;
extern struct fuel_instance_t fuel_2_instance;
extern struct fuel_instance_t fuel_3_instance;
extern struct fuel_instance_t fuel_4_instance;
extern struct fuel_config_t fuel_config;
extern struct fuel_states_t fuel_1_states;
extern struct fuel_states_t fuel_2_states;
extern struct fuel_states_t fuel_3_states;
extern struct fuel_states_t fuel_4_states;
extern struct fuel_instance_t *fuel_instance_array[4];

/* Global KNOCK structures defined in etpu_gct.c */
extern struct knock_instance_t knock_1_instance;
extern struct knock_config_t knock_config;

/* Global TG structures defined in etpu_gct.c */
extern struct tg_instance_t tg_instance;
extern struct tg_config_t tg_config;
extern struct tg_states_t tg_states;

/******************************************************************************
* Function Prototypes
******************************************************************************/
sint32 my_system_etpu_init(void);
void my_system_etpu_start(void);

#ifdef EXTERNAL_
#undef EXTERNAL_
#endif
#endif /* ETPU_CFG_H_ */
