#include "System.h"

#include <iostream>

/**
 * Prints a boolean value.
 *
 * @param b The boolean to be printed
 */
void PrintStream::print(bool b) {
    std::cout << (b ? "true" : "false");
}

/**
 * Prints a character.
 *
 * @param c The char to be printed
 */
void PrintStream::print(char c) {
    std::cout << c;
}

/**
 * Prints an array of characters.
 *
 * @param s The array of chars to be printed
 */
void PrintStream::print(char* s, int32_t length) {
    for (int i = 0; i < length; i++) {
        std::cout << s[i];
    }
}

/**
 * Prints a double-precision floating-point number.
 *
 * @param d The double to be printed
 */
void PrintStream::print(double d) {
    std::cout << d;
}

/**
 * Prints a floating-point number.
 *
 * @param f The float to be printed
 */
void PrintStream::print(float f) {
    std::cout << f;
}

/**
 * Prints an integer.
 *
 * @param i The int to be printed
 */
void PrintStream::print(int32_t i) {
    std::cout << i;
}

/**
 * Prints a long integer.
 *
 * @param l The long to be printed
 */
void PrintStream::print(int64_t l) {
    std::cout << l;
}

/**
 * Prints an object.
 *
 * @param obj The Object to be printed
 */
void PrintStream::print(Object *obj) {
    String *s = obj->toString();
    std::cout << s->_s();
    delete s;
}

/**
 * Prints a string.
 *
 * @param s The String to be printed
 */
void PrintStream::print(String *s) {
    std::cout << s->_s();
}

/**
 * Terminates the current line by writing the line separator string.
 */
void PrintStream::println() {
    std::cout << std::endl;
}

/**
 * Prints a boolean and then terminate the line.
 *
 * @param x The boolean to be printed
 */
void PrintStream::println(bool x) {
    std::cout << (x ? "true" : "false") << std::endl;
}

/**
 * Prints a character and then terminate the line.
 *
 * @param x The char to be printed.
 */
void PrintStream::println(char x) {
    std::cout << x << std::endl;
}

/**
 * Prints an array of characters and then terminate the line.
 *
 * @param x an array of chars to print.
 */
void PrintStream::println(char* x, int32_t length) {
    for (int i = 0; i < length; i++) {
        std::cout << x[i];
    }
    
    std::cout << "" << std::endl;
}

/**
 * Prints a double and then terminate the line.
 *
 * @param x The double to be printed.
 */
void PrintStream::println(double x) {
    std::cout << x << std::endl;
}

/**
 * Prints a float and then terminate the line.
 *
 * @param x The float to be printed.
 */
void PrintStream::println(float x) {
    std::cout << x << std::endl;
}

/**
 * Prints an integer and then terminate the line.
 *
 * @param x The int to be printed.
 */
void PrintStream::println(int32_t x) {
    std::cout << x << std::endl;
}

/**
 * Prints a long and then terminate the line.
 *
 * @param x The long to be printed.
 */
void PrintStream::println(int64_t x) {
    std::cout << x << std::endl;
}

/**
 * Prints an Object and then terminate the line.
 *
 * @param x The Object to be printed.
 */
void PrintStream::println(Object *obj) {
    String *s = obj->toString();
    std::cout << s->_s() << std::endl;
    delete s;
}

/**
 * Prints a String and then terminate the line.
 *
 * @param x The String to be printed.
 */
void PrintStream::println(String *x) {
    std::cout << x->_s() << std::endl;
}

InputStream *System::in = new InputStream();
PrintStream *System::out = new PrintStream();