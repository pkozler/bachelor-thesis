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
    float v = ptr->v;
    float v2 = anotherFloat->v;

    // porovnání hodnoty Not a Number
    if (isnan(v)) {
        // dvě NaN hodnoty se při tomto způsobu porovnání rovnají
        if (isnan(v2)) {
            return 0;
        }

        return 1;
    }

    // hodnota NaN je větší než jakákoliv jiná hodnota (včetně kladného nekonečna)
    if (isnan(v2)) {
        return -1;
    }

    FloatInt32 vBits, v2Bits;
    vBits.val = v;
    v2Bits.val = v2;
    int32_t negativeZeroBits = _getNegativeZeroFloatBits();

    // porovnání kladné a záporné nuly (kladná je vyhodnocena jako větší)
    if (vBits.bits == 0
            && v2Bits.bits == negativeZeroBits) {
        return 1;
    }

    // porovnání kladné a záporné nuly (obráceně)
    if (vBits.bits == negativeZeroBits
            && v2Bits.bits == 0) {
        return -1;
    }

    // běžné porovnání pro ostatní hodnoty
    return (v > v2 ? 1 : v < v2 ? -1 : 0);
}

bool equalsF(Float *ptr, Float *obj) {
    if (ptr == obj) {
        return true;
    }

    if (ptr == NULL || obj == NULL) {
        return false;
    }
    
    float v = ptr->v;
    float v2 = obj->v;

    // porovnání hodnoty Not a Number (dvě NaN hodnoty se považují za shodné)
    if (isnan(v) && isnan(v2)) {
        return true;
    }

    FloatInt32 vBits, v2Bits;
    vBits.val = v;
    v2Bits.val = v2;
    int32_t negativeZeroBits = _getNegativeZeroFloatBits();

    // porovnání kladné a záporné nuly (považují se za rozdílné hodnoty)
    if (vBits.bits == negativeZeroBits) {
        return v2Bits.bits == negativeZeroBits;
    }

    // porovnání kladné a záporné nuly (obráceně)
    if (v2Bits.bits == negativeZeroBits) {
        return vBits.bits == negativeZeroBits;
    }

    // běžné vyhodnocení rovnosti pro ostatní hodnoty
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
