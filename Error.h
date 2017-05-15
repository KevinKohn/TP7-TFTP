#ifndef ERROR_H
#define	ERROR_H

#include "GenericEvent.h"

class Error : public GenericEvent
{
private:
	unsigned int errorCode;
public:
	Error(unsigned int code);

	
};


#endif //ERROR_H