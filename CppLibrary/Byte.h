#ifndef BYTE_INCLUDED
#define BYTE_INCLUDED

#include "String.h"

class Byte {
    char v;
public:
    static const char MIN_VALUE;
    static const char MAX_VALUE;
    Byte(char value);
    ~Byte();
    char byteValue();
    int compareTo(Byte *anotherByte);
    bool equals(Byte *obj);
    String *toString();
    static String *toString(char b);
    static char parseByte(String *s);
    friend std::ostream &operator<<(std::ostream &s, Byte &obj);
};

#endif // BYTE_INCLUDED
