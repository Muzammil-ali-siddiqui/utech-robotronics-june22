#include <LiquidCrystal.h>

char displayLine1[16];
char displayLine2[16];
char welcome_msg1[] = "Welcome !!!";
char welcome_msg2[] = "Made by Muzammil";
int contrast = 0;

int echo = 4;
int trig = 5; 
int ledGreen = 7;
int ledRed = 8;
int ledBlue = 9;

int duration = 0;
int distance = 0;

int limit = 15;

LiquidCrystal lcd(2, 3, 13, 12, 11, 10);


void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);  
  pinMode(echo, INPUT);

  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledBlue, OUTPUT);

  digitalWrite(ledBlue, HIGH);
  analogWrite(A0, contrast);
  lcd.begin(16, 2);
  lcd.home();
  lcd.print(welcome_msg1);
  lcd.setCursor(0, 1);
  lcd.print(welcome_msg2);
  delay(1000*10);

  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool isLimitReached = false;
    
  digitalWrite(trig, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = (duration/2) / 28.5;
  Serial.println(distance);

  if (distance <= limit) {
    digitalWrite(ledBlue, HIGH);
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, HIGH);  
    isLimitReached = true;
  } else {
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledRed, LOW);
    digitalWrite(ledBlue, LOW);
  }

  lcd.clear();
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm.");
  if (isLimitReached) {
    lcd.setCursor(0, 1);
    lcd.print("Limit is REACHED"); 
  }

  delay(250);
}
