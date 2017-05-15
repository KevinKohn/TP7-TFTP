#ifndef WAITING_LAST_ACK_H
#define WAITING_LAST_ACK_H

#include "GenericState.h"

class WaitingLastAck : public GenericState
{
public:
	virtual GenericState* onData (GenericEvent *);
    virtual GenericState* onLastData (GenericEvent *);
    virtual GenericState* onAck (GenericEvent *);
    virtual GenericState* onTimeout	(GenericEvent *);
    virtual GenericState* onError (GenericEvent *);

};


#endif //WAITING_LAST_ACK_H