// Estar atento, hace el subscribe
// Le manda esto al arduino-DMX por comunicacion serial

#include <Arduino.h>
#include <pipea.h>
char light[20] = "";
PIPEA DMX;

void reaccionar (char* personaje, char* accion){
  if(!strcmp(personaje,"DMX")){
  strcpy(light,accion);
      Serial.println(light);
      Serial2.println(light);
  
    //if(!strcmp(accion,"electricidad")){
      //Serial.println("electricidad");
      
      //Serial.println("el strig se asigno");
      //Serial.println(light);
     // Serial2.println("electricity");

    }
  }
}

void setup(){

  // Parte funcional
  Serial.begin(9600);
  Serial2.begin(9600,SERIAL_8N1,16,17);

  DMX.inicio();
  DMX.estar_atento("DMX",reaccionar);
}

void loop(){


DMX.actualizar();

}
