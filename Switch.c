#include"Standard_Types.h"
#include"utils.h"
#include"DIO.h"

extern void Switch_voidSwitchDefine(u8 PinName) {
		DIO_voidSetPinDirection(PinName,INPUT);//1- PIN ==> INPUT
		DIO_voidWritePinValue(PinName,HIGH);//2- Internal PULL UP RES
}

extern u8 Switch_voidReadSwitch(u8 PinName){
	u8 Value=255;
	Value=DIO_voidReadPinValue(PinName);
	return Value;
}

extern void Switch_voidPortSwitchesDefine(u8 PortName){//32 A or33 Bor34 Cor35 D
	DIO_voidSetPortDirection(PortName,ALL_INPUT);//All Pin==> INput
	DIO_voidWritePortValue(PortName,ALL_HIGH);//==> AllPin ==> Internal Pull UP RES
}

extern u8 Switch_voidPortReadSwitches(u8 PortName){
		u8 Value=0;
		Value=DIO_voidReadPortValue(PortName);//
		return Value;
}

