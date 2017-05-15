#ifndef TFTP_FSM_H
#define	TFTP_FSM_H
#include "GenericFSM.h"

class TFTP_FSM : public GenericFSM
{
public:
	virtual void dispatch(GenericEvent& ev);
};


#endif //TFTP_FSM_H