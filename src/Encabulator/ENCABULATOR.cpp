#include "ENCABULATOR.h"

void ENCABULATOR::Setup()
{   
    //Starts up the PCA9685 chip, the screen, and the gyroscope
    Serial.println("Initializing PWM");
    Chip.PWM1.begin();
    Chip.PWM1.setPWMFreq(500);
    Chip.PWM2.begin();
    Chip.PWM2.setPWMFreq(500);
    Screen.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    Screen.clearDisplay();
    Screen.setCursor(0, 0);
    Screen.setTextSize(1);
    Screen.setTextColor(WHITE);
    Screen.display();
    pinMode(16, OUTPUT);
    digitalWrite(16, HIGH);     
}

void ENCABULATOR::Loop()
{
    //GYRO Loop 
}

//Writes on the display (parameter text size (1 or 2 ideal) String to write)
void ENCABULATOR::DrawString(int TextSize, String ToDraw)
{
    Screen.clearDisplay();
    Screen.setCursor(0,0);
    Screen.setTextSize(TextSize);
    Screen.println(ToDraw);
    Screen.display();
}

//Writes on the display (parameter the string to write)
void ENCABULATOR::DrawString(String ToDraw)
{
    Screen.clearDisplay();
    Screen.setCursor(0,0);
    Screen.setTextSize(1);
    Screen.println(ToDraw);
    Screen.display();
}

//Writes on the display (Paraemter x coord(0-127) ycoord(0-63) Text size(1 or 2 ideal) String to write)
void ENCABULATOR::DrawString(int xcoord, int ycoord, int TextSize, String ToDraw)
{
    Screen.clearDisplay();
    Screen.setCursor(xcoord,ycoord);
    Screen.setTextSize(TextSize);
    Screen.println(ToDraw);
    Screen.display();
}

