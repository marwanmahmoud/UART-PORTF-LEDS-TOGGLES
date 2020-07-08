#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "uart.h"
#include "portf.h"
int main ()
{
PORTF_init();
UART_init(UART00,UART_BAUD_38400);	
UART_sendChar(UART00, 'c');

}