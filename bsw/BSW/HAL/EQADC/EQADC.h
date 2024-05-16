/*
 * eqadc.h
 *
 *  Created on: Dec 17, 2015
 *      Author: Mati
 */

#ifndef FS_EQADC_H_
#define FS_EQADC_H_

#define ADC_VREF_075_CODE 
#define IDEAL_RES75 0x3000
#define IDEAL_RES25 0x1000
#define VREF_075_CH 43
#define VREF_025_CH 44
#define PUSH_CFIFO0(n) EQADC.CFPR[0].R = n
#define PUSH_CFIFO1(n) EQADC.CFPR[1].R = n
#define PUSH_CFIFO2(n) EQADC.CFPR[2].R = n
#define PUSH_CFIFO3(n) EQADC.CFPR[3].R = n
#define PUSH_CFIFO4(n) EQADC.CFPR[4].R = n
#define PUSH_CFIFO5(n) EQADC.CFPR[5].R = n


#define POP_RFIFO0 (uint16)EQADC.RFPR[0].R
#define POP_RFIFO1 (uint16)EQADC.RFPR[1].R
#define POP_RFIFO2 (uint16)EQADC.RFPR[2].R
#define POP_RFIFO3 (uint16)EQADC.RFPR[3].R
#define POP_RFIFO4 (uint16)EQADC.RFPR[4].R
#define POP_RFIFO5 (uint16)EQADC.RFPR[5].R

#define ADC(n) 		(n << (31-6))    // which converter
#define LST(n)      (n << (31-13))	 // extra sample clocks (may reduce noise)
#define RFIFO(n) 	(n << (31-11))   // where to put results
#define CHANNEL(n) 	(n << (31-23))
#define PAUSE 		(1 << (31-1))
#define REG_EOQ 		(1UL << (31-0))
#define BN(n)  		((n) << (31-6)) /* which CBUFFER */
#define CAL(n)		((n) << (31-7))
#define FFMT(n)		((n) << (31-15))
#define ALT_CFG(n)	(n)

#define RFIFO_0_DMA_CHN 1
#define SIZE_2_BYTE 1


/*CFIFO Operation Mode*/
#define DISABLE_TRIG 0x0
#define SW_TRIG_SS 0x1
#define LOW_GATED_EXT_SS 0x2
#define HIGH_GATED_EXT_SS 0x3
#define FALLING_EXT_SS 0x4
#define RISING_EXT_SS 0x5
#define FALL_OR_RISE_EXT_SS 0x6
#define SW_TRIG_CS 0x9
#define LOW_GATED_EXT_CS 0xA
#define HIGH_GATED_EXT_CS 0xB
#define FALLING_EXT_CS 0xC
#define RISING_EXT_CS 0xD
#define FALL_OR_RISE_EXT_CS 0xE

/*CFIFO0 Advance Trigger Operation Mode*/
#define AMODE_DISABLE 0x0
#define AMODE_FALLING_EXT_SS 0x4
#define AMODE_RISING_EXT_SS 0x5
#define AMODE_FALL_OR_RISE_EXT_SS 0x6

//EQADC_IDCR MASK
#define	EQADC_IDCR_NCIE_MASK	0x8000
#define EQADC_IDCR_TORIE_MASK	0x4000
#define EQADC_IDCR_PIE_MASK		0x2000
#define EQADC_IDCR_EOQIE_MASK	0x1000
#define EQADC_IDCR_CFUIE_MASK	0x0800
#define EQADC_IDCR_CFFE_MASK 	0x0200
#define EQADC_IDCR_CFFS_MASK	0x0100
#define EQADC_IDCR_RFOI_MASK	0x0008
#define EQADC_IDCR_RFDE_MASK	0x0002
#define EQADC_IDCR_RFDS_MASK	0x0001

//EQADC_FISR MASK
#define EQADC_FISR_NCF_MASK		0x80000000
#define EQADC_FISR_TORF_MASK	0x40000000
#define EQADC_FISR_PF_MASK		0x20000000
#define EQADC_FISR_EOQF_MASK	0x10000000
#define EQADC_FISR_CFUF_MASK	0x08000000
#define EQADC_FISR_SSS_MASK		0x04000000
#define EQADC_FISR_CFFF_MASK	0x02000000
#define EQADC_FISR_RFOF_MASK	0x00080000
#define EQADC_FISR_RFDF_MASK	0x00020000


//#define EQADC_IDCR_EQQIE0_MASK	
#define FISR_EOQ_MASK 0x10000000

/* EQADC_CFCR MASK*/
#define EQADC_CFCR_CFEEE0_MASK	0x1000
#define EQADC_CFCR_STRME0_MASK	0x0800
#define EQADC_CFCR_SSE_MASK		0x0400
#define EQADC_CFCR_CFINV_MASK	0x0200

#define PUSH_TO_CFIFO(Y)			EQADC.CFPR[0].R = (uint32)Y

/*ADCx_CR MASK*/
#define ADC_EN_MASK			0x8000
#define ADC_EMU_MASK		0x0800
#define ADC_ODD_PS_MASK		0x0080
#define ADC_CLK_DTY_MASK	0x0040
#define ADC_CLK_SEL_MASK	0x0020
#define ADC_TBSEL_SRV1_MASK	0x0100
#define ADC_TBSEL_SRV2_MASK	0x0200

//CFIFO Macros
#define AD_FMTA(n)			((n) << (15-6))
#define AD_DEST(n)			((n) << (15-5))
#define AD_GAIN(n)			(n)
#define AD_ENABLE 			(1 << 15)
#define AD_CLOCK(n) 	    ((n) << 0)      /* ADC0/1_CLK_PS[0:4]  - divisor select */
#define ADC_REG_ADDR(x)		(((x)&0xFF))
#define ADC_REG_VALUE(x) 	(((x)&0xFFFF)<<8)
#define conv_command_std   	0x00
 #define ADC0_CR            0x01
 #define ADC1_CR            0x01
 #define ADC_TSCR           0x02
 #define ADC_TBCR           0x03
 #define ADC0_GCCR          0x04
 #define ADC1_GCCR          0x04
 #define ADC0_OCCR          0x05
 #define ADC1_OCCR          0x05
 #define conv_command_alt1  0x08
 #define conv_command_alt2  0x09
 #define conv_command_alt3  0x0A
 #define conv_command_alt4  0x0B
 #define conv_command_alt5  0x0C
 #define conv_command_alt6  0x0D
 #define conv_command_alt7  0x0E
 #define conv_command_alt8  0x0F
 #define ADC_ACR1           0x30
 #define ADC0_AGR1          0x31
 #define ADC1_AGR1          0x31
 #define ADC0_AOR1          0x32
 #define ADC1_AOR1          0x32
 #define ADC_ACR2           0x34
 #define ADC0_AGR2          0x35
 #define ADC1_AGR2          0x35
 #define ADC0_AOR2          0x36
 #define ADC1_AOR2          0x36
 #define ADC_ACR3           0x38
 #define ADC_ACR4           0x3C
 #define ADC_ACR5           0x40
 #define ADC_ACR6           0x44
 #define ADC_ACR7           0x48
 #define ADC_ACR8           0x4C
 #define ADC_PUDCR0         0x70
 #define ADC_PUDCR1         0x71
 #define ADC_PUDCR2         0x72
 #define ADC_PUDCR3         0x73
 #define ADC_PUDCR4         0x74
 #define ADC_PUDCR5         0x75
 #define ADC_PUDCR6         0x76
 #define ADC_PUDCR7         0x77
 #define ADC_REDTBR1        0xA0
 #define ADC_REDTBR2        0xA1


#define SIZE_1_byte  0
#define SIZE_2_byte  1 
#define SIZE_4_byte  2
#define SIZE_8_byte  3
#define SIZE_16_byte 4
#define SIZE_32_byte 5  


#define EQADC_BASE 	  0xFFF80000
#define CFIFO0_PUSH   (EQADC_BASE + 0x10)	// 32 bits
#define CFIFO1_PUSH   (EQADC_BASE + 0x14)        
#define CFIFO2_PUSH   (EQADC_BASE + 0x18)        
#define CFIFO3_PUSH   (EQADC_BASE + 0x1C)   
#define CFIFO4_PUSH   (EQADC_BASE + 0x20)        
#define CFIFO5_PUSH   (EQADC_BASE + 0x24)

#define RFIFO0_POP    (EQADC_BASE + 0x32)
#define RFIFO1_POP    (EQADC_BASE + 0x36)	 /* Lower 16 Bits */
#define RFIFO2_POP    (EQADC_BASE + 0x3A)	 
#define RFIFO3_POP    (EQADC_BASE + 0x3E)	 
#define RFIFO4_POP    (EQADC_BASE + 0x42)	 
#define RFIFO5_POP    (EQADC_BASE + 0x46)	 

__inline int ADC_u16Compare(const void * p0, const void * p1);
void Zero_DMA_Channel(int DMA_chan);
void DmacConfig(uint8 DMA_chan, void *cmd_source, void *cmd_dest, uint8 cmd_count, void *rec_source, void *rec_dest, uint8 rec_count);
void EQADCStartupCalibration(void);
void dec_fil_a_config(uint32* coef, uint8 scale,uint8 dec_rate);
void EQADC_StartConfig(void);

#endif /* EQADC_H_ */
