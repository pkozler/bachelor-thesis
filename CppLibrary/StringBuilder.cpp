#include "StringBuilder.h"

StringBuilder::StringBuilder() {
}

StringBuilder::~StringBuilder() {    
}

StringBuilder *StringBuilder::append(String *str) {
    oss << str->toString();
    
    return this;
}

String *StringBuilder::toString() {
    return new String(oss.str());
}
