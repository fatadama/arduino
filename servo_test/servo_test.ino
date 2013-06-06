
//test APM2 servo output control for accelerometer/gyro tests

//based on APM2_radio.pde example


#include <Arduino_Mega_ISR_Registry.h>
#include <APM_RC.h> // ArduPilot Mega RC Library
#include <Servo.h>

Servo theServo;

Arduino_Mega_ISR_Registry isr_registry;
APM_RC_APM2 APM_RC;

bool flagOn = 0;

void setup()
{
  /*isr_registry.init();
  APM_RC.Init(&isr_registry);
  
  APM_RC.enable_out(CH_1);
  APM_RC.enable_out(CH_2);
  APM_RC.enable_out(CH_3);
  APM_RC.enable_out(CH_4);
  APM_RC.enable_out(CH_5);
  APM_RC.enable_out(CH_6);
  APM_RC.enable_out(CH_7);
  APM_RC.enable_out(CH_8);
  
  pinMode(5,OUTPUT);*/
  
  theServo.attach(12);
  
  Serial.begin(115200);
  Serial.println("ArduPilot Mega RC library test");
  delay(1000);
}

void loop()
{
  if(flagOn)
  {
    //APM_RC.OutputCh(7,900);
    theServo.write(0);
    Serial.print(millis());
    //Serial.print("\t Channel 8 current = ");
    //Serial.println(APM_RC.OutputCh_current(7));
    delay(500);
  }
  else
  {
    //APM_RC.OutputCh(7,2100);
    theServo.write(90);
    Serial.print(millis());
    Serial.println("\t output set to 90");
    //Serial.print("\t Channel 8 current = ");
    //Serial.println(APM_RC.OutputCh_current(7));
    delay(500);
  }
  flagOn = !flagOn;
}
