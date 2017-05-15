#ifndef EVENTS_INFO_H
#define EVENTS_INFO_H

#include "Buffer.h"
#include "KeyboardEvGen.h"
#include "NetworkingEvGen.h"
#include "SoftwareEvGen.h"
#include <fstream>

class EventsInfo
{
private:
	Buffer<GenericEvent *> buffer;
	client c;

public:
	EventsInfo(char * serverIP, char * portNumber);
	~EventsInfo();
	bool sendData(char * buffer, unsigned int size);

	SoftwareEvGen * software;
	NetworkingEvGen * networking;
	KeyboardEvGen * keyboard;

	char * fileName;
	std::ofstream * output;
	std::ifstream * input;
	
	unsigned int lastDataSize;
};


#endif //EVENTS_INFO_H
