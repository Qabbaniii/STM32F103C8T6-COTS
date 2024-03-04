/********************************************************************************
 *	FILE DESCRIPTION
 *********************************************************************************
 * Filename              :   LCD_private.c
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
#ifndef LCD_LCD_PRIVATE_H_
#define LCD_LCD_PRIVATE_H_

#include"../../MCAL/GPIO/GPIO_interface.h"

#define LCD_DATA_PORT           PORTB

#define LCD_DATA_PIN4           PIN15

#define LCD_DATA_PIN5           PIN14

#define LCD_DATA_PIN6           PIN13

#define LCD_DATA_PIN7           PIN12

#define LCD_CTRL_PORT           PORTA

#define LCD_RS_PIN              PIN11

#define LCD_E_PIN               PIN8



static PinConfig_t RS =
{
		.PortName = LCD_CTRL_PORT,
		.PinNum = LCD_RS_PIN,
		.OutputMode = OUT_PUSH_PULL,
		.Mode=OUTPUT_10MHZ,
};

static PinConfig_t E =
{
		.PortName = LCD_CTRL_PORT,
		.PinNum = LCD_E_PIN,
		.OutputMode = OUT_PUSH_PULL,
		.Mode=OUTPUT_10MHZ,
};
static PinConfig_t D4 =
{
		.PortName = LCD_DATA_PORT,
		.PinNum = LCD_DATA_PIN4,
		.OutputMode = OUT_PUSH_PULL,
		.Mode=OUTPUT_10MHZ,
};
static PinConfig_t D5 =
{
		.PortName = LCD_DATA_PORT,
		.PinNum = LCD_DATA_PIN5,
		.OutputMode = OUT_PUSH_PULL,
		.Mode=OUTPUT_10MHZ,
};
static PinConfig_t D6 =
{
		.PortName = LCD_DATA_PORT,
		.PinNum = LCD_DATA_PIN6,
		.OutputMode = OUT_PUSH_PULL,
		.Mode=OUTPUT_10MHZ,
};
static PinConfig_t D7 =
{
		.PortName = LCD_DATA_PORT,
		.PinNum = LCD_DATA_PIN7,
		.OutputMode = OUT_PUSH_PULL,
		.Mode=OUTPUT_10MHZ,
};


/*COMMANDS*/

#define SET_DDRAM_ADDRESS  ( 0x80 )
#define SET_CGRAM_ADDRESS  ( 0x40 )

/*index of Commands*/
#define CLR_SCREEN 0x01
#define RETURN_HOME 0x02

#define DISPLAY_ON_CURSOR_ON 0x0e
#define DISPLAY_ON_CURSOR_OFF 0x0c
#define DISPLAY_OFF_CURSOR_ON 0x0a
#define DISPLAY_OFF_CURSOR_OFF 0x08
#define DISPLAY_ON_CURSOR_BLINKUNG 0x0f

#define SHIFT_CURSOR_LEFT 0x10
#define SHIFT_CURSOR_RIGHT 0x14
#define SHIFT_DISPLAY_LEFT 0x18
#define SHIFT_DISPLAY_RIGHT 0x1c

#define BEDGINNING_1st_LINE 0x80
#define BEDGINNING_2nd_LINE 0xc0


#define ENTRY_MODE 0x06

/*to be edited*/
#define LCD_DATA_USED_PORT       DIO_u8_PORTA
#define LCD_CONTROL_USED_PORT    DIO_u8_PORTB

#define CURSOR_MODE DISPLAY_ON_CURSOR_BLINKUNG



/*SOME VALUES*/

#define LOCATION_SIZE_IN_CGRAM        8
#define MAX_NUMBER_OF_DIGITS_IN_S32  10
#define ZERO_ASCII                   48





#define LCD_8BIT_MODE    1
#define LCD_4BIT_MODE    2


#define NUMBER_OF_LINES_BIT   3
#define FONT_SIZE_BIT         2

#define RIGHT_LEFT_SHIFT_BIT  2

#define LCD_16X2  1
#define LCD_20X4  2

#endif /* LCD_LCD_PRIVATE_H_ */
