#ifndef NETWORKING_EV_GEN_H
#define NETWORKING_EV_GEN_H

#include "GenericEvent.h"
#include "client.h"

class NetworkingEvGen
{
private:
	client * c;


public:
	NetworkingEvGen(client * c);
	GenericEvent * getNextEvent();

	unsigned int waitingForPaquet; // el numero de paquete ack/data que estoy esperando
};

#endif //NETWORKING_EV_GEN_H
