#ifndef SHORT_INCLUDED
#define SHORT_INCLUDED

#include "String.h"
#include <cstdint>

/**
 * The Short class wraps a value of primitive type int16_t (representing a short value) in an object.
 *
 * @author Petr Kozler (A13B0359P)
 */
class Short : public Comparable<Short> {
    int16_t v;
public:
    /**
     * A constant holding the maximum value a short can have, 2^15-1.
     */
    static const int16_t MIN_VALUE;
    
    /**
     * A constant holding the minimum value a short can have, -2^15.
     */
    static const int16_t MAX_VALUE;
    
    Short(int16_t value);
    int16_t shortValue();
    int32_t compareTo(Short *anotherShort);
    static int32_t compare(int16_t x, int16_t y);
    int16_t equals(Short *obj);
    String *toString();
    static String *toString(int16_t s);
    static int16_t parseShort(String *s);
};

#endif // SHORT_INCLUDED
