/*
 * 001LED_TEST.c
 *
 *  Created on: Nov 2, 2026
 *      Author: kep
 */

#include "stm32f407xx.h"

void delay(void)
{
	for (uint32_t i = 0; i<250000;i++);

}


int main (void)
{	// For ORANGE ONBOARD LED
	GPIO_Handle_t ORANGE_LED;
	ORANGE_LED.pGPIOx=GPIOD;
	ORANGE_LED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_13;
	ORANGE_LED.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	ORANGE_LED.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OP_SPEED_HI;
	ORANGE_LED.GPIO_PinConfig.GPIO_PinOPType= GPIO_OP_TYPE_PP;


	//FOR GREEN ONBOARD LED
	GPIO_Handle_t GREEN_LED;
	GREEN_LED.pGPIOx=GPIOD;
	GREEN_LED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_12;
	GREEN_LED.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GREEN_LED.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OP_SPEED_HI;
	GREEN_LED.GPIO_PinConfig.GPIO_PinOPType= GPIO_OP_TYPE_PP;



		//FOR GREEN ONBOARD LED
	GPIO_Handle_t RED_LED;
	RED_LED.pGPIOx=GPIOD;
	RED_LED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_14;
	RED_LED.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	RED_LED.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OP_SPEED_HI;
	RED_LED.GPIO_PinConfig.GPIO_PinOPType= GPIO_OP_TYPE_PP;


				//FOR GREEN ONBOARD LED
	GPIO_Handle_t BLUE_LED;
	BLUE_LED.pGPIOx=GPIOD;
	BLUE_LED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_15;
	BLUE_LED.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	BLUE_LED.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OP_SPEED_HI;
	BLUE_LED.GPIO_PinConfig.GPIO_PinOPType= GPIO_OP_TYPE_PP;

	GPIO_Handle_t pushbutton;

	pushbutton.pGPIOx = GPIOA;
	pushbutton.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_0;
	pushbutton.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	pushbutton.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OP_SPEED_HI;
	pushbutton.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PD;


	GPIO_PeriClockControl(GPIOA,ENABLE);
	GPIO_PeriClockControl(GPIOD,ENABLE);
	GPIO_Init(&ORANGE_LED);
	GPIO_Init(&GREEN_LED);
	GPIO_Init(&RED_LED);
	GPIO_Init(&BLUE_LED);
	GPIO_Init(&pushbutton);
	while(1){

		if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_0) ==1)
		{


		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_15);
		delay();
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_15);
		delay();
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_12);
		delay();
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_12);
		delay();
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_13);
		delay();
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_13);
		delay();
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_14);
		delay();
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_14);
		delay();
		}
				else if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_0) ==0)
				{
						GPIO_WriteToOutputPort(GPIOD,0);
				}

	}




	return 0;

}
