/********************************************************************************
 *	FILE DESCRIPTION
 *********************************************************************************
 * Filename              :   SysTick_register.c
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
#ifndef MCAL_SYSTICK_SYSTICK_REGISTER_H_
#define MCAL_SYSTICK_SYSTICK_REGISTER_H_



enum
{
	SYST_ENABLE,
	SYST_TICKINT,
	SYST_CLKSOURCE,
	SYST_COUNTFLAG =16
	};

#define RELOAD  0

#define CURRENT 0




#endif /* MCAL_SYSTICK_SYSTICK_REGISTER_H_ */
