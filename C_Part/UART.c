#include <MKL25Z4.H>
#include <stdio.h>
#include <math.h>
#include <string.h>  


int main(void){
	
// Enable PORTA clock
SIM->SCGC5 |= SIM_SCGC5_PORTA(1);
 
PORTA_PCR1|=  PORT_PCR_MUX(2); /* PTA1 as ALT2 (UART0) */
PORTA_PCR2 |=  PORT_PCR_MUX(2); /* PTA2 as ALT2 (UART0) */

	// Select MCGFLLCLK as UART0 clock
SIM->SOPT2 |= SIM_SOPT2_UART0SRC(1);
 
// Enable UART0 Clock
SIM->SCGC4 |= SIM_SCGC4_UART0(1);
	
// Configure Baud Rate as 9600
UART0->BDL = 0x0B;
UART0->BDH = 0x0;
	
// Configure Serial Port as 8-N-1
// (8 data bits, No parity and 1 stop bit)
UART0->C1  = 0x00;

// Configure Tx/Rx Interrupts
UART0->C2  |= UART_C2_TIE(0);  // Tx Interrupt disabled
UART0->C2  |= UART_C2_TCIE(0); // Tx Complete Interrupt disabled
UART0->C2  |= UART_C2_RIE(1);    // Rx Interrupt enabled
 
// Configure Transmitter/Receiever
UART0->C2  |= UART_C2_TE(1);     // Tx Enabled
UART0->C2  |= UART_C2_RE(1);     // Rx Enabled


}