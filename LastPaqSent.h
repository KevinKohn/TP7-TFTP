#ifndef LAST_PAQ_SENT_H
#define LAST_PAQ_SENT_H

#include "GenericEvent.h"

class LastPaqSent : public GenericEvent
{
public:
	LastPaqSent() { type = EV_LAST_PAQ_SENT; }

};

#endif // !LAST_PAQ_SENT_H
