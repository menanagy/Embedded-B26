/*
 * Led.h
 *
 *  Created on: Agu 23, 2020
 *      Author: Mina Nagy
 */
//Embedded mmmmmmmmmmmm
#ifndef LED_H_
#define LED_H_
#define OUTPUT 1
#define HIGH 1
#define LOW 0
#define LED_PinA0 0
#define LED_PinA1 1
#define LED_PinA2 2
#define LED_PinA3 3
#define LED_PinA4 4
#define LED_PinA5 5
#define LED_PinA6 6
#define LED_PinA7 7
#define LED_PinB0 8
#define LED_PinB1 9
#define LED_PinB2 10
#define LED_PinB3 11
#define LED_PinB4 12
#define LED_PinB5 13
#define LED_PinB6 14
#define LED_PinB7 15
#define LED_PinC0 16
#define LED_PinC1 17
#define LED_PinC2 18
#define LED_PinC3 19
#define LED_PinC4 20
#define LED_PinC5 21
#define LED_PinC6 22
#define LED_PinC7 23
#define LED_PinD0 24
#define LED_PinD1 25
#define LED_PinD2 26
#define LED_PinD3 27
#define LED_PinD4 28
#define LED_PinD5 29
#define LED_PinD6 30
#define LED_PinD7 31
#define LED_ALL_PA 32
#define LED_ALL_PB 33
#define LED_ALL_PC 34
#define LED_ALL_PD 35
extern void Led_voidLedDefine(u8 PinName);
extern void Led_voidLedOn(u8 PinName);
extern void Led_voidLedOff(u8 PinName);
extern void Leds_voidShapes(u8 PortName);
#endif /* LED_H_ */
