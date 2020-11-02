#include <Arduino.h>
#include <Wire.h>
#include "Robot.h"
#include"Encabulator/ENCABULATOR.h"
#include "Autonomous/AUTONOMOUS.h"

#define SDA_PIN 23
#define SCL_PIN 22
#define I2C_FREQ 400000

void RobotTask(void*pvParameters);
void AutonTask(void*pvParameters);

ROBOT Robot;
ENCABULATOR Brain;

void setup() 
{  
  //Main Setup code
  //Begins Serial, I2C bus, and tasks
  
  //Tasks begin
  xTaskCreatePinnedToCore(RobotTask, "RobotTask", 10000, NULL, 1, NULL, 1);
  xTaskCreatePinnedToCore(AutonTask, "AutonTask", 10000, NULL, 1, NULL, 1);

  Serial.begin(115200);
  Serial.println("Main Setup Running!");
  Serial.println("Initializing I2C");
  //Init I2C
  Wire.begin(SDA_PIN, SCL_PIN, I2C_FREQ); 
  Brain.Setup();
  Robot.Setup();
  
}

//Arudino 'loop' function
void loop() 
{
  //Main brain loop
  Brain.Loop();
  delay(1);
  yield();
}

//Run the robot task with the controller read and motor controller writing 
void RobotTask(void *pvParameters)
{ 
  while (true)
  {
    Robot.Loop();
  }
  
}

//Run the autonomous task serperate so during autonomous, the controller will still read and the motors will still write
void AutonTask(void *pvParameters)
{
  while (true)
  {
    Robot.Auton.Loop();
  }
  
}