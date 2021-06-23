#include <Wire.h>
#include <LiquidCrystal.h>
int temp;
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
const int butonPin = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
char  *message = "Alihan Dogan";



void setup() {
  Wire.begin(1);
  Serial.begin(9600);
  pinMode(butonPin,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(butonPin),butonaBasildi,RISING);
  lcd.begin(16, 2);
  Wire.onReceive(gelenVeri);
}

void loop() {
 
  butonBirakildi();

}

void showLetters(int printStart, int startLetter)
{
  lcd.setCursor(printStart, 0);
  for (int currentLetter = startLetter; currentLetter < strlen(message); currentLetter++)
  {
    lcd.print(message[currentLetter]);
  }
  lcd.print("        ");
  delay(50);
}
void gelenVeri(int numBytes) {
  while (Wire.available()) {
    temp = Wire.read();
  }
}


void butonaBasildi(){
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print(temp);

  if (temp < 25) {
    lcd.setCursor(5, 0);
    lcd.print("NORMAL");
    lcd.print(" ");
    lcd.setCursor(12, 0);
    lcd.print(" ");
  }
  else if (temp >= 25 && temp <= 30) {
    lcd.setCursor(5, 0);
    lcd.print("SICAK");
    lcd.print(" ");
    lcd.setCursor(11, 0);
    for (int i = 0 ; i < 3 ; i++) {
      lcd.print(" ");
    }
  }
  else if (temp > 30) {
    lcd.setCursor(5, 0);
    lcd.print("COK SICAK");
    lcd.print(" ");
  }
 for (int printStart = 15; printStart >= 0; printStart--)  
 {
   showLetterss(printStart, 0);
 }

 for (int letter = 1; letter <= strlen(message); letter++)  
 {
   showLetterss(0, letter);
 }

 attachInterrupt(digitalPinToInterrupt(butonPin),butonBirakildi,FALLING);
  
  }
 
 void showLetterss(int printStart, int startLetter)
{
  lcd.setCursor(printStart, 1);
  for (int currentLetter = startLetter; currentLetter < strlen(message); currentLetter++)
  {
    lcd.print(message[currentLetter]);
  }
  lcd.print("        ");
  delay(50);
}

void butonBirakildi(){
  lcd.clear();
  lcd.setCursor(2, 1);
  lcd.print(temp);

  if (temp < 25) {
    lcd.setCursor(5, 1);
    lcd.print("NORMAL");
    lcd.print(" ");
    lcd.setCursor(12, 1);
    lcd.print(" ");
  }
  else if (temp >= 25 && temp <= 30) {
    lcd.setCursor(5, 1);
    lcd.print("SICAK");
    lcd.print(" ");
    lcd.setCursor(11, 1);
    for (int i = 0 ; i < 3 ; i++) {
      lcd.print(" ");
    }
  }
  else if (temp > 30) {
    lcd.setCursor(5, 1);
    lcd.print("COK SICAK");
    lcd.print(" ");
  }
 for (int printStart = 15; printStart >= 0; printStart--)  
 {
   showLetters(printStart, 0);
 }

 for (int letter = 1; letter <= strlen(message); letter++)  
 {
   showLetters(0, letter);
 }
 attachInterrupt(digitalPinToInterrupt(butonPin),butonaBasildi,RISING);
  
  
  }
