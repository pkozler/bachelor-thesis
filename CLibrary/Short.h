#ifndef SHORT_INCLUDED
#define SHORT_INCLUDED

#include "String.h"
#include <stdbool.h>

#define Short_MAX_VALUE 32767
#define Short_MIN_VALUE -32768

typedef struct {
    short v;
} Short;

Short *new_Short(short value);
short shortValue(Short *ptr);
int compareToS(Short *ptr, Short *anotherShort);
bool equalsS(Short *ptr, Short *obj);
String *toStringS(Short *ptr);
String *Short_toString(short s);
short Short_parseShort(String *s);

#endif /* SHORT_INCLUDED */
