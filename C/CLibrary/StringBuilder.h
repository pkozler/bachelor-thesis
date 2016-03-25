#ifndef STRINGBUILDER_INCLUDED
#define	STRINGBUILDER_INCLUDED

#include "String.h"
#include <stdint.h>

/**
 * A mutable sequence of characters.
 *
 * @author Petr Kozler (A13B0359P)
 */

typedef struct {
    char *buffer;
    int32_t count;
    int32_t capacity;
} StringBuilder;

StringBuilder *new_StringBuilder();
void delete_StringBuilder(StringBuilder *ptr);
StringBuilder *append(StringBuilder *ptr, String *str);
String *toStringSb(StringBuilder *ptr);

#endif	/* STRINGBUILDER_INCLUDED */