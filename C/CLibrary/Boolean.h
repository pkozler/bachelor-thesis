#ifndef BOOLEAN_INCLUDED
#define BOOLEAN_INCLUDED

#include "String_.h"
#include <stdbool.h>
#include <stdint.h>

/**
 * The Boolean struct wraps a value of the type bool, representing a boolean value.
 *
 * @author Petr Kozler (A13B0359P)
 */

typedef struct {
    bool v;
} Boolean;

Boolean *new_Boolean(bool value);
bool booleanValue(Boolean *ptr);
int32_t compareToBool(Boolean *ptr, Boolean *b);
int32_t Boolean_compare(bool x, bool y);
bool equalsBool(Boolean *ptr, Boolean *obj);
String *toStringBool(Boolean *ptr);
String *Boolean_toString(bool b);
bool Boolean_parseBoolean(String *s);

#endif /* BOOLEAN_INCLUDED */
