#include "StringTokenizer.h"
#include "System.h"

#include <iostream>
#include <cstring>
#include <string.h>

void StringTokenizer::init(std::string str, std::string delim) {
    size_t pos = str.find_first_of(delim, 0);
    
    for (tokensLength = 1; pos != str.npos; tokensLength++) {
        pos = str.find_first_of(delim, pos + 1);
    }
    
    tokenCounter = 0;
    tokens = new std::string[tokensLength];
    
    char* tmpS = strdup(str.c_str());
    
    char *s = strtok(tmpS, delim.c_str());
    int32_t i = 0;
    
    while (s != 0) {
        tokens[i] = s;
        i++;
        s = strtok(NULL, delim.c_str());
    }
    
    tokensLength = i;
    std::string *tempTokens = new std::string[tokensLength];
    
    for (int32_t j = 0; j < tokensLength; j++) {
        tempTokens[j] = tokens[j];
    }
    
    delete[] tokens;
    tokens = tempTokens;
}

/**
 * Constructs a string tokenizer for the specified string.
 *
 * @param str a string to be parsed.
 */
StringTokenizer::StringTokenizer(String *str) {
    init(str->_s(), " \t\n\r\f");
}

/**
 * Constructs a string tokenizer for the specified string.
 *
 * @param str a string to be parsed.
 * @param delim the delimiters.
 */
StringTokenizer::StringTokenizer(String *str, String *delim) {
    init(str->_s(), delim->_s());
}

StringTokenizer::~StringTokenizer() {
    delete[] tokens;
}

/**
 * Calculates the number of times that this tokenizer's nextToken method can
 * be called before it results in undefined behavior.
 *
 * @return the number of tokens remaining in the string using the current
 * delimiter set.
 */
int32_t StringTokenizer::countTokens() {
    return tokensLength - tokenCounter;
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
    String *str = new String(tokens[tokenCounter]);
    tokenCounter++;
    
    return str;
}
