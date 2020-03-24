//
// Created by 周典 on 2020/3/23.
//

#ifndef AUTOJOYSTICK_PC_H
#define AUTOJOYSTICK_PC_H

#endif //AUTOJOYSTICK_PC_H

#include <stdint.h>

#define START_SIGNAL (0x01)

void print4(int digit);

void print(uint8_t digit, uint8_t position);

void countTimeTask(void *pvParameters);

void countTimeTask2(void *pvParameters);

void printPCTask(void *pvParameters);
