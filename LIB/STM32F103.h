/********************************************************************************
 *	FILE DESCRIPTION
 ********************************************************************************
 * Filename              :   STM32f103.h
 * Author                :   Abdullah Qabbani
 * Origin Date           :   29/02/2024
 * Version               :   1.0.0
 * Compiler              :   GCC ARM Embedded Toolchain
 * Target                :
 * Notes                 :	
 *
 *********************************************************************************/
/************************ SOURCE REVISION LOG *************************************
 *
 *  Date 	 	     Version   Author             Description
 *  29/02/2024       1.0.0     Abdullah Qabbani   Initial Release.
 *
 **********************************************************************************/
#ifndef STM32F103_H_
#define STM32F103_H_

/********************************************************************************
 *	Various Memories Base Address
 ********************************************************************************/

#define FLASH_BASE_ADDRESS		0x08000000UL
#define SRAM_BADE_ADDRESS		0x20000000UL


/********************************************************************************
 *	AHB1 Peripheral Base Address 
 ********************************************************************************/
 
 /**************************   GPIOx Base Address     ***************************/
 #define GPIOA_BASE_ADDRESS		0x40010800UL
 #define GPIOB_BASE_ADDRESS		0x40010C00UL
 #define GPIOC_BASE_ADDRESS		0x40011000UL
 #define GPIOD_BASE_ADDRESS		0x40011400UL
 #define GPIOE_BASE_ADDRESS		0x40011800UL
 #define GPIOF_BASE_ADDRESS		0x40011C00UL
 #define GPIOG_BASE_ADDRESS		0x40012000UL
 /***************************   RCC Base Address     ***************************/
 #define RCC_BASE_ADDRESS		0x40021000UL
 
/********************************************************************************
 *	AHB2 Peripheral Base Address 
 ********************************************************************************/
 
 /********************************************************************************
 *	AHB3 Peripheral Base Address 
 ********************************************************************************/
 
/********************************************************************************
 *	APB1 Peripheral Base Address 
 ********************************************************************************/
  
/********************************************************************************
 *  APB2 Peripheral Base Address 
 ********************************************************************************/
  

/********************************************************************************
 *	Various Registers Definition
 ********************************************************************************/

/********************   GPIO Registers Definition Structure    ********************/

typedef struct
{
	volatile uint32_t CR[2];
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
} GPIO_RegDef_t;

/********************   RCC Registers Definition Structure    ********************/

typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
} RCC_REG_t; 


/********************************************************************************
 *	Various PREPHIRAL DEFINITION
 ********************************************************************************/

/********************   GPIO peripheral Definitions     ********************/

#define GPIOA ((GPIO_RegDef_t *)GPIOA_BASE_ADDRESS)
#define GPIOB ((GPIO_RegDef_t *)GPIOB_BASE_ADDRESS)
#define GPIOC ((GPIO_RegDef_t *)GPIOC_BASE_ADDRESS)
#define GPIOD ((GPIO_RegDef_t *)GPIOD_BASE_ADDRESS)
#define GPIOE ((GPIO_RegDef_t *)GPIOE_BASE_ADDRESS)
#define GPIOF ((GPIO_RegDef_t *)GPIOF_BASE_ADDRESS)
#define GPIOG ((GPIO_RegDef_t *)GPIOG_BASE_ADDRESS)

/********************   RCC peripheral Definitions     ********************/

#define RCC  ((RCC_REG_t*)RCC_BASE_ADDRESS)

 

/*********************************************************************************
 *	END OF FILE: STM32F103.h
 *********************************************************************************/
 #endif
