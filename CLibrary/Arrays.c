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
#include "StringBuilder.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int32_t _compareB(const void *a, const void *b) {
    return Byte_compare(*(int8_t*)a, *(int8_t*)b);
}

int32_t _compareC(const void *a, const void *b) {
    return Character_compare(*(char*)a, *(char*)b);
}

int32_t _compareD(const void *a, const void *b) {
    return Double_compare(*(double*)a, *(double*)b);
}

int32_t _compareF(const void *a, const void *b) {
    return Float_compare(*(float*)a, *(float*)b);
}

int32_t _compareI(const void *a, const void *b) {
    return Integer_compare(*(int32_t*)a, *(int32_t*)b);
}

int32_t _compareL(const void *a, const void *b) {
    return Long_compare(*(int64_t*)a, *(int64_t*)b);
}

int32_t _compareS(const void *a, const void *b) {
    return Short_compare(*(int16_t*)a, *(int16_t*)b);
}

bool _equalsBool(const void *a, const void *b) {
    Boolean *x = new_Boolean(*(bool*)a);
    Boolean *y = new_Boolean(*(bool*)b);
    bool equal = equalsBool(x, y);
    free(x);
    free(y);
    
    return equal;
}

bool _equalsB(const void *a, const void *b) {
    Byte *x = new_Byte(*(int8_t*)a);
    Byte *y = new_Byte(*(int8_t*)b);
    bool equal = equalsB(x, y);
    free(x);
    free(y);
    
    return equal;
}

bool _equalsC(const void *a, const void *b) {
    Character *x = new_Character(*(char*)a);
    Character *y = new_Character(*(char*)b);
    bool equal = equalsC(x, y);
    free(x);
    free(y);
    
    return equal;
}

bool _equalsD(const void *a, const void *b) {
    Double *x = new_Double(*(double*)a);
    Double *y = new_Double(*(double*)b);
    bool equal = equalsD(x, y);
    free(x);
    free(y);
    
    return equal;
}

bool _equalsF(const void *a, const void *b) {
    Float *x = new_Float(*(float*)a);
    Float *y = new_Float(*(float*)b);
    bool equal = equalsF(x, y);
    free(x);
    free(y);
    
    return equal;
}

bool _equalsI(const void *a, const void *b) {
    Integer *x = new_Integer(*(int32_t*)a);
    Integer *y = new_Integer(*(int32_t*)b);
    bool equal = equalsI(x, y);
    free(x);
    free(y);
    
    return equal;
}

bool _equalsL(const void *a, const void *b) {
    Long *x = new_Long(*(int64_t*)a);
    Long *y = new_Long(*(int64_t*)b);
    bool equal = equalsL(x, y);
    free(x);
    free(y);
    
    return equal;
}

bool _equalsS(const void *a, const void *b) {
    Short *x = new_Short(*(int16_t*)a);
    Short *y = new_Short(*(int16_t*)b);
    bool equal = equalsS(x, y);
    free(x);
    free(y);
    
    return equal;
}

String *_toStringBool(const void *a) {
    return Boolean_toString(*(bool*)a);
}

String *_toStringB(const void *a) {
    return Byte_toString(*(int8_t*)a);
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
    return Integer_toString(*(int32_t*)a);
}

String *_toStringL(const void *a) {
    return Long_toString(*(int64_t*)a);
}

String *_toStringS(const void *a) {
    return Short_toString(*(int16_t*)a);
}

int32_t _binarySearchPointer(void *a, int32_t fromIndex, int32_t toIndex, int32_t size, void *key, int32_t (*c)(const void *, const void *)) {
    int32_t lower = fromIndex;
    int32_t upper = toIndex - 1;

    while (lower <= upper) {
        int32_t middle = ((uint32_t)lower + (uint32_t)upper) >> 1;
        void *middleValue = a + middle * size;

        if (c(middleValue, key) < 0) {
            lower = middle + 1;
        }
        else if (c(middleValue, key) > 0) {
            upper = middle - 1;
        }
        else {
            return middle;
        }
    }
    
    return -(lower + 1);
}

void *_copyOfRangePointer(void *original, int32_t length, int32_t size, int32_t from, int32_t to) {
    void *a = malloc(size * (to - from));
    int32_t i;

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

bool _equalsPointer(void *a, int32_t length, void *a2, int32_t length2, int32_t size, bool (*equals)(const void *, const void *)) {
    if (a == a2) {
        return true;
    }

    if (a == NULL || a2 == NULL) {
        return false;
    }

    if (length2 != length) {
        return false;
    }

    int32_t i;
    for (i = 0; i < length; i++) {
        if (!equals(a + i * size, a2 + i * size)) {
            return false;
        }
    }

    return true;
}

void _fillPointer(void *a, int32_t fromIndex, int32_t toIndex, int32_t size, void *val) {
    int32_t i;
    for (i = fromIndex; i < toIndex; i++) {
        memcpy(a + i * size, val, size);
    }
}

void _sortPointer(void *a, int32_t fromIndex, int32_t toIndex, int32_t size, int32_t (*c)(const void *, const void *), bool stable) {
    if (!stable) {
        qsort(a + fromIndex, toIndex - fromIndex, size, c);
    }
    else {
        void **aux = malloc(sizeof(void *) * (toIndex - fromIndex));
        _mergeSort((void **)a, aux, fromIndex, toIndex - 1, c);
        free(aux);
    }
}

String *_toStringPointer(void *a, int32_t length, int32_t size, String *(*toString)(const void *)) {
    StringBuilder *sb = new_StringBuilder();
    String *str = new_String("[");
    append(sb, str);
    delete_String(str);
    
    if (length > 0) {
        str = toString(a);
        append(sb, str);
        delete_String(str);
    }

    int32_t i;
    for (i = 1; i < length; i++) {
        str = new_String(", ");
        append(sb, str);
        delete_String(str);
        str = toString(a + i * size);
        append(sb, str);
        delete_String(str);
    }

    str = new_String("]");
    append(sb, str);
    delete_String(str);
    str = toStringSb(sb);
    delete_StringBuilder(sb);
    
    return str;
}

int32_t Arrays_binarySearchB(int8_t *a, int32_t length, int8_t key) {
    return _binarySearchPointer(a, 0, length, sizeof(int8_t), &key, _compareC);
}

int32_t Arrays_binarySearchRangeB(int8_t *a, int32_t fromIndex, int32_t toIndex, int8_t key) {
    return _binarySearchPointer(a, fromIndex, toIndex, sizeof(int8_t), &key, _compareC);
}

int32_t Arrays_binarySearchC(char *a, int32_t length, char key) {
    return _binarySearchPointer(a, 0, length, sizeof(char), &key, _compareC);
}

int32_t Arrays_binarySearchRangeC(char *a, int32_t fromIndex, int32_t toIndex, char key) {
    return _binarySearchPointer(a, fromIndex, toIndex, sizeof(char), &key, _compareC);
}

int32_t Arrays_binarySearchD(double *a, int32_t length, double key) {
    return _binarySearchPointer(a, 0, length, sizeof(double), &key, _compareD);
}

int32_t Arrays_binarySearchRangeD(double *a, int32_t fromIndex, int32_t toIndex, double key) {
    return _binarySearchPointer(a, fromIndex, toIndex, sizeof(double), &key, _compareD);
}

int32_t Arrays_binarySearchF(float *a, int32_t length, float key) {
    return _binarySearchPointer(a, 0, length, sizeof(float), &key, _compareF);
}

int32_t Arrays_binarySearchFloatF(float *a, int32_t fromIndex, int32_t toIndex, float key) {
    return _binarySearchPointer(a, fromIndex, toIndex, sizeof(float), &key, _compareF);
}

int32_t Arrays_binarySearchI(int32_t *a, int32_t length, int32_t key) {
    return _binarySearchPointer(a, 0, length, sizeof(int32_t), &key, _compareI);
}

int32_t Arrays_binarySearchRangeI(int32_t *a, int32_t fromIndex, int32_t toIndex, int32_t key) {
    return _binarySearchPointer(a, fromIndex, toIndex, sizeof(int32_t), &key, _compareI);
}

int32_t Arrays_binarySearchL(int64_t *a, int32_t length, int64_t key) {
    return _binarySearchPointer(a, 0, length, sizeof(int64_t), &key, _compareL);
}

int32_t Arrays_binarySearchRangeL(int64_t *a, int32_t fromIndex, int32_t toIndex, int64_t key) {
    return _binarySearchPointer(a, fromIndex, toIndex, sizeof(int64_t), &key, _compareL);
}

int32_t Arrays_binarySearchS(int16_t *a, int32_t length, int16_t key) {
    return _binarySearchPointer(a, 0, length, sizeof(int16_t), &key, _compareS);
}

int32_t Arrays_binarySearchRangeS(int16_t *a, int32_t fromIndex, int32_t toIndex, int16_t key) {
    return _binarySearchPointer(a, fromIndex, toIndex, sizeof(int16_t), &key, _compareS);
}

int32_t Arrays_binarySearchObj(void **a, int32_t length, void *key, int32_t (*c)(const void *, const void *)) {
    return _binarySearchPointer(a, 0, length, sizeof(void *), &key, c);
}

int32_t Arrays_binarySearchRangeObj(void **a, int32_t fromIndex, int32_t toIndex, void *key, int32_t (*c)(const void *, const void *)) {
    return _binarySearchPointer(a, fromIndex, toIndex, sizeof(void *), &key, c);
}

bool *Arrays_copyOfBool(bool *original, int32_t length, int32_t newLength) {
    return _copyOfRangePointer(original, length, sizeof(bool), 0, newLength);
}

int8_t *Arrays_copyOfB(int8_t *original, int32_t length, int32_t newLength) {
    return _copyOfRangePointer(original, length, sizeof(int8_t), 0, newLength);
}

char *Arrays_copyOfC(char *original, int32_t length, int32_t newLength) {
    return _copyOfRangePointer(original, length, sizeof(char), 0, newLength);
}

double *Arrays_copyOfD(double *original, int32_t length, int32_t newLength) {
    return _copyOfRangePointer(original, length, sizeof(double), 0, newLength);
}

float *Arrays_copyOfF(float *original, int32_t length, int32_t newLength) {
    return _copyOfRangePointer(original, length, sizeof(float), 0, newLength);
}

int32_t *Arrays_copyOfI(int32_t *original, int32_t length, int32_t newLength) {
    return _copyOfRangePointer(original, length, sizeof(int32_t), 0, newLength);
}

int64_t *Arrays_copyOfL(int64_t *original, int32_t length, int32_t newLength) {
    return _copyOfRangePointer(original, length, sizeof(int64_t), 0, newLength);
}

int16_t *Arrays_copyOfS(int16_t *original, int32_t length, int32_t newLength) {
    return _copyOfRangePointer(original, length, sizeof(int16_t), 0, newLength);
}

void **Arrays_copyOfObj(void **original, int32_t length, int32_t newLength) {
    return _copyOfRangePointer(original, length, sizeof(void *), 0, newLength);
}

bool *Arrays_copyOfRangeBool(bool *original, int32_t length, int32_t from, int32_t to) {
    return _copyOfRangePointer(original, length, sizeof(bool), from, to);
}

int8_t *Arrays_copyOfRangeB(int8_t *original, int32_t length, int32_t from, int32_t to) {
    return _copyOfRangePointer(original, length, sizeof(int8_t), from, to);
}

char *Arrays_copyOfRangeC(char *original, int32_t length, int32_t from, int32_t to) {
    return _copyOfRangePointer(original, length, sizeof(char), from, to);
}

double *Arrays_copyOfRangeD(double *original, int32_t length, int32_t from, int32_t to) {
    return _copyOfRangePointer(original, length, sizeof(double), from, to);
}

float *Arrays_copyOfRangeF(float *original, int32_t length, int32_t from, int32_t to) {
    return _copyOfRangePointer(original, length, sizeof(float), from, to);
}

int32_t *Arrays_copyOfRangeI(int32_t *original, int32_t length, int32_t from, int32_t to) {
    return _copyOfRangePointer(original, length, sizeof(int32_t), from, to);
}

int64_t *Arrays_copyOfRangeL(int64_t *original, int32_t length, int32_t from, int32_t to) {
    return _copyOfRangePointer(original, length, sizeof(int64_t), from, to);
}

int16_t *Arrays_copyOfRangeS(int16_t *original, int32_t length, int32_t from, int32_t to) {
    return _copyOfRangePointer(original, length, sizeof(int16_t), from, to);
}

void **Arrays_copyOfRangeObj(void **original, int32_t length, int32_t from, int32_t to) {
    return _copyOfRangePointer(original, length, sizeof(void *), from, to);
}

bool Arrays_equalsBool(bool *a, int32_t length, bool *a2, int32_t length2) {
    return _equalsPointer(a, length, a2, length2, sizeof(bool), _equalsBool);
}

bool Arrays_equalsB(int8_t *a, int32_t length, int8_t *a2, int32_t length2) {
    return _equalsPointer(a, length, a2, length2, sizeof(int8_t), _equalsC);
}

bool Arrays_equalsC(char *a, int32_t length, char *a2, int32_t length2) {
    return _equalsPointer(a, length, a2, length2, sizeof(char), _equalsC);
}

bool Arrays_equalsD(double *a, int32_t length, double *a2, int32_t length2) {
    return _equalsPointer(a, length, a2, length2, sizeof(double), _equalsD);
}

bool Arrays_equalsF(float *a, int32_t length, float *a2, int32_t length2) {
    return _equalsPointer(a, length, a2, length2, sizeof(float), _equalsF);
}

bool Arrays_equalsI(int32_t *a, int32_t length, int32_t *a2, int32_t length2) {
    return _equalsPointer(a, length, a2, length2, sizeof(int32_t), _equalsI);
}

bool Arrays_equalsL(int64_t *a, int32_t length, int64_t *a2, int32_t length2) {
    return _equalsPointer(a, length, a2, length2, sizeof(int64_t), _equalsL);
}

bool Arrays_equalsObj(void **a, int32_t length, void **a2, int32_t length2, bool (*equals)(const void *, const void *)) {
    return _equalsPointer(a, length, a2, length2, sizeof(void *), equals);
}

bool Arrays_equalsS(int16_t *a, int32_t length, int16_t *a2, int32_t length2) {
    return _equalsPointer(a, length, a2, length2, sizeof(int16_t), _equalsS);
}

void Arrays_fillBool(bool *a, int32_t length, bool val) {
    _fillPointer(a, 0, length, sizeof(bool), &val);
}

void Arrays_fillRangeBool(bool *a, int32_t fromIndex, int32_t toIndex, bool val) {
    _fillPointer(a, fromIndex, toIndex, sizeof(bool), &val);
}

void Arrays_fillB(int8_t *a, int32_t length, int8_t val) {
    _fillPointer(a, 0, length, sizeof(int8_t), &val);
}

void Arrays_fillRangeB(int8_t *a, int32_t fromIndex, int32_t toIndex, int8_t val) {
    _fillPointer(a, fromIndex, toIndex, sizeof(int8_t), &val);
}

void Arrays_fillC(char *a, int32_t length, char val) {
    _fillPointer(a, 0, length, sizeof(char), &val);
}

void Arrays_fillRangeC(char *a, int32_t fromIndex, int32_t toIndex, char val) {
    _fillPointer(a, fromIndex, toIndex, sizeof(char), &val);
}

void Arrays_fillD(double *a, int32_t length, double val) {
    _fillPointer(a, 0, length, sizeof(double), &val);
}

void Arrays_fillRangeD(double *a, int32_t fromIndex, int32_t toIndex, double val) {
    _fillPointer(a, fromIndex, toIndex, sizeof(double), &val);
}

void Arrays_fillF(float *a, int32_t length, float val) {
    _fillPointer(a, 0, length, sizeof(float), &val);
}

void Arrays_fillRangeF(float *a, int32_t fromIndex, int32_t toIndex, float val) {
    _fillPointer(a, fromIndex, toIndex, sizeof(float), &val);
}

void Arrays_fillI(int32_t *a, int32_t length, int32_t val) {
    _fillPointer(a, 0, length, sizeof(int32_t), &val);
}

void Arrays_fillRangeI(int32_t *a, int32_t fromIndex, int32_t toIndex, int32_t val) {
    _fillPointer(a, fromIndex, toIndex, sizeof(int32_t), &val);
}

void Arrays_fillL(int64_t *a, int32_t length, int64_t val) {
    _fillPointer(a, 0, length, sizeof(int64_t), &val);
}

void Arrays_fillRangeL(int64_t *a, int32_t fromIndex, int32_t toIndex, int64_t val) {
    _fillPointer(a, fromIndex, toIndex, sizeof(int64_t), &val);
}

void Arrays_fillObj(void **a, int32_t length, void *val) {
    _fillPointer(a, 0, length, sizeof(void *), &val);
}

void Arrays_fillRangeObj(void **a, int32_t fromIndex, int32_t toIndex, void *val) {
    _fillPointer(a, fromIndex, toIndex, sizeof(void *), &val);
}

void Arrays_fillS(int16_t *a, int32_t length, int16_t val) {
    _fillPointer(a, 0, length, sizeof(int16_t), &val);
}

void Arrays_fillRangeS(int16_t *a, int32_t fromIndex, int32_t toIndex, int16_t val) {
    _fillPointer(a, fromIndex, toIndex, sizeof(int16_t), &val);
}

void Arrays_sortB(int8_t *a, int32_t length) {
    _sortPointer(a, 0, length, sizeof(int8_t), _compareC, false);
}

void Arrays_sortRangeB(int8_t *a, int32_t fromIndex, int32_t toIndex) {
    _sortPointer(a, fromIndex, toIndex, sizeof(int8_t), _compareC, false);
}

void Arrays_sortC(char *a, int32_t length) {
    _sortPointer(a, 0, length, sizeof(char), _compareC, false);
}

void Arrays_sortRangeC(char *a, int32_t fromIndex, int32_t toIndex) {
    _sortPointer(a, fromIndex, toIndex, sizeof(char), _compareC, false);
}

void Arrays_sortD(double *a, int32_t length) {
    _sortPointer(a, 0, length, sizeof(double), _compareD, false);
}

void Arrays_sortRangeD(double *a, int32_t fromIndex, int32_t toIndex) {
    _sortPointer(a, fromIndex, toIndex, sizeof(double), _compareD, false);
}

void Arrays_sortF(float *a, int32_t length) {
    _sortPointer(a, 0, length, sizeof(float), _compareF, false);
}

void Arrays_sortRangeF(float *a, int32_t fromIndex, int32_t toIndex) {
    _sortPointer(a, fromIndex, toIndex, sizeof(float), _compareF, false);
}

void Arrays_sortI(int32_t *a, int32_t length) {
    _sortPointer(a, 0, length, sizeof(int32_t), _compareI, false);
}

void Arrays_sortRangeI(int32_t *a, int32_t fromIndex, int32_t toIndex) {
    _sortPointer(a, fromIndex, toIndex, sizeof(int32_t), _compareI, false);
}

void Arrays_sortL(int64_t *a, int32_t length) {
    _sortPointer(a, 0, length, sizeof(int64_t), _compareL, false);
}

void Arrays_sortRangeL(int64_t *a, int32_t fromIndex, int32_t toIndex) {
    _sortPointer(a, fromIndex, toIndex, sizeof(int64_t), _compareL, false);
}

void Arrays_sortS(int16_t *a, int32_t length) {
    _sortPointer(a, 0, length, sizeof(int16_t), _compareS, false);
}

void Arrays_sortRangeS(int16_t *a, int32_t fromIndex, int32_t toIndex) {
    _sortPointer(a, fromIndex, toIndex, sizeof(int16_t), _compareS, false);
}

void Arrays_sortObj(void **a, int32_t length, int32_t (*c)(const void *, const void *)) {
    _sortPointer(a, 0, length, sizeof(void *), c, true);
}

void Arrays_sortRangeObj(void **a, int32_t fromIndex, int32_t toIndex, int32_t (*c)(const void *, const void *)) {
    _sortPointer(a, fromIndex, toIndex, sizeof(void *), c, true);
}

String *Arrays_toStringBool(bool *a, int32_t length) {
    return _toStringPointer(a, length, sizeof(bool), _toStringBool);
}

String *Arrays_toStringB(int8_t *a, int32_t length) {
    return _toStringPointer(a, length, sizeof(int8_t), _toStringC);
}

String *Arrays_toStringC(char *a, int32_t length) {
    return _toStringPointer(a, length, sizeof(char), _toStringC);
}

String *Arrays_toStringD(double *a, int32_t length) {
    return _toStringPointer(a, length, sizeof(double), _toStringD);
}

String *Arrays_toStringF(float *a, int32_t length) {
    return _toStringPointer(a, length, sizeof(float), _toStringF);
}

String *Arrays_toStringI(int32_t *a, int32_t length) {
    return _toStringPointer(a, length, sizeof(int32_t), _toStringI);
}

String *Arrays_toStringL(int64_t *a, int32_t length) {
    return _toStringPointer(a, length, sizeof(int64_t), _toStringL);
}

String *Arrays_toStringObj(void **a, int32_t length, int32_t size, String *(*toString)(const void *)) {
    return _toStringPointer(a, length, size, toString);
}

String *Arrays_toStringS(int16_t *a, int32_t length) {
    return _toStringPointer(a, length, sizeof(int16_t), _toStringS);
}
