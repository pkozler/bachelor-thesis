#include <cstdlib>
#include <iostream>
#include <cstdint>

#include "PrintStreamTest.h"

/**
 * A PrintStream class test utility.
 *
 * @author Petr Kozler (A13B0359P)
 */

// a test function pointer
typedef void (*TestFunction)();

// a test function pointer array length
const int32_t TEST_FUNCTION_COUNT = 19;

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
 * Calls the PrintStream test function with the index specified in the command-line argument
 * and returns the count of errors found during the test as the exit status.
 *
 * @param argc command-line argument count
 * @param argv command-line arguments
 * @return exit status
 */
int main(int argc, char** argv) {
    testFunctions = new TestFunction[TEST_FUNCTION_COUNT] {
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
