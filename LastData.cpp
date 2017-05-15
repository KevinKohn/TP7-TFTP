#include "LastData.h"


LastData :: LastData(char * paquet, unsigned int paqSize) : Data(paquet)
{ 
	this->paqSize = paqSize;
	type = EV_DATA;
}

