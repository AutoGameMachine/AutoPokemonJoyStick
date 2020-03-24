//
// Created by 周典 on 2020/3/24.
//

#include "key.h"
#include "main.h"

osThreadId KeyHandle;
extern osThreadId Task1Handle;

void KeyTask(void *pvParameters) {
    while (1) {
//        if (!HAL_GPIO_ReadPin(key0_GPIO_Port, key0_Pin)) {
//            osSignalSet(Task1Handle, START_SIGNAL);
//        }
    }

}
