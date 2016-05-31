#include "StringTokenizer.h"

#include <iostream>

/**
 * Constructs a string tokenizer for the specified string.
 *
 * @param str a string to be parsed.
 */
StringTokenizer::StringTokenizer(String *str) {
    this->str = str->_s();
    this->delim = " \t\n\r\f";
}

/**
 * Constructs a string tokenizer for the specified string.
 *
 * @param str a string to be parsed.
 * @param delim the delimiters.
 */
StringTokenizer::StringTokenizer(String *str, String *delim) {
    this->str = str->_s();
    this->delim = delim->_s();
}

StringTokenizer::~StringTokenizer() {
    // really no code
}

/**
 * Calculates the number of times that this tokenizer's nextToken method can
 * be called before it results in undefined behavior.
 *
 * @return the number of tokens remaining in the string using the current
 * delimiter set.
 */
int32_t StringTokenizer::countTokens() {
    int32_t count = 0;
    int32_t pos = 0;

    while (pos != std::string::npos) {
        pos += this->str.find_first_of(delim, pos) + 1;
        count++;
    }

    return count;
}

/**
 * Tests if there are more tokens available from this tokenizer's string.
 *
 * @return true if and only if there is at least one token in the string
 * after the current position; false otherwise.
 */
bool StringTokenizer::hasMoreTokens() {
    return (countTokens() > 0);
}

/**
 * Returns the next token from this string tokenizer.
 *
 * @return the next token from this string tokenizer.
 */
String *StringTokenizer::nextToken() {
    int32_t pos = this->str.find_first_of(delim);
    std::string s = this->str.substr(0, pos);
    this->str.erase(0, pos);

    return new String(s);
}
