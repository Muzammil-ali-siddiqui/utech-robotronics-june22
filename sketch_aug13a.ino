#include <LiquidCrystal.h>


LiquidCrystal lcd(11, 12, 5, 4, 3, 2);
int intensity = 0;

int safeLed = 9;
int dangerLed = 10;

#define flamePin 7
#define buzzerPin 8

int seconds = 0;

void setup(){
  Serial.begin(9600);
  
  lcd.begin(16, 2); // Set up the number of columns and rows on the LCD.
  analogWrite(A0, intensity);

  pinMode(safeLed, OUTPUT);
  pinMode(dangerLed, OUTPUT);
  
  pinMode(buzzerPin, OUTPUT);
  pinMode(flamePin, INPUT);
  
  // Print a message to the LCD
  lcd.setCursor(0, 0);
  lcd.print("Calibrating");
  
  for (int i = 0; i < 15; i++) {
    if (i == 4) {
      lcd.setCursor(0, 1);
      lcd.print(".");
    } else  
      lcd.print(".");
    delay(500);
  }

  lcd.setCursor(11, 1);
  lcd.print("Done");
  
  delay(1000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sensor Active...");
  
  
  digitalWrite(safeLed, HIGH);
}  

void loop(){  

  int flameValue = digitalRead(flamePin);
  bool isFlameDetected = (flameValue == LOW);
  Serial.print(flameValue);

  lcd.setCursor(0, 1);
  
  if (isFlameDetected) {
    digitalWrite(dangerLed, HIGH);
    digitalWrite(safeLed, LOW);
    digitalWrite(buzzerPin, HIGH);

    lcd.print("DANGER!! FIRE!");
  } else {
    digitalWrite(dangerLed, LOW);
    digitalWrite(safeLed, HIGH);
    digitalWrite(buzzerPin, LOW);
    
    lcd.print("________________"); 
  }
  
  delay(500);
}  
