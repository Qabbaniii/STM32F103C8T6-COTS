/********************************************************************************
 *	FILE DESCRIPTION
 *********************************************************************************
 * Filename              :   SysTick_interface.c
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
#ifndef SYSTICK_SYSTICK_INTERFACE_H_
#define SYSTICK_SYSTICK_INTERFACE_H_

/***********************************************************************************
 * 	INCLUDES
 **********************************************************************************/
#include "../../LIB/STD_TYPES.h"

/***********************************************************************************
 *	FUNCTION PROTOTYPES
 **********************************************************************************/

void vSysTick_Delay_ms(uint32 Copy_u32Time_ms);
void vSysTick_Delay_us(uint32 Copy_u32Time_us);

#endif /* SYSTICK_SYSTICK_INTERFACE_H_ */
