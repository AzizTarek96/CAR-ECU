

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"


#include "../MCAL/PORT/PORT_interface.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/TIMER/TIMER_interface.h"
#include "../MCAL/GIE/GIE_interface.h"

#include "../HAL/CAR/CAR_interface.h"
#include "../HAL/CLCD/CLCD_interface.h"
#include "../HAL/KPD/KPD_interface.h"

volatile u8 ErrorFlag = 0;
volatile u8 Led_State = 1;
volatile u8 LedRightFlag = 0;
volatile u8 LedLeftFlag = 0;

void Toggling_voidTraffic(void);
void Error_voidCommand(void);

void main (void)
{
	volatile u8 Local_u8Id = 0 , Local_u8Command = 0 , Local_u8Data = 0;
	volatile u8 Local_u8PressedKey = NO_PRESSED_KEY , i = 0 ,Local_u8State = 0, Display = 1;
	volatile u8 RunFlag= 0, LedFrontFlag = 0, LedBackFlag = 0, CloseTrafficFlag = 0;

	PORT_voidInit();
	CLCD_voidInit();
	GIE_voidEnableGlobal();

	TIMER0_u8OverflowSetCallBack(&Toggling_voidTraffic);
	TIMER2_u8OverflowSetCallBack(&Error_voidCommand);
	while(1)
	{
		if(ErrorFlag == 0)
		{
			Local_u8PressedKey = KPD_u8GetPressedKey();
			if(Local_u8State == 0 && Local_u8PressedKey != 'A')
			{
				if(Display == 1)
				{
					CLCD_voidWriteString("Enter Id");
					Display = 0;
				}
				if(Local_u8PressedKey != NO_PRESSED_KEY)
				{
					Local_u8Id =(Local_u8Id*10)+Local_u8PressedKey;
				}
			}
			else if(Local_u8State == 1 && Local_u8PressedKey != 'A')
			{
				if(Display == 1)
				{
					CLCD_voidWriteString("Enter Command");
					Display = 0;
				}
				if(Local_u8PressedKey != NO_PRESSED_KEY)
				{
					Local_u8Command =(Local_u8Command*10)+Local_u8PressedKey;
				}
			}

			if(Local_u8PressedKey != NO_PRESSED_KEY && Local_u8PressedKey != 'A' && Local_u8Data <= 100)
			{
				CLCD_voidGoToXY(i,1);
				ClCD_voidWriteInteger(Local_u8PressedKey);
				if(Local_u8State == 2)
				{
					Local_u8Data = (Local_u8Data * 10) + Local_u8PressedKey;
				}
				i++;
			}
			else if(Local_u8PressedKey == 'A')
			{
				Local_u8State++;
				if(Local_u8State > 2)
				{
					RunFlag = 1;
					Local_u8State = 0;
				}
				CLCD_voidSendCommand(CLR_DISPLAY);
				i = 0;
				Display = 1;
				Local_u8PressedKey = NO_PRESSED_KEY;
			}
			if((Local_u8Command == ADJUST_SPEED || Local_u8Command == FRONT_LED || Local_u8Command == BACK_LED) && Local_u8State == 2)
			{
				if(Display == 1 && RunFlag !=1)
				{
					CLCD_voidWriteString("Enter Data");
					Local_u8Data = 0;
					Display = 0;
				}
			}
			else if(Local_u8State ==2)
			{
				RunFlag = 1;
				Local_u8State = 0;
			}
			if(RunFlag == 1)
			{
				RunFlag = 0;
				switch(Local_u8Id)
				{

				case Motor :
					switch(Local_u8Command)
					{
					case	INCREMENT_SPEED   : Car_voidMotorIncrementSpeed();break;
					case	DECREMENT_SPEED   : Car_voidMotorDecrementSpeed();break;
					case	ADJUST_SPEED	  : Car_voidMotorAdjustSpeed(Local_u8Data);break;
					case	MOTOR_STOP		  : Car_voidMotorStop();break;
					case	NO_PRESSED_KEY	  : Local_u8State = 1;break;
					default  :  				ErrorFlag = 1;
												CLCD_voidSendCommand(CLR_DISPLAY);
												CLCD_voidWriteString("Error Command");
												TIMER2_voidInt(); break;
					}
					break;

					case Leds :
						switch(Local_u8Command)
						{
						case	RIGHT_TRAFFIC  	  :	LedRightFlag = 1; LedLeftFlag = 0; TIMER0_voidInt();break;
						case	LEFT_TRAFFIC	  : LedRightFlag = 0; LedLeftFlag = 1; TIMER0_voidInt();break;
						case	FRONT_LED		  : LedFrontFlag = 1; break;
						case	BACK_LED		  : LedBackFlag = 1; break;
						case  	CLOSE_TRAFFIC	  : LedRightFlag = 0; LedLeftFlag = 0; CloseTrafficFlag = 1; break;
						case	NO_PRESSED_KEY	  : Local_u8State = 1;break;
						default		: 				ErrorFlag = 1;
													CLCD_voidSendCommand(CLR_DISPLAY);
													CLCD_voidWriteString("Error Command");
													TIMER2_voidInt();break;
						}
					break;
					case	NO_PRESSED_KEY	  : Local_u8State = 0; break;

					default	:					ErrorFlag = 1;
												CLCD_voidSendCommand(CLR_DISPLAY);
												CLCD_voidWriteString("Error ID");
												TIMER2_voidInt(); break;
				}
				Local_u8Id = 0;
				Local_u8Command = 0;
			}
		}

		if(LedRightFlag == 1)
		{
			LED_voidCloseTraffic();
			LED_voidRIGHT(Led_State);
		}
		else if(LedLeftFlag == 1)
		{
			LED_voidCloseTraffic();
			LED_voidLEFT(Led_State);
		}
		else if(CloseTrafficFlag ==1)
		{
			LED_voidCloseTraffic();
			CloseTrafficFlag = 0;
			LedRightFlag = 0;
			LedLeftFlag = 0;
			TIMER0_voidStopTimer0();
		}
		if(LedFrontFlag == 1)
		{
			LED_voidFRONT(Local_u8Data);
			LedFrontFlag = 0;
		}
		if(LedBackFlag == 1)
		{
			LED_voidBACK(Local_u8Data);
			LedBackFlag = 0 ;
		}

	}
}
void Toggling_voidTraffic(void)
{
	TOGGLE_BIT(Led_State,0);
}
void Error_voidCommand(void)
{
	ErrorFlag = 0;
	CLCD_voidSendCommand(CLR_DISPLAY);
	TIMER2_voidStopTimer2();
}
