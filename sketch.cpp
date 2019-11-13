// ICS Servo sample (Asynchrotous API)
#include <Arduino.h>
#include <ICS.h>

IcsController ICS(Serial1);
IcsServo servo1;

void setup() {

  Serial.begin(115200);

  ICS.begin(1250000);
  //servo1.attach(ICS, 0x02);
  servo1.attach(ICS, 11); //should be like this

  servo1.setPosition(7500);

  delay(1000);
}

void loop() {

  for(int position=-2000; position<=2000; position+=100){
    servo1.requestPosition(7500+position);

    while(!ICS.isReady())
    {
        ICS.loop();
        ; // Do any other process while communicating!
    }

    Serial.print(position);
    Serial.print("\t");
    Serial.print(servo1.position);
    Serial.print("\n");

    delay(20);
  }
  for(int position=-2000; position<=2000; position+=100){
    servo1.requestPosition(7500-position);

    while(!ICS.isReady())
    {
        ICS.loop();
        ; // Do any other process while communicating!
    }

    Serial.print(position);
    Serial.print("\t");
    Serial.print(servo1.position);
    Serial.print("\n");

    delay(20);
  }
}
