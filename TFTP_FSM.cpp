#include "TFTP_FSM.h"

void TFTP_FSM :: dispatch(GenericEvent& ev)
{
	GenericState * newState = NULL;
	
	switch (ev.getType()) { //llamar a la reaction routine que indique el evento
		case EV_DATA:
			newState = currentState->onData(&ev);
		break;

		case EV_LAST_DATA:
			newState = currentState->onLastData(&ev);
		break;

		case EV_ACK:
			newState = currentState->onAck(&ev);
		break;
				
		case EV_TIMEOUT:
			newState = currentState->onTimeout(&ev);
		break;
				
		case EV_ERROR:
			newState = currentState->onError(&ev);
		break;

		case EV_MAKE_RRQ:
			newState = currentState->onMakeRrq(&ev);
		break;

		case EV_MAKE_WRQ:
			newState = currentState->onMakeWrq(&ev);
		break;
#if I_AM == SERVER
		case RRQ:
			newState = currentState->onRrq(&ev);
		break;

		case WRQ:
			newState = currentState->onWrq(&ev);
		break;
#endif
	}

	if (newState != NULL)
	{
		delete currentState;
		currentState = newState;
	}
}