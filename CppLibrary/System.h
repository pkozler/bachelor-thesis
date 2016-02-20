#ifndef SYSTEM_INCLUDED
#define	SYSTEM_INCLUDED

#include "String.h"

class PrintStream {
public:
    PrintStream();
    ~PrintStream();
    void print(bool b);
    void print(char c);
    void print(char* s);
    void print(double d);
    void print(float f);
    void print(int i);
    void print(long l);
    void print(String *s);
    void println();
    void println(bool b);
    void println(char c);
    void println(char* s);
    void println(double d);
    void println(float f);
    void println(int i);
    void println(long l);
    void println(String *s);
};

class System {
    static const int DEFAULT_RADIX;
    System();
    ~System();
public:
    static void *in;
    static PrintStream *out;
};

#endif	// SYSTEM_INCLUDED
