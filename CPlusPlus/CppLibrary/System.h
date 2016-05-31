#ifndef SYSTEM_INCLUDED
#define	SYSTEM_INCLUDED

#include "String_.h"
#include <cstdint>

/**
 * A PrintStream adds functionality to another output stream,
 * namely the ability to print representations of various data values conveniently.
 *
 * @author Petr Kozler (A13B0359P)
 */
class PrintStream : public Object {
public:
    void print(bool b);
    void print(char c);
    void print(char* s, int32_t length);
    void print(double d);
    void print(float f);
    void print(int32_t i);
    void print(int64_t l);
    void print(Object *obj);
    void print(String *s);
    void println();
    void println(bool x);
    void println(char x);
    void println(char* x, int32_t length);
    void println(double x);
    void println(float x);
    void println(int32_t x);
    void println(int64_t x);
    void println(Object *obj);
    void println(String *x);
};

/**
 * This abstract class is the superclass of all classes
 * representing an input stream of bytes.
 * 
 * @author Petr Kozler (A13B0359P)
 */
class InputStream : public Object {
    // really no code
};

/**
 * The System class contains several useful class fields and methods.
 *
 * @author Petr Kozler (A13B0359P)
 */
class System {
public:
    /**
     * The "standard" input stream.
     */
    static InputStream *in;
    
    /**
     * The "standard" output stream.
     */
    static PrintStream *out;
};

#endif	// SYSTEM_INCLUDED
