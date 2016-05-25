#include <cstdlib>
#include <iostream>

#include "test.h"
#include "Character.h"

/*
 * Simple C++ Test Suite
 */

/**
 * Tests the charValue method.
 */

void charValueTest() {
    Character *a;
    char b;
    // uppercase letter
    a = new Character('A');
    b = a->charValue();
    Test::assertEquals('A', b);
    // lowercase letter
    a = new Character('a');
    b = a->charValue();
    Test::assertEquals('a', b);
    // digit
    a = new Character('0');
    b = a->charValue();
    Test::assertEquals('0', b);
}

/**
 * Tests the compareTo method.
 */

void compareToTest() {
    Character *a, *b;
    int32_t c;
    // digit and uppercase letter
    a = new Character('9');
    b = new Character('Z');
    c = a->compareTo(b);
    Test::assertEquals(-33, c);
    // lowercase letter and digit
    a = new Character('z');
    b = new Character('9');
    c = a->compareTo(b);
    Test::assertEquals(65, c);
    // lowercase and uppercase letters
    a = new Character('z');
    b = new Character('A');
    c = a->compareTo(b);
    Test::assertEquals(57, c);
    // uppercase and lowercase letters
    a = new Character('Z');
    b = new Character('a');
    c = a->compareTo(b);
    Test::assertEquals(-7, c);
    // both chars are uppercase letters
    a = new Character('Z');
    b = new Character('Z');
    c = a->compareTo(b);
    Test::assertEquals(0, c);
    // both chars are lowercase letters
    a = new Character('a');
    b = new Character('a');
    c = a->compareTo(b);
    Test::assertEquals(0, c);
}

/**
 * Tests the compare method.
 */

void compareTest() {
    char a, b;
    int32_t c;
    a = '9';
    b = 'Z';
    c = Character::compare(a, b);
    Test::assertEquals(-33, c);
    a = 'z';
    b = '9';
    c = Character::compare(a, b);
    Test::assertEquals(65, c);
    a = 'z';
    b = 'A';
    c = Character::compare(a, b);
    Test::assertEquals(57, c);
    a = 'Z';
    b = 'a';
    c = Character::compare(a, b);
    Test::assertEquals(-7, c);
    a = 'Z';
    b = 'Z';
    c = Character::compare(a, b);
    Test::assertEquals(0, c);
    a = 'a';
    b = 'a';
    c = Character::compare(a, b);
    Test::assertEquals(0, c);
}

/**
 * Tests the equals method.
 */

void equalsTest() {
    Character *a, *b;
    bool c;
    a = new Character('9');
    b = new Character('Z');
    c = a->equals(b);
    Test::assertEquals(false, c);
    a = new Character('z');
    b = new Character('9');
    c = a->equals(b);
    Test::assertEquals(false, c);
    a = new Character('z');
    b = new Character('A');
    c = a->equals(b);
    Test::assertEquals(false, c);
    a = new Character('Z');
    b = new Character('a');
    c = a->equals(b);
    Test::assertEquals(false, c);
    a = new Character('Z');
    b = new Character('Z');
    c = a->equals(b);
    Test::assertEquals(true, c);
    a = new Character('a');
    b = new Character('a');
    c = a->equals(b);
    Test::assertEquals(true, c);
}

/**
 * Tests the toString method.
 */

void toStringTest() {
    Character *a;
    String *b;
    // digit text representation
    a = new Character('0');
    b = a->toString();
    Test::assertEquals("0", b->_s());
    // uppercase letter text representation
    a = new Character('A');
    b = a->toString();
    Test::assertEquals("A", b->_s());
    // lowercase letter text representation
    a = new Character('a');
    b = a->toString();
    Test::assertEquals("a", b->_s());
}

/**
 * Tests the static toString method.
 */

void toStringTest2() {
    char a;
    String *b;
    a = '0';
    b = Character::toString(a);
    Test::assertEquals("0", b->_s());
    a = 'A';
    b = Character::toString(a);
    Test::assertEquals("A", b->_s());
    a = 'a';
    b = Character::toString(a);
    Test::assertEquals("a", b->_s());
}

/**
 * Tests the isDigit method.
 */

void isDigitTest() {
    char a;
    bool b;
    // lowercase letter
    a = 'a';
    b = Character::isDigit(a);
    Test::assertEquals(false, b);
    // uppercase letter
    a = 'Z';
    b = Character::isDigit(a);
    Test::assertEquals(false, b);
    // digit
    a = '0';
    b = Character::isDigit(a);
    Test::assertEquals(true, b);
    // another digit
    a = '9';
    b = Character::isDigit(a);
    Test::assertEquals(true, b);
    // whitespace
    a = ' ';
    b = Character::isDigit(a);
    Test::assertEquals(false, b);
}

/**
 * Tests the isLetter method.
 */

void isLetterTest() {
    char a;
    bool b;
    a = 'a';
    b = Character::isLetter(a);
    Test::assertEquals(true, b);
    a = 'Z';
    b = Character::isLetter(a);
    Test::assertEquals(true, b);
    a = '0';
    b = Character::isLetter(a);
    Test::assertEquals(false, b);
    a = '9';
    b = Character::isLetter(a);
    Test::assertEquals(false, b);
    a = ' ';
    b = Character::isLetter(a);
    Test::assertEquals(false, b);
}

int main(int argc, char** argv) {
    Test::setUpTestModule("CharacterTest");

    Test::registerTest(charValueTest, "charValueTest");
    Test::registerTest(compareToTest, "compareToTest");
    Test::registerTest(compareTest, "compareTest");
    Test::registerTest(equalsTest, "equalsTest");
    Test::registerTest(toStringTest, "toStringTest");
    Test::registerTest(toStringTest2, "toStringTest2");
    Test::registerTest(isDigitTest, "isDigitTest");
    Test::registerTest(isLetterTest, "isLetterTest");
    
    Test::runTests();

    return (EXIT_SUCCESS);
}