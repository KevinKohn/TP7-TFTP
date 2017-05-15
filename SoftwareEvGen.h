#ifndef SOFTWARE_EV_GEN_H
#define SOFTWARE_EV_GEN_H

#include "GenericEvent.h"

class SoftwareEvGen
{
private:
	clock_t tInicial;

public:
	bool reachedEOF;
	SoftwareEvGen();
	GenericEvent * getNextEvent();
	void StartTimer();
	unsigned int lastTimedOutPaquet;
};



#endif //SOFTWARE_EV_GEN_H
