#include "test.h"

#include <cstring>
#include <cmath>

TestContainer::TestContainer(void(*testFunction)(), std::string testFunctionName) {
    this->testFunction = testFunction;
    this->testFunctionName = testFunctionName;
}

std::string Test::testFileName = "";
int32_t Test::counter = 0;
std::vector<TestContainer> Test::testList;

void Test::assertEquals(bool expected, bool actual) {
    if (expected != actual) {
        std::cout << "%TEST_FAILED% time=0 testname=" << testList[counter].testFunctionName
                << " (" << testFileName << ") message=Expected: " 
                << (expected ? "true" : "false") << "; Actual: " 
                << (actual ? "true" : "false") << std::endl;
    }
}

void Test::assertEquals(int8_t expected, int8_t actual) {
    if (expected != actual) {
        std::cout << "%TEST_FAILED% time=0 testname=" << testList[counter].testFunctionName
                << " (" << testFileName << ") message=Expected: " 
                << expected << "; Actual: " << actual << std::endl;
    }
}

void Test::assertEquals(int16_t expected, int16_t actual) {
    if (expected != actual) {
        std::cout << "%TEST_FAILED% time=0 testname=" << testList[counter].testFunctionName
                << " (" << testFileName << ") message=Expected: " 
                << expected << "; Actual: " << actual << std::endl;
    }
}

void Test::assertEquals(int32_t expected, int32_t actual) {
    if (expected != actual) {
        std::cout << "%TEST_FAILED% time=0 testname=" << testList[counter].testFunctionName
                << " (" << testFileName << ") message=Expected: " 
                << expected << "; Actual: " << actual << std::endl;
    }
}

void Test::assertEquals(int64_t expected, int64_t actual) {
    if (expected != actual) {
        std::cout << "%TEST_FAILED% time=0 testname=" << testList[counter].testFunctionName
                << " (" << testFileName << ") message=Expected: " 
                << expected << "; Actual: " << actual << std::endl;
    }
}

void Test::assertEquals(float expected, float actual) {
    if (expected != actual) {
        std::cout << "%TEST_FAILED% time=0 testname=" << testList[counter].testFunctionName
                << " (" << testFileName << ") message=Expected: " 
                << expected << "; Actual: " << actual << std::endl;
    }
}

void Test::assertEquals(double expected, double actual) {
    if (expected != actual) {
        std::cout << "%TEST_FAILED% time=0 testname=" << testList[counter].testFunctionName
                << " (" << testFileName << ") message=Expected: " 
                << expected << "; Actual: " << actual << std::endl;
    }
}

void Test::assertEquals(float expected, float actual, float epsilon) {
    if (std::abs(expected - actual) >= epsilon) {
        std::cout << "%TEST_FAILED% time=0 testname=" << testList[counter].testFunctionName
                << " (" << testFileName << ") message=Expected: " 
                << expected << "; Actual: " << actual << std::endl;
    }
}

void Test::assertEquals(double expected, double actual, double epsilon) {
    if (std::abs(expected - actual) >= epsilon) {
        std::cout << "%TEST_FAILED% time=0 testname=" << testList[counter].testFunctionName
                << " (" << testFileName << ") message=Expected: " 
                << expected << "; Actual: " << actual << std::endl;
    }
}

void Test::assertEquals(char expected, char actual) {
    if (expected != actual) {
        std::cout << "%TEST_FAILED% time=0 testname=" << testList[counter].testFunctionName
                << " (" << testFileName << ") message=Expected: " 
                << expected << "; Actual: " << actual << std::endl;
    }
}

void Test::assertEquals(std::string expected, std::string actual) {
    if (expected.compare(actual)) {
        std::cout << "%TEST_FAILED% time=0 testname=" << testList[counter].testFunctionName
                << " (" << testFileName << ") message=Expected: " 
                << expected << "; Actual: " << actual << std::endl;
    }
}

void Test::setUpTestModule(std::string name) {
    testFileName = name;
}

void Test::registerTest(void (*testFunction)(), std::string testFunctionName) {
    TestContainer tc(testFunction, testFunctionName);
    testList.push_back(tc);
}

void Test::runTests() {
    std::cout << "%SUITE_STARTING% " << testFileName << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    int32_t count = testList.size();
    for (counter = 0; counter < count; counter++) {
        std::cout << "%TEST_STARTED% " << testList[counter].testFunctionName
                << " (" << testFileName << ")" << std::endl;
        testList[counter].testFunction();
        std::cout << "%TEST_FINISHED% time=0 " << testList[counter].testFunctionName
                << " (" << testFileName << ")" << std::endl;
    }
    
    std::cout << "%SUITE_FINISHED% time=0" << std::endl;
    testList.clear();
}