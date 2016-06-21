#ifndef BOOLEAN_INCLUDED
#define BOOLEAN_INCLUDED

#include "String_.h"
#include <cstdint>

/**
 * The Boolean class wraps a value of the primitive type bool (representing a boolean value) in an object.
 *
 * @author Petr Kozler (A13B0359P)
 */
class Boolean : public Comparable {
    // an inner value
    bool v;
public:
    Boolean(bool value);
    bool booleanValue();
    int32_t compareTo(Object *b);
    static int32_t compare(bool x, bool y);
    bool equals(Object *obj);
    String *toString();
    static String *toString(bool b);
    static bool parseBoolean(String *s);
};

#endif // BOOLEAN_INCLUDED
