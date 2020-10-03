/*
 * Keypad.h
 *
 *  Created on: 27 Agu 2020
 *      Author: Mina Nagy
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_
extern void Keypad_voidInit(void);
extern u8 Keypad_u8ReadButton(u8 Button_Number);
extern u8 keypad_u8GetKey(u8 Keypad_Symbol[4][4]);
#endif /* KEYPAD_H_ */
