int echo = 3;
int trig = 2;
int led1 = 10;
int led2 = 9;
int led3 = 8;
int buzzer = 7;

int duration = 0;
int distance = 0;

void setup(){
  pinMode(trig, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buzzer, OUTPUT);
    
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop(){
  digitalWrite(trig, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
   distance = (duration/2) / 28.5;
  Serial.println(distance); 


  if ( distance <= 6 ){
    digitalWrite(led1, HIGH);
    delay(100);
  }
  else{
    digitalWrite(led1, LOW);
    delay(100);
  }
  
  
  if ( distance <= 6 ){
    digitalWrite(buzzer, HIGH);
    delay(100);
  }
  else{
    digitalWrite(buzzer, LOW);
    delay(100);
  }
  

  if ( distance <= 14){
    digitalWrite(led2, HIGH);
  }
  else{
    digitalWrite(led2, LOW);
  }

  if ( distance <= 21){
    digitalWrite(led3, HIGH);
  }
  else{
    digitalWrite(led3, LOW);
  }
  
}
