#include "Scanner.h"

#include <cstdlib>
#include <sstream>

Scanner::Scanner(void *source) {
}

Scanner::Scanner() {
}

Scanner::~Scanner() {
}

String *Scanner::next() {
    std::string s;
    std::cin >> s;

    return new String(s);
}

bool Scanner::nextBoolean() {
    bool b;
    std::cin >> b;

    return b;
}

char Scanner::nextByte() {
    int b;
    std::cin >> b;

    return (char) b;
}

short Scanner::nextShort() {
    short s;
    std::cin >> s;

    return s;
}

int Scanner::nextInt() {
    int i;
    std::cin >> i;

    return i;
}

long Scanner::nextLong() {
    long l;
    std::cin >> l;

    return l;
}

float Scanner::nextFloat() {
    float f;
    std::cin >> f;

    return f;
}

double Scanner::nextDouble() {
    double d;
    std::cin >> d;

    return d;
}

String *Scanner::nextLine() {
    std::string s;
    std::getline(std::cin, s);

    return new String(s);
}
