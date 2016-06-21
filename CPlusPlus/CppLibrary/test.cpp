#include "test.h"

#include <cstring>
#include <cmath>

/**
 * Creates a new test container.
 * 
 * @param testFunction a test function to call
 * @param testFunctionName a test function name to print in the test results
 */
TestContainer::TestContainer(void(*testFunction)(), std::string testFunctionName) {
    this->testFunction = testFunction;
    this->testFunctionName = testFunctionName;
}

// a test module name to print in the test results
std::string Test::testFileName = "";
// a test function count
int32_t Test::counter = 0;
// a test function pointer dynamic array
std::vector<TestContainer> Test::testList;

/**
 * Verifies if the actual test result bool value is equal to the expected value.
 * If the values are not equal, prints the message showing the specified values.
 * 
 * @param expected expected value
 * @param actual actual value
 */
void Test::assertEquals(bool expected, bool actual) {
    if (expected != actual) {
        std::cout << "%TEST_FAILED% time=0 testname=" << testList[counter].testFunctionName
                << " (" << testFileName << ") message=Expected: " 
                << (expected ? "true" : "false") << "; Actual: " 
                << (actual ? "true" : "false") << std::endl;
    }
}

/**
 * Verifies if the actual test result int8_t value is equal to the expected value.
 * If the values are not equal, prints the message showing the specified values.
 * 
 * @param expected expected value
 * @param actual actual value
 */
void Test::assertEquals(int8_t expected, int8_t actual) {
    if (expected != actual) {
        std::cout << "%TEST_FAILED% time=0 testname=" << testList[counter].testFunctionName
                << " (" << testFileName << ") message=Expected: " 
                << expected << "; Actual: " << actual << std::endl;
    }
}

/**
 * Verifies if the actual test result int16_t value is equal to the expected value.
 * If the values are not equal, prints the message showing the specified values.
 * 
 * @param expected expected value
 * @param actual actual value
 */
void Test::assertEquals(int16_t expected, int16_t actual) {
    if (expected != actual) {
        std::cout << "%TEST_FAILED% time=0 testname=" << testList[counter].testFunctionName
                << " (" << testFileName << ") message=Expected: " 
                << expected << "; Actual: " << actual << std::endl;
    }
}

/**
 * Verifies if the actual test result int32_t value is equal to the expected value.
 * If the values are not equal, prints the message showing the specified values.
 * 
 * @param expected expected value
 * @param actual actual value
 */
void Test::assertEquals(int32_t expected, int32_t actual) {
    if (expected != actual) {
        std::cout << "%TEST_FAILED% time=0 testname=" << testList[counter].testFunctionName
                << " (" << testFileName << ") message=Expected: " 
                << expected << "; Actual: " << actual << std::endl;
    }
}

/**
 * Verifies if the actual test result int64_t value is equal to the expected value.
 * If the values are not equal, prints the message showing the specified values.
 * 
 * @param expected expected value
 * @param actual actual value
 */
void Test::assertEquals(int64_t expected, int64_t actual) {
    if (expected != actual) {
        std::cout << "%TEST_FAILED% time=0 testname=" << testList[counter].testFunctionName
                << " (" << testFileName << ") message=Expected: " 
                << expected << "; Actual: " << actual << std::endl;
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
void Test::assertEquals(float expected, float actual, float epsilon) {
    if (std::abs(expected - actual) >= epsilon) {
        std::cout << "%TEST_FAILED% time=0 testname=" << testList[counter].testFunctionName
                << " (" << testFileName << ") message=Expected: " 
                << expected << "; Actual: " << actual << std::endl;
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
void Test::assertEquals(double expected, double actual, double epsilon) {
    if (std::abs(expected - actual) >= epsilon) {
        std::cout << "%TEST_FAILED% time=0 testname=" << testList[counter].testFunctionName
                << " (" << testFileName << ") message=Expected: " 
                << expected << "; Actual: " << actual << std::endl;
    }
}

/**
 * Verifies if the actual test result char value is equal to the expected value.
 * If the values are not equal, prints the message showing the specified values.
 * 
 * @param expected expected value
 * @param actual actual value
 */
void Test::assertEquals(char expected, char actual) {
    if (expected != actual) {
        std::cout << "%TEST_FAILED% time=0 testname=" << testList[counter].testFunctionName
                << " (" << testFileName << ") message=Expected: " 
                << expected << "; Actual: " << actual << std::endl;
    }
}

/**
 * Verifies if the actual test result string value is equal to the expected value.
 * If the values are not equal, prints the message showing the specified values.
 * 
 * @param expected expected value
 * @param actual actual value
 */
void Test::assertEquals(std::string expected, std::string actual) {
    if (expected.compare(actual)) {
        std::cout << "%TEST_FAILED% time=0 testname=" << testList[counter].testFunctionName
                << " (" << testFileName << ") message=Expected: " 
                << expected << "; Actual: " << actual << std::endl;
    }
}

/**
 * Initializes the module global variables for the new test suite.
 * 
 * @param name test suite name
 * @param count test funtion count
 */
void Test::setUpTestModule(std::string name) {
    testFileName = name;
}

/**
 * Adds the specified test function pointer to the array for the new test run.
 * 
 * @param testFunction test function pointer
 * @param testFunctionName test function name
 */
void Test::registerTest(void (*testFunction)(), std::string testFunctionName) {
    TestContainer tc(testFunction, testFunctionName);
    testList.push_back(tc);
}

/**
 * Calls the functions registered in the test function array and prints
 * the test messages.
 */
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