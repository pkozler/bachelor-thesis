#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "PrintStreamTest.h"

typedef void (*TestFunction)();

const int32_t TEST_FUNCTION_COUNT = 19;

TestFunction *testFunctions;

void usage() {
    printf("Zadejte platné číslo testovací metody. (%d - %d)", 0, TEST_FUNCTION_COUNT - 1);
    exit(-1);
}

int main(int argc, char** argv) {
    testFunctions = malloc(TEST_FUNCTION_COUNT * sizeof(TestFunction));
    testFunctions[0] = printTest;
    testFunctions[1] = printTest2;
    testFunctions[2] = printTest3;
    testFunctions[3] = printTest4;
    testFunctions[4] = printTest5;
    testFunctions[5] = printTest6;
    testFunctions[6] = printTest7;
    testFunctions[7] = printTest8;
    testFunctions[8] = printTest9;
    testFunctions[9] = printlnTest;
    testFunctions[10] = printlnTest2;
    testFunctions[11] = printlnTest3;
    testFunctions[12] = printlnTest4;
    testFunctions[13] = printlnTest5;
    testFunctions[14] = printlnTest6;
    testFunctions[15] = printlnTest7;
    testFunctions[16] = printlnTest8;
    testFunctions[17] = printlnTest9;
    testFunctions[18] = printlnTest10;
    int32_t n;

    if (argc < 2)
    {
        usage();
    }

    n = strtol(argv[1], NULL, 10);
    testFunctions[n]();

    return (EXIT_SUCCESS);
}
