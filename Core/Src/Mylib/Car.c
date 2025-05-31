#include "Car.h"
#include "Motor.h"

// Khai b�o extern d? s? d?ng c�c bi?n motor d� kh?i t?o t? noi kh�c (thu?ng l� main.c)
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
            motor_control_(&motor_left, MOTOR_CW, 80);     // 80 l� t?c d? PWM, c� th? ch?nh
            motor_control_(&motor_right, MOTOR_CW, 80);
            break;

        case CAR_BACKWARD:
            motor_control_(&motor_left, MOTOR_CCW, 80);
            motor_control_(&motor_right, MOTOR_CCW, 80);
            break;

        case CAR_LEFT:
            motor_control_(&motor_left, MOTOR_STOP, 0);     // d?ng b�n tr�i
            motor_control_(&motor_right, MOTOR_CW, 80);     // quay b�n ph?i
            break;

        case CAR_RIGHT:
            motor_control_(&motor_left, MOTOR_CW, 80);      // quay b�n tr�i
            motor_control_(&motor_right, MOTOR_STOP, 0);    // d?ng b�n ph?i
            break;
    }
}
