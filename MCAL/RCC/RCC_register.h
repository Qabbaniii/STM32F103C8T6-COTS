/**********************************************************************************
 *	FILE DESCRIPTION
 **********************************************************************************
 * Filename              :   RCC_register.h
 * Author                :   Abdullah Qabbani
 * Origin Date           :   19/2/2024
 * Version               :   1.0.0
 * Compiler              :   GCC ARM Embedded Toolchain
 * Target                :
 * Notes                 :
 *
 **********************************************************************************/
/************************ SOURCE REVISION LOG *************************************
 *
 *  Date 	    Version   Author             Description
 *  23/2/2024   1.0.0     Abdullah Qabbani   Initial Release.
 *
 **********************************************************************************/

#ifndef MCAL_RCC_REGISTER_H_
#define MCAL_RCC_REGISTER_H_
#include "../../LIB/STM32F103.h"
/*RCC clock control register RCC_CR pins*/
enum{
	HSION,HSIRDY,HSITRIM0=3,HSITRIM1,HSITRIM2,HSITRIM3,HSITRIM4,
	HSICAL0,HSICAL1,HSICAL2,HSICAL3,HSICAL4,HSICAL5,HSICAL6,HSICAL7
	,HSEON,HSERDY,HSEBYP,CSSON,PLLON =24,PLLRDY
};

/*RCC clock configuration register  (RCC_CFGR) PINS*/
enum{
	SW0,SW1,SWS0,SWS1,HPRE0,HPRE1,HPRE2,HPRE3,
	PPRE10,PPRE11,PPRE12,PPRE20,PPRE21,PPRE22
	,ADCPRE0,ADCPRE1,PLLSRC,PLLXTPRE,
	PLLMUL0,PLLMUL1,PLLMUL2,PLLMUL3,USBPRE,
	MCO0=24,MCO1,MCO2
};

/*RCC clock interrupt register (RCC_CIR) PINS*/
enum{
	LSIRDYF,LSERDYF,HSIRDYF,HSERDYF,PLLRDYF,
	CSSF=7,LSIRDYIE,LSERDYIE,HSIRDYIE,HSERDYIE,PLLRDYIE,
	LSIRDYC=16,LSERDYC,HSIRDYC,
	HSERDYC,PLLRDYC,CSSC=23

};

/*RCC APB2 peripheral reset register (RCC_APB2RSTR) PINS*/
enum{
	AFIORST,IOPARST=2,IOPBRST,IOPCRST,
	IOPDRST,IOPERST,IOPFRST,IOPGRST,
	ADC1RST,ADC2RST,TIM1RST,SPI1RST,
	TIM8RST,USART1RST,ADC3RST,
	TIM9RST=19,TIM10RST,TIM11RST
};

/*RCC APB1 peripheral reset register (RCC_APB1RSTR) PINS*/
enum{
	TIM2RST,TIM3RST,TIM4RST,TM5RST,TM6RST,TM7RST,TIM12RST,TIM13RST,TIM14RST
	,WWDGRST=11,SPI2RST=14,SPI3RST,USART2RST=17,USART3RST,UART4RST,UART5RST
	,I2C1RST,I2C2RST,USBRST,CANRST=25,BKPRST=27,PWRRST,DACRST
};

/*RCC AHB peripheral clock enable register (RCC_AHBENR) PINS*/
enum{
	DMA1EN,DMA2EN,SRAMEN,FLITFEN=4,CRCEN=6,FSMCEN=8,SDIOEN=10,
};

/*RCC APB2 peripheral clock enable register (RCC_APB2ENR) PINS*/
enum{
	AFIOEN,IOPAEN=2,IOPBEN,
	IOPCEN,IOPDEN,IOPEEN,IOPFEN,IOPGEN,
		ADC1EN,ADC2EN,TIM1EN,SPI1EN,
		TIM8EN,USART1EN,ADC3EN,
		TIM9EN=19,TIM10EN,TIM11EN
};

/*APB1 peripheral clock enable register (RCC_APB1ENR) PINS*/
enum{
	TIM2EN,TIM3EN,TIM4EN,TM5EN,TM6EN,TM7EN,TIM12EN,TIM13EN,TIM14EN
		,WWDGEN=11,SPI2EN=14,SPI3EN,USART2EN=17,USART3EN,UART4EN,UART5EN
		,I2C1EN,I2C2EN,USBEN,CANEN=25,BKPEN=27,PWREN,DACEN
};

/*Backup domain control register (RCC_BDCR) PINS*/
enum{
	LSEON,LSERDY,LSEBYP,RTCSEL0=8,RTCSEL1,RTCEN=15,BDRST
};

/*Control/status register (RCC_CSR) PINS*/
enum{
	LSION,LSIRDY,RMVF=24,PINRSTF=26,PORRSTF,SFTRSTF,IWDGRSTF,WWDGRSTF,LPWRSTF
};
#endif /* MCAL_RCC_REGISTER_H_ */
