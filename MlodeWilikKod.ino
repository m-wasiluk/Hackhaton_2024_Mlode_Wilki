#include <OneWire.h>
#include <DallasTemperature.h>

#define relay1 2

#define relay2 13

#define temp1 15

OneWire oneWire(temp1);
DallasTemperature czujnik(&oneWire);

  float avgT;
  float T1;
  float T2;
  float T3;
  float T4;
  float T5;
  float T6;

  float TMAX=25.0;


void setup() {
  Serial.begin(115200);
  czujnik.begin();
  pinMode(relay1,OUTPUT);

  pinMode(relay2,OUTPUT);

  czujnik.requestTemperatures();

  T1=czujnik.getTempCByIndex(0);
  T2=T1;
  T3=T2;
  T4=T3;
  T5=T4;
  T6=T5;
}

void loop() {
  
  //Serial.print(czujnik.getTempCByIndex(0));
  //digitalWrite(relay1,HIGH);
  //delay(200);
  //digitalWrite(relay1,LOW);


  delay(1000);
  czujnik.requestTemperatures();


  T1=czujnik.getTempCByIndex(0);

  Serial.print(T1);
  Serial.println(" °C");
  
  if(T1>=TMAX)
  {
    digitalWrite(relay1,HIGH);
  }
  else
  {
    digitalWrite(relay1,LOW);
  } 
  delay(1000);

  digitalWrite(relay2,HIGH);
  delayMicroseconds(200);
  digitalWrite(relay2,LOW);
  

  czujnik.requestTemperatures();


  T1=czujnik.getTempCByIndex(0);

  Serial.print(T1);
  Serial.println(" °C");
  
  if(T1>=TMAX)
  {
    digitalWrite(relay1,HIGH);
  }
  else
  {
    digitalWrite(relay1,LOW);
  }


}
