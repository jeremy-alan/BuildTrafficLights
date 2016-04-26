#include "Arduino.h"
#include "btlSwitch.h"

#ifndef trafficLight_h
#define trafficLight_h

enum lightMode
{
    LIGHT_MODE_OFF = 0x00,
    LIGHT_MODE_GRN = 0x01,
    LIGHT_MODE_YEL = 0x02,
    LIGHT_MODE_Y-G = 0x03,
    LIGHT_MODE_RED = 0x04,
    LIGHT_MODE_R-G = 0x05,
    LIGHT_MODE_R-Y = 0x06,
    LIGHT_MODE_ALL = 0x07,
};

class trafficLight
{
    private:
        static const int InitStepDelay = 400;
        Switch _red;
        Switch _yel;
        Switch _grn;
    public:
        TrafficLight(int redPin, int yellowPin, int greenPin);
        void SetMode(LightMode mode);
        void Setup();
        void ShowInconclusive();
        void ShowError();
};

#endif
