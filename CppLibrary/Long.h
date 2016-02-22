#ifndef LONG_INCLUDED
#define LONG_INCLUDED

#include "String.h"
#include <cstdint>

class Long {
    int64_t v;
public:
    static const int64_t MIN_VALUE;
    static const int64_t MAX_VALUE;
    Long(int64_t value);
    ~Long();
    int64_t longValue();
    int32_t compareTo(Long *anotherLong);
    bool equals(Long *obj);
    String *toString();
    static String *toString(int64_t l);
    static int64_t parseLong(String *s);
    friend std::ostream &operator<<(std::ostream &s, Long &obj);
};

#endif // LONG_INCLUDED
