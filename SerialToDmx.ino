#include <DmxSimple.h>
#include <ArduinoSTL.h>
#include <map>

//Seteado a PIN3 para output
static int outputPin = 3;

static int faders[8];

static const int pinFaders[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };

static std::map<String, int> PARAMETERS;

void setup() {
  Serial.begin(9600);

  loadParameters("lb200");

  for (int i = 0; i < sizeof(faders) / sizeof(faders[0]); i++) {
    faders[i] = 0;
  }

  DmxSimple.usePin(outputPin);

  Serial.println("SerialToDmx ready");
}

void loop() {
  for (int i = 0; i < sizeof(faders) / sizeof(faders[0]); i++) {
    faders[i] = analogRead(pinFaders[i]) / 4;
    if (faders[i] > 255) {
      faders[i] = 255;
    }
  }

  DmxSimple.write(PARAMETERS["COLOR"], faders[0]);
  DmxSimple.write(PARAMETERS["STROBE"], faders[1]);
  DmxSimple.write(PARAMETERS["DIMMER"], faders[2]);
  DmxSimple.write(PARAMETERS["GOBO"], faders[3]);
  DmxSimple.write(PARAMETERS["FOCUS"], faders[4]);
  DmxSimple.write(PARAMETERS["TILT"], faders[5]);
  DmxSimple.write(PARAMETERS["PAN"], faders[6]);
  DmxSimple.write(PARAMETERS["LAMP"], faders[7]);

  Serial.println("COLOR: " + String(faders[0]) + " | STROBE: " + String(faders[1]) + " | DIMMER: " + String(faders[2]) + " | GOBO: " + String(faders[3]) + " | FOCUS: " + String(faders[4]) + " | TILT: " + String(faders[5]) + " | PAN: " + String(faders[6]) + " | LAMP: " + String(faders[7]));
}

void loadParameters(String machine) {
  if (machine == "lb200") {
    PARAMETERS["COLOR"] = 1;
    PARAMETERS["STROBE"] = 2;
    PARAMETERS["DIMMER"] = 3;
    PARAMETERS["GOBO"] = 4;
    PARAMETERS["PRISM_INSERTION"] = 5;
    PARAMETERS["PRISM_ROTATION"] = 6;
    PARAMETERS["EFFECTS"] = 7;
    PARAMETERS["FROST"] = 8;
    PARAMETERS["FOCUS"] = 9;
    PARAMETERS["PAN"] = 10;
    PARAMETERS["PAN_FINE"] = 11;
    PARAMETERS["TILT"] = 12;
    PARAMETERS["TILT_FINE"] = 13;
    PARAMETERS["MACRO"] = 14;
    PARAMETERS["RESET"] = 15;
    PARAMETERS["LAMP"] = 16;
  }
}
