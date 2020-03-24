//
// Created by 周典 on 2020/3/23.
//

#include "pc.h"
#include "main.h"
#include "cmsis_os.h"

osThreadId Task1Handle;
osThreadId Task2Handle;
osThreadId PCHandle;
uint8_t dig_font[] = {0xeb, 0x28, 0xb3, 0xba, 0x78, 0xda, 0xdb, 0xa8, 0xfb, 0xf8};

int i = 0;

void print4(int digit) {
    print(digit % 10, 4u);
    osDelay(5);
    digit /= 10;
    print(digit % 10, 3u);
    osDelay(5);
    digit /= 10;
    print(digit % 10, 2u);
    osDelay(5);
    digit /= 10;
    print(digit % 10, 1u);
    osDelay(5);
}

void print(uint8_t digit, uint8_t position) {
    HAL_GPIO_WritePin(pc6_GPIO_Port, pc6_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(pc8_GPIO_Port, pc8_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(pc9_GPIO_Port, pc9_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(pc12_GPIO_Port, pc12_Pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(pc1_GPIO_Port, pc1_Pin, dig_font[digit] & 0x1);
    HAL_GPIO_WritePin(pc2_GPIO_Port, pc2_Pin, dig_font[digit] & 0x2);
    HAL_GPIO_WritePin(pc3_GPIO_Port, pc3_Pin, dig_font[digit] & 0x4);
    HAL_GPIO_WritePin(pc4_GPIO_Port, pc4_Pin, dig_font[digit] & 0x8);
    HAL_GPIO_WritePin(pc5_GPIO_Port, pc5_Pin, dig_font[digit] & 0x10);
    if (position != 4)
        HAL_GPIO_WritePin(pc6_GPIO_Port, pc6_Pin, GPIO_PIN_SET);

    HAL_GPIO_WritePin(pc7_GPIO_Port, pc7_Pin, dig_font[digit] & 0x20);

    if (position != 3)
        HAL_GPIO_WritePin(pc8_GPIO_Port, pc8_Pin, GPIO_PIN_SET);
    if (position != 2)
        HAL_GPIO_WritePin(pc9_GPIO_Port, pc9_Pin, GPIO_PIN_SET);

    HAL_GPIO_WritePin(pc10_GPIO_Port, pc10_Pin, dig_font[digit] & 0x40);
    HAL_GPIO_WritePin(pc11_GPIO_Port, pc11_Pin, dig_font[digit] & 0x80);
    if (position != 1)
        HAL_GPIO_WritePin(pc12_GPIO_Port, pc12_Pin, GPIO_PIN_SET);
}


void countTimeTask(void *pvParameters) {
    const char *pcTaskName = "countTimeTask is running\r\n";
    volatile unsigned long ul;
    int start_flag = 0;
    for (;;) {
        if (HAL_GPIO_ReadPin(key0_GPIO_Port, key0_Pin)) {
            i++;
            HAL_GPIO_WritePin(led0_GPIO_Port, led0_Pin, GPIO_PIN_RESET);
            osDelay(500);
            HAL_GPIO_WritePin(led0_GPIO_Port, led0_Pin, GPIO_PIN_SET);
            osDelay(500);
        }
    }
}

void countTimeTask2(void *pvParameters) {
    const char *pcTaskName = "countTimeTask2 is running\r\n";
    volatile unsigned long ul;
    for (;;) {
        HAL_GPIO_WritePin(led1_GPIO_Port, led1_Pin, GPIO_PIN_RESET);
        osDelay(1000);
//        print4(4321);
        HAL_GPIO_WritePin(led1_GPIO_Port, led1_Pin, GPIO_PIN_SET);
        osDelay(1000);
    }
}

void printPCTask(void *pvParameters) {
    const char *pcTaskName = "printPCTask is running\r\n";
    volatile unsigned long ul;
    for (;;) {
        print4(i);
    }
}