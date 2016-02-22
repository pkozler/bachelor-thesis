#include "Double.h"

#include <string>
#include <cmath>

const double Double::MAX_VALUE = 1.7976931348623157e+308;
const double Double::MIN_VALUE = 4.9e-324;

Double::Double(double value) {
    v = value;
}

Double::~Double() {
}

double Double::doubleValue() {
    return v;
}

int32_t Double::compareTo(Double *anotherDouble) {
    double val = v - anotherDouble->v;

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

bool Double::equals(Double *obj) {
    if (obj == nullptr) {
        return false;
    }

    return (v == obj->v);
}

String *Double::toString() {
    return toString(v);
}

String *Double::toString(double d) {
    return new String(std::to_string(d));
}

double Double::parseDouble(String *s) {
    return std::stod(s->toString(), nullptr);
}

std::ostream &operator<<(std::ostream &s, Double &obj) {
    return s << obj.toString()->toString().c_str();
}
