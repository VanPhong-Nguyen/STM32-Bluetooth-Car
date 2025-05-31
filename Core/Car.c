#include "Car.h"
#include "Motor.h"

// Khai báo extern d? s? d?ng các bi?n motor dã kh?i t?o t? noi khác (thu?ng là main.c)
extern Motor_Typedef motor_left;
extern Motor_Typedef motor_right;

void car_control(CarState state)
{
    switch(state)
    {
        case CAR_STOP:
            motor_control_(&motor_left, MOTOR_STOP, 0);
            motor_control_(&motor_right, MOTOR_STOP, 0);
            break;

        case CAR_FORWARD:
            motor_control_(&motor_left, MOTOR_CW, 80);     // 80 là t?c d? PWM, có th? ch?nh
            motor_control_(&motor_right, MOTOR_CW, 80);
            break;

        case CAR_BACKWARD:
            motor_control_(&motor_left, MOTOR_CCW, 80);
            motor_control_(&motor_right, MOTOR_CCW, 80);
            break;

        case CAR_LEFT:
            motor_control_(&motor_left, MOTOR_STOP, 0);     // d?ng bên trái
            motor_control_(&motor_right, MOTOR_CW, 80);     // quay bên ph?i
            break;

        case CAR_RIGHT:
            motor_control_(&motor_left, MOTOR_CW, 80);      // quay bên trái
            motor_control_(&motor_right, MOTOR_STOP, 0);    // d?ng bên ph?i
            break;
    }
}
