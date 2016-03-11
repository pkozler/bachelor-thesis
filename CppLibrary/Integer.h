#ifndef INTEGER_INCLUDED
#define	INTEGER_INCLUDED

#include "String.h"
#include <iostream>
#include <sstream>
#include <cstdint>

/**
 * The Integer class wraps a value of the primitive type int in an object.
 *
 * @author Petr Kozler (A13B0359P)
 */
class Integer {
    int32_t v;
public:
    static const int32_t MIN_VALUE;
    static const int32_t MAX_VALUE;
    Integer(int32_t value);
    ~Integer();
    int32_t intValue();
    int32_t compareTo(Integer *anotherInteger);
    static int32_t compare(int32_t x, int32_t y);
    bool equals(Integer *obj);
    String *toString();
    static String *toString(int32_t i);
    static int32_t parseInt(String *s);
    friend std::ostream &operator<<(std::ostream &s, Integer &obj);
};

#endif	// INTEGER_INCLUDED
