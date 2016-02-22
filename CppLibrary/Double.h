#ifndef DOUBLE_INCLUDED
#define DOUBLE_INCLUDED

#include "String.h"
#include <cstdint>

class Double {
    double v;
public:
    static const double MIN_VALUE;
    static const double MAX_VALUE;
    Double(double value);
    ~Double();
    double doubleValue();
    int32_t compareTo(Double *anotherDouble);
    bool equals(Double *obj);
    String *toString();
    static String *toString(double d);
    static double parseDouble(String *s);
    friend std::ostream &operator<<(std::ostream &s, Double &obj);
};

#endif // DOUBLE_INCLUDED
