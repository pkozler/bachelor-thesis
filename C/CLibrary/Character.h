#ifndef CHARACTER_INCLUDED
#define	CHARACTER_INCLUDED

#include "String.h"
#include <stdbool.h>
#include <stdint.h>

/**
 * The Character struct wraps a value of the type char.
 *
 * @author Petr Kozler (A13B0359P)
 */

typedef struct {
    char v;
} Character;

Character *new_Character(char value);
char charValue(Character *ptr);
int32_t compareToC(Character *ptr, Character *anotherCharacter);
int32_t Character_compare(char x, char y);
bool equalsC(Character *ptr, Character *obj);
String *toStringC(Character *ptr);
String *Character_toString(char c);
bool Character_isDigit(char ch);
bool Character_isLetter(char ch);

#endif	/* CHARACTER_INCLUDED */
