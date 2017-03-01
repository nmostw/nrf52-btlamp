/*
 * system_config.h
 *
 *  Created on: Mar 1, 2017
 *      Author: petera
 */

#ifndef SYSTEM_CONFIG_H_
#define SYSTEM_CONFIG_H_

#include "system.h"

#define PIN_UART_RX_NUMBER    UART_PIN_DISCONNECTED//8
#define PIN_UART_TX_NUMBER    6
#define PIN_MOSI_NUMBER       8
#define DEVICE_NAME                     "Pelles_BT_lampa"                               /**< Name of device. Will be included in the advertising data. */
#define APP_TIMER_PRESCALER             0                                           /**< Value of the RTC1 PRESCALER register. */
#define APP_TIMER_OP_QUEUE_SIZE         8                                           /**< Size of timer operation queues. */

#endif /* SYSTEM_CONFIG_H_ */