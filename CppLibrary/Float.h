#ifndef FLOAT_INCLUDED
#define FLOAT_INCLUDED

#include "String.h"
#include <cstdint>

typedef union {
    float val;
    int32_t bits;
} FloatInt32;

/**
 * The Float class wraps a value of primitive type float in an object.
 *
 * @author Petr Kozler (A13B0359P)
 */
class Float {
    float v;
    static int32_t getNegativeZeroBits();
public:
    static const float POSITIVE_INFINITY;
    static const float NEGATIVE_INFINITY;
    static const float NaN;
    static const float MIN_VALUE;
    static const float MAX_VALUE;
    static const int32_t MAX_EXPONENT;
    static const int32_t MIN_EXPONENT;
    static const float MIN_NORMAL;
    Float(float value);
    float floatValue();
    int32_t compareTo(Float *anotherFloat);
    static int32_t compare(float f1, float f2);
    bool equals(Float *obj);
    String *toString();
    static String *toString(float f);
    static float parseFloat(String *s);
    friend std::ostream &operator<<(std::ostream &s, Float &obj);
};

#endif // FLOAT_INCLUDED
