#include "MakeRrq.h"


MakeRrq :: MakeRrq(std::ofstream * f, char * name) : f(f) 
{
	type = EV_MAKE_RRQ;
	
	this->name = new char[strlen(name)];
	strcpy(this->name, name);
}; 
