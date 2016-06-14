#ifndef BYTE_INCLUDED
#define BYTE_INCLUDED

#include "String_.h"
#include <cstdint>

/**
 * The Byte class wraps a value of primitive type int8_t (representing a byte value) in an object.
 *
 * @author Petr Kozler (A13B0359P)
 */
class Byte : public Comparable {
    int8_t v;
public:
    /**
     * A constant holding the maximum value a byte can have, 2^7-1.
     */
    static const int8_t MIN_VALUE;
    
    /**
     * A constant holding the minimum value a byte can have, -2^7.
     */
    static const int8_t MAX_VALUE;
    
    Byte(int8_t value);
    int8_t byteValue();
    int32_t compareTo(Object *anotherByte);
    static int32_t compare(int8_t x, int8_t y);
    bool equals(Object *obj);
    String *toString();
    static String *toString(int8_t b);
    static int8_t parseByte(String *s);
};

#endif // BYTE_INCLUDED
