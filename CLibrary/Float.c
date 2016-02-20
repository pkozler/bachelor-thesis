#include "Float.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define _MAX_FLOAT_STRLEN 12

Float *new_Float(float value) {
    Float *f = malloc(sizeof(Float));
    f->v = value;

    return f;
}

float floatValue(Float *ptr) {
    return ptr->v;
}

int compareToF(Float *ptr, Float *anotherFloat) {
    float val = ptr->v - anotherFloat->v;

    if (val > 0) {
        return ceilf(val);
    }
    else if (val < 0) {
        return floorf(val);
    }
    else {
        return 0;
    }
}

bool equalsF(Float *ptr, Float *obj) {
    if (ptr == obj) {
        return true;
    }

    if (ptr == NULL || obj == NULL) {
        return false;
    }

    return (ptr->v == obj->v);
}

String *toStringF(Float *ptr) {
    return Float_toString(ptr->v);
}

String *Float_toString(float f) {
    char *str = malloc(_MAX_FLOAT_STRLEN + 1);
    char buf[_MAX_FLOAT_STRLEN];

    str[0] = '\0';
    sprintf(buf, "%G", f);
    strcat(str, buf);

    return new_String(str);
}

float Float_parseFloat(String *s) {
    return strtof(s->s, NULL);
}
