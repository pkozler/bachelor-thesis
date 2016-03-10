#include "Double.h"

#include <string>
#include <cmath>

const double Double::POSITIVE_INFINITY = 1.0 / 0.0;
const double Double::NEGATIVE_INFINITY = -1.0 / 0.0;
const double Double::NaN = 0.0 / 0.0;
const double Double::MAX_VALUE = 1.7976931348623157e+308;
const double Double::MIN_VALUE = 4.9e-324;
const int32_t Double::MAX_EXPONENT = 1023;
const int32_t Double::MIN_EXPONENT = -1022;
const double Double::MIN_NORMAL = 2.2250738585072014e-308;

Double::Double(double value) {
    v = value;
}

Double::~Double() {
    // really no code
}

int64_t Double::getNegativeZeroBits() {
    DoubleInt64 bitConverter;
    bitConverter.val = -0.0;

    return bitConverter.bits;
}

double Double::doubleValue() {
    return v;
}

int32_t Double::compareTo(Double *anotherDouble) {
    return compare(v, anotherDouble->v);
}

int32_t Double::compare(double d1, double d2) {
    if (std::isnan(d1)) {
        if (std::isnan(d2)) {
            return 0;
        }

        return 1;
    }

    if (std::isnan(d2)) {
        return -1;
    }

    DoubleInt64 vBits, v2Bits;
    vBits.val = d1;
    v2Bits.val = d2;
    int64_t negativeZeroBits = getNegativeZeroBits();

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

bool Double::equals(Double *obj) {
    if (obj == nullptr) {
        return false;
    }

    if (sizeof (*this) != sizeof (*obj)) {
        return false;
    }

    double v2 = obj->v;

    if (std::isnan(v) && std::isnan(v2)) {
        return true;
    }

    DoubleInt64 vBits, v2Bits;
    vBits.val = v;
    v2Bits.val = v2;
    int64_t negativeZeroBits = getNegativeZeroBits();

    if (vBits.bits == negativeZeroBits) {
        return v2Bits.bits == negativeZeroBits;
    }

    if (v2Bits.bits == negativeZeroBits) {
        return vBits.bits == negativeZeroBits;
    }

    return (v == v2);
}

String *Double::toString() {
    return toString(v);
}

String *Double::toString(double d) {
    return new String(std::to_string(d));
}

double Double::parseDouble(String *s) {
    return std::stod(s->toString(), nullptr);
}

std::ostream &operator<<(std::ostream &s, Double &obj) {
    return s << obj.toString()->toString().c_str();
}
