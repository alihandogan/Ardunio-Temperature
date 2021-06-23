#include <Wire.h>
int LM35 = A15;
int data;
int temp;


void setup() {
  analogReference(INTERNAL1V1);
  Wire.begin();
  Serial.begin(9600);

}

void loop() {
  Wire.beginTransmission(1);
  data = analogRead(LM35);
  temp = data / 9.31; 
  //Serial.print("Sıcaklık: ");
  //Serial.println(temp);
  Wire.write(temp);
  Wire.endTransmission();
  delay(1000);

}
