#include "uart.h"
char buffer[UART_BUFFER_SIZE];
volatile uint8_t buffer_index = 0;
volatile Uart uartAttachedToBuffer;

void UART_init(Uart uart, UART_BAUDRATE baudrate){
  
	(*SYSCTL_RCGCGUART)|=0x01;
	(*RCGC2_REG)|=0x01;
	uint32_t delay=delay+1;
	Memory(uart, UART_CTL) &= ~0x00000001;						// Disable UART Module
  Memory(PORTA,GPIO_AFSEL)|=0x03;
	Memory(PORTA,GPIO_PCTL)=0x11;
  Memory(PORTA,GPIO_DEN)|=0x03;
  Memory (PORTA,GPIO_DIR)=0x02;
  Memory(PORTA,GPIO_DIR)&=~(1<<1);		
  Memory(uart, UART_IBRD) = 26	;	// writing integer baudrate divisor
	Memory(uart, UART_FBRD) = 3	;	// Fractional integer baudrate divisor
	Memory(uart, UART_CC) &= ~0x0000000F; 						// clock source is system clock
	Memory(uart, UART_LCTL) = 0x00000060;  						// 8 bit, no parity bits, one stop, no FIFOs
	Memory(uart, UART_CTL) |= 0x00000001;							// enable UART

}
uint8_t UART_readChar(Uart uart){
  while((Memory(uart, UART_FLAG)&0x0010) != 0);     // wait until RXFE is 0 (reciver is empty)
  return (uint8_t)Memory(uart, UART_DATA);
}

void UART_sendChar(Uart uart, const char data){
	while((Memory(uart, UART_FLAG)&0x0020) != 0);			// wait until TXFF is 0 (transmitter is  full)
	Memory(uart, UART_DATA) = data;
}
