#include "Float.h"

#include <string>
#include <cmath>

const float Float::POSITIVE_INFINITY = 1.0f / 0.0f;
const float Float::NEGATIVE_INFINITY = -1.0f / 0.0f;
const float Float::NaN = 0.0f / 0.0f;
const float Float::MAX_VALUE = 3.4028235e+38f;
const float Float::MIN_VALUE = 1.4e-45f;
const int32_t Float::MAX_EXPONENT = 127;
const int32_t Float::MIN_EXPONENT = -126;
const float Float::MIN_NORMAL = 1.17549435e-38f;

Float::Float(float value) {
    v = value;
}

Float::~Float() {
}

int32_t Float::getNegativeZeroBits() {
    FloatInt32 bitConverter;
    bitConverter.val = -0.0;
    
    return bitConverter.bits;
}

float Float::floatValue() {
    return v;
}

int32_t Float::compareTo(Float *anotherFloat) {
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
    int32_t negativeZeroBits = getNegativeZeroBits();

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

bool Float::equals(Float *obj) {
    if (obj == nullptr) {
        return false;
    }

    float v2 = obj->v;

    // porovnání hodnoty Not a Number (dvě NaN hodnoty se považují za shodné)
    if (isnan(v) && isnan(v2)) {
        return true;
    }

    FloatInt32 vBits, v2Bits;
    vBits.val = v;
    v2Bits.val = v2;
    int32_t negativeZeroBits = getNegativeZeroBits();

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

String *Float::toString() {
    return toString(v);
}

String *Float::toString(float f) {
    return new String(std::to_string(f));
}

float Float::parseFloat(String *s) {
    return std::stof(s->toString(), nullptr);
}

std::ostream &operator<<(std::ostream &s, Float &obj) {
    return s << obj.toString()->toString().c_str();
}
