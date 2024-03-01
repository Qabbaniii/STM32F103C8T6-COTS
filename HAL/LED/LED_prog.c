/**********************************************************************************
 *	FILE DESCRIPTION
 **********************************************************************************
 * Filename              :   LED_proj.h
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
 *  Date 	    	 Version   Author             Description
 *  01/03/2024       1.0.0     Abdullah Qabbani   Initial Release.
 *
 **********************************************************************************/


#include <stdio.h>
#include"LED_interface.h"



 void LED_vInit  (uint8 copy_u8PortName,uint32 copy_u32PinNumber)
{
	  PinConfig_t PinConfig = {
			copy_u8PortName,
			copy_u32PinNumber,
			OUTPUT_10MHZ,
			OUT_PUSH_PULL};
	GPIO_u8PinInit(& PinConfig);
}

void LED_vOn (uint8 copy_u8PortName,uint32 copy_u32PinNumber){

	GPIO_u8SetPinValue(copy_u8PortName,copy_u32PinNumber,PIN_HIGH);
}

void LED_vOff (uint8 copy_u8PortName,uint32 copy_u32PinNumber){

	GPIO_u8SetPinValue(copy_u8PortName,copy_u32PinNumber,PIN_LOW);
}

void LED_vToggle (uint8 copy_u8PortName,uint32 copy_u32PinNumber)
{
	
	GPIO_u8TogglePinValue(copy_u8PortName,copy_u32PinNumber);
}


void LED_u8GetStatus (uint8 copy_u8PortName,uint32 copy_32PinNumber,PinVal_t *PinVal)
{

	GPIO_u8ReadPinValue(copy_u8PortName,copy_32PinNumber,PinVal);
}
