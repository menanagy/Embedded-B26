/*
 * Lcd.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: mina
 */

#include"Standard_Types.h"
#include"DIO.h"
#include"Lcd.h"
#include"Lcd_Cfg.h"
#include<avr/delay.h>
extern void Lcd_Init(void)
{
	//MICROCONTROLLER Configuration ==> LCD
	DIO_voidSetPortDirection(lcdPort,ALL_OUTPUT);//PORTLCD==>o/P
	DIO_voidSetPinDirection(RS,OUTPUT);//==>RS==>O/P
	DIO_voidSetPinDirection(En,OUTPUT);
	DIO_voidSetPinDirection(RW,OUTPUT);//==> RW
	//LCD INitialization
	_delay_ms(50);//DataSheet ==> 37ms
	Lcd_voidWriteCommand(0b00111000);//Function Set
	_delay_ms(1);
	Lcd_voidWriteCommand(0b00001100);//Display ON OFF
	_delay_ms(1);
	Lcd_voidWriteCommand(0b00000001);//Clear
}
extern void Lcd_voidWriteData(u8 data)
{
	DIO_voidWritePortValue(lcdPort,data);//PORTLCD ==> DATA
	DIO_voidWritePinValue(RS,HIGH);//Choose Data
	DIO_voidWritePinValue(RW,LOW);//Write
	DIO_voidWritePinValue(En,HIGH);//Pulse OPen Door
	_delay_ms(1);
	DIO_voidWritePinValue(En,LOW);
	_delay_ms(2);
}
extern void Lcd_voidWriteCommand (u8 Command)
{
	DIO_voidWritePortValue(lcdPort,Command);//Command ==> PORTLCD
	DIO_voidWritePinValue(RS,LOW);//Command Choose
	DIO_voidWritePinValue(RW,LOW);//LOW (Write)
	DIO_voidWritePinValue(En,HIGH);//
	_delay_ms(1);
 	DIO_voidWritePinValue(En,LOW);
	_delay_ms(2);
	/* _____  2ms
	 *| 1ms	|______
	 */
}

extern void Lcd_voidSetCursar(u8 row,u8 coloum)//Col==>0:15
{
	if(row==1 && coloum<=15)
	{
		Lcd_voidWriteCommand(128+coloum);//Set DDRAM Adress==>0b1Address==>FirstAddress=0b10000000=128;
	}
	else if(row==2 && coloum<=15 )
	{
		Lcd_voidWriteCommand(128+64+coloum);//FirstAddressSecondRow=0b10000000=128+64;
	}
}

//"Mina"==> '\0'
extern void Lcd_voidWriteString(u8 * Array)
{
	u8 x=0;
	while(Array[x]!='\0')//Don't Equal NULL
	{
		Lcd_voidWriteData(Array[x]);//M,i,n,a,\0
		x++;
	}

}
//"12345"
//int x = 456 ;
//==> 4 5 6
extern void Lcd_voidWriteNum(u64 Num)
{
	u64 y=1,reminder,reminder2;
	if(Num==0){Lcd_voidWriteData('0');}
	while(Num !=0)
	{
		reminder=Num%10;//6,5,4
		y=(y*10)+reminder;//y=10*0+6=6,y=60+5=65,y=650+4=654
		Num=Num/10;//45,4,0
	}
	//y=654 ==>'0'+4==>'0','1'==>'0'+1,'9'==>'0'+9
	while(y!=1)
	{
		reminder2=y%10;//==>4,5
		Lcd_voidWriteData('0'+reminder2);//==>'0'+ 4,'0'+5
		y=y/10;//==>65,6
	}
}
extern void Lcd_voidCreateChar(u8 Num,u8* Symbol)
{
	u8 i=0;
	if(Num>0 || Num<8)//Num0to7
	  Lcd_voidWriteCommand(64+(8*Num));//LCD CMD ==>0b01Adress==(64+8*Numb)
	for(i=0; i<8; i++)
	{
			Lcd_voidWriteData(Symbol[i]);
	}
}
extern void LCD_voidClear(void)
{
	Lcd_voidWriteCommand(0x01);
	_delay_ms(2);
}
extern void LCD_voidClear_RoW(u8 Row)
{
	char clear[]="                ";
	Lcd_voidSetCursar(Row,0);
	Lcd_voidWriteString(clear);
	_delay_ms(1);
}
