#include "Integer.h"

#include <string>

const int Integer::MAX_VALUE = 2147483647;
const int Integer::MIN_VALUE = -2147483648;

Integer::Integer(int value) {
    v = value;
}

Integer::~Integer() {
}

int Integer::intValue() {
    return v;
}

int Integer::compareTo(Integer *anotherInteger) {
    return (v - anotherInteger->v);
}

bool Integer::equals(Integer *obj) {
    if (obj == nullptr) {
        return false;
    }

    return (v == obj->v);
}

String *Integer::toString() {
    return toString(v);
}

String *Integer::toString(int i) {
    return new String(std::to_string(i));
}

int Integer::parseInt(String *s) {
    return std::stoi(s->toString(), nullptr, 10);
}

std::ostream &operator<<(std::ostream &s, Integer &obj) {
    return s << obj.toString()->toString().c_str();
}
