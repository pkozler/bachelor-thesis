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
    return (v - anotherCharacter->v);
}

bool Character::equals(Character *obj) {
    if (obj == nullptr) {
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
