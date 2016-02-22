#include "Double.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define _MAX_DOUBLE_STRLEN 13

Double *new_Double(double value) {
    Double *d = malloc(sizeof(Double));
    d->v = value;

    return d;
}

double doubleValue(Double *ptr) {
    return ptr->v;
}

int32_t compareToD(Double *ptr, Double *anotherDouble) {
    double val = ptr->v - anotherDouble->v;

    if (val > 0) {
        return ceil(val);
    }
    else if (val < 0) {
        return floor(val);
    }
    else {
        return 0;
    }
}

bool equalsD(Double *ptr, Double *obj) {
    if (ptr == obj) {
        return true;
    }

    if (ptr == NULL || obj == NULL) {
        return false;
    }

    return (ptr->v == obj->v);
}

String *toStringD(Double *ptr) {
    return Double_toString(ptr->v);
}

String *Double_toString(double d) {
    char *str = malloc(_MAX_DOUBLE_STRLEN + 1);
    char buf[_MAX_DOUBLE_STRLEN];

    str[0] = '\0';
    sprintf(buf, "%lG", d);
    strcat(str, buf);

    return new_String(str);
}

double Double_parseDouble(String *s) {
    return strtod(s->s, NULL);
}
