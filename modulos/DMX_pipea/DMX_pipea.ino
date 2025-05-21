

#include <DmxSimple.h>
#include <Arduino.h>
//#include <pipea.h>

//char light[20];
String light = "";
void setup() {
  /* The most common pin for DMX output is pin 3, which DmxSimple
  ** uses by default. If you need to change that, do it here. */
  DmxSimple.usePin(3);

  /* DMX devices typically need to receive a complete set of channels
  ** even if you only need to adjust the first channel. You can
  ** easily change the number of channels sent here. If you don't
  ** do this, DmxSimple will set the maximum channel number to the
  ** highest channel you DmxSimple.write() to. */
  //DmxSimple.maxChannel(15);

  Serial.begin(9600);
  
  //   while(!Serial);
  // Serial.println("Esperando");
}

void loop() {

// Se recibe el mensaje por comunicacion serial

  if (Serial.available()) {
    String light = Serial.readStringUntil('\n');
    light.trim();
    Serial.print("Received: ");
    Serial.println(light);
  int brightness;
  int micValue = analogRead(A0);
  int count = 0;
if (light.equals("electricity")){
    Serial.println(F("Electricity recibido"));
    // Turn on Electricity
    DmxSimple.write(5, 0);
    DmxSimple.write(6, 0);
    DmxSimple.write(3, 0);
    DmxSimple.write(2, 255);
    DmxSimple.write(1, 255);
    DmxSimple.write(8, 255);
    DmxSimple.write(7, 35);
    delay(2000);
    DmxSimple.write(2, 0);
    DmxSimple.write(6, 0);
    DmxSimple.write(7, 0);
    DmxSimple.write(8, 0);
    for (brightness = 0; brightness <= 255; brightness++) {
    DmxSimple.write(5, brightness);
    delay(20);
    }
  }

 //Check if button is pressed
  if (strcmp(light.c_str(), "fight") == 0){
    Serial.println(F("Fight recibido"));
    // Turn on Red ramp up
    DmxSimple.write(3, 0);
    DmxSimple.write(5, 0);
    DmxSimple.write(6, 0);
    DmxSimple.write(7, 0);
    DmxSimple.write(8, 0); // if (!strcmp(light,"white")) {
…  //     DmxSimple.write(8, 255);
  //     delay(10);
  //   }
  // }

    DmxSimple.write(2, 150);
    DmxSimple.write(5, 255);
    DmxSimple.write(8, 255);
    delay(1000);

    DmxSimple.write(2, 150);
    DmxSimple.write(5, 255);
    DmxSimple.write(6, 255);
    DmxSimple.write(8, 255);
    delay(1000);

    DmxSimple.write(6, 0);
    DmxSimple.write(2, 150);
    DmxSimple.write(5, 255);
    DmxSimple.write(8, 255);
    delay(1000);

    DmxSimple.write(2, 150);
    DmxSimple.write(5, 255);
    DmxSimple.write(6, 255);
    DmxSimple.write(8, 255);
    delay(1000);

    DmxSimple.write(6, 0);
    DmxSimple.write(2, 150);
    DmxSimple.write(5, 255);
    DmxSimple.write(8, 255);
    delay(1000);

    DmxSimple.write(2, 150);
    DmxSimple.write(5, 255);
    DmxSimple.write(6, 255);
    DmxSimple.write(8, 255);
    delay(10);

  }


if (strcmp(light.c_str(), "green") == 0) {
    Serial.println(F("green recibido"));
    // Turn Off all lights
    DmxSimple.write(3, 0);
    DmxSimple.write(5, 0);
    DmxSimple.write(6, 0);
    DmxSimple.write(7, 0);
    DmxSimple.write(8, 0);

    for (brightness = 0; brightness <= 255; brightness++) {
          DmxSimple.write(1, brightness);
          DmxSimple.write(6, 200);
          DmxSimple.write(5, 20);
          delay(10);
    }
  }

if (strcmp(light.c_str(), "RAN") == 0) {
    Serial.println(F("RAN recibido"));
    // Turn Off all lights
    DmxSimple.write(3, 0);
    DmxSimple.write(5, 0);
    DmxSimple.write(6, 0);
    DmxSimple.write(7, 0);
    DmxSimple.write(8, 0);

    for (brightness = 0; brightness <= 255; brightness++) {
          DmxSimple.write(1, brightness);
          DmxSimple.write(8, 255);
          DmxSimple.write(5, 40);
          DmxSimple.write(6, 10);
          delay(5);
    }

    for (brightness = 255; brightness >= 0; brightness--) {
          DmxSimple.write(1, brightness);
          DmxSimple.write(8, 255);
          DmxSimple.write(5, 40);
          DmxSimple.write(6, 10);
          delay(5);
    }
    delay(1);
    DmxSimple.write(1, 255);
    DmxSimple.write(2, 255);
    DmxSimple.write(8, 255);

    delay(20);

    DmxSimple.write(1, 0);
    DmxSimple.write(2, 0);
    DmxSimple.write(6, 0);
    DmxSimple.write(7, 0);
    DmxSimple.write(8, 0);
    for (brightness = 0; brightness <= 255; brightness++) {
    DmxSimple.write(1, 255);
    DmxSimple.write(5, brightness);

    delay(1);
    }
  }  



  // if (!strcmp(light,"white")) {
  //  Serial.println(F("white recibido"));

  //   DmxSimple.write(3, 0);
  //   DmxSimple.write(5, 0);
  //   DmxSimple.write(6, 0);
  //   DmxSimple.write(7, 0);
  //   DmxSimple.write(8, 0);

  //   for (brightness = 0; brightness <= 255; brightness++) {
  //     DmxSimple.write(1, brightness);
  //     DmxSimple.write(8, 255);
  //     delay(10);
  //   }
   }
  }


  // if (!strcmp(light,"OFF")) {
  //   Serial.println(F("OFF recibido));
  //   // Turn Off all lights
  //   DmxSimple.write(5, 0);
  //   DmxSimple.write(3, 10);
  //   DmxSimple.write(6, 0);
  //   DmxSimple.write(7, 0);
  //   DmxSimple.write(8, 0);
  //   DmxSimple.write(2, 0);
