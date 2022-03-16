#include <Arduino.h>

// Left
const int in_1 = 2;
const int in_2 = 3;

// Left
const int in_3 = 4;
const int in_4 = 5;

void setup()
{

  // Initialize pins
  pinMode(in_1, OUTPUT);
  pinMode(in_2, OUTPUT);
  pinMode(in_3, OUTPUT);
  pinMode(in_4, OUTPUT);
}

void loop()
{
  foward();
  delay(3000);
  backward();
  delay(3000);
   backward();
  delay(3000);
}

void foward()
{
  digitalWrite(in_1, HIGH);
  digitalWrite(in_2, LOW);
  digitalWrite(in_3, HIGH);
  digitalWrite(in_4, LOW);
}

void backward()
{
  digitalWrite(in_1, LOW);
  digitalWrite(in_2, HIGH);
  digitalWrite(in_3, LOW);
  digitalWrite(in_4, HIGH);
}

void right()
{
  digitalWrite(in_1, HIGH);
  digitalWrite(in_2, LOW);
  
}