#ifndef CHARACTER_INCLUDED
#define	CHARACTER_INCLUDED

#include "String.h"

class Character {
    char v;
public:
    Character(char value);
    ~Character();
    char charValue();
    int compareTo(Character *anotherCharacter);
    bool equals(Character *obj);
    String *toString();
    static String *toString(char c);
    static bool isDigit(char ch);
    static bool isLetter(char ch);
    friend std::ostream &operator<<(std::ostream &s, Character &obj);
};

#endif	// CHARACTER_INCLUDED
