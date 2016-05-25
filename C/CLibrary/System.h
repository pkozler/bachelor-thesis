#ifndef SYSTEM_INCLUDED
#define	SYSTEM_INCLUDED

#include "String.h"
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

/**
 * The System module contains several useful global variables and functions.
 *
 * @author Petr Kozler (A13B0359P)
 */

/**
 * A struct representing PrintStream which provides ability to print
 * representations of various data values conveniently.
 * Currently serves only as a fake structure for the purpose
 * of the Java code imitation.
 *
 * @author Petr Kozler (A13B0359P)
 */

typedef struct {
    void *dummy; // dummy variable for the struct to have at least one member
} PrintStream;

/**
 * This struct represents an input stream of bytes.
 * Currently serves only as a fake structure for the purpose
 * of the Java code imitation.
 * 
 * @author Petr Kozler (A13B0359P)
 */

typedef struct {
    void *dummy; // dummy variable for the struct to have at least one member
} InputStream;

void printBool(PrintStream *ptr, bool b);
void printC(PrintStream *ptr, char c);
void printS(PrintStream *ptr, char *s, int32_t length);
void printD(PrintStream *ptr, double d);
void printF(PrintStream *ptr, float f);
void printI(PrintStream *ptr, int32_t i);
void printL(PrintStream *ptr, int64_t l);
void printObj(PrintStream *ptr, void *obj, String *(*toString)(void *));
void printStr(PrintStream *ptr, String *s);
void println(PrintStream *ptr);
void printlnBool(PrintStream *ptr, bool x);
void printlnC(PrintStream *ptr, char x);
void printlnS(PrintStream *ptr, char *x, int32_t length);
void printlnD(PrintStream *ptr, double x);
void printlnF(PrintStream *ptr, float x);
void printlnI(PrintStream *ptr, int32_t x);
void printlnL(PrintStream *ptr, int64_t x);
void printlnObj(PrintStream *ptr, void *obj, String *(*toString)(void *));
void printlnStr(PrintStream *ptr, String *x);

/**
 * The struct instance representing the fake "standard" input stream
 * (for purpose of the imitation of Java code).
 */
InputStream *System_in;

/**
 * The struct instance representing the fake "standard" output stream
 * (for purpose of the imitation of Java code).
 */
PrintStream *System_out;

void _mergeSort(void **array, void **aux, int32_t left, int32_t right, int32_t (*compare)(const void *, const void *));

#endif	/* SYSTEM_INCLUDED */
