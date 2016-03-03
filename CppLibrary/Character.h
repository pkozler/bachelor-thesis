#ifndef CHARACTER_INCLUDED
#define	CHARACTER_INCLUDED

#include "String.h"
#include <cstdint>

class Character {
    char v;
public:
    Character(char value);
    ~Character();
    char charValue();
    int32_t compareTo(Character *anotherCharacter);
    static int32_t compare(char x, char y);
    bool equals(Character *obj);
    String *toString();
    static String *toString(char c);
    static bool isDigit(char ch);
    static bool isLetter(char ch);
    friend std::ostream &operator<<(std::ostream &s, Character &obj);
};

#endif	// CHARACTER_INCLUDED
