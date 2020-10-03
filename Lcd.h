/*
 * Lcd.h
 *
 *  Created B26 Embedded
 *      Author: mina
 */

#ifndef LCD_H_
#define LCD_H_
extern void Lcd_Init(void);
extern void Lcd_voidWriteData(u8 data);
extern void Lcd_voidWriteCommand(u8 Command);
extern void Lcd_voidSetCursar(u8 row,u8 coloum);
extern void Lcd_voidWriteString(u8* g);
extern void Lcd_voidWriteNum(u64 Num);
extern void Lcd_voidCreateChar(u8 Num,u8* Symbol);
extern void LCD_voidClear(void);
extern void LCD_voidClear_RoW(u8 Row);
#endif /* LCD_H_ */
