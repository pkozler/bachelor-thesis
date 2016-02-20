#ifndef LONG_INCLUDED
#define LONG_INCLUDED

#include "String.h"
#include <stdbool.h>

#define Long_MAX_VALUE 9223372036854775807
#define Long_MIN_VALUE -9223372036854775808

typedef struct {
    long v;
} Long;

Long *new_Long(long value);
long longValue(Long *ptr);
int compareToL(Long *ptr, Long *anotherLong);
bool equalsL(Long *ptr, Long *obj);
String *toStringL(Long *ptr);
String *Long_toString(long l);
long Long_parseLong(String *s);

#endif /* LONG_INCLUDED */
