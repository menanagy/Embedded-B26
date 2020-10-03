/*
 * main.c
 *
 *  Created on: Aug 23, 2020
 *      Author: Mina
 */
/*
 * App.c
 *
 *  Created on: Agu 23, 2020
 *      Author: Mina Nagy
 */
#include"Standard_Types.h"
#include"utils.h"
#include"avr/delay.h"
#include"Led.h"
#include"Seg.h"
#include "Switch.h"
#include "LCD.h"
#include"Keypad.h"
void main(void)
{
	Lcd_Init();
	Keypad_voidInit();
	u8 arr[4][4]={'7','8','9','/','4','5','6','*','1','2','3','-','C','0','=','+'};
	u8 x=0;
	while(1){
		x=keypad_u8GetKey(arr);//1
		if(x!=0){
			Lcd_voidSetCursar(1,0);
			Lcd_voidWriteNum(x);
			_delay_ms(100);
			LCD_voidClear();
		}



		//Lcd_voidWriteNum(x);
	}
}
/*Switch_voidSwitchDefine(Switch_PinC7);
while(1){
	while(Switch_voidReadSwitch(Switch_PinC7)==0 && flag==0){
		_delay_ms(20);
	while(Switch_voidReadSwitch(Switch_PinC7)==0 && flag==0)
			{
				flag=1;
				Count++;
			}
	}
	flag=0;
	//if(Switch_voidReadSwitch(Switch_PinC7)==0){
		//_delay_ms(1000);
		//Count++;

	//}
	Lcd_voidSetCursar(1,0);
	Lcd_voidWriteNum(Count);
}*/
/*Lcd_voidWriteString("AMIR , Ahmed");
Lcd_voidSetCursar(2,0);
Lcd_voidWriteString("ALI Mostafa");
_delay_ms(5000);
LCD_voidClear();
Lcd_voidWriteString("Fady , Mena");
Lcd_voidSetCursar(2,0);
Lcd_voidWriteString("Ashraf Abobakr");
_delay_ms(5000);
LCD_voidClear();
Lcd_voidWriteString("Moaz RAWAN");
Lcd_voidSetCursar(2,0);
Lcd_voidWriteNum(254);*/
/*u8 count=0;
//Switch_voidPortSwitchesDefine(Switch_PinB3);
//Led_voidLedDefine(LED_PinC0);//C0
//Led_voidLedDefine(LED_ALL_PB);//PB
//Switch_voidSwitchDefine();
 //Seg_voidInit_OneSeg();//Define==>1) Common O/p ,2) Common HIGH,LOW, 3)a,b,c,d,e,f,g,dot==>o/p
 //Seg_voidEnterNumber(5);//Case2 ==>
//Seg_voidDisplayDecrement9to0();
while(1){
	Seg_voidEnterNumber(count);//0
	//Seg_voidDisplayDecrement9to0();
	//Led_voidLedOn(LED_PinC0);
	//Led_voidLedOn(LED_ALL_PB);
	//_delay_ms(500);
	//Led_voidLedOff(LED_PinC0);
	//Led_voidLedOff(LED_ALL_PB);
	//_delay_ms(500);
}*/
