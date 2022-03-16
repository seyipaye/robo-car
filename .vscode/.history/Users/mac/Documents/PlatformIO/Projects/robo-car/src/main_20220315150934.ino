#include <Arduino.h>
#include <MPU6050_tockn.h>

MPU6050 mpu6050(Wire);

// Left
const int in_1 = 2;
const int in_2 = 3;

// Right
const int in_3 = 4;
const int in_4 = 5;

void setup()
{

  // Initialize pins
  pinMode(in_1, OUTPUT);
  pinMode(in_2, OUTPUT);
  pinMode(in_3, OUTPUT);
  pinMode(in_4, OUTPUT);

  // Initialize MPU6050
   Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void loop()
{
  // foward();
  // delay(3000);
  // backward();
  // delay(3000);
  // right();
  // delay(3000);
  // left();
  // delay(3000);

 mpu6050.update();
  Serial.print("angleX : ");
  Serial.print(mpu6050.getAngleX());
  Serial.print("\tangleY : ");
  Serial.print(mpu6050.getAngleY());
  Serial.print("\tangleZ : ");
  Serial.println(mpu6050.getAngleZ());

// Serial.print("gyroAngleX : ");Serial.print(mpu6050.getGyroAngleX());
//     Serial.print("\tgyroAngleY : ");Serial.print(mpu6050.getGyroAngleY());
//     Serial.print("\tgyroAngleZ : ");Serial.println(mpu6050.getGyroAngleZ());

  delay(100);
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

void left()
{
  stop();
  digitalWrite(in_1, HIGH);
  digitalWrite(in_2, LOW);
}

void right()
{
  stop();
  digitalWrite(in_3, HIGH);
  digitalWrite(in_4, LOW);
}

void stop()
{
  digitalWrite(in_1, LOW);
  digitalWrite(in_2, LOW);
  digitalWrite(in_3, LOW);
  digitalWrite(in_4, LOW);
}
