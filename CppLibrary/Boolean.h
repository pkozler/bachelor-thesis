#ifndef BOOLEAN_INCLUDED
#define BOOLEAN_INCLUDED

#include "String.h"

class Boolean {
    bool v;
public:
    Boolean(bool value);
    ~Boolean();
    bool booleanValue();
    int compareTo(Boolean *anotherBoolean);
    bool equals(Boolean *obj);
    String *toString();
    static String *toString(bool b);
    static bool parseBoolean(String *s);
    friend std::ostream &operator<<(std::ostream &s, Boolean &obj);
};

#endif // BOOLEAN_INCLUDED
