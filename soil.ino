#include <ESP8266WiFi.h>
#include "DHT.h"

#define S3 D0
#define S2 D1
#define S1 D2
#define S0 D3
#define analogpin A0
#define DHTTYPE DHT11
//#define dht_dpin D7
#define DHTPIN D7
DHT dht(DHTPIN, DHTTYPE); 

#define SensorPin 0          
unsigned long int avgValue;  
float b;
int buf[10],temp;


void setup() {
  dht.begin();
  Serial.begin(115200);
  delay(10);
  pinMode(analogpin, INPUT);
  pinMode(S0,OUTPUT);
  pinMode(S1,OUTPUT);
  pinMode(S2,OUTPUT);
  pinMode(S3,OUTPUT);  
}
void loop() {

 
  
  digitalWrite(S0,LOW);
  digitalWrite(S1,LOW);
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  Serial.print("LDR::");Serial.print(analogRead(analogpin));
  Serial.print("||");
  delay(100);

  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  Serial.print("MOISTURE::");Serial.print(analogRead(analogpin));
  Serial.print("||");
    delay(100);

  digitalWrite(S0,LOW);
  digitalWrite(S1,HIGH);
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
 
 for(int i=0;i<10;i++)       
  { 
    buf[i]=analogRead(SensorPin);
    delay(10);
  }
  for(int i=0;i<9;i++)        
  {
    for(int j=i+1;j<10;j++)
    {
      if(buf[i]>buf[j])
      {
        temp=buf[i];
        buf[i]=buf[j];
        buf[j]=temp;
      }
    }
  }
  avgValue=0;
  for(int i=2;i<8;i++)                      
    avgValue+=buf[i];
  float phValue=(float)avgValue*5.0/1024/6; 
  phValue=3*phValue;                      
  Serial.print("    pH:");  
  Serial.print(phValue,2);
  delay(100);
  
    float h = dht.readHumidity();
    float t = dht.readTemperature();         
    Serial.print("Current humidity = ");
    Serial.print(h);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(t); 
    Serial.println("C  ");
  delay(1000);


  
}
