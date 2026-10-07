/*
 * stm32f407xx.h
 *
 *  Created on: Oct 6, 2026
 *      Author: kep
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdint.h>
#define __vo volatile


/* define the base address of flash and SRAM */

#define FLASH_BASEADDR 				0x08000000U  /* FLASH or MAIN memory base address */

/* SRAM1 is main SRAM. Simply calling SRAM1 or MAIN SRAM as SRAM */
#define SRAM_BASEADDR 				0x20000000U
#define SRAM 		   				SRAM_BASEADDR
#define SRAM2_BASEADDR	 			0x2001C000U  	/*SRAM2 BASE ADDRESS*/
#define ROM_BASEADDR   				0x1FFF0000U		/*ROM or SYSTEM MEMORY base address */
#define OTPAREA_BASEADDR 			0x1FFF7800U


/* AHB and APB peripheral base address */

#define PERIPH_BASE 				0x40000000U
#define APB1PERIPH_BASEADDR 		PERIPH_BASE
#define APB2PERIPH_BASEADDR			0x40010000U
#define AHB1PERIPH_BASEADDR 		0x40020000U
#define AHB2PERIPH_BASEADDR			0x50000000U


/*Define base address for all peripherals on AHB1 */

#define GPIOA_BASEADDR 				(AHB1PERIPH_BASEADDR + 0x0000) /*base address + offset*/
#define GPIOB_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR				(AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR				(AHB1PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR				(AHB1PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR				(AHB1PERIPH_BASEADDR + 0x1C00)
#define GPIOI_BASEADDR				(AHB1PERIPH_BASEADDR + 0x2000)
#define GPIOJ_BASEADDR				(AHB1PERIPH_BASEADDR + 0x2400)
#define GPIOK_BASEADDR				(AHB1PERIPH_BASEADDR + 0x2800)

/*RCC BASE ADDRESS */

#define RCC_BASEADDR				(AHB1PERIPH_BASEADDR + 0x3800)


/*Base addresses of peripheral on APB1 bus*/

#define TIM2_BASEADDR			(APB1PERIPH_BASEADDR + 0x0000)
#define TIM3_BASEADDR			(APB1PERIPH_BASEADDR + 0x0400)
#define TIM4_BASEADDR			(APB1PERIPH_BASEADDR + 0x0800)
#define TIM5_BASEADDR			(APB1PERIPH_BASEADDR + 0x0C00)
#define TIM6_BASEADDR			(APB1PERIPH_BASEADDR + 0x1000)
#define TIM7_BASEADDR			(APB1PERIPH_BASEADDR + 0x1400)
#define TIM12_BASEADDR			(APB1PERIPH_BASEADDR + 0x1800)
#define TIM13_BASEADDR			(APB1PERIPH_BASEADDR + 0x1C00)
#define TIM14_BASEADDR			(APB1PERIPH_BASEADDR + 0x2000)

#define I2C1_BASEADDR			(APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR			(APB1PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR			(APB1PERIPH_BASEADDR + 0x5C00)

#define CAN1_BASEADDR			(APB1PERIPH_BASEADDR + 0x6400)
#define CAN2_BASEADDR			(APB1PERIPH_BASEADDR + 0x6800)

#define UART4_BASEADDR			(APB1PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR			(APB1PERIPH_BASEADDR + 0x5000)
#define UART7_BASEADD			(APB1PERIPH_BASEADDR + 0x7C00)
#define UART8_BASEADDR			(APB1PERIPH_BASEADDR + 0x7800)

#define USART2_BASEADDR			(APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR			(APB1PERIPH_BASEADDR + 0x4800)

#define SPI2_BASEADDR			(APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR			(APB1PERIPH_BASEADDR + 0x3C00)

#define WWDG_BASEADDR			(APB1PERIPH_BASEADDR + 0x2C00)  /* Window Watchdog */
#define IWDG_BASEADDR			(APB1PERIPH_BASEADDR + 0x3000)	/* Independent Watchdog */

/*Base addresses of peripherals on APB2 */

#define EXTI_BASEADDR			(APB2PERIPH_BASEADDR + 0x3C00)

#define TIM1_BASEADDR			(APB2PERIPH_BASEADDR + 0x0000)
#define TIM8_BASEADDR			(APB2PERIPH_BASEADDR + 0x0400)
#define TIM9_BASEADDR 			(APB2PERIPH_BASEADDR + 0x4000)
#define TIM10_BASEADDR			(APB2PERIPH_BASEADDR + 0x4400)
#define TIM11_BASEADDR			(APB2PERIPH_BASEADDR + 0x4800)

#define USART1_BASEADDR			(APB2PERIPH_BASEADDR + 0x1000)
#define USART6_BASEADDR			(APB2PERIPH_BASEADDR + 0x1400)

#define SPI1_BASEADDR			(APB2PERIPH_BASEADDR + 0x3000)
#define SPI4_BASEADDR			(APB2PERIPH_BASEADDR + 0x3400)
#define SPI5_BASEADDR			(APB2PERIPH_BASEADDR + 0x5000)
#define SPI6_BASEADDR			(APB2PERIPH_BASEADDR + 0x5400)

#define SYSCFG_BASEADDR			(APB2PERIPH_BASEADDR + 0x3800)

/* Peripheral register addresses using struct */


typedef struct
{
	__vo uint32_t MODER;		/*GPIO port mode register*/
	__vo uint32_t OTYPER;		/*GPIO port output type register */
	__vo uint32_t OSPEEDR;		/*GPIO port output speed register */
	__vo uint32_t PUPDR;		/*GPIO Port pull-up/pull-down register */
	__vo uint32_t IDR;			/*GPIO port input data register */
	__vo uint32_t ODR;			/*GPIO port out data register */
	__vo uint32_t BSRR;			/*GPIO port bit set/reset register */
	__vo uint32_t LCKR;			/*GPIO port configuration lock register */
	__vo uint32_t AFRL;			/*GPIO alternate function low register */
	__vo uint32_t AFRH;			/*GPIO alternate function high register */

}GPIO_RegDef_t;

/* Peripheral definitions (peripheral base addresses typecasted to xxx_RegDef_t) */
#define GPIOA     ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB     ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC     ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD     ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE     ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF     ((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG     ((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH     ((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define GPIOI     ((GPIO_RegDef_t*)GPIOI_BASEADDR)
#define GPIOJ     ((GPIO_RegDef_t*)GPIOJ_BASEADDR)
#define GPIOK     ((GPIO_RegDef_t*)GPIOK_BASEADDR)




/*Struct for RCC register addresses */

typedef struct
{
 __vo uint32_t	RCC_CR;
 __vo uint32_t	RCC_PLLCFGR;
 __vo uint32_t	RCC_CFGR;
 __vo uint32_t	RCC_CIR;
 __vo uint32_t	RCC_AHB1RSTR;
 __vo uint32_t	RCC_AHB2RSTR;
 __vo uint32_t	RCC_AHB3RSTR;
 __vo uint32_t	RESERVED0;
 __vo uint32_t	RCC_APB1RSTR;
 __vo uint32_t	RCC_APB2RSTR;
 __vo uint32_t	RESERVED1;
 __vo uint32_t	RESERVED2;
 __vo uint32_t	RCC_AHB1ENR;
 __vo uint32_t	RCC_AHB2ENR;
 __vo uint32_t	RCC_AHB3ENR;
 __vo uint32_t	RESERVED3;
 __vo uint32_t	RCC_APB1ENR;
 __vo uint32_t	RCC_APB2ENR;
 __vo uint32_t	RESERVED4;
 __vo uint32_t	RESERVED5;
 __vo uint32_t	RCC_AHB1LPENR;
 __vo uint32_t	RCC_AHB2LPENR;
 __vo uint32_t	RCC_AHB3LPENR;
 __vo uint32_t	RESERVED6;
 __vo uint32_t	RCC_APB1LPENR;
 __vo uint32_t	RCC_APB2LPENR;
 __vo uint32_t	RESERVED7;
 __vo uint32_t	RESERVED8;
 __vo uint32_t	RCC_BDCR;
 __vo uint32_t	RCC_CSR;
 __vo uint32_t	RESERVED9;
 __vo uint32_t	RESERVED10;
 __vo uint32_t	RCC_SSCGR;
 __vo uint32_t	RCC_PLLI2SCFGR;
 __vo uint32_t	RCC_PLLSAICFGR;
 __vo uint32_t	RCC_DCKCFGR;

}RCC_RegDef_t;

#define RCC 	((RCC_RegDef_t*)RCC_BASEADDR))

/* CLOCK ENABLE MACRO FOR GPIO A TO K */

#define GPIOA_PCLK_EN()	(RCC->AHB1ENR |= (1<<0))
#define GPIOB_PCLK_EN()	(RCC->AHB1ENR |= (1<<1))
#define GPIOC_PCLK_EN()	(RCC->AHB1ENR |= (1<<2))
#define GPIOD_PCLK_EN()	(RCC->AHB1ENR |= (1<<3))
#define GPIOE_PCLK_EN()	(RCC->AHB1ENR |= (1<<4))
#define GPIOF_PCLK_EN()	(RCC->AHB1ENR |= (1<<5))
#define GPIOG_PCLK_EN()	(RCC->AHB1ENR |= (1<<6))
#define GPIOH_PCLK_EN()	(RCC->AHB1ENR |= (1<<7))
#define GPIOI_PCLK_EN()	(RCC->AHB1ENR |= (1<<8))
#define GPIOJ_PCLK_EN()	(RCC->AHB1ENR |= (1<<9))
#define GPIOK_PCLK_EN()	(RCC->AHB1ENR |= (1<<10))

/* I2C CLOCK ENABLE MACROS */

#define I2C1_CLK_EN()	(RCC->APB1ENR|= (1<<21))
#define I2C2_CLK_EN()	(RCC->APB1ENR|= (1<<22))
#define I2C3_CLK_EN()	(RCC->APB1ENR|= (1<<23))

/*SPI CLOCK ENABLE MACROS */
#define SPI1_CLK_EN()	(RCC->APB2ENR)|=(1<<12)
#define SPI2_CLK_EN()	(RCC->APB1ENR|= (1<<14))
#define SPI3_CLK_EN()	(RCC->APB1ENR|= (1<<15))
#define SPI4_CLK_EN()	(RCC->APB2ENR|= (1<<13))

/*UART CLOCK ENABLE MACROS */

#define UART4_CLK_EN()	(RCC->APB1ENR|= (1<<19))
#define UART5_CLK_EN()	(RCC->APB1ENR|= (1<<20))
#define UART7_CLK_EN()	(RCC->APB1ENR|= (1<<30))
#define UART8_CLK_EN()	(RCC->APB1ENR|= (1<<31))

/*CAN BUS CLOCK ENABLE MACROS */

#define CAN1_CLK_EN()	(RCC->APB1ENR|= (1<<25))
#define CAN2_CLK_EN()	(RCC->APB1ENR|= (1<<26))

/*USART CLOCK ENABLE MACROS */
#define USART1_CLK_EN()	(RCC->APB2ENR|= (1<<4))
#define USART2_CLK_EN()	(RCC->APB1ENR|= (1<<17))
#define USART3_CLK_EN()	(RCC->APB1ENR|= (1<<18))
#define USART6_CLK_EN()	(RCC->APB1ENR|= (1<<5))

/* SYSCFG CLOCK ENABLE MACRO */

#define SYSCFG_CLK_EN()	(RCC->APB2ENR|= (1<<14))


/* CLOCK DISABLE MACRO FOR GPIO A TO K */

#define GPIOA_PCLK_DI()	(RCC->AHB1ENR &= ~(1<<0))
#define GPIOB_PCLK_DI()	(RCC->AHB1ENR &= ~(1<<1))
#define GPIOC_PCLK_DI()	(RCC->AHB1ENR &= ~(1<<2))
#define GPIOD_PCLK_DI()	(RCC->AHB1ENR &= ~(1<<3))
#define GPIOE_PCLK_DI()	(RCC->AHB1ENR &= ~(1<<4))
#define GPIOF_PCLK_DI()	(RCC->AHB1ENR &= ~(1<<5))
#define GPIOG_PCLK_DI()	(RCC->AHB1ENR &= ~(1<<6))
#define GPIOH_PCLK_DI()	(RCC->AHB1ENR &= ~(1<<7))
#define GPIOI_PCLK_DI()	(RCC->AHB1ENR &= ~(1<<8))
#define GPIOJ_PCLK_DI()	(RCC->AHB1ENR &= ~(1<<9))
#define GPIOK_PCLK_DI()	(RCC->AHB1ENR &= ~(1<<10))

/* I2C CLOCK DISABLE MACROS */

#define I2C1_CLK_DI()	(RCC->APB1ENR &= ~(1<<21))
#define I2C2_CLK_DI()	(RCC->APB1ENR &= ~(1<<22))
#define I2C3_CLK_DI()	(RCC->APB1ENR &= ~(1<<23))

/*SPI CLOCK DISABLE MACROS */
#define SPI1_CLK_DI()	(RCC->APB2ENR&= ~(1<<12))
#define SPI2_CLK_DI()	(RCC->APB1ENR&= ~(1<<14))
#define SPI3_CLK_DI()	(RCC->APB1ENR&= ~(1<<15))
#define SPI4_CLK_DI()	(RCC->APB2ENR&= ~(1<<13))

/*UART CLOCK DISABLE MACROS */

#define UART4_CLK_DI()	(RCC->APB1ENR &= ~(1<<19))
#define UART5_CLK_DI()	(RCC->APB1ENR &= ~(1<<20))
#define UART7_CLK_DI()	(RCC->APB1ENR &= ~(1<<30))
#define UART8_CLK_DI()	(RCC->APB1ENR &= ~(1<<31))

/*CAN BUS CLOCK DISABLE MACROS */

#define CAN1_CLK_DI()	(RCC->APB1ENR &= ~(1<<25))
#define CAN2_CLK_DI()	(RCC->APB1ENR &= ~(1<<26))

/*USART CLOCK DISABLE MACROS */
#define USART1_CLK_DI()	(RCC->APB2ENR &= ~(1<<4))
#define USART2_CLK_DI()	(RCC->APB1ENR &= ~(1<<17))
#define USART3_CLK_DI()	(RCC->APB1ENR &= ~(1<<18))
#define USART6_CLK_DI()	(RCC->APB1ENR &= ~(1<<5))

/* SYSCFG CLOCK DISABLE MACRO */

#define SYSCFG_CLK_DI()	(RCC->APB2ENR &= ~(1<<14))






















#endif /* INC_STM32F407XX_H_ */
