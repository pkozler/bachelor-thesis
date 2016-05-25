#ifndef TEST_H
#define	TEST_H

#include <stdbool.h>
#include <stdint.h>

typedef struct {
    void (*testFunction)();
    char *testFunctionName;
} TestContainer;

char *testFileName;
int32_t testCount;
int32_t counter;
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