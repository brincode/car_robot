#define fan 6
#define led 5

#include <TMP36.h>

//Create an instance of the TMP36 class and 
//define the pin the sensor is connected to
//If using 3.3v Arduino, change 5 to 3.3
TMP36 myTMP36(A0, 5.0); 

void setup() {
  Serial.begin(9600);
  pinMode(fan, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  //create a variable and store the current temperature in
  //celsius in it using the getTempC function
  float celsius = myTMP36.getTempC(); 
  if(celsius > 30)
  {
    digitalWrite(fan, HIGH);
    digitalWrite(led, LOW);
  }else{
    digitalWrite(led, HIGH);
    digitalWrite(fan, LOW);
  }
  
  //create a variable and store the current temperature in
  //fahrenheit in it using the getTempF function
  // float fahrenheit = myTMP36.getTempF(); 

  //Print the data to the Serial monitor
  Serial.print("Celsius: ");
  Serial.print(celsius);
  // Serial.print(" Fahrenheit: ");
  // Serial.println(fahrenheit);
  delay(500);
}
