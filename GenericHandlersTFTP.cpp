#include "GenericHandlersTFTP.h"
#include "EventsInfo.h"

#include "Data.h"

#define ACK_SIZE	4
#define ACK_CODE	4

#define DATA_MIN	4
#define DATA_CODE	3

#define ERROR_SIZE	5
#define ERROR_CODE	5

void endReading(GenericEvent * e)
{ 
	e->i->output->close();
	delete [] e->i->fileName;
	delete e->i->output;
}

void endWriting(GenericEvent * e)
{ 
	e->i->input->close();
	delete [] e->i->fileName;
	delete e->i->input;
}



void sendAck(GenericEvent * e) 
{
	Data * ev = (Data *)e;

	char ack[ACK_SIZE] = {ACK_CODE, 0};	//header
	ack[3] = (char) e->i->networking->waitingForPaquet;	//numero de paquete
	ack[4] = e->i->networking->waitingForPaquet>>8;
	e->i->sendData(ack, ACK_SIZE);
}


void lastDataActions(GenericEvent * e)
{
	e->i->output->close();
	delete [] e->i->fileName;
	delete [] e->i->output;
}


unsigned int sendData(GenericEvent * e)
{
	char buffer[DATA_SIZE + DATA_MIN] = {DATA_CODE, 0};
	buffer[3] = (char) e->i->networking->waitingForPaquet;	//numero de paquete
	buffer[4] = e->i->networking->waitingForPaquet>>8;

	unsigned int byRead = e->i->input->readsome(&buffer[DATA_MIN], DATA_SIZE);
	e->i->sendData(buffer, DATA_MIN + byRead);

	return byRead;
}

void sendError(GenericEvent * e, unsigned int errorCode)
{ 
	char buffer[ERROR_SIZE] = { ERROR_CODE, 0, errorCode, 0, 0 };
	e->i->sendData(buffer, ERROR_SIZE);
}
