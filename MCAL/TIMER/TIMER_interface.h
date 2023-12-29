/*****************************************************************/
/*****************************************************************/
/***************		Author: Aziz Tarek		******************/
/***************		Layer: MCAL				******************/
/***************		SWC: Timer				******************/
/***************		Date: 2-11-2023			******************/
/***************		Version: 1.00			******************/
/*****************************************************************/
/*****************************************************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_



#define FALLING_EDGE		0
#define RISING_EDGE			1


#define SleepTime_16_3ms            0
#define SleepTime_32_5ms            1
#define SleepTime_65ms	            2
#define SleepTime_0_13s	            3
#define SleepTime_0_26s	            4
#define SleepTime_0_52s	            5
#define SleepTime_1s	            6
#define SleepTime_2_1s	            7


void TIMER0_voidInt(void);
u8   TIMER0_u8OverflowSetCallBack(void (*Copy_pvCallBackFunc)(void));
u8   TIMER0_u8CompMatchSetCallBack(void (*Copy_pvCallBackFunc)(void));
void TIMER0_voidSetPreload(u8 Copy_u8Preload);
void TIMER0_voidStopTimer0(void);

void TIMER2_voidInt(void);
u8   TIMER2_u8OverflowSetCallBack(void (*Copy_pvCallBackFunc)(void));
u8 	 TIMER2_u8CompMatchSetCallBack(void (*Copy_pvCallBackFunc)(void));
void TIMER2_voidSetPreload(u8 Copy_u8Preload);
void TIMER2_voidStopTimer2(void);

void TIMER1_voidInt(void);
void TIMER1_voidStop(void);
void TIMER1_voidSetChannelACompValue(u16 Copy_u16Value);
u16  TIMER1_u16GetCompValue();
void TIMER1_voidSetPreloadValue(u16 Copy_u16Value);
u16  TIMER1_Readu16TimerValue(void);

void ICU_voidInit(void);
u8   ICU_u8SetCallBack(void(*Copy_pvCallBackFunc)(void));
u8   ICU_u8SetTrigger(u8 Copy_u8TriggerSource);
u16  ICU_u16ReadInputCapture(void);
void ICU_voidInterruptDisable(void);


void WDT_voidEnable(void);
void WDT_voidDisable(void);
u8   WDT_u8Sleep(u8 Copy_u8SleepTime);


#endif


