#include "Encoder.h"
#include <iostream>
/*this is only for testing purposes*/
int main()
{
	Encoder encodeDat = Encoder();
	encodeDat.dat.latitude = -117.0164789;
	encodeDat.dat.longitude = 46.7255421;
	encodeDat.dat.altitude = 11.923423;
	encodeDat.dat.temperatureE = 273;
	encodeDat.dat.temperatureI = 270;
	encodeDat.dat.signalStrength = 4;
	encodeDat.EncodeData();
	std::cout << encodeDat.getBitString();
}