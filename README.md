# IR Remote Receiver

Jaesung Yoo
01/22/2024

Receives IR signal from IR remote control and switches electrical devices on and off using arduino uno and relay module  

## Devices Used
Arduino Uno

Breadboard

Relay Module

VS1838 IR Receiver

4 in 1 MAX7219 8x8 Dot Matrix Display

IR Remote Control

## Libraries Used
IRremote

MD_MAX72XX

MD_Parola

## Project Description
5V from Arduino Uno was used to provide power on all the devices

Arduino Uno receives signals from an IR remote using VS1838 IR receiver

IR receiver is connected to arduino to retrieve data from the remote

IR remote sends out signals in NEC infrared transmission protocol which is translated using Arduino IRremote library

Arduino then controls LED matrix and relay module

Relay module is connected to arduino to switch electrical devices on and off when buttons are pressed from IR remote

LED dot matrix is connected to arduino to display different messages when corresponding buttons are pressed from IR remote

### Picture & Diagram
<img width="1000" alt="image" src="https://github.com/yoojsung/IR_Remote_Receiver/assets/49657149/2cd4dc8c-1179-495b-8b26-97f30a344134">

<img width="300" alt="image" src="https://github.com/yoojsung/IR_Remote_Receiver/assets/49657149/401ba973-849b-4c7c-a358-853c1e546010">

Up and down buttons on the left side of the remote were used to turn the relay module on and off

<img width="1000" alt="image" src="https://github.com/yoojsung/IR_Remote_Receiver/assets/49657149/4a8ce0f2-c4f4-4439-9fe8-b8f85d83f6aa">

