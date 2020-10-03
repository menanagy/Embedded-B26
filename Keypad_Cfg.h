/*
 * Keypad_Cfg.h
 *
 *  Created on: 27 Agu 2020
 *      Author: Mina Nagy
 */

#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_
#define R0 DIO_PinC4
#define R1 DIO_PinC5
#define R2 DIO_PinC6
#define R3 DIO_PinC7
#define C0 DIO_PinC3
#define C1 DIO_PinC2
#define C2 DIO_PinC1
#define C3 DIO_PinC0
#define ColNum 4 //4==>4(ROW)*4(COL) or 3==>4(RoW)*3(COL)
#endif /* KEYPAD_CFG_H_ */
/*
Connection Kit IMT
 _______________________________________
| R3 | R2 | R1 | R0 | C0 | C1 | C2 | C3 |
| A7 | A6 | A5 | A4 | A3 | A2 | A1 | A0 |
|_______________________________________|

Real Connection
		  _____________________________
		 |  ___    ___    ___    ___   |
		 | |   |  |   |  |   |  |   |  |
ROW0 ____| | 0 |  | 1 |  | 2 |  | 3 |  |
		 | |___|  |___|  |___|  |___|  |
		 |  ___    ___    ___    ___   |
		 | |   |  |   |  |   |  |   |  |
ROW1 ____| | 4 |  | 5 |  | 6 |  | 7 |  |
		 | |___|  |___|  |___|  |___|  |
		 |  ___    ___    ___    ___   |
		 | |   |  |   |  |   |  |   |  |
ROW2 ____| | 8 |  | 9 |  | 10|  | 11|  |
		 | |___|  |___|  |___|  |___|  |
		 |  ___    ___    ___    ___   |
		 | |   |  |   |  |   |  |   |  |
ROW3 ____| | 12|  | 13|  | 14|  | 15|  |
		 | |___|  |___|  |___|  |___|  |
		 |_____________________________|
		     |      |      |      |
		     |      |      |      |
		     |      |      |      |
         Column0 Column1 Column2 Column0


 * */
