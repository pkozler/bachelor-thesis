#include "Character.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define _MAX_CHAR_STRLEN 1

Character *new_Character(char value) {
    Character *c = malloc(sizeof(Character));
    c->v = value;

    return c;
}

char charValue(Character *ptr) {
    return ptr->v;
}

int32_t compareToC(Character *ptr, Character *anotherCharacter) {
    return Character_compare(ptr->v, anotherCharacter->v);
}

int32_t Character_compare(char x, char y) {
    return x - y;
}

bool equalsC(Character *ptr, Character *obj) {
    if (ptr == obj) {
        return true;
    }

    if (ptr == NULL || obj == NULL) {
        return false;
    }

    if (sizeof(*ptr) != sizeof(*obj)) {
        return false;
    }

    return (ptr->v == obj->v);
}

String *toStringC(Character *ptr) {
    return Character_toString(ptr->v);
}

String *Character_toString(char c) {
    char *str = malloc(_MAX_CHAR_STRLEN + 1);
    char buf[_MAX_CHAR_STRLEN];

    str[0] = '\0';
    sprintf(buf, "%c", c);
    strcat(str, buf);

    return new_String(str);
}

bool Character_isDigit(char ch) {
    return isdigit((int32_t)ch);
}

bool Character_isLetter(char ch) {
    return isalpha((int32_t)ch);
}
