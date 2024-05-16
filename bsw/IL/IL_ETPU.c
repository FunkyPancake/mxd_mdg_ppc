#ifndef IL_ETPU_C_
#define IL_ETPU_C_
#endif

/*
 * IL_ETPU.c
 *
 *  Created on: Dec 27, 2018
 *      Author: Mati
 */
#include "IL_ETPU.h"
#include "ETPU_Cfg.h"
#include "etpu_spark.h"
#include "etpu_fuel.h"
#include "etpu_crank.h"
#include "etpu_cam.h"
#include "IgnGov_Out.h"

//#pragma push
//#pragma section all_types ".meas_ram" ".meas_ram"
//boolean B_crank_osc_en;
uint24_t etpu_cam_log[CAM_LOG_SIZE];
uint24_t etpu_tooth_period_log[TEETH_PER_CYCLE];
//#pragma pop
// __declspec(section ".rodata") const volatile uint16 EngNmotCrankTh_Rpm_P = 750;
// __declspec(section ".rodata") const volatile uint16 EngNmotStall_Rpm_P = 25;
void SetIgnEvent(void)
{
  /*sint16 end_angle = Get_IgnAdv_Deg();
  uint32 dwell = Get_IgnDwl_uSec();
  boolean b_ign_en = (uint8)(Get_Ign_bOffNMax() == STD_IDLE) && (uint8)(Get_Ign_bOffOvr() == STD_IDLE) && Get_Eng_bNMot();
  if (b_ign_en == STD_ACTIVE)
  {
    spark_config.generation_disable = FS_ETPU_SPARK_GENERATION_ALLOWED;
  }
  else
  {
    spark_config.generation_disable = FS_ETPU_SPARK_GENERATION_DISABLED;
  }
  single_spark_ptr[0].dwell_time = USEC2TCR1(dwell);
  single_spark_ptr[0].end_angle = DEG012TCR2(end_angle);
  single_spark_ptr[1].dwell_time = USEC2TCR1(dwell);
  single_spark_ptr[1].end_angle = DEG012TCR2(end_angle - 3600);
  fs_etpu_spark_config(&spark_1_instance, &spark_config);
  fs_etpu_spark_config(&spark_2_instance, &spark_config);*/
}

void SetInjEvent(void)
{
  /*uint8 i;
  fuel_config.angle_normal_end = DEG2TCR2(Get_Inj_PulEnd_Deg());
  fuel_config.injection_time = MSEC2TCR1(Get_Inj_PulDur_ms());
  boolean b_inj_en = (uint8)(Get_Inj_bOffNMax() == 0) && (uint8)(Get_Inj_bOffOvr() == 0) && Get_Eng_bNMot() && (uint8)(Get_Inj_bOffCut() == 0);
  if (b_inj_en == STD_ACTIVE)
  {
    fuel_config.generation_disable = FS_ETPU_FUEL_GENERATION_ALLOWED;
  }
  else
  {
    fuel_config.generation_disable = FS_ETPU_FUEL_GENERATION_DISABLED;
  }
  for (i = 0; i < 4; i++)
  {
    fs_etpu_fuel_config(fuel_instance_array[i], &fuel_config);
  }*/
}
void CalcNmot(uint8 error_flag)
{
  //   register uint8 i;
  //   register uint32 avg;
  //   register uint16 nmot;
  //   register boolean b_nmot;
  //   boolean b_stend = Get_Eng_bStEnd();
  //   if ((error_flag & FS_ETPU_CRANK_ERR_STALL) == FS_ETPU_CRANK_ERR_STALL)
  //   {
  //     b_nmot = STD_IDLE;
  //     nmot = 0;
  //   }
  //   else
  //   {
  //     avg = 0;
  //     for (i = 0; i < TEETH_PER_CYCLE; i++)
  //       avg += etpu_tooth_period_log[i];
  //     avg = avg / TEETH_PER_CYCLE;
  //     nmot = (uint16)TP2RPM(avg);
  //     if (nmot > EngNmotStall_Rpm_P)
  //       b_nmot = STD_ACTIVE;
  //     else
  //       b_nmot = STD_IDLE;
  //     if (nmot > EngNmotCrankTh_Rpm_P)
  //       b_stend = STD_ACTIVE;
  //   }
  //   Set_Eng_bStEnd(b_stend);
  //   Set_Eng_bNMot(b_nmot);
  //   Set_Eng_Nmot_Rpm(nmot);
}

void etpu_crank_isr(void)
{
  // uint24_t tcr2_adjustment;
  // uint8 err_flag = 0;
  // fs_etpu_clear_chan_interrupt_flag(ETPU_CRANK_CHAN);

  // /* Follow Engine Position state */
  // fs_etpu_crank_get_states(&crank_instance, &crank_states);
  // switch (crank_states.eng_pos_state)
  // {
  // case FS_ETPU_ENG_POS_SEEK:
  //   fs_etpu_crank_get_states(&crank_instance, &crank_states);
  //   err_flag = crank_states.error;
  //   /* Crank has stalled. Read Crank error to know the reason. */
  //   break;
  // case FS_ETPU_ENG_POS_FIRST_HALF_SYNC:
  //   /* Crank has found the gap, or
  //      Crank did not received CRANK_HSR_SET_SYNC and hence Crank reset
  //      the Cam log to repeat recording the Cam log. */
  //   break;
  // case FS_ETPU_ENG_POS_PRE_FULL_SYNC:
  //   /* Cam signal is logged, the log corresponds to a segment of
  //      teeth_per_sync Crank teeth starting from a gap.
  //      NOW THE CPU MUST RECOGNIZE THE LOGGED CAM PATTERN AND
  //      1) SET tcr2_adjustment
  //      2) ASSIGN CRANK HSR = CRANK_HSR_SET_SYNC. */
  //   fs_etpu_cam_get_states(&cam_instance, &cam_states);
  //   fs_etpu_cam_copy_log(&cam_instance, &etpu_cam_log[0]);

  //   if ((cam_states.log_count == 0))
  //   {
  //     /* 3 transition logged,
  //        the first transition is a rising one
  //        => the  first half-cycle was logged */
  //     /* Set, what angle should have been at the last gap */
  //     tcr2_adjustment = DEG2TCR2(360);
  //   }
  //   else if ((cam_states.log_count == 2))
  //   {
  //     /* 3 transitions logged,
  //        the first transition is a falling one
  //        => the second half-cycle was logged */
  //     /* Set, what angle should have been at the last gap */
  //     tcr2_adjustment = DEG2TCR2(0);
  //   }
  //   else
  //   {
  //     /* Cam pattern is not recognized */
  //     break;
  //   }
  //   fs_etpu_crank_set_sync(&crank_instance, tcr2_adjustment);
  //   break;
  // case FS_ETPU_ENG_POS_FULL_SYNC:
  //   /* Regular interrupt on the first tooth every engine cycle. */
  //   /* Clear errors */
  //   crank_states.error = 0;
  //   cam_states.error = 0;
  //   break;
  // }

  // /* Interface CRANK eTPU function */
  // fs_etpu_crank_get_states(&crank_instance, &crank_states);
  // fs_etpu_crank_config(&crank_instance, &crank_config);
  // fs_etpu_crank_copy_tooth_period_log(&crank_instance, &etpu_tooth_period_log[0]);
  // /* Interface CAM eTPU function */
  // fs_etpu_cam_get_states(&cam_instance, &cam_states);
  // fs_etpu_cam_config(&cam_instance, &cam_config);
  // fs_etpu_cam_copy_log(&cam_instance, &etpu_cam_log[0]);

  // /* Evaluate eTPU load */
  // //  etpu_engine_load = get_etpu_load_a();

  // //  if(B_crank_osc_en == STD_ACTIVE)
  // //	  CrankOsc();
  // CalcNmot(err_flag);
  // Inc_Eng_Nturns();
}

// void ETPU_EnableCrankIsr(void)
// {
//   INTC_InstallINTCInterruptHandler(etpu_crank_isr, 68 + ETPU_CRANK_CHAN, 6);
// }
