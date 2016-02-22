#include "Long.h"

#include <string>

const int64_t Long::MAX_VALUE = 9223372036854775807;
const int64_t Long::MIN_VALUE = -9223372036854775808;

Long::Long(int64_t value) {
    v = value;
}

Long::~Long() {
}

int64_t Long::longValue() {
    return v;
}

int32_t Long::compareTo(Long *anotherLong) {
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

String *Long::toString(int64_t l) {
    return new String(std::to_string(l));
}

int64_t Long::parseLong(String *s) {
    return std::stol(s->toString(), nullptr, 10);
}

std::ostream &operator<<(std::ostream &s, Long &obj) {
    return s << obj.toString()->toString().c_str();
}
