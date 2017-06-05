//здесь объявление функций
#include "Creceiver.h"
#include "CifcWallSweptSolid.h"

bool IFCInterpreterInterface OpenRepository(char *IFCName);
int IFCInterpreterInterface ReadSTEPFile(char *IFCName);
int IFCInterpreterInterface getProjects(Creceiver *Receiver);
