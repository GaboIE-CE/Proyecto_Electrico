// Este archivo recibe comandos por comunicacion serial del esp32
// Ejecuta esos comandos en la DMX

#include <DmxSimple.h>
#include <Arduino.h>

String light = "";
void setup() {

  DmxSimple.usePin(3);


  Serial.begin(9600);

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



// Comando luz verde
if (strcmp(light.c_str(), "GREEN") == 0) {
    Serial.println(F("green recibido"));
    // Turn Off all lights
    DmxSimple.write(3, 0);
    DmxSimple.write(5, 0);// RED
    DmxSimple.write(6, 0);// GREEn
    DmxSimple.write(7, 0);// BLUE
    DmxSimple.write(8, 0);

    for (brightness = 0; brightness <= 255; brightness++) {
          DmxSimple.write(1, brightness); 
          DmxSimple.write(6, 200);    
          DmxSimple.write(5, 20);
          delay(10);
    }
  }
// Comando luz roja   
if (strcmp(light.c_str(), "RED") == 0) {
    Serial.println(F("green recibido"));
    // Turn Off all lights
    DmxSimple.write(3, 0);
    DmxSimple.write(5, 0);
    DmxSimple.write(6, 0);
    DmxSimple.write(7, 0);
    DmxSimple.write(8, 0);

    for (brightness = 0; brightness <= 255; brightness++) {
          DmxSimple.write(1, brightness); // RED
          DmxSimple.write(5, 200);    // GREEn
         // DmxSimple.write(5, 20);
          delay(10);
    }
  }
  
  // Comando luz azul   
if (strcmp(light.c_str(), "RED") == 0) {
    Serial.println(F("green recibido"));
    // Turn Off all lights
    DmxSimple.write(3, 0);
    DmxSimple.write(5, 0);
    DmxSimple.write(6, 0);
    DmxSimple.write(7, 0);
    DmxSimple.write(8, 0);

    for (brightness = 0; brightness <= 255; brightness++) {
          DmxSimple.write(1, brightness); // RED
          DmxSimple.write(7, 200);    // GREEn
         // DmxSimple.write(5, 20);
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



  
   }
  }


