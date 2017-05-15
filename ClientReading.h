#ifndef CLIENT_READING_H
#define CLIENT_READING_H

#include "GenericState.h"
#include "GenericEvent.h"



class Reading : public GenericState
{
protected:
	virtual GenericState* onData (GenericEvent * ev);
    virtual GenericState* onLastData (GenericEvent * ev);
    virtual GenericState* onTimeout(GenericEvent * ev);
    virtual GenericState* onError (GenericEvent * ev);
    virtual GenericState* onAck	(GenericEvent *);
    virtual GenericState* onExit (GenericEvent * ev);
};



#endif //CLIENT_READING_H