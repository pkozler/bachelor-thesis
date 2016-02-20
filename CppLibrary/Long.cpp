#include "Long.h"

#include <string>

const long Long::MAX_VALUE = 9223372036854775807;
const long Long::MIN_VALUE = -9223372036854775808;

Long::Long(long value) {
    v = value;
}

Long::~Long() {
}

long Long::longValue() {
    return v;
}

int Long::compareTo(Long *anotherLong) {
    return (v - anotherLong->v);
}

bool Long::equals(Long *obj) {
    if (obj == nullptr) {
        return false;
    }

    return (v == obj->v);
}

String *Long::toString() {
    return toString(v);
}

String *Long::toString(long l) {
    return new String(std::to_string(l));
}

long Long::parseLong(String *s) {
    return std::stol(s->toString(), nullptr, 10);
}

std::ostream &operator<<(std::ostream &s, Long &obj) {
    return s << obj.toString()->toString().c_str();
}
