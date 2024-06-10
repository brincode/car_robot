int led = 4;
int buzzer = 3;
int sensor = 5;

void setup() {
  pinMode(led,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(sensor,INPUT);
}

void loop() {
    int sensData = digitalRead(sensor);
    if(sensData){
      digitalWrite(led, HIGH);
      digitalWrite(buzzer, HIGH);
    }else{
      digitalWrite(led, LOW);
      digitalWrite(buzzer, LOW);

    }

}
