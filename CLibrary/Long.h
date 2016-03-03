#ifndef LONG_INCLUDED
#define LONG_INCLUDED

#include "String.h"
#include <stdbool.h>
#include <stdint.h>

#define Long_MAX_VALUE 9223372036854775807
#define Long_MIN_VALUE -9223372036854775808

typedef struct {
    int64_t v;
} Long;

Long *new_Long(int64_t value);
int64_t longValue(Long *ptr);
int32_t compareToL(Long *ptr, Long *anotherLong);
int32_t Long_compare(int64_t x, int64_t y);
bool equalsL(Long *ptr, Long *obj);
String *toStringL(Long *ptr);
String *Long_toString(int64_t l);
int64_t Long_parseLong(String *s);

#endif /* LONG_INCLUDED */
