#include "EventsInfo.h"
#include "client.h"
#define BUFFER_SIZE	100

EventsInfo :: ~EventsInfo()
{
	delete networking;
	delete software;
	delete keyboard;
}

EventsInfo :: EventsInfo(char * serverIP, char * portNumber) : buffer(BUFFER_SIZE)
{
	c.ConectToServer(serverIP, portNumber);
}


bool EventsInfo :: sendData(char * data, unsigned int size)
{
	c.sendData(data, size);
}