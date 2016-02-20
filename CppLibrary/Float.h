#ifndef FLOAT_INCLUDED
#define FLOAT_INCLUDED

#include "String.h"

class Float {
    float v;
public:
    static const float MIN_VALUE;
    static const float MAX_VALUE;
    Float(float value);
    ~Float();
    float floatValue();
    int compareTo(Float *anotherFloat);
    bool equals(Float *obj);
    String *toString();
    static String *toString(float f);
    static float parseFloat(String *s);
    friend std::ostream &operator<<(std::ostream &s, Float &obj);
};

#endif // FLOAT_INCLUDED
