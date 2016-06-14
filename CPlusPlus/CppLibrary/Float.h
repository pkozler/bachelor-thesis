#ifndef FLOAT_INCLUDED
#define FLOAT_INCLUDED

#include "String_.h"
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
class Float : public Comparable {
    float v;
    static int32_t getNegativeZeroBits();
public:
    /**
     * A constant holding the positive infinity of type float.
     */
    static const float POSITIVE_INFINITY;
    
    /**
     * A constant holding the negative infinity of type float.
     */
    static const float NEGATIVE_INFINITY;
    
    /**
     * A constant holding a Not-a-Number (NaN) value of type float.
     */
    static const float NaN;
    
    /**
     * A constant holding the largest positive finite value of type float, (2-2^-23)·2^127.
     */
    static const float MIN_VALUE;
    
    /**
     * A constant holding the smallest positive nonzero value of type float, 2-^149.
     */
    static const float MAX_VALUE;
    
    /**
     * Maximum exponent a finite float variable may hav
     */
    static const int32_t MAX_EXPONENT;
    
    /**
     * Minimum exponent a normalized float variable may have.
     */
    static const int32_t MIN_EXPONENT;
    
    /**
     * A constant holding the smallest positive normal value of type float, 2^-126.
     */
    static const float MIN_NORMAL;
    
    Float(float value);
    float floatValue();
    int32_t compareTo(Object *anotherFloat);
    static int32_t compare(float f1, float f2);
    bool equals(Object *obj);
    String *toString();
    static String *toString(float f);
    static float parseFloat(String *s);
};

#endif // FLOAT_INCLUDED
