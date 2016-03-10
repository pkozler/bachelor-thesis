#include "StringBuilder.h"

#include "String.h"
#include <stdlib.h>
#include <string.h>

#define _STR_DEFAULT_CAPACITY 16
#define _STR_RESIZE_COEF 2

StringBuilder *new_StringBuilder() {
    StringBuilder *sb = (StringBuilder *) malloc(sizeof (StringBuilder));
    sb->count = 1;
    sb->capacity = _STR_DEFAULT_CAPACITY;
    sb->buffer = (char *) malloc(sb->capacity * sizeof (char));
    sb->buffer[0] = '\0';

    return sb;
}

void delete_StringBuilder(StringBuilder *ptr) {
    free(ptr->buffer);
    free(ptr);
}

StringBuilder *append(StringBuilder *ptr, String *str) {
    if (ptr->count + str->len >= ptr->capacity) {
        ptr->capacity += str->len * _STR_RESIZE_COEF;
        ptr->buffer = realloc(ptr->buffer, ptr->capacity);
    }

    strcat(ptr->buffer, str->s);
    ptr->count += str->len;

    return ptr;
}

String *toStringSb(StringBuilder *ptr) {
    return new_String(ptr->buffer);
}
