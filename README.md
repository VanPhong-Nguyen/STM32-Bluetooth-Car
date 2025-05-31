# STM32 Bluetooth Car – HC-05 + PWM + UART

## ⚙System Overview

- **MCU**: STM32F103C8T6 (Blue Pill)
- **Communication**: HC-05 Bluetooth module (UART via USART2 – PA2, PA3)
- **Control App**: Android app (e.g. Bluetooth RC Controller or Serial Bluetooth Terminal)
- **Motor Driver**: L298N Dual H-Bridge
- **Motor Control**: PWM using TIM1 Channels 1 & 2
- **Power**: 2x18650 or 7.4V battery pack

![System Diagram](images/system-diagram.png)

---

## Components

### 1. Motor Control
- `Motor.c / Motor.h` – Low-level driver to control direction and speed of each motor via GPIO + PWM
- Uses TIM1 CH1 & CH2 for left and right wheels

### 2. Car Logic
- `Car.c / Car.h` – High-level logic for car movement
- Supports `FORWARD`, `BACKWARD`, `LEFT`, `RIGHT`, `STOP`

### 3. UART Communication
- Configured with **USART2** (PA2-TX, PA3-RX)
- Baudrate: `9600`
- Received characters `'F'`, `'B'`, `'L'`, `'R'`, `'S'` mapped to actions

### 4. Bluetooth App (Mobile)
- Works with Serial Bluetooth Terminal or Bluetooth RC Controller
- Send characters:
  - `F` → Move Forward
  - `B` → Move Backward
  - `L` → Turn Left
  - `R` → Turn Right
  - `S` → Stop

---

## How to Build & Upload

1. Open the project in **STM32CubeIDE** or **Keil uVision**
2. Connect ST-Link or USB-to-Serial to flash firmware
3. Pair phone with HC-05 (default PIN: `1234` or `0000`)
4. Open app and send characters
