#include "Byte.h"

#include <string>

const char Byte::MAX_VALUE = 127;
const char Byte::MIN_VALUE = -128;

Byte::Byte(char value) {
    v = value;
}

Byte::~Byte() {
}

char Byte::byteValue() {
    return v;
}

int Byte::compareTo(Byte *anotherByte) {
    return (v - anotherByte->v);
}

bool Byte::equals(Byte *obj) {
    if (obj == nullptr) {
        return false;
    }

    return (v == obj->v);
}

String *Byte::toString() {
    return toString(v);
}

String *Byte::toString(char b) {
    return new String(std::to_string(b));
}

char Byte::parseByte(String *s) {
    return (char) std::stoi(s->toString(), nullptr, 10);
}

std::ostream &operator<<(std::ostream &s, Byte &obj) {
    return s << obj.toString()->toString().c_str();
}
