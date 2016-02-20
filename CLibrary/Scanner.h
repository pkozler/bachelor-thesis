#ifndef SCANNER_INCLUDED
#define	SCANNER_INCLUDED

#include "String.h"

String *next();
bool nextBoolean();
char nextByte();
short nextShort();
int nextInt();
long nextLong();
float nextFloat();
double nextDouble();
String *nextLine();

#endif	/* SCANNER_INCLUDED */
