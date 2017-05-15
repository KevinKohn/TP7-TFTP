#ifndef EVENT_GENERATOR_H
#define EVENT_GENERATOR_H


#include "GenericEvent.h"
#include "EventsInfo.h"
#include "Buffer.h"

class EventGenerator
{
private:
	EventsInfo i;
	Buffer<GenericEvent *> buffer;

public:
	EventGenerator(EventsInfo& i) : i(i) {;}
	GenericEvent * getNextEvent();
};







#endif //EVENT_GENERATOR_H