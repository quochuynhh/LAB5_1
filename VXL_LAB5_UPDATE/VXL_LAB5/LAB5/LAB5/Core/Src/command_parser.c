/*
 * command_parser.c
 *
 *
 *      Author: Quoc
 */

#include "command_parser.h"


void command_parser_fsm() {
	switch(status_parser) {
	case INIT_STR:
		if(temp == '!') {
			status_parser = WAIT_END;
			command_index = 0;
		}
		break;

	case WAIT_END:
		if(temp == '#') {
			status_parser = INIT_STR;//check ket thuc
			command[command_index] = '\0';
			command_flag = 1;
		}
		else {
			if (temp == '!') // truong hop gõ 2 lần !!
				command_index = 0;
			else {
//				command[command_index++] = temp;// chuan bi cho ki tu tiep theo
//				if (command_index == MAX_BUFFER_SIZE) command_index = 0;

				// Chỉ thêm vào nếu còn chỗ (trừ 1 cho ký tự '\0')
				    if (command_index < (MAX_BUFFER_SIZE - 1)) {
				        command[command_index++] = temp;
				    }
				    // else: Nếu đầy, thì bỏ qua ký tự, không làm gì cả
			}
		}
		break;
	default:
		break;
	}
}
