#include "Timeout.h"

Timeout::Timeout() : Error(EV_TIMEOUT)
{
	type = EV_TIMEOUT;
};