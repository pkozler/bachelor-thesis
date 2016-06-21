#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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
    printf("Zadejte platné číslo testovací metody. (%d - %d)", 0, TEST_FUNCTION_COUNT - 1);
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
