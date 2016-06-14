#include "ScannerTest.h"

#include <cstdlib>
#include <iostream>

#include "Scanner.h"
#include "Boolean.h"
#include "Byte.h"
#include "Short.h"
#include "Integer.h"
#include "Long.h"
#include "Float.h"
#include "Double.h"
#include "Character.h"
#include "String.h"

/*
 * Simple C++ Test Suite
 */

int32_t errorsInFunction;

union {
    bool currentScannedBoolean;
    int8_t currentScannedByte;
    int16_t currentScannedShort;
    int32_t currentScannedInt;
    int64_t currentScannedLong;
    float currentScannedFloat;
    double currentScannedDouble;
    String *currentScannedString;
} currentScannedValue;

bool _testEqualsBool(void *a, void *b) {
    Boolean *x = new Boolean(*((bool *)a));
    Boolean *y = new Boolean(*((bool *)b));

    return x->equals(y);
};

bool _testEqualsB(void *a, void *b) {
    Byte *x = new Byte(*((int8_t *) a));
    Byte *y = new Byte(*((int8_t *) b));

    return x->equals(y);
};

bool _testEqualsD(void *a, void *b) {
    Double *x = new Double(*((double *) a));
    Double *y = new Double(*((double *) b));

    return x->equals(y);
};

bool _testEqualsF(void *a, void *b) {
    Float *x = new Float(*((float *) a));
    Float *y = new Float(*((float *) b));

    return x->equals(y);
};

bool _testEqualsI(void *a, void *b) {
    Integer *x = new Integer(*((int32_t *) a));
    Integer *y = new Integer(*((int32_t *) b));

    return x->equals(y);
};

bool _testEqualsL(void *a, void *b) {
    Long *x = new Long(*((int64_t *) a));
    Long *y = new Long(*((int64_t *) b));

    return x->equals(y);
};

bool _testEqualsS(void *a, void *b) {
    Short *x = new Short(*((int16_t *) a));
    Short *y = new Short(*((int16_t *) b));

    return x->equals(y);
};

bool _testEqualsStr(void *a, void *b) {
    return (*((String **) a))->equals(*((String **) b));
};

String *_testToStringBool(void *a) {
    return Boolean::toString(*((bool *)a));
};

String *_testToStringB(void *a) {
    return Byte::toString(*((int8_t *) a));
};

String *_testToStringD(void *a) {
    return Double::toString(*((double *) a));
};

String *_testToStringF(void *a) {
    return Float::toString(*((float *) a));
};

String *_testToStringI(void *a) {
    return Integer::toString(*((int32_t *) a));
};

String *_testToStringL(void *a) {
    return Long::toString(*((int64_t *) a));
};

String *_testToStringS(void *a) {
    return Short::toString(*((int16_t *) a));
};

String *_testToStringStr(void *a) {
    return (*((String **) a))->toString();
};

void _scanBool(Scanner *sc) {
    currentScannedValue.currentScannedBoolean = sc->nextBoolean();
};

void _scanB(Scanner *sc) {
    currentScannedValue.currentScannedByte = sc->nextByte();
};

void _scanD(Scanner *sc) {
    currentScannedValue.currentScannedDouble = sc->nextDouble();
};

void _scanF(Scanner *sc) {
    currentScannedValue.currentScannedFloat = sc->nextFloat();
};

void _scanI(Scanner *sc) {
    currentScannedValue.currentScannedInt = sc->nextInt();
};

void _scanL(Scanner *sc) {
    currentScannedValue.currentScannedLong = sc->nextLong();
};

void _scanS(Scanner *sc) {
    currentScannedValue.currentScannedShort = sc->nextShort();
};

void _scanStr(Scanner *sc) {
    currentScannedValue.currentScannedString = sc->next();
};

void _scanStrLn(Scanner *sc) {
    currentScannedValue.currentScannedString = sc->nextLine();
};

void assertEquals(std::string name, void *expected, Scanner *sc, void (*scan)(Scanner *),
        bool (*equals) (void *, void *), String *(*toString)(void *)) {
    std::cout << "" << std::endl;
    std::cout << "Testovaná metoda: \"" << name << "\"" << std::endl;
    void *actual;
    std::cout << "Očekávaná hodnota: \"" << toString(expected)->_s() << "\"" << std::endl;

    scan(sc);
    actual = &currentScannedValue;

    if (equals(expected, actual)) {
        std::cout << "OK" << std::endl;
    }
    else {
        std::cout << "FAIL - skutečná hodnota: \"" << toString(actual)->_s() << "\"" << std::endl;
        errorsInFunction++;
    }
}

void nextAssertEquals(Scanner *sc, String *expected) {
    assertEquals("next", &expected, sc, _scanStr, _testEqualsStr, _testToStringStr);
}

void nextBooleanAssertEquals(Scanner *sc, bool expected) {
    assertEquals("nextBoolean", &expected, sc, _scanBool, _testEqualsBool, _testToStringBool);
}

void nextByteAssertEquals(Scanner *sc, int8_t expected) {
    assertEquals("nextByte", &expected, sc, _scanB, _testEqualsB, _testToStringB);
}

void nextShortAssertEquals(Scanner *sc, int16_t expected) {
    assertEquals("nextShort", &expected, sc, _scanS, _testEqualsS, _testToStringS);
}

void nextIntAssertEquals(Scanner *sc, int32_t expected) {
    assertEquals("nextInt", &expected, sc, _scanI, _testEqualsI, _testToStringI);
}

void nextLongAssertEquals(Scanner *sc, int64_t expected) {
    assertEquals("nextLong", &expected, sc, _scanL, _testEqualsL, _testToStringL);
}

void nextFloatAssertEquals(Scanner *sc, float expected) {
    assertEquals("nextFloat", &expected, sc, _scanF, _testEqualsF, _testToStringF);
}

void nextDoubleAssertEquals(Scanner *sc, double expected) {
    assertEquals("nextDouble", &expected, sc, _scanD, _testEqualsD, _testToStringD);
}

void nextLineAssertEquals(Scanner *sc, String *expected) {
    assertEquals("nextLine", &expected, sc, _scanStrLn, _testEqualsStr, _testToStringStr);
}

/**
 * Tests the constructor.
 */

void scannerTest() {
    Scanner *a;
    a = new Scanner(System::in);

    // random test of different type values scanning
    nextAssertEquals(a, new String("a"));
    nextBooleanAssertEquals(a, false);
    nextByteAssertEquals(a, 0);
    nextShortAssertEquals(a, 0);
    nextIntAssertEquals(a, 0);
    nextLongAssertEquals(a, 0LL);
    nextFloatAssertEquals(a, 0.1F);
    nextDoubleAssertEquals(a, 0.1);
    nextLineAssertEquals(a, new String(" "));
}

/**
 * Tests the next method.
 */

void nextTest() {
    Scanner *a;
    a = new Scanner(System::in);

    // scanning of strings delimited by different counts of whitespaces
    nextAssertEquals(a, new String("test1"));
    nextAssertEquals(a, new String("test2"));
    nextAssertEquals(a, new String("test3"));
    nextAssertEquals(a, new String("test4"));
    nextAssertEquals(a, new String("test5"));
    nextAssertEquals(a, new String("true"));
    nextAssertEquals(a, new String("1"));
    nextAssertEquals(a, new String("1.0"));
    nextAssertEquals(a, new String("."));
}

/**
 * Tests the nextBoolean method.
 */

void nextBooleanTest() {
    Scanner *a;
    a = new Scanner(System::in);

    // scanning of strings representing bool values
    nextBooleanAssertEquals(a, true);
    nextBooleanAssertEquals(a, true);
    nextBooleanAssertEquals(a, false);
    nextBooleanAssertEquals(a, true);
    nextBooleanAssertEquals(a, false);
    nextBooleanAssertEquals(a, false);
    nextBooleanAssertEquals(a, true);
    nextBooleanAssertEquals(a, false);
}

/**
 * Tests the nextByte method.
 */

void nextByteTest() {
    Scanner *a;
    a = new Scanner(System::in);

    // scanning of integers (zeroes, ones, positive and negative minimal and maximal values)
    nextByteAssertEquals(a, (int8_t) 0);
    nextByteAssertEquals(a, (int8_t) 0);
    nextByteAssertEquals(a, (int8_t) 0);
    nextByteAssertEquals(a, (int8_t) 1);
    nextByteAssertEquals(a, (int8_t) 1);
    nextByteAssertEquals(a, (int8_t) - 1);
    nextByteAssertEquals(a, (int8_t) 127);
    nextByteAssertEquals(a, (int8_t) 127);
    nextByteAssertEquals(a, (int8_t) - 127);
    nextByteAssertEquals(a, (int8_t) - 128);
}

/**
 * Tests the nextShort method.
 */

void nextShortTest() {
    Scanner *a;
    a = new Scanner(System::in);

    nextShortAssertEquals(a, (int16_t) 0);
    nextShortAssertEquals(a, (int16_t) 0);
    nextShortAssertEquals(a, (int16_t) 0);
    nextShortAssertEquals(a, (int16_t) 1);
    nextShortAssertEquals(a, (int16_t) 1);
    nextShortAssertEquals(a, (int16_t) - 1);
    nextShortAssertEquals(a, (int16_t) 32767);
    nextShortAssertEquals(a, (int16_t) 32767);
    nextShortAssertEquals(a, (int16_t) - 32767);
    nextShortAssertEquals(a, (int16_t) - 32768);
}

/**
 * Tests the nextInt method.
 */

void nextIntTest() {
    Scanner *a;
    a = new Scanner(System::in);

    nextIntAssertEquals(a, (int32_t) 0);
    nextIntAssertEquals(a, (int32_t) 0);
    nextIntAssertEquals(a, (int32_t) 0);
    nextIntAssertEquals(a, (int32_t) 1);
    nextIntAssertEquals(a, (int32_t) 1);
    nextIntAssertEquals(a, (int32_t) - 1);
    nextIntAssertEquals(a, (int32_t) 2147483647);
    nextIntAssertEquals(a, (int32_t) 2147483647);
    nextIntAssertEquals(a, (int32_t) - 2147483647);
    nextIntAssertEquals(a, (int32_t) - 2147483648);
}

/**
 * Tests the nextLong method.
 */

void nextLongTest() {
    Scanner *a;
    a = new Scanner(System::in);

    nextLongAssertEquals(a, (int64_t) 0LL);
    nextLongAssertEquals(a, (int64_t) 0LL);
    nextLongAssertEquals(a, (int64_t) 0LL);
    nextLongAssertEquals(a, (int64_t) 1LL);
    nextLongAssertEquals(a, (int64_t) 1LL);
    nextLongAssertEquals(a, (int64_t) - 1LL);
    nextLongAssertEquals(a, (int64_t) 9223372036854775807LL);
    nextLongAssertEquals(a, (int64_t) 9223372036854775807LL);
    nextLongAssertEquals(a, (int64_t) - 9223372036854775807LL);
    nextLongAssertEquals(a, (int64_t) - 9223372036854775808LL);
}

/**
 * Tests the nextFloat method.
 */

void nextFloatTest() {
    Scanner *a;
    a = new Scanner(System::in);

    /* 
     scanning of decimal values
     (with and without sign and decimal dot and with omission of digits on different positions,
     scanning of zeroes, ones, minimal and maximal absolute values)
     */
    nextFloatAssertEquals(a, (float) 0.0F);
    nextFloatAssertEquals(a, (float) 0.0F);
    nextFloatAssertEquals(a, (float) - 0.0F);
    nextFloatAssertEquals(a, (float) 0.0F);
    nextFloatAssertEquals(a, (float) 0.0F);
    nextFloatAssertEquals(a, (float) - 0.0F);
    nextFloatAssertEquals(a, (float) 0.0F);
    nextFloatAssertEquals(a, (float) 0.0F);
    nextFloatAssertEquals(a, (float) - 0.0F);
    nextFloatAssertEquals(a, (float) 0.0F);
    nextFloatAssertEquals(a, (float) 0.0F);
    nextFloatAssertEquals(a, (float) - 0.0F);
    nextFloatAssertEquals(a, (float) 1.0F);
    nextFloatAssertEquals(a, (float) 1.0F);
    nextFloatAssertEquals(a, (float) - 1.0F);
    nextFloatAssertEquals(a, (float) 1.0F);
    nextFloatAssertEquals(a, (float) 1.0F);
    nextFloatAssertEquals(a, (float) - 1.0F);
    nextFloatAssertEquals(a, (float) 0.1F);
    nextFloatAssertEquals(a, (float) 0.1F);
    nextFloatAssertEquals(a, (float) - 0.1F);
    nextFloatAssertEquals(a, (float) 0.1F);
    nextFloatAssertEquals(a, (float) 0.1F);
    nextFloatAssertEquals(a, (float) - 0.1F);
    nextFloatAssertEquals(a, (float) 3.4028235E38F);
    nextFloatAssertEquals(a, (float) 3.4028235E38F);
    nextFloatAssertEquals(a, (float) - 3.4028235E38F);
    nextFloatAssertEquals(a, (float) 1.4E-45F);
    nextFloatAssertEquals(a, (float) 1.4E-45F);
    nextFloatAssertEquals(a, (float) - 1.4E-45F);
}

/**
 * Tests the nextDouble method.
 */

void nextDoubleTest() {
    Scanner *a;
    a = new Scanner(System::in);

    nextDoubleAssertEquals(a, (double) 0.0);
    nextDoubleAssertEquals(a, (double) 0.0);
    nextDoubleAssertEquals(a, (double) - 0.0);
    nextDoubleAssertEquals(a, (double) 0.0);
    nextDoubleAssertEquals(a, (double) 0.0);
    nextDoubleAssertEquals(a, (double) - 0.0);
    nextDoubleAssertEquals(a, (double) 0.0);
    nextDoubleAssertEquals(a, (double) 0.0);
    nextDoubleAssertEquals(a, (double) - 0.0);
    nextDoubleAssertEquals(a, (double) 0.0);
    nextDoubleAssertEquals(a, (double) 0.0);
    nextDoubleAssertEquals(a, (double) - 0.0);
    nextDoubleAssertEquals(a, (double) 1.0);
    nextDoubleAssertEquals(a, (double) 1.0);
    nextDoubleAssertEquals(a, (double) - 1.0);
    nextDoubleAssertEquals(a, (double) 1.0);
    nextDoubleAssertEquals(a, (double) 1.0);
    nextDoubleAssertEquals(a, (double) - 1.0);
    nextDoubleAssertEquals(a, (double) 0.1);
    nextDoubleAssertEquals(a, (double) 0.1);
    nextDoubleAssertEquals(a, (double) - 0.1);
    nextDoubleAssertEquals(a, (double) 0.1);
    nextDoubleAssertEquals(a, (double) 0.1);
    nextDoubleAssertEquals(a, (double) - 0.1);
    nextDoubleAssertEquals(a, (double) 1.7976931348623157E308);
    nextDoubleAssertEquals(a, (double) 1.7976931348623157E308);
    nextDoubleAssertEquals(a, (double) - 1.7976931348623157E308);
    nextDoubleAssertEquals(a, (double) 4.9E-324);
    nextDoubleAssertEquals(a, (double) 4.9E-324);
    nextDoubleAssertEquals(a, (double) - 4.9E-324);
}

/**
 * Tests the nextLine method.
 */

void nextLineTest() {
    Scanner *a;
    a = new Scanner(System::in);

    // scanning of lines with different types of std::string
    nextLineAssertEquals(a, new String(""));
    nextLineAssertEquals(a, new String(" "));
    nextLineAssertEquals(a, new String("   "));
    nextLineAssertEquals(a, new String("test"));
    nextLineAssertEquals(a, new String("this is another test"));
    nextLineAssertEquals(a, new String(" this is another test "));
    nextLineAssertEquals(a, new String("   this is another test   "));
    nextLineAssertEquals(a, new String("   this is   another test   "));
}

