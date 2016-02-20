#ifndef SHORT_INCLUDED
#define SHORT_INCLUDED

#include "String.h"

class Short {
    short v;
public:
    static const short MIN_VALUE;
    static const short MAX_VALUE;
    Short(short value);
    ~Short();
    short shortValue();
    int compareTo(Short *anotherShort);
    short equals(Short *obj);
    String *toString();
    static String *toString(short s);
    static short parseShort(String *s);
    friend std::ostream &operator<<(std::ostream &s, Short &obj);
};

#endif // SHORT_INCLUDED
