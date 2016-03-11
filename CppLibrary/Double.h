#ifndef DOUBLE_INCLUDED
#define DOUBLE_INCLUDED

#include "String.h"
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
class Double {
    double v;
    static int64_t getNegativeZeroBits();
public:
    static const double POSITIVE_INFINITY;
    static const double NEGATIVE_INFINITY;
    static const double NaN;
    static const double MIN_VALUE;
    static const double MAX_VALUE;
    static const int32_t MAX_EXPONENT;
    static const int32_t MIN_EXPONENT;
    static const double MIN_NORMAL;
    Double(double value);
    ~Double();
    double doubleValue();
    int32_t compareTo(Double *anotherDouble);
    static int32_t compare(double d1, double d2);
    bool equals(Double *obj);
    String *toString();
    static String *toString(double d);
    static double parseDouble(String *s);
    friend std::ostream &operator<<(std::ostream &s, Double &obj);
};

#endif // DOUBLE_INCLUDED
