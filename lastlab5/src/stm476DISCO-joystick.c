#include "stm32l476xx.h"
#include "stm476DISCO-joystick.h"
#include "stm476DISCO-leds.h"

//*****************************************************************************
//  STM32L476 Discovery Board Driver for the Joystick
//      author: Scott Tippens
//        date: 2018-06-22 -- created
//              2018-10-25 -- updated for GNU compiler
//
//      Provides a hardware drivers for the STM32L476 Discovery board joystick.
//
//      NOTE: 
//          The 'initJoystick()' initialization routine must be called prior
//          to using any of the other joystick functions.  
//*****************************************************************************

 
//=============================================================================
//  initJoystick()
//      parms:  none
//      return: none
//      description:
//          Initializes the joystick inputs on port A
//=============================================================================
void initJoystick()
{
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;      // Enable PortA clock
    
    GPIOA->MODER &= ~(GPIO_MODER_MODE0        // PA0=input
                       | GPIO_MODER_MODE1     // PA1=input 
                       | GPIO_MODER_MODE2     // PA2=input
                       | GPIO_MODER_MODE3     // PA3=input
                       | GPIO_MODER_MODE5);   // PA5=input

    GPIOA->PUPDR = (GPIOA->PUPDR & ~(GPIO_PUPDR_PUPD0       // PE0 = no pullup or pulldown
                                      | GPIO_PUPDR_PUPD1    // clear PE1 mode bits
                                      | GPIO_PUPDR_PUPD2    // clear PE2 mode bits
                                      | GPIO_PUPDR_PUPD3    // clear PE3 mode bits
                                      | GPIO_PUPDR_PUPD5)   // clear PE5 mode bits
                    ) | GPIO_PUPDR_PUPD1_1    // PE1 = pulldown
                      | GPIO_PUPDR_PUPD2_1    // PE2 = pulldown
                      | GPIO_PUPDR_PUPD3_1    // PE3 = pulldown
                      | GPIO_PUPDR_PUPD5_1;   // PE5 = pulldown
}

 
//=============================================================================
//  readJoystickCenter()
//      parms:  none
//      return:  0 = not pressed
//              !0 = pressed
//      description:
//          Read joystick center button
//=============================================================================
int readJoystickCenter()
{
    return GPIOA->IDR & GPIO_IDR_ID0;
}

 
//=============================================================================
//  readJoystickLeft()
//      parms:  none
//      return:  0 = not pressed
//              !0 = pressed
//      description:
//          Read joystick left button
//=============================================================================
int readJoystickLeft()
{
    return GPIOA->IDR & GPIO_IDR_ID1;
}

 
//=============================================================================
//  readJoystickRight()
//      parms:  none
//      return:  0 = not pressed
//              !0 = pressed
//      description:
//          Read joystick right button
//=============================================================================
int readJoystickRight()
{
    return GPIOA->IDR & GPIO_IDR_ID2;
}

 
//=============================================================================
//  readJoystickUp()
//      parms:  none
//      return:  0 = not pressed
//              !0 = pressed
//      description:
//          Read joystick up button
//=============================================================================
int readJoystickUp()
{
    return GPIOA->IDR & GPIO_IDR_ID3;
}

 
//=============================================================================
//  readJoystickDown()
//      parms:  none
//      return:  0 = not pressed
//              !0 = pressed
//      description:
//          Read joystick down button
//=============================================================================
int readJoystickDown()
{
    return GPIOA->IDR & GPIO_IDR_ID5;
}

            
