#include "Scanner.h"

#include <cstdlib>
#include <sstream>

/**
 * Constructs a new Scanner that produces values scanned from the specified
 * input stream.
 *
 * @param source An input stream to be scanned
 */
Scanner::Scanner(void *source) {
    // really no code
}

Scanner::Scanner() {
    // really no code
}

Scanner::~Scanner() {
    // really no code
}

/**
 * Finds and returns the next complete token from this scanner.
 *
 * @return the next token
 */
String *Scanner::next() {
    std::string s;
    std::cin >> s;

    return new String(s);
}

/**
 * Scans the next token of the input into a boolean value and returns that
 * value.
 *
 * @return the boolean scanned from the input
 */
bool Scanner::nextBoolean() {
    bool b;
    std::cin >> b;

    return b;
}

/**
 * Scans the next token of the input as a byte.
 *
 * @return the byte scanned from the input
 */
int8_t Scanner::nextByte() {
    int8_t b;
    std::cin >> b;

    return b;
}

/**
 * Scans the next token of the input as a short.
 *
 * @return the short scanned from the input
 */
int16_t Scanner::nextShort() {
    int16_t s;
    std::cin >> s;

    return s;
}

/**
 * Scans the next token of the input as an int.
 *
 * @return the int scanned from the input
 */
int32_t Scanner::nextInt() {
    int32_t i;
    std::cin >> i;

    return i;
}

/**
 * Scans the next token of the input as a long.
 * 
 * @return the long scanned from the input
 */
int64_t Scanner::nextLong() {
    int64_t l;
    std::cin >> l;

    return l;
}

/**
 * Scans the next token of the input as a float.
 * 
 * @return the float scanned from the input
 */
float Scanner::nextFloat() {
    float f;
    std::cin >> f;

    return f;
}

/**
 * Scans the next token of the input as a double.
 * 
 * @return the double scanned from the input
 */
double Scanner::nextDouble() {
    double d;
    std::cin >> d;

    return d;
}

/**
 * Advances this scanner past the current line and returns the input that was skipped.
 * 
 * @return the line that was skipped
 */
String *Scanner::nextLine() {
    std::string s;
    std::getline(std::cin, s);

    return new String(s);
}
