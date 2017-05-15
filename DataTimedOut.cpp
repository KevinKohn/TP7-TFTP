#include "DataTimedOut.h"

#include "Data.h"
#include "LastData.h"
#include "Error.h"
#include "Timeout.h"

#include "ClientReading.h"
#include "ClientIdle.h"



GenericState* DataTimedOut :: onData (GenericEvent * ev)
{
	((Data *)ev)->dataActions();

	return new Reading;
}

GenericState* DataTimedOut :: onLastData (GenericEvent * ev)
{
	((LastData *)ev)->lastDataActions();

	return new Idle;
}

GenericState* DataTimedOut :: onError (GenericEvent * ev)
{
	((Error *)ev)->readingError();

	return new Idle;
}

GenericState* DataTimedOut :: onTimeout	(GenericEvent *ev)
{
	((Timeout *)ev)->readingError();

	return new Idle;
}