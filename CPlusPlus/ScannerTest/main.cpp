#include <cstdlib>
#include <iostream>
#include <cstdint>

#include "ScannerTest.h"

typedef void (*TestFunction)();

const int32_t TEST_FUNCTION_COUNT = 10;

TestFunction *testFunctions;

void usage() {
    std::cout << "Zadejte platné číslo testovací metody. (" << 0 << " - " << TEST_FUNCTION_COUNT - 1 << ")";
    exit(-1);
}

int main(int argc, char** argv) {
    errorsInFunction = 0;
    testFunctions = new TestFunction[TEST_FUNCTION_COUNT] {
        scannerTest,
        nextTest,
        nextBooleanTest,
        nextByteTest,
        nextShortTest,
        nextIntTest,
        nextLongTest,
        nextFloatTest,
        nextDoubleTest,
        nextLineTest,
    };
    int32_t n;

    if (argc < 2) {
        usage();
    }

    n = strtol(argv[1], NULL, 10);
    testFunctions[n]();

    return (errorsInFunction);
}
