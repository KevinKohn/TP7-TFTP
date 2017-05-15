#ifndef ACK_TIMED_OUT_H
#define ACK_TIMED_OUT_H

#include "GenericState.h"

class AckTimedOut : public GenericState
{
public:
    virtual GenericState* onData		(GenericEvent *);
    virtual GenericState* onLastData	(GenericEvent *);
    virtual GenericState* onAck			(GenericEvent *);
    virtual GenericState* onTimeout		(GenericEvent *);
    virtual GenericState* onError		(GenericEvent *);
};



#endif // !ACK_TIMED_OUT_H\
