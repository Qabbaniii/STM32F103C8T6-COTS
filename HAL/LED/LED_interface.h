
/**********************************************************************************
 *	FILE DESCRIPTION
 **********************************************************************************
 * Filename              :   LED_interface.h
 * Author                :   Abdullah Qabbani
 * Origin Date           :   01/03/2024
 * Version               :   1.0.0
 * Compiler              :   GCC ARM Embedded Toolchain
 * Target                :
 * Notes                 :	
 *
 **********************************************************************************/
/************************ SOURCE REVISION LOG *************************************
 *
 *  Date 	    	Version   Author             Description
 *  01/03/2024       1.0.0     Abdullah Qabbani   Initial Release.
 *
 **********************************************************************************/


#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

#include"../../MCAl/GPIO/GPIO_interface.h"

    /*  Function Prototype  */
void LED_vInit   (uint8 copy_u8PortName,uint32 copy_u32PinNumber);
void LED_vOn   (uint8 copy_u8PortName,uint32 copy_u32PinNumber);
void LED_vOff  (uint8 copy_u8PortName,uint32 copy_u32PinNumber);
void LED_vToggle (uint8 copy_u8PortName,uint32 copy_u32PinNumber);
void LED_vGetStatus (uint8 copy_u8PortName,uint32 copy_u32PinNumber);
#endif /* HAL_LED_LED_INTERFACE_H_ */
