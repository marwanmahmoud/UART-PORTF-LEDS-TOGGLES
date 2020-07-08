#include "portf.h"

void PORTF_init()
{
*(SYSCTL_RCGCGPIO)|=0x20;
uint32_t delaay=delaay+1;
*(RCGC2_REG	)|=0x20;
	delaay=delaay+1;
Memory(PORTF,GPIO_LCK)=UNLOCK;
Memory(PORTF,GPIO_CR)=0x1F;
Memory(PORTF,GPIO_AFSEL)=0;
Memory(PORTF,GPIO_AMSEL)=0;
Memory(PORTF,GPIO_PCTL)=0;
Memory(PORTF,GPIO_DIR)|=0x0E;
Memory(PORTF,GPIO_DEN)|=0x1F;
Memory(PORTF,GPIO_PUR)|=0x11;
GPIOF->DATA=(1<<2);
}