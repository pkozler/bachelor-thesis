#include "Character.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define _MAX_CHAR_STRLEN 1

/**
 * Constructs a newly allocated Character structure that represents the
 * specified char value.
 *
 * @param value the value to be represented by the Character structure.
 */
Character *new_Character(char value) {
    Character *c = malloc(sizeof(Character));
    c->v = value;

    return c;
}

/**
 * Returns the value of the specified Character structure.
 *
 * @param ptr The allocated structure
 * @return the primitive char value represented by the specified structure.
 */
char charValue(Character *ptr) {
    return ptr->v;
}

/**
 * Compares two Character structures numerically.
 *
 * @param ptr The allocated structure
 * @param anotherCharacter the Character to be compared.
 * @return the value 0 if the second Character is equal to the first Character;
 * a value less than 0 if the first Character is numerically less than the
 * second Character; and a value greater than 0 if the first Character is
 * numerically greater than the second Character (unsigned comparison).
 * Note that this is strictly a numerical comparison; it is not
 * locale-dependent.
 */
int32_t compareToC(Character *ptr, Character *anotherCharacter) {
    return Character_compare(ptr->v, anotherCharacter->v);
}

/**
 * Compares two char values numerically.
 *
 * @param x the first char to compare
 * @param y the second char to compare
 * @return the value 0 if x == y; a value less than 0 if x < y; and a value greater than 0 if x
 * > y
 */
int32_t Character_compare(char x, char y) {
    return x - y;
}

/**
 * Compares the one structure against the other.
 *
 * @param ptr The allocated structure
 * @param obj the structure to compare with.
 * @return true if the structures are the same; false otherwise.
 */
bool equalsC(Character *ptr, Character *obj) {
    if (ptr == NULL || obj == NULL) {
        return false;
    }

    if (sizeof(*ptr) != sizeof(*obj)) {
        return false;
    }

    return (ptr->v == obj->v);
}

/**
 * Returns a String structure representing the specified Character's value.
 *
 * @param ptr The allocated structure
 * @return a string representation of the specified structure.
 */
String *toStringC(Character *ptr) {
    return Character_toString(ptr->v);
}

/**
 * Returns a String structure representing the specified char.
 *
 * @param c the char to be converted
 * @return the string representation of the specified char
 */
String *Character_toString(char c) {
    char *str = malloc(_MAX_CHAR_STRLEN + 1);
    char buf[_MAX_CHAR_STRLEN];

    str[0] = '\0';
    sprintf(buf, "%c", c);
    strcat(str, buf);

    return new_String(str);
}

/**
 * Determines if the specified character is a digit.
 *
 * @param ch the character to be tested.
 * @return true if the character is a digit; false otherwise.
 */
bool Character_isDigit(char ch) {
    return isdigit((int32_t)ch);
}

/**
 * Determines if the specified character is a letter.
 *
 * @param ch the character to be tested.
 * @return true if the character is a letter; false otherwise.
 */
bool Character_isLetter(char ch) {
    return isalpha((int32_t)ch);
}
