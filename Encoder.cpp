#include "Encoder.h"
Encoder::Encoder()
{
	dat = data();
}
std::string Encoder::Encode(void* var, int amtOB)
{
	int amtOfBy = ceil(amtOB / 8.0);
	std::string cbitString;
	for (int i = amtOfBy-1; i >= 0 ; i--)
	{
		char *byte = (char*)var; // convert void pointer to char pointer because a char is one byte
		std::bitset<8> curAdd(byte[i]);
		cbitString.append(curAdd.to_string()); // append byte data to string
	}	
	cbitString = cbitString.substr(cbitString.length()-amtOB); 
	return cbitString;
}
std::string Encoder::EncodeDes(void* var, int amtOB, int desPl) // runs encode for desimal
{
	int datToEn = round(*(float*)(var)*pow(10, desPl));
	return Encode(&datToEn, amtOB);
}
void Encoder::EncodeData()
{
	bitString.append(EncodeDes(&dat.latitude, 25, 5));
	bitString.append(EncodeDes(&dat.longitude, 24, 5));
	bitString.append(EncodeDes(&dat.altitude, 16, 2));
	bitString.append(Encode(&dat.temperatureE, 10));
	bitString.append(Encode(&dat.temperatureI, 10));
	bitString.append(Encode(&dat.signalStrength, 3));
	bitString.append(Encode(&dat.clock, 17));
}
std::string Encoder::getBitString()
{
	return bitString;
}