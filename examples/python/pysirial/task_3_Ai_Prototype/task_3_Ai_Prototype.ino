
#define waterpump 8

char recievedchar;

void setup() {

  Serial.begin(9600);

  pinMode(waterpump, OUTPUT);
}

void loop() {

  if (Serial.available() > 0 ){

    recievedchar = Serial.read();

    if (recievedchar == '1'){

      digitalWrite(waterpump, 1); 
      
  }

  else{

      digitalWrite(waterpump, 0);
    }
    


  }
  delay(500);
}