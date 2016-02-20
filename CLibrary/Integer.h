#ifndef INTEGER_INCLUDED
#define	INTEGER_INCLUDED

#include "String.h"
#include <stdbool.h>

#define Integer_MAX_VALUE 2147483647
#define Integer_MIN_VALUE -2147483648

typedef struct {
    int v;
} Integer;

Integer *new_Integer(int value);
int intValue(Integer *ptr);
int compareToI(Integer *ptr, Integer *anotherInteger);
bool equalsI(Integer *ptr, Integer *obj);
String *toStringI(Integer *ptr);
String *Integer_toString(int i);
int Integer_parseInt(String *s);

#endif	/* INTEGER_INCLUDED */
