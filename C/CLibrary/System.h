#ifndef SYSTEM_INCLUDED
#define	SYSTEM_INCLUDED

#include "String.h"
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

/**
 * A PrintStream adds functionality to another output stream,
 * namely the ability to print representations of various data values conveniently.
 *
 * @author Petr Kozler (A13B0359P)
 */

typedef struct {
    // really no code
} PrintStream;

/**
 * This abstract class is the superclass of all classes
 * representing an input stream of bytes.
 * 
 * @author Petr Kozler (A13B0359P)
 */

typedef struct {
    // really no code
} InputStream;

void printB(PrintStream *ptr, bool b);
void printC(PrintStream *ptr, char c);
void printS(PrintStream *ptr, char *s);
void printD(PrintStream *ptr, double d);
void printF(PrintStream *ptr, float f);
void printI(PrintStream *ptr, int32_t i);
void printL(PrintStream *ptr, int64_t l);
void printObj(PrintStream *ptr, void *obj, String *(*toString)(void *));
void printStr(PrintStream *ptr, String *s);
void println(PrintStream *ptr);
void printlnB(PrintStream *ptr, bool x);
void printlnC(PrintStream *ptr, char x);
void printlnS(PrintStream *ptr, char *x);
void printlnD(PrintStream *ptr, double x);
void printlnF(PrintStream *ptr, float x);
void printlnI(PrintStream *ptr, int32_t x);
void printlnL(PrintStream *ptr, int64_t x);
void printlnObj(PrintStream *ptr, void *obj, String *(*toString)(void *));
void printlnStr(PrintStream *ptr, String *x);

/**
 * The System class contains several useful class fields and methods.
 *
 * @author Petr Kozler (A13B0359P)
 */

/**
 * The "standard" input stream.
 */
InputStream *System_in;

/**
 * The "standard" output stream.
 */
PrintStream *System_out;

void _mergeSort(void **array, void **aux, int32_t left, int32_t right, int32_t (*compare)(const void *, const void *));

#endif	/* SYSTEM_INCLUDED */
