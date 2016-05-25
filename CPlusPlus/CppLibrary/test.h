#ifndef TEST_H
#define	TEST_H

#include <cstdbool>
#include <cstdint>
#include <iostream>
#include <vector>

typedef void (*testFunction)();

class TestContainer {
public:
    std::string testFunctionName;
    void (*testFunction)();
    TestContainer(void (*testFunction)(), std::string testFunctionName);
};

class Test {
    static std::string testFileName;
    static int32_t counter;
    static std::vector<TestContainer> testList;
public:
    static void assertEquals(bool expected, bool actual);
    static void assertEquals(int8_t expected, int8_t actual);
    static void assertEquals(int16_t expected, int16_t actual);
    static void assertEquals(int32_t expected, int32_t actual);
    static void assertEquals(int64_t expected, int64_t actual);
    static void assertEquals(float expected, float actual);
    static void assertEquals(double expected, double actual);
    static void assertEquals(float expected, float actual, float epsilon);
    static void assertEquals(double expected, double actual, double epsilon);
    static void assertEquals(char expected, char actual);
    static void assertEquals(std::string expected, std::string actual);
    static void setUpTestModule(std::string name);
    static void registerTest(void (*testFunction)(), std::string testFunctionName);
    static void runTests();
};

#endif	// TEST_H