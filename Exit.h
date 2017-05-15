#ifndef EXIT_H
#define EXIT_H

#include "GenericEvent.h"

class Exit : public GenericEvent
{
public:
	Exit() { type = EV_EXIT; }
};


#endif // !EXIT_H
