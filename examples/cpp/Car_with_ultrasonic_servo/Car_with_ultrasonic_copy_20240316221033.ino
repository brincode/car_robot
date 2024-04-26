// First Include the NewPing and Servo Libraries 

#include <NewPing.h> // library uses to read more accurate values from ultrasonic sensor 
#include <Servo.h> 

#define TRIG_PIN A1 
#define ECHO_PIN A2
#define MAX_DISTANCE 200 
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); // sensor function 
Servo myservo;   

int distance = 100;
// Motor A
const int motorPin1  = 6;  //left motor 1st pin  
const int motorPin2  = 5;  //left motor 2st pin

//Motor B
const int motorPin3  = 11; //right motor 1st pin
const int motorPin4  = 10;  //right motor 2st pin

void setup() {  
  
  myservo.attach(8);  // pin of servo motor
  myservo.write(115); 
  delay(2000);
  distance = readPing(); 
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);

  
}

void loop() {
 int distanceR = 0; // right
 int distanceL =  0; // left
 delay(40);
 
 if(distance<=20)
 {
  moveStop();
  delay(100);
  moveBackward();
  delay(400);
  moveStop();
  delay(200);
  distanceR = lookRight();
  delay(200);
  distanceL = lookLeft();
  delay(200);

  if(distanceR>=distanceL)
    {
      turnRight();
    
    }
  else
    {
      turnLeft();
    }
 }
 else
  { 
    moveForward();
  }
 
 distance = readPing();

}

int lookRight()
{
    myservo.write(50); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(115); 
    return distance;
}

int lookLeft()
{
    myservo.write(170); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(115); 
    return distance;
    delay(100);
}

int readPing() {  // defines a function returns an integer
  delay(70);      // delay of 70 milliseconds
  int cm = sonar.ping_cm();  //The ping_cm() function is used to measure the distance in centimeters for ultrasonic.
  if(cm==0)            //  if the measurement is 0 (which could indicate a problem), it adjusts the value to 250 before returning it.
  {
    cm = 250;
  }
  return cm;
}

void moveStop() {
  analogWrite(motorPin1, 1);
    analogWrite(motorPin2, 1);
    analogWrite(motorPin3, 1);
    analogWrite(motorPin4, 1);
  } 
  
void moveForward() {


    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 180);
    analogWrite(motorPin3, 180);
    analogWrite(motorPin4, 0);  
  
}

void moveBackward() {
    
    analogWrite(motorPin1, 180);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 180);
    analogWrite(motorPin4, 0);   
  
}  

void turnRight() {
 analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 0);
  analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 180);    
  delay(1000);
 moveForward();      
  
} 
 
void turnLeft() {
  analogWrite(motorPin1, 180);
    analogWrite(motorPin2, 0);    
 analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 0);     
  delay(1000);
   moveForward();
}  


