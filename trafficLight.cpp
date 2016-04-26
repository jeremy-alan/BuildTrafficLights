#include "Arduino.h"
#include "TrafficLight.h"

TrafficLight::TrafficLight(int redPin, int yellowPin, int greenPin)
                         : _red(redPin), _yel(amberPin), _grn(greenPin)
{
}

void TrafficLight::SetMode(LightMode mode)
{
    _red.Set(mode & 0x04);
    _yel.Set(mode & 0x02);
    _grn.Set(mode & 0x01);
}

void TrafficLight::Setup()
{
    LightMode lights[] = {
        LIGHT_MODE_RED,
        LIGHT_MODE_YEL,
        LIGHT_MODE_GRN,
        LIGHT_MODE_OFF,
        LIGHT_MODE_ALL,
        LIGHT_MODE_OFF,
    };

    for (int i = 0; i < 6; ++i)
    {
        SetMode(lights[i]);
        delay(InitStepDelay);
    }
}

void TrafficLight::ShowInconclusive()
{
    SetMode(LIGHT_MODE_AMBER);
}

void TrafficLight::ShowError()
{
    SetMode(LIGHT_MODE_RED_GREEN);
}