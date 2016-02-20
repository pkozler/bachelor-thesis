#ifndef FLOAT_INCLUDED
#define FLOAT_INCLUDED

#include "String.h"
#include <stdbool.h>

#define Float_MAX_VALUE 3.4028235e+38f
#define Float_MIN_VALUE 1.4e-45f

typedef struct {
    float v;
} Float;

Float *new_Float(float value);
float floatValue(Float *ptr);
int compareToF(Float *ptr, Float *anotherFloat);
bool equalsF(Float *ptr, Float *obj);
String *toStringF(Float *ptr);
String *Float_toString(float f);
float Float_parseFloat(String *s);

#endif /* FLOAT_INCLUDED */
