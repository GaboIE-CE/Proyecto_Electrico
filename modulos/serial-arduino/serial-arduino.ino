void setup() {
  Serial.begin(9600); // This is Arduino's only hardware serial (pins 0 & 1)
  while(!Serial);
  Serial.println("Esperando");
}

void loop() {
  if (Serial.available()) {
    String msg = Serial.readStringUntil('\n');
    Serial.print("Received: ");
    Serial.println(msg);
  }
}
