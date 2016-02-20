#ifndef STRINGTOKENIZER_INCLUDED
#define	STRINGTOKENIZER_INCLUDED

#include "String.h"
#include <stdbool.h>

typedef struct {
    char *str;
    char *delim;
    bool first;
} StringTokenizer;

StringTokenizer *new_StringTokenizer(String *str);
StringTokenizer *new_StringTokenizerDelim(String *str, String *delim);
void delete_StringTokenizer(StringTokenizer *ptr);
int countTokens(StringTokenizer *ptr);
bool hasMoreTokens(StringTokenizer *ptr);
String *nextToken(StringTokenizer *ptr);

#endif	/* STRINGTOKENIZER_INCLUDED */
