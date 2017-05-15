#include "ClientIdle.h"

#include "MakeRrq.h"
#include "MakeWrq.h"
#include "Exit.h"

#include <cstring>

#define MAX_PAQUET_SIZE	600

#define MODE_S		"netascii"
#define MODE_LEN	9

enum {RRQ = 1, WRQ, DATA, ACK, TFTP_ERROR};


GenericState* onMakeRrq(GenericEvent * ev)
{
	MakeRrq * e = (MakeRrq *)ev;
	unsigned int fileLen = strlen(e->name);

	char paquet[MAX_PAQUET_SIZE] = {0, RRQ, '\0'};
	strncat(&paquet[1], e->name, MAX_PAQUET_SIZE-3);
	strncpy(&paquet[3+fileLen], "netascii", MAX_PAQUET_SIZE-3-fileLen);

	e->i->output = e->f;
	e->i->fileName = e->name;
	e->i->sendData(&paquet[0], 3+fileLen+MODE_LEN);
	e->i->networking->waitingForPaquet = 0;
	e->i->software->StartTimer();

	return new WaitingFirstData;
}


GenericState* onMakeWrq(GenericEvent * ev)
{
	MakeWrq * e = (MakeWrq *)ev;
	unsigned int fileLen = strlen(e->name);

	char paquet[MAX_PAQUET_SIZE] = {0, WRQ, '\0'};
	strncat(&paquet[1], e->name, MAX_PAQUET_SIZE-3);
	strncpy(&paquet[3+fileLen], "netascii", MAX_PAQUET_SIZE-3-fileLen);

	e->i->input = e->f;
	e->i->fileName = e->name;
	e->i->sendData(&paquet[0], 3+fileLen+MODE_LEN);
	e->i->networking->waitingForPaquet = 0;
	e->i->software->StartTimer();

	return new WaitingFirstAck;
}
