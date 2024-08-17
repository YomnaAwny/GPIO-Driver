/*
 * GPIO_Interface.h
 *
 *  Created on: Aug 15, 2024
 *      Author: Dell
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "GPIO_Registers.h"
#include "GPIO_Config.h"

#define GPIO_M_IN_FLOATING     0b01 //01 IN CNF &00 IN MODE
#define GPIO_M_IN_UPDOWN  0b10//10
#define GPIO_M_IN_ANALOG       0b00//00

#define GPIO_M_OUT_OPENDRAIN  0b01 //01 IN CNF
#define GPIO_M_OUT_PUSHPULL   0b00//00 IN CNF
#define GPIO_M_ALT_OPENDRAIN  0b11//11 IN CNF
#define GPIO_M_ALT_PUSHPULL   0b10//10 IN CNF

#define GPIO_SPEED_10MHZ 0 //01 IN MODE
#define GPIO_SPEED_2MHZ  1 //10 IN MODE
#define SPEED_50MHZ      2 //11 IN MODE

#define GPIO_PULLUP   1
#define GPIO_PULLDOWN 0

#define ATOMIC      YES


 typedef enum{PORTA, PORTB, PORTC, PORTD}GPIO_Port;
 typedef volatile struct{
	 GPIO_Port port;
	 u8 pinN;
	 u8 mode;
	 u8 speed;
	 u8 pullType;
	 u8 setreset; //0 for reset , 1 for set
 }GPIO_Config;

void GPIO_Init(GPIO_Config* config);

void GPIO_SetPin(GPIO_Config* config);
void GPIO_GetPin(GPIO_Config* config);


#endif /* GPIO_INTERFACE_H_ */
