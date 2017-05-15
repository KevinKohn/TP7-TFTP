#ifndef MAKE_WRQ_H
#define MAKE_WRQ_H

#include "GenericEvent.h"
#include "EventsInfo.h"

class MakeWrq : public GenericEvent
{
private:


public:

	MakeWrq(std::ifstream * file, char * name);
	//EL IFSTREAM RECIBIDO YA TIENE QUE ESTAR ASOCIADO CON EL ARCHIVO

	std::ifstream * f;	//archivo que se quiere mandar al servidor
	char * name;	//nombre de ese archivo (con extension)
};


#endif //MAKE_WRQ_H