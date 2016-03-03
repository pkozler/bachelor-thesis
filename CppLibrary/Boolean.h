#ifndef BOOLEAN_INCLUDED
#define BOOLEAN_INCLUDED

#include "String.h"
#include <cstdint>

class Boolean {
    bool v;
public:
    Boolean(bool value);
    ~Boolean();
    bool booleanValue();
    int32_t compareTo(Boolean *anotherBoolean);
    static int32_t compare(bool x, bool y);
    bool equals(Boolean *obj);
    String *toString();
    static String *toString(bool b);
    static bool parseBoolean(String *s);
    friend std::ostream &operator<<(std::ostream &s, Boolean &obj);
};

#endif // BOOLEAN_INCLUDED
