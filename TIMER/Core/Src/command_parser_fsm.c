/*
 * command_parser_fsm.c
 *
 *  Created on: Dec 14, 2022
 *      Author: Hong Phat
 */
#include "command_parser_fsm.h"
#include "uart_communiation_fsm.h"
void command_parser_fsm(){
	if(state == 0){
		switch(state2){
		case 0:
			send = 1;
			buffer_flag = 0;
			if(buffer[--index_buffer] == '!'){
				state2 = 1;

			}
			else{
				state2 = 0;
			}
			break;
		case 1:
			buffer_flag = 0;
			send = 1;
			if(buffer[--index_buffer] == 'R'){
				state2 = 2;
			}
			else{
				state2 = 0;
			}
			break;
		case 2:
			send = 1;
			buffer_flag = 0;
			if(buffer[--index_buffer] == 'S'){
				state2 = 3;
			}
			else{
				state2 = 0;
			}
			break;
		case 3:
			send = 1;
			buffer_flag = 0;
			buffer_flag = 0;
			if(buffer[--index_buffer] == 'T'){
				state2 = 4;
			}
			else{
				state2 = 0;
			}
			break;
		case 4:
			send = 1;
			if(buffer[--index_buffer] == '#'){
				state2 = 0;
				state = 1;
				setTimer(3000);
				setTimer2(200);
				HAL_UART_Transmit (&huart2 ,&buffer[index_buffer],1,50) ;
			}
			else{
				state2 = 0;
			}
			break;
		default:
			break;
		}

	}
	if(state==1){
		switch(state2){
		case 0:
			buffer_flag = 0;
			send = 1;
			if(buffer[--index_buffer] == '!'){
				state2 = 1;
			}
			else{
				state2 = 0;
			}
			break;
		case 1:
			buffer_flag = 0;
			send = 1;
			if(buffer[--index_buffer] == 'O'){
				state2 = 2;
			}
			else{
				state2 = 0;
			}
			break;
		case 2:
			send = 1;
			buffer_flag = 0;
			if(buffer[--index_buffer] == 'K'){
				state2 = 3;
			}
			else{
				state2 = 0;
			}
			break;
		case 3:
			send = 1;
			buffer_flag = 0;
			if(buffer[--index_buffer] == '#'){
				state2 = 0;
				state = 0;
			}
			else{
				state2 = 0;
			}
			break;
		case 4:
			send = 1;
			state = 0;
			state2 = 0;
			break;
		default:
			break;
		}
	}
}
