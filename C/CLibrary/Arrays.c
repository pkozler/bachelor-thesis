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
#include "String_.h"
#include "StringBuilder.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * default values used for copying one array to the another with greater length:
 */

bool _defaultBool = false;
int8_t _defaultByte = 0;
char _defaultChar = '\0';
double _defaultDouble = 0.0;
float _defaultFloat = 0.0f;
int32_t _defaultInt = 0;
int64_t _defaultLong = 0LL;
void *_defaultPointer = NULL;
int16_t _defaultShort = 0;

/*
 * functions for comparing the two specified values:
 */

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

/*
 * functions for testing if the two specified values are equal:
 */

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

/*
 * functions for returning the string representation of the specified value:
 */

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

/*
    Represents the type-agnostic function for binary searching
    in the specified sorted part of any array according to a specified compare function.
 */
int32_t _binarySearchPointer(void *a, int32_t fromIndex, int32_t toIndex, int32_t size, void *key, int32_t (*c)(const void *, const void *), bool isObjectArray) {
    // initial lower index
    int32_t lower = fromIndex;
    // initial upper index
    int32_t upper = toIndex - 1;

    while (lower <= upper) {
        // middle index
        int32_t middle = ((uint32_t)lower + (uint32_t)upper) >> 1;
        int32_t cmp; 
        
        // dereferencing the pointers to the struct pointers for comparing
        if (isObjectArray) {
            void **o1 = a + middle * size;
            void **o2 = key;
            cmp = c(*o1, *o2);
        }
        // getting the value pointers for comparing
        else {
            void *o1 = a + middle * size;
            void *o2 = key;
            cmp = c(o1, o2);
        }
        
        // middle index is the new lower index if the key is greater than middle value
        if (cmp < 0) {
            lower = middle + 1;
        }
        // middle index is the new upper index if the key is greater than middle value
        else if (cmp > 0) {
            upper = middle - 1;
        }
        // returning the element if middle index value is equal to the key
        else {
            return middle;
        }
    }

    // returning the negative index if element not found
    return -(lower + 1);
}

/*
    Represents the type-agnostic function for copying
    the specified part of any array.
 */
void *_copyOfRangePointer(void *original, int32_t length, int32_t size, int32_t from, int32_t to, void *defaultValue) {
    // a new array with the length equal to the difference of boundaries of the original array
    void *a = calloc(to - from, size);
    int32_t i;

    // the specified upper boundary if greater than the original array length
    if (to > length) {
        // copying the values from the original array to its last element
        for (i = from; i < length; i++) {
            memcpy(a + (i - from) * size, original + i * size, size);
        }

        // filling the rest of the new array with the default value of the given type
        for (i = length; i < to; i++) {
            memcpy(a + (i - from) * size, defaultValue, size);
        }
    }
    // the specified upper boundary is less then the original array length
    else {
        // copying the values from the original array to the element on the specified upper boundary
        for (i = from; i < to; i++) {
            memcpy(a + (i - from) * size, original + i * size, size);
        }
    }

    return a;
}

/*
    Represents the type-agnostic function for testing if two
    specified arrays are equal.
 */
bool _equalsPointer(void *a, int32_t length, void *a2, int32_t length2, int32_t size, bool (*equals)(const void *, const void *), bool isObjectArray) {
    // comparing pointers
    if (a == a2) {
        return true;
    }
    
    // testing the pointers for a NULL value
    if (a == NULL || a2 == NULL) {
        return false;
    }

    // comparing the array lengths
    if (length2 != length) {
        return false;
    }
    
    // comparing corresponding elements of arrays
    int32_t i;
    for (i = 0; i < length; i++) {
        bool e;
        
        // checking NULL values for object pointers
        if (isObjectArray) {
            void **o1 = a + i * size;
            void **o2 = a2 + i * size;
            e = *o1 == NULL ? *o2 == NULL : equals(*o1, *o2);
        }
        else {
            void *o1 = a + i * size;
            void *o2 = a2 + i * size;
            e = equals(o1, o2);
        }
        
        if (!e) {
            return false;
        }
    }

    return true;
}

/*
    Represents the type-agnostic function for filling
    the specified part of any array with the specified value.
 */
void _fillPointer(void *a, int32_t fromIndex, int32_t toIndex, int32_t size, void *val) {
    // setting each element to the value
    int32_t i;
    for (i = fromIndex; i < toIndex; i++) {
        memcpy(a + i * size, val, size);
    }
}

/*
    Represents the type-agnostic function for sorting
    the specified part of any array according to a specified compare function.
 */
void _sortPointer(void *a, int32_t fromIndex, int32_t toIndex, int32_t size, int32_t (*c)(const void *, const void *), bool isObjectArray) {
    // unstable sort for primitive values
    if (!isObjectArray) {
        qsort(a + fromIndex * size, toIndex - fromIndex, size, c);
    }
    // stable sort for structure pointers
    else {
        void **aux = malloc(sizeof(void *) * (toIndex - fromIndex));
        _mergeSort((void **)a, aux, fromIndex, toIndex - 1, c);
        free(aux);
    }
}

/*
    Represents the type-agnostic function for creating
    the string representation of any array.
 */
String *_toStringPointer(void *a, int32_t length, int32_t size, String *(*toString)(const void *), bool isObjectArray) {
    // create StringBuilder for appending the text
    StringBuilder *sb = new_StringBuilder();
    String *str = new_String("[");
    append(sb, str);
    delete_String(str);

    // append first element string representation
    if (length > 0) {
        // checking NULL values for struct pointers
        if (isObjectArray) {
            void **o = a;
            str = *o == NULL ? new_String("null") : toString(*o);
        }
        else  {
            void *o = a;
            str = toString(o);
        }
        
        append(sb, str);
        delete_String(str);
    }

    // append another elements string representation
    int32_t i;
    for (i = 1; i < length; i++) {
        str = new_String(", ");
        append(sb, str);
        delete_String(str);
        
        // checking NULL values for struct pointers
        if (isObjectArray) {
            void **o = a + i * size;
            str = *o == NULL ? new_String("null") : toString(*o);
        }
        else  {
            void *o = a + i * size;
            str = toString(o);
        }
        
        append(sb, str);
        delete_String(str);
    }

    // create Java-like string
    str = new_String("]");
    append(sb, str);
    delete_String(str);
    str = toStringSb(sb);
    delete_StringBuilder(sb);

    return str;
}

/**
 * Searches the specified array of bytes for the specified value using the
 * binary search algorithm
 *
 * @param a the array to be searched
 * @param length The array length
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array;
 * otherwise, (-(insertion point) - 1). The insertion point is defined as
 * the point at which the key would be inserted into the array: the index of
 * the first element greater than the key, or a.length if all elements in
 * the array are less than the specified key. Note that this guarantees that
 * the return value will be >= 0 if and only if the key is found.
 */
int32_t Arrays_binarySearchB(int8_t *a, int32_t length, int8_t key) {
    return _binarySearchPointer(a, 0, length, sizeof(int8_t), &key, _compareC, false);
}

/**
 * Searches a range of the specified array of bytes for the specified value
 * using the binary search algorithm.
 *
 * @param a the array to be searched
 * @param fromIndex the index of the first element (inclusive) to be
 * searched
 * @param toIndex the index of the last element (exclusive) to be searched
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array within
 * the specified range; otherwise, (-(insertion point) - 1). The insertion
 * point is defined as the point at which the key would be inserted into the
 * array: the index of the first element in the range greater than the key,
 * or toIndex if all elements in the range are less than the specified key.
 * Note that this guarantees that the return value will be >= 0 if and only
 * if the key is found.
 */
int32_t Arrays_binarySearchRangeB(int8_t *a, int32_t fromIndex, int32_t toIndex, int8_t key) {
    return _binarySearchPointer(a, fromIndex, toIndex, sizeof(int8_t), &key, _compareC, false);
}

/**
 * Searches the specified array of chars for the specified value using the
 * binary search algorithm.
 *
 * @param a the array to be searched
 * @param length The array length
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array;
 * otherwise, (-(insertion point) - 1). The insertion point is defined as
 * the point at which the key would be inserted into the array: the index of
 * the first element greater than the key, or a.length if all elements in
 * the array are less than the specified key. Note that this guarantees that
 * the return value will be >= 0 if and only if the key is found.
 */
int32_t Arrays_binarySearchC(char *a, int32_t length, char key) {
    return _binarySearchPointer(a, 0, length, sizeof(char), &key, _compareC, false);
}

/**
 * Searches a range of the specified array of chars for the specified value
 * using the binary search algorithm.
 *
 * @param a the array to be searched
 * @param fromIndex the index of the first element (inclusive) to be
 * searched
 * @param toIndex the index of the last element (exclusive) to be searched
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array within
 * the specified range; otherwise, (-(insertion point) - 1). The insertion
 * point is defined as the point at which the key would be inserted into the
 * array: the index of the first element in the range greater than the key,
 * or toIndex if all elements in the range are less than the specified key.
 * Note that this guarantees that the return value will be >= 0 if and only
 * if the key is found.
 */
int32_t Arrays_binarySearchRangeC(char *a, int32_t fromIndex, int32_t toIndex, char key) {
    return _binarySearchPointer(a, fromIndex, toIndex, sizeof(char), &key, _compareC, false);
}

/**
 * Searches the specified array of doubles for the specified value using the
 * binary search algorithm.
 *
 * @param a the array to be searched
 * @param length The array length
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array;
 * otherwise, (-(insertion point) - 1). The insertion point is defined as
 * the point at which the key would be inserted into the array: the index of
 * the first element greater than the key, or a.length if all elements in
 * the array are less than the specified key. Note that this guarantees that
 * the return value will be >= 0 if and only if the key is found.
 */
int32_t Arrays_binarySearchD(double *a, int32_t length, double key) {
    return _binarySearchPointer(a, 0, length, sizeof(double), &key, _compareD, false);
}

/**
 * Searches a range of the specified array of doubles for the specified
 * value using the binary search algorithm.
 *
 * @param a the array to be searched
 * @param fromIndex the index of the first element (inclusive) to be
 * searched
 * @param toIndex the index of the last element (exclusive) to be searched
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array within
 * the specified range; otherwise, (-(insertion point) - 1). The insertion
 * point is defined as the point at which the key would be inserted into the
 * array: the index of the first element in the range greater than the key,
 * or toIndex if all elements in the range are less than the specified key.
 * Note that this guarantees that the return value will be >= 0 if and only
 * if the key is found.
 */
int32_t Arrays_binarySearchRangeD(double *a, int32_t fromIndex, int32_t toIndex, double key) {
    return _binarySearchPointer(a, fromIndex, toIndex, sizeof(double), &key, _compareD, false);
}

/**
 * Searches the specified array of floats for the specified value using the
 * binary search algorithm.
 *
 * @param a the array to be searched
 * @param length The array length
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array;
 * otherwise, (-(insertion point) - 1). The insertion point is defined as
 * the point at which the key would be inserted into the array: the index of
 * the first element greater than the key, or a.length if all elements in
 * the array are less than the specified key. Note that this guarantees that
 * the return value will be >= 0 if and only if the key is found.
 */
int32_t Arrays_binarySearchF(float *a, int32_t length, float key) {
    return _binarySearchPointer(a, 0, length, sizeof(float), &key, _compareF, false);
}

/**
 * Searches a range of the specified array of floats for the specified value
 * using the binary search algorithm.
 *
 * @param a the array to be searched
 * @param fromIndex the index of the first element (inclusive) to be
 * searched
 * @param toIndex the index of the last element (exclusive) to be searched
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array within
 * the specified range; otherwise, (-(insertion point) - 1). The insertion
 * point is defined as the point at which the key would be inserted into the
 * array: the index of the first element in the range greater than the key,
 * or toIndex if all elements in the range are less than the specified key.
 * Note that this guarantees that the return value will be >= 0 if and only
 * if the key is found.
 */
int32_t Arrays_binarySearchRangeF(float *a, int32_t fromIndex, int32_t toIndex, float key) {
    return _binarySearchPointer(a, fromIndex, toIndex, sizeof(float), &key, _compareF, false);
}

/**
 * Searches the specified array of ints for the specified value using the
 * binary search algorithm.
 *
 * @param a the array to be searched
 * @param length The array length
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array;
 * otherwise, (-(insertion point) - 1). The insertion point is defined as
 * the point at which the key would be inserted into the array: the index of
 * the first element greater than the key, or a.length if all elements in
 * the array are less than the specified key. Note that this guarantees that
 * the return value will be >= 0 if and only if the key is found.
 */
int32_t Arrays_binarySearchI(int32_t *a, int32_t length, int32_t key) {
    return _binarySearchPointer(a, 0, length, sizeof(int32_t), &key, _compareI, false);
}

/**
 * Searches a range of the specified array of ints for the specified value
 * using the binary search algorithm.
 *
 * @param a the array to be searched
 * @param fromIndex the index of the first element (inclusive) to be
 * searched
 * @param toIndex the index of the last element (exclusive) to be searched
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array within
 * the specified range; otherwise, (-(insertion point) - 1). The insertion
 * point is defined as the point at which the key would be inserted into the
 * array: the index of the first element in the range greater than the key,
 * or toIndex if all elements in the range are less than the specified key.
 * Note that this guarantees that the return value will be >= 0 if and only
 * if the key is found.
 */
int32_t Arrays_binarySearchRangeI(int32_t *a, int32_t fromIndex, int32_t toIndex, int32_t key) {
    return _binarySearchPointer(a, fromIndex, toIndex, sizeof(int32_t), &key, _compareI, false);
}

/**
 * Searches the specified array of longs for the specified value using the
 * binary search algorithm.
 *
 * @param a the array to be searched
 * @param length The array length
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array;
 * otherwise, (-(insertion point) - 1). The insertion point is defined as
 * the point at which the key would be inserted into the array: the index of
 * the first element greater than the key, or a.length if all elements in
 * the array are less than the specified key. Note that this guarantees that
 * the return value will be >= 0 if and only if the key is found.
 */
int32_t Arrays_binarySearchL(int64_t *a, int32_t length, int64_t key) {
    return _binarySearchPointer(a, 0, length, sizeof(int64_t), &key, _compareL, false);
}

/**
 * Searches a range of the specified array of longs for the specified value
 * using the binary search algorithm.
 *
 * @param a the array to be searched
 * @param fromIndex the index of the first element (inclusive) to be
 * searched
 * @param toIndex the index of the last element (exclusive) to be searched
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array within
 * the specified range; otherwise, (-(insertion point) - 1). The insertion
 * point is defined as the point at which the key would be inserted into the
 * array: the index of the first element in the range greater than the key,
 * or toIndex if all elements in the range are less than the specified key.
 * Note that this guarantees that the return value will be >= 0 if and only
 * if the key is found.
 */
int32_t Arrays_binarySearchRangeL(int64_t *a, int32_t fromIndex, int32_t toIndex, int64_t key) {
    return _binarySearchPointer(a, fromIndex, toIndex, sizeof(int64_t), &key, _compareL, false);
}

/**
 * Searches the specified array for the specified structure using the binary
 * search algorithm.
 *
 * @param a the array to be searched
 * @param length The array length
 * @param key the value to be searched for
 * @param c The structure compare function
 * @return index of the search key, if it is contained in the array;
 * otherwise, (-(insertion point) - 1). The insertion point is defined as
 * the point at which the key would be inserted into the array: the index of
 * the first element greater than the key, or a.length if all elements in
 * the array are less than the specified key. Note that this guarantees that
 * the return value will be >= 0 if and only if the key is found.
 */
int32_t Arrays_binarySearchObj(void **a, int32_t length, void *key, int32_t (*c)(const void *, const void *)) {
    return _binarySearchPointer(a, 0, length, sizeof(void *), &key, c, true);
}

/**
 * Searches a range of the specified array for the specified structure using
 * the binary search algorithm.
 *
 * @param a the array to be searched
 * @param fromIndex the index of the first element (inclusive) to be
 * searched
 * @param toIndex the index of the last element (exclusive) to be searched
 * @param key the value to be searched for
 * @param c The structure compare function
 * @return index of the search key, if it is contained in the array within
 * the specified range; otherwise, (-(insertion point) - 1). The insertion
 * point is defined as the point at which the key would be inserted into the
 * array: the index of the first element in the range greater than the key,
 * or toIndex if all elements in the range are less than the specified key.
 * Note that this guarantees that the return value will be >= 0 if and only
 * if the key is found.
 */
int32_t Arrays_binarySearchRangeObj(void **a, int32_t fromIndex, int32_t toIndex, void *key, int32_t (*c)(const void *, const void *)) {
    return _binarySearchPointer(a, fromIndex, toIndex, sizeof(void *), &key, c, true);
}

/**
 * Searches the specified array of shorts for the specified value using the
 * binary search algorithm.
 *
 * @param a the array to be searched
 * @param length The array length
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array;
 * otherwise, (-(insertion point) - 1). The insertion point is defined as
 * the point at which the key would be inserted into the array: the index of
 * the first element greater than the key, or a.length if all elements in
 * the array are less than the specified key. Note that this guarantees that
 * the return value will be >= 0 if and only if the key is found.
 */
int32_t Arrays_binarySearchS(int16_t *a, int32_t length, int16_t key) {
    return _binarySearchPointer(a, 0, length, sizeof(int16_t), &key, _compareS, false);
}

/**
 * Searches a range of the specified array of shorts for the specified value
 * using the binary search algorithm.
 *
 * @param a the array to be searched
 * @param fromIndex the index of the first element (inclusive) to be
 * searched
 * @param toIndex the index of the last element (exclusive) to be searched
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array within
 * the specified range; otherwise, (-(insertion point) - 1). The insertion
 * point is defined as the point at which the key would be inserted into the
 * array: the index of the first element in the range greater than the key,
 * or toIndex if all elements in the range are less than the specified key.
 * Note that this guarantees that the return value will be >= 0 if and only
 * if the key is found.
 */
int32_t Arrays_binarySearchRangeS(int16_t *a, int32_t fromIndex, int32_t toIndex, int16_t key) {
    return _binarySearchPointer(a, fromIndex, toIndex, sizeof(int16_t), &key, _compareS, false);
}

/**
 * Copies the specified array, truncating or padding with false (if
 * necessary) so the copy has the specified length.
 *
 * @param original the array to be copied
 * @param length The array length
 * @param newLength the length of the copy to be returned
 * @return a copy of the original array, truncated or padded with false
 * elements to obtain the specified length
 */
bool *Arrays_copyOfBool(bool *original, int32_t length, int32_t newLength) {
    return _copyOfRangePointer(original, length, sizeof(bool), 0, newLength, &_defaultBool);
}

/**
 * Copies the specified array, truncating or padding with zeros (if
 * necessary) so the copy has the specified length.
 *
 * @param original the array to be copied
 * @param length The array length
 * @param newLength the length of the copy to be returned
 * @return a copy of the original array, truncated or padded with zeros to
 * obtain the specified length
 */
int8_t *Arrays_copyOfB(int8_t *original, int32_t length, int32_t newLength) {
    return _copyOfRangePointer(original, length, sizeof(int8_t), 0, newLength, &_defaultByte);
}

/**
 * Copies the specified array, truncating or padding with null characters
 * (if necessary) so the copy has the specified length.
 *
 * @param original the array to be copied
 * @param length The array length
 * @param newLength the length of the copy to be returned
 * @return a copy of the original array, truncated or padded with null
 * characters to obtain the specified length
 */
char *Arrays_copyOfC(char *original, int32_t length, int32_t newLength) {
    return _copyOfRangePointer(original, length, sizeof(char), 0, newLength, &_defaultChar);
}

/**
 * Copies the specified array, truncating or padding with zeros (if
 * necessary) so the copy has the specified length.
 *
 * @param original the array to be copied
 * @param length The array length
 * @param newLength the length of the copy to be returned
 * @return a copy of the original array, truncated or padded with zeros to
 * obtain the specified length
 */
double *Arrays_copyOfD(double *original, int32_t length, int32_t newLength) {
    return _copyOfRangePointer(original, length, sizeof(double), 0, newLength, &_defaultDouble);
}

/**
 * Copies the specified array, truncating or padding with zeros (if
 * necessary) so the copy has the specified length.
 *
 * @param original the array to be copied
 * @param length The array length
 * @param newLength the length of the copy to be returned
 * @return a copy of the original array, truncated or padded with zeros to
 * obtain the specified length
 */
float *Arrays_copyOfF(float *original, int32_t length, int32_t newLength) {
    return _copyOfRangePointer(original, length, sizeof(float), 0, newLength, &_defaultFloat);
}

/**
 * Copies the specified array, truncating or padding with zeros (if
 * necessary) so the copy has the specified length.
 *
 * @param original the array to be copied
 * @param length The array length
 * @param newLength the length of the copy to be returned
 * @return a copy of the original array, truncated or padded with zeros to
 * obtain the specified length
 */
int32_t *Arrays_copyOfI(int32_t *original, int32_t length, int32_t newLength) {
    return _copyOfRangePointer(original, length, sizeof(int32_t), 0, newLength, &_defaultInt);
}

/**
 * Copies the specified array, truncating or padding with zeros (if
 * necessary) so the copy has the specified length.
 *
 * @param original the array to be copied
 * @param length The array length
 * @param newLength the length of the copy to be returned
 * @return a copy of the original array, truncated or padded with zeros to
 * obtain the specified length
 */
int64_t *Arrays_copyOfL(int64_t *original, int32_t length, int32_t newLength) {
    return _copyOfRangePointer(original, length, sizeof(int64_t), 0, newLength, &_defaultLong);
}

/**
 * Copies the specified array, truncating or padding with zeros (if
 * necessary) so the copy has the specified length.
 *
 * @param original the array to be copied
 * @param length The array length
 * @param newLength the length of the copy to be returned
 * @return a copy of the original array, truncated or padded with zeros to
 * obtain the specified length
 */
int16_t *Arrays_copyOfS(int16_t *original, int32_t length, int32_t newLength) {
    return _copyOfRangePointer(original, length, sizeof(int16_t), 0, newLength, &_defaultShort);
}

/**
 * Copies the specified array, truncating or padding with nulls (if
 * necessary) so the copy has the specified length.
 *
 * @param original the array to be copied
 * @param length The array length
 * @param newLength the length of the copy to be returned
 * @return a copy of the original array, truncated or padded with nulls to
 * obtain the specified length
 */
void **Arrays_copyOfObj(void **original, int32_t length, int32_t newLength) {
    return _copyOfRangePointer(original, length, sizeof(void *), 0, newLength, &_defaultPointer);
}

/**
 * Copies the specified range of the specified array into a new array.
 *
 * @param original the array from which a range is to be copied
 * @param length The array length
 * @param from the initial index of the range to be copied, inclusive
 * @param to the final index of the range to be copied, exclusive. (This
 * index may lie outside the array.)
 * @return a new array containing the specified range from the original
 * array, truncated or padded with false elements to obtain the required
 * length
 */
bool *Arrays_copyOfRangeBool(bool *original, int32_t length, int32_t from, int32_t to) {
    return _copyOfRangePointer(original, length, sizeof(bool), from, to, &_defaultBool);
}

/**
 * Copies the specified range of the specified array into a new array.
 *
 * @param original the array from which a range is to be copied
 * @param length The array length
 * @param from the initial index of the range to be copied, inclusive
 * @param to the final index of the range to be copied, exclusive. (This
 * index may lie outside the array.)
 * @return a new array containing the specified range from the original
 * array, truncated or padded with zeros to obtain the required length
 */
int8_t *Arrays_copyOfRangeB(int8_t *original, int32_t length, int32_t from, int32_t to) {
    return _copyOfRangePointer(original, length, sizeof(int8_t), from, to, &_defaultByte);
}

/**
 * Copies the specified range of the specified array into a new array.
 *
 * @param original the array from which a range is to be copied
 * @param length The array length
 * @param from the initial index of the range to be copied, inclusive
 * @param to the final index of the range to be copied, exclusive. (This
 * index may lie outside the array.)
 * @return a new array containing the specified range from the original
 * array, truncated or padded with null characters to obtain the required
 * length
 */
char *Arrays_copyOfRangeC(char *original, int32_t length, int32_t from, int32_t to) {
    return _copyOfRangePointer(original, length, sizeof(char), from, to, &_defaultChar);
}

/**
 * Copies the specified range of the specified array into a new array.
 *
 * @param original the array from which a range is to be copied
 * @param length The array length
 * @param from the initial index of the range to be copied, inclusive
 * @param to the final index of the range to be copied, exclusive. (This
 * index may lie outside the array.)
 * @return a new array containing the specified range from the original
 * array, truncated or padded with zeros to obtain the required length
 */
double *Arrays_copyOfRangeD(double *original, int32_t length, int32_t from, int32_t to) {
    return _copyOfRangePointer(original, length, sizeof(double), from, to, &_defaultDouble);
}

/**
 * Copies the specified range of the specified array into a new array.
 *
 * @param original the array from which a range is to be copied
 * @param length The array length
 * @param from the initial index of the range to be copied, inclusive
 * @param to the final index of the range to be copied, exclusive. (This
 * index may lie outside the array.)
 * @return a new array containing the specified range from the original
 * array, truncated or padded with zeros to obtain the required length
 */
float *Arrays_copyOfRangeF(float *original, int32_t length, int32_t from, int32_t to) {
    return _copyOfRangePointer(original, length, sizeof(float), from, to, &_defaultFloat);
}

/**
 * Copies the specified range of the specified array into a new array.
 *
 * @param original the array from which a range is to be copied
 * @param length The array length
 * @param from the initial index of the range to be copied, inclusive
 * @param to the final index of the range to be copied, exclusive. (This
 * index may lie outside the array.)
 * @return a new array containing the specified range from the original
 * array, truncated or padded with zeros to obtain the required length
 */
int32_t *Arrays_copyOfRangeI(int32_t *original, int32_t length, int32_t from, int32_t to) {
    return _copyOfRangePointer(original, length, sizeof(int32_t), from, to, &_defaultInt);
}

/**
 * Copies the specified range of the specified array into a new array.
 *
 * @param original the array from which a range is to be copied
 * @param length The array length
 * @param from the initial index of the range to be copied, inclusive
 * @param to the final index of the range to be copied, exclusive. (This
 * index may lie outside the array.)
 * @return a new array containing the specified range from the original
 * array, truncated or padded with zeros to obtain the required length
 */
int64_t *Arrays_copyOfRangeL(int64_t *original, int32_t length, int32_t from, int32_t to) {
    return _copyOfRangePointer(original, length, sizeof(int64_t), from, to, &_defaultLong);
}

/**
 * Copies the specified range of the specified array into a new array.
 *
 * @param original the array from which a range is to be copied
 * @param length The array length
 * @param from the initial index of the range to be copied, inclusive
 * @param to the final index of the range to be copied, exclusive. (This
 * index may lie outside the array.)
 * @return a new array containing the specified range from the original
 * array, truncated or padded with zeros to obtain the required length
 */
int16_t *Arrays_copyOfRangeS(int16_t *original, int32_t length, int32_t from, int32_t to) {
    return _copyOfRangePointer(original, length, sizeof(int16_t), from, to, &_defaultShort);
}

/**
 * Copies the specified range of the specified array into a new array.
 *
 * @param original the array from which a range is to be copied
 * @param length The array length
 * @param from the initial index of the range to be copied, inclusive
 * @param to the final index of the range to be copied, exclusive. (This
 * index may lie outside the array.)
 * @return a new array containing the specified range from the original
 * array, truncated or padded with nulls to obtain the required length
 */
void **Arrays_copyOfRangeObj(void **original, int32_t length, int32_t from, int32_t to) {
    return _copyOfRangePointer(original, length, sizeof(void *), from, to, &_defaultPointer);
}

/**
 * Returns true if the two specified arrays of booleans are equal to one
 * another.
 *
 * @param a one array to be tested for equality
 * @param length The array length
 * @param a2 the other array to be tested for equality
 * @param length2 The other array length
 * @return true if the two arrays are equal
 */
bool Arrays_equalsBool(bool *a, int32_t length, bool *a2, int32_t length2) {
    return _equalsPointer(a, length, a2, length2, sizeof(bool), _equalsBool, false);
}

/**
 * Returns true if the two specified arrays of bytes are equal to one
 * another.
 *
 * @param a one array to be tested for equality
 * @param length The array length
 * @param a2 the other array to be tested for equality
 * @param length2 The other array length
 * @return true if the two arrays are equal
 */
bool Arrays_equalsB(int8_t *a, int32_t length, int8_t *a2, int32_t length2) {
    return _equalsPointer(a, length, a2, length2, sizeof(int8_t), _equalsC, false);
}

/**
 * Returns true if the two specified arrays of chars are equal to one
 * another.
 *
 * @param a one array to be tested for equality
 * @param length The array length
 * @param a2 the other array to be tested for equality
 * @param length2 The other array length
 * @return true if the two arrays are equal
 */
bool Arrays_equalsC(char *a, int32_t length, char *a2, int32_t length2) {
    return _equalsPointer(a, length, a2, length2, sizeof(char), _equalsC, false);
}

/**
 * Returns true if the two specified arrays of doubles are equal to one
 * another.
 *
 * @param a one array to be tested for equality
 * @param length The array length
 * @param a2 the other array to be tested for equality
 * @param length2 The other array length
 * @return true if the two arrays are equal
 */
bool Arrays_equalsD(double *a, int32_t length, double *a2, int32_t length2) {
    return _equalsPointer(a, length, a2, length2, sizeof(double), _equalsD, false);
}

/**
 * Returns true if the two specified arrays of floats are equal to one
 * another.
 *
 * @param a one array to be tested for equality
 * @param length The array length
 * @param a2 the other array to be tested for equality
 * @param length2 The other array length
 * @return true if the two arrays are equal
 */
bool Arrays_equalsF(float *a, int32_t length, float *a2, int32_t length2) {
    return _equalsPointer(a, length, a2, length2, sizeof(float), _equalsF, false);
}

/**
 * Returns true if the two specified arrays of ints are equal to one
 * another.
 *
 * @param a one array to be tested for equality
 * @param length The array length
 * @param a2 the other array to be tested for equality
 * @param length2 The other array length
 * @return true if the two arrays are equal
 */
bool Arrays_equalsI(int32_t *a, int32_t length, int32_t *a2, int32_t length2) {
    return _equalsPointer(a, length, a2, length2, sizeof(int32_t), _equalsI, false);
}

/**
 * Returns true if the two specified arrays of longs are equal to one
 * another.
 *
 * @param a one array to be tested for equality
 * @param length The array length
 * @param a2 the other array to be tested for equality
 * @param length2 The other array length
 * @return true if the two arrays are equal
 */
bool Arrays_equalsL(int64_t *a, int32_t length, int64_t *a2, int32_t length2) {
    return _equalsPointer(a, length, a2, length2, sizeof(int64_t), _equalsL, false);
}

/**
 * Returns true if the two specified arrays of structures are equal to one
 * another.
 *
 * @param a one array to be tested for equality
 * @param length The array length
 * @param a2 the other array to be tested for equality
 * @param length2 The other array length
 * @param equals The structure equals function
 * @return true if the two arrays are equal
 */
bool Arrays_equalsObj(void **a, int32_t length, void **a2, int32_t length2, bool (*equals)(const void *, const void *)) {
    return _equalsPointer(a, length, a2, length2, sizeof(void *), equals, true);
}

/**
 * Returns true if the two specified arrays of shorts are equal to one
 * another.
 *
 * @param a one array to be tested for equality
 * @param length The array length
 * @param a2 the other array to be tested for equality
 * @param length2 The other array length
 * @return true if the two arrays are equal
 */
bool Arrays_equalsS(int16_t *a, int32_t length, int16_t *a2, int32_t length2) {
    return _equalsPointer(a, length, a2, length2, sizeof(int16_t), _equalsS, false);
}

/**
 * Assigns the specified boolean value to each element of the specified
 * array of booleans.
 *
 * @param a the array to be filled
 * @param length The array length
 * @param val the value to be stored in all elements of the array
 */
void Arrays_fillBool(bool *a, int32_t length, bool val) {
    _fillPointer(a, 0, length, sizeof(bool), &val);
}

/**
 * Assigns the specified boolean value to each element of the specified
 * range of the specified array of booleans.
 *
 * @param a the array to be filled
 * @param fromIndex the index of the first element (inclusive) to be filled
 * with the specified value
 * @param toIndex the index of the last element (exclusive) to be filled
 * with the specified value
 * @param val the value to be stored in all elements of the array
 */
void Arrays_fillRangeBool(bool *a, int32_t fromIndex, int32_t toIndex, bool val) {
    _fillPointer(a, fromIndex, toIndex, sizeof(bool), &val);
}

/**
 * Assigns the specified byte value to each element of the specified array
 * of bytes.
 *
 * @param a the array to be filled
 * @param length The array length
 * @param val the value to be stored in all elements of the array
 */
void Arrays_fillB(int8_t *a, int32_t length, int8_t val) {
    _fillPointer(a, 0, length, sizeof(int8_t), &val);
}

/**
 * Assigns the specified byte value to each element of the specified range
 * of the specified array of bytes.
 *
 * @param a the array to be filled
 * @param fromIndex the index of the first element (inclusive) to be filled
 * with the specified value
 * @param toIndex the index of the last element (exclusive) to be filled
 * with the specified value
 * @param val the value to be stored in all elements of the array
 */
void Arrays_fillRangeB(int8_t *a, int32_t fromIndex, int32_t toIndex, int8_t val) {
    _fillPointer(a, fromIndex, toIndex, sizeof(int8_t), &val);
}

/**
 * Assigns the specified char value to each element of the specified array
 * of chars.
 *
 * @param a the array to be filled
 * @param length The array length
 * @param val the value to be stored in all elements of the array
 */
void Arrays_fillC(char *a, int32_t length, char val) {
    _fillPointer(a, 0, length, sizeof(char), &val);
}

/**
 * Assigns the specified char value to each element of the specified range
 * of the specified array of chars.
 *
 * @param a the array to be filled
 * @param fromIndex the index of the first element (inclusive) to be filled
 * with the specified value
 * @param toIndex the index of the last element (exclusive) to be filled
 * with the specified value
 * @param val the value to be stored in all elements of the array
 */
void Arrays_fillRangeC(char *a, int32_t fromIndex, int32_t toIndex, char val) {
    _fillPointer(a, fromIndex, toIndex, sizeof(char), &val);
}

/**
 * Assigns the specified double value to each element of the specified array
 * of doubles.
 *
 * @param a the array to be filled
 * @param length The array length
 * @param val the value to be stored in all elements of the array
 */
void Arrays_fillD(double *a, int32_t length, double val) {
    _fillPointer(a, 0, length, sizeof(double), &val);
}

/**
 * Assigns the specified double value to each element of the specified range
 * of the specified array of doubles.
 *
 * @param a the array to be filled
 * @param fromIndex the index of the first element (inclusive) to be filled
 * with the specified value
 * @param toIndex the index of the last element (exclusive) to be filled
 * with the specified value
 * @param val the value to be stored in all elements of the array
 */
void Arrays_fillRangeD(double *a, int32_t fromIndex, int32_t toIndex, double val) {
    _fillPointer(a, fromIndex, toIndex, sizeof(double), &val);
}

/**
 * Assigns the specified float value to each element of the specified array
 * of floats.
 *
 * @param a the array to be filled
 * @param length The array length
 * @param val the value to be stored in all elements of the array
 */
void Arrays_fillF(float *a, int32_t length, float val) {
    _fillPointer(a, 0, length, sizeof(float), &val);
}

/**
 * Assigns the specified float value to each element of the specified range
 * of the specified array of floats.
 *
 * @param a the array to be filled
 * @param fromIndex the index of the first element (inclusive) to be filled
 * with the specified value
 * @param toIndex the index of the last element (exclusive) to be filled
 * with the specified value
 * @param val the value to be stored in all elements of the array
 */
void Arrays_fillRangeF(float *a, int32_t fromIndex, int32_t toIndex, float val) {
    _fillPointer(a, fromIndex, toIndex, sizeof(float), &val);
}

/**
 * Assigns the specified int value to each element of the specified array of
 * ints.
 *
 * @param a the array to be filled
 * @param length The array length
 * @param val the value to be stored in all elements of the array
 */
void Arrays_fillI(int32_t *a, int32_t length, int32_t val) {
    _fillPointer(a, 0, length, sizeof(int32_t), &val);
}

/**
 * Assigns the specified int value to each element of the specified range of
 * the specified array of ints.
 *
 * @param a the array to be filled
 * @param fromIndex the index of the first element (inclusive) to be filled
 * with the specified value
 * @param toIndex the index of the last element (exclusive) to be filled
 * with the specified value
 * @param val the value to be stored in all elements of the array
 */
void Arrays_fillRangeI(int32_t *a, int32_t fromIndex, int32_t toIndex, int32_t val) {
    _fillPointer(a, fromIndex, toIndex, sizeof(int32_t), &val);
}

/**
 * Assigns the specified long value to each element of the specified array
 * of longs.
 *
 * @param a the array to be filled
 * @param length The array length
 * @param val the value to be stored in all elements of the array
 */
void Arrays_fillL(int64_t *a, int32_t length, int64_t val) {
    _fillPointer(a, 0, length, sizeof(int64_t), &val);
}

/**
 * Assigns the specified long value to each element of the specified range
 * of the specified array of longs.
 *
 * @param a the array to be filled
 * @param fromIndex the index of the first element (inclusive) to be filled
 * with the specified value
 * @param toIndex the index of the last element (exclusive) to be filled
 * with the specified value
 * @param val the value to be stored in all elements of the array
 */
void Arrays_fillRangeL(int64_t *a, int32_t fromIndex, int32_t toIndex, int64_t val) {
    _fillPointer(a, fromIndex, toIndex, sizeof(int64_t), &val);
}

/**
 * Assigns the specified structure pointer to each element of the specified
 * array of structures.
 *
 * @param a the array to be filled
 * @param length The array length
 * @param val the value to be stored in all elements of the array
 */
void Arrays_fillObj(void **a, int32_t length, void *val) {
    _fillPointer(a, 0, length, sizeof(void *), &val);
}

/**
 * Assigns the specified structure pointer to each element of the specified
 * range of the specified array of structures.
 *
 * @param a the array to be filled
 * @param fromIndex the index of the first element (inclusive) to be filled
 * with the specified value
 * @param toIndex the index of the last element (exclusive) to be filled
 * with the specified value
 * @param val the value to be stored in all elements of the array
 */
void Arrays_fillRangeObj(void **a, int32_t fromIndex, int32_t toIndex, void *val) {
    _fillPointer(a, fromIndex, toIndex, sizeof(void *), &val);
}

/**
 * Assigns the specified short value to each element of the specified array
 * of shorts.
 *
 * @param a the array to be filled
 * @param length The array length
 * @param val the value to be stored in all elements of the array
 */
void Arrays_fillS(int16_t *a, int32_t length, int16_t val) {
    _fillPointer(a, 0, length, sizeof(int16_t), &val);
}

/**
 * Assigns the specified short value to each element of the specified range
 * of the specified array of shorts.
 *
 * @param a the array to be filled
 * @param fromIndex the index of the first element (inclusive) to be filled
 * with the specified value
 * @param toIndex the index of the last element (exclusive) to be filled
 * with the specified value
 * @param val the value to be stored in all elements of the array
 */
void Arrays_fillRangeS(int16_t *a, int32_t fromIndex, int32_t toIndex, int16_t val) {
    _fillPointer(a, fromIndex, toIndex, sizeof(int16_t), &val);
}

/**
 * Sorts the specified array into ascending numerical order.
 *
 * @param a the array to be sorted
 * @param length The array length
 */
void Arrays_sortB(int8_t *a, int32_t length) {
    _sortPointer(a, 0, length, sizeof(int8_t), _compareC, false);
}

/**
 * Sorts the specified range of the array into ascending order.
 *
 * @param a the array to be sorted
 * @param fromIndex the index of the first element (inclusive) to be sorted
 * @param toIndex the index of the last element (exclusive) to be sorted
 */
void Arrays_sortRangeB(int8_t *a, int32_t fromIndex, int32_t toIndex) {
    _sortPointer(a, fromIndex, toIndex, sizeof(int8_t), _compareC, false);
}

/**
 * Sorts the specified array into ascending numerical order.
 *
 * @param a the array to be sorted
 * @param length The array length
 */
void Arrays_sortC(char *a, int32_t length) {
    _sortPointer(a, 0, length, sizeof(char), _compareC, false);
}

/**
 * Sorts the specified range of the array into ascending order.
 *
 * @param a the array to be sorted
 * @param fromIndex the index of the first element (inclusive) to be sorted
 * @param toIndex the index of the last element (exclusive) to be sorted
 */
void Arrays_sortRangeC(char *a, int32_t fromIndex, int32_t toIndex) {
    _sortPointer(a, fromIndex, toIndex, sizeof(char), _compareC, false);
}

/**
 * Sorts the specified array into ascending numerical order.
 *
 * @param a the array to be sorted
 * @param length The array length
 */
void Arrays_sortD(double *a, int32_t length) {
    _sortPointer(a, 0, length, sizeof(double), _compareD, false);
}

/**
 * Sorts the specified range of the array into ascending order.
 *
 * @param a the array to be sorted
 * @param fromIndex the index of the first element (inclusive) to be sorted
 * @param toIndex the index of the last element (exclusive) to be sorted
 */
void Arrays_sortRangeD(double *a, int32_t fromIndex, int32_t toIndex) {
    _sortPointer(a, fromIndex, toIndex, sizeof(double), _compareD, false);
}

/**
 * Sorts the specified array into ascending numerical order.
 *
 * @param a the array to be sorted
 * @param length The array length
 */
void Arrays_sortF(float *a, int32_t length) {
    _sortPointer(a, 0, length, sizeof(float), _compareF, false);
}

/**
 * Sorts the specified range of the array into ascending order.
 *
 * @param a the array to be sorted
 * @param fromIndex the index of the first element (inclusive) to be sorted
 * @param toIndex the index of the last element (exclusive) to be sorted
 */
void Arrays_sortRangeF(float *a, int32_t fromIndex, int32_t toIndex) {
    _sortPointer(a, fromIndex, toIndex, sizeof(float), _compareF, false);
}

/**
 * Sorts the specified array into ascending numerical order.
 *
 * @param a the array to be sorted
 * @param length The array length
 */
void Arrays_sortI(int32_t *a, int32_t length) {
    _sortPointer(a, 0, length, sizeof(int32_t), _compareI, false);
}

/**
 * Sorts the specified range of the array into ascending order.
 *
 * @param a the array to be sorted
 * @param fromIndex the index of the first element (inclusive) to be sorted
 * @param toIndex the index of the last element (exclusive) to be sorted
 */
void Arrays_sortRangeI(int32_t *a, int32_t fromIndex, int32_t toIndex) {
    _sortPointer(a, fromIndex, toIndex, sizeof(int32_t), _compareI, false);
}

/**
 * Sorts the specified array into ascending numerical order.
 *
 * @param a the array to be sorted
 * @param length The array length
 */
void Arrays_sortL(int64_t *a, int32_t length) {
    _sortPointer(a, 0, length, sizeof(int64_t), _compareL, false);
}

/**
 * Sorts the specified range of the array into ascending order.
 *
 * @param a the array to be sorted
 * @param fromIndex the index of the first element (inclusive) to be sorted
 * @param toIndex the index of the last element (exclusive) to be sorted
 */
void Arrays_sortRangeL(int64_t *a, int32_t fromIndex, int32_t toIndex) {
    _sortPointer(a, fromIndex, toIndex, sizeof(int64_t), _compareL, false);
}

/**
 * Sorts the specified array of structures into ascending order, according to
 * the natural ordering of its elements.
 *
 * @param a the array to be sorted
 * @param length The array length
 * @param c The structure compare function
 */
void Arrays_sortObj(void **a, int32_t length, int32_t (*c)(const void *, const void *)) {
    _sortPointer(a, 0, length, sizeof(void *), c, true);
}

/**
 * Sorts the specified range of the specified array of structures into
 * ascending order, according to the natural ordering of its elements.
 *
 * @param a the array to be sorted
 * @param fromIndex the index of the first element (inclusive) to be sorted
 * @param toIndex the index of the last element (exclusive) to be sorted
 * @param c The structure compare function
 */
void Arrays_sortRangeObj(void **a, int32_t fromIndex, int32_t toIndex, int32_t (*c)(const void *, const void *)) {
    _sortPointer(a, fromIndex, toIndex, sizeof(void *), c, true);
}

/**
 * Sorts the specified array into ascending numerical order.
 *
 * @param a the array to be sorted
 * @param length The array length
 */
void Arrays_sortS(int16_t *a, int32_t length) {
    _sortPointer(a, 0, length, sizeof(int16_t), _compareS, false);
}

/**
 * Sorts the specified range of the array into ascending order.
 *
 * @param a the array to be sorted
 * @param fromIndex the index of the first element (inclusive) to be sorted
 * @param toIndex the index of the last element (exclusive) to be sorted
 */
void Arrays_sortRangeS(int16_t *a, int32_t fromIndex, int32_t toIndex) {
    _sortPointer(a, fromIndex, toIndex, sizeof(int16_t), _compareS, false);
}

/**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @param length The array length
 * @return a string representation of a
 */
String *Arrays_toStringBool(bool *a, int32_t length) {
    return _toStringPointer(a, length, sizeof(bool), _toStringBool, false);
}

/**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @param length The array length
 * @return a string representation of a
 */
String *Arrays_toStringB(int8_t *a, int32_t length) {
    return _toStringPointer(a, length, sizeof(int8_t), _toStringB, false);
}

/**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @param length The array length
 * @return a string representation of a
 */
String *Arrays_toStringC(char *a, int32_t length) {
    return _toStringPointer(a, length, sizeof(char), _toStringC, false);
}

/**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @param length The array length
 * @return a string representation of a
 */
String *Arrays_toStringD(double *a, int32_t length) {
    return _toStringPointer(a, length, sizeof(double), _toStringD, false);
}

/**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @param length The array length
 * @return a string representation of a
 */
String *Arrays_toStringF(float *a, int32_t length) {
    return _toStringPointer(a, length, sizeof(float), _toStringF, false);
}

/**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @param length The array length
 * @return a string representation of a
 */
String *Arrays_toStringI(int32_t *a, int32_t length) {
    return _toStringPointer(a, length, sizeof(int32_t), _toStringI, false);
}

/**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @param length The array length
 * @return a string representation of a
 */
String *Arrays_toStringL(int64_t *a, int32_t length) {
    return _toStringPointer(a, length, sizeof(int64_t), _toStringL, false);
}

/**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @param length The array length
 * @param toString The structure toString function
 * @return a string representation of a
 */
String *Arrays_toStringObj(void **a, int32_t length, String *(*toString)(const void *)) {
    return _toStringPointer(a, length, sizeof(void *), toString, true);
}

/**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @param length The array length
 * @return a string representation of a
 */
String *Arrays_toStringS(int16_t *a, int32_t length) {
    return _toStringPointer(a, length, sizeof(int16_t), _toStringS, false);
}
