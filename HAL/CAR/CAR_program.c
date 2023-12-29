/*
 *  * CAR_program.c
 *
 *  Created on: Dec 2, 2023
 *      Author: Aziz
 */

#include "../../LIB/STD_TYPES.h"

#include "CAR_interface.h"
#include "CAR_config.h"
#include "CAR_private.h"

#include "../../MCAL/TIMER/TIMER_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "util/delay.h"

void Car_voidMotorAdjustSpeed(u8 Copy_u8Speed)
{
	u16 Local_u16SpeedMapping = ((f32)Copy_u8Speed/MAX_SPEED)*(MAX_PERIOD);

	TIMER1_voidInt();

	if (Copy_u8Speed == STOP_SPEED)
	{
		TIMER1_voidStop();
	}
	else if (Copy_u8Speed == MAX_SPEED)
	{
		TIMER1_voidSetChannelACompValue(MAX_PERIOD);
	}
	else
	{
		TIMER1_voidSetChannelACompValue(Local_u16SpeedMapping);
	}
}
void Car_voidMotorIncrementSpeed(void)
{
	u16 Speed = TIMER1_u16GetCompValue()+INCREMENT_DECREMENT;
	TIMER1_voidInt();
	if(Speed >= MAX_PERIOD)
	{
		Speed = MAX_PERIOD;
		TIMER1_voidSetChannelACompValue(MAX_PERIOD);
		CLCD_voidSendCommand(1);
		CLCD_voidWriteString("FFF");
		_delay_ms(1000);
	}
	else
	{
		TIMER1_voidSetChannelACompValue(Speed);
	}
}
void Car_voidMotorDecrementSpeed(void)
{
	s16 Speed = TIMER1_u16GetCompValue()-INCREMENT_DECREMENT;

	if(Speed<STOP_SPEED)
	{
		Speed = STOP_SPEED;
		TIMER1_voidStop();
	}
	TIMER1_voidSetChannelACompValue(Speed);
}
void Car_voidMotorStop(void)
{
	TIMER1_voidStop();
}
void LED_voidInit()
{
	DIO_u8SetPinDirection(LED_FRONT_PORT,LED_FRONT_PIN,DIO_u8PIN_OUTPUT);

	DIO_u8SetPinDirection(LED_BACK_PORT,LED_BACK_PIN,DIO_u8PIN_OUTPUT);

	DIO_u8SetPinDirection(LED_RIGHT_PORT,LED_RIGHT_PIN,DIO_u8PIN_OUTPUT);

	DIO_u8SetPinDirection(LED_LEFT_PORT,LED_LEFT_PIN,DIO_u8PIN_OUTPUT);
}

void LED_voidRIGHT(u8 Copy_u8State)
{
	if(Copy_u8State == LED_ON)
	{
		DIO_u8SetPinValue(LED_RIGHT_PORT,LED_RIGHT_PIN,DIO_u8PIN_HIGH);
	}
	else if(Copy_u8State == LED_OFF)
	{
		DIO_u8SetPinValue(LED_RIGHT_PORT,LED_RIGHT_PIN,DIO_u8PIN_LOW);
	}
}
void LED_voidLEFT(u8 Copy_u8State)
{
	if(Copy_u8State == LED_ON)
	{
		DIO_u8SetPinValue(LED_LEFT_PORT,LED_LEFT_PIN,DIO_u8PIN_HIGH);
	}
	else if(Copy_u8State == LED_OFF)
	{
		DIO_u8SetPinValue(LED_LEFT_PORT,LED_LEFT_PIN,DIO_u8PIN_LOW);
	}
}
void LED_voidCloseTraffic(void)
{
	DIO_u8SetPinValue(LED_RIGHT_PORT,LED_RIGHT_PIN,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(LED_LEFT_PORT,LED_LEFT_PIN,DIO_u8PIN_LOW);
}
void LED_voidFRONT(u8 Copy_u8State)
{
	if(Copy_u8State == LED_ON)
	{
		DIO_u8SetPinValue(LED_LEFT_PORT,LED_FRONT_PIN,DIO_u8PIN_HIGH);
	}
	else
	{
		DIO_u8SetPinValue(LED_FRONT_PORT,LED_FRONT_PIN,DIO_u8PIN_LOW);
	}
}
void LED_voidBACK(u8 Copy_u8State)
{
	if(Copy_u8State == LED_ON)
	{
		DIO_u8SetPinValue(LED_BACK_PORT,LED_BACK_PIN,DIO_u8PIN_HIGH);
	}
	else
	{
		DIO_u8SetPinValue(LED_BACK_PORT,LED_BACK_PIN,DIO_u8PIN_LOW);
	}
}

void LED_voidControl(u8 Copy_u8PIN,u8 Copy_u8State)
{
	DIO_u8SetPinDirection(LED_CONTROL_PORT,Copy_u8PIN,DIO_u8PIN_OUTPUT);

	if(Copy_u8State == LED_ON)
	{
		DIO_u8SetPinValue(LED_CONTROL_PORT,Copy_u8PIN,DIO_u8PIN_HIGH);
	}
	else
	{
		DIO_u8SetPinValue(LED_CONTROL_PORT,Copy_u8PIN,DIO_u8PIN_LOW);
	}
}
