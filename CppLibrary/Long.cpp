#include "Long.h"

#include <string>

const int64_t Long::MAX_VALUE = 9223372036854775807L;
const int64_t Long::MIN_VALUE = 9223372036854775808L;

Long::Long(int64_t value) {
    v = value;
}

Long::~Long() {
    // really no code
}

int64_t Long::longValue() {
    return v;
}

int32_t Long::compareTo(Long *anotherLong) {
    return Long::compare(v, anotherLong->v);
}

int32_t Long::compare(int64_t x, int64_t y) {
    return (x < y) ? -1 : ((x == y) ? 0 : 1);
}

bool Long::equals(Long *obj) {
    if (obj == nullptr) {
        return false;
    }

    if (sizeof(*this) != sizeof(*obj)) {
        return false;
    }
    
    return (v == obj->v);
}

String *Long::toString() {
    return toString(v);
}

String *Long::toString(int64_t l) {
    return new String(std::to_string(l));
}

int64_t Long::parseLong(String *s) {
    return std::stol(s->toString(), nullptr, 10);
}

std::ostream &operator<<(std::ostream &s, Long &obj) {
    return s << obj.toString()->toString().c_str();
}
