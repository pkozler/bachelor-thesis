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
}

int StringTokenizer::countTokens() {
    int count = 0;
    unsigned int pos = 0;

    // dokud existuje další token
    while (pos != std::string::npos) {
        // hledá se dále od pozice posledního tokenu a uloží se nová pozice
        pos += this->str.find_first_of(delim, pos) + 1;
        count++;
    }

    return count;
}

bool StringTokenizer::hasMoreTokens() {
    return (countTokens() > 0);
}

String *StringTokenizer::nextToken() {
    int pos = this->str.find_first_of(delim);
    std::string s = this->str.substr(0, pos);
    this->str.erase(0, pos);

    return new String(s);
}
