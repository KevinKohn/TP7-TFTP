#ifndef CLIENT_IDLE_H
#define CLIENT_IDLE_H


#include "GenericState.h"

class Idle : public GenericState
{
    virtual GenericState* onMakeRrq(GenericEvent * ev);
    virtual GenericState* onMakeWrq(GenericEvent * ev);
};


#endif //CLIENT_IDLE_H
