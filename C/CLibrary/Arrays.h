#ifndef ARRAYS_INCLUDED
#define	ARRAYS_INCLUDED

#include "String.h"
#include <stdbool.h>
#include <stdint.h>

/**
 * This module contains various functions for manipulating arrays (such as sorting and searching).
 *
 * @author Petr Kozler (A13B0359P)
 */

int32_t Arrays_binarySearchB(int8_t *a, int32_t length, int8_t key);
int32_t Arrays_binarySearchRangeB(int8_t *a, int32_t fromIndex, int32_t toIndex, int8_t key);
int32_t Arrays_binarySearchC(char *a, int32_t length, char key);
int32_t Arrays_binarySearchRangeC(char *a, int32_t fromIndex, int32_t toIndex, char key);
int32_t Arrays_binarySearchD(double *a, int32_t length, double key);
int32_t Arrays_binarySearchRangeD(double *a, int32_t fromIndex, int32_t toIndex, double key);
int32_t Arrays_binarySearchF(float *a, int32_t length, float key);
int32_t Arrays_binarySearchRangeF(float *a, int32_t fromIndex, int32_t toIndex, float key);
int32_t Arrays_binarySearchI(int32_t *a, int32_t length, int32_t key);
int32_t Arrays_binarySearchRangeI(int32_t *a, int32_t fromIndex, int32_t toIndex, int32_t key);
int32_t Arrays_binarySearchL(int64_t *a, int32_t length, int64_t key);
int32_t Arrays_binarySearchRangeL(int64_t *a, int32_t fromIndex, int32_t toIndex, int64_t key);
int32_t Arrays_binarySearchObj(void **a, int32_t length, void *key, int32_t(*c)(const void *, const void *));
int32_t Arrays_binarySearchRangeObj(void **a, int32_t fromIndex, int32_t toIndex, void *key, int32_t(*c)(const void *, const void *));
int32_t Arrays_binarySearchS(int16_t *a, int32_t length, int16_t key);
int32_t Arrays_binarySearchRangeS(int16_t *a, int32_t fromIndex, int32_t toIndex, int16_t key);
bool *Arrays_copyOfBool(bool *original, int32_t length, int32_t newLength);
int8_t *Arrays_copyOfB(int8_t *original, int32_t length, int32_t newLength);
char *Arrays_copyOfC(char *original, int32_t length, int32_t newLength);
double *Arrays_copyOfD(double *original, int32_t length, int32_t newLength);
float *Arrays_copyOfF(float *original, int32_t length, int32_t newLength);
int32_t *Arrays_copyOfI(int32_t *original, int32_t length, int32_t newLength);
int64_t *Arrays_copyOfL(int64_t *original, int32_t length, int32_t newLength);
int16_t *Arrays_copyOfS(int16_t *original, int32_t length, int32_t newLength);
void **Arrays_copyOfObj(void **original, int32_t length, int32_t newLength);
bool *Arrays_copyOfRangeBool(bool *original, int32_t length, int32_t from, int32_t to);
int8_t *Arrays_copyOfRangeB(int8_t *original, int32_t length, int32_t from, int32_t to);
char *Arrays_copyOfRangeC(char *original, int32_t length, int32_t from, int32_t to);
double *Arrays_copyOfRangeD(double *original, int32_t length, int32_t from, int32_t to);
float *Arrays_copyOfRangeF(float *original, int32_t length, int32_t from, int32_t to);
int32_t *Arrays_copyOfRangeI(int32_t *original, int32_t length, int32_t from, int32_t to);
int64_t *Arrays_copyOfRangeL(int64_t *original, int32_t length, int32_t from, int32_t to);
int16_t *Arrays_copyOfRangeS(int16_t *original, int32_t length, int32_t from, int32_t to);
void **Arrays_copyOfRangeObj(void **original, int32_t length, int32_t from, int32_t to);
bool Arrays_equalsBool(bool *a, int32_t length, bool *a2, int32_t length2);
bool Arrays_equalsB(int8_t *a, int32_t length, int8_t *a2, int32_t length2);
bool Arrays_equalsC(char *a, int32_t length, char *a2, int32_t length2);
bool Arrays_equalsD(double *a, int32_t length, double *a2, int32_t length2);
bool Arrays_equalsF(float *a, int32_t length, float *a2, int32_t length2);
bool Arrays_equalsI(int32_t *a, int32_t length, int32_t *a2, int32_t length2);
bool Arrays_equalsL(int64_t *a, int32_t length, int64_t *a2, int32_t length2);
bool Arrays_equalsObj(void **a, int32_t length, void **a2, int32_t length2, bool (*equals)(const void *, const void *));
bool Arrays_equalsS(int16_t *a, int32_t length, int16_t *a2, int32_t length2);
void Arrays_fillBool(bool *a, int32_t length, bool val);
void Arrays_fillRangeBool(bool *a, int32_t fromIndex, int32_t toIndex, bool val);
void Arrays_fillB(int8_t *a, int32_t length, int8_t val);
void Arrays_fillRangeB(int8_t *a, int32_t fromIndex, int32_t toIndex, int8_t val);
void Arrays_fillC(char *a, int32_t length, char val);
void Arrays_fillRangeC(char *a, int32_t fromIndex, int32_t toIndex, char val);
void Arrays_fillD(double *a, int32_t length, double val);
void Arrays_fillRangeD(double *a, int32_t fromIndex, int32_t toIndex, double val);
void Arrays_fillF(float *a, int32_t length, float val);
void Arrays_fillRangeF(float *a, int32_t fromIndex, int32_t toIndex, float val);
void Arrays_fillI(int32_t *a, int32_t length, int32_t val);
void Arrays_fillRangeI(int32_t *a, int32_t fromIndex, int32_t toIndex, int32_t val);
void Arrays_fillL(int64_t *a, int32_t length, int64_t val);
void Arrays_fillRangeL(int64_t *a, int32_t fromIndex, int32_t toIndex, int64_t val);
void Arrays_fillObj(void **a, int32_t length, void *val);
void Arrays_fillRangeObj(void **a, int32_t fromIndex, int32_t toIndex, void *val);
void Arrays_fillS(int16_t *a, int32_t length, int16_t val);
void Arrays_fillRangeS(int16_t *a, int32_t fromIndex, int32_t toIndex, int16_t val);
void Arrays_sortC(char *a, int32_t length);
void Arrays_sortRangeC(char *a, int32_t fromIndex, int32_t toIndex);
void Arrays_sortB(int8_t *a, int32_t length);
void Arrays_sortRangeB(int8_t *a, int32_t fromIndex, int32_t toIndex);
void Arrays_sortD(double *a, int32_t length);
void Arrays_sortRangeD(double *a, int32_t fromIndex, int32_t toIndex);
void Arrays_sortF(float *a, int32_t length);
void Arrays_sortRangeF(float *a, int32_t fromIndex, int32_t toIndex);
void Arrays_sortI(int32_t *a, int32_t length);
void Arrays_sortRangeI(int32_t *a, int32_t fromIndex, int32_t toIndex);
void Arrays_sortL(int64_t *a, int32_t length);
void Arrays_sortRangeL(int64_t *a, int32_t fromIndex, int32_t toIndex);
void Arrays_sortObj(void **a, int32_t length, int32_t(*c)(const void *, const void *));
void Arrays_sortRangeObj(void **a, int32_t fromIndex, int32_t toIndex, int32_t(*c)(const void *, const void *));
void Arrays_sortS(int16_t *a, int32_t length);
void Arrays_sortRangeS(int16_t *a, int32_t fromIndex, int32_t toIndex);
String *Arrays_toStringBool(bool *a, int32_t length);
String *Arrays_toStringB(int8_t *a, int32_t length);
String *Arrays_toStringC(char *a, int32_t length);
String *Arrays_toStringD(double *a, int32_t length);
String *Arrays_toStringF(float *a, int32_t length);
String *Arrays_toStringI(int32_t *a, int32_t length);
String *Arrays_toStringL(int64_t *a, int32_t length);
String *Arrays_toStringObj(void **a, int32_t length, int32_t size, String *(*toString)(const void *));
String *Arrays_toStringS(int16_t *a, int32_t length);

#endif	/* ARRAYS_INCLUDED */
