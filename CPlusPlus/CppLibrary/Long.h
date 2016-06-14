#ifndef LONG_INCLUDED
#define LONG_INCLUDED

#include "String_.h"
#include <cstdint>

/**
 * The Long class wraps a value of the primitive type int64_t (representing a long value) in an object.
 *
 * @author Petr Kozler (A13B0359P)
 */
class Long : public Comparable {
    int64_t v;
public:
    /**
     * A constant holding the maximum value a long can have, 2^63-1.
     */
    static const int64_t MIN_VALUE;
    
    /**
     * A constant holding the minimum value a long can have, -2^63.
     */
    static const int64_t MAX_VALUE;
    
    Long(int64_t value);
    int64_t longValue();
    int32_t compareTo(Object *anotherLong);
    static int32_t compare(int64_t x, int64_t y);
    bool equals(Object *obj);
    String *toString();
    static String *toString(int64_t l);
    static int64_t parseLong(String *s);
};

#endif // LONG_INCLUDED
