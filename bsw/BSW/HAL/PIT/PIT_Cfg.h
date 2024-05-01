/*
 * PIT_Cfg.h
 *
 *  Created on: Nov 20, 2018
 *      Author: Mati
 */

#ifndef PIT_CFG_H_
#define PIT_CFG_H_

#define PIT_CHN_1ms 0
#define PIT_CHN_10ms 1
#define PIT_CHN_50ms 2
#define PIT_US2CLK(x) (uint32)(120U * x)
#define PIT_MS2CLK(x) (uint32)(120000U * x)
#define PIT_CNT_1ms (uint32)(PIT_US2CLK(950) - 1)
#define PIT_CNT_10ms (uint32)(PIT_MS2CLK(9) - 1)
#define PIT_CNT_50ms (uint32)(PIT_MS2CLK(49) - 1)

void PIT_Init(void);

#endif /* PIT_CFG_H_ */
