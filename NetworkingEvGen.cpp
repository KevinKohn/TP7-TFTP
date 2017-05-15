	#include "NetworkingEvGen.h"

#include "Error.h"
#include "Exit.h"
#include "Data.h"
#include "LastData.h"
#include "Ack.h"

#define MAX_PAQ_SIZE	600

#define DEST_DIR		"downloads\"

#define DATA_MIN		4
#define DATA_MAX		DATA_SIZE+DATA_MIN

#define ACK_SIZE		4

#define ILLEGAL_OPERATION	4

#define	LITTLE_ENDIAN(arr, n) ( ((arr)[(n)+1]<<8) | (arr)[n])


enum {RRQ = 1, WRQ, DATA, ACK, TFTP_ERROR};

NetworkingEvGen :: NetworkingEvGen(client * c) : c(c) {;}



GenericEvent * NetworkingEvGen :: getNextEvent()
{
	GenericEvent * newEv = NULL;
	char buffer[MAX_PAQ_SIZE];

	uint16_t msgSize = c->nonBlockinReceiveDataForServer(&buffer[0], MAX_PAQ_SIZE);

	if(msgSize != 0) {
		uint16_t op = 0;
		op = LITTLE_ENDIAN(buffer, 0); //pasar a little endian

		switch(op) {
			case DATA: {
				if (LITTLE_ENDIAN(buffer,2) == waitingForPaquet) { //verificar primero que sea el numero de paq correcto
					if (msgSize == DATA_MAX) {
						newEv = new Data(&buffer[DATA_MIN-1]);
					}	//para data paso la data en si y el numero de paquete por separado
					else if (msgSize < DATA_MAX && msgSize >= DATA_MIN)	{
						newEv = new LastData(&buffer[DATA_MIN-1], msgSize - DATA_MIN);
					}
					else {
						newEv = new Error(ILLEGAL_OPERATION);
					}
				}
				else {
					newEv = new Error(ILLEGAL_OPERATION);
				}
			}
			break;

			case ACK: {
				if (msgSize == ACK_SIZE && LITTLE_ENDIAN(buffer,2) == waitingForPaquet) 
					newEv = new Ack(); 
				else
					newEv = new Error(ILLEGAL_OPERATION);
			}
			break;

			case TFTP_ERROR:
				newEv = new Exit;
			break;

			default:
				newEv = new Error(ILLEGAL_OPERATION);
			break;
		}
	}

	return newEv;
}