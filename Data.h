#ifndef DATA_H
#define DATA_H

#include "GenericEvent.h"

#define DATA_SIZE	 512


class Data : public GenericEvent
{
public:
	Data(char * paquet);
	~Data();

	char paquet [DATA_SIZE];
	unsigned int paqSize;	//en Data siempre 512, en LastData varia

};

#endif //DATA_H