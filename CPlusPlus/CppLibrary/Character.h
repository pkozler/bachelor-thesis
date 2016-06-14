#ifndef CHARACTER_INCLUDED
#define	CHARACTER_INCLUDED

#include "String_.h"
#include <cstdint>

/**
 * The Character class wraps a value of the primitive type char in an object.
 *
 * @author Petr Kozler (A13B0359P)
 */
class Character : public Comparable {
    char v;
public:
    Character(char value);
    char charValue();
    int32_t compareTo(Object *anotherCharacter);
    static int32_t compare(char x, char y);
    bool equals(Object *obj);
    String *toString();
    static String *toString(char c);
    static bool isDigit(char ch);
    static bool isLetter(char ch);
};

#endif	// CHARACTER_INCLUDED
