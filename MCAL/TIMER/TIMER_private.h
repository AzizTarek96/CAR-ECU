/*****************************************************************/
/*****************************************************************/
/***************		Author: Aziz Tarek		******************/
/***************		Layer: MCAL				******************/
/***************		SWC: Timer				******************/
/***************		Date: 2-11-2023			******************/
/***************		Version: 1.00			******************/
/*****************************************************************/
/*****************************************************************/

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_


#define PRESCALER_1					1
#define PRESCALER_8 				2
#define PRESCALER_64 				3
#define PRESCALER_256 				4
#define PRESCALER_1024 				5
#define PRESCALER_RISING_EDGE 		6
#define PRESCALER_FALLING_EDGE		7



#define TIMER0_PRESCALER_MASK  		0b11111000

#define TIMER2_PRESCALER_MASK  		0b11111000


#define WDT_MASK_DISABLE			0b00011000


#define WDT_PRESCALER_MASK			0b11111000






#endif


