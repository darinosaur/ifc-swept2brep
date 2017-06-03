#pragma once
#include "sdai.h"

SdaiString UnicodeRead(SdaiString UniCode);
unsigned int UnicodeToInt(char Up,char Mid, char Down);
char UnicodeGetLetter(unsigned int DigitalValue);
bool FindUnicode(SdaiString UniCode);
