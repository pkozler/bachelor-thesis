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

int32_t Double_compare(double v, double v2) {
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

    DoubleInt64 vBits, v2Bits;
    vBits.val = v;
    v2Bits.val = v2;
    int64_t negativeZeroBits = _getNegativeZeroDoubleBits();

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

    // porovnání hodnoty Not a Number (dvě NaN hodnoty se považují za shodné)
    if (isnan(v) && isnan(v2)) {
        return true;
    }

    DoubleInt64 vBits, v2Bits;
    vBits.val = v;
    v2Bits.val = v2;
    int64_t negativeZeroBits = _getNegativeZeroDoubleBits();

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
