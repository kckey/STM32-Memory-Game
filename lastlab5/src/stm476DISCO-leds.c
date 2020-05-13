#include <stdint.h>
#include "stm32l476xx.h"
#include "stm476DISCO-leds.h"

//*****************************************************************************
//  STM32L476 Discovery Board Driver for the LEDs
//      author: Scott Tippens
//        date: 2018-06-23 -- created
//              2018-10-25 -- updated for GNU compiler
//
//      Provides a hardware driver for the STM32L476 Discovery board red and
//      green LEDs.
//
//      NOTE: The 'initLEDs()' initialization routine must be called prior
//            to using any of the other joystick functions.
//*****************************************************************************

 
//=============================================================================
//  initLEDs()
//      parms:  none
//      return: none
//      description:
//          Initializes the red and green leds on the STM32L476 Discovery Board.
//          Red LED   = Port B pin 2
//          Green LED = Port E pin 8
//=============================================================================
void initLEDs()
{
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN | RCC_AHB2ENR_GPIOEEN; // Enable PortB and PortE clocks
    
    //-- configure red led ----------------------------------------------------
    GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE2) | GPIO_MODER_MODE2_0;   // PB2=output
    GPIOB->OTYPER &= ~(GPIO_OTYPER_OT2);                                      // PB2=push-pull
    GPIOB->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED2);                                // PB2=low speed
    GPIOB->PUPDR &= ~(GPIO_PUPDR_PUPD2);                                      // PB2=no pullup or pulldown
    
    //-- configure green led --------------------------------------------------
    GPIOE->MODER = (GPIOE->MODER & ~GPIO_MODER_MODE8) | GPIO_MODER_MODE8_0;   // PE8=output
    GPIOE->OTYPER &= ~(GPIO_OTYPER_OT8);                                      // PE8=push-pull​
    GPIOE->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED8);                                // PE8=low speed
    GPIOE->PUPDR &= ~(GPIO_PUPDR_PUPD8);                                      // PE8=no pullup or pulldown
}

 
//=============================================================================
//  redLEDOn()
//      parms:  none
//      return: none
//      description:
//          Turns on the red led
//=============================================================================
void redLEDOn()
{
    GPIOB->ODR |= GPIO_ODR_OD2;   // Output 1 to turn on red LED
}

 
//=============================================================================
//  redLEDOff()
//      parms:  none
//      return: none
//      description:
//          Turns off the red led
//=============================================================================
void redLEDOff()
{
    GPIOB->ODR &= ~(GPIO_ODR_OD2);   // Output 0 to turn off red LED
}

 
//=============================================================================
//  redLEDToggle()
//      parms:  none
//      return: none
//      description:
//          Toggle the red led
//=============================================================================
void redLEDToggle()
{
    GPIOB->ODR ^= GPIO_ODR_OD2;   // Toggle red LED
}

 
//=============================================================================
//  greenLEDOn()
//      parms:  none
//      return: none
//      description:
//          Turns on the green led
//=============================================================================
void greenLEDOn()
{
    GPIOE->ODR |= GPIO_ODR_OD8;   // Output 1 to turn on green LED
}

 
//=============================================================================
//  greenLEDOff()
//      parms:  none
//      return: none
//      description:
//          Turns off the green led
//=============================================================================
void greenLEDOff()
{
    GPIOE->ODR &= ~(GPIO_ODR_OD8);   // Output 0 to turn off green LED
}

 
//=============================================================================
//  greenLEDToggle()
//      parms:  none
//      return: none
//      description:
//          Toggles the green LED
//=============================================================================
void greenLEDToggle()
{
    GPIOE->ODR ^= GPIO_ODR_OD8;   // Toggle green LED
}

            
