#include "String.h"

#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

/**
 * Indicates whether some other object is "equal to" this one.
 *
 * @param obj the reference object with which to compare.
 * @return true if this object is the same as the obj argument; false otherwise.
 */
bool Object::equals(Object *obj) {
    return this == obj;
}

/**
 * Returns a string representation of the object.
 *
 * @return a string representation of the object.
 */
String *Object::toString() {
    std::stringstream stream;
    stream << std::hex << this;
    return new String(stream.str());
}

std::ostream &operator<<(std::ostream &s, Object &o) {
    return s << o.toString()->_s();
}

/**
 * Constructs a new String by decoding the specified array of bytes using
 * the platform's default charset.
 *
 * @param bytes The bytes to be decoded into characters
 */
String::String(int8_t *value, int32_t length) {
    this->s = ((char *) value, length);
}

/**
 * Constructs a new String by decoding the specified subarray of bytes using
 * the platform's default charset.
 *
 * @param bytes The bytes to be decoded into characters
 * @param offset The index of the first byte to decode
 * @param length The number of bytes to decode
 */
String::String(int8_t *value, int32_t offset, int32_t length) {
    this->s = ((char *) (value + offset), length);
}

/**
 * Initializes a newly created String object so that it represents the same
 * sequence of characters as the argument; in other words, the newly created
 * string is a copy of the argument string. Unless an explicit copy of
 * original is needed, use of this constructor is unnecessary since Strings
 * are immutable.
 *
 * @param original A String
 */
String::String(std::string original) {
    this->s = original;
}

/**
 * Compares two strings lexicographically.
 *
 * @param anotherString the String to be compared.
 * @return the value 0 if the argument string is equal to this string; a
 * value less than 0 if this string is lexicographically less than the
 * string argument; and a value greater than 0 if this string is
 * lexicographically greater than the string argument.
 */
int32_t String::compareTo(String *anotherString) {
    return this->s.compare(anotherString->s);
}

/**
 * Compares this string to the specified object.
 *
 * @param anObject The object to compare this String against
 * @return true if the given object represents a String equivalent to this
 * string, false otherwise
 */
bool String::equals(String *anObject) {
    if (anObject == nullptr) {
        return false;
    }

    if (sizeof (*this) != sizeof (*anObject)) {
        return false;
    }

    return (bool) !this->s.compare(anObject->s);
}

/**
 * Returns a new string that is a substring of this string.
 * 
 * @param beginIndex the beginning index, inclusive.
 * @return the specified substring.
 */
String *String::substring(int32_t beginIndex) {
    return new String(this->s.substr(beginIndex));
}

/**
 * Returns a new string that is a substring of this string.
 *
 * @param beginIndex the beginning index, inclusive.
 * @param endIndex the ending index, exclusive.
 * @return the specified substring.
 */
String *String::substring(int32_t beginIndex, int32_t endIndex) {
    return new String(this->s.substr(beginIndex, endIndex - beginIndex + 1));
}

/**
 * Returns the index within this string of the first occurrence of the
 * specified character.
 *
 * @param ch a character (Unicode code point).
 * @return the index of the first occurrence of the character in the
 * character sequence represented by this object, or -1 if the character
 * does not occur.
 */
int32_t String::indexOf(int32_t ch) {
    return this->s.find((char) ch);
}

/**
 * Returns the index within this string of the first occurrence of the
 * specified character, starting the search at the specified index.
 *
 * @param ch a character (Unicode code point).
 * @param fromIndex the index to start the search from.
 * @return the index of the first occurrence of the character in the
 * character sequence represented by this object that is greater than or
 * equal to fromIndex, or -1 if the character does not occur.
 */
int32_t String::indexOf(int32_t ch, int32_t fromIndex) {
    return this->s.find((char) ch, fromIndex);
}

/**
 * Returns the index within this string of the first occurrence of the
 * specified substring.
 *
 * @param str the substring to search for.
 * @return the index of the first occurrence of the specified substring, or
 * -1 if there is no such occurrence.
 */
int32_t String::indexOf(String *str) {
    return this->s.find(str->s);
}

/**
 * Returns the index within this string of the first occurrence of the
 * specified substring, starting at the specified index.
 *
 * @param str the substring to search for.
 * @param fromIndex the index from which to start the search.
 * @return the index of the first occurrence of the specified substring,
 * starting at the specified index, or -1 if there is no such occurrence.
 */
int32_t String::indexOf(String *str, int32_t fromIndex) {
    return this->s.find(str->s, fromIndex);
}

/**
 * Returns the length of this string.
 *
 * @return the length of the sequence of characters represented by this
 * object.
 */
int32_t String::length() {
    return this->s.length();
}

/**
 * Returns a copy of the string, with leading and trailing whitespace
 * omitted.
 *
 * @return A copy of this string with leading and trailing white space
 * removed, or this string if it has no leading or trailing white space.
 */
String *String::trim() {
    const char* white_spaces = " \t\n\r\f";

    int32_t first = this->s.find_first_not_of(white_spaces);

    if (first == std::string::npos) {
        return new String(std::string(""));
    }

    int32_t last = this->s.find_last_not_of(white_spaces);

    return new String(this->s.substr(first, last - first + 1));
}

/**
 * Converts all of the characters in this String to lower case using the
 * rules of the default locale.
 *
 * @return the String, converted to lowercase.
 */
String *String::toLowerCase() {
    std::string lowerCaseStr = this->s;
    std::transform(this->s.begin(), this->s.end(), std::back_inserter(lowerCaseStr), ::tolower);
    return new String(lowerCaseStr);
}

/**
 * Converts all of the characters in this String to upper case using the
 * rules of the default locale.
 *
 * @return the String, converted to uppercase.
 */
String *String::toUpperCase() {
    std::string upperCaseStr = this->s;
    std::transform(this->s.begin(), this->s.end(), std::back_inserter(upperCaseStr), ::toupper);
    return new String(upperCaseStr);
}

/**
 * Returns the char value at the specified index.
 *
 * @param index the index of the char value.
 * @return the char value at the specified index of this string. The first
 * char value is at index 0.
 */
char String::charAt(int32_t index) {
    return this->s.at(index);
}

/**
 * Returns a new string resulting from replacing all occurrences of oldChar
 * in this string with newChar.
 *
 * @param oldChar the old character.
 * @param newChar the new character.
 * @return a string derived from this string by replacing every occurrence
 * of oldChar with newChar.
 */
String *String::replace(char oldChar, char newChar) {
    std::string str = this->s;
    std::replace(str.begin(), str.end(), oldChar, newChar);

    return new String(str);
}

/**
 * Tests if this string starts with the specified prefix.
 *
 * @param prefix the prefix.
 * @return true if the character sequence represented by the argument is a
 * prefix of the character sequence represented by this string; false
 * otherwise. Note also that true will be returned if the argument is an
 * empty string or is equal to this String object as determined by the
 * equals(Object) method.
 */
bool String::startsWith(String *prefix) {
    return (s.size() >= prefix->_s().size() && s.find(prefix->_s()) == 0);
}

/**
 * Tests if this string ends with the specified suffix.
 *
 * @param suffix the suffix.
 * @return true if the character sequence represented by the argument is a
 * suffix of the character sequence represented by this object; false
 * otherwise. Note that the result will be true if the argument is the empty
 * string or is equal to this String object as determined by the
 * equals(Object) method.
 */
bool String::endsWith(String *suffix) {
    return (s.size() >= suffix->_s().size() &&
            s.compare(s.size() - suffix->_s().size(), suffix->_s().size(), suffix->_s()) == 0);
}

/**
 * Returns true if, and only if, length() is 0.
 *
 * @return true if length() is 0, otherwise false
 */
bool String::isEmpty() {
    return (this->s.length() == 0);
}

/**
 * This object (which is already a string!) is itself returned.
 *
 * @return the string itself.
 */
String *String::toString() {
    return new String(s);
}

String *String::operator=(std::string &s) {
    return new String(s);
}
