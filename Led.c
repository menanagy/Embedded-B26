/*
 * Led.c
 *
 *  Created on: Agu 23, 2020
 *      Author: Mina Nagy
 */
#include"Standard_Types.h"
#include"utils.h"
#include "DIO.h"
#include"Led.h"
#include<avr/delay.h>
static void shape1(u8 PortName);
static void shape2(u8 PortName);
static void shape3(u8 PortName);
static void shape4(u8 PortName);
static void shape5(u8 PortName);
extern void Led_voidLedDefine(u8 PinName)
{
	if(PinName<32)
	DIO_voidSetPinDirection(PinName,OUTPUT);//0:31,1
	else
	DIO_voidSetPortDirection(PinName,ALL_OUTPUT);//0xff
}
extern void Led_voidLedOn(u8 PinName){//Positive Logic
	if(PinName<32)
	DIO_voidWritePinValue(PinName,LOW);
	else
	DIO_voidWritePortValue(PinName,ALL_LOW);
}
extern void Led_voidLedOff(u8 PinName)
{
		if(PinName<32)
		DIO_voidWritePinValue(PinName,HIGH);
		else
		DIO_voidWritePortValue(PinName,ALL_HIGH);
}
extern void Leds_void_5_Shapes(u8 PortName){

	shape1(PortName);
	shape2(PortName);
	shape3(PortName);
	shape4(PortName);
	shape5(PortName);

}
static void shape1(u8 PortName)
{
	u8 i=0;
	for(i=0; i<3; i++)
	{
		DIO_voidWritePortValue(PortName,ALL_HIGH);
		_delay_ms(500);
		DIO_voidWritePortValue(PortName,ALL_LOW);
		_delay_ms(500);
	}
}
static void shape2(u8 PortName)
{
	u8 arr[]={1,2,4,8,16,32,64,128,256};
	u8 i=0;
	for(i=0; i<8;  i++)
	{
		DIO_voidWritePortValue(PortName,arr[i]);
			_delay_ms(500);
	}
}
static void shape3(u8 PortName)
{
	u8 arr[]={0b00000000,0b00000001,0b00000011,0b00000111,0b00001111
		,0b00011111,0b00111111,0b01111111,0b11111111};
	u8 i=0;
	for(i=0; i<9;  i++)
	{
		DIO_voidWritePortValue(PortName,arr[i]);
			_delay_ms(500);
	}
}
static void shape4(u8 PortName)
{
	u8 arr[]={0b11111111,0b01111111,0b00111111,0b00011111,
			0b00001111,0b00000111,0b00000011,0b00000001,0};
	u8 i=0;
	for(i=0; i<9;  i++)
	{
		DIO_voidWritePortValue(PortName,arr[i]);
			_delay_ms(500);
	}
}
static void shape5(u8 PortName)
{
	u8 arr[]={0B00011000,0b00111100,0B01111110,0B111111111,0B00000000};
	u8 i=0;
	for(i=0; i<5;  i++)
	{
		DIO_voidWritePortValue(PortName,arr[i]);
			_delay_ms(500);
	}
}

/*	if(PinName>31){
		DIO_voidWritePinValue(PinName,ALL_LOW);//ALL LOW
	}
	else
	{*/
