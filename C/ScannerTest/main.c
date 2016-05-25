#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "ScannerTest.h"

typedef void (*TestFunction)();

const int32_t TEST_FUNCTION_COUNT = 10;

TestFunction *testFunctions;

void usage() {
    printf("Zadejte platné číslo testovací metody. ({%d} - {%d})", 0, TEST_FUNCTION_COUNT - 1);
    exit(-1);
}

int main(int argc, char** argv) {
    testFunctions = malloc(TEST_FUNCTION_COUNT * sizeof(TestFunction));
    testFunctions[0] = scannerTest;
    testFunctions[1] = nextTest;
    testFunctions[2] = nextBooleanTest;
    testFunctions[3] = nextByteTest;
    testFunctions[4] = nextShortTest;
    testFunctions[5] = nextIntTest;
    testFunctions[6] = nextLongTest;
    testFunctions[7] = nextFloatTest;
    testFunctions[8] = nextDoubleTest;
    testFunctions[9] = nextLineTest;
    int32_t n;

    if (argc < 2)
    {
        usage();
    }

    n = strtol(argv[1], NULL, 10);
    testFunctions[n]();

    return (errorsInFunction);
}
