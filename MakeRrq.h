#ifndef MAKE_RRQ_H
#define MAKE_RRQ_H

#include <fstream>
#include "GenericEvent.h"


class MakeRrq : public GenericEvent
{
private:

public:
	MakeRrq(std::ofstream * f, char * name); 

	char * name;	//nombre del archivo que se va a pedir
	std::ofstream * f; //donde se guardara lo que se reciba

};//OFSTREAM YA TIENE QUE ESTAR ABIERTO


#endif //MAKE_RRQ_H