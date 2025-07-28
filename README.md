# E-Formula Firmware

Firmware for the NTU Dnipro Polytechnic E-Formula competition car.

## Purpose

Controls a race car that autonomously follows a black line on the floor, using hardware designed for E-Formula competitions.

## Hardware Requirements

- **Microcontroller:** Arduino Nano
- **Motors:** 2 DC motors
- **Battery:** Suitable for the motors and Nano
- **Line Sensor:** One sensor for detecting surface darkness

## Features

- **PID Line Tracking:**  
  The car uses a PID controller to follow the black line.  
  PID coefficients can be changed in the code to adapt to different cars.
- **Operating Modes:**  
  - **Off:** The car does nothing, keeping previous calibration.
  - **Calibration:** Resets old values and calibrates the sensor.
  - **Active:** Follows the black line using the PID controller.

## Dependencies

- **PlatformIO** (for building and uploading firmware)
- **C++ (Arduino core)**
- No external libraries required beyond PlatformIO and standard Arduino core.

## Installation

1. **Clone the repository:**
    ```bash
    git clone https://github.com/TimCixo/E-Formula.git
    cd E-Formula
    ```
2. **Open the project in PlatformIO (VSCode recommended).**
3. **Connect your Arduino Nano and upload the firmware via PlatformIO.**

## Usage

- After uploading, select the operating mode:
  - **Off:** Keeps previous calibration, motors are off.
  - **Calibration:** Sets up the line sensor for your environment.
  - **Active:** Car follows the black line.
- **To change PID coefficients:**  
  Edit the relevant values in the code before uploading to optimize for your specific car.

## License

This project is licensed under the MIT License.

## Gallery

<div align="center">
  <img width="1280" height="720" alt="image" src="https://github.com/user-attachments/assets/9f05a6d8-5a13-45b0-a20d-4e625e9247ec" />
  <img width=48% alt="image" src="https://github.com/user-attachments/assets/b683e9be-3e71-437b-bd83-299839498df5"/>
  <img width=48% alt="image" src="https://github.com/user-attachments/assets/287152f8-afbf-48d6-be10-90db92e5bfbc"/>
  <img width="1080" height="580" alt="image" src="https://github.com/user-attachments/assets/f049a8e7-f610-4384-aac2-a7bba23ca5b2" />

</div>
