#ifndef GenericState_h
#define GenericState_h

#include <cstdio>
#include "GenericEvent.h"



class GenericState
{
public:
#if I_AM == CLIENT
	virtual GenericState* onMakeRrq		(GenericEvent *)	{return NULL;}
    virtual GenericState* onMakeWrq		(GenericEvent *)	{return NULL;}
#else
	virtual GenericState* onRrq			(GenericEvent *)	{return NULL;}
    virtual GenericState* onWrq			(GenericEvent *)	{return NULL;}
#endif
    virtual GenericState* onData		(GenericEvent *)	{return NULL;}
    virtual GenericState* onLastData	(GenericEvent *)	{return NULL;}
    virtual GenericState* onAck			(GenericEvent *)	{return NULL;}
    virtual GenericState* onTimeout		(GenericEvent *)	{return NULL;}
    virtual GenericState* onError		(GenericEvent *)	{return NULL;}
	virtual GenericState* onLastPaqSent (GenericEvent *)	{return NULL;}
};


#endif /* GenericState_h */

