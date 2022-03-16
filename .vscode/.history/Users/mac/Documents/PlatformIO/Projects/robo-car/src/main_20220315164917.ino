#include <Arduino.h>
#include <MPU6050_tockn.h>

MPU6050 mpu6050(Wire);
long timer = 0;

// Left
const int in_1 = 2;
const int in_2 = 3;

// Right
const int in_3 = 4;
const int in_4 = 5;

float angleZ = 0;
bool movingLeft = false;

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

  update();
  // Serial.print("angleX : ");
  // Serial.print(mpu6050.getAngleX());
  // Serial.print("\tangleY : ");
  // Serial.print(mpu6050.getAngleY());
  // Serial.print("\tangleZ : ");
  // Serial.println(mpu6050.getAngleZ());

  //  Serial.print("gyroX : ");Serial.print(mpu6050.getGyroX());
  //     Serial.print("\tgyroY : ");Serial.print(mpu6050.getGyroY());
  //     Serial.print("\tgyroZ : ");Serial.println(mpu6050.getGyroZ());

  // Serial.print("gyroAngleX : ");Serial.print(mpu6050.getGyroAngleX());
  //     Serial.print("\tgyroAngleY : ");Serial.print(mpu6050.getGyroAngleY());
  //     Serial.print("\tgyroAngleZ : ");Serial.println(mpu6050.getGyroAngleZ());
}

void update()
{
  mpu6050.update();
  if (movingLeft == true)
  {
    if (millis() - timer > 1000)
    {
      // 1 seconds has pass
      // Read value
      if (mpu6050.getAngleZ() - angleZ >= 90)
      {
        // 90 degrees has passed
        // Stop rotation
        stop();
        movingLeft == false;
      }
      timer = millis();
    }
  }
}

void turnLeft()
{
  float angleZ = 0;
angleZ = mpu6050.getAngleZ();
  timer = millis();
  movingLeft = true;
  left();
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
