#include <Servo.h> 

Servo theServo;

bool testStart = 0;

int serData = -1;
int i = 0;
#ifndef MAXDEFLECTION
#define MAXDEFLECTION 90
#endif
#ifndef DEFLECTIONRATE
#define DEFLECTIONRATE 1
#endif

void setup()
{
  theServo.attach(9);
  
  theServo.write(0);
  
  Serial.begin(115200);
  Serial.print("time\tservo pos\n");
}

void loop()
{
  //process serial data
  if (Serial.available())
  {
    serData = Serial.read();
    if(serData == int('b'))
    {
      testStart = 1;
      //flush the buffer
      while(Serial.available())
      {
        serData = Serial.read();
      }

      serData = -1;
    }
  }
  if(testStart)
  {
    //set servo to max deflection
    for (i=0;i<MAXDEFLECTION;i+=DEFLECTIONRATE)
    {
      theServo.write(i);
      Serial.print(millis());
      Serial.print("\t");
      Serial.println(theServo.read());
      delay(15);
    }
    delay(1000);
    for (i=MAXDEFLECTION;i>=0;i-=DEFLECTIONRATE)
    {
      theServo.write(i);
      Serial.print(millis());
      Serial.print("\t");
      Serial.print(theServo.read());
      Serial.print("\t");
      Serial.println(i);
      delay(15);
    }
    testStart = 0;
    //theServo.write(180);

  }
}
