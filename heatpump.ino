// based on
//    https://github.com/tiegz/Spark-Core-IRremote
//    https://github.com/r45635/HVAC-IR-Control

#include "IRremote.h"

IRsend irsend(D3);
int led = D7;

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
