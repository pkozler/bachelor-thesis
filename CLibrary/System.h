#ifndef SYSTEM_INCLUDED
#define	SYSTEM_INCLUDED

#include "String.h"
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

void _mergeSort(void **array, void **aux, int32_t left, int32_t right, int32_t (*compare)(const void *, const void *));
void System_out_printB(bool b);
void System_out_printC(char c);
void System_out_printS(char *s);
void System_out_printD(double d);
void System_out_printF(float f);
void System_out_printI(int32_t i);
void System_out_printL(int64_t l);
void System_out_printStr(String *s);
void System_out_println();
void System_out_printlnB(bool b);
void System_out_printlnC(char c);
void System_out_printlnS(char *s);
void System_out_printlnD(double d);
void System_out_printlnF(float f);
void System_out_printlnI(int32_t i);
void System_out_printlnL(int64_t l);
void System_out_printlnStr(String *s);

#endif	/* SYSTEM_INCLUDED */
