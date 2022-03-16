#include <Arduino.h>
#include <MPU6050_tockn.h>

// ? Car
// Left tyres
const int in_1 = 2;
const int in_2 = 3;
const int enA = 9;


// Right tyres
const int in_3 = 4;
const int in_4 = 5;
const int enB = 10;


// ? Ultasonic Sensor
const int trigPin = 7;
const int echoPin = 6;

MPU6050 mpu6050(Wire);
long timer = 0;
float angleZ = 0;
bool movingLeft = false;

long runTime = 3000;
long startTime = 0;

void setup()
{

  // Initialize pins
  pinMode(in_1, OUTPUT);
  pinMode(in_2, OUTPUT);
  pinMode(in_3, OUTPUT);
  pinMode(in_4, OUTPUT);
   pinMode(enA, OUTPUT); 
  pinMode(enB, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Initialize MPU6050
  Serial.begin(9600);
  Wire.begin();
  //mpu6050.begin();
  //mpu6050.calcGyroOffsets(true);
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

  // foward();

  if (millis() - startTime < runTime)
  {

    foward();
    speed()
    if (getDistance() < 10)
    {
      stop();
      delay(200);
      reverse(200);
      delay(300); // time to break before turning
      right();
      foward();
    }
  }
  stop();
  /* update();
  Serial.print("angleX : ");
  Serial.print(mpu6050.getAngleX());
  Serial.print("\tangleY : ");
  Serial.print(mpu6050.getAngleY());
  Serial.print("\tangleZ : ");
  Serial.println(mpu6050.getAngleZ());

   Serial.print("gyroX : ");Serial.print(mpu6050.getGyroX());
      Serial.print("\tgyroY : ");Serial.print(mpu6050.getGyroY());
      Serial.print("\tgyroZ : ");Serial.println(mpu6050.getGyroZ());

  Serial.print("gyroAngleX : ");Serial.print(mpu6050.getGyroAngleX());
      Serial.print("\tgyroAngleY : ");Serial.print(mpu6050.getGyroAngleY());
      Serial.print("\tgyroAngleZ : ");Serial.println(mpu6050.getGyroAngleZ()); */
}

void speed(int val) {
  analogWrite(9, val); //ENA pin
  analogWrite(10, val);
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

/* void turnLeft()
{

  // +ve change
  angleZ = mpu6050.getAngleZ();
  while (angleZ > mpu6050.getAngleZ())
  {

    // send msg to move front
    message = 1;
    _radioData.Data = message;
    sendData();
    Serial.println("front");
    mpu.Execute();
  }

  angleZ = mpu6050.getAngleZ();
  timer = millis();
  movingLeft = true;
  left();
}
 */

void foward()
{
  digitalWrite(in_1, HIGH);
  digitalWrite(in_2, LOW);
  digitalWrite(in_3, HIGH);
  digitalWrite(in_4, LOW);
}

void reverse(long ms)
{
  stop();
  digitalWrite(in_1, LOW);
  digitalWrite(in_2, HIGH);
  digitalWrite(in_3, LOW);
  digitalWrite(in_4, HIGH);
  delay(ms);
  stop();
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
  digitalWrite(in_1, HIGH);
  digitalWrite(in_2, LOW);
  digitalWrite(in_3, LOW);
  digitalWrite(in_4, HIGH);
  // How long it should turn for
  delay(400);
  stop();
  delay(3000);
}

void stop()
{
  digitalWrite(in_1, LOW);
  digitalWrite(in_2, LOW);
  digitalWrite(in_3, LOW);
  digitalWrite(in_4, LOW);
}

float getDistance()
{

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = (0.0343 / 2 * duration);
  Serial.println(distance);

  return distance;
}