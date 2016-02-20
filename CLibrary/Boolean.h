#ifndef BOOLEAN_INCLUDED
#define BOOLEAN_INCLUDED

#include "String.h"
#include <stdbool.h>

typedef struct {
    bool v;
} Boolean;

Boolean *new_Boolean(bool value);
bool booleanValue(Boolean *ptr);
int compareToBool(Boolean *ptr, Boolean *anotherBoolean);
bool equalsBool(Boolean *ptr, Boolean *obj);
String *toStringBool(Boolean *ptr);
String *Boolean_toString(bool b);
bool Boolean_parseBoolean(String *s);

#endif /* BOOLEAN_INCLUDED */
