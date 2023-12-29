/* * CAR_interface.h
 *
 *  Created on: Dec 2, 2023
 *      Author: Aziz
 */


#ifndef	CAR_INTERFACE_H_
#define	CAR_INTERFACE_H_


#define 	Motor					1
#define		Leds					2
#define     INCREMENT_SPEED			1
#define     DECREMENT_SPEED			2
#define     ADJUST_SPEED	  		3
#define 	MOTOR_STOP				4
#define     RIGHT_TRAFFIC  			5
#define     LEFT_TRAFFIC			6
#define     FRONT_LED				7
#define     BACK_LED				8
#define		CLOSE_TRAFFIC			9

void Car_voidMotorInit(void);
void Car_voidMotorAdjustSpeed(u8 Copy_u8Speed);
void Car_voidMotorIncrementSpeed(void);
void Car_voidMotorDecrementSpeed(void);
void Car_voidMotorStop(void);

void LED_voidInit();

void LED_voidRIGHT(u8 Copy_u8State);

void LED_voidLEFT(u8 Copy_u8State);

void LED_voidCloseTraffic(void);

/*Choose between below states for this function :
 * 		1-LED_ON
 * 		2-LED_OFF
 */
void LED_voidFRONT(u8 Copy_u8State);

/*Choose between below states for this function :
 * 		1-LED_ON
 * 		2-LED_OFF
 */
void LED_voidBACK(u8 Copy_u8State);

/*Choose between below states for this function :
 * 		1-LED_ON
 * 		2-LED_OFF
 */
void LED_voidControl(u8 Copy_u8PIN,u8 Copy_u8State);


#endif
