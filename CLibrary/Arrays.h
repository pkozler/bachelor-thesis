#ifndef ARRAYS_INCLUDED
#define	ARRAYS_INCLUDED

#include "String.h"
#include <stdbool.h>

int Arrays_binarySearchC(char *a, int length, char key);
int Arrays_binarySearchRangeC(char *a, int fromIndex, int toIndex, char key);
int Arrays_binarySearchD(double *a, int length, double key);
int Arrays_binarySearchRangeD(double *a, int fromIndex, int toIndex, double key);
int Arrays_binarySearchF(float *a, int length, float key);
int Arrays_binarySearchFloatF(float *a, int fromIndex, int toIndex, float key);
int Arrays_binarySearchI(int *a, int length, int key);
int Arrays_binarySearchRangeI(int *a, int fromIndex, int toIndex, int key);
int Arrays_binarySearchL(long *a, int length, long key);
int Arrays_binarySearchRangeL(long *a, int fromIndex, int toIndex, long key);
int Arrays_binarySearchS(short *a, int length, short key);
int Arrays_binarySearchRangeS(short *a, int fromIndex, int toIndex, short key);
int Arrays_binarySearchObj(void **a, int length, void *key, int (*c)(const void *, const void *));
int Arrays_binarySearchRangeObj(void **a, int fromIndex, int toIndex, void *key, int (*c)(const void *, const void *));
bool *Arrays_copyOfRangeBool(bool *original, int length, int from, int to);
char *Arrays_copyOfRangeC(char *original, int length, int from, int to);
double *Arrays_copyOfRangeD(double *original, int length, int from, int to);
float *Arrays_copyOfRangeF(float *original, int length, int from, int to);
int *Arrays_copyOfRangeI(int *original, int length, int from, int to);
long *Arrays_copyOfRangeL(long *original, int length, int from, int to);
short *Arrays_copyOfRangeS(short *original, int length, int from, int to);
void **Arrays_copyOfRangeObj(void **original, int length, int from, int to);
bool *Arrays_copyOfBool(bool *original, int length, int newLength);
char *Arrays_copyOfC(char *original, int length, int newLength);
double *Arrays_copyOfD(double *original, int length, int newLength);
float *Arrays_copyOfF(float *original, int length, int newLength);
int *Arrays_copyOfI(int *original, int length, int newLength);
long *Arrays_copyOfL(long *original, int length, int newLength);
short *Arrays_copyOfS(short *original, int length, int newLength);
void **Arrays_copyOfObj(void **original, int length, int newLength);
bool Arrays_equalsBool(bool *a, int length, bool *a2, int length2);
bool Arrays_equalsC(char *a, int length, char *a2, int length2);
bool Arrays_equalsD(double *a, int length, double *a2, int length2);
bool Arrays_equalsF(float *a, int length, float *a2, int length2);
bool Arrays_equalsI(int *a, int length, int *a2, int length2);
bool Arrays_equalsL(long *a, int length, long *a2, int length2);
bool Arrays_equalsObj(void **a, int length, void **a2, int length2, bool (*equals)(const void *, const void *));
bool Arrays_equalsS(short *a, int length, short *a2, int length2);
void Arrays_fillBool(bool *a, int length, bool val);
void Arrays_fillRangeBool(bool *a, int fromIndex, int toIndex, bool val);
void Arrays_fillC(char *a, int length, char val);
void Arrays_fillRangeC(char *a, int fromIndex, int toIndex, char val);
void Arrays_fillD(double *a, int length, double val);
void Arrays_fillRangeD(double *a, int fromIndex, int toIndex, double val);
void Arrays_fillF(float *a, int length, float val);
void Arrays_fillRangeF(float *a, int fromIndex, int toIndex, float val);
void Arrays_fillI(int *a, int length, int val);
void Arrays_fillRangeI(int *a, int fromIndex, int toIndex, int val);
void Arrays_fillL(long *a, int length, long val);
void Arrays_fillRangeL(long *a, int fromIndex, int toIndex, long val);
void Arrays_fillObj(void **a, int length, void *val);
void Arrays_fillRangeObj(void **a, int fromIndex, int toIndex, void *val);
void Arrays_fillS(short *a, int length, short val);
void Arrays_fillRangeS(short *a, int fromIndex, int toIndex, short val);
void Arrays_sortC(char *a, int length);
void Arrays_sortRangeC(char *a, int fromIndex, int toIndex);
void Arrays_sortD(double *a, int length);
void Arrays_sortRangeD(double *a, int fromIndex, int toIndex);
void Arrays_sortF(float *a, int length);
void Arrays_sortRangeF(float *a, int fromIndex, int toIndex);
void Arrays_sortI(int *a, int length);
void Arrays_sortRangeI(int *a, int fromIndex, int toIndex);
void Arrays_sortL(long *a, int length);
void Arrays_sortRangeL(long *a, int fromIndex, int toIndex);
void Arrays_sortS(short *a, int length);
void Arrays_sortRangeS(short *a, int fromIndex, int toIndex);
void Arrays_sortObj(void **a, int length, int (*c)(const void *, const void *));
void Arrays_sortRangeObj(void **a, int fromIndex, int toIndex, int (*c)(const void *, const void *));
String *Arrays_toStringBool(bool *a, int length);
String *Arrays_toStringC(char *a, int length);
String *Arrays_toStringD(double *a, int length);
String *Arrays_toStringF(float *a, int length);
String *Arrays_toStringI(int *a, int length);
String *Arrays_toStringL(long *a, int length);
String *Arrays_toStringObj(void **a, int length, int size, String *(*toString)(const void *));
String *Arrays_toStringS(short *a, int length);

#endif	/* ARRAYS_INCLUDED */
