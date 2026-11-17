/*
 * LEDorder.c
 *
 *  Created on: Nov 3, 2026
 *      Author: kep
 */

#include "stm32f407xx.h"


#define HIGH 1

void delay(void)
{
	for(uint32_t j=0;j<500000;j++);
}

int main(void)
{

	GPIO_Handle_t pushbutton, ORANGE_LED, GREEN_LED, RED_LED, BLUE_LED;


	ORANGE_LED.pGPIOx=GPIOD;
	ORANGE_LED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_13;
	ORANGE_LED.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	ORANGE_LED.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OP_SPEED_HI;
	ORANGE_LED.GPIO_PinConfig.GPIO_PinOPType= GPIO_OP_TYPE_PP;


	//FOR GREEN ONBOARD LED

	GREEN_LED.pGPIOx=GPIOD;
	GREEN_LED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_12;
	GREEN_LED.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GREEN_LED.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OP_SPEED_HI;
	GREEN_LED.GPIO_PinConfig.GPIO_PinOPType= GPIO_OP_TYPE_PP;



		//FOR GREEN ONBOARD LED

	RED_LED.pGPIOx=GPIOD;
	RED_LED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_14;
	RED_LED.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	RED_LED.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OP_SPEED_HI;
	RED_LED.GPIO_PinConfig.GPIO_PinOPType= GPIO_OP_TYPE_PP;


				//FOR GREEN ONBOARD LED

	BLUE_LED.pGPIOx=GPIOD;
	BLUE_LED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_15;
	BLUE_LED.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	BLUE_LED.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OP_SPEED_HI;
	BLUE_LED.GPIO_PinConfig.GPIO_PinOPType= GPIO_OP_TYPE_PP;



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
	uint32_t i=0;

	uint32_t  previous =0;
	while(1)
	{

		if ((GPIO_ReadFromInputPin(GPIOA, 0)) == HIGH && previous ==0)
		{
			delay();
			++i;
		}
			if(i==1)
			{ GPIO_WriteToOutputPin(GPIOD, 13,HIGH);

			} else if (i==2)
			{

				GPIO_WriteToOutputPin(GPIOD, 12,HIGH);
			} else if (i==3)
			{
				GPIO_WriteToOutputPin(GPIOD, 14,HIGH);

			} else if (i==4)
			{
				GPIO_WriteToOutputPin(GPIOD, 15,HIGH);
			} else if(i>4)
			{
				i=0;
				GPIO_WriteToOutputPort(GPIOD, 0);
			}

		}




		return 0;
	}


