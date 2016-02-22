#include "Float.h"

#include <string>
#include <cmath>

const float Float::MAX_VALUE = 3.4028235e+38f;
const float Float::MIN_VALUE = 1.4e-45f;

Float::Float(float value) {
    v = value;
}

Float::~Float() {
}

float Float::floatValue() {
    return v;
}

int32_t Float::compareTo(Float *anotherFloat) {
    float val = v - anotherFloat->v;

    if (val > 0) {
        return ceil(val);
    }
    else if (val < 0) {
        return floor(val);
    }
    else {
        return 0;
    }
}

bool Float::equals(Float *obj) {
    if (obj == nullptr) {
        return false;
    }

    return (v == obj->v);
}

String *Float::toString() {
    return toString(v);
}

String *Float::toString(float f) {
    return new String(std::to_string(f));
}

float Float::parseFloat(String *s) {
    return std::stof(s->toString(), nullptr);
}

std::ostream &operator<<(std::ostream &s, Float &obj) {
    return s << obj.toString()->toString().c_str();
}
