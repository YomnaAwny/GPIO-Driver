/*
 * GPIO_Program.c
 *
 *  Created on: Aug 15, 2024
 *      Author: Dell
 */

#include "GPIO_Interface.h"


void GPIO_Init(GPIO_Config* config)
{
	GPIO_Reg* GPIOX;

	switch(config->port)
	{
	case PORTA:
		     GPIOX=GPIOA;
		    break;
	case PORTB:
			GPIOX=GPIOB;
			break;
	case PORTC:
			GPIOX=GPIOC;
			break;
	case PORTD:
			GPIOX=GPIOD;
			break;
	}

if(config->pinN<8){
	//Input
	if(config->mode <3)
	{  GPIOX->CRL &=~(0b11<< 4*config->pinN);

	   GPIOX->CRL &=~(0b11<< 4*config->pinN +2);
	GPIOX->CRL |= (config->mode << 4*config->pinN +2);

	if(config->pullType ==GPIO_PULLDOWN)
		GPIOX->ODR &=~(1<<config->pinN);
	else
		GPIOX->ODR |= (1<<config->pinN);

	}

	//Output
	else{
		//speed 10MHZ
		if(config->speed ==0)
		{GPIOX->CRL &=~(0b11<< 4*config->pinN);
		GPIOX->CRL |= (0b01<< 4*config->pinN);

		GPIOX->CRL &=~(0b11<< 4*config->pinN +2);
		GPIOX->CRL |= (config->mode << 4*config->pinN +2);}
         //speed 2MHZ
		else if(config->speed ==1)
		{GPIOX->CRL &=~(0b11<< 4*config->pinN);
		GPIOX->CRL |= (0b10<< 4*config->pinN);

		GPIOX->CRL &=~(0b11<< 4*config->pinN +2);
		GPIOX->CRL |= (config->mode << 4*config->pinN +2);}
        //speed 50MHZ
		else{GPIOX->CRL |= (0b11<< 4*config->pinN);

		GPIOX->CRL &=~(0b11<< 4*config->pinN +2);
		GPIOX->CRL |= (config->mode << 4*config->pinN +2);}
	}
}
else{
	config->pinN -=8;
	//Input
		if(config->mode <3)
		{  GPIOX->CRH &=~(0b11<< 4*config->pinN);
		   GPIOX->CRH &=~(0b11<< 4*config->pinN +2);
		GPIOX->CRH |= (config->mode << 4*config->pinN +2);

		if(config->pullType ==GPIO_PULLDOWN)
			GPIOX->ODR &=~(1<<config->pinN+8);
		else
			GPIOX->ODR |= (1<<config->pinN+8);

		}

	//Output
	else{
		//speed 10MHZ
	if(config->speed ==0)
	{GPIOX->CRH &=~(0b11<< 4*config->pinN);
	GPIOX->CRH |= (0b01<< 4*config->pinN);

	GPIOX->CRH &=~(0b11<< 4*config->pinN +2);
	GPIOX->CRH |= (config->mode << 4*config->pinN +2);}
       //speed 2MHZ
	else if(config->speed ==1)
	{GPIOX->CRH &=~(0b11<< 4*config->pinN);
	GPIOX->CRH |= (0b10<< 4*config->pinN);

	GPIOX->CRH &=~(0b11<< 4*config->pinN +2);
	GPIOX->CRH |= (config->mode << 4*config->pinN +2);}
      //speed 50MHZ
	else{GPIOX->CRH |= (0b11<< 4*config->pinN);
	GPIOX->CRH &=~(0b11<< 4*config->pinN +2);
	GPIOX->CRH |= (config->mode << 4*config->pinN +2);}

	}
	config->pinN +=8;}
}


void GPIO_GetPin(GPIO_Config* config){

	GPIO_Reg* GPIOX;

		switch(config->port)
		{
		case PORTA:
			     GPIOX=GPIOA;
			    break;
		case PORTB:
				GPIOX=GPIOB;
				break;
		case PORTC:
				GPIOX=GPIOC;
				break;
		case PORTD:
				GPIOX=GPIOD;
				break;
		}

	return(GPIOX->IDR &(1<<config->pinN));

}


void GPIO_SetPin(GPIO_Config* config){

	GPIO_Reg* GPIOX;

		switch(config->port)
		{
		case PORTA:
			     GPIOX=GPIOA;
			    break;
		case PORTB:
				GPIOX=GPIOB;
				break;
		case PORTC:
				GPIOX=GPIOC;
				break;
		case PORTD:
				GPIOX=GPIOD;
				break;
		}

#if Atomic==NO
	GPIOX->ODR |=(1<<config->pinN);
#else
	GPIOX->BSRR =(1<<config->pinN);
#endif

}
