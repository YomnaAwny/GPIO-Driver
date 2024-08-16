/*
 * GPIO_Registers.h
 *
 *  Created on: Aug 15, 2024
 *      Author: Dell
 */

#ifndef GPIO_REGISTERS_H_
#define GPIO_REGISTERS_H_

#define GPIOA_BASE_ADD  0x40010800
#define GPIOB_BASE_ADD  0x40010C00
#define GPIOC_BASE_ADD  0x40011000
#define GPIOD_BASE_ADD  0x40011400

typedef volatile struct{
	u32 CRL;
	u32 CRH;
	u32 IDR;
	u32 ODR;
	u32 BSRR;
	u32 BRR;
	u32 LCKR;

}GPIO_Reg;

#define GPIOA     ((GPIO_Reg *)(GPIOA_BASE_ADD))
#define GPIOB     ((GPIO_Reg *)(GPIOB_BASE_ADD))
#define GPIOC     ((GPIO_Reg *)(GPIOC_BASE_ADD))
#define GPIOD     ((GPIO_Reg *)(GPIOD_BASE_ADD))

#endif /* GPIO_REGISTERS_H_ */
