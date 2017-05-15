#include "Data.h"


Data :: Data(char * paquet) 
{ 
	type = EV_DATA;
	paqSize = DATA_SIZE;

	for(unsigned int i = 0; i<DATA_SIZE; i++)
		this->paquet[i] = paquet[i];
}

