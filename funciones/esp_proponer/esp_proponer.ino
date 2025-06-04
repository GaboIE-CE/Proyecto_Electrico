// Recibe la palabra hablada desde el arduino nano
// Ejecuta el publish
//HardwareSerial mySerial(1); // UART1



#include <pipea.h>
#include <hidboot.h>
#include <usbhub.h>
String msg = " ";
PIPEA nodo_emisor;

void setup() {
  Serial.begin(115200);                          // Debugging
  Serial1.begin(9600, SERIAL_8N1, 16, 17);// RX, TX
  
  // Inicia al nodo
  nodo_emisor.inicio();

}

void loop() {
  // Read from Arduino
  if (Serial1.available()) {
     msg = Serial1.readStringUntil('\n');
    Serial.println(msg);
    // Genera el publish
    nodo_emisor.proponer("DMX",msg);
    
  }

nodo_emisor.actualizar();

}

