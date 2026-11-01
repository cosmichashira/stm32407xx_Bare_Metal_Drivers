/*
 * stm32f407xx_gpio_driver.c
 *
 */

#include "stm32f407xx_gpio_driver.h"


//Peripheral Clock Setup


/*********************************************************************
 * @Function      		  - GPIO_PeriClockControl
 *
 * @brief             - This function enables or disables peripheral clock for the given GPIO port
 *
 * @parameter[in(data in)]- base address of GPIO peripheral
 * @parameter[in]         - ENABLE or DISABLE macros
 * @parameter[in]         -
 *
 * @return            -  none (void func)
 *
 * @Note              -  none

 */

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}else if(pGPIOx== GPIOB)
		{
			GPIOB_PCLK_EN();
		}else if(pGPIOx== GPIOC)
		{
			GPIOC_PCLK_EN();
		}else if(pGPIOx== GPIOD)
		{
			GPIOD_PCLK_EN();
		}else if(pGPIOx== GPIOE)
		{
			GPIOE_PCLK_EN();
		}else if(pGPIOx== GPIOF)
		{
			GPIOF_PCLK_EN();
		}else if(pGPIOx== GPIOG)
		{
			GPIOG_PCLK_EN();
		}else if(pGPIOx== GPIOH)
		{
			GPIOH_PCLK_EN();
		}else if(pGPIOx== GPIOI)
		{
			GPIOI_PCLK_EN();
		}
}else{
	if(pGPIOx == GPIOA)
	{
		GPIOA_PCLK_DI();

	}else if(pGPIOx== GPIOB)
	{
	GPIOB_PCLK_DI();
	}else if(pGPIOx== GPIOC)
	{
	GPIOC_PCLK_DI();
	}else if(pGPIOx== GPIOD)
	{
	GPIOD_PCLK_DI();
	}else if(pGPIOx== GPIOE)
	{
	GPIOE_PCLK_DI();
	}else if(pGPIOx== GPIOF)
	{
		GPIOF_PCLK_DI();
	}else if(pGPIOx== GPIOG)
	{
		GPIOG_PCLK_DI();
	}else if(pGPIOx== GPIOH)
	{
	GPIOH_PCLK_DI();
	}else if(pGPIOx== GPIOI)
	{
		GPIOI_PCLK_DI();
	}
		}
	}


// Init and De-Init
/*********************************************************************
 * @Function      		  - GPIO_Init
 *
 * @brief             -  1. Configure the mode of gpio pin
 	 	 	 	 	 	 * 2. Configure the speed
 	 	 	 	 	 	 * 3. Configure the PuPd settings
 	 	 	 	 	 	 * 4. Configure the Output type
 	 	 	 	 	 	 * 5. Configure the alt functionality
 *
 * @parameter[in(data in)]- base address of GPIO peripheral
 * @parameter[in]         - ENABLE or DISABLE macros
 * @parameter[in]         -
 *
 * @return            -  none (void func)
 *
 * @Note              -  none
 *
 * */

void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	uint32_t temp; //temporary register
	temp=0;

	//1. Configure the mode of GPIO pin

	if(pGPIOHandle ->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
		// Non interrupt mode

		temp = pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 *pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	}else
	{
		//code Later (interrupt mode
	}
}




void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

// Data
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint8_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

//IRQ CONFIG AND ISR HANDLIING
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi);
void GPIO_IRQHandling(uint8_t PinNumber);
