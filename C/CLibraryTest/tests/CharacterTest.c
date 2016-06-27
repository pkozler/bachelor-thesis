#include <stdio.h>
#include <stdlib.h>

#include "test.h"
#include "Character.h"

/**
 * A Character module test suite.
 *
 * @author Petr Kozler (A13B0359P)
 */

/**
 * Tests the charValue function.
 */

void charValueTest() {
    Character *a;
    char b;
    // uppercase letter
    a = new_Character('A');
    b = charValue(a);
    assertEqualsC('A', b);
    // lowercase letter
    a = new_Character('a');
    b = charValue(a);
    assertEqualsC('a', b);
    // digit
    a = new_Character('0');
    b = charValue(a);
    assertEqualsC('0', b);
}

/**
 * Tests the compareTo function.
 */

void compareToTest() {
    Character *a, *b;
    int32_t c;
    // digit and uppercase letter
    a = new_Character('9');
    b = new_Character('Z');
    c = compareToC(a, b);
    assertEqualsI(-33, c);
    // lowercase letter and digit
    a = new_Character('z');
    b = new_Character('9');
    c = compareToC(a, b);
    assertEqualsI(65, c);
    // lowercase and uppercase letters
    a = new_Character('z');
    b = new_Character('A');
    c = compareToC(a, b);
    assertEqualsI(57, c);
    // uppercase and lowercase letters
    a = new_Character('Z');
    b = new_Character('a');
    c = compareToC(a, b);
    assertEqualsI(-7, c);
    // both chars are uppercase letters
    a = new_Character('Z');
    b = new_Character('Z');
    c = compareToC(a, b);
    assertEqualsI(0, c);
    // both chars are lowercase letters
    a = new_Character('a');
    b = new_Character('a');
    c = compareToC(a, b);
    assertEqualsI(0, c);
}

/**
 * Tests the compare function.
 */

void compareTest() {
    char a, b;
    int32_t c;
    a = '9';
    b = 'Z';
    c = Character_compare(a, b);
    assertEqualsI(-33, c);
    a = 'z';
    b = '9';
    c = Character_compare(a, b);
    assertEqualsI(65, c);
    a = 'z';
    b = 'A';
    c = Character_compare(a, b);
    assertEqualsI(57, c);
    a = 'Z';
    b = 'a';
    c = Character_compare(a, b);
    assertEqualsI(-7, c);
    a = 'Z';
    b = 'Z';
    c = Character_compare(a, b);
    assertEqualsI(0, c);
    a = 'a';
    b = 'a';
    c = Character_compare(a, b);
    assertEqualsI(0, c);
}

/**
 * Tests the equals function.
 */

void equalsTest() {
    Character *a, *b;
    bool c;
    a = new_Character('9');
    b = new_Character('Z');
    c = equalsC(a, b);
    assertEqualsBool(false, c);
    a = new_Character('z');
    b = new_Character('9');
    c = equalsC(a, b);
    assertEqualsBool(false, c);
    a = new_Character('z');
    b = new_Character('A');
    c = equalsC(a, b);
    assertEqualsBool(false, c);
    a = new_Character('Z');
    b = new_Character('a');
    c = equalsC(a, b);
    assertEqualsBool(false, c);
    a = new_Character('Z');
    b = new_Character('Z');
    c = equalsC(a, b);
    assertEqualsBool(true, c);
    a = new_Character('a');
    b = new_Character('a');
    c = equalsC(a, b);
    assertEqualsBool(true, c);
}

/**
 * Tests the toString function.
 */

void toStringTest() {
    Character *a;
    String *b;
    // digit text representation
    a = new_Character('0');
    b = toStringC(a);
    assertEqualsStr("0", b->s);
    // uppercase letter text representation
    a = new_Character('A');
    b = toStringC(a);
    assertEqualsStr("A", b->s);
    // lowercase letter text representation
    a = new_Character('a');
    b = toStringC(a);
    assertEqualsStr("a", b->s);
}

/**
 * Tests the static toString function.
 */

void toStringTest2() {
    char a;
    String *b;
    a = '0';
    b = Character_toString(a);
    assertEqualsStr("0", b->s);
    a = 'A';
    b = Character_toString(a);
    assertEqualsStr("A", b->s);
    a = 'a';
    b = Character_toString(a);
    assertEqualsStr("a", b->s);
}

/**
 * Tests the isDigit function.
 */

void isDigitTest() {
    char a;
    bool b;
    // lowercase letter
    a = 'a';
    b = Character_isDigit(a);
    assertEqualsBool(false, b);
    // uppercase letter
    a = 'Z';
    b = Character_isDigit(a);
    assertEqualsBool(false, b);
    // digit
    a = '0';
    b = Character_isDigit(a);
    assertEqualsBool(true, b);
    // another digit
    a = '9';
    b = Character_isDigit(a);
    assertEqualsBool(true, b);
    // whitespace
    a = ' ';
    b = Character_isDigit(a);
    assertEqualsBool(false, b);
}

/**
 * Tests the isLetter function.
 */

void isLetterTest() {
    char a;
    bool b;
    a = 'a';
    b = Character_isLetter(a);
    assertEqualsBool(true, b);
    a = 'Z';
    b = Character_isLetter(a);
    assertEqualsBool(true, b);
    a = '0';
    b = Character_isLetter(a);
    assertEqualsBool(false, b);
    a = '9';
    b = Character_isLetter(a);
    assertEqualsBool(false, b);
    a = ' ';
    b = Character_isLetter(a);
    assertEqualsBool(false, b);
}

int main(int argc, char** argv) {
    const int testCount = 8;
    setUpTestModule("CharacterTest", testCount);

    registerTest(charValueTest, "charValueTest");
    registerTest(compareToTest, "compareToTest");
    registerTest(compareTest, "compareTest");
    registerTest(equalsTest, "equalsTest");
    registerTest(toStringTest, "toStringTest");
    registerTest(toStringTest2, "toStringTest2");
    registerTest(isDigitTest, "isDigitTest");
    registerTest(isLetterTest, "isLetterTest");
    
    runTests();

    return (EXIT_SUCCESS);
}
