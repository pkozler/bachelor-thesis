#include "StringBuilder.h"

#include "String_.h"
#include <stdlib.h>
#include <string.h>

// initial capacity for the inner dynamically resized string buffer
#define _STR_DEFAULT_CAPACITY 16
// coefficient for increasing the string buffer capacity
#define _STR_RESIZE_COEF 2

/**
 * Constructs a string builder with no characters in it and an initial
 * capacity of 16 characters.
 */
StringBuilder *new_StringBuilder() {
    StringBuilder *sb = (StringBuilder *) malloc(sizeof (StringBuilder));
    sb->count = 1;
    sb->capacity = _STR_DEFAULT_CAPACITY;
    // allocating the inner buffer to the default capacity
    sb->buffer = (char *) malloc(sb->capacity * sizeof (char));
    sb->buffer[0] = '\0';

    return sb;
}

/*
    Destructs the StringBuilder.
 */
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
    // increasing the buffer capacity if the new string length reaches the current capacity
    if (ptr->count + str->len >= ptr->capacity) {
        ptr->capacity += str->len * _STR_RESIZE_COEF;
        // reallocating the memory (expanding the allocated memory by the resize coefficient)
        ptr->buffer = realloc(ptr->buffer, ptr->capacity * sizeof (char));
    }

    // concatenating the new string
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
