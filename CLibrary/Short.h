#ifndef SHORT_INCLUDED
#define SHORT_INCLUDED

#include "String.h"
#include <stdbool.h>
#include <stdint.h>

#define Short_MAX_VALUE 32767
#define Short_MIN_VALUE -32768

typedef struct {
    int16_t v;
} Short;

Short *new_Short(int16_t value);
int16_t shortValue(Short *ptr);
int32_t compareToS(Short *ptr, Short *anotherShort);
int32_t Short_compare(int16_t x, int16_t y);
bool equalsS(Short *ptr, Short *obj);
String *toStringS(Short *ptr);
String *Short_toString(int16_t s);
int16_t Short_parseShort(String *s);

#endif /* SHORT_INCLUDED */
