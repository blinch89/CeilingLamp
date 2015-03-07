/*
 * Main.c
 *
 *  Created on: 06.03.2015
 *      Author: blinch89
 */

#include <DAVE3.h>			//Declarations from DAVE3 Code Generation (includes SFR declaration)
#include "light_ws2812_cortex.h"
#include "XMC1100.h"
#include "GPIO.h"
#include "core_cmFunc.h"

void updateOnboardLEDs();
void testUARTTx();

#define WS2812_QUANTITY 88

uint8_t matrix[88*3];
static unsigned char *ptr;
static unsigned int pos = 0;
volatile unsigned char go = 0;


int main(void)
{
	//status_t status;		// Declaration of return variable for DAVE3 APIs (toggle comment if required)
	DAVE_Init();			// Initialization of DAVE Apps
	IO004_SetPin(IO004_Handle0);
	P0_5_set_mode(OUTPUT_PP_GP); 	//WS2812 data pin
	//handle_t timer;
	//timer=SYSTM001_CreateTimer(1000,SYSTM001_PERIODIC,testUARTTx,NULL);
	//SYSTM001_StartTimer(timer);
	while(1)
	{
		if (go==1)
		{
			 __disable_irq();
			ws2812_sendarray(matrix, WS2812_QUANTITY * 3);
			__enable_irq();
			go=0;
		}
	}
	return 0;
}



void testUARTTx()
{
	//const uint8_t daten[] = "ABCDEFGHIJKLMNOP\n";
	//uint16_t written = 0;
	//while(written < sizeof(daten)-1)
	//	written += UART001_WriteDataBytes(&UART001_Handle0,&daten[written],sizeof(daten)-written-1);

	//UART001_WriteDataBytes(&UART001_Handle0,daten,17);
	//UART001_WriteDataMultiple(&UART001_Handle0,(uint16_t *)daten,sizeof(daten)/2);
}



void updateOnboardLEDs()
{
	IO004_TogglePin(IO004_Handle0);
	IO004_TogglePin(IO004_Handle1);
}



void RxFIFOBufferEventHandler()
{
	if(UART001_GetFlagStatus(&UART001_Handle0,UART001_FIFO_STD_RECV_BUF_FLAG) == UART001_SET)
	{
		UART001_ClearFlag(&UART001_Handle0,UART001_FIFO_STD_RECV_BUF_FLAG);
		unsigned char b;
		b = UART001_ReadData(UART001_Handle0);
		if (b == 1)  {pos=0; ptr=matrix; return;}
		if (pos == (WS2812_QUANTITY*3)) {} else {*ptr=b; ptr++; pos++;}
		if (pos == ((WS2812_QUANTITY*3)-1)) {go=1;}
		updateOnboardLEDs();
	}

	//UART001_WriteData(UART001_Handle0,uartInput);
}



void TxBufferEventHandler()
{
	if(UART001_GetFlagStatus(&UART001_Handle0,UART001_FIFO_STD_TRANSMIT_BUF_FLAG) == UART001_SET)
		UART001_ClearFlag(&UART001_Handle0,UART001_FIFO_STD_TRANSMIT_BUF_FLAG);
}
