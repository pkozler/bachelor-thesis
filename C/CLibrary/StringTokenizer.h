#ifndef STRINGTOKENIZER_INCLUDED
#define	STRINGTOKENIZER_INCLUDED

#include "String_.h"
#include <stdbool.h>
#include <stdint.h>

/**
 * The string tokenizer module allows an application to break a string into tokens.
 *
 * @author Petr Kozler (A13B0359P)
 */

typedef struct {
    // string token array
    char **tokens;
    // token array length
    int32_t tokensLength;
    // current position in the token array
    int32_t tokenCounter;
} StringTokenizer;

StringTokenizer *new_StringTokenizer(String *str);
StringTokenizer *new_StringTokenizerDelim(String *str, String *delim);
void delete_StringTokenizer(StringTokenizer *ptr);
int32_t countTokens(StringTokenizer *ptr);
bool hasMoreTokens(StringTokenizer *ptr);
String *nextToken(StringTokenizer *ptr);

#endif	/* STRINGTOKENIZER_INCLUDED */
