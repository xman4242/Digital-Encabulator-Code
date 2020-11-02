#ifndef ENCABULATOR_h
#define ENCABULATOR_h
#include "MDD10A.h"
#include"MOTORCHIP.h"
#include "Adafruit_SSD1306.h"
#include "Adafruit_GFX.h"
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_ADDR 0x3C //0x3D


class ENCABULATOR
{
private:
    //Private Vars
    MOTORCHIP Chip;
public:
    //Public vars and funtions

    void Setup();
    void Loop();
    void DrawString(int TextSize, String ToDraw);
    void DrawString(String ToDraw);
    void DrawString(int xcoord, int ycoord, int TextSize, String ToDraw);
    Adafruit_SSD1306 Screen;
    
    
};




#endif //ENCABULATOR_h