#pragma once
struct data
{
public:
    float latitude = 000.00000; //25 bits
    float longitude = 000.00000; //24 bits
    float altitude = 000.00000; // 16 bits
    int temperatureE = 000; //10
    int temperatureI = 000; //10
    int signalStrength = 0; //3 stop here
    int clock = 000000;
};