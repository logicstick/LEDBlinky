#include <LPC17xx.H>


#define LED (1<<29)

int main(void) {
	uint32_t i = 0;
	//Do system initialization stuff
	SystemInit();
	//Set direction
	LPC_GPIO1->FIODIR |= LED ;
	// Clear / switch off the led
	LPC_GPIO1->FIOCLR |= LED ;
	
	while(1){
		// Switch on the led
		LPC_GPIO1->FIOSET |= LED;
		//Just waste some time
		for(i=0; i < 10000000 ; i++);
		//Clear or switch off the LED
		LPC_GPIO1->FIOCLR |= LED;
		// Waste some more time
		for(i=0; i < 10000000 ; i++);
	}
}