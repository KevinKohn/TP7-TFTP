#ifndef GENERIC_EVENT_H
#define GENERIC_EVENT_H

#include "EventsInfo.h"

#define	CLIENT	1	
#define SERVER	0

#define I_AM	CLIENT

#if I_AM == CLIENT
typedef enum{EV_ACK, EV_DATA, EV_LAST_DATA, EV_TIMEOUT, EV_ERROR, EV_EXIT, EV_HELP, 
			EV_MAKE_RRQ, EV_MAKE_WRQ, EV_LAST_PAQ_SENT, EVENT_COUNT} event_t;
#elif I_AM == SERVER
#include "server.h"
#else
#error	"This program must emulate either a CLIENT or a SERVER in a TFTP connection"
#endif



class GenericEvent
{
public:
	GenericEvent() {;}
	void setEvInfo(EventsInfo * i) { this->i = i; }
	event_t getType() {	return type; }
	EventsInfo * i;

protected:
	event_t type;
};


#endif //GENERIC_EVENT_H