#ifndef _UART_H
#define _UART_H
//#include "TM4C123GH6PM.h"
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "portf.h"
#define UART_BUFFER_SIZE 	64
#define Memory(X,Y)			 	(*((volatile uint32_t*)(((uint32_t)X)+((uint32_t)Y))))
//#define BAUD_IDIV(B)		 	(int)(16000000/(16*B))
//#define BAUD_FDIV(B) 		 	(int)(((16000000/(16*B)) - BAUD_IDIV(B))*64)

#define RCGC2_REG				 	((volatile uint32_t *)0x400FE108)	//really don't know why we are using this
#define NVIC_EN0         	((volatile uint32_t*)0xE000E100)
#define SYSCTL_RCGCGPIO 		((volatile uint32_t*)0x400FE608)
#define SYSCTL_RCGCGUART		((volatile uint32_t*)0x400FE618)
#define PORTA           0x400004000
typedef enum Uart{
	UART00 			= 0x4000C000,
	UART11 			= 0x4000D000,
	UART22 			= 0x4000E000,
	UART33 			= 0x4000F000,
	UART44 			= 0x40010000,
	UART55		  	= 0x40011000,
	UART66			  = 0x40012000,
	UART77			  = 0x40013000,
} Uart;

typedef enum UARTRegistersOffset{
	UART_DATA 			= 0x000,
	UART_RS_EC 			= 0x004,
	UART_FLAG 			= 0x018,
	UART_IBRD 			= 0x024,
	UART_FBRD 			= 0x028,
	UART_LCTL			= 0x02C,
	UART_CTL			= 0x030,
	UART_IFLS			= 0x034,
	UART_IM 			= 0x038,
	UART_RIS			= 0x03C,
	UART_MIS			= 0x040,
	UART_IC			    = 0x044,
	UART_DMACTL			= 0x048,
	UART_PP 			= 0xFC0,
	UART_CC 			= 0xFC8,
} UARTRegistersOffset;

typedef enum UART_BAUDRATE{
	UART_BAUD_300 			  = 300,
	UART_BAUD_1200 			= 1200,
	UART_BAUD_2400 			= 2400,
	UART_BAUD_4800 			= 4800,
	UART_BAUD_9600 			= 9600,
	UART_BAUD_19200 			= 19200,
	UART_BAUD_38400 			= 38400,
	UART_BAUD_57600 			= 57600,
	UART_BAUD_74880 			= 74880,
	UART_BAUD_115200			= 115200,
} UART_BAUDRATE;

void UART_init(Uart uart, UART_BAUDRATE baudrate);
uint8_t UART_readChar(Uart uart);
void UART_sendChar(Uart uart, const char data);

#endif