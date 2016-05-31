#ifndef SCANNER_INCLUDED
#define	SCANNER_INCLUDED

#include "String.h"
#include "System.h"
#include "String.h"
#include <stdint.h>

/**
 * A simple text scanner which can parse basic types and strings.
 *
 * @author Petr Kozler (A13B0359P)
 */

typedef struct {
    char *line;
} Scanner;

Scanner *new_Scanner(InputStream *source);
String *next(Scanner *ptr);
bool nextBoolean(Scanner *ptr);
int8_t nextByte(Scanner *ptr);
int16_t nextShort(Scanner *ptr);
int32_t nextInt(Scanner *ptr);
int64_t nextLong(Scanner *ptr);
float nextFloat(Scanner *ptr);
double nextDouble(Scanner *ptr);
String *nextLine(Scanner *ptr);

#endif	/* SCANNER_INCLUDED */
