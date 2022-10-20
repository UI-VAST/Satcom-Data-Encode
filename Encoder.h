#include <string>;
#include <bitset>;
#include <math.h>;
#include "data.h"
#pragma once
class Encoder
{
private:
	std::string bitString; // bit string that gets returned
public:
	data dat; // struct with all relivant data
	Encoder();
	std::string Encode(void*, int); // gets bits at a location
	void EncodeData(); // encodes dat to bitsring
	std::string EncodeDes(void*, int, int); // turns desimals into a bitstring
	std::string getBitString(); // gets the bitstring

};
