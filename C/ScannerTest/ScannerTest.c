#include "ScannerTest.h"

#include <stdio.h>
#include <stdlib.h>

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

/**
 * A Scanner module test suite.
 *
 * @author Petr Kozler (A13B0359P)
 */

int32_t errorsInFunction;

// current scanned value
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

/*
 * functions for testing if the two scanned values are equal:
 */

bool _testEqualsBool(void *a, void *b) {
    Boolean *x = new_Boolean(*((bool *)a));
    Boolean *y = new_Boolean(*((bool *)b));

    return equalsBool(x, y);
};

bool _testEqualsB(void *a, void *b) {
    Byte *x = new_Byte(*((int8_t *) a));
    Byte *y = new_Byte(*((int8_t *) b));

    return equalsB(x, y);
};

bool _testEqualsD(void *a, void *b) {
    Double *x = new_Double(*((double *) a));
    Double *y = new_Double(*((double *) b));

    return equalsD(x, y);
};

bool _testEqualsF(void *a, void *b) {
    Float *x = new_Float(*((float *) a));
    Float *y = new_Float(*((float *) b));

    return equalsF(x, y);
};

bool _testEqualsI(void *a, void *b) {
    Integer *x = new_Integer(*((int32_t *) a));
    Integer *y = new_Integer(*((int32_t *) b));

    return equalsI(x, y);
};

bool _testEqualsL(void *a, void *b) {
    Long *x = new_Long(*((int64_t *) a));
    Long *y = new_Long(*((int64_t *) b));

    return equalsL(x, y);
};

bool _testEqualsS(void *a, void *b) {
    Short *x = new_Short(*((int16_t *) a));
    Short *y = new_Short(*((int16_t *) b));

    return equalsS(x, y);
};

bool _testEqualsStr(void *a, void *b) {
    return equalsStr(*((String **)a), *((String **)b));
};

/*
 * functions for getting the string representation of the current scanned value:
 */

String *_testToStringBool(void *a) {
    return Boolean_toString(*((bool *)a));
};

String *_testToStringB(void *a) {
    return Byte_toString(*((int8_t *) a));
};

String *_testToStringD(void *a) {
    return Double_toString(*((double *) a));
};

String *_testToStringF(void *a) {
    return Float_toString(*((float *) a));
};

String *_testToStringI(void *a) {
    return Integer_toString(*((int32_t *) a));
};

String *_testToStringL(void *a) {
    return Long_toString(*((int64_t *) a));
};

String *_testToStringS(void *a) {
    return Short_toString(*((int16_t *) a));
};

String *_testToStringStr(void *a) {
    return toStringStr(*((String **) a));
};

/*
 * functions for scanning the next value with the specified scanner:
 */

void _scanBool(Scanner *sc) {
    currentScannedValue.currentScannedBoolean = nextBoolean(sc);
};

void _scanB(Scanner *sc) {
    currentScannedValue.currentScannedByte = nextByte(sc);
};

void _scanD(Scanner *sc) {
    currentScannedValue.currentScannedDouble = nextDouble(sc);
};

void _scanF(Scanner *sc) {
    currentScannedValue.currentScannedFloat = nextFloat(sc);
};

void _scanI(Scanner *sc) {
    currentScannedValue.currentScannedInt = nextInt(sc);
};

void _scanL(Scanner *sc) {
    currentScannedValue.currentScannedLong = nextLong(sc);
};

void _scanS(Scanner *sc) {
    currentScannedValue.currentScannedShort = nextShort(sc);
};

void _scanStr(Scanner *sc) {
    currentScannedValue.currentScannedString = next(sc);
};

void _scanStrLn(Scanner *sc) {
    currentScannedValue.currentScannedString = nextLine(sc);
};

/*
    Invokes the specified scanner method and verifies the scanned value with the specified expected value.
*/
void assertEquals(const char *name, void *expected, Scanner *sc, void (*scan)(Scanner *),
        bool (*equals) (void *, void *), String *(*toString)(void *)) {
    printf("\n");
    fflush(stdout);
    printf("Testovaná metoda: \"%s\"\n", name);
    fflush(stdout);
    void *actual;
    printf("Očekávaná hodnota: \"%s\"\n", toString(expected)->s);
    fflush(stdout);

    scan(sc);
    actual = &currentScannedValue;

    if (equals(expected, actual)) {
        printf("OK\n");
        fflush(stdout);
    }
    else {
        printf("FAIL - skutečná hodnota: \"%s\"\n", toString(actual)->s);
        fflush(stdout);
        errorsInFunction++;
    }
}

/*
    Verifies that the scanned string value is equal to the expected value.
*/
void nextAssertEquals(Scanner *sc, String *expected) {
    assertEquals("next", &expected, sc, _scanStr, _testEqualsStr, _testToStringStr);
}

/*
    Verifies that the scanned boolean value is equal to the expected value.
*/
void nextBooleanAssertEquals(Scanner *sc, bool expected) {
    assertEquals("nextBoolean", &expected, sc, _scanBool, _testEqualsBool, _testToStringBool);
}

/*
    Verifies that the scanned byte value is equal to the expected value.
*/
void nextByteAssertEquals(Scanner *sc, int8_t expected) {
    assertEquals("nextByte", &expected, sc, _scanB, _testEqualsB, _testToStringB);
}

/*
    Verifies that the scanned short value is equal to the expected value.
*/
void nextShortAssertEquals(Scanner *sc, int16_t expected) {
    assertEquals("nextShort", &expected, sc, _scanS, _testEqualsS, _testToStringS);
}

/*
    Verifies that the scanned int value is equal to the expected value.
*/
void nextIntAssertEquals(Scanner *sc, int32_t expected) {
    assertEquals("nextInt", &expected, sc, _scanI, _testEqualsI, _testToStringI);
}

/*
    Verifies that the scanned long value is equal to the expected value.
*/
void nextLongAssertEquals(Scanner *sc, int64_t expected) {
    assertEquals("nextLong", &expected, sc, _scanL, _testEqualsL, _testToStringL);
}

/*
    Verifies that the scanned float value is equal to the expected value.
*/
void nextFloatAssertEquals(Scanner *sc, float expected) {
    assertEquals("nextFloat", &expected, sc, _scanF, _testEqualsF, _testToStringF);
}

/*
    Verifies that the scanned double value is equal to the expected value.
*/
void nextDoubleAssertEquals(Scanner *sc, double expected) {
    assertEquals("nextDouble", &expected, sc, _scanD, _testEqualsD, _testToStringD);
}

/*
    Verifies that the scanned line string value is equal to the expected value.
*/
void nextLineAssertEquals(Scanner *sc, String *expected) {
    assertEquals("nextLine", &expected, sc, _scanStrLn, _testEqualsStr, _testToStringStr);
}

/**
 * Tests the constructor.
 */

void scannerTest() {
    Scanner *a;
    a = new_Scanner(System_in);

    // random test of different type values scanning
    nextAssertEquals(a, new_String("a"));
    nextBooleanAssertEquals(a, false);
    nextByteAssertEquals(a, 0);
    nextShortAssertEquals(a, 0);
    nextIntAssertEquals(a, 0);
    nextLongAssertEquals(a, 0);
    nextFloatAssertEquals(a, 0.1f);
    nextDoubleAssertEquals(a, 0.1);
    nextLineAssertEquals(a, new_String(" "));
}

/**
 * Tests the next method.
 */

void nextTest() {
    Scanner *a;
    a = new_Scanner(System_in);

    // scanning of strings delimited by different counts of whitespaces
    nextAssertEquals(a, new_String("test1"));
    nextAssertEquals(a, new_String("test2"));
    nextAssertEquals(a, new_String("test3"));
    nextAssertEquals(a, new_String("test4"));
    nextAssertEquals(a, new_String("test5"));
    nextAssertEquals(a, new_String("true"));
    nextAssertEquals(a, new_String("1"));
    nextAssertEquals(a, new_String("1.0"));
    nextAssertEquals(a, new_String("."));
}

/**
 * Tests the nextBoolean method.
 */

void nextBooleanTest() {
    Scanner *a;
    a = new_Scanner(System_in);

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
    a = new_Scanner(System_in);

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
    a = new_Scanner(System_in);

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
    a = new_Scanner(System_in);

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
    a = new_Scanner(System_in);

    nextLongAssertEquals(a, (int64_t) 0L);
    nextLongAssertEquals(a, (int64_t) 0L);
    nextLongAssertEquals(a, (int64_t) 0L);
    nextLongAssertEquals(a, (int64_t) 1L);
    nextLongAssertEquals(a, (int64_t) 1L);
    nextLongAssertEquals(a, (int64_t) - 1L);
    nextLongAssertEquals(a, (int64_t) 9223372036854775807L);
    nextLongAssertEquals(a, (int64_t) 9223372036854775807L);
    nextLongAssertEquals(a, (int64_t) - 9223372036854775807L);
    nextLongAssertEquals(a, (int64_t) - 9223372036854775808L);
}

/**
 * Tests the nextFloat method.
 */

void nextFloatTest() {
    Scanner *a;
    a = new_Scanner(System_in);

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
    a = new_Scanner(System_in);

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
    a = new_Scanner(System_in);

    // scanning of lines with different types of string
    nextLineAssertEquals(a, new_String(""));
    nextLineAssertEquals(a, new_String(" "));
    nextLineAssertEquals(a, new_String("   "));
    nextLineAssertEquals(a, new_String("test"));
    nextLineAssertEquals(a, new_String("this is another test"));
    nextLineAssertEquals(a, new_String(" this is another test "));
    nextLineAssertEquals(a, new_String("   this is another test   "));
    nextLineAssertEquals(a, new_String("   this is   another test   "));
}
