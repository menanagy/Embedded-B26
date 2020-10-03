#ifndef Switch_H_
#define Switch_H_
#define OUTPUT 1
#define HIGH 1
#define LOW 0
#define Switch_PinA0 0
#define Switch_PinA1 1
#define Switch_PinA2 2
#define Switch_PinA3 3
#define Switch_PinA4 4
#define Switch_PinA5 5
#define Switch_PinA6 6
#define Switch_PinA7 7
#define Switch_PinB0 8
#define Switch_PinB1 9
#define Switch_PinB2 10
#define Switch_PinB3 11
#define Switch_PinB4 12
#define Switch_PinB5 13
#define Switch_PinB6 14
#define Switch_PinB7 15
#define Switch_PinC0 16
#define Switch_PinC1 17
#define Switch_PinC2 18
#define Switch_PinC3 19
#define Switch_PinC4 20
#define Switch_PinC5 21
#define Switch_PinC6 22
#define Switch_PinC7 23
#define Switch_PinD0 24
#define Switch_PinD1 25
#define Switch_PinD2 26
#define Switch_PinD3 27
#define Switch_PinD4 28
#define Switch_PinD5 29
#define Switch_PinD6 30
#define Switch_PinD7 31
#define Switch_ALL_PA 32
#define Switch_ALL_PB 33
#define Switch_ALL_PC 34
#define Switch_ALL_PD 35
extern u8 Switch_voidReadSwitch(u8 PinName);
extern void Switch_voidSwitchDefine(u8 PinName);
extern void Switch_voidPortSwitchesDefine(u8 PortName);
extern u8 Switch_voidPortReadSwitches(u8 PortName);
#endif
