#ifndef LONG_INCLUDED
#define LONG_INCLUDED

#include "String.h"
#include <stdbool.h>
#include <stdint.h>

/**
 * The Long struct wraps a value of the type int64_t, representing a long value.
 *
 * @author Petr Kozler (A13B0359P)
 */

/**
 * A constant holding the maximum value a long can have, 2^63-1.
 */
#define Long_MAX_VALUE 9223372036854775807LL
/**
 * A constant holding the minimum value a long can have, -2^63.
 */
#define Long_MIN_VALUE -9223372036854775808LL

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
