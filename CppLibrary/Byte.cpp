#include "Byte.h"

#include <string>

const int8_t Byte::MAX_VALUE = 127;
const int8_t Byte::MIN_VALUE = -128;

Byte::Byte(int8_t value) {
    v = value;
}

Byte::~Byte() {
    // really no code
}

int8_t Byte::byteValue() {
    return v;
}

int32_t Byte::compareTo(Byte *anotherByte) {
    return compare(v, anotherByte->v);
}

int32_t Byte::compare(int8_t x, int8_t y) {
    return x - y;
}

bool Byte::equals(Byte *obj) {
    if (obj == nullptr) {
        return false;
    }

    if (sizeof(*this) != sizeof(*obj)) {
        return false;
    }
    
    return (v == obj->v);
}

String *Byte::toString() {
    return toString(v);
}

String *Byte::toString(int8_t b) {
    return new String(std::to_string(b));
}

int8_t Byte::parseByte(String *s) {
    return (int8_t) std::stoi(s->toString(), nullptr, 10);
}

std::ostream &operator<<(std::ostream &s, Byte &obj) {
    return s << obj.toString()->toString().c_str();
}
