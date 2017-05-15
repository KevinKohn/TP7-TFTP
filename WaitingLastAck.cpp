#include "WaitingLastAck.h"
#include "GenericHandlersTFTP.h"

#include "ClientIdle.h"

GenericState * WaitingLastAck :: onData (GenericEvent *ev)
{
	endWriting(ev);
	sendError(ev);
	return new Idle;
}

GenericState * WaitingLastAck :: onLastData (GenericEvent *ev)
{
	endWriting(ev);
	sendError(ev);
	return new Idle;
}

GenericState * WaitingLastAck :: onAck (GenericEvent *ev)
{
	endWriting(ev);
	return new Idle;
}
GenericState * WaitingLastAck :: onTimeout	(GenericEvent *ev)
{
	ev->i->input->seekg(-ev->i->lastDataSize, std::ios_base::cur); 
	//solo see reenvia last data una vez. lo reenvio y salgo
	
	sendData(ev);
	
	return new Idle;
}

GenericState * WaitingLastAck :: onError (GenericEvent *ev)
{
	endWriting(ev);
	return new Idle;
}
