#include "ClientWriting.h"
#include "ClientIdle.h"
#include "AckTimedOut.h"
#include "WaitingLastAck.h"

#include "GenericHandlersTFTP.h"

#include "Ack.h"
#include "Timeout.h"
#include "LastPaqSent.h"
#include "Error.h"
#include "Data.h"
#include "LastData.h"

#define DATA_SIZE	512
#define	DATA_MIN	4

#define DATA_CODE	3

GenericState* Writing :: onAck(GenericEvent * event)
{
	event->i->networking->waitingForPaquet++;
	unsigned int bySent = sendData(event);

	if(event->i->input->eof() == true) {
		event->i->software->reachedEOF = true;
		event->i->lastDataSize = bySent;
	}

	event->i->software->StartTimer();
	return NULL;
}

GenericState* Writing :: onTimeout(GenericEvent * event)
{
	event->i->input->seekg(-DATA_SIZE, std::ios_base::cur); ///volver 512 lugares
	//si se hubiese enviado LAST DATA (menor que 512), no se estaria en este estado
	
	unsigned int byRead = sendData(event);
	
	event->i->software->StartTimer();

	return new AckTimedOut;
}

GenericState* Writing :: onError (GenericEvent * event)
{
	endWriting(event);
	return new Idle;
}


GenericState* Writing :: onLastPaqSent (GenericEvent * ev)
{
	return new WaitingLastAck;
}

//
//GenericState* Writing :: onExit (GenericEvent * event)
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
