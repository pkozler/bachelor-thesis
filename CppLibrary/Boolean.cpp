#include "Boolean.h"

Boolean::Boolean(bool value) {
    v = value;
}

Boolean::~Boolean() {
}

bool Boolean::booleanValue() {
    return v;
}

int32_t Boolean::compareTo(Boolean *anotherBoolean) {
    return compare(v, anotherBoolean->v);
}

int32_t Boolean::compare(bool x, bool y) {
    return (x == y) ? 0 : (x ? 1 : -1);
}

bool Boolean::equals(Boolean *obj) {
    if (obj == nullptr) {
        return false;
    }

    if (sizeof(*this) != sizeof(*obj)) {
        return false;
    }
    
    return (v == obj->v);
}

String *Boolean::toString() {
    return toString(v);
}

String *Boolean::toString(bool b) {
    return new String(b ? "true" : "false");
}

bool Boolean::parseBoolean(String *s) {
    String *trueStr = new String("true");
    String *falseStr = new String("false");
    bool value = false;

    if (s->toLowerCase()->equals(trueStr)) {
        value = true;
    }
    else if (s->toLowerCase()->equals(falseStr)) {
        value = false;
    }

    delete trueStr;
    delete falseStr;

    return value;
}

std::ostream &operator<<(std::ostream &s, Boolean &obj) {
    return s << obj.toString()->toString().c_str();
}
