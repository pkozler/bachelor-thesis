#include "test.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "math.h"

void assertEqualsBool(bool expected, bool actual) {
    if (expected != actual) {
        printf("%%TEST_FAILED%% time=0 testname=%s (%s) message=Expected: %s; Actual: %s\n", 
            testList[counter].testFunctionName, testFileName, 
                expected ? "true" : "false", actual ? "true" : "false");
    }
}

void assertEqualsB(int8_t expected, int8_t actual) {
    if (expected != actual) {
        printf("%%TEST_FAILED%% time=0 testname=%s (%s) message=Expected: %d; Actual: %d\n", 
            testList[counter].testFunctionName, testFileName, expected, actual);
    }
}

void assertEqualsS(int16_t expected, int16_t actual) {
    if (expected != actual) {
        printf("%%TEST_FAILED%% time=0 testname=%s (%s) message=Expected: %d; Actual: %d\n", 
            testList[counter].testFunctionName, testFileName, expected, actual);
    }
}

void assertEqualsI(int32_t expected, int32_t actual) {
    if (expected != actual) {
        printf("%%TEST_FAILED%% time=0 testname=%s (%s) message=Expected: %d; Actual: %d\n", 
            testList[counter].testFunctionName, testFileName, expected, actual);
    }
}

void assertEqualsL(int64_t expected, int64_t actual) {
    if (expected != actual) {
        printf("%%TEST_FAILED%% time=0 testname=%s (%s) message=Expected: %lld; Actual: %lld\n", 
            testList[counter].testFunctionName, testFileName, expected, actual);
    }
}

void assertEqualsF(float expected, float actual, float epsilon) {
    if (fabsf(expected - actual) >= epsilon) {
        printf("%%TEST_FAILED%% time=0 testname=%s (%s) message=Expected: %f; Actual: %f\n", 
            testList[counter].testFunctionName, testFileName, expected, actual);
    }
}

void assertEqualsD(double expected, double actual, double epsilon) {
    if (fabs(expected - actual) >= epsilon) {
        printf("%%TEST_FAILED%% time=0 testname=%s (%s) message=Expected: %lf; Actual: %lf\n", 
            testList[counter].testFunctionName, testFileName, expected, actual);
    }
}

void assertEqualsC(char expected, char actual) {
    if (expected != actual) {
        printf("%%TEST_FAILED%% time=0 testname=%s (%s) message=Expected: %c; Actual: %c\n", 
            testList[counter].testFunctionName, testFileName, expected, actual);
    }
}

void assertEqualsStr(char *expected, char *actual) {
    if (strcmp(expected, actual)) {
        printf("%%TEST_FAILED%% time=0 testname=%s (%s) message=Expected: %s; Actual: %s\n", 
            testList[counter].testFunctionName, testFileName, expected, actual);
    }
}

void setUpTestModule(char *name, int32_t count) {
    counter = 0;
    testFileName = name;
    testCount = count;
    testList = malloc(testCount * sizeof(TestContainer));
}

void registerTest(void (*testFunction)(), char *testFunctionName) {
    testList[counter].testFunction = testFunction;
    testList[counter].testFunctionName = testFunctionName;
    counter++;
}

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