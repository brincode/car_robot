#include<Ultrasonic.h>
Ultrasonic ultr(5, 4);
// int ECHO=4; // define ultrasonic signal receiver pin ECHO to D4 
// int TRIG=5; // define ultrasonic signal transmitter pin TRIG to D5 
int led =13;
int LDR = A0;
#define FAN 12// define ultrasonic signal transmitter pin TRIG to D5

int buz = 3;  //buzzer connected to pin 3
int RedLed = 2;  //led connected to pin 2
const int aqsensor = A1;  //output of mq135 connected to A0 pin of Arduino
int threshold = 250;

#include <DHT11.h>
DHT11 dht11(11);

#include <Servo.h>
Servo s;

int PIR = 6;
Servo sPIR;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // pinMode(ECHO , INPUT); 
  // pinMode(TRIG , OUTPUT);

  pinMode(led, OUTPUT);// LDR + LED

  s.attach(7); // Servo Attach to PIN 7

  pinMode(FAN,OUTPUT ); 

  pinMode (buz,OUTPUT);     // buzzer is connected as Output from Arduino
  pinMode (RedLed,OUTPUT);     // led is connected as output from Arduino
  pinMode (aqsensor,INPUT); // MQ135 is connected as INPUT to arduino

  pinMode (PIR,INPUT); // PIR is connected as INPUT to arduino
  sPIR.attach(10); // Servo Attach to PIN 10

}

void loop() {
  //LDR+LED (Controlling Home Lighting)
  float LDRval = analogRead(LDR); // Value OF LDR
  Serial.println("LDR value: ");
  Serial.print(LDRval); // print LDR Value in Serial Monitor
  Serial.println();
  delay(500);
  if(LDRval<15){
    digitalWrite(led, 1);
  }
  else{
    digitalWrite(led, 0);
  }

  //DHT11 +Fan (Controlling temperature and humidity)
  int temperature = dht11.readTemperature(); //Temprature Readings 
  Serial.println("temperature: "); // print DHT11 Value in Serial Monitor
  Serial.print(temperature); // print DHT11 Value in Serial Monitor
  Serial.println();
  delay(500);
  if (temperature > 20) {
    
    digitalWrite(FAN , HIGH); // Must connect FAN with Transistor 
    // digitalWrite(led , HIGH);

  }
  else{
  
   digitalWrite(FAN, LOW); 
  //  digitalWrite(led, LOW); 
   
  }


  //Controlling windows and curtains inside rooms


  //Ultrasonic + Servo motor (Opening and closing the garage door)
  // digitalWrite(TRIG, LOW); 
  // delayMicroseconds(2); 

  // digitalWrite(TRIG, HIGH); // Pulse for 10μs to trigger ultrasonic detection 
  // delayMicroseconds(10); 

  // digitalWrite(TRIG, LOW); 

  // int distance = pulseIn(ECHO, HIGH); // Read receiver pulse time
  // // Serial.println("Distance : "  );
  // // Serial.print(distance);
  // // Serial.println();  
  // distance= distance/58; // Transform pulse time to distance  2cm to 400cm
  // Serial.println("Distance:");
  // Serial.print(distance); //Ourput distance
  // Serial.println();
  // delay(500);
  int distance = ultr.read();
  Serial.println("Distance:");
  Serial.print(distance); //Ourput distance
  Serial.println();
  delay(500);
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


  //Air Quality Sensor(MQ135) + Buzzer + RedLed (Controlling safety inside the home)
  int AQ = analogRead(aqsensor); //read MQ135 analog outputs at A1 and store it in AQ

  Serial.println("Air Quality: ");  //print message in serail monitor
  Serial.print(AQ);            //print value of AQ in serial monitor
  Serial.println();
  delay(500);
  if (AQ < threshold)            // check is ppm is greater than threshold or not
    {
      //tone(RedLed,1000,200);         //blink led with turn on time 1000mS, turn off time 200mS
      digitalWrite(RedLed,HIGH);
      digitalWrite(buz,HIGH);     //Turn ON Buzzer
    }
  else
    {
      digitalWrite(led,LOW);   //jump here if ppm is not greater than threshold and turn off LED
      digitalWrite(buz,LOW);   //Turn off Buzzer
    }


  //Opening and closing doors
  int PIRval = digitalRead(PIR);
  Serial.println("PIR value: ");  //print message in serail monitor
  Serial.print(PIRval);            //print value of PIR in serial monitor
  Serial.println();
  delay(500);
  if(PIRval)
  {
    sPIR.write(90);
    // for(int pos= 0 ; pos<= 180 ; pos++ ){
    //   sPIR.write(pos);
    //   delay(10); 
    // }

  }else{
    sPIR.write(0);
    // for(int pos=180; pos>=0; pos--)
    // {
    //   sPIR.write(pos);
    //   delay(10);
    // }
  }

  delay(200);

}
