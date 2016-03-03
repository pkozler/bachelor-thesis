#ifndef BYTE_INCLUDED
#define BYTE_INCLUDED

#include "String.h"
#include <cstdint>

class Byte {
    int8_t v;
public:
    static const int8_t MIN_VALUE;
    static const int8_t MAX_VALUE;
    Byte(int8_t value);
    ~Byte();
    int8_t byteValue();
    int32_t compareTo(Byte *anotherByte);
    static int32_t compare(int8_t x, int8_t y);
    bool equals(Byte *obj);
    String *toString();
    static String *toString(int8_t b);
    static int8_t parseByte(String *s);
    friend std::ostream &operator<<(std::ostream &s, Byte &obj);
};

#endif // BYTE_INCLUDED
