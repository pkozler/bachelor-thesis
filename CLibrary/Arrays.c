#include "Arrays.h"

#include "System.h"
#include "Boolean.h"
#include "Byte.h"
#include "Character.h"
#include "Double.h"
#include "Float.h"
#include "Integer.h"
#include "Long.h"
#include "Short.h"
#include "String.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// minimální počet znaků ve výstupu metody toString (závorky + nulový znak)
#define _MIN_STR_LEN 3
// počet znaků na oddělovač prvků (čárka + mezera)
#define _DELIM_STRLEN 2
// koeficient zvětšení bufferu pro řetězec ve funkci toString
#define _BUF_RESIZE_COEF 2

int _compareC(const void *a, const void *b) {
    return ( *(char*)a - *(char*)b );
}

int _compareD(const void *a, const void *b) {
    Double *d1 = new_Double(*(double*)a);
    Double *d2 = new_Double(*(double*)b);

    return compareToD(d1, d2);
}

int _compareF(const void *a, const void *b) {
    Float *f1 = new_Float(*(float*)a);
    Float *f2 = new_Float(*(float*)b);

    return compareToF(f1, f2);
}

int _compareI(const void *a, const void *b) {
    return ( *(int*)a - *(int*)b );
}

int _compareL(const void *a, const void *b) {
    return ( *(long*)a - *(long*)b );
}

int _compareS(const void *a, const void *b) {
    return ( *(short*)a - *(short*)b );
}

bool _equalsBool(const void *a, const void *b) {
    return (*(bool*)a == *(bool*)b);
}

bool _equalsC(const void *a, const void *b) {
    return (*(char*)a == *(char*)b);
}

bool _equalsD(const void *a, const void *b) {
    Double *d1 = new_Double(*(double*)a);
    Double *d2 = new_Double(*(double*)b);
    bool equal = equalsD(d1, d2);
    free(d1);
    free(d2);
    
    return equal;
}

bool _equalsF(const void *a, const void *b) {
    Float *f1 = new_Float(*(float*)a);
    Float *f2 = new_Float(*(float*)b);
    bool equal = equalsF(f1, f2);
    free(f1);
    free(f2);
    
    return equal;
}

bool _equalsI(const void *a, const void *b) {
    return (*(int*)a == *(int*)b);
}

bool _equalsL(const void *a, const void *b) {
    return (*(long*)a == *(long*)b);
}

bool _equalsS(const void *a, const void *b) {
    return (*(short*)a == *(short*)b);
}

String *_toStringBool(const void *a) {
    return Boolean_toString(*(bool*)a);
}

String *_toStringC(const void *a) {
    return Character_toString(*(char*)a);
}

String *_toStringD(const void *a) {
    return Double_toString(*(double*)a);
}

String *_toStringF(const void *a) {
    return Float_toString(*(float*)a);
}

String *_toStringI(const void *a) {
    return Integer_toString(*(int*)a);
}

String *_toStringL(const void *a) {
    return Long_toString(*(long*)a);
}

String *_toStringS(const void *a) {
    return Short_toString(*(short*)a);
}

int _binarySearchPointer(void *a, int fromIndex, int toIndex, int size, void *key, int (*c)(const void *, const void *)) {
    void *i = bsearch(key, a + fromIndex, toIndex, size, c);
    
    if (i == NULL) {
        return -1;
    }
    else {
        return (i - a) / size;
    }
}

void *_copyOfRangePointer(void *original, int length, int size, int from, int to) {
    void *a = malloc(size * (to - from));
    int i;

    if (to > length) {
        for (i = 0; i < length; i++) {
            memcpy(a + (i - from) * size, original + i * size, size);
        }

        for (i = length; i < to; i++) {
            memset(a + (i - from) * size, 0, size);
        }
    }
    else {
        for (i = from; i < to; i++) {
            memcpy(a + (i - from) * size, original + i * size, size);
        }
    }

    return a;
}

bool _equalsPointer(void *a, int length, void *a2, int length2, int size, bool (*equals)(const void *, const void *)) {
    if (a == a2) {
        return true;
    }

    if (a == NULL || a2 == NULL) {
        return false;
    }

    if (length2 != length) {
        return false;
    }

    int i;
    for (i = 0; i < length; i++) {
        if (!equals(a + i * size, a2 + i * size)) {
            return false;
        }
    }

    return true;
}

void _fillPointer(void *a, int fromIndex, int toIndex, int size, void *val) {
    int i;
    for (i = fromIndex; i < toIndex; i++) {
        memcpy(a + i * size, val, size);
    }
}

void _sortPointer(void *a, int fromIndex, int toIndex, int size, int (*c)(const void *, const void *), bool stable) {
    if (!stable) {
        qsort(a + fromIndex, toIndex - fromIndex, size, c);
    }
    else {
        void **aux = malloc(sizeof(void *) * (toIndex - fromIndex));
        _mergeSort((void **)a, aux, fromIndex, toIndex - 1, c);
        free(aux);
    }
}

String *_toStringPointer(void *a, int length, int size, String *(*toString)(const void *)) {
    // počáteční kapacita bufferu (vyhrazen 1 znak pro prvek)
    int bufCapacity = _MIN_STR_LEN + (_DELIM_STRLEN + 1) * (length - 1) + 1;
    // počet znaků v bufferu (přičteny závorky a nulový znak)
    int bufCount = _MIN_STR_LEN;
    char *buf = malloc(bufCapacity * sizeof(char));

    buf[0] = '\0';
    strcat(buf, "[");

    if (length > 0) {
        strcat(buf, toString(a)->s);
    }

    int i;
    for (i = 1; i < length; i++) {
        String *str = toString(a + i * size);
        
        // zvětšení kapacity bufferu, pokud se nový prvek nevejde
        if (bufCount + str->len + _DELIM_STRLEN >= bufCapacity) {
            bufCapacity *= _BUF_RESIZE_COEF;
            buf = realloc(buf, bufCapacity);
        }
        
        strcat(buf, ", ");
        strcat(buf, str->s);
        delete_String(str);
    }

    strcat(buf, "]");
    String *result = new_String(buf);
    free(buf);

    return result;
}

int Arrays_binarySearchC(char *a, int length, char key) {
    return _binarySearchPointer(a, 0, length, sizeof(char), &key, _compareC);
}

int Arrays_binarySearchRangeC(char *a, int fromIndex, int toIndex, char key) {
    return _binarySearchPointer(a, fromIndex, toIndex, sizeof(char), &key, _compareC);
}

int Arrays_binarySearchD(double *a, int length, double key) {
    return _binarySearchPointer(a, 0, length, sizeof(double), &key, _compareD);
}

int Arrays_binarySearchRangeD(double *a, int fromIndex, int toIndex, double key) {
    return _binarySearchPointer(a, fromIndex, toIndex, sizeof(double), &key, _compareD);
}

int Arrays_binarySearchF(float *a, int length, float key) {
    return _binarySearchPointer(a, 0, length, sizeof(float), &key, _compareF);
}

int Arrays_binarySearchFloatF(float *a, int fromIndex, int toIndex, float key) {
    return _binarySearchPointer(a, fromIndex, toIndex, sizeof(float), &key, _compareF);
}

int Arrays_binarySearchI(int *a, int length, int key) {
    return _binarySearchPointer(a, 0, length, sizeof(int), &key, _compareI);
}

int Arrays_binarySearchRangeI(int *a, int fromIndex, int toIndex, int key) {
    return _binarySearchPointer(a, fromIndex, toIndex, sizeof(int), &key, _compareI);
}

int Arrays_binarySearchL(long *a, int length, long key) {
    return _binarySearchPointer(a, 0, length, sizeof(long), &key, _compareL);
}

int Arrays_binarySearchRangeL(long *a, int fromIndex, int toIndex, long key) {
    return _binarySearchPointer(a, fromIndex, toIndex, sizeof(long), &key, _compareL);
}

int Arrays_binarySearchS(short *a, int length, short key) {
    return _binarySearchPointer(a, 0, length, sizeof(short), &key, _compareS);
}

int Arrays_binarySearchRangeS(short *a, int fromIndex, int toIndex, short key) {
    return _binarySearchPointer(a, fromIndex, toIndex, sizeof(short), &key, _compareS);
}

int Arrays_binarySearchObj(void **a, int length, void *key, int (*c)(const void *, const void *)) {
    return _binarySearchPointer(a, 0, length, sizeof(void *), &key, c);
}

int Arrays_binarySearchRangeObj(void **a, int fromIndex, int toIndex, void *key, int (*c)(const void *, const void *)) {
    return _binarySearchPointer(a, fromIndex, toIndex, sizeof(void *), &key, c);
}

bool *Arrays_copyOfRangeBool(bool *original, int length, int from, int to) {
    return _copyOfRangePointer(original, length, sizeof(bool), from, to);
}

char *Arrays_copyOfRangeC(char *original, int length, int from, int to) {
    return _copyOfRangePointer(original, length, sizeof(char), from, to);
}

double *Arrays_copyOfRangeD(double *original, int length, int from, int to) {
    return _copyOfRangePointer(original, length, sizeof(double), from, to);
}

float *Arrays_copyOfRangeF(float *original, int length, int from, int to) {
    return _copyOfRangePointer(original, length, sizeof(float), from, to);
}

int *Arrays_copyOfRangeI(int *original, int length, int from, int to) {
    return _copyOfRangePointer(original, length, sizeof(int), from, to);
}

long *Arrays_copyOfRangeL(long *original, int length, int from, int to) {
    return _copyOfRangePointer(original, length, sizeof(long), from, to);
}

short *Arrays_copyOfRangeS(short *original, int length, int from, int to) {
    return _copyOfRangePointer(original, length, sizeof(short), from, to);
}

void **Arrays_copyOfRangeObj(void **original, int length, int from, int to) {
    return _copyOfRangePointer(original, length, sizeof(void *), from, to);
}

bool *Arrays_copyOfBool(bool *original, int length, int newLength) {
    return _copyOfRangePointer(original, length, sizeof(bool), 0, newLength);
}

char *Arrays_copyOfC(char *original, int length, int newLength) {
    return _copyOfRangePointer(original, length, sizeof(char), 0, newLength);
}

double *Arrays_copyOfD(double *original, int length, int newLength) {
    return _copyOfRangePointer(original, length, sizeof(double), 0, newLength);
}

float *Arrays_copyOfF(float *original, int length, int newLength) {
    return _copyOfRangePointer(original, length, sizeof(float), 0, newLength);
}

int *Arrays_copyOfI(int *original, int length, int newLength) {
    return _copyOfRangePointer(original, length, sizeof(int), 0, newLength);
}

long *Arrays_copyOfL(long *original, int length, int newLength) {
    return _copyOfRangePointer(original, length, sizeof(long), 0, newLength);
}

short *Arrays_copyOfS(short *original, int length, int newLength) {
    return _copyOfRangePointer(original, length, sizeof(short), 0, newLength);
}

void **Arrays_copyOfObj(void **original, int length, int newLength) {
    return _copyOfRangePointer(original, length, sizeof(void *), 0, newLength);
}

bool Arrays_equalsBool(bool *a, int length, bool *a2, int length2) {
    return _equalsPointer(a, length, a2, length2, sizeof(bool), _equalsBool);
}

bool Arrays_equalsC(char *a, int length, char *a2, int length2) {
    return _equalsPointer(a, length, a2, length2, sizeof(char), _equalsC);
}

bool Arrays_equalsD(double *a, int length, double *a2, int length2) {
    return _equalsPointer(a, length, a2, length2, sizeof(double), _equalsD);
}

bool Arrays_equalsF(float *a, int length, float *a2, int length2) {
    return _equalsPointer(a, length, a2, length2, sizeof(float), _equalsF);
}

bool Arrays_equalsI(int *a, int length, int *a2, int length2) {
    return _equalsPointer(a, length, a2, length2, sizeof(int), _equalsI);
}

bool Arrays_equalsL(long *a, int length, long *a2, int length2) {
    return _equalsPointer(a, length, a2, length2, sizeof(long), _equalsL);
}

bool Arrays_equalsObj(void **a, int length, void **a2, int length2, bool (*equals)(const void *, const void *)) {
    return _equalsPointer(a, length, a2, length2, sizeof(void *), equals);
}

bool Arrays_equalsS(short *a, int length, short *a2, int length2) {
    return _equalsPointer(a, length, a2, length2, sizeof(short), _equalsS);
}

void Arrays_fillBool(bool *a, int length, bool val) {
    _fillPointer(a, 0, length, sizeof(bool), &val);
}

void Arrays_fillRangeBool(bool *a, int fromIndex, int toIndex, bool val) {
    _fillPointer(a, fromIndex, toIndex, sizeof(bool), &val);
}

void Arrays_fillC(char *a, int length, char val) {
    _fillPointer(a, 0, length, sizeof(char), &val);
}

void Arrays_fillRangeC(char *a, int fromIndex, int toIndex, char val) {
    _fillPointer(a, fromIndex, toIndex, sizeof(char), &val);
}

void Arrays_fillD(double *a, int length, double val) {
    _fillPointer(a, 0, length, sizeof(double), &val);
}

void Arrays_fillRangeD(double *a, int fromIndex, int toIndex, double val) {
    _fillPointer(a, fromIndex, toIndex, sizeof(double), &val);
}

void Arrays_fillF(float *a, int length, float val) {
    _fillPointer(a, 0, length, sizeof(float), &val);
}

void Arrays_fillRangeF(float *a, int fromIndex, int toIndex, float val) {
    _fillPointer(a, fromIndex, toIndex, sizeof(float), &val);
}

void Arrays_fillI(int *a, int length, int val) {
    _fillPointer(a, 0, length, sizeof(int), &val);
}

void Arrays_fillRangeI(int *a, int fromIndex, int toIndex, int val) {
    _fillPointer(a, fromIndex, toIndex, sizeof(int), &val);
}

void Arrays_fillL(long *a, int length, long val) {
    _fillPointer(a, 0, length, sizeof(long), &val);
}

void Arrays_fillRangeL(long *a, int fromIndex, int toIndex, long val) {
    _fillPointer(a, fromIndex, toIndex, sizeof(long), &val);
}

void Arrays_fillObj(void **a, int length, void *val) {
    _fillPointer(a, 0, length, sizeof(void *), &val);
}

void Arrays_fillRangeObj(void **a, int fromIndex, int toIndex, void *val) {
    _fillPointer(a, fromIndex, toIndex, sizeof(void *), &val);
}

void Arrays_fillS(short *a, int length, short val) {
    _fillPointer(a, 0, length, sizeof(short), &val);
}

void Arrays_fillRangeS(short *a, int fromIndex, int toIndex, short val) {
    _fillPointer(a, fromIndex, toIndex, sizeof(short), &val);
}

void Arrays_sortC(char *a, int length) {
    _sortPointer(a, 0, length, sizeof(char), _compareC, false);
}

void Arrays_sortRangeC(char *a, int fromIndex, int toIndex) {
    _sortPointer(a, fromIndex, toIndex, sizeof(char), _compareC, false);
}

void Arrays_sortD(double *a, int length) {
    _sortPointer(a, 0, length, sizeof(double), _compareD, false);
}

void Arrays_sortRangeD(double *a, int fromIndex, int toIndex) {
    _sortPointer(a, fromIndex, toIndex, sizeof(double), _compareD, false);
}

void Arrays_sortF(float *a, int length) {
    _sortPointer(a, 0, length, sizeof(float), _compareF, false);
}

void Arrays_sortRangeF(float *a, int fromIndex, int toIndex) {
    _sortPointer(a, fromIndex, toIndex, sizeof(float), _compareF, false);
}

void Arrays_sortI(int *a, int length) {
    _sortPointer(a, 0, length, sizeof(int), _compareI, false);
}

void Arrays_sortRangeI(int *a, int fromIndex, int toIndex) {
    _sortPointer(a, fromIndex, toIndex, sizeof(int), _compareI, false);
}

void Arrays_sortL(long *a, int length) {
    _sortPointer(a, 0, length, sizeof(long), _compareL, false);
}

void Arrays_sortRangeL(long *a, int fromIndex, int toIndex) {
    _sortPointer(a, fromIndex, toIndex, sizeof(long), _compareL, false);
}

void Arrays_sortS(short *a, int length) {
    _sortPointer(a, 0, length, sizeof(short), _compareS, false);
}

void Arrays_sortRangeS(short *a, int fromIndex, int toIndex) {
    _sortPointer(a, fromIndex, toIndex, sizeof(short), _compareS, false);
}

void Arrays_sortObj(void **a, int length, int (*c)(const void *, const void *)) {
    _sortPointer(a, 0, length, sizeof(void *), c, true);
}

void Arrays_sortRangeObj(void **a, int fromIndex, int toIndex, int (*c)(const void *, const void *)) {
    _sortPointer(a, fromIndex, toIndex, sizeof(void *), c, true);
}

String *Arrays_toStringBool(bool *a, int length) {
    return _toStringPointer(a, length, sizeof(bool), _toStringBool);
}

String *Arrays_toStringC(char *a, int length) {
    return _toStringPointer(a, length, sizeof(char), _toStringC);
}

String *Arrays_toStringD(double *a, int length) {
    return _toStringPointer(a, length, sizeof(double), _toStringD);
}

String *Arrays_toStringF(float *a, int length) {
    return _toStringPointer(a, length, sizeof(float), _toStringF);
}

String *Arrays_toStringI(int *a, int length) {
    return _toStringPointer(a, length, sizeof(int), _toStringI);
}

String *Arrays_toStringL(long *a, int length) {
    return _toStringPointer(a, length, sizeof(long), _toStringL);
}

String *Arrays_toStringObj(void **a, int length, int size, String *(*toString)(const void *)) {
    return _toStringPointer(a, length, size, toString);
}

String *Arrays_toStringS(short *a, int length) {
    return _toStringPointer(a, length, sizeof(short), _toStringS);
}
