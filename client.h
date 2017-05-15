#ifndef CLIENT_H
#define CLIENT_H

#include "GenericEvent.h"

//eventos:
typedef enum{ACK, LAST_ACK, DATA, LAST_DATA, TIMEOUT, ERROR, EXIT, HELP, MAKE_RRQ, MAKE_WRQ, EVENT_COUNT} event_t;

//teclas correspondientes a cada evento:
#define ACK_K		'a'
#define LAST_ACK_K	'l'
#define DATA_K		'd'
#define LAST_DATA_K	'b'
#define TIMEOUT_K	't'
#define ERROR_K		'e'
#define EXIT_K		'q'


//GenericEvent * eventGenerator();


#endif //CLIENT_H