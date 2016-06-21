#include <cstdlib>
#include <iostream>
#include <cstdint>

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
    std::cout << "Zadejte platné číslo testovací metody. (" << 0 << " - " << TEST_FUNCTION_COUNT - 1 << ")";
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
