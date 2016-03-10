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
    // really no code
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
    return compare(v, anotherFloat->v);
}

int32_t Float::compare(float f1, float f2) {
    if (std::isnan(f1)) {
        if (std::isnan(f2)) {
            return 0;
        }

        return 1;
    }

    if (std::isnan(f2)) {
        return -1;
    }

    FloatInt32 vBits, v2Bits;
    vBits.val = f1;
    v2Bits.val = f2;
    int32_t negativeZeroBits = getNegativeZeroBits();

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

bool Float::equals(Float *obj) {
    if (obj == nullptr) {
        return false;
    }

    if (sizeof (*this) != sizeof (*obj)) {
        return false;
    }

    float v2 = obj->v;

    if (std::isnan(v) && std::isnan(v2)) {
        return true;
    }

    FloatInt32 vBits, v2Bits;
    vBits.val = v;
    v2Bits.val = v2;
    int32_t negativeZeroBits = getNegativeZeroBits();

    if (vBits.bits == negativeZeroBits) {
        return v2Bits.bits == negativeZeroBits;
    }

    if (v2Bits.bits == negativeZeroBits) {
        return vBits.bits == negativeZeroBits;
    }

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
