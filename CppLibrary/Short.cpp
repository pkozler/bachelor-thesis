#include "Short.h"

#include <string>

const short Short::MAX_VALUE = 32767;
const short Short::MIN_VALUE = -32768;

Short::Short(short value) {
    v = value;
}

Short::~Short() {
}

short Short::shortValue() {
    return v;
}

int Short::compareTo(Short *anotherShort) {
    return (v - anotherShort->v);
}

short Short::equals(Short *obj) {
    if (obj == nullptr) {
        return false;
    }

    return (v == obj->v);
}

String *Short::toString() {
    return toString(v);
}

String *Short::toString(short s) {
    return new String(std::to_string(s));
}

short Short::parseShort(String *s) {
    return (short) std::stoi(s->toString(), nullptr, 10);
}

std::ostream &operator<<(std::ostream &s, Short &obj) {
    return s << obj.toString()->toString().c_str();
}
