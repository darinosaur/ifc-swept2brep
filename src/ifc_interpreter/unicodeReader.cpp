#include "stdafx.h"
#include "unicodeReader.h"
#include "sdai.h"

SdaiString UnicodeRead(SdaiString UniCode)
	//проверка на юникод
	//int UnicodeRead(SdaiString  UniCode,int index,char toRusString);
{
	SdaiString toRusString = new char[1024];
	//

	unsigned int DigitalValue = 0; 
	int i = 0; //место в выходной строке
	memset(toRusString,0,1024);

	int index = 0;
	for (; index < 1024 ; index++)
	{

		if ((UniCode[index+1] == 'X')&&(UniCode[index+2] == '2'))

			//UnicodeTranslater(UniCode, index + 4)
			for (int pos1 = index + 5;;)
				//
			{
				/*if((UniCode[pos1+1] != 'X')&&(UniCode[pos1+2] == '0'))*/
				if(UniCode[pos1] != 'X')
				{
					DigitalValue = UnicodeToInt(UniCode[pos1],UniCode[pos1+1],UniCode[pos1+2]);
					toRusString[i] = UnicodeGetLetter(DigitalValue);
					i++;
					pos1 += 4;
				}
				else
				{
					toRusString[i] = ' ';
					i++;
					index += 3 + pos1;
					break;
				}
			}
		else
		{
			index = 1024;
			break;
		}
	}





	return toRusString;
}

unsigned int UnicodeToInt(char Up, char Mid, char Down)
{
	unsigned int DigitalValue = 0;

	switch(Up)
	{
	case '0':
		{
			DigitalValue = 0;
		}
		break;
	case '1':
		{
			DigitalValue = 16;
		}
		break;
	case '2':
		{
			DigitalValue = 32;
		}
		break;
	case '3':
		{
			DigitalValue = 48;
		}
		break;
	case '4':
		{
			DigitalValue = 64;
		}
		break;
	case '5':
		{
			DigitalValue = 80;
		}
		break;
	case '6':
		{
			DigitalValue = 96;
		}
		break;
	case '7':
		{
			DigitalValue = 112;
		}
		break;
	case '8':
		{
			DigitalValue = 128;
		}
		break;
	case '9':
		{
			DigitalValue = 144;
		}
		break;
	case 'A':
		{
			DigitalValue = 160;
		}
		break;
	case 'B':
		{
			DigitalValue = 176;
		}
		break;
	case 'C':
		{
			DigitalValue = 192;
		}
		break;
	case 'D':
		{
			DigitalValue = 208;
		}
		break;
	case 'E':
		{
			DigitalValue = 224;
		}
		break;
	case 'F':
		{
			DigitalValue = 240;
		}
		break;
	}
	switch(Mid)
	{
	case '0':
		{
		}
		break;
	case '1':
		{
			DigitalValue += 1;
		}
		break;
	case '2':
		{
			DigitalValue += 2;
		}
		break;
	case '3':
		{
			DigitalValue += 3;
		}
		break;
	case '4':
		{
			DigitalValue += 4;
		}
		break;
	case '5':
		{
			DigitalValue += 5;
		}
		break;
	case '6':
		{
			DigitalValue += 6;
		}
		break;
	case '7':
		{
			DigitalValue += 7;
		}
		break;
	case '8':
		{
			DigitalValue += 8;
		}
		break;
	case '9':
		{
			DigitalValue += 9;
		}
		break;
	case 'A':
		{
			DigitalValue += 10;
		}
		break;
	case 'B':
		{
			DigitalValue += 11;
		}
		break;
	case 'C':
		{
			DigitalValue += 12;
		}
		break;
	case 'D':
		{
			DigitalValue += 13;
		}
		break;
	case 'E':
		{
			DigitalValue += 14;
		}
		break;
	case 'F':
		{
			DigitalValue += 15;
		}
		break;

	}

	DigitalValue *= 16;

	switch(Down)
	{
	case '0':
		{
		}
		break;
	case '1':
		{
			DigitalValue += 1;
		}
		break;
	case '2':
		{
			DigitalValue += 2;
		}
		break;
	case '3':
		{
			DigitalValue += 3;
		}
		break;
	case '4':
		{
			DigitalValue += 4;
		}
		break;
	case '5':
		{
			DigitalValue += 5;
		}
		break;
	case '6':
		{
			DigitalValue += 6;
		}
		break;
	case '7':
		{
			DigitalValue += 7;
		}
		break;
	case '8':
		{
			DigitalValue += 8;
		}
		break;
	case '9':
		{
			DigitalValue += 9;
		}
		break;
	case 'A':
		{
			DigitalValue += 10;
		}
		break;
	case 'B':
		{
			DigitalValue += 11;
		}
		break;
	case 'C':
		{
			DigitalValue += 12;
		}
		break;
	case 'D':
		{
			DigitalValue += 13;
		}
		break;
	case 'E':
		{
			DigitalValue += 14;
		}
		break;
	case 'F':
		{
			DigitalValue += 15;
		}
		break;

	}
	return DigitalValue;
}



char UnicodeGetLetter(unsigned int DigitalValue)
{
	char UnicodeLetter;
	switch(DigitalValue)
	{
	case 1040:
		{
			UnicodeLetter = 'А';
		}
		break;
	case 1041:
		{
			UnicodeLetter = 'Б';
		}
		break;
	case 1042:
		{
			UnicodeLetter = 'В';
		}
		break;
	case 1043:
		{
			UnicodeLetter = 'Г';
		}
		break;
	case 1044:
		{
			UnicodeLetter = 'Д';
		}
		break;
	case 1045:
		{
			UnicodeLetter = 'Е';
		}
		break;
	case 1046:
		{
			UnicodeLetter = 'Ж';
		}
		break;
	case 1047:
		{
			UnicodeLetter = 'З';
		}
		break;
	case 1048:
		{
			UnicodeLetter = 'И';
		}
		break;
	case 1049:
		{
			UnicodeLetter = 'Й';
		}
		break;
	case 1050:
		{
			UnicodeLetter = 'К';
		}
		break;
	case 1051:
		{
			UnicodeLetter = 'Л';
		}
		break;
	case 1052:
		{
			UnicodeLetter = 'М';
		}
		break;
	case 1053:
		{
			UnicodeLetter = 'Н';
		}
		break;
	case 1054:
		{
			UnicodeLetter = 'О';
		}
		break;
	case 1055:
		{
			UnicodeLetter = 'П';
		}
		break;
	case 1056:
		{
			UnicodeLetter = 'Р';
		}
		break;
	case 1057:
		{
			UnicodeLetter = 'С';
		}
		break;
	case 1058:
		{
			UnicodeLetter = 'Т';
		}
		break;
	case 1059:
		{
			UnicodeLetter = 'У';
		}
		break;
	case 1060:
		{
			UnicodeLetter = 'Ф';
		}
		break;
	case 1061:
		{
			UnicodeLetter = 'Х';
		}
		break;
	case 1062:
		{
			UnicodeLetter = 'Ц';
		}
		break;
	case 1063:
		{
			UnicodeLetter = 'Ч';
		}
		break;
	case 1064:
		{
			UnicodeLetter = 'Ш';
		}
		break;
	case 1065:
		{
			UnicodeLetter = 'Щ';
		}
		break;
	case 1066:
		{
			UnicodeLetter = 'Ъ';
		}
		break;
	case 1067:
		{
			UnicodeLetter = 'Ы';
		}
		break;
	case 1068:
		{
			UnicodeLetter = 'Ь';
		}
		break;
	case 1069:
		{
			UnicodeLetter = 'Э';
		}
		break;
	case 1070:
		{
			UnicodeLetter = 'Ю';
		}
		break;
	case 1071:
		{
			UnicodeLetter = 'Я';
		}
		break;
	case 1072:
		{
			UnicodeLetter = 'а';
		}
		break;
	case 1073:
		{
			UnicodeLetter = 'б';
		}
		break;
	case 1074:
		{
			UnicodeLetter = 'в';
		}
		break;
	case 1075:
		{
			UnicodeLetter = 'г';
		}
		break;
	case 1076:
		{
			UnicodeLetter = 'д';
		}
		break;
	case 1077:
		{
			UnicodeLetter = 'е';
		}
		break;
	case 1078:
		{
			UnicodeLetter = 'ж';
		}
		break;
	case 1079:
		{
			UnicodeLetter = 'з';
		}
		break;
	case 1080:
		{
			UnicodeLetter = 'и';
		}
		break;
	case 1081:
		{
			UnicodeLetter = 'й';
		}
		break;
	case 1082:
		{
			UnicodeLetter = 'к';
		}
		break;
	case 1083:
		{
			UnicodeLetter = 'л';
		}
		break;
	case 1084:
		{
			UnicodeLetter = 'м';
		}
		break;
	case 1085:
		{
			UnicodeLetter = 'н';
		}
		break;
	case 1086:
		{
			UnicodeLetter = 'о';
		}
		break;
	case 1087:
		{
			UnicodeLetter = 'п';
		}
		break;
	case 1088:
		{
			UnicodeLetter = 'р';
		}
		break;
	case 1089:
		{
			UnicodeLetter = 'с';
		}
		break;
	case 1090:
		{
			UnicodeLetter = 'т';
		}
		break;
	case 1091:
		{
			UnicodeLetter = 'у';
		}
		break;
	case 1092:
		{
			UnicodeLetter = 'ф';
		}
		break;
	case 1093:
		{
			UnicodeLetter = 'х';
		}
		break;
	case 1094:
		{
			UnicodeLetter = 'ц';
		}
		break;
	case 1095:
		{
			UnicodeLetter = 'ч';
		}
		break;
	case 1096:
		{
			UnicodeLetter = 'ш';
		}
		break;
	case 1097:
		{
			UnicodeLetter = 'щ';
		}
		break;
	case 1098:
		{
			UnicodeLetter = 'ъ';
		}
		break;
	case 1099:
		{
			UnicodeLetter = 'ы';
		}
		break;
	case 1100:
		{
			UnicodeLetter = 'ь';
		}
		break;
	case 1101:
		{
			UnicodeLetter = 'э';
		}
		break;
	case 1102:
		{
			UnicodeLetter = 'ю';
		}
		break;
	case 1103:
		{
			UnicodeLetter = 'я';
		}
		break;
	case 863:
		{
			UnicodeLetter = '_';
		}
		break;
	case 33:
		{
			UnicodeLetter = '!';
		}
		break;
		//case 34:
		//	{
		//		UnicodeLetter = ''';
		//	}
		//	break;
	case 35:
		{
			UnicodeLetter = '#';
		}
		break;
	case 36:
		{
			UnicodeLetter = '$';
		}
		break;
	case 37:
		{
			UnicodeLetter = '%';
		}
		break;
	case 38:
		{
			UnicodeLetter = '&';
		}
		break;
		/*case 39:
		{
		UnicodeLetter = ''';
		}
		break;*/
	case 40:
		{
			UnicodeLetter = '(';
		}
		break;
	case 41:
		{
			UnicodeLetter = ')';
		}
		break;
	case 42:
		{
			UnicodeLetter = '*';
		}
		break;
	case 43:
		{
			UnicodeLetter = '+';
		}
		break;
	case 44:
		{
			UnicodeLetter = ',';
		}
		break;
	case 45:
		{
			UnicodeLetter = '-';
		}
		break;
	case 46:
		{
			UnicodeLetter = '.';
		}
		break;
	case 47:
		{
			UnicodeLetter = '/';
		}
		break;
	case 48:
		{
			UnicodeLetter = '0';
		}
		break;
	case 49:
		{
			UnicodeLetter = '1';
		}
		break;
	case 50:
		{
			UnicodeLetter = '2';
		}
		break;
	case 51:
		{
			UnicodeLetter = '3';
		}
		break;
	case 52:
		{
			UnicodeLetter = '4';
		}
		break;
	case 53:
		{
			UnicodeLetter = '5';
		}
		break;
	case 54:
		{
			UnicodeLetter = '6';
		}
		break;
	case 55:
		{
			UnicodeLetter = '7';
		}
		break;
	case 56:
		{
			UnicodeLetter = '8';
		}
		break;
	case 57:
		{
			UnicodeLetter = '9';
		}
		break;
	case 58:
		{
			UnicodeLetter = ':';
		}
		break;
	case 59:
		{
			UnicodeLetter = ';';
		}
		break;
	case 60:
		{
			UnicodeLetter = '<';
		}
		break;
	case 61:
		{
			UnicodeLetter = '=';
		}
		break;
	case 62:
		{
			UnicodeLetter = '>';
		}
		break;
	case 63:
		{
			UnicodeLetter = '?';
		}
		break;
	case 64:
		{
			UnicodeLetter = '@';
		}
		break;
	case 65:
		{
			UnicodeLetter = 'A';
		}
		break;
	case 66:
		{
			UnicodeLetter = 'B';
		}
		break;
	case 67:
		{
			UnicodeLetter = 'C';
		}
		break;
	case 68:
		{
			UnicodeLetter = 'D';
		}
		break;
	case 69:
		{
			UnicodeLetter = 'E';
		}
		break;
	case 70:
		{
			UnicodeLetter = 'F';
		}
		break;
	case 71:
		{
			UnicodeLetter = 'G';
		}
		break;
	case 72:
		{
			UnicodeLetter = 'H';
		}
		break;
	case 73:
		{
			UnicodeLetter = 'I';
		}
		break;
	case 74:
		{
			UnicodeLetter = 'J';
		}
		break;
	case 75:
		{
			UnicodeLetter = 'K';
		}
		break;
	case 76:
		{
			UnicodeLetter = 'L';
		}
		break;
	case 77:
		{
			UnicodeLetter = 'M';
		}
		break;
	case 78:
		{
			UnicodeLetter = 'N';
		}
		break;
	case 79:
		{
			UnicodeLetter = 'O';
		}
		break;
	case 80:
		{
			UnicodeLetter = 'P';
		}
		break;
	case 81:
		{
			UnicodeLetter = 'Q';
		}
		break;
	case 82:
		{
			UnicodeLetter = 'R';
		}
		break;
	case 83:
		{
			UnicodeLetter = 'S';
		}
		break;
	case 84:
		{
			UnicodeLetter = 'T';
		}
		break;
	case 85:
		{
			UnicodeLetter = 'U';
		}
		break;
	case 86:
		{
			UnicodeLetter = 'V';
		}
		break;
	case 87:
		{
			UnicodeLetter = 'W';
		}
		break;
	case 88:
		{
			UnicodeLetter = 'X';
		}
		break;
	case 89:
		{
			UnicodeLetter = 'Y';
		}
		break;
	case 90:
		{
			UnicodeLetter = 'Z';
		}
		break;
	case 91:
		{
			UnicodeLetter = '[';
		}
		break;
		/*case 92:
		{
		UnicodeLetter = '\';
		}
		break;*/
	case 93:
		{
			UnicodeLetter = ']';
		}
		break;
	case 94:
		{
			UnicodeLetter = '^';
		}
		break;
	case 95:
		{
			UnicodeLetter = '_';
		}
		break;
	case 96:
		{
			UnicodeLetter = '`';
		}
		break;
	case 97:
		{
			UnicodeLetter = 'a';
		}
		break;
	case 98:
		{
			UnicodeLetter = 'b';
		}
		break;
	case 99:
		{
			UnicodeLetter = 'c';
		}
		break;
	case 100:
		{
			UnicodeLetter = 'd';
		}
		break;
	case 101:
		{
			UnicodeLetter = 'e';
		}
		break;
	case 102:
		{
			UnicodeLetter = 'f';
		}
		break;
	case 103:
		{
			UnicodeLetter = 'g';
		}
		break;
	case 104:
		{
			UnicodeLetter = 'h';
		}
		break;
	case 105:
		{
			UnicodeLetter = 'i';
		}
		break;
	case 106:
		{
			UnicodeLetter = 'j';
		}
		break;
	case 107:
		{
			UnicodeLetter = 'k';
		}
		break;
	case 108:
		{
			UnicodeLetter = 'l';
		}
		break;
	case 109:
		{
			UnicodeLetter = 'm';
		}
		break;
	case 110:
		{
			UnicodeLetter = 'n';
		}
		break;
	case 111:
		{
			UnicodeLetter = 'o';
		}
		break;
	case 112:
		{
			UnicodeLetter = 'p';
		}
		break;
	case 113:
		{
			UnicodeLetter = 'q';
		}
		break;
	case 114:
		{
			UnicodeLetter = 'r';
		}
		break;
	case 115:
		{
			UnicodeLetter = 's';
		}
		break;
	case 116:
		{
			UnicodeLetter = 't';
		}
		break;
	case 117:
		{
			UnicodeLetter = 'u';
		}
		break;
	case 118:
		{
			UnicodeLetter = 'v';
		}
		break;
	case 119:
		{
			UnicodeLetter = 'w';
		}
		break;
	case 120:
		{
			UnicodeLetter = 'x';
		}
		break;
	case 121:
		{
			UnicodeLetter = 'y';
		}
		break;
	case 122:
		{
			UnicodeLetter = 'z';
		}
		break;
	case 123:
		{
			UnicodeLetter = '{';
		}
		break;
	case 124:
		{
			UnicodeLetter = '|';
		}
		break;
	case 125:
		{
			UnicodeLetter = '}';
		}
		break;
	case 126:
		{
			UnicodeLetter = '~';
		}
		break;

	}
	return UnicodeLetter;
}

bool FindUnicode(SdaiString UniCode)
{
	char toRusString[1024] = "";
	int unicodePosition = 0;
	int i = 0;
	int unicodeJump = 0;
	for (int index = 0; index < 1024 ; index++)
	{
		if ((UniCode[index] == '//')&&(UniCode[index+1] == 'X')&&(UniCode[index+1] == '2'))
		{
			unicodePosition = index + 5;
			//unicodePosition = index + 1;
			//unicodeJump = UnicodeRead(UniCode, unicodePosition, &toRusString);
			//i += unicodeJump;
		}
		else
		{
			toRusString[i] = UniCode[index];
			i++;
			index++;
		}
	}
	return true;
	//return toRusString;
}