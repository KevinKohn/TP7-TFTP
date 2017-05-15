#include "EventGenerator.h"


GenericEvent * EventGenerator :: getNextEvent()
{
	GenericEvent * newEv;

	if(buffer.isFull())	{ //no seguir escribiendo en el buffer si ya esta lleno
		newEv = buffer.read();
		newEv->setEvInfo(&i);
		return newEv;
	}

	if((newEv = i.keyboard->getNextEvent())!= NULL) {
		buffer.write(newEv);

		if(buffer.isFull())	{ 
			newEv = buffer.read();
			newEv->setEvInfo(&i);
			return newEv;
		}
	}

	if((newEv = i.software->getNextEvent())!=NULL) {
		buffer.write(newEv);
		
		if(buffer.isFull()){ 
			newEv = buffer.read();
			newEv->setEvInfo(&i);
			return newEv;
		}
	}

	if((newEv = i.networking->getNextEvent())!=NULL) {
		buffer.write(newEv);
	}

	if (buffer.isEmpty())
		return NULL;
	else { 
		newEv = buffer.read();
		newEv->setEvInfo(&i);
		return newEv;
	}
}
