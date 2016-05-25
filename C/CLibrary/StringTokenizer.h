#ifndef STRINGTOKENIZER_INCLUDED
#define	STRINGTOKENIZER_INCLUDED

#include "String.h"
#include <stdbool.h>
#include <stdint.h>

/**
 * The string tokenizer module allows an application to break a string into tokens.
 *
 * @author Petr Kozler (A13B0359P)
 */

typedef struct {
    char *str;
    char *delim;
    bool first;
} StringTokenizer;

StringTokenizer *new_StringTokenizer(String *str);
StringTokenizer *new_StringTokenizerDelim(String *str, String *delim);
void delete_StringTokenizer(StringTokenizer *ptr);
int32_t countTokens(StringTokenizer *ptr);
bool hasMoreTokens(StringTokenizer *ptr);
String *nextToken(StringTokenizer *ptr);

#endif	/* STRINGTOKENIZER_INCLUDED */
