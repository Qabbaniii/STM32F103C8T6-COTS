/**********************************************************************************
 *	FILE DESCRIPTION
 **********************************************************************************
 * Filename              :   GPIO_interface.h
 * Author                :   Abdullah Qabbani
 * Origin Date           :   29/02/2024
 * Version               :   1.0.0
 * Compiler              :   GCC ARM Embedded Toolchain
 * Target                :
 * Notes                 :	
 *
 **********************************************************************************/
/************************ SOURCE REVISION LOG *************************************
 *
 *  Date 	   		 Version   Author             Description
 *  29/02/2024       1.0.0     Abdullah Qabbani   Initial Release.
 *
 **********************************************************************************/


/***********************************************************************************
 * 	INCLUDES
 **********************************************************************************/
#include "../../LIB/STD_TYPES.h"
/***********************************************************************************
 *	CONSTANT MACROS & ENUMS
 ***********************************************************************************/

typedef enum
{
    PORTA = 0,
    PORTB,
    PORTC,
	PORTD,
	PORTE,
	PORTF,
	PORTG
} Port_t;
typedef enum
{
    PIN0 = 0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
    PIN8,
    PIN9,
    PIN10,
    PIN11,
    PIN12,
    PIN13,
    PIN14,
    PIN15
} Pin_t;
typedef enum
{
    ANALOG = 0,
    INPUT_FLOATING,
	INPUT_PULL
} InputMode_t;

typedef enum
{
    OUT_PUSH_PULL = 0,
	OUT_OPEN_DRAIN,
    AF_PUSH_PULL,
    AF_OPEN_DRAIN
} OutputMode_t;

typedef enum
{
    INPUT = 0,
    OUTPUT_10MHZ,
    OUTPUT_2MHZ,
    OUTPUT_50MHZ
} Mode_t;

typedef enum
{
    PIN_LOW,
    PIN_HIGH
} PinVal_t;


typedef struct
{
    Port_t 		 PortName;
    Pin_t 	  	 PinNum;
	Mode_t 		 Mode;
    InputMode_t  InputMode;
    OutputMode_t OutputMode;

} PinConfig_t;

/***********************************************************************************
 *	FUNCTION PROTOTYPES
 **********************************************************************************/

uint8_t GPIO_u8PinInit(const PinConfig_t *PinConfig);
uint8_t GPIO_u8SetPinValue(Port_t PortName, Pin_t PinNum, PinVal_t PinVal);
uint8_t GPIO_u8TogglePinValue(Port_t PortName, Pin_t PinNum);
uint8_t GPIO_u8ReadPinValue(Port_t PortName, Pin_t PinNum, PinVal_t *PinVal);

/**********************************************************************************
 *	END OF FILE: GPIO_interface.h
 **********************************************************************************/
