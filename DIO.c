/*
 * Dio.c
 *  Created on: Agu 23, 2020
 *      Author: Mina Nagy
 */
#include "Standard_Types.h"
#include "utils.h"
#include "DIO.h"
#define DDRA  (*(volatile u8 * )0x3A)//DDR=0x04; ==> (*(volatile u8*)00x3A)=0x04;
#define DDRB  (*(volatile u8 * )0x37)
#define DDRC  (*(volatile u8 * )0x34)
#define DDRD  (*(volatile u8 * )0x31)
#define PINA  (*(volatile u8 * )0x39)
#define PINB  (*(volatile u8 * )0x36)
#define PINC  (*(volatile u8 * )0x33)
#define PIND  (*(volatile u8 * )0x30)
#define PORTA (*(volatile u8 * )0x3B)
#define PORTB (*(volatile u8 * )0x38)
#define PORTC (*(volatile u8 * )0x35)
#define PORTD (*(volatile u8 * )0x32)
//DIO_voidSetPinDirection(DIO_PIN_C0,INPUT);//==>i/p
extern void DIO_voidSetPinDirection(u8 PinNum , u8 PinDir)//0:31 , 1
{
	if(PinNum>=0 && PinNum<=7)//Pin 0 to 7 ==>PORTA
	{
		assign_bit(DDRA,PinNum,PinDir);
	}
	else if(PinNum>=8 && PinNum<=15)//Pin 8 to 15 ==>PORTB ==>0:7
	{
		assign_bit(DDRB,PinNum%8,PinDir);//PB 0:7==>8%8 : 15%8
	}
	else if(PinNum>=16 && PinNum<=23)//Pin 15 to 23 ==>PORTc
	{
		assign_bit(DDRC,PinNum%8,PinDir);
	}
	else if(PinNum>=24 && PinNum<=31)//Pin 24 to 31 ==>PORTD
	{
		assign_bit(DDRD,PinNum%8,PinDir);
	}
}
//DIO_voidWritePinValue(DIO_PIN_C0,HIGH);//=> Enable Internal Pull UP
extern void DIO_voidWritePinValue (u8 PinNum ,u8 PinValue)//O/P==> LOW , HIGH ,INPUT ==> HIGH , PULLUP
{
	if(PinNum>=0 && PinNum<=7)
	{
		assign_bit(PORTA,PinNum,PinValue);
	}
	else if(PinNum>=8 && PinNum<=15)
	{
		assign_bit(PORTB,PinNum%8,PinValue);
	}
	else if(PinNum>=16 && PinNum<=23)
	{
		assign_bit(PORTC,PinNum%8,PinValue);
	}
	else if(PinNum>=24 && PinNum<=31)
	{
		assign_bit(PORTD,PinNum%8,PinValue);
	}
}
extern u8 DIO_voidReadPinValue(u8 PinNum)
{
	u8 Read_Value=255;

	if(PinNum>=0 && PinNum<=7)
	{
		Read_Value=get_bit(PINA,PinNum);
	}
	else if(PinNum>=8 && PinNum<=15)
	{
		Read_Value=get_bit(PINB,PinNum%8);
	}
	else if(PinNum>=16 && PinNum<=23)
	{
		Read_Value=get_bit(PINC,PinNum%8);
	}
	else if(PinNum>=24 && PinNum<=31)
	{
		Read_Value=get_bit(PIND,PinNum%8);
	}
	return Read_Value;
}
extern void DIO_voidSetPortDirection(u8 Port_Num , u8 PortDir)//32:35 ,ALL_INPUT==>0x00,ALL_OUPTUT==>0xff
{
	switch(Port_Num)
	{
		case 32: DDRA=PortDir; break;//ALLO/p or //ALL I/p
		case 33: DDRB=PortDir; break;
		case 34: DDRC=PortDir; break;
		case 35: DDRD=PortDir; break;
	}
}
extern void DIO_voidWritePortValue(u8 Port_Num , u8 PortValue)
{
	switch(Port_Num)
	{
		case 32: PORTA=PortValue; break;//All HIGH or ALL LOW
		case 33: PORTB=PortValue; break;
		case 34: PORTC=PortValue; break;
		case 35: PORTD=PortValue; break;
	}
}
extern u8 DIO_voidReadPortValue(u8 Port_Num)
{
	u8 Read=0;
	switch(Port_Num)
	{
		case 32: Read=PINA; break;//Read All Pin
		case 33: Read=PINB; break;
		case 34: Read=PINC; break;
		case 35: Read=PIND; break;
	}
	return Read;
}

