int ECHO=2; // define ultrasonic signal receiver pin ECHO to D4 
int TRIG=3; 
#define FAN 4// define ultrasonic signal transmitter pin TRIG to D5 
#include <DHT11.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd (0x27 , 16 , 2 ); 
Servo servo;
Servo s;

DHT11 dht11(7);

int led = 8;
void setup() {
  // servo.attach(5);
  Serial.begin(9600);
  // put your setup code here, to run once:
 pinMode(led, OUTPUT);// LDR + LED

 pinMode(ECHO , INPUT); 
 pinMode(TRIG , OUTPUT);
 pinMode(FAN,OUTPUT ); 
 s.attach(5); // Servo Attach to PIN 5 
 lcd.clear(); // Clear the LCD
 lcd.init(); // intiate the lCD
 lcd.backlight(); // light of LCD 


}

void loop() {
  int temperature = dht11.readTemperature(); //Temprature Readings 
  float val = analogRead(A0); // Value OF LDR
  Serial.println(temperature); // print DHT11 Value in Serial Monitor
   lcd.setCursor(0, 0); 
   lcd.print("Temprature : ");
   lcd.print(temperature); 

  if (temperature > 27) {
    
    digitalWrite(FAN , HIGH); // Must connect FAN with Transistor 

  }
  else{
  
   digitalWrite(FAN, LOW); 
   
  }
  //Ultrasonic
  digitalWrite(TRIG, LOW); 

  delayMicroseconds(2); 

  digitalWrite(TRIG, HIGH); // Pulse for 10μs to trigger ultrasonic detection 
  delayMicroseconds(10); 
  digitalWrite(TRIG, LOW); 
  int distance = pulseIn(ECHO, HIGH); 
  Serial.println("Distance : "  );
  Serial.print(distance);// Read receiver pulse time
  Serial.println();  
  distance= distance/58; // Transform pulse time to distance  2cm to 400cm
  Serial.println("D:");
  Serial.print(distance); //Ourput distance
   //Ourput distance
  if(distance <= 20)
  {
    
    for(int pos= 0 ; pos<= 180 ; pos++ ){
      s.write(pos);
      delay(10); 
    }
    delay(100);


  }else{
    for(int pos=180; pos>=0; pos--)
    {
      s.write(pos);
      delay(10);
    }
    s.write(0);
  }
//LDR+LED (Controlling Home Lighting)

  if(val<200){
    digitalWrite(led, 1);
  }
  else{
    digitalWrite(led, 0);
  }
  delay(200);
  // put your main code here, to run repeatedly:
  lcd.clear(); 
}
