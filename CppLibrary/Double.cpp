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

int32_t Double::compare(double v, double v2) {
    // porovnání hodnoty Not a Number
    if (std::isnan(v)) {
        // dvě NaN hodnoty se při tomto způsobu porovnání rovnají
        if (std::isnan(v2)) {
            return 0;
        }

        return 1;
    }

    // hodnota NaN je větší než jakákoliv jiná hodnota (včetně kladného nekonečna)
    if (std::isnan(v2)) {
        return -1;
    }

    DoubleInt64 vBits, v2Bits;
    vBits.val = v;
    v2Bits.val = v2;
    int64_t negativeZeroBits = getNegativeZeroBits();

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

bool Double::equals(Double *obj) {
    if (obj == nullptr) {
        return false;
    }

    if (sizeof (*this) != sizeof (*obj)) {
        return false;
    }

    double v2 = obj->v;

    // porovnání hodnoty Not a Number (dvě NaN hodnoty se považují za shodné)
    if (std::isnan(v) && std::isnan(v2)) {
        return true;
    }

    DoubleInt64 vBits, v2Bits;
    vBits.val = v;
    v2Bits.val = v2;
    int64_t negativeZeroBits = getNegativeZeroBits();

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
