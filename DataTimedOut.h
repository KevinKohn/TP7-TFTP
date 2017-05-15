#ifndef DATA_TIMED_OUT_T
#define DATA_TIMED_OUT_T

#include "GenericState.h"

class DataTimedOut : public GenericState
{
public:
    virtual GenericState* onData		(GenericEvent *);
    virtual GenericState* onLastData	(GenericEvent *);
    virtual GenericState* onError		(GenericEvent *);
    virtual GenericState* onTimeout		(GenericEvent *);
};



#endif //DATA_TIMED_OUT_T