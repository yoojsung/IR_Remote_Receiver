// Author: Jaesung Yoo
// 1/22/2024
// IR Remote Receiver Project

#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include <IRremote.h>

// Using 4in1 MAX7219 8x8 Dot Matrix
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
// CS pin number for SPI
#define CS 3
// Relay DIN pin
#define RELAY_ENABLE 2
// VS1838 IR receiver signal out pin
#define REC_PIN 5

IRrecv irrecv(REC_PIN);
decode_results res;

MD_Parola ledDisplay = MD_Parola(HARDWARE_TYPE, CS, MAX_DEVICES);

void setup()
{
  // LED Matrix setup
  ledDisplay.begin();
  ledDisplay.setIntensity(0);
  ledDisplay.displayClear();
  ledDisplay.print("Welcome");

  // Serial setup for monitoring
  Serial.begin(9600);
  Serial.println("Ready for IR test");

  // Start the receiver
  irrecv.enableIRIn(); 

  // Relay Module setup
  pinMode(RELAY_ENABLE, OUTPUT);
  digitalWrite(RELAY_ENABLE, LOW);
}

//Infinite loop
void loop() {
  if (irrecv.decode(&res)) {
    Serial.println(res.value, HEX);
    dump(&res);
    irrecv.resume();
  }
}

void dump(decode_results *res) {
  if (res->decode_type == UNKNOWN)
    Serial.println("Error: unknown encoding");

  else if (res->decode_type == NEC) {
    ledDisplay.displayClear();
    switch(res->value) {
    case 0x17B08F7:
        ledDisplay.print("DOWN");
        digitalWrite(RELAY_ENABLE, LOW);
        Serial.println("RELAY OFF");
        break;
    case 0x17B10EF:
        ledDisplay.print("UP");
        digitalWrite(RELAY_ENABLE, HIGH);
        Serial.println("RELAY ON");
        break;
    case 0x17B00FF:
        ledDisplay.print("POWER");
        Serial.println("Power button pressed");
        break;
    case 0x17B906F:
        ledDisplay.print("WIND");
        Serial.println("Wind button pressed");
        break;
    case 0x17B48B7:
        ledDisplay.print("ONE");
        Serial.println("One button pressed");
        break;
    case 0x17B708F:
        ledDisplay.print("TWO");
        Serial.println("Two button pressed");
        break;
    case 0x17B50AF:
        ledDisplay.print("FOUR");
        Serial.println("Four button pressed");
        break;
    case 0x17BA857:
        ledDisplay.print("LR");
        Serial.println("Left & right button pressed");
        break;
    case 0x17B6897:
        ledDisplay.print("UD");
        Serial.println("Up & down button pressed");
        break;
    default:
        break;
    }
  }
  
  int len = res->rawlen;

  // Delay to process next signal
  delay(100);
}