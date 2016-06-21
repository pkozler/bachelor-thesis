#ifndef INTEGER_INCLUDED
#define	INTEGER_INCLUDED

#include "String_.h"
#include <iostream>
#include <sstream>
#include <cstdint>

/**
 * The Integer class wraps a value of the primitive type int32_t (representing an int value) in an object.
 *
 * @author Petr Kozler (A13B0359P)
 */
class Integer : public Comparable {
    // an inner value
    int32_t v;
public:
    /**
     * A constant holding the maximum value an int can have, 2^31-1.
     */
    static const int32_t MIN_VALUE;
    
    /**
     * A constant holding the minimum value an int can have, -2^31.
     */
    static const int32_t MAX_VALUE;
    
    Integer(int32_t value);
    int32_t intValue();
    int32_t compareTo(Object *anotherInteger);
    static int32_t compare(int32_t x, int32_t y);
    bool equals(Object *obj);
    String *toString();
    static String *toString(int32_t i);
    static int32_t parseInt(String *s);
};

#endif	// INTEGER_INCLUDED
