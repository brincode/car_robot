#include<Servo.h>
#include<DHT11.h>
Servo s;
DHT11 d(A0);
void setup() {
  // put your setup code here, to run once:
s.attach(7);
}

void loop() {
  // put your main code here, to run repeatedly:
int humidity=d.readHumidity();
if(humidity > 80){
  // s.write(80);
  for(int pos=0;pos<=180;pos++){
    s.write(pos);
    delay(15);
  }
  for(int pos=180;pos>=0;pos--){
    s.write(pos);
    delay(15);
  }
}
}
