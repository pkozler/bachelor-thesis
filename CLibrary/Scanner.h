#ifndef SCANNER_INCLUDED
#define	SCANNER_INCLUDED

#include "String.h"
#include <stdint.h>

/**
 * A simple text scanner which can parse primitive types and strings using regular expressions.
 *
 * @author Petr Kozler (A13B0359P)
 */

String *next();
bool nextBoolean();
int8_t nextByte();
int16_t nextShort();
int32_t nextInt();
int64_t nextLong();
float nextFloat();
double nextDouble();
String *nextLine();

#endif	/* SCANNER_INCLUDED */
