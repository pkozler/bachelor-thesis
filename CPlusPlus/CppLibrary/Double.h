#ifndef DOUBLE_INCLUDED
#define DOUBLE_INCLUDED

#include "String_.h"
#include <cstdint>

typedef union {
    double val;
    int64_t bits;
} DoubleInt64;

/**
 * The Double class wraps a value of the primitive type double in an object.
 *
 * @author Petr Kozler (A13B0359P)
 */
class Double : public Comparable<Double> {
    double v;
    static int64_t getNegativeZeroBits();
public:
    /**
     * A constant holding the positive infinity of type double.
     */
    static const double POSITIVE_INFINITY;
    
    /**
     * A constant holding the negative infinity of type double.
     */
    static const double NEGATIVE_INFINITY;
    
    /**
     * A constant holding a Not-a-Number (NaN) value of type double.
     */
    static const double NaN;
    
    /**
     * A constant holding the largest positive finite value of type double, (2-2^-52)·2^1023.
     */
    static const double MIN_VALUE;
    
    /**
     * A constant holding the smallest positive nonzero value of type double, 2^-1074.
     */
    static const double MAX_VALUE;
    
    /**
     * Maximum exponent a finite double variable may have.
     */
    static const int32_t MAX_EXPONENT;
    
    /**
     * Minimum exponent a normalized double variable may have.
     */
    static const int32_t MIN_EXPONENT;
    
    /**
     * A constant holding the smallest positive normal value of type double, 2^-1022.
     */
    static const double MIN_NORMAL;
    
    Double(double value);
    double doubleValue();
    int32_t compareTo(Double *anotherDouble);
    static int32_t compare(double d1, double d2);
    bool equals(Double *obj);
    String *toString();
    static String *toString(double d);
    static double parseDouble(String *s);
};

#endif // DOUBLE_INCLUDED
