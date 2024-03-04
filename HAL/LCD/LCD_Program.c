/********************************************************************************
 *	FILE DESCRIPTION
 *********************************************************************************
 * Filename              :   LCD_prog.c
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
#include <stdint.h>
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "../../MCAL/RCC/RCC_Interface.h"
#include "LCD_Interface.h"
#include "LCD_Config.h"
#include "LCD_Private.h"
#include "../../MCAL/SysTick/SysTick_Interface.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/



/*********************************************************************************
 *	GLOBAL FUNCTIONS
 *********************************************************************************/

/*
 * Prototype   : void LCD_vInit(void);
 * Description : Initialize LCD
 * Arguments   : void
 * return      : void
 */
void LCD_vInit(void)
{

	uint8_t FUNCTION_SET_4BIT = 0x20 ;
	/* Initialize Pins */
	GPIO_u8PinInit(&RS);
	GPIO_u8PinInit(&E);
	GPIO_u8PinInit(&D4);
	GPIO_u8PinInit(&D5);
	GPIO_u8PinInit(&D6);
	GPIO_u8PinInit(&D7);
	/* Wait for more than 30 ms */
	vSysTick_Delay_ms(30);

	/*FUNCTION SET 4 BIT INTIALIZATION*/
	#if configNUMBER_OF_LINES == 1
		CLR_BIT( FUNCTION_SET_4BIT , NUMBER_OF_LINES_BIT ) ;
	#elif configNUMBER_OF_LINES == 2
		SET_BIT( FUNCTION_SET_4BIT , NUMBER_OF_LINES_BIT ) ;
	#endif

	#if configFONT_SIZE_5x8 == 1
		CLR_BIT( FUNCTION_SET_4BIT , FONT_SIZE_BIT ) ;
	#elif configFONT_SIZE_5x8 == 0
		SET_BIT( FUNCTION_SET_4BIT , FONT_SIZE_BIT ) ;
	#endif

		LCD_vSendCommand(0x20);
		LCD_vSendCommand(FUNCTION_SET_4BIT);

		/*Display ON/OFF Control*/
		LCD_vSendCommand(CURSOR_MODE);

		/*Clear Display*/
		LCD_vSendCommand(CLR_SCREEN);

		/*Return Cursor Home*/
		LCD_vSendCommand(RETURN_HOME);
		LCD_vMoveCursor(1, 1);

		vSysTick_Delay_ms(20);

}
/*
 * Prototype   : void LCD_vSendCommand(uint8_t copy_u8Command);
 * Description : Send command to LCD
 * Arguments   : uint8_t copy_u8Command
 * return      : void
 */
void LCD_vSendCommand(uint8_t copy_u8Command)
{
	/* Mirroring Commands */
	uint8_t Counter=0 , Command_Reversed=0,Bit=0;
	for (Counter=0;Counter<8;Counter++)
	{

		Bit = GET_BIT(copy_u8Command,Counter);
		if(Bit==1)
			SET_BIT(Command_Reversed,(7-Counter));
		else if (Bit==0)
			CLR_BIT(Command_Reversed,(7-Counter));

	}
	/*set RS pin to low for command*/
	GPIO_u8SetPinValue(RS.PortName, RS.PinNum, PIN_LOW);

	/*send command to data pins*/
	GPIO_u8SetFourPortValue(PORTB, PIN12, (Command_Reversed & 0x0F));

	/*send enable pulse*/
	LCD_vSendEnablePulse();

	vSysTick_Delay_us(200);

	/*send command to data pins*/

	GPIO_u8SetFourPortValue(PORTB, PIN12, ((Command_Reversed >> 4) & 0x0F));
	/*send enable pulse*/
	LCD_vSendEnablePulse();
}

void LCD_vClearScreen(void)
{
	LCD_vSendCommand(CLR_SCREEN);
}

static void LCD_vSendEnablePulse(void)
{
	GPIO_u8SetPinValue(E.PortName, E.PinNum, PIN_HIGH);
	vSysTick_Delay_ms(2);
	GPIO_u8SetPinValue(E.PortName, E.PinNum, PIN_LOW);
	vSysTick_Delay_ms(2);
}
/*
 * Prototype   : void LCD_vSendChar(uint8_t copy_u8Data);
 * Description : Send data to LCD
 * Arguments   : uint8_t copy_u8Data
 * return      : void
 */
void LCD_vSendChar(uint8_t copy_u8Data)
{
	uint8_t Counter=0 , Command_Reversed=0 ,Bit=0;
	for (Counter=0;Counter<8;Counter++)
	{
		Bit = GET_BIT(copy_u8Data,Counter);
		if(Bit==1)
			SET_BIT(Command_Reversed,(7-Counter));
		else if (Bit==0)
			CLR_BIT(Command_Reversed,(7-Counter));
	}
	/*set RS pin to low for command*/
	GPIO_u8SetPinValue(RS.PortName, RS.PinNum, PIN_HIGH);

	/*send Data to data pins*/
	GPIO_u8SetFourPortValue(PORTB, PIN12, (Command_Reversed & 0x0F));
	/*send enable pulse*/
	LCD_vSendEnablePulse();

	/*send Data to data pins*/
	GPIO_u8SetFourPortValue(PORTB, PIN12, ((Command_Reversed >> 4) & 0x0F));
	/*send enable pulse*/
	LCD_vSendEnablePulse();
}
/*
 * Prototype   : void LCD_vSendString(const char *LOC_u8counter);
 * Description : Send string to LCD
 * Arguments   : const char *copy_String
 * return      : void
 */
void LCD_vSendString(const char *copy_String)
{
	uint8_t LOC_u8counter=0;
	while(copy_String[LOC_u8counter]!='\0')
	{
		LCD_vSendChar(copy_String[LOC_u8counter]);
		LOC_u8counter++;
	}

}
/*
 * Prototype   : void LCD_vMoveCursor(uint8_t copy_u8Row, uint8_t copy_u8Coloumn);
 * Description : Go to specific position in LCD
 * Arguments   : uint8_t copy_u8Row, uint8_t copy_u8Coloumn
 * return      : void
 */
void LCD_vMoveCursor(uint8_t copy_u8Row,uint8_t copy_u8Coloumn)
{
	uint8_t data ;
	if(copy_u8Row>2||copy_u8Row<1||copy_u8Coloumn>16||copy_u8Coloumn<1)
	{
		data=0x80;
	}
	else if(copy_u8Row==1)
	{
		data=0x80+copy_u8Coloumn-1 ;
	}
	else if (copy_u8Row==2)
	{
		data=0xc0+copy_u8Coloumn-1;
	}
	LCD_vSendCommand(data);
	vSysTick_Delay_ms(1);

}
/*
 * Prototype   : void LCD_vWriteSpecialChar(uint8_t *copy_u8Pattern, uint8_t copy_u8PatternNumber, uint8_t copy_u8XPos, uint8_t copy_u8YPos);
 * Description : Write special character in LCD
 * Arguments   : uint8_t *copy_u8Pattern, uint8_t copy_u8PatternNumber, uint8_t copy_u8XPos, uint8_t copy_u8YPos
 * return      : void
 */
void LCD_vWriteSpecialChar(uint8_t *copy_u8Pattern, uint8_t copy_u8PatternNumber, uint8_t copy_u8XPos, uint8_t copy_u8YPos)
{
	uint8_t copy_u8CGRAMAddress=0,copy_u8Iterator=0;
	/*calculate cgram address whose each block is 8 bytes*/
	copy_u8CGRAMAddress=copy_u8PatternNumber*8;
	/*send cgram command to lcd ith set bitting 6 , clearing bit 7 */
	LCD_vSendCommand(copy_u8CGRAMAddress+64);
	/*write a pattern into cgram*/
	for(copy_u8Iterator=0;copy_u8Iterator<8;copy_u8Iterator++)
	{
		LCD_vSendChar(copy_u8Pattern[copy_u8Iterator]);
	}
	/*go back to ddram*/
	LCD_vMoveCursor(copy_u8XPos, copy_u8YPos);
	/*display the pattern written in CGram*/
	LCD_vSendChar(copy_u8PatternNumber);
}
/*
 * Prototype   : void LCD_vSendNumber(int32_t copy_S32Number);
 * Description : Send number to LCD
 * Arguments   : int32_t copy_S32Number
 * return      : void
 */
void LCD_vSendNumber(int32_t copy_S32Number)
{
	int32_t copy_S32Nu = 1;
	if(copy_S32Number == 0)
	{
		LCD_vSendChar('0');
	}
	else if(copy_S32Number <0)
	{
		LCD_vSendChar('-');
		copy_S32Number *=-1 ;
	}
	while(copy_S32Number != 0)
	{
		copy_S32Nu = ((copy_S32Nu * 10) + (copy_S32Number % 10));
		copy_S32Number = (copy_S32Number / 10);
	}
	while(copy_S32Nu !=1 )
	{
		LCD_vSendChar((copy_S32Nu % 10) + 48);
		copy_S32Nu = (copy_S32Nu/10);
	}

}
/*
 * Prototype   : void LCD_vShiftLeft(void);
 * Description : Shift left
 * Arguments   : void
 * return      : void
 */

