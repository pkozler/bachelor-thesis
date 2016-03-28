#include <stdio.h>
#include <stdlib.h>

#include "test.h"

#define TEST_COUNT 2

/*
 * Simple C Test Suite
 */

void test1() {
    assertEqualsI(0, 0);
}

void test2() {
    assertEqualsI(0, 1);
}

int main(int argc, char** argv) {
    setUpTestModule("MathTest", TEST_COUNT);
    
    registerTest(test1, "test1");
    registerTest(test2, "test2");
    
    runTests();

    return (EXIT_SUCCESS);
}
