#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "ScannerTest.h"

/**
 * A Scanner class test utility.
 *
 * @author Petr Kozler (A13B0359P)
 */

// a test function pointer
typedef void (*TestFunction)();

// a test function pointer array length
const int32_t TEST_FUNCTION_COUNT = 10;

// an array of the test function pointers
TestFunction *testFunctions;

/*
    Prints help message if the specified function index is not valid.
*/
void usage() {
    printf("Zadejte platné číslo testovací metody. (%d - %d)", 0, TEST_FUNCTION_COUNT - 1);
    exit(-1);
}

/**
 * Calls the Scanner test function with the index specified in the command-line argument
 * and returns the count of errors found during the test as the exit status.
 *
 * @param argc command-line argument count
 * @param argv command-line arguments
 * @return exit status
 */
int main(int argc, char** argv) {
    errorsInFunction = 0;
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
