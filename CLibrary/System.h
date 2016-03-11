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

/**
 * The System class contains several useful class fields and methods.
 *
 * @author Petr Kozler (A13B0359P)
 */

void _mergeSort(void **array, void **aux, int32_t left, int32_t right, int32_t (*compare)(const void *, const void *));
void System_out_printB(bool b);
void System_out_printC(char c);
void System_out_printS(char *s);
void System_out_printD(double d);
void System_out_printF(float f);
void System_out_printI(int32_t i);
void System_out_printL(int64_t l);
void System_out_printObj(void *obj, String *(*toString)(void *));
void System_out_printStr(String *s);
void System_out_println();
void System_out_printlnB(bool x);
void System_out_printlnC(char x);
void System_out_printlnS(char *x);
void System_out_printlnD(double x);
void System_out_printlnF(float x);
void System_out_printlnI(int32_t x);
void System_out_printlnL(int64_t x);
void System_out_printlnObj(void *obj, String *(*toString)(void *));
void System_out_printlnStr(String *x);

#endif	/* SYSTEM_INCLUDED */
