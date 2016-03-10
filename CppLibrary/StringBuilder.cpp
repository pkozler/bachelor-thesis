#include "StringBuilder.h"

StringBuilder::StringBuilder() {
    // really no code
}

StringBuilder::~StringBuilder() {
    // really no code
}

StringBuilder *StringBuilder::append(String *str) {
    oss << str->toString();
    
    return this;
}

String *StringBuilder::toString() {
    return new String(oss.str());
}
