#ifndef GENERIC_HANDLERS_TFTP
#define GENERIC_HANDLERS_TFTP

#include "GenericEvent.h"

void endReading(GenericEvent *);

void endWriting(GenericEvent *);

void sendAck(GenericEvent *);
void lastDataActions(GenericEvent *);

unsigned int sendData(GenericEvent *);

void sendError(GenericEvent *, unsigned int errorCode);		//siempre errorcode esta entre 0 y 7!!

#endif // !GENERIC_HANDLERS_TFTP
