#include "StringTokenizer.h"

#include <stdlib.h>
#include <string.h>

/**
 * Constructs a string tokenizer for the specified string.
 *
 * @param str a string to be parsed.
 */
StringTokenizer *new_StringTokenizer(String *str) {
    return new_StringTokenizerDelim(str, new_String(" \t\n\r\f"));
}

/**
 * Constructs a string tokenizer for the specified string.
 *
 * @param str a string to be parsed.
 * @param delim the delimiters.
 */
StringTokenizer *new_StringTokenizerDelim(String *str, String *delim) {
    StringTokenizer *strTok = malloc(sizeof(StringTokenizer));
    strTok->str = strdup(str->s);
    strTok->delim = strdup(delim->s);
    strTok->first = true;

    return strTok;
}

void delete_StringTokenizer(StringTokenizer *ptr) {
    free(ptr);
}

/**
 * Calculates the number of times that the specified tokenizer's nextToken function can
 * be called before it results in undefined behavior.
 *
 * @param ptr The allocated structure
 * @return the number of tokens remaining in the string using the current
 * delimiter set.
 */
int32_t countTokens(StringTokenizer *ptr) {
    int32_t n = 0;
    char *s = strdup(ptr->str);

    while((s = strpbrk(s, ptr->delim)) != NULL) {
        n++;
        s++;
    }

    return n;
}

/**
 * Tests if there are more tokens available from the specified tokenizer's string.
 *
 * @param ptr The allocated structure
 * @return true if and only if there is at least one token in the string
 * after the current position; false otherwise.
 */
bool hasMoreTokens(StringTokenizer *ptr) {
    return (countTokens(ptr) > 0);
}

/**
 * Returns the next token from the specified string tokenizer.
 *
 * @param ptr The allocated structure
 * @return the next token from the specified string tokenizer.
 */
String *nextToken(StringTokenizer *ptr) {
    if (ptr->first) {
        ptr->first = false;
        return new_String(strtok(ptr->str, ptr->delim));
    }

    return new_String(strtok(0, ptr->delim));
}
