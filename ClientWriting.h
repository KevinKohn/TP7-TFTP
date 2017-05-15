#ifndef CLIENT_WRITING_H
#define CLIENT_WRITING_H

#include "GenericState.h"

class Writing : public GenericState
{
    virtual GenericState* onAck(GenericEvent * ev);
    virtual GenericState* onTimeout(GenericEvent * ev);
    virtual GenericState* onError (GenericEvent * ev);
	virtual GenericState* onData (GenericEvent * ev);
	virtual GenericState* onLastData (GenericEvent *ev);
    virtual GenericState* onExit (GenericEvent * ev);
	virtual GenericState* onLastPaqSent (GenericEvent *);

};



#endif //CLIENT_WRITING_H
