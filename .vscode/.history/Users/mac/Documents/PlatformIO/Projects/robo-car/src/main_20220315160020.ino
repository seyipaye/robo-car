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

void update() {
    mpu6050.update();

}

void turnLeft()
{
  timer = millis();
  const int angleZ = mpu6050.getAngleZ();

  Serial.print("\tangleZ : ");
  Serial.println(mpu6050.getAngleZ());

  if (millis() - timer > 1000)
  {
    // 1 seconds has pass
    Serial.println("=======================================================");
    Serial.print("temp : ");
    Serial.println(mpu6050.getTemp());
    Serial.print("accX : ");
    Serial.print(mpu6050.getAccX());
    Serial.print("\taccY : ");
    Serial.print(mpu6050.getAccY());
    Serial.print("\taccZ : ");
    Serial.println(mpu6050.getAccZ());

    Serial.print("gyroX : ");
    Serial.print(mpu6050.getGyroX());
    Serial.print("\tgyroY : ");
    Serial.print(mpu6050.getGyroY());
    Serial.print("\tgyroZ : ");
    Serial.println(mpu6050.getGyroZ());

    Serial.print("accAngleX : ");
    Serial.print(mpu6050.getAccAngleX());
    Serial.print("\taccAngleY : ");
    Serial.println(mpu6050.getAccAngleY());

    Serial.print("gyroAngleX : ");
    Serial.print(mpu6050.getGyroAngleX());
    Serial.print("\tgyroAngleY : ");
    Serial.print(mpu6050.getGyroAngleY());
    Serial.print("\tgyroAngleZ : ");
    Serial.println(mpu6050.getGyroAngleZ());

    Serial.print("angleX : ");
    Serial.print(mpu6050.getAngleX());
    Serial.print("\tangleY : ");
    Serial.print(mpu6050.getAngleY());
    Serial.print("\tangleZ : ");
    Serial.println(mpu6050.getAngleZ());
    Serial.println("=======================================================\n");
    timer = millis();
  }
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
