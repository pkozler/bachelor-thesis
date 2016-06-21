#include "Scanner.h"

#include <cstdlib>
#include <sstream>
#include "Boolean.h"
#include "Byte.h"
#include "Short.h"
#include "Integer.h"
#include "Long.h"
#include "Float.h"
#include "Double.h"

/*
    Reads the line from the standard input.
*/
String *Scanner::readLine() {
    std::string line;
    // reading the new line
    std::getline(std::cin, line);
    
    return new String(line);
}

/*
    Returns TRUE if and only if there is only the white-space characters
    left in the line or if the current scanned line is already empty.
*/
bool Scanner::isEmptyOrWhiteSpace(std::string line) {
    // testing the size and the position of the first non-whitespace character
    return line.size() == 0 || 
            line.find_first_not_of(" \t\n\x0b\f\r") == std::string::npos;
}

/*
    Removes all leading white-space characters from the line.
*/
std::string Scanner::trimStart(std::string line) {
    const char* white_spaces = " \t\n\x0b\r\f";

    // finding the first non-whitespace character
    int32_t first = line.find_first_not_of(white_spaces);
    
    // returning an empty line if there are only whitespaces
    if (first == std::string::npos) {
        return std::string("");
    }

    // returning the substring without the leading whitespaces
    return line.substr(first, line.size());
}

/*
    Removes the part of the current line to the first white-space character
    after the first sequence of non-whitespace characters and returns this
    part as the scanned token.
*/
std::string Scanner::removeLineToWhiteSpace() {
    this->line = trimStart(this->line);
    // finding the first whitespace after the sequence of non whitespace charaters
    int32_t i = line.find_first_of(" \t\n\x0b\f\r");
    // getting the next token
    std::string token = this->line.substr(0, i);
    // removing the token from the current line
    this->line = this->line.erase(0, i);
    
    return token;
}

/*
    Returns the next token of the current line or reads the new line
    from the standard input if the current line has been scanned completely.
*/
String *Scanner::getNextToken() {
    // reading the next line if the current is empty
    while (isEmptyOrWhiteSpace(this->line)) {
        String *line = readLine();
        // removing all leading whitespaces
        this->line = trimStart(line->_s());
        delete line;
    }

    // returning the next scanned token
    return new String(removeLineToWhiteSpace()); 
}

/**
 * Constructs a new Scanner that produces values scanned from the specified
 * input stream.
 *
 * @param source An input stream to be scanned
 */
Scanner::Scanner(InputStream *source) {
    this->line = "";
}

/**
 * Finds and returns the next complete token from this scanner.
 *
 * @return the next token
 */
String *Scanner::next() {
    return getNextToken();
}

/**
 * Scans the next token of the input into a boolean value and returns that
 * value.
 *
 * @return the boolean scanned from the input
 */
bool Scanner::nextBoolean() {
    return Boolean::parseBoolean(getNextToken());
}

/**
 * Scans the next token of the input as a byte.
 *
 * @return the byte scanned from the input
 */
int8_t Scanner::nextByte() {
    return Byte::parseByte(getNextToken());
}

/**
 * Scans the next token of the input as a short.
 *
 * @return the short scanned from the input
 */
int16_t Scanner::nextShort() {
    return Short::parseShort(getNextToken());
}

/**
 * Scans the next token of the input as an int.
 *
 * @return the int scanned from the input
 */
int32_t Scanner::nextInt() {
    return Integer::parseInt(getNextToken());
}

/**
 * Scans the next token of the input as a long.
 * 
 * @return the long scanned from the input
 */
int64_t Scanner::nextLong() {
    return Long::parseLong(getNextToken());
}

/**
 * Scans the next token of the input as a float.
 * 
 * @return the float scanned from the input
 */
float Scanner::nextFloat() {
    return Float::parseFloat(getNextToken());
}

/**
 * Scans the next token of the input as a double.
 * 
 * @return the double scanned from the input
 */
double Scanner::nextDouble() {
    return Double::parseDouble(getNextToken());
}

/**
 * Advances this scanner past the current line and returns the input that was skipped.
 * 
 * @return the line that was skipped
 */
String *Scanner::nextLine() {
    // reading the next line if the current is empty
    if ((this->line.size()) == 0) {
        return readLine();
    }
    
    // returning the rest of the current line if not empty
    String *str = new String(this->line);
    this->line = "";

    return str;
}
