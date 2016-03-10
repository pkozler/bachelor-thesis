#include "Double.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define _MAX_DOUBLE_STRLEN 13

Double *new_Double(double value) {
    Double *d = malloc(sizeof (Double));
    d->v = value;

    return d;
}

long _getNegativeZeroDoubleBits() {
    DoubleInt64 bitConverter;
    bitConverter.val = -0.0;

    return bitConverter.bits;
}

double doubleValue(Double *ptr) {
    return ptr->v;
}

int32_t compareToD(Double *ptr, Double *anotherDouble) {
    return Double_compare(ptr->v, anotherDouble->v);
}

int32_t Double_compare(double d1, double d2) {
    if (isnan(d1)) {
        if (isnan(d2)) {
            return 0;
        }

        return 1;
    }

    if (isnan(d2)) {
        return -1;
    }

    DoubleInt64 vBits, v2Bits;
    vBits.val = d1;
    v2Bits.val = d2;
    int64_t negativeZeroBits = _getNegativeZeroDoubleBits();

    if (vBits.bits == 0
            && v2Bits.bits == negativeZeroBits) {
        return 1;
    }

    if (vBits.bits == negativeZeroBits
            && v2Bits.bits == 0) {
        return -1;
    }

    return (d1 > d2 ? 1 : d1 < d2 ? -1 : 0);
}

bool equalsD(Double *ptr, Double *obj) {
    if (ptr == obj) {
        return true;
    }

    if (ptr == NULL || obj == NULL) {
        return false;
    }

    if (sizeof (*ptr) != sizeof (*obj)) {
        return false;
    }

    double v = ptr->v;
    double v2 = obj->v;

    if (isnan(v) && isnan(v2)) {
        return true;
    }

    DoubleInt64 vBits, v2Bits;
    vBits.val = v;
    v2Bits.val = v2;
    int64_t negativeZeroBits = _getNegativeZeroDoubleBits();

    if (vBits.bits == negativeZeroBits) {
        return v2Bits.bits == negativeZeroBits;
    }

    if (v2Bits.bits == negativeZeroBits) {
        return vBits.bits == negativeZeroBits;
    }

    return (v == v2);
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
