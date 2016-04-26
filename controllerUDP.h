
#include "trafficLight.h"

#ifndef controllerUDP_h
#define controllerUDP_h

class controllerUDP
{
    private:
        static const unsigned int port = 2806;
        static const unsigned long updateIntervalMS = 16000;
        unsigned long _lastUpdateMS;
        TrafficLight* _traffic;

    public:
        UdpController(TrafficLight* traffic);
        void Setup();
        void Loop();
};

#endif