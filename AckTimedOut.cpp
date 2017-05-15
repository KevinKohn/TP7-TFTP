#include "AckTimedOut.h"

#include "ClientWriting.h"
#include "ClientIdle.h"
#include "GenericHandlersTFTP.h"

GenericState* AckTimedOut :: onData (GenericEvent * ev)
{
	sendError(ev);
	writingError(ev);
	return new Idle;
}

GenericState* AckTimedOut :: onLastData (GenericEvent * ev)
{
	sendError(ev);
	writingError(ev);
	return new Idle;
}

GenericState* AckTimedOut :: onAck	(GenericEvent * ev)
{
	unsigned int bySent = sendData(ev);

	if(ev->i->input->eof() == true) {
		ev->i->software->reachedEOF = true;
		ev->i->lastDataSize = bySent;
	}

	ev->i->networking->waitingForPaquet++;
	ev->i->software->StartTimer();

	return new Writing;
}

GenericState* AckTimedOut :: onTimeout (GenericEvent * ev)
{
	sendError(ev);
	writingError(ev);
	return new Idle;
}

GenericState* AckTimedOut :: onError (GenericEvent * ev)
{
	writingError(ev);
	return new Idle;
}
