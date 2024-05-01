/*
 * GPIO_Cfg.h
 *
 *  Created on: Oct 28, 2018
 *      Author: Mati
 */

#ifndef GPIO_CFG_H_
#define GPIO_CFG_H_

#define PAD_SPARKDUR 123
#define PAD_NOMI 133
#define PAD_MAXI 134
#define PAD_FUEL1 122
#define PAD_FUEL2 121
#define PAD_FUEL3 120
#define PAD_FUEL4 119
#define PAD_IGN1 127
#define PAD_IGN2 126
#define PAD_IGN3 125
#define PAD_IGN4 124
#define PAD_OUTEN 132
#define PAD_CS_810 105
#define PAD_CS_800 107
#define PAD_CRANK 115
#define PAD_CAM 136
#define PAD_CRANK_TG 140
#define PAD_CAM_TG 139
#define PAD_IND1 190
#define PAD_IND2 191
#define PAD_IND3 192
#define PAD_IND4 193
#define PAD_SQWE 194
#define PAD_ESCI_A_TX 89
#define PAD_ESCI_A_RX 90
#define PAD_CAN_A_TX 83
#define PAD_CAN_A_RX 84
#define PAD_CAN_C_TX 87
#define PAD_CAN_C_RX 88
#define PAD_MISO_B 104
#define PAD_MOSI_B 103
#define PAD_SCLK_B 102
#define PAD_PWM_MOS1 188
#define PAD_PWM_MOS2 183
#define PAD_PWM_MOS3 181
#define PAD_PWM12 182
#define PAD_PWM34 185
#define PAD_PWM56 186
#define PAD_PWM78 187
#define PAD_VSNS_EN 137
#define PAD_UART_RX 90
#define PAD_UART_TX 89

void InitGPIO(void);

#endif /* GPIO_CFG_H_ */
