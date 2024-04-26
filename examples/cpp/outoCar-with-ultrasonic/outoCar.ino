
// ultrasonic  pins
// #define trigPin1 12
// #define echoPin1 11

// Motor PINS
#define motor_N1 2
#define motor_N2 3
#define motor_N3 4
#define motor_N4 5
// #define EN1       6
// #define EN2       7


void Forward() {
  // digitalWrite(EN1,HIGH) ;
  // digitalWrite(EN2,HIGH) ;
  digitalWrite(motor_N1, HIGH); 
  digitalWrite(motor_N2, LOW);
  digitalWrite(motor_N3, LOW);
  digitalWrite(motor_N4, HIGH);
}
void Revers() {
  // digitalWrite(EN1,HIGH) ;
  // digitalWrite(EN2,HIGH) ;
  digitalWrite(motor_N1, LOW);
  digitalWrite(motor_N2, HIGH);
  digitalWrite(motor_N3, HIGH);
  digitalWrite(motor_N4, LOW);
}

void Stop() {
  // digitalWrite(EN1,LOW) ;
  // digitalWrite(EN2,LOW) ;
  digitalWrite(motor_N1, LOW);
  digitalWrite(motor_N2, LOW);
  digitalWrite(motor_N3, LOW);
  digitalWrite(motor_N4, LOW);

  //or

  // digitalWrite(motor_N1, HIGH);
  // digitalWrite(motor_N2, HIGH);
  // digitalWrite(motor_N3, HIGH);
  // digitalWrite(motor_N4, HIGH);
}

// void Right() {

//   //  digitalWrite(EN1,HIGH) ;
//   // digitalWrite(EN2,HIGH) ;
//   digitalWrite(motor_N1, HIGH);
//   digitalWrite(motor_N2, HIGH);
//   digitalWrite(motor_N3, LOW);
//   digitalWrite(motor_N4, LOW);
// }

// void Left() {

//   // digitalWrite(EN1,HIGH) ;
//   // digitalWrite(EN2,HIGH) ;
//   digitalWrite(motor_N1, LOW);
//   digitalWrite(motor_N2, LOW);
//   digitalWrite(motor_N3, HIGH);
//   digitalWrite(motor_N4, HIGH);
// }
// define ultrasonic variable
// long duration1;
// int distanceL;


// int calculateDistance1() {
//   digitalWrite(trigPin1, LOW);
//   delayMicroseconds(2);
//   digitalWrite(trigPin1, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(trigPin1, LOW);
//   duration1 = pulseIn(echoPin1, HIGH);
//   distanceL = duration1 * 0.034 / 2;
//   return distanceL;
// }

void setup() {
  // put your setup code here, to run once:
  // pinMode(trigPin1, OUTPUT);
  // pinMode(echoPin1, INPUT);
  pinMode(motor_N1, OUTPUT);
  pinMode(motor_N2, OUTPUT);
  pinMode(motor_N3, OUTPUT);
  pinMode(motor_N4, OUTPUT);
  // pinMode(EN1,OUTPUT) ;
  // pinMode(EN2,OUTPUT) ;
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  // int val = calculateDistance1();
  delay(5);
  // Serial.println(val);
  // Forward () ;
  Revers();
  // if(val < 30){
  //   Stop();
  //   delay(100);
  //   Revers();
  //   delay(100);
  //   Stop();
  // }else{
  //   Forward();
  // }

  // if (val < 60) {
  //   Stop();
  //   delay(100);
  //   Revers();
  //   delay(100);
  //   Stop();
    
  //   Right();
  //   delay(200);
  //   Stop();
  //   delay(100);
  // } else {
  //   Left();
  //   delay(300);
  //   Stop();
  //   delay(100);
  // }

  // if (val > 30) {
  //   Forward();
  // }
  // if (val < 30) {
  //   Stop();
  //   delay(100);
  //   Revers();
  //   delay(100);
  //   Stop();

  //   if (val < 60) {
  //     Right();
  //     delay(200);
  //     Stop();
  //     delay(100);
  //   } else {
  //     Left();
  //     delay(300);
  //     Stop();
  //     delay(100);
  //   }
  // }
}
