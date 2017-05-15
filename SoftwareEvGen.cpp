#include <ctime>
#include "SoftwareEvGen.h"

#include "LastPaqSent.h"
#include "Timeout.h"

using namespace std;


SoftwareEvGen::SoftwareEvGen()
{
	reachedEOF = false;
}

GenericEvent * SoftwareEvGen::getNextEvent()
{
	GenericEvent * newEv = NULL;	//solo cambiara si hay un evento


	if ((clock() - tInicial) > 60 * CLOCKS_PER_SEC)
	{
		newEv = new Timeout;
		tInicial = clock();	//para que no se manden muchos timeouts seguidos
	}

	if (reachedEOF == true) {
		newEv = new LastPaqSent;
	}

	return newEv;
}

void SoftwareEvGen::StartTimer()
{	
	tInicial = clock();		//se fija una hora concreta para el comienzo del timer
}