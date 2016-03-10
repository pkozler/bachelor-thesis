#ifndef SYSTEM_INCLUDED
#define	SYSTEM_INCLUDED

#include "String.h"
#include <cstdint>

class PrintStream {
public:
    PrintStream();
    ~PrintStream();
    void print(bool b);
    void print(char c);
    void print(char* s);
    void print(double d);
    void print(float f);
    void print(int32_t i);
    void print(int64_t l);
    void print(String *s);
    void println();
    void println(bool x);
    void println(char x);
    void println(char* x);
    void println(double x);
    void println(float x);
    void println(int32_t x);
    void println(int64_t x);
    void println(String *x);
};

class System {
    static const int32_t DEFAULT_RADIX;
    System();
    ~System();
public:
    static void *in;
    static PrintStream *out;
};

#endif	// SYSTEM_INCLUDED
