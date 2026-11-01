/*
 * stm32f407xx_gpio_driver.h
 *
 *  Created on: Oct 7, 2026
 *      Author: kep
 */

#ifndef INC_STM32F407XX_GPIO_DRIVER_H_
#define INC_STM32F407XX_GPIO_DRIVER_H_

#include "stm32f407xx.h"

/*Handle Structure for a GPIO pin */

typedef struct
{
	uint8_t GPIO_PinNumber;		/* !< Values from @GPIO_PIN_NUMBERS */
	uint8_t GPIO_PinMode;		/*Possible values from @GPIO_PIN_MODES */
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFuncMode;

}GPIO_PinConfig_t;

typedef struct
{
	//pointer to hold the base address of GPIO peripheral//

	GPIO_RegDef_t *pGPIOx; //this holds the base address of the GPIO to which the pin belongs
	GPIO_PinConfig_t GPIO_PinConfig; //This holds the GPIO pin configuration settings//


}GPIO_Handle_t;

/* @GPIO_PIN_NUMBERS
 *
 */

#define GPIO_PIN_0		0
#define	GPIO_PIN_1		1
#define GPIO_PIN_2		2
#define	GPIO_PIN_3		3
#define GPIO_PIN_4		4
#define	GPIO_PIN_5		5
#define GPIO_PIN_6		6
#define	GPIO_PIN_7		7
#define GPIO_PIN_8		8
#define	GPIO_PIN_9		9
#define GPIO_PIN_10		10
#define	GPIO_PIN_11		11
#define GPIO_PIN_12		12
#define	GPIO_PIN_13		13
#define GPIO_PIN_14		14
#define	GPIO_PIN_15		15










/*
 * @GPIO_PIN_MODES
 */
//ACCORDING TO REFERENCE MANUAL REGISTER
#define GPIO_MODE_IN 		0
#define GPIO_MODE_OUT 		1
#define GPIO_MODE_ALT		2
#define GPIO_MODE_ANALOG	3

// CUSTOM FUNCTIONS
#define GPIO_MODE_IT_FT  	4  //IT INPUT FT- FALLING EDGE
#define GPIO_MODE_IT_RT		5	// RISING EDGE
#define GPIO_MODE_IT_RFT	6	// RISING EDGE FALLING EDGE TRIGGER

/* GPIO POSSIBLE OUTPUT TYPES
 *
 */

#define GPIO_OP_TYPE_PP 0		// OUTPUT TYPE PUSH-PULL
#define GPIO_OP_TYPE_OD	1		//OUT TYPE- OPEN DRAIN

/* GPIO OUTPUT SPEED POSSIBLE MODES */

#define GPIO_OP_SPEED_LOW	0
#define GPIO_OP_SPEED_MED	1
#define GPIO_OP_SPEED_HI 	2		//High Speed
#define GPIO_OP_SPEED_VHI	3		//Very High speed

/*GPIO PULLUP PULLDOWN CONFIG */

#define GPIO_NO_PUPD		0
#define GPIO_PU				1
#define GPIO_PD				2



/************************************************************************************
 * 								APIs support by this driver
 * 					For more info about the APIs check the function definitions
 ************************************************************************************/

//Peripheral Clock Setup
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);

// Init and De-Init
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
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









#endif /* INC_STM32F407XX_GPIO_DRIVER_H_ */
