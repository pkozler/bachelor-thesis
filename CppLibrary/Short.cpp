#include "Short.h"

#include <string>

const int16_t Short::MAX_VALUE = 32767;
const int16_t Short::MIN_VALUE = -32768;

Short::Short(int16_t value) {
    v = value;
}

Short::~Short() {
}

int16_t Short::shortValue() {
    return v;
}

int32_t Short::compareTo(Short *anotherShort) {
    return (v - anotherShort->v);
}

int16_t Short::equals(Short *obj) {
    if (obj == nullptr) {
        return false;
    }

    return (v == obj->v);
}

String *Short::toString() {
    return toString(v);
}

String *Short::toString(int16_t s) {
    return new String(std::to_string(s));
}

int16_t Short::parseShort(String *s) {
    return (int16_t) std::stoi(s->toString(), nullptr, 10);
}

std::ostream &operator<<(std::ostream &s, Short &obj) {
    return s << obj.toString()->toString().c_str();
}
