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

int run(String command) {
  int temperature = command.toInt();
  bool turnOn = (16 < temperature && temperature < 30);

  if (turnOn) {
    digitalWrite(led, HIGH);
    irsend.sendHvacMitsubishi(HVAC_HOT, temperature, FAN_SPEED_AUTO, VANNE_AUTO_MOVE, HVAC_ON);
  }
  else {
    digitalWrite(led, LOW);
    irsend.sendHvacMitsubishi(HVAC_HOT, 22, FAN_SPEED_AUTO, VANNE_AUTO_MOVE, HVAC_OFF);
  }

  return temperature;
}

void setup() {
  pinMode(led, OUTPUT);
  Spark.function("heatpump", run);
}

void loop() {
  // Controlled through te cloud
}
