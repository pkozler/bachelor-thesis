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
    if (v == true && anotherBoolean->v == false) {
        return 1;
    }
    else if (v == false && anotherBoolean->v == true) {
        return -1;
    }
    else {
        return 0;
    }
}

bool Boolean::equals(Boolean *obj) {
    if (obj == nullptr) {
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
