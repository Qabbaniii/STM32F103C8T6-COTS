/********************************************************************************
 *	FILE DESCRIPTION
 *********************************************************************************
 * Filename              :   GPIO_Program.c
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
 *  Date 	    	 Version   Author             Description
 *  29/02/2024       1.0.0     Abdullah Qabbani   Initial Release.
 *
 **********************************************************************************/

/**********************************************************************************
 * 	INCLUDES
 **********************************************************************************/
#include "stdint.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/STM32F103.h"
#include "../../LIB/ERROR_TYPES.h"
#include "GPIO_Interface.h"



/* static array of 8 pointers (the GPIO Ports) to avoid using "switch case" */

static GPIO_RegDef_t *GPIO_PORT[7] = {GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF, GPIOG};

/*********************************************************************************
 *	GLOBAL FUNCTIONS
 *********************************************************************************/

/*
 * Prototype        : uint8_t GPIO_u8PinInit(const PinConfig_t * PinConfig);
 * Description      : initializes the GPIO pin according to the input paramters
 * Parameters (in)  : PinConfig  :  A struct of paramters to config the pin like :
									PortName,pinNum,Mode,InputMode,OutputMode
 * Parameters (out) : None                          
 * return           : ErrorStatus   OK(0) means no error,NOK(1) means Undefined PORT Argument
 */                                                 
                                                    
uint8 GPIO_u8PinInit(const PinConfig_t * PinConfig) 
{
	uint8_t Local_u8ErrorStatus = OK;
		if((PinConfig->PortName <= PORTG) && (PinConfig->PinNum <= PIN15) )
		{
			uint8_t LOC_u8RegNum = (PinConfig->PinNum) / 8;
			uint8_t LOC_u8BitNum = ((PinConfig->PinNum) % 8) * 4;

			/*Selecting Mode */
			GPIO_PORT[PinConfig->PortName]->CR[LOC_u8RegNum] &= ~(TWO_BIT_MASK << LOC_u8BitNum);
			GPIO_PORT[PinConfig->PortName]->CR[LOC_u8RegNum] |= ((PinConfig->Mode) << LOC_u8BitNum);

			/*Selecting Mode Type*/
			if (PinConfig->Mode > INPUT)
			{
				GPIO_PORT[PinConfig->PortName]->CR[LOC_u8RegNum] &= ~(TWO_BIT_MASK << (LOC_u8BitNum + 2));
				GPIO_PORT[PinConfig->PortName]->CR[LOC_u8RegNum] |= ((PinConfig->OutputMode) << (LOC_u8BitNum + 2));
			}
			else
			{
				GPIO_PORT[PinConfig->PortName]->CR[LOC_u8RegNum] &= ~(TWO_BIT_MASK << (LOC_u8BitNum + 2));
				GPIO_PORT[PinConfig->PortName]->CR[LOC_u8RegNum] |= ((PinConfig->InputMode) << (LOC_u8BitNum + 2));
			}
		}
		else
		{
			Local_u8ErrorStatus = NOK;
		}
		return Local_u8ErrorStatus;
}

/*
 * Prototype        : uint8 GPIO_u8SetPinValue(Port_t PortName ,Pin_t pinNum,PinVal_t PinVal)
 * Description      : set a certain value on an output pin
 * Parameters (in)  : PortName [PORTA - PORTH] 
					  pinNum   [PIN0 - PIN15]
					  PinVal   PIN_LOW,PIN_HIGH            
 * Parameters (out) : None    
 * return           : ErrorStatus    OK(0) means no error,NOK(1) means Undefined PORT Argument
 */
 
uint8 GPIO_u8SetPinValue(Port_t portName ,Pin_t pinNum,PinVal_t PinVal)
{
	uint8_t Local_u8ErrorStatus = OK;
		if ((portName <= PORTC) && (pinNum <= PIN15))
		{
			if (PinVal == PIN_HIGH)
			{
				GPIO_PORT[portName]->ODR |= (ONE_BIT_MASK << pinNum);
			}
			else if (PinVal == PIN_LOW)
			{
				GPIO_PORT[portName]->ODR &= ~(ONE_BIT_MASK << pinNum);
			}
		}
		else
		{
			Local_u8ErrorStatus = NOK;
		}
		return Local_u8ErrorStatus;
}

/*
 * Prototype        : uint8 GPIO_u8TogglePinValue(Port_t PortName ,Pin_t pinNum);
 * Description      : toggles the value of a certain pin
 * Parameters (in)  : PortName [PORTA - PORTH] 
					  pinNum   [PIN0 - PIN15]
 * Parameters (out) : None    
 * return           : ErrorStatus    OK(0) means no error,NOK(1) means Undefined PORT Argument
 */

uint8 GPIO_u8TogglePinValue(Port_t portName ,Pin_t pinNum)
{
	uint8_t Local_u8ErrorStatus = OK;
	if ((portName <= PORTC) && (pinNum <= PIN15))
	{
		GPIO_PORT[portName]->ODR ^= (ONE_BIT_MASK << pinNum);
	}
	else
	{
		Local_u8ErrorStatus = NOK;
	}
	return Local_u8ErrorStatus;
}

/*
 * Prototype        : uint8 GPIO_vReadPinValue(PORT_t Port ,Pin_t pinNum,PinVal_t* PinVal);
 * Description      : reads the value of a certain pin
 * Parameters (in)  : PortName [PORTA - PORTH]
					  pinNum   [PIN0 - PIN15]
 * Parameters (out) : PinVal   0,1   
 * return           : ErrorStatus
 */
 uint8 GPIO_u8ReadPinValue(Port_t portName ,Pin_t pinNum,PinVal_t* PinVal)
 {
	 uint8_t Local_u8ErrorStatus = OK;
	 	if ((portName <= PORTC) && (pinNum <= PIN15))
	 	{
	 		*PinVal = (GPIO_PORT[portName]->IDR >> pinNum) & ONE_BIT_MASK;
	 	}
	 	else
	 	{
	 		Local_u8ErrorStatus = NOK;
	 	}
	 	return Local_u8ErrorStatus;
 }

 /*
  * Prototype   : void GPIO_u8SetFourPortValue(PORT_t Port, Pin_t PinNum, PinVal_t PinVal)
  * Description : Set Value of 4 Pins
  * Arguments   : PORT(PORTA , PORTB,PORTC)
  *               PinNum(PIN1 ..... PIN15)
  *               pinVal(0x00 to 0x0F)
  * return      : void
  */
 void GPIO_u8SetFourPortValue(Port_t PortName, Pin_t PinNum, uint8_t PinVal)
 {
 	uint32_t LOC_u32Value = 0;
 	GPIO_PORT[PortName]->ODR &= ~(FOUR_BIT_MASK << PinNum);
 	LOC_u32Value = GPIO_PORT[PortName]->ODR | (PinVal << PinNum);
 	GPIO_PORT[PortName]->ODR = LOC_u32Value;
 }
/**************************************************************************************
 *  END OF FILE: GPIO_Program.c
 **************************************************************************************/
