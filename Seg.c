/*
 * Seg.c
 *
 *  Created LOW: Aug 25, 2020
 *      Author: Mina Nagy
 */
#include "Standard_Types.h"
#include "utils.h"
#include "DIO.h"
#include "Seg_Cnf.h"
#include "Seg.h"
#include <avr/delay.h>
extern void Seg_voidInit_OneSeg()
{
	/*
	 * 		1- Common Pin O/p
	  	    2- Write Common Pin ==> HIGH ==> Anode,LOW ==> Cathod
	  	    3- a pin ,b,c,d,e,f,g,dot==> o/p
	*/
	DIO_voidSetPinDirection(Common,OUTPUT);
	DIO_voidWritePinValue(Common,CommonPin);//Anode==>HIGH,Cathod==>LOW
	//DIO_voidWritePinValue(DIO_PINC7,);
	DIO_voidSetPinDirection(a,OUTPUT);
	DIO_voidSetPinDirection(b,OUTPUT);
	DIO_voidSetPinDirection(c,OUTPUT);
	DIO_voidSetPinDirection(d,OUTPUT);
	DIO_voidSetPinDirection(e,OUTPUT);
	DIO_voidSetPinDirection(f,OUTPUT);
	DIO_voidSetPinDirection(g,OUTPUT);
	DIO_voidSetPinDirection(dot,OUTPUT);
}
extern void Seg_voidDisplayDecrement9to0()
{
	s8 j;//Signed Char =;
		for(j=9; j>=0; j--)
			{
				Seg_voidEnterNumber(j);//9 8 7 6
				_delay_ms(1000);//1 Sec
			}
}
extern void Seg_voidDisplayDecrement0to9(){
	u8 j;
		for(j=0; j<10; j++)// 0 : 9
			{
				Seg_voidEnterNumber(j);
				_delay_ms(1000);
			}
}
extern void Seg_voidEnterNumber(u8 Number)//0 : 9
{
	/*
	 * 0==>9
	 *
	 * */
	switch(Number)
	{
		case 0 :
		DIO_voidWritePinValue(a,LED_ON );
		DIO_voidWritePinValue(b,LED_ON );
		DIO_voidWritePinValue(c,LED_ON );
		DIO_voidWritePinValue(d,LED_ON );
		DIO_voidWritePinValue(e,LED_ON );
		DIO_voidWritePinValue(f,LED_ON );
		DIO_voidWritePinValue(g,LED_OFF);
		break;
		case 1 :
		DIO_voidWritePinValue(a,LED_OFF);
		DIO_voidWritePinValue(b,LED_ON);
		DIO_voidWritePinValue(c,LED_ON);
		DIO_voidWritePinValue(d,LED_OFF );
		DIO_voidWritePinValue(e,LED_OFF );
		DIO_voidWritePinValue(f,LED_OFF );
		DIO_voidWritePinValue(g,LED_OFF );
		break;
		case 2 :
		DIO_voidWritePinValue(a,LED_ON);//LOW OR HIGH==< #define LED_ON
		DIO_voidWritePinValue(b,LED_ON);
		DIO_voidWritePinValue(c,LED_OFF);
		DIO_voidWritePinValue(d,LED_ON);
		DIO_voidWritePinValue(e,LED_ON);
		DIO_voidWritePinValue(f,LED_OFF);
		DIO_voidWritePinValue(g,LED_ON);
		break;
		case 3 :
		DIO_voidWritePinValue(a,LED_ON);
		DIO_voidWritePinValue(b,LED_ON);
		DIO_voidWritePinValue(c,LED_ON);
		DIO_voidWritePinValue(d,LED_ON);
		DIO_voidWritePinValue(e,LED_OFF);
		DIO_voidWritePinValue(f,LED_OFF);
		DIO_voidWritePinValue(g,LED_ON);
		break;
		case 4 :
		DIO_voidWritePinValue(a,LED_OFF);
		DIO_voidWritePinValue(b,LED_ON);
		DIO_voidWritePinValue(c,LED_ON);
		DIO_voidWritePinValue(d,LED_OFF);
		DIO_voidWritePinValue(e,LED_OFF);
		DIO_voidWritePinValue(f,LED_ON);
		DIO_voidWritePinValue(g,LED_ON);
		break;
		case 5 :
		DIO_voidWritePinValue(a,LED_ON);
		DIO_voidWritePinValue(b,LED_OFF);
		DIO_voidWritePinValue(c,LED_ON);
		DIO_voidWritePinValue(d,LED_ON);
		DIO_voidWritePinValue(e,LED_OFF);
		DIO_voidWritePinValue(f,LED_ON);
		DIO_voidWritePinValue(g,LED_ON);
		break;
		case 6 :
		DIO_voidWritePinValue(a,LED_ON);
		DIO_voidWritePinValue(b,LED_OFF);
		DIO_voidWritePinValue(c,LED_ON);
		DIO_voidWritePinValue(d,LED_ON);
		DIO_voidWritePinValue(e,LED_ON);
		DIO_voidWritePinValue(f,LED_ON);
		DIO_voidWritePinValue(g,LED_ON);
		break;
		case 7 :
		DIO_voidWritePinValue(a,LED_ON);
		DIO_voidWritePinValue(b,LED_ON);
		DIO_voidWritePinValue(c,LED_ON);
		DIO_voidWritePinValue(d,LED_OFF);
		DIO_voidWritePinValue(e,LED_OFF);
		DIO_voidWritePinValue(f,LED_OFF);
		DIO_voidWritePinValue(g,LED_OFF);
		break;
		case 8 :
		DIO_voidWritePinValue(a,LED_ON);
		DIO_voidWritePinValue(b,LED_ON);
		DIO_voidWritePinValue(c,LED_ON);
		DIO_voidWritePinValue(d,LED_ON);
		DIO_voidWritePinValue(e,LED_ON);
		DIO_voidWritePinValue(f,LED_ON);
		DIO_voidWritePinValue(g,LED_ON);
		break;
		case 9 :
		DIO_voidWritePinValue(a,LED_ON);
		DIO_voidWritePinValue(b,LED_ON);
		DIO_voidWritePinValue(c,LED_ON);
		DIO_voidWritePinValue(d,LED_ON);
		DIO_voidWritePinValue(e,LED_OFF);
		DIO_voidWritePinValue(f,LED_ON);
		DIO_voidWritePinValue(g,LED_ON);
		break;
	}
	DIO_voidWritePinValue(dot,LED_OFF);
	_delay_ms(1);//
}



