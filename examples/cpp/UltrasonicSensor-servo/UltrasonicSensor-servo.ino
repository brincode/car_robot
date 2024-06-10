// int inputPin=4; // define ultrasonic signal receiver pin ECHO to D4 
// int outputPin=5; // define ultrasonic signal transmitter pin TRIG to D5 
#include<Ultrasonic.h>
Ultrasonic ultr(5, 4);
#include<Servo.h>
Servo s;

void setup()
{
  Serial.begin(9600); 
  // pinMode(inputPin, INPUT); 
  // pinMode(outputPin, OUTPUT);
  s.attach(7);

 }
 
void loop()
 
{
  int distance = ultr.read();
  Serial.println("Distance:");
  Serial.print(distance); //Ourput distance

  if(distance <= 5)
  {
    s.write(90);
    // for(int pos= 0 ; pos<= 180 ; pos++ ){
    //   s.write(pos);
    //   delay(10); 
    // }
    // delay(100);


  }else{
    // for(int pos=180; pos>=0; pos--)
    // {
    //   s.write(pos);
    //   delay(10);
    // }
    s.write(0);
    
  }


  ////ultrasonic code in details

  // digitalWrite(outputPin, LOW); 

  // delayMicroseconds(2); 

  // digitalWrite(outputPin, HIGH); // Pulse for 10μs to trigger ultrasonic detection 
  // delayMicroseconds(10); 
  // digitalWrite(outputPin, LOW); 
  // int distance = pulseIn(inputPin, HIGH); // Read receiver pulse time 
  // distance= distance/58; // Transform pulse time to distance  2cm to 400cm
  // Serial.println(distance); //Ourput distance
  // if(distance <= 10)
  // {
  //   // for(int pos=0; pos<=90; pos++)
  //   // {
  //   //   s.write(pos);
  //   //   delay(5);
  //   // }
  //   s.write(120);
  //   delay(1000);

  // }else{
  //   // for(int pos=90; pos>=0; pos--)
  //   // {
  //   //   s.write(pos);
  //   //   delay(5);
  //   // }
  //   s.write(0);
  // }
  delay(50);
} 
