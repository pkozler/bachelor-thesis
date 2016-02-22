#ifndef SHORT_INCLUDED
#define SHORT_INCLUDED

#include "String.h"
#include <cstdint>

class Short {
    int16_t v;
public:
    static const int16_t MIN_VALUE;
    static const int16_t MAX_VALUE;
    Short(int16_t value);
    ~Short();
    int16_t shortValue();
    int32_t compareTo(Short *anotherShort);
    int16_t equals(Short *obj);
    String *toString();
    static String *toString(int16_t s);
    static int16_t parseShort(String *s);
    friend std::ostream &operator<<(std::ostream &s, Short &obj);
};

#endif // SHORT_INCLUDED
