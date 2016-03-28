#include "test.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void assertEqualsBool(bool expected, bool actual) {
    if (expected != actual) {
        printf("%%TEST_FAILED%% time=0 testname=%s (%s) message=Expected: %s; Actual: %s\n", 
            testFunctionList[counter].testFunctionName, testModuleName, 
                expected ? "true" : "false", actual ? "true" : "false");
    }
}

void assertEqualsB(int8_t expected, int8_t actual) {
    if (expected != actual) {
        printf("%%TEST_FAILED%% time=0 testname=%s (%s) message=Expected: %d; Actual: %d\n", 
            testFunctionList[counter].testFunctionName, testModuleName, expected, actual);
    }
}

void assertEqualsS(int16_t expected, int16_t actual) {
    if (expected != actual) {
        printf("%%TEST_FAILED%% time=0 testname=%s (%s) message=Expected: %d; Actual: %d\n", 
            testFunctionList[counter].testFunctionName, testModuleName, expected, actual);
    }
}

void assertEqualsI(int32_t expected, int32_t actual) {
    if (expected != actual) {
        printf("%%TEST_FAILED%% time=0 testname=%s (%s) message=Expected: %d; Actual: %d\n", 
            testFunctionList[counter].testFunctionName, testModuleName, expected, actual);
    }
}

void assertEqualsL(int64_t expected, int64_t actual) {
    if (expected != actual) {
        printf("%%TEST_FAILED%% time=0 testname=%s (%s) message=Expected: %lld; Actual: %lld\n", 
            testFunctionList[counter].testFunctionName, testModuleName, expected, actual);
    }
}

void assertEqualsF(float expected, float actual, float epsilon) {
    if (fabsf(expected - actual) >= epsilon) {
        printf("%%TEST_FAILED%% time=0 testname=%s (%s) message=Expected: %f; Actual: %f\n", 
            testFunctionList[counter].testFunctionName, testModuleName, expected, actual);
    }
}

void assertEqualsD(double expected, double actual, double epsilon) {
    if (fabs(expected - actual) >= epsilon) {
        printf("%%TEST_FAILED%% time=0 testname=%s (%s) message=Expected: %lf; Actual: %lf\n", 
            testFunctionList[counter].testFunctionName, testModuleName, expected, actual);
    }
}

void assertEqualsC(char expected, char actual) {
    if (expected != actual) {
        printf("%%TEST_FAILED%% time=0 testname=%s (%s) message=Expected: %c; Actual: %c\n", 
            testFunctionList[counter].testFunctionName, testModuleName, expected, actual);
    }
}

void assertEqualsStr(char *expected, char *actual) {
    if (strcmp(expected, actual)) {
        printf("%%TEST_FAILED%% time=0 testname=%s (%s) message=Expected: %s; Actual: %s\n", 
            testFunctionList[counter].testFunctionName, testModuleName, expected, actual);
    }
}

void setUpTestModule(char *name, int32_t count) {
    counter = 0;
    testModuleName = name;
    testFunctionCount = count;
    testFunctionList = malloc(testFunctionCount * sizeof(TestContainer));
}

void registerTest(void (*testFunction)(), char *testFunctionName) {
    testFunctionList[counter].testFunction = testFunction;
    testFunctionList[counter].testFunctionName = testFunctionName;
    counter++;
}

void runTests() {
    printf("%%SUITE_STARTING%% MathTest\n");
    printf("%%SUITE_STARTED%%\n");

    for (counter = 0; counter < testFunctionCount; counter++) {
        printf("%%TEST_STARTED%% %s (%s)\n", testFunctionList[counter].testFunctionName, testModuleName);
        testFunctionList[counter].testFunction();
        printf("%%TEST_FINISHED%% time=0 %s (%s) \n", testFunctionList[counter].testFunctionName, testModuleName);
    }
    
    printf("%%SUITE_FINISHED%% time=0\n");
    free(testFunctionList);
}