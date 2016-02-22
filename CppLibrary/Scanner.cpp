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

int8_t Scanner::nextByte() {
    int8_t b;
    std::cin >> b;

    return b;
}

int16_t Scanner::nextShort() {
    int16_t s;
    std::cin >> s;

    return s;
}

int32_t Scanner::nextInt() {
    int32_t i;
    std::cin >> i;

    return i;
}

int64_t Scanner::nextLong() {
    int64_t l;
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
