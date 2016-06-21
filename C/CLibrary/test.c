#include "test.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "math.h"

/**
 * Verifies if the actual test result bool value is equal to the expected value.
 * If the values are not equal, prints the message showing the specified values.
 * 
 * @param expected expected value
 * @param actual actual value
 */
void assertEqualsBool(bool expected, bool actual) {
    if (expected != actual) {
        printf("%%TEST_FAILED%% time=0 testname=%s (%s) message=Expected: %s; Actual: %s\n", 
            testList[counter].testFunctionName, testFileName, 
                expected ? "true" : "false", actual ? "true" : "false");
    }
}

/**
 * Verifies if the actual test result int8_t value is equal to the expected value.
 * If the values are not equal, prints the message showing the specified values.
 * 
 * @param expected expected value
 * @param actual actual value
 */
void assertEqualsB(int8_t expected, int8_t actual) {
    if (expected != actual) {
        printf("%%TEST_FAILED%% time=0 testname=%s (%s) message=Expected: %d; Actual: %d\n", 
            testList[counter].testFunctionName, testFileName, expected, actual);
    }
}

/**
 * Verifies if the actual test result int16_t value is equal to the expected value.
 * If the values are not equal, prints the message showing the specified values.
 * 
 * @param expected expected value
 * @param actual actual value
 */
void assertEqualsS(int16_t expected, int16_t actual) {
    if (expected != actual) {
        printf("%%TEST_FAILED%% time=0 testname=%s (%s) message=Expected: %d; Actual: %d\n", 
            testList[counter].testFunctionName, testFileName, expected, actual);
    }
}

/**
 * Verifies if the actual test result int32_t value is equal to the expected value.
 * If the values are not equal, prints the message showing the specified values.
 * 
 * @param expected expected value
 * @param actual actual value
 */
void assertEqualsI(int32_t expected, int32_t actual) {
    if (expected != actual) {
        printf("%%TEST_FAILED%% time=0 testname=%s (%s) message=Expected: %d; Actual: %d\n", 
            testList[counter].testFunctionName, testFileName, expected, actual);
    }
}

/**
 * Verifies if the actual test result int64_t value is equal to the expected value.
 * If the values are not equal, prints the message showing the specified values.
 * 
 * @param expected expected value
 * @param actual actual value
 */
void assertEqualsL(int64_t expected, int64_t actual) {
    if (expected != actual) {
        printf("%%TEST_FAILED%% time=0 testname=%s (%s) message=Expected: %lld; Actual: %lld\n", 
            testList[counter].testFunctionName, testFileName, expected, actual);
    }
}

/**
 * Verifies if the difference between the actual test result float value
 * and the expected value is less than the specified epsilon value.
 * If the difference greater, prints the message showing the specified values.
 * 
 * @param expected expected value
 * @param actual actual value
 * @param epsilon maximal difference
 */
void assertEqualsF(float expected, float actual, float epsilon) {
    if (fabsf(expected - actual) >= epsilon) {
        printf("%%TEST_FAILED%% time=0 testname=%s (%s) message=Expected: %f; Actual: %f\n", 
            testList[counter].testFunctionName, testFileName, expected, actual);
    }
}

/**
 * Verifies if the difference between the actual test result double value
 * and the expected value is less than the specified epsilon value.
 * If the difference greater, prints the message showing the specified values.
 * 
 * @param expected expected value
 * @param actual actual value
 * @param epsilon maximal difference
 */
void assertEqualsD(double expected, double actual, double epsilon) {
    if (fabs(expected - actual) >= epsilon) {
        printf("%%TEST_FAILED%% time=0 testname=%s (%s) message=Expected: %lf; Actual: %lf\n", 
            testList[counter].testFunctionName, testFileName, expected, actual);
    }
}

/**
 * Verifies if the actual test result char value is equal to the expected value.
 * If the values are not equal, prints the message showing the specified values.
 * 
 * @param expected expected value
 * @param actual actual value
 */
void assertEqualsC(char expected, char actual) {
    if (expected != actual) {
        printf("%%TEST_FAILED%% time=0 testname=%s (%s) message=Expected: %c; Actual: %c\n", 
            testList[counter].testFunctionName, testFileName, expected, actual);
    }
}

/**
 * Verifies if the actual test result string value is equal to the expected value.
 * If the values are not equal, prints the message showing the specified values.
 * 
 * @param expected expected value
 * @param actual actual value
 */
void assertEqualsStr(char *expected, char *actual) {
    if (strcmp(expected, actual)) {
        printf("%%TEST_FAILED%% time=0 testname=%s (%s) message=Expected: %s; Actual: %s\n", 
            testList[counter].testFunctionName, testFileName, expected, actual);
    }
}

/**
 * Initializes the module global variables for the new test suite.
 * 
 * @param name test suite name
 * @param count test funtion count
 */
void setUpTestModule(char *name, int32_t count) {
    counter = 0;
    testFileName = name;
    testCount = count;
    testList = malloc(testCount * sizeof(TestContainer));
}

/**
 * Adds the specified test function pointer to the array for the new test run.
 * 
 * @param testFunction test function pointer
 * @param testFunctionName test function name
 */
void registerTest(void (*testFunction)(), char *testFunctionName) {
    testList[counter].testFunction = testFunction;
    testList[counter].testFunctionName = testFunctionName;
    counter++;
}

/**
 * Calls the functions registered in the test function array and prints
 * the test messages.
 */
void runTests() {
    printf("%%SUITE_STARTING%% %s\n", testFileName);
    printf("%%SUITE_STARTED%%\n");

    for (counter = 0; counter < testCount; counter++) {
        printf("%%TEST_STARTED%% %s (%s)\n", testList[counter].testFunctionName, testFileName);
        testList[counter].testFunction();
        printf("%%TEST_FINISHED%% time=0 %s (%s) \n", testList[counter].testFunctionName, testFileName);
    }
    
    printf("%%SUITE_FINISHED%% time=0\n");
    free(testList);
}