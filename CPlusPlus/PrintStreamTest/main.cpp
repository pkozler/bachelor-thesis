#include <cstdlib>
#include <iostream>
#include <cstdint>

#include "PrintStreamTest.h"

typedef void (*TestFunction)();

const int32_t TEST_FUNCTION_COUNT = 19;

TestFunction *testFunctions;

void usage() {
    std::cout << "Zadejte platné číslo testovací metody. (" << 0 << " - " << TEST_FUNCTION_COUNT - 1 << ")";
    exit(-1);
}

int main(int argc, char** argv) {
    testFunctions = new TestFunction[] {
        printTest,
        printTest2,
        printTest3,
        printTest4,
        printTest5,
        printTest6,
        printTest7,
        printTest8,
        printTest9,
        printlnTest,
        printlnTest2,
        printlnTest3,
        printlnTest4,
        printlnTest5,
        printlnTest6,
        printlnTest7,
        printlnTest8,
        printlnTest9,
        printlnTest10,
    };
    int32_t n;

    if (argc < 2)
    {
        usage();
    }

    n = strtol(argv[1], NULL, 10);
    testFunctions[n]();

    return (EXIT_SUCCESS);
}
