#include "MakeWrq.h"


MakeWrq :: MakeWrq(std::ifstream * f, char * name, EventsInfo * i) : f(f) 
{
	type = EV_MAKE_WRQ;
	
	this->name = new char[strlen(name)];
	strcpy(this->name, name);
}; 
