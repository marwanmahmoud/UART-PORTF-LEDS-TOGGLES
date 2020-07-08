#ifndef _portf_H
#define _portf_H
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "TM4C123GH6PM.h"
#define Memory(X,Y)			 	(*((volatile uint32_t*)(((uint32_t)X)+((uint32_t)Y))))
#define PORTF             0x40025000
#define SYSCTL_RCGCGPIO 		((volatile uint32_t*)0x400FE608)
#define UNLOCK					0x4C4F434B
#define RCGC2_REG				    ((volatile uint32_t *)0x400FE108)
typedef enum GPIORegistersOffset{
	GPIO_DIR 			= 0x400,
	GPIO_DATA     = 0x000,
	GPIO_IS 			= 0x404,
	GPIO_IBE 			= 0x408,
	GPIO_IEV 			= 0x40C,
	GPIO_IM 			= 0x410,
	GPIO_RIS			= 0x414,
	GPIO_MIS			= 0x418,
	GPIO_ICR			= 0x41C,
	GPIO_AFSEL			= 0x420,
	GPIO_DRV2M			= 0x500,
	GPIO_DRV4M			= 0x504,
	GPIO_DRV8M			= 0x508,
	GPIO_ODR			= 0x50C,
	GPIO_PUR			= 0x510,
	GPIO_PDR			= 0x514,
	GPIO_SLR 			= 0x518,
	GPIO_DEN			= 0x51C,
	GPIO_LCK			= 0x520,
	GPIO_CR				= 0x524,
	GPIO_AMSEL			= 0x528,
	GPIO_PCTL			= 0x52C,
	GPIO_ADCCTL   = 0x530
} GPIORegistersOffset;

void PORTF_init();













#endif