/*
 * Dio.h
 *
  *  Created on: Agu 23, 2020
 *      Author: Mina Nagy
 */

#ifndef DIO_H_
#define DIO_H_
/*enum{DIO_PinA0,DIO_PinA1,DIO_PinA2,DIO_PinA3,DIO_PinA4,DIO_PinA5,DIO_PinA6,DIO_PinA7
,DIO_PinB0,DIO_PinB1,DIO_PinB2,DIO_PinB3,DIO_PinB4,DIO_PinB5,DIO_PinB6,DIO_PinB7,
DIO_PinC0,DIO_PinC1,DIO_PinC2,DIO_PinC3,DIO_PinC4,DIO_PinC5,DIO_PinC6,DIO_PinC7,
DIO_PinD0,DIO_PinD1,DIO_PinD2,DIO_PinD3,DIO_PinD4,DIO_PinD5,DIO_PinD6,DIO_PinD7
}*/
#define OUTPUT 1
#define INPUT 0
#define HIGH 1
#define LOW 0
#define DIO_PinA0 0
#define DIO_PinA1 1
#define DIO_PinA2 2
#define DIO_PinA3 3
#define DIO_PinA4 4
#define DIO_PinA5 5
#define DIO_PinA6 6
#define DIO_PinA7 7
#define DIO_PinB0 8
#define DIO_PinB1 9
#define DIO_PinB2 10
#define DIO_PinB3 11
#define DIO_PinB4 12
#define DIO_PinB5 13
#define DIO_PinB6 14
#define DIO_PinB7 15
#define DIO_PinC0 16
#define DIO_PinC1 17
#define DIO_PinC2 18
#define DIO_PinC3 19
#define DIO_PinC4 20
#define DIO_PinC5 21
#define DIO_PinC6 22
#define DIO_PinC7 23
#define DIO_PinD0 24
#define DIO_PinD1 25
#define DIO_PinD2 26
#define DIO_PinD3 27
#define DIO_PinD4 28
#define DIO_PinD5 29
#define DIO_PinD6 30
#define DIO_PinD7 31
#define PA_ALL 32
#define PB_ALL 33
#define PC_ALL 34
#define PD_ALL 35
#define ALL_OUTPUT 0xff
#define ALL_HIGH 0xff
#define ALL_INPUT 0x00
#define ALL_LOW 0x00
extern void DIO_voidSetPinDirection(u8 PinNum,u8 PinDir);
extern void DIO_voidWritePinValue(u8 PinNum,u8 PinValue);
extern void DIO_voidSetPortDirection(u8 Port_Num , u8 PortDir);
extern void DIO_voidWritePortValue(u8 Port_Num , u8 PortValue);
extern u8 DIO_voidReadPinValue(u8 PinNum);
extern u8 DIO_voidReadPortValue(u8 PortNum);
#endif /* DIO_H_ */
