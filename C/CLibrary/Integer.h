#ifndef INTEGER_INCLUDED
#define	INTEGER_INCLUDED

#include "String_.h"
#include <stdbool.h>
#include <stdint.h>

/**
 * The Integer struct wraps a value of the type int32_t, representing an integer value.
 *
 * @author Petr Kozler (A13B0359P)
 */

/**
 * A constant holding the maximum value an int can have, 2^31-1.
 */
#define Integer_MAX_VALUE 2147483647
/**
 * A constant holding the minimum value an int can have, -2^31.
 */
#define Integer_MIN_VALUE -2147483648

typedef struct {
    int32_t v;
} Integer;

Integer *new_Integer(int32_t value);
int32_t intValue(Integer *ptr);
int32_t compareToI(Integer *ptr, Integer *anotherInteger);
int32_t Integer_compare(int32_t x, int32_t y);
bool equalsI(Integer *ptr, Integer *obj);
String *toStringI(Integer *ptr);
String *Integer_toString(int32_t i);
int32_t Integer_parseInt(String *s);

#endif	/* INTEGER_INCLUDED */
