#ifndef FLOAT_INCLUDED
#define FLOAT_INCLUDED

#include "String.h"
#include <cstdint>

typedef union {
    float val;
    int32_t bits;
} FloatInt32;

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
    ~Float();
    float floatValue();
    int32_t compareTo(Float *anotherFloat);
    bool equals(Float *obj);
    String *toString();
    static String *toString(float f);
    static float parseFloat(String *s);
    friend std::ostream &operator<<(std::ostream &s, Float &obj);
};

#endif // FLOAT_INCLUDED
