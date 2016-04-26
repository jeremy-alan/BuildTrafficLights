###############################################################################
#
# Project: buildTrafficLights
#
#
#
###############################################################################


#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>

#include "trafficLight.h"
#include "controllerUDP.h"

const int LOOP_DELAY = 100;

const int redPin = 7;
const int yellowPin = 6;
const int greenPin = 5;

buildTrafficLight _traffic(redPin, yellowPin, greenPin);

controllerUDP _controller(&_traffic);

void setup()
{
    _traffic.Setup();
    _controller.Setup();
}

void loop()
{
    _controller.Loop();
    delay(LOOP_DELAY);
}