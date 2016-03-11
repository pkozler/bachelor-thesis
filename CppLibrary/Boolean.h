#ifndef BOOLEAN_INCLUDED
#define BOOLEAN_INCLUDED

#include "String.h"
#include <cstdint>

/**
 * The Boolean class wraps a value of the primitive type boolean in an object.
 *
 * @author Petr Kozler (A13B0359P)
 */
class Boolean {
    bool v;
public:
    Boolean(bool value);
    bool booleanValue();
    int32_t compareTo(Boolean *b);
    static int32_t compare(bool x, bool y);
    bool equals(Boolean *obj);
    String *toString();
    static String *toString(bool b);
    static bool parseBoolean(String *s);
    friend std::ostream &operator<<(std::ostream &s, Boolean &obj);
};

#endif // BOOLEAN_INCLUDED
