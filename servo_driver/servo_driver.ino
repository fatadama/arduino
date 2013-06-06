#include <Servo.h> 

Servo theServo;

bool testStart = 0;

int serData = -1;

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
    }
  }
  if(testStart)
  {
    //set servo to max deflection
    theServo.write(180);
  }
  else
  {
    //set servo to 0
    theServo.write(0);
  }
  Serial.print(millis());
  Serial.print("\t");
  Serial.println(theServo.read());
}
