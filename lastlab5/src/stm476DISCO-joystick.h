//*****************************************************************************
// STM32L476 Discovery Board Joystick Driver
//     author: Scott Tippens
//     date:   June 18, 2018
//*****************************************************************************
#ifndef __STM476DISCO_JOYSTICK_H
#define __STM476DISCO_JOYSTICK_H


void initJoystick();
int  readJoystickCenter();
int  readJoystickLeft();
int  readJoystickRight();
int  readJoystickUp();
int  readJoystickDown();


#endif /* __STM476DISCO_JOYSTICK_H */
