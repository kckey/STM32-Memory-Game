#include "stm32l476xx.h"
#include "stm476DISCO-leds.h"
#include "stm476DISCO-joystick.h"


#define startLab            0
#define gameStart           1
#define gamePattern         2
#define playerPress         3
#define leftJoystickDown    4
#define rightJoystickDown   5
#define leftJoystickUp      6
#define rightJoystickUp     7
#define losingRedLEDs       8
#define winningGreenLEDs    9
#define newGamePressed     10
#define newGameReleased    11
int state = startLab;

/*
 *
 * Due on: Apr 27, 2020
 *      Author: kaleb Key
 *      Class: CPE 3000
 *      Assignment: Lab 5
 * Purpose: This Lab is an assignment where we have to make a memory game with our stm32 board
 * I chose to do this by using a state machine, and running through each case as appropriate
 * there are cases for the start, getting a pattern, user input through the joystick(left,right,up & down)
 * this assignment is more easily accomplished with the use of the header files that contain the function for the
 * led operation and the joystick buttons being pressed and not so.
 *
 */

int main()
{
	//== Initialization of the Joystick & the LEDs==================================
	initLEDs();
	initJoystick();
	int pattern; //holds the binary value for the pattern to compare
	int andmask; //we use this andmask to generate a pattern with the & operation
	int countLoop; //for use to end conditions in forloop

	//== loop that keeps the program continuous ====================================
	while(1)
	{

		switch(state) //switch statement begins, controls the cases ----------------
		{
		//startLab the whole game==
		case startLab:
		countLoop= 3000-2921;
		pattern= 0;
		state = gameStart;
		break;




		//==down joystick button starts the program on read of press ===============
		case gameStart:
			//-- Initialization of the ---------------------------------------------
			redLEDOn();
			greenLEDOn();

		//== Create operation that begins the game on joystick down press =========
			pattern= 79;
			while(!readJoystickDown())
			{
			pattern++;
			}
			state=gamePattern;
			break;


		//== Create a pattern based on time it takes to press joystick down========
		case gamePattern:
			andmask=0x01;
			for (int i=0; i<6; i++)
					{
						//--turn leds off half cycle-------------------------------
						redLEDOff();
						greenLEDOff();
						for(int j=0;j<87654;j++); //delay half cycle

						//-- turn on pattern led for half cycle -------------------
						if(pattern & andmask)
						{
							redLEDOff();
							greenLEDOn();
							//leftRight=0;
						}
						else
						{
							redLEDOn();
							greenLEDOff();
							//leftRight=1;
						}

						for(int j=0; j<87654;j++); //delay half cycle

						andmask <<= 1;// shifts the bit to the left 1

					}
			andmask = 0x01;
			state=playerPress;
			break;


		case playerPress: //turns off both leds and then checks for which state to send to
			redLEDOff();
			greenLEDOff();
			if(readJoystickRight())
				state = rightJoystickDown;
			else if(readJoystickLeft())
				state = leftJoystickDown;
			else if(readJoystickUp())
				state = newGamePressed;
			break;


		case newGamePressed://--restart case for if the up button is pressed ------------------
			if(readJoystickUp)
				state=gameStart;//sends to start
		else
				state=gameStart;//sends to start
			break;


		case rightJoystickDown://-- case for is the right button is pressed ------------------------
			greenLEDOn();
			redLEDOff();
			if(!readJoystickRight())
				state=rightJoystickUp;
			break;


		case rightJoystickUp://--case for moving forward to win or lose after the right button is released
			greenLEDOff();
			redLEDOff();

			if((pattern & andmask) && (countLoop !=5))
			{
				andmask <<=1;
				countLoop++;
				state=playerPress;
			}
			else if(!(pattern & andmask) && (countLoop == 5))
				state=winningGreenLEDs;
			else
				state=losingRedLEDs;
			break;


		case leftJoystickDown://== case for is the left button is pressed =================================
			greenLEDOff();
			redLEDOn();
			if(!readJoystickLeft())
				state= leftJoystickUp;
			break;


		case leftJoystickUp://--case for moving forward to win or lose after the left button is released
			greenLEDOff();
			redLEDOff();

			if(!(pattern & andmask) && (countLoop != 5))
			{
				andmask <<=1;
				countLoop++;
				state=playerPress;
			}
			else if(!(pattern & andmask) && (countLoop == 5))
				state = winningGreenLEDs;
			else
				state= losingRedLEDs;
			break;


		case winningGreenLEDs: //== case with a for loop to flash the green LED three times==================
			for(int i=0; i<3;i++)
			{
					greenLEDOn();
					for(int j=0;j<87654;j++); //LED flash delay
					greenLEDOff();
					for(int j=0; j<87654;j++);
			}
			state = playerPress;
			break;


		case losingRedLEDs: //== case with a for loop to flash the red LED three times===================
				for(int i=0; i<3;i++)
				{
						redLEDOn();
						for(int j=0;j<87654;j++); //LED flash delay
						redLEDOff();
						for(int j=0; j<87654;j++);
				}
				state = gameStart;//sends to start
				break;
			}
		}
	}

