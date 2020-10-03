/*
 * Keypad.c
 *
 *  Created on: 27 Agu 2020
 *      Author: Mina Nagy
 */
#include"Standard_Types.h"
#include"utils.h"
#include"DIO.h"
#include"Keypad_Cfg.h"
#include"Keypad.h"
#include <avr/delay.h>
static void Keypad_Seq(u8 i);
extern void Keypad_voidInit(void){
	//1- ROWS Input ==> Enable Internal PULL UP Res
	DIO_voidSetPinDirection(R0,INPUT);
	DIO_voidWritePinValue(R0,HIGH);//Internal PULL UP
	DIO_voidSetPinDirection(R1,INPUT);
	DIO_voidWritePinValue(R1,HIGH);//PULL UP
	DIO_voidSetPinDirection(R2,INPUT);
	DIO_voidWritePinValue(R2,HIGH);//PULL UP
	DIO_voidSetPinDirection(R3,INPUT);
	DIO_voidWritePinValue(R3,HIGH);//PULL UP
	//2- Col ==> O
	DIO_voidSetPinDirection(C0,OUTPUT);
	DIO_voidSetPinDirection(C1,OUTPUT);
	DIO_voidSetPinDirection(C2,OUTPUT);
	#if (ColNum == 4)
		DIO_voidSetPinDirection(C3,OUTPUT);
	#endif

}
extern u8 Keypad_u8ReadButton(u8 Button_Number)
{
	//b7dd Button fenhy Col , ROW
	u8 Value=LOW;
	u8 Col_Num=Button_Number%ColNum;//Define Button ==> COL ?
	u8 Row_Num=Button_Number/4;//Define Button ==> ROW ?
	#if (ColNum == 4)
		u8 const Real_Col[]={C0,C1,C2,C3};
	#endif
	#if (ColNum == 3)
		u8 const Real_Col[]={C0,C1,C2};
	#endif

	u8 const Real_ROW[]={R0,R1,R2,R3};
	DIO_voidWritePinValue(C0,HIGH);
	DIO_voidWritePinValue(C1,HIGH);
	DIO_voidWritePinValue(C2,HIGH);
	#if (ColNum == 4)
	 DIO_voidWritePinValue(C3,HIGH);
    #endif
	DIO_voidWritePinValue(Real_Col[Col_Num],LOW);
	u8 read=DIO_voidReadPinValue(Real_ROW[Row_Num]);
	if(read==0)
	{
		_delay_ms(10);
		read=DIO_voidReadPinValue(Real_ROW[Row_Num]);
		if(read==0)
		{
			Value=HIGH;
		}
	}

	return Value;
}
extern u8 keypad_u8GetKey(u8 Keypad_Symbol[4][4]){ //APi
	    u8 Value=0;
	    u8 i=0 ,j=0;
		u8 flag[4]={0};//Array Flags
		u8 ROW[]={R0,R1,R2,R3};//Array
		//LOOP : ==> 4
		//Throw one Col 0 ==> Other 1 ,i=0(First once)==>C0=0,C1=C2=C3=1, i=1==>C0=1,C1=0,C2=C3=1
		//Read 4 Row if(Row[j]==0)==> Press Return[j][i]
		//else GO TO LOOP
		for(i=0; i<ColNum; i++)//For Sequence of Col  ==> i=0==> C0=0
		{
			Keypad_Seq(i);//Sequence of Col O/P
			for(j=0; j<4; j++)//j=0 R0=0 ==>ROW
			{
				u8 read=DIO_voidReadPinValue(ROW[j]);//ROW0 ,1,2,3
				if(read==0)
				{
					_delay_ms(30);//Debouncing
					read= DIO_voidReadPinValue(ROW[j]);
					if(read==0 && flag[j]==0)//Check number 2
					{
						flag[j]=1;
						Value=Keypad_Symbol[j][i]; //J=ROW , i=col
					}
					else if(read==1)
					{
						flag[j]=0;
					}
				}
			}
		}
	return Value;
}
static void Keypad_Seq(u8 i){//Internal Function
	switch (i)
	{
	case 0 :
	DIO_voidWritePinValue(C0,LOW);
	DIO_voidWritePinValue(C1,HIGH);
	DIO_voidWritePinValue(C2,HIGH);
    #if (ColNum == 4)
		DIO_voidWritePinValue(C3,HIGH);
	#endif
	break;
	case 1 :
	DIO_voidWritePinValue(C0,HIGH);
	DIO_voidWritePinValue(C1,LOW);
	DIO_voidWritePinValue(C2,HIGH);
	#if (ColNum == 4)
		DIO_voidWritePinValue(C3,HIGH);
	#endif
	break;
	case 2 :
	DIO_voidWritePinValue(C0,HIGH);
	DIO_voidWritePinValue(C1,HIGH);
	DIO_voidWritePinValue(C2,LOW);
	#if (ColNum == 4)
		DIO_voidWritePinValue(C3,HIGH);
	#endif
	break;
	case 3 :
	DIO_voidWritePinValue(C0,HIGH);
	DIO_voidWritePinValue(C1,HIGH);
	DIO_voidWritePinValue(C2,HIGH);
	#if (ColNum == 4)
		DIO_voidWritePinValue(C3,LOW);
	#endif
	break;
	}
}
/*u8 getKey()
{
	u8 flags[16]={0};//Check One Press Switch
	u8 i=0 ,value=0,count=0;
	char Button[]="Button Number:";
	for(i=0; i<=15; i++)
	{
		value=Keypad_u8ReadButton(i);
		if(value==1 && flags[i]==0)//Check One Press Switch(Do'nt Repeate if)
		{
			if(count==16)
			{
				count=0;
				Clear_RoW(2);
			}
			flags[i]=1;
			count++;
		}
		else if(value==0)
		{
			flags[i]=0;
		}*/
