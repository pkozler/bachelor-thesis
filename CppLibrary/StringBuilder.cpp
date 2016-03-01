#include "StringBuilder.h"

#include <sstream>

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
