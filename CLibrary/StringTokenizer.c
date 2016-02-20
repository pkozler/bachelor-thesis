#include "StringTokenizer.h"

#include <stdlib.h>
#include <string.h>

StringTokenizer *new_StringTokenizer(String *str) {
    return new_StringTokenizerDelim(str, new_String(" \t\n\r\f"));
}

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

int countTokens(StringTokenizer *ptr) {
    int n = 0;
    char *s = strdup(ptr->str);

    while((s = strpbrk(s, ptr->delim)) != NULL) {
        n++;
        s++;
    }

    return n;
}

bool hasMoreTokens(StringTokenizer *ptr) {
    return (countTokens(ptr) > 0);
}

String *nextToken(StringTokenizer *ptr) {
    if (ptr->first) {
        ptr->first = false;
        return new_String(strtok(ptr->str, ptr->delim));
    }

    return new_String(strtok(0, ptr->delim));
}
