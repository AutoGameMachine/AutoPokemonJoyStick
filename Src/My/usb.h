//
// Created by 周典 on 2020/3/23.
//

#ifndef AUTOJOYSTICK_USB_H
#define AUTOJOYSTICK_USB_H

#endif //AUTOJOYSTICK_USB_H

#include "stm32f1xx_hal.h"

#define HAT_TOP 0x00
#define HAT_TOP_RIGHT 0x01
#define HAT_RIGHT 0x02
#define HAT_BOTTOM_RIGHT 0x03
#define HAT_BOTTOM 0x04
#define HAT_BOTTOM_LEFT 0x05
#define HAT_LEFT 0x06
#define HAT_TOP_LEFT 0x07
#define HAT_CENTER 0x08

#define STICK_MIN 0
#define STICK_CENTER 128
#define STICK_MAX 255
typedef struct {
    uint16_t Button; // 16 buttons; see JoystickButtons_t for bit mapping
    uint8_t HAT;     // HAT switch; one nibble w/ unused nibble
    uint8_t LX;      // Left  Stick X
    uint8_t LY;      // Left  Stick Y
    uint8_t RX;      // Right Stick X
    uint8_t RY;      // Right Stick Y
    uint8_t VendorSpec;
} USB_JoystickReport_Input_t;

typedef struct {
    uint16_t Button; // 16 buttons; see JoystickButtons_t for bit mapping
    uint8_t HAT;     // HAT switch; one nibble w/ unused nibble
    uint8_t LX;      // Left  Stick X
    uint8_t LY;      // Left  Stick Y
    uint8_t RX;      // Right Stick X
    uint8_t RY;      // Right Stick Y
} USB_JoystickReport_Output_t;

typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    UPLEFT, // UP + LEFT
    UPRIGHT,
    DOWNLEFT,
    DOWNRIGHT,
    HOLD_UP,   // Hold L Stick UP
    HOLD_DOWN, // using duration = 0
    HOLD_LEFT,
    HOLD_RIGHT,
    HOLD_CLEAR, // clear Hold L Stick = center
    HOLD_CAM_L, // Hold R Stick Left
    HOLD_CAM_R, // Hold R Stick Right
    HOLD_CAM_C, // clear Hold R Stick = center
    X,
    Y,
    A,
    B,
    L,
    R,
    ZL,
    ZR,
    PLUS,
    MINUS,
    HOME,
    LCLICK,
    RCLICK,
    SCRIPT_END,
    PAUSE
} Buttons_t;

typedef struct {
    Buttons_t button;
    uint16_t duration;
} command;

typedef enum {
    SWITCH_Y = 0x01,
    SWITCH_B = 0x02,
    SWITCH_A = 0x04,
    SWITCH_X = 0x08,
    SWITCH_L = 0x10,
    SWITCH_R = 0x20,
    SWITCH_ZL = 0x40,
    SWITCH_ZR = 0x80,
    SWITCH_MINUS = 0x100,
    SWITCH_PLUS = 0x200,
    SWITCH_LCLICK = 0x400,
    SWITCH_RCLICK = 0x800,
    SWITCH_HOME = 0x1000,
    SWITCH_CAPTURE = 0x2000,
} JoystickButtons_t;

void GetNextReport(USB_JoystickReport_Input_t *const ReportData, Buttons_t button);

void HID_Task(Buttons_t button);

void RunStep(Buttons_t button, uint16_t duration);

void RunScript(const command script[], int times);

void send_callback(void);

