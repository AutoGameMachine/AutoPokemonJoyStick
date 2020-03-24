//
// Created by 周典 on 2020/3/24.
//

#ifndef AUTOJOYSTICK_PROGRAM_H
#define AUTOJOYSTICK_PROGRAM_H

#endif //AUTOJOYSTICK_PROGRAM_H

#include "usb.h"



static const command program[] = {
        {LEFT, 60},
};

//同步
static const command Sync[] = {
        {LCLICK,     2},
        {PAUSE,      10},
        {SCRIPT_END, 0},
};

void USBTask(void *pvParameters);

void USBTickTask(void *pvParameters);