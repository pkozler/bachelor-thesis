#ifndef SYSTEM_INCLUDED
#define	SYSTEM_INCLUDED

#include "String.h"
#include <cstdint>

/**
 * A PrintStream adds functionality to another output stream,
 * namely the ability to print representations of various data values conveniently.
 *
 * @author Petr Kozler (A13B0359P)
 */
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
    void print(void *obj, String *(*toString)(void *));
    void print(String *s);
    void println();
    void println(bool x);
    void println(char x);
    void println(char* x);
    void println(double x);
    void println(float x);
    void println(int32_t x);
    void println(int64_t x);
    void println(void *obj, String *(*toString)(void *));
    void println(String *x);
};

/**
 * The System class contains several useful class fields and methods.
 *
 * @author Petr Kozler (A13B0359P)
 */
class System {
    System();
    ~System();
public:
    static void *in;
    static PrintStream *out;
};

#endif	// SYSTEM_INCLUDED
