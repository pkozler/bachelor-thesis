#include "String.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

String *new_String(char *original) {
    String *str = malloc(sizeof(String));
    char *s = strdup(original);
    str->s = s;
    str->len = strlen(s);

    return str;
}

String *new_StringRange(char *value, int offset, int count) {
    char *s = (char*) malloc(count);
    strncpy(s, value + offset, (size_t) count);
    String *str = new_String(s);
    free(s);

    return str;
}

void delete_String(String *ptr) {
    free(ptr->s);
    free(ptr);
}

int compareTo(String *ptr, String *anotherString) {
    return strcmp(ptr->s, anotherString->s);
}

bool equals(String *ptr, String *anObject) {
    return !strcmp(ptr->s, anObject->s);
}

String *substring(String *ptr, int beginIndex) {
    return substringTo(ptr, 0, strlen(ptr->s) - 1);
}

String *substringTo(String *ptr, int beginIndex, int endIndex) {
    int len = endIndex - beginIndex;
    char *to = (char*) malloc(len);
    strncpy(to, ptr->s + beginIndex, (size_t) endIndex - beginIndex);

    String *str = new_String(to);
    free(to);

    return str;
}

int indexOfC(String *ptr, int ch) {
    return indexOfFromC(ptr, ch, 0);
}

int indexOfFromC(String *ptr, int ch, int fromIndex) {
    char* str = ptr->s + fromIndex;

    char* c = strchr(str, ch);
    int index = (int)(c - str);

    return index;
}

int indexOfStr(String *ptr, String *str) {
    return indexOfFromStr(ptr, str, 0);
}

int indexOfFromStr(String *ptr, String *str, int fromIndex) {
    char* str0 = ptr->s + fromIndex;
    int index = (int) strcspn(str0, str->s);

    return index;
}

int length(String *ptr) {
    return ptr->len;
}

String *trim(String *ptr) {
    int i, j;

    for (i = 0; isspace(ptr->s[i]); i++);
    for (j = ptr->len - 1; isspace(ptr->s[j]); j--);
    int num = j - i + 1;

    char *str = (char *) malloc(num + 1);
    strncpy(str, ptr->s + i, num);
    str[num] = '\0';

    String *changedStr = new_String(str);
    free(str);

    return changedStr;
}

String *toLowerCase(String *ptr) {
    char *str = (char*) malloc(ptr->len);

    int i = 0;
    char c;
    while (ptr->s[i]) {
        c = ptr->s[i];
        str[i] = tolower((int)c);
        i++;
    }
    str[i] = '\0';

    String *changedStr = new_String(str);
    free(str);

    return changedStr;
}

String *toUpperCase(String *ptr) {
    char *str = (char*) malloc(ptr->len);

    int i = 0;
    char c;
    while (ptr->s[i]) {
        c = ptr->s[i];
        str[i] = toupper((int)c);
        i++;
    }
    str[i] = '\0';

    String *changedStr = new_String(str);
    free(str);

    return changedStr;
}

char charAt(String *ptr, int index) {
    return ptr->s[index];
}

String *replace(String *ptr, char oldChar, char newChar) {
    char *str = (char*) malloc(ptr->len);
    int i;

    for (i = 0; ptr->s[i]; i++) {
        if (ptr->s[i] == oldChar) {
            ptr->s[i] = newChar;
        }
    }

    String *changedStr = new_String(str);
    free(str);

    return changedStr;
}

bool startsWith(String *ptr, String *prefix) {
    return ptr->len < prefix->len ? false
            : strncmp(prefix->s, ptr->s, prefix->len) == 0;
}

bool endsWith(String *ptr, String *suffix) {
    return ptr->len < suffix->len ? false
            : strncmp(suffix->s, ptr->s + (ptr->len - suffix->len), suffix->len) == 0;
}

bool isEmptyStr(String *ptr) {
    return ptr->len == 0;
}

char *toString(String *ptr) {
    return ptr->s;
}
