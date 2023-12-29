/* * Car_config.h
 *
 *  Created on: Dec 2, 2023
 *      Author: Aziz
 */


#ifndef CAR_CONFIG_H_
#define CAR_CONFIG_H



#define STOP_SPEED						0
#define	MAX_SPEED						100

#define	MAX_PERIOD						20000UL

#define	INCREMENT_DECREMENT				1000


#define LED_FRONT_PORT					DIO_u8PORTB
#define LED_FRONT_PIN					DIO_u8PIN0

#define LED_BACK_PORT					DIO_u8PORTB
#define LED_BACK_PIN					DIO_u8PIN1


#define LED_RIGHT_PORT					DIO_u8PORTB
#define LED_RIGHT_PIN					DIO_u8PIN2

#define LED_LEFT_PORT					DIO_u8PORTB
#define LED_LEFT_PIN					DIO_u8PIN3


#define LED_CONTROL_PORT				DIO_u8PORTB

#endif
