#include "Float.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define _MAX_FLOAT_STRLEN 12

Float *new_Float(float value) {
    Float *f = malloc(sizeof (Float));
    f->v = value;

    return f;
}

long _getNegativeZeroFloatBits() {
    FloatInt32 bitConverter;
    bitConverter.val = -0.0;

    return bitConverter.bits;
}

float floatValue(Float *ptr) {
    return ptr->v;
}

int32_t compareToF(Float *ptr, Float *anotherFloat) {
    return Float_compare(ptr->v, anotherFloat->v);
}

int32_t Float_compare(float f1, float f2) {
    if (isnan(f1)) {
        if (isnan(f2)) {
            return 0;
        }

        return 1;
    }

    if (isnan(f2)) {
        return -1;
    }

    FloatInt32 vBits, v2Bits;
    vBits.val = f1;
    v2Bits.val = f2;
    int32_t negativeZeroBits = _getNegativeZeroFloatBits();

    if (vBits.bits == 0
            && v2Bits.bits == negativeZeroBits) {
        return 1;
    }

    if (vBits.bits == negativeZeroBits
            && v2Bits.bits == 0) {
        return -1;
    }

    return (f1 > f2 ? 1 : f1 < f2 ? -1 : 0);
}

bool equalsF(Float *ptr, Float *obj) {
    if (ptr == obj) {
        return true;
    }

    if (ptr == NULL || obj == NULL) {
        return false;
    }

    if (sizeof (*ptr) != sizeof (*obj)) {
        return false;
    }

    float v = ptr->v;
    float v2 = obj->v;

    if (isnan(v) && isnan(v2)) {
        return true;
    }

    FloatInt32 vBits, v2Bits;
    vBits.val = v;
    v2Bits.val = v2;
    int32_t negativeZeroBits = _getNegativeZeroFloatBits();

    if (vBits.bits == negativeZeroBits) {
        return v2Bits.bits == negativeZeroBits;
    }

    if (v2Bits.bits == negativeZeroBits) {
        return vBits.bits == negativeZeroBits;
    }

    return (v == v2);
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
