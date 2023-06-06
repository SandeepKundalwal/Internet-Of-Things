/* Simulate parallel commun
 *  This is transmitter
 */

#include <stdlib.h>  

 void DisplayNumber(int num){
  switch(num)
  {
    case 0:
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
      break;
    case 1:
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,HIGH);
      break;
    case 2:
      digitalWrite(8,LOW);
      digitalWrite(9,HIGH);
      digitalWrite(10,LOW);
      break;
    case 3:
      digitalWrite(8,LOW);
      digitalWrite(9,HIGH);
      digitalWrite(10,HIGH);
      break;
    case 4:
      digitalWrite(8,HIGH);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
      break;
    case 5:
      digitalWrite(8,HIGH);
      digitalWrite(9,LOW);
      digitalWrite(10,HIGH);
      break;
    case 6:
      digitalWrite(8,HIGH);
      digitalWrite(9,HIGH);
      digitalWrite(10,LOW);
      break;
    default:
      break;
  }
  delay(500);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
 }

void setup() {
  // put your setup code here, to run once:
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  while(true){
    Serial.println("1.Normal\n2.Engine Temp Low\n3.Coolant Low \n4.Oil Low \n5.Tyre Pressure Low \n6.Service Error \n");
    Serial.println("Enter Choice: ");  
    while(Serial.available() == 0){}

    int choice = Serial.parseInt();
    DisplayNumber(choice);
  }
}
