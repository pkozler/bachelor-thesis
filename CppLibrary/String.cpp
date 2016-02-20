#include <algorithm>
#include <string>

#include "String.h"

String::String(char *value) {
    this->s = value;
}

String::String(char *value, int offset, int count) {
    this->s = value;
    this->s = this->s.substr(offset, count);
}

String::String(std::string original) {
    this->s = original;
}

String::~String() {
}

int String::compareTo(String *anotherString) {
    return this->s.compare(anotherString->s);
}

bool String::equals(String *anObject) {
    return (bool) !this->s.compare(anObject->s);
}

String *String::substring(int beginIndex) {
    return new String(this->s.substr(beginIndex));
}

String *String::substring(int beginIndex, int endIndex) {
    return new String(this->s.substr(beginIndex, endIndex - beginIndex + 1));
}

int String::indexOf(int ch) {
    return this->s.find((char) ch);
}

int String::indexOf(int ch, int fromIndex) {
    return this->s.find((char) ch, fromIndex);
}

int String::indexOf(String *str) {
    return this->s.find(str->s);
}

int String::indexOf(String *str, int fromIndex) {
    return this->s.find(str->s, fromIndex);
}

int String::length() {
    return this->s.length();
}

String *String::trim() {
    const char* white_spaces = " \t\n\r\f";

    // nalezení prvního nebílého znaku
    int first = this->s.find_first_not_of(white_spaces);

    // všechny znaky bílé, vytvořen prázdný řetězec
    if (first == std::string::npos) {
        return new String(std::string(""));
    }

    // nalezení posledního nebílého znaku
    int last = this->s.find_last_not_of(white_spaces);

    return new String(this->s.substr(first, last - first + 1));
}

String *String::toLowerCase() {
    std::string lowerCaseStr = this->s;
    std::transform(this->s.begin(), this->s.end(), std::back_inserter(lowerCaseStr), ::tolower);
    return new String(lowerCaseStr);
}

String *String::toUpperCase() {
    std::string upperCaseStr = this->s;
    std::transform(this->s.begin(), this->s.end(), std::back_inserter(upperCaseStr), ::toupper);
    return new String(upperCaseStr);
}

char String::charAt(int index) {
    return this->s.at(index);
}

String *String::replace(char oldChar, char newChar) {
    std::string str = this->s;
    std::replace(str.begin(), str.end(), oldChar, newChar);

    return new String(str);
}

bool String::startsWith(String *prefix) {
    return (s.size() >= prefix->toString().size() && s.find(prefix->toString()) == 0);
}

bool String::endsWith(String *suffix) {
    return (s.size() >= suffix->toString().size() &&
           s.compare(s.size() - suffix->toString().size(), suffix->toString().size(), suffix->toString()) == 0);
}

bool String::isEmpty() {
    return (this->s.length() == 0);
}

std::string String::toString() {
    return s;
}

std::ostream &operator<<(std::ostream &s, String &str) {
    return s << str.toString().c_str();
}

String *operator+(String &s1, String &s2) {
    return new String(s1.toString() + s2.toString());
}

String *String::operator=(String &s) {
    return new String(s.toString());
}
