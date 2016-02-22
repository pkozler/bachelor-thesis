#ifndef INTEGER_INCLUDED
#define	INTEGER_INCLUDED

#include "String.h"
#include <stdbool.h>
#include <stdint.h>

#define Integer_MAX_VALUE 2147483647
#define Integer_MIN_VALUE -2147483648

typedef struct {
    int32_t v;
} Integer;

Integer *new_Integer(int32_t value);
int32_t intValue(Integer *ptr);
int32_t compareToI(Integer *ptr, Integer *anotherInteger);
bool equalsI(Integer *ptr, Integer *obj);
String *toStringI(Integer *ptr);
String *Integer_toString(int32_t i);
int32_t Integer_parseInt(String *s);

#endif	/* INTEGER_INCLUDED */
