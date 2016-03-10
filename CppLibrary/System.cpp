#include "System.h"

#include <iostream>

PrintStream::PrintStream() {
    // really no code
}

PrintStream::~PrintStream() {
    // really no code
}

void PrintStream::print(bool b) {
    std::cout << (b ? "true" : "false");
}

void PrintStream::print(char c) {
    std::cout << c;
}

void PrintStream::print(char* s) {
    std::cout << s;
}

void PrintStream::print(double d) {
    std::cout << d;
}

void PrintStream::print(float f) {
    std::cout << f;
}

void PrintStream::print(int32_t i) {
    std::cout << i;
}

void PrintStream::print(int64_t l) {
    std::cout << l;
}

void PrintStream::print(String *s) {
    std::cout << s->toString();
}

void PrintStream::println() {
    std::cout << std::endl;
}

void PrintStream::println(bool x) {
    std::cout << (x ? "true" : "false") << std::endl;
}

void PrintStream::println(char x) {
    std::cout << x << std::endl;
}

void PrintStream::println(char* x) {
    std::cout << x << std::endl;
}

void PrintStream::println(double x) {
    std::cout << x << std::endl;
}

void PrintStream::println(float x) {
    std::cout << x << std::endl;
}

void PrintStream::println(int32_t x) {
    std::cout << x << std::endl;
}

void PrintStream::println(int64_t x) {
    std::cout << x << std::endl;
}

void PrintStream::println(String *x) {
    std::cout << x->toString() << std::endl;
}

void *System::in = nullptr;

PrintStream *System::out = new PrintStream();

System::System() {
    // really no code
}

System::~System() {
    // really no code
}