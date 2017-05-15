#include "KeyboardEvGen.h"

#include <cstring>

#include "Help.h"
#include "MakeWrq.h"
#include "MakeRrq.h"
#include "Exit.h"

extern "C" {
#include "moreString.h"
#include <conio.h>
}


#define	DEST_DIRECTORY	"downloads/"

#define ESCAPE_KEY		27

using namespace std;


KeyboardEvGen :: KeyboardEvGen()
{
	nWordsReceived = 0;
	strLen = 0;
	buffer[0] = '\0';
}

GenericEvent * KeyboardEvGen :: getNextEvent()
{
	GenericEvent * newEv = NULL;	//solo cambiara si llega algo valido
	bool endLine = false;
	char key;


	while (kbhit()) { 
		// obtener todo lo que se escribio desde la ultima vez
		key = getch();

		//procesar key solo si el input es valido
		if ( strLen < MAX_INPUT_LEN && endLine == false && nWordsReceived < 2 ) {
			switch (key) {
				case '\n': {
					endLine = true;
					nWordsReceived++;
					key = '\0';
				}
				break;

				case '\0': {
					nWordsReceived++;
				}
				break;		
			}

			buffer[strLen++] = key;
		}
	}

	if (endLine == true) {
		toLowercase(buffer,buffer, MAX_INPUT_LEN);

		switch(nWordsReceived) {
			case 1: {
				if(!strcmp(buffer, "help")) {
					newEv = new Help;
				}
				else if (buffer[0] == ESCAPE_KEY)
					newEv = new Exit;
				else
					newEv = new InputError(nWordsReceived, buffer);
			}
			break;

			case 2: {
				char fileName[MAX_INPUT_LEN] = {DEST_DIRECTORY};
				strncat(fileName, &(buffer[strlen(buffer)]), MAX_INPUT_LEN - strlen(DEST_DIRECTORY) - 1);

				if(!strcmp(buffer, "put")) {
					ifstream * f = new ifstream(&fileName[0]);
					if(f->good()) {
						newEv = new MakeWrq(f, &fileName[0]);
					}
					else
						newEv = new InputError(buffer);
				}
				else if(!strcmp(buffer, "get")) {
					ofstream * f = new ofstream (&fileName[0]);
					if(f->good())
						newEv = new MakeRrq(f, &fileName[0]);
					else
						newEv = new InputError(nWordsReceived, buffer);
				}
				else
				newEv = new InputError(nWordsReceived, buffer);
			}
			break;

			default: {
				newEv = new InputError(nWordsReceived, buffer);
			}
			break;
		}


		nWordsReceived = 0;
		strLen = 0;
	}
	return newEv;
}
