#include <cmsis_os.h>
#include "program.h"
#include "main.h"

osThreadId USBHandle;
osThreadId USBTickHandle;

void USBTask(void *pvParameters) {
    const char *pcTaskName = "USBTask is running.\r\n";
    volatile unsigned long ul;
    int32_t signals;
    osEvent evt;
    int start = 0;

    while (1) {
        if (!HAL_GPIO_ReadPin(key1_GPIO_Port, key1_Pin)) {
            while (!HAL_GPIO_ReadPin(key1_GPIO_Port, key1_Pin)) { ; }
            start = 1;
        }

        if (start) {
            RunScript(Sync, 3);
            int pc = 0;
            while (!HAL_GPIO_ReadPin(key1_GPIO_Port, key1_Pin)) { ; }
            for (;;) {
                if (!HAL_GPIO_ReadPin(key1_GPIO_Port, key1_Pin)) {
                    while (!HAL_GPIO_ReadPin(key1_GPIO_Port, key1_Pin)) { ; }
                    break;
                }
                evt = osSignalWait(0x02, osWaitForever);
                pc++;
                if (pc < 60) {
                    HID_Task(LEFT);
                } else {
                    HID_Task(RIGHT);
                }
                if (pc > 120) {
                    pc = 0;
                }
            }
        }
        while (!HAL_GPIO_ReadPin(key1_GPIO_Port, key1_Pin)) { ; }
        start = 0;
    }
}

void USBTickTask(void *pvParameters) {
    const char *pvTaskName = "USBTickTask is running.\r\n";
    volatile unsigned long ul;
    while (1) {
        osDelay(24);
        osSignalSet(USBHandle, 0x02);
    }
}

