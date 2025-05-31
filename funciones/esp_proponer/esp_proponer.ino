// Recibe la palabra hablada desde el arduino nano
// Ejecuta el publish

HardwareSerial mySerial(1); // UART1

PIPEA nodo_emisor;
#include <pipea.h>
#include <hidboot.h>
#include <usbhub.h>

void proponer
void setup() {
  Serial.begin(115200);                          // Debugging
  mySerial.begin(9600, SERIAL_8N1, 16, 17);      // RX, TX
  
  // Inicia al nodo
  nodo_emisor.inicio();

}

void loop() {
  // Read from Arduino
  if (mySerial.available()) {
    String msg = mySerial.readStringUntil('\n');
    Serial.println(msg);
    // Genera el publish
    nodo_emisor.proponer("DMX",msg);
    nodo_emisor.actualizar();
  }



}

