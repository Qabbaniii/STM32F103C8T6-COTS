/********************************************************************************
 *	FILE DESCRIPTION
 *********************************************************************************
 * Filename              :   SysTick_Program.c
 * Author                :   Abdullah Qabbani
 * Origin Date           :   03/03/2024
 * Version               :   1.0.0
 * Compiler              :   GCC ARM Embedded Toolchain
 * Target                :
 * Notes                 :
 *
 *********************************************************************************/
/************************ SOURCE REVISION LOG *************************************
 *
 *  Date 	    	 Version   Author             Description
 *  03/03/2024       1.0.0     Abdullah Qabbani   Initial Release.
 *
 **********************************************************************************/
/*==============================================================================================================================================
 * Includes
 *==============================================================================================================================================*/
#include <stdint.h>
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STM32F103.h"
#include "SysTick_interface.h"
#include "SysTick_private.h"
#include "SysTick_register.h"


/*
 * Prototype   : void vSysTick_Delay_ms(uint32 Copy_u32Time_ms)
 * Description : make a delay by Systick in mile Second
 * Arguments   : Copy_u32Time_ms : Time delay that you need in ms
 * return      : none
 */
void vSysTick_Delay_ms(uint32 Copy_u32Time_ms)
{
	/*Store Reload Value*/
	SysTick->RVR = (Copy_u32Time_ms * 1000);
	/*Select SysTick Source AHB/8*/
	CLR_BIT(SysTick->CSR,SYST_CLKSOURCE);
	/*Enable SysTick*/
	SET_BIT(SysTick->CSR,SYST_ENABLE);
	/*Wait Until Count Flag Set*/
	while (((SysTick->CSR) & (1 << SYST_COUNTFLAG)) == 0)	;
	/*disable SysTick*/
	SysTick->CSR &= ~(1 << SYST_ENABLE);
}

/*
 * Prototype   : void vSysTick_Delay_us(uint32 Copy_u32Time_us)
 * Description : make a delay by Systick in micro Second
 * Arguments   : Copy_u32Time_us : Time delay that you need in us
 * return      : none
 */
void vSysTick_Delay_us(uint32 Copy_u32Time_us)
{
	/*Store Reload Value*/
	SysTick->RVR = (Copy_u32Time_us);
	/*Select SysTick Source AHB/8*/
	CLR_BIT(SysTick->CSR,SYST_CLKSOURCE);
	/*Enable SysTick*/
	SET_BIT(SysTick->CSR,SYST_ENABLE);
	/*Wait Until Count Flag Set*/
	while (((SysTick->CSR) & (1 << SYST_COUNTFLAG)) == 0)	;
	/*disable SysTick*/
	SysTick->CSR &= ~(1 << SYST_ENABLE);
}
