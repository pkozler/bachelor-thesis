#include <cstdlib>
#include <iostream>

#include "test.h"

/*
 * Simple C++ Test Suite
 */

void test1() {
    Test::assertEquals(0, 0);
}

void test2() {
    Test::assertEquals(0, 1);
}

int main(int argc, char** argv) {
    Test::setUpTestModule("MathTest");
    Test::registerTest(test1, "test1");
    Test::registerTest(test2, "test2");
    Test::runTests();
    
    return (EXIT_SUCCESS);
}

