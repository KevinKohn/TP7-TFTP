#ifndef HELP_H
#define HELP_H

#include "GenericEvent.h"

class Help : public GenericEvent 
{
private:
public:
	Help() { type = EV_HELP; }
};

#endif //HELP_H
