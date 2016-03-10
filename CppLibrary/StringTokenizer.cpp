#include "StringTokenizer.h"

#include <iostream>
#include <cstring>

StringTokenizer::StringTokenizer(String *str) {
    this->str = str->toString();
    this->delim = " \t\n\r\f";
}

StringTokenizer::StringTokenizer(String *str, String *delim) {
    this->str = str->toString();
    this->delim = delim->toString();
}

StringTokenizer::~StringTokenizer() {
    // really no code
}

int32_t StringTokenizer::countTokens() {
    int32_t count = 0;
    int32_t pos = 0;

    while (pos != std::string::npos) {
        pos += this->str.find_first_of(delim, pos) + 1;
        count++;
    }

    return count;
}

bool StringTokenizer::hasMoreTokens() {
    return (countTokens() > 0);
}

String *StringTokenizer::nextToken() {
    int32_t pos = this->str.find_first_of(delim);
    std::string s = this->str.substr(0, pos);
    this->str.erase(0, pos);

    return new String(s);
}
