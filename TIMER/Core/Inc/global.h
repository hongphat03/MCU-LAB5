/*
 * global.h
 *
 *  Created on: Oct 9, 2022
 *      Author: Hong Phat
 */
#include "software_timer.h"
#include "stdio.h"
#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#define MAX_BUFFER_SIZE  30
#define NORMAL 0
#define SEND_ADC 1
int state;
int state2;
int send;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer ;
uint8_t buffer_flag ;
uint32_t ADC_value;
#endif /* INC_GLOBAL_H_ */
