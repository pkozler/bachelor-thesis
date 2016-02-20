#ifndef LONG_INCLUDED
#define LONG_INCLUDED

#include "String.h"

class Long {
    long v;
public:
    static const long MIN_VALUE;
    static const long MAX_VALUE;
    Long(long value);
    ~Long();
    long longValue();
    int compareTo(Long *anotherLong);
    bool equals(Long *obj);
    String *toString();
    static String *toString(long l);
    static long parseLong(String *s);
    friend std::ostream &operator<<(std::ostream &s, Long &obj);
};

#endif // LONG_INCLUDED
