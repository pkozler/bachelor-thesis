#include "StringTokenizer.h"
#include "ArrayList.h"
#include "System.h"

#include <stdlib.h>
#include <string.h>
#include <wchar.h>

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
    char *ch = strpbrk(str->s, delim->s);
    
    // determining the greatest possible length of the token array
    for (strTok->tokensLength = 1; ch != NULL; strTok->tokensLength++) {
        ch = strpbrk(ch + 1, delim->s);
    }
    
    strTok->tokenCounter = 0;
    // allocating the token array with the determined length
    strTok->tokens = (char **) malloc(strTok->tokensLength * sizeof(char *));
    
    char *s = strtok(str->s, delim->s);
    int32_t i = 0;
    
    // inserting the tokens into the token array
    while (s != NULL) {
        strTok->tokens[i] = s;
        i++;
        s = strtok(NULL, delim->s);
    }

    strTok->tokensLength = i;
    // reallocating the token array to the exact length
    strTok->tokens = realloc(strTok->tokens, strTok->tokensLength * sizeof(char *));
    
    return strTok;
}

/*
    Destructs the StringTokenizer.
 */
void delete_StringTokenizer(StringTokenizer *ptr) {
    // deallocating the memory for the each string token
    int32_t i;
    for (i = 0; i < ptr->tokensLength; i++) {
        free(ptr->tokens[i]);
    }
    
    free(ptr->tokens);
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
    return ptr->tokensLength - ptr->tokenCounter;
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
    String *str = new_String(ptr->tokens[ptr->tokenCounter]);
    ptr->tokenCounter++;
    
    return str;
}
