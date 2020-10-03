/*
 * Seg_Cnf.h
 *
 *  Created on: Aug 25, 2020
 *      Author: Mina Nagy
 */

#ifndef SEG_CNF_H_
#define SEG_CNF_H_

/*      				  g  f com a  b
*		a				__|__|__|__|__|__
*	#########		   |			     |
*   #		# 		   |     _______	 |
*  f#		#b		   |    |   a   |    |
*	#       #		   |   f|		|b   |
*	#########		   |	|_______|    |
*	#	g	#		   |    |   g   |    |
*  e#		# c		   |   e|      c|    |
*  	#		#		   |	|_______|    |
*	######### 		   |		d		 |
*		d			   |_________________|
*						  |  |  |  |  |
*	    				  e  d com c dot
*/
#define Anode HIGH
#define Cathode LOW
#define a DIO_PinD0
#define b DIO_PinD1
#define c DIO_PinD2
#define d DIO_PinD3
#define e DIO_PinD4
#define f DIO_PinD5
#define g DIO_PinD6
#define dot DIO_PinD7
#define Common DIO_PinC7
#define CommonPin Anode
#define LED_ON LOW
#define LED_OFF HIGH



#endif /* SEG_CNF_H_ */
