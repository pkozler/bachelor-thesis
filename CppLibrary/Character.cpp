#include "Character.h"

#include <cctype>

Character::Character(char value) {
    v = value;
}

Character::~Character() {
}

char Character::charValue() {
    return v;
}

int32_t Character::compareTo(Character *anotherCharacter) {
    return compare(v, anotherCharacter->v);
}

int32_t Character::compare(char x, char y) {
    return x - y;
}

bool Character::equals(Character *obj) {
    if (obj == nullptr) {
        return false;
    }

    if (sizeof(*this) != sizeof(*obj)) {
        return false;
    }
    
    return (v == obj->v);
}

String *Character::toString() {
    return toString(v);
}

String *Character::toString(char c) {
    return new String(std::string(1, c));
}

bool Character::isDigit(char ch) {
    return isdigit(ch);
}

bool Character::isLetter(char ch) {
    return isalpha(ch);
}

std::ostream &operator<<(std::ostream &s, Character &obj) {
    return s << obj.toString()->toString().c_str();
}
