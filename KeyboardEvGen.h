#ifndef KEYBOARD_EV_GEN_H
#define KEYBOARD_EV_GEN_H

#include "GenericEvent.h"


#define MAX_INPUT_LEN	100

class KeyboardEvGen 
{
private:
	unsigned int strLen;
	short unsigned nWordsReceived;
	char buffer[MAX_INPUT_LEN];

public:
	KeyboardEvGen();
	GenericEvent * getNextEvent();

};



#endif //KEYBOARD_EV_GEN_H
