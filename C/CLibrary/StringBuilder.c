#include "StringBuilder.h"

#include "String.h"
#include <stdlib.h>
#include <string.h>

#define _STR_DEFAULT_CAPACITY 16
#define _STR_RESIZE_COEF 2

/**
 * Constructs a string builder with no characters in it and an initial
 * capacity of 16 characters.
 */
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

/**
 * Appends the specified string to the specified character sequence.
 *
 * @param ptr The allocated structure
 * @param str a string.
 * @return a pointer to the specified structure.
 */
StringBuilder *append(StringBuilder *ptr, String *str) {
    if (ptr->count + str->len >= ptr->capacity) {
        ptr->capacity += str->len * _STR_RESIZE_COEF;
        ptr->buffer = realloc(ptr->buffer, ptr->capacity * sizeof (char));
    }

    strcat(ptr->buffer, str->s);
    ptr->count += str->len;

    return ptr;
}

/**
 * Returns a string representing the data in the specified sequence.
 *
 * @param ptr The allocated structure
 * @return a string representation of the specified sequence of characters.
 */
String *toStringSb(StringBuilder *ptr) {
    return new_String(ptr->buffer);
}
