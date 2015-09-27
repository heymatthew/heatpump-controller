// based on
// https://github.com/tiegz/Spark-Core-IRremote
// https://github.com/r45635/HVAC-IR-Control

#include "IRremote.h"

#define NUM_0 48
#define NUM_1 49
#define NUM_2 50
#define ENTER 10

IRsend irsend(D3);
int led = D7;
int msDelay = 5000;

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  Serial.println("Ready and waiting...");
}

int mode;
void loop() {
    if (Serial.available() > 0) {
        mode = Serial.read();

        if (mode == NUM_2) {
            RGB.control(true);
            RGB.color(255,255,0);
            delay(1000);
            Serial.println("Hello world!");
            delay(1000);
            RGB.color(0,0,0);
        } else if (mode == NUM_1) {
            Serial.println("AC: ON");
            digitalWrite(led, HIGH);
            irsend.sendHvacMitsubishi(HVAC_HOT, 20, FAN_SPEED_AUTO, VANNE_AUTO_MOVE, HVAC_ON);
        } else if (mode == NUM_0) {
            Serial.println("AC: OFF");
            digitalWrite(led, LOW);
            irsend.sendHvacMitsubishi(HVAC_HOT,  20,  FAN_SPEED_AUTO, VANNE_AUTO_MOVE, HVAC_OFF);
        } else if (mode == ENTER) {
          // do nothing
        } else {
            Serial.print("Unrecognised mode: ");
            Serial.println(mode, DEC);
        }
    }
}
