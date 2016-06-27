#ifndef SCANNER_INCLUDED
#define	SCANNER_INCLUDED

#include "String_.h"
#include "System.h"
#include <stdint.h>

/**
 * A simple text scanner which can parse basic types and strings.
 *
 * @author Petr Kozler (A13B0359P)
 */

typedef struct {
    // current line
    char *line;
} Scanner;

Scanner *new_Scanner(InputStream *source);
void delete_Scanner(Scanner *ptr);
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
