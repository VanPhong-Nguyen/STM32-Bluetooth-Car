#ifndef CAR_H
#define CAR_H

#include "Motor.h"

// C�c tr?ng th�i di?u khi?n xe
typedef enum
{
    CAR_STOP,
    CAR_FORWARD,
    CAR_BACKWARD,
    CAR_LEFT,
    CAR_RIGHT
} CarState;

// H�m di?u khi?n xe
void car_control(CarState state);

#endif
