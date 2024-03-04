/********************************************************************************
 *	FILE DESCRIPTION
 *********************************************************************************
 * Filename              :   LCD_interface.c
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
#ifndef LCD_LCD_INTERFACE_H_
#define LCD_LCD_INTERFACE_H_

typedef struct
{
    PinConfig_t RS;
    PinConfig_t E;
    PinConfig_t D[4];
} LCD_PINS_t;
/*******************************************************************************
 *                      Function Decleration                                   *
 *******************************************************************************/
void LCD_vInit(void);

void LCD_vSendCommand(uint8_t copy_u8Command);

void LCD_vSendChar(uint8_t copy_u8Data);

void LCD_vSendString(const char *copy_String);

void LCD_vMoveCursor(uint8_t copy_u8XPos, uint8_t copy_u8YPos);

void LCD_WriteSpecialChar(uint8_t *copy_u8Pattern, uint8_t copy_u8PatternNumber, uint8_t copy_u8XPos, uint8_t copy_u8YPos);

void LCD_vSendNumber(int32_t copy_S32Number);
static void LCD_vSendEnablePulse();





#endif /* LCD_LCD_INTERFACE_H_ */
