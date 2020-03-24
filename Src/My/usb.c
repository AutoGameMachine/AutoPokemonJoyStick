//
// Created by 周典 on 2020/3/23.
//
#include <cmsis_os.h>
#include "usb.h"
#include "usbd_conf.h"
#include "usbd_hid.h"
#include "usb_device.h"
#include "cmsis_os.h"

extern USBD_HandleTypeDef hUsbDeviceFS;

char STOP = 1;                  //启停状态
char PlusButton = 0;            //加号键
char MinusButton = 0;           //减号键
char State = 1;                 //切换状态
char ScriptNum = 1;             //脚本编号
char CycleNum = 11;             //周期数
char CycleStr[3] = {49, 49, 0}; //周期数字符串形式
char BoxNum = 1;                //箱数
char BoxStr[3] = {48, 49, 0};   //箱数字符串形式
char ProgressNum = 0;
char ProgressStr[3] = {48, 48, 0};
unsigned int FrameNum = 30;                 //帧数
char FrameStr[6] = {48, 48, 48, 51, 48, 0}; //帧数字符串形式
char initialized = 0;                       //初始化状态
char Stopping = 0;                          //停止信号 用于逐层返回主循环并重新选择脚本

USB_JoystickReport_Input_t last_report;
int report_count = 0;
int hold_LX = STICK_CENTER;
int hold_LY = STICK_CENTER;
int hold_RX = STICK_CENTER;
uint8_t buffer[8];

void HID_Task(Buttons_t button) {
    USB_JoystickReport_Input_t JoystickInputData;
    GetNextReport(&JoystickInputData, button);
}

void RunStep(Buttons_t button, uint16_t duration) {
    for (; duration > 0; duration--) {
        HID_Task(button);
    }
}

void RunScript(const command script[], int times) {
    if (Stopping)
        return;
    for (; times > 0; times--) {
        for (int i = 0;; i++) {
            if (script[i].button == SCRIPT_END) {
                break;
            }
            RunStep(script[i].button, script[i].duration);
            if (Stopping)
                break;
        }
        if (Stopping)
            break;
    }
}


void GetNextReport(USB_JoystickReport_Input_t *const ReportData, Buttons_t button) {
    //按键释放
    memset(ReportData, 0, sizeof(USB_JoystickReport_Input_t));
    ReportData->LX = STICK_CENTER;
    ReportData->LY = STICK_CENTER;
    ReportData->RX = STICK_CENTER;
    ReportData->RY = STICK_CENTER;
    ReportData->HAT = HAT_CENTER;


    switch (button) {
        case UP:
            ReportData->LY = STICK_MIN;
            break;

        case LEFT:
            ReportData->LX = STICK_MIN;
            break;

        case DOWN:
            ReportData->LY = STICK_MAX;
            break;

        case RIGHT:
            ReportData->LX = STICK_MAX;
            break;

        case UPLEFT:
            ReportData->LY = STICK_MIN;
            ReportData->LX = STICK_MIN;
            break;

        case UPRIGHT:
            ReportData->LY = STICK_MIN;
            ReportData->LX = STICK_MAX;
            break;

        case DOWNLEFT:
            ReportData->LY = STICK_MAX;
            ReportData->LX = STICK_MIN;
            break;

        case DOWNRIGHT:
            ReportData->LY = STICK_MAX;
            ReportData->LX = STICK_MAX;
            break;

        case HOLD_UP:
            hold_LY = STICK_MIN;
            break;

        case HOLD_LEFT:
            hold_LX = STICK_MIN;
            break;

        case HOLD_DOWN:
            hold_LY = STICK_MAX;
            break;

        case HOLD_RIGHT:
            hold_LX = STICK_MAX;
            break;

        case HOLD_CLEAR:
            hold_LX = STICK_CENTER;
            hold_LY = STICK_CENTER;
            break;

        case HOLD_CAM_L:
            hold_RX = STICK_MIN;
            break;

        case HOLD_CAM_R:
            hold_RX = STICK_MAX;
            break;

        case HOLD_CAM_C:
            hold_RX = STICK_CENTER;
            break;

        case A:
            ReportData->Button |= SWITCH_A;
            break;

        case B:
            ReportData->Button |= SWITCH_B;
            break;

        case X:
            ReportData->Button |= SWITCH_X;
            break;

        case Y:
            ReportData->Button |= SWITCH_Y;
            break;

        case L:
            ReportData->Button |= SWITCH_L;
            break;

        case R:
            ReportData->Button |= SWITCH_R;
            break;

        case PLUS:
            ReportData->Button |= SWITCH_PLUS;
            break;

        case HOME:
            ReportData->Button |= SWITCH_HOME;
            break;

        default:
            break;
    }

    USBD_HID_SendReport(&hUsbDeviceFS, ReportData, sizeof(USB_JoystickReport_Input_t));
    memcpy(&last_report, ReportData, sizeof(USB_JoystickReport_Input_t));
}
