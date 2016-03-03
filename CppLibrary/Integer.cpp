#include "Integer.h"

#include <string>

const int32_t Integer::MAX_VALUE = 2147483647;
const int32_t Integer::MIN_VALUE = -2147483648;

Integer::Integer(int32_t value) {
    v = value;
}

Integer::~Integer() {
}

int32_t Integer::intValue() {
    return v;
}

int32_t Integer::compareTo(Integer *anotherInteger) {
    return Integer::compare(v, anotherInteger->v);
}

int32_t Integer::compare(int32_t x, int32_t y) {
    return (x < y) ? -1 : ((x == y) ? 0 : 1);
}

bool Integer::equals(Integer *obj) {
    if (obj == nullptr) {
        return false;
    }

    if (sizeof(*this) != sizeof(*obj)) {
        return false;
    }
    
    return (v == obj->v);
}

String *Integer::toString() {
    return toString(v);
}

String *Integer::toString(int32_t i) {
    return new String(std::to_string(i));
}

int32_t Integer::parseInt(String *s) {
    return std::stoi(s->toString(), nullptr, 10);
}

std::ostream &operator<<(std::ostream &s, Integer &obj) {
    return s << obj.toString()->toString().c_str();
}
