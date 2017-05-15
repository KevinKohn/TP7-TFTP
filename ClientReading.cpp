#include "ClientReading.h"

#include <cstdio>
#include "GenericHandlersTFTP.h"

#include "ClientIdle.h"
#include "DataTimedOut.h"

#include "Data.h"
#include "LastData.h"
#include "Error.h"
#include "Timeout.h"
#include "Ack.h"


#define ACK_SIZE	4
#define ACK_CODE	4


GenericState* Reading :: onData (GenericEvent * event)
{
	Data * ev = (Data *)event;

	for(unsigned int j = 0; j<ev->paqSize; j++) //guardar la informacion
		ev->i->output->put(ev->paquet[j]);

	sendAck(event);
	ev->i->networking->waitingForPaquet++;
	ev->i->software->StartTimer();

	return NULL;
}

GenericState* Reading :: onLastData (GenericEvent * event)
{
	LastData * e = (LastData *)event;	
	
	sendAck(event);
	endReading(event);

	return new Idle;
}

GenericState* Reading :: onTimeout(GenericEvent * event)
{	
	//reenviar el ultimo ack
	sendAck(event);
	event->i->software->StartTimer();
	//reempezar el timer para ver si llega data antes del 2do timeout

	return new DataTimedOut;
}

GenericState* Reading :: onError (GenericEvent * event)
{
	endReading(event);
	std::remove(event->i->fileName);	//el archivo quedo incompleto
	
	return new Idle;
}


GenericState* Reading :: onAck (GenericEvent * event)
{
	sendError(event);
	endReading(event);
	std::remove(event->i->fileName);	//el archivo quedo incompleto
	return new Idle;
}


//GenericState* Reading :: onExit (GenericEvent * event)
//{
//	//SimulationEvent * ev = (SimulationEvent *)event;
//	//Point p = ev->getWhereToWrite();
//
//	//move(p.getX(), p.getY());
//	//printw("end connection and shut down");
//	//clrtoeol();
//
//	return NULL;
//}

