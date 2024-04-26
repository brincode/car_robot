#include<Servo.h>
// Object for Servo
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
//The pins for motor
int servopin1 = 2;
int servopin2 = 3;
int servopin3 = 4;
int servopin4 = 5;
int servopin5 = 6;
int servopin6 = 7;
//The pins for pots 
int potpin1 = A0;
int potpin2 = A1;
int potpin3 = A2;
int potpin4 = A3;
int potpin5 = A4;
int potpin6 = A5;


void setup() {
  servo1.attach(servopin1);
  servo2.attach(servopin2);
  servo3.attach(servopin3);
  servo4.attach(servopin4);
  servo5.attach(servopin5);
  servo6.attach(servopin6);
}

void loop() {
  int potvalue1 = analogRead(potpin1);
  int potvalue2 = analogRead(potpin2);
  int potvalue3 = analogRead(potpin3);
  int potvalue4 = analogRead(potpin4);
  int potvalue5 = analogRead(potpin5);
  int potvalue6 = analogRead(potpin6);

  int servovalue1 = map(potvalue1, 0, 1023, 0, 180);
  int servovalue2 = map(potvalue2, 0, 1023, 0, 180);
  int servovalue3 = map(potvalue3, 0, 1023, 0, 180);
  int servovalue4 = map(potvalue4, 0, 1023, 0, 180);
  int servovalue5 = map(potvalue5, 0, 1023, 0, 180);
  int servovalue6 = map(potvalue6, 0, 1023, 0, 180);

  servo1.write(servovalue1);
  servo2.write(servovalue2);
  servo3.write(servovalue3);
  servo4.write(servovalue4);
  servo5.write(servovalue5);
  servo6.write(servovalue6);

  delay(15);
}