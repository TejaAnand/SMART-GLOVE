# 🧤 Smart Glove - Arduino Based Gesture Recognition System

The **Smart Glove** is an innovative wearable device designed to recognize hand gestures and convert them into meaningful messages. Using a combination of flex sensors and analog readings, this glove can assist individuals with speech disabilities to communicate effectively. 

It can detect specific gestures and output predefined messages like:
- "A warm welcome to you all"
- "Good morning one and all"
- "I need medicine"
- "I want some food"
... and more!

## 🔧 Hardware Requirements

- Arduino Uno (or compatible board)
- Flex sensors (4 units, connected to A0-A3)
- Thumb pressure or analog sensor (A2)
- Palm pressure/analog sensor (A4 and A5 used as `x`, `y` axes)
- Jumper wires
- Breadboard
- USB cable for Arduino

## 🖥️ Software Requirements

- [Arduino IDE](https://www.arduino.cc/en/software)
- Serial Monitor enabled (baud rate: 9600)

## 📁 Project Structure

```bash
Smart-Glove/
├── main.ino        # Main Arduino sketch
├── README.md             # Project overview and documentation
└── requirements.txt      # Development dependencies


https://drive.google.com/drive/folders/1SRliZxgAP08aJOCZN3NXApLTGDXerMNB
