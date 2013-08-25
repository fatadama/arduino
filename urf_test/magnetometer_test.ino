/*
  Read PWM input from magnetometer
  
 */
#define VCC 5//assumed APM2 VCC out value. Range scaling factor is VCC/1024 counts per cm
#define A8 62//pin for analog input8 pin on APM2.5 board

int magnetPin = A8;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
const float scaling = 1.0/58.0;// pwm scale factor in cm/microseconds

void setup() {
  //start serial at 115200 baud
  Serial.begin(115200);
  // declare the ledPin as an OUTPUT:
  pinMode(magnetPin, INPUT);  
}

void loop() {
  // read the value from the sensor:
  sensorValue = pulseIn(magnetPin,HIGH);
  //print range in cm
  Serial.println(float(sensorValue)*scaling);                  
  delay(500);
}
