#ifndef CHARACTER_INCLUDED
#define	CHARACTER_INCLUDED

#include "String.h"
#include <stdbool.h>

typedef struct {
    char v;
} Character;

Character *new_Character(char value);
char charValue(Character *ptr);
int compareToC(Character *ptr, Character *anotherCharacter);
bool equalsC(Character *ptr, Character *obj);
String *toStringC(Character *ptr);
String *Character_toString(char c);
bool Character_isDigit(char ch);
bool Character_isLetter(char ch);

#endif	/* CHARACTER_INCLUDED */
