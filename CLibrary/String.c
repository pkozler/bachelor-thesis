#include "String.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

String *new_StringB(int8_t *value, int32_t length) {
    return new_StringRangeB(value, 0, length);
}

String *new_StringRangeB(int8_t *value, int32_t offset, int32_t length) {
    String *str = malloc(sizeof(String));
    str->s[0] = '\0';
    strncat(str->s, (char *) value + offset, length);

    return str;
}

String *new_String(char *original) {
    String *str = malloc(sizeof(String));
    str->s = strdup(original);
    str->len = strlen(str->s);

    return str;
}

void delete_String(String *ptr) {
    free(ptr->s);
    free(ptr);
}

int32_t compareTo(String *ptr, String *anotherString) {
    return strcmp(ptr->s, anotherString->s);
}

bool equals(String *ptr, String *anObject) {
    if (ptr == anObject) {
        return true;
    }

    if (anObject == NULL || anObject == NULL) {
        return false;
    }

    if (sizeof(*ptr) != sizeof(*anObject)) {
        return false;
    }

    return !strcmp(ptr->s, anObject->s);
}

String *substring(String *ptr, int32_t beginIndex) {
    return substringTo(ptr, 0, strlen(ptr->s) - 1);
}

String *substringTo(String *ptr, int32_t beginIndex, int32_t endIndex) {
    int32_t len = endIndex - beginIndex;
    char *to = (char*) malloc(len);
    strncpy(to, ptr->s + beginIndex, (size_t) endIndex - beginIndex);

    String *str = new_String(to);
    free(to);

    return str;
}

int32_t indexOfC(String *ptr, int32_t ch) {
    return indexOfFromC(ptr, ch, 0);
}

int32_t indexOfFromC(String *ptr, int32_t ch, int32_t fromIndex) {
    char* str = ptr->s + fromIndex;

    char* c = strchr(str, ch);
    int32_t index = (int32_t)(c - str);

    return index;
}

int32_t indexOfStr(String *ptr, String *str) {
    return indexOfFromStr(ptr, str, 0);
}

int32_t indexOfFromStr(String *ptr, String *str, int32_t fromIndex) {
    char* str0 = ptr->s + fromIndex;
    int32_t index = (int32_t) strcspn(str0, str->s);

    return index;
}

int32_t length(String *ptr) {
    return ptr->len;
}

String *trim(String *ptr) {
    int32_t i, j;

    for (i = 0; isspace(ptr->s[i]); i++);
    for (j = ptr->len - 1; isspace(ptr->s[j]); j--);
    int32_t num = j - i + 1;

    char *str = (char *) malloc(num + 1);
    strncpy(str, ptr->s + i, num);
    str[num] = '\0';

    String *changedStr = new_String(str);
    free(str);

    return changedStr;
}

String *toLowerCase(String *ptr) {
    char *str = (char*) malloc(ptr->len);

    int32_t i = 0;
    char c;
    while (ptr->s[i]) {
        c = ptr->s[i];
        str[i] = tolower((int32_t)c);
        i++;
    }
    str[i] = '\0';

    String *changedStr = new_String(str);
    free(str);

    return changedStr;
}

String *toUpperCase(String *ptr) {
    char *str = (char*) malloc(ptr->len);

    int32_t i = 0;
    char c;
    while (ptr->s[i]) {
        c = ptr->s[i];
        str[i] = toupper((int32_t)c);
        i++;
    }
    str[i] = '\0';

    String *changedStr = new_String(str);
    free(str);

    return changedStr;
}

char charAt(String *ptr, int32_t index) {
    return ptr->s[index];
}

String *replace(String *ptr, char oldChar, char newChar) {
    char *str = (char*) malloc(ptr->len);
    int32_t i;

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
