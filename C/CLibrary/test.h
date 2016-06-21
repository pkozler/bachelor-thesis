#ifndef TEST_H
#define	TEST_H

#include <stdbool.h>
#include <stdint.h>


/**
 * Test module provides the functions for running the registered test functions
 * and for verifying the result values.
 * 
 * @author Petr Kozler (A13B0359P)
 */

/**
 * TestContainer struct serves as a container for the test function pointer 
 * and the string value which holds the name of the test function.
 */
typedef struct {
    // a test function to call
    void (*testFunction)();
    // a test function name to print in the test results
    char *testFunctionName;
} TestContainer;

// a test module name to print in the test results
char *testFileName;
// a test function count
int32_t testCount;
// a test function counter for creating the array
int32_t counter;
// a test function pointer array
TestContainer *testList;

void assertEqualsBool(bool expected, bool actual);
void assertEqualsB(int8_t expected, int8_t actual);
void assertEqualsS(int16_t expected, int16_t actual);
void assertEqualsI(int32_t expected, int32_t actual);
void assertEqualsL(int64_t expected, int64_t actual);
void assertEqualsF(float expected, float actual, float epsilon);
void assertEqualsD(double expected, double actual, double epsilon);
void assertEqualsC(char expected, char actual);
void assertEqualsStr(char *expected, char *actual);
void setUpTestModule(char *name, int32_t count);
void registerTest(void (*testFunction)(), char *testFunctionName);
void runTests();

#endif	// TEST_H