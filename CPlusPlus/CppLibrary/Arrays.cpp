#include "Arrays.h"

#include "Boolean.h"
#include "Byte.h"
#include "Character.h"
#include "Double.h"
#include "Float.h"
#include "Integer.h"
#include "Long.h"
#include "Short.h"

bool Arrays::defaultBool = false;
int8_t Arrays::defaultByte = 0;
char Arrays::defaultChar = '\0';
double Arrays::defaultDouble = 0.0;
float Arrays::defaultFloat = 0.0f;
int32_t Arrays::defaultInt = 0;
int64_t Arrays::defaultLong = 0LL;
Object *Arrays::defaultPointer = 0;
int16_t Arrays::defaultShort = 0;
void *Arrays::currentComparator = nullptr;

/*
 * methods for testing if the two specified values are equal:
 */

bool Arrays::equalsBool(bool a, bool b) {
    Boolean x(a);
    Boolean y(b);

    return (&x)->equals(&y);
}

bool Arrays::equalsB(int8_t a, int8_t b) {
    Byte x(a);
    Byte y(b);

    return (&x)->equals(&y);
}

bool Arrays::equalsC(char a, char b) {
    Character x(a);
    Character y(b);

    return (&x)->equals(&y);
}

bool Arrays::equalsD(double a, double b) {
    Double x(a);
    Double y(b);

    return (&x)->equals(&y);
}

bool Arrays::equalsF(float a, float b) {
    Float x(a);
    Float y(b);

    return (&x)->equals(&y);
}

bool Arrays::equalsI(int32_t a, int32_t b) {
    Integer x(a);
    Integer y(b);

    return (&x)->equals(&y);
}

bool Arrays::equalsL(int64_t a, int64_t b) {
    Long x(a);
    Long y(b);

    return (&x)->equals(&y);
}

bool Arrays::equalsS(int16_t a, int16_t b) {
    Short x(a);
    Short y(b);

    return (&x)->equals(&y);
}

bool Arrays::equalsObj(Object *a, Object *b) {
    return a->equals(b);
}

/*
 * method for returning the string representation of the specified object:
 */
String *Arrays::toStringObj(Object *a) {
    return a->toString();
}

/*
 * methods for comparing the two specified values:
 */

bool Arrays::compareB(int8_t a, int8_t b) {
    return compareBI(a, b) < 0;
}

bool Arrays::compareC(char a, char b) {
    return compareCI(a, b) < 0;
}

bool Arrays::compareD(double a, double b) {
    return compareDI(a, b) < 0;
}

bool Arrays::compareF(float a, float b) {
    return compareFI(a, b) < 0;
}

bool Arrays::compareI(int32_t a, int32_t b) {
    return compareII(a, b) < 0;
}

bool Arrays::compareL(int64_t a, int64_t b) {
    return compareLI(a, b) < 0;
}

bool Arrays::compareS(int16_t a, int16_t b) {
    return compareSI(a, b) < 0;
}

bool Arrays::compareObj(Object *a, Object *b) {
    return compareObjI(a, b) < 0;
}

bool Arrays::compareObjComp(Object *a, Object *b) {
    return compareObjCompI(a, b) < 0;
}

int32_t Arrays::compareBI(int8_t a, int8_t b) {
    return Byte::compare(a, b);
}

int32_t Arrays::compareCI(char a, char b) {
    return Character::compare(a, b);
}

int32_t Arrays::compareDI(double a, double b) {
    return Double::compare(a, b);
}

int32_t Arrays::compareFI(float a, float b) {
    return Float::compare(a, b);
}

int32_t Arrays::compareII(int32_t a, int32_t b) {
    return Integer::compare(a, b);
}

int32_t Arrays::compareLI(int64_t a, int64_t b) {
    return Long::compare(a, b);
}

int32_t Arrays::compareSI(int16_t a, int16_t b) {
    return Short::compare(a, b);
}

int32_t Arrays::compareObjI(Object *a, Object *b) {
    Comparable *x = (Comparable *) a;
    Comparable *y = (Comparable *) b;
    
    return x->compareTo(y);
}

int32_t Arrays::compareObjCompI(Object *a, Object *b) {
    return ((Comparator *) currentComparator)->compare(a, b);
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
int32_t Arrays::binarySearch(int8_t *a, int32_t length, int8_t key) {
    return binarySearchGeneric(a, 0, length, key, compareBI);
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
int32_t Arrays::binarySearch(int8_t *a, int32_t fromIndex, int32_t toIndex, int8_t key) {
    return binarySearchGeneric(a, fromIndex, toIndex, key, compareBI);
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
int32_t Arrays::binarySearch(char *a, int32_t length, char key) {
    return binarySearchGeneric(a, 0, length, key, compareCI);
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
int32_t Arrays::binarySearch(char *a, int32_t fromIndex, int32_t toIndex, char key) {
    return binarySearchGeneric(a, fromIndex, toIndex, key, compareCI);
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
int32_t Arrays::binarySearch(double *a, int32_t length, double key) {
    return binarySearchGeneric(a, 0, length, key, compareDI);
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
int32_t Arrays::binarySearch(double *a, int32_t fromIndex, int32_t toIndex, double key) {
    return binarySearchGeneric(a, fromIndex, toIndex, key, compareDI);
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
int32_t Arrays::binarySearch(float *a, int32_t length, float key) {
    return binarySearchGeneric(a, 0, length, key, compareFI);
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
int32_t Arrays::binarySearch(float *a, int32_t fromIndex, int32_t toIndex, float key) {
    return binarySearchGeneric(a, fromIndex, toIndex, key, compareFI);
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
int32_t Arrays::binarySearch(int32_t *a, int32_t length, int32_t key) {
    return binarySearchGeneric(a, 0, length, key, compareII);
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
int32_t Arrays::binarySearch(int32_t *a, int32_t fromIndex, int32_t toIndex, int32_t key) {
    return binarySearchGeneric(a, fromIndex, toIndex, key, compareII);
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
int32_t Arrays::binarySearch(int64_t *a, int32_t length, int64_t key) {
    return binarySearchGeneric(a, 0, length, key, compareLI);
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
int32_t Arrays::binarySearch(int64_t *a, int32_t fromIndex, int32_t toIndex, int64_t key) {
    return binarySearchGeneric(a, fromIndex, toIndex, key, compareLI);
}

/**
 * Searches the specified array for the specified object using the binary
 * search algorithm.
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
int32_t Arrays::binarySearch(Object **a, int32_t length, Object *key) {
    return binarySearchGeneric(a, 0, length, key, compareObjI);
}

/**
 * Searches a range of the specified array for the specified object using
 * the binary search algorithm.
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
int32_t Arrays::binarySearch(Object **a, int32_t fromIndex, int32_t toIndex, Object *key) {
    return binarySearchGeneric(a, fromIndex, toIndex, key, compareObjI);
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
int32_t Arrays::binarySearch(int16_t *a, int32_t length, int16_t key) {
    return binarySearchGeneric(a, 0, length, key, compareSI);
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
int32_t Arrays::binarySearch(int16_t *a, int32_t fromIndex, int32_t toIndex, int16_t key) {
    return binarySearchGeneric(a, fromIndex, toIndex, key, compareSI);
}

/**
 * Searches the specified array for the specified object using the binary
 * search algorithm.
 *
 * @param a the array to be searched
 * @param length The array length
 * @param key the value to be searched for
 * @param c the comparator by which the array is ordered. A null value
 * indicates that the elements' natural ordering should be used.
 * @return index of the search key, if it is contained in the array;
 * otherwise, (-(insertion point) - 1). The insertion point is defined as
 * the point at which the key would be inserted into the array: the index of
 * the first element greater than the key, or a.length if all elements in
 * the array are less than the specified key. Note that this guarantees that
 * the return value will be >= 0 if and only if the key is found.
 */
int32_t Arrays::binarySearch(Object **a, int32_t length, Object *key, Comparator *c) {
    // setting the comparator used by the specified comparison function
    currentComparator = c;
    return binarySearchGeneric(a, 0, length, key, compareObjCompI);
}

/**
 * Searches a range of the specified array for the specified object using
 * the binary search algorithm.
 *
 * @param a the array to be searched
 * @param fromIndex the index of the first element (inclusive) to be
 * searched
 * @param toIndex the index of the last element (exclusive) to be searched
 * @param key the value to be searched for
 * @param c the comparator by which the array is ordered. A null value
 * indicates that the elements' natural ordering should be used.
 * @return index of the search key, if it is contained in the array within
 * the specified range; otherwise, (-(insertion point) - 1). The insertion
 * point is defined as the point at which the key would be inserted into the
 * array: the index of the first element in the range greater than the key,
 * or toIndex if all elements in the range are less than the specified key.
 * Note that this guarantees that the return value will be >= 0 if and only
 * if the key is found.
 */
int32_t Arrays::binarySearch(Object **a, int32_t fromIndex, int32_t toIndex, Object *key, Comparator *c) {
    // setting the comparator used by the specified comparison function
    currentComparator = c;
    return binarySearchGeneric(a, fromIndex, toIndex, key, compareObjCompI);
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
bool *Arrays::copyOf(bool *original, int32_t length, int32_t newLength) {
    return copyOfRangeGeneric(original, length, 0, newLength, defaultBool);
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
int8_t *Arrays::copyOf(int8_t *original, int32_t length, int32_t newLength) {
    return copyOfRangeGeneric(original, length, 0, newLength, defaultByte);
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
char *Arrays::copyOf(char *original, int32_t length, int32_t newLength) {
    return copyOfRangeGeneric(original, length, 0, newLength, defaultChar);
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
double *Arrays::copyOf(double *original, int32_t length, int32_t newLength) {
    return copyOfRangeGeneric(original, length, 0, newLength, defaultDouble);
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
float *Arrays::copyOf(float *original, int32_t length, int32_t newLength) {
    return copyOfRangeGeneric(original, length, 0, newLength, defaultFloat);
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
int32_t *Arrays::copyOf(int32_t *original, int32_t length, int32_t newLength) {
    return copyOfRangeGeneric(original, length, 0, newLength, defaultInt);
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
int64_t *Arrays::copyOf(int64_t *original, int32_t length, int32_t newLength) {
    return copyOfRangeGeneric(original, length, 0, newLength, defaultLong);
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
Object **Arrays::copyOf(Object **original, int32_t length, int32_t newLength) {
    return copyOfRangeGeneric(original, length, 0, newLength, defaultPointer);
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
int16_t *Arrays::copyOf(int16_t *original, int32_t length, int32_t newLength) {
    return copyOfRangeGeneric(original, length, 0, newLength, defaultShort);
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
bool *Arrays::copyOfRange(bool *original, int32_t length, int32_t from, int32_t to) {
    return copyOfRangeGeneric(original, length, from, to, defaultBool);
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
int8_t *Arrays::copyOfRange(int8_t *original, int32_t length, int32_t from, int32_t to) {
    return copyOfRangeGeneric(original, length, from, to, defaultByte);
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
char *Arrays::copyOfRange(char *original, int32_t length, int32_t from, int32_t to) {
    return copyOfRangeGeneric(original, length, from, to, defaultChar);
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
double *Arrays::copyOfRange(double *original, int32_t length, int32_t from, int32_t to) {
    return copyOfRangeGeneric(original, length, from, to, defaultDouble);
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
float *Arrays::copyOfRange(float *original, int32_t length, int32_t from, int32_t to) {
    return copyOfRangeGeneric(original, length, from, to, defaultFloat);
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
int32_t *Arrays::copyOfRange(int32_t *original, int32_t length, int32_t from, int32_t to) {
    return copyOfRangeGeneric(original, length, from, to, defaultInt);
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
int64_t *Arrays::copyOfRange(int64_t *original, int32_t length, int32_t from, int32_t to) {
    return copyOfRangeGeneric(original, length, from, to, defaultLong);
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
Object **Arrays::copyOfRange(Object **original, int32_t length, int32_t from, int32_t to) {
    return copyOfRangeGeneric(original, length, from, to, defaultPointer);
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
int16_t *Arrays::copyOfRange(int16_t *original, int32_t length, int32_t from, int32_t to) {
    return copyOfRangeGeneric(original, length, from, to, defaultShort);
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
bool Arrays::equals(bool *a, int32_t length, bool *a2, int32_t length2) {
    return equalsGeneric(a, length, a2, length2, equalsBool, false);
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
bool Arrays::equals(int8_t *a, int32_t length, int8_t *a2, int32_t length2) {
    return equalsGeneric(a, length, a2, length2, equalsB, false);
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
bool Arrays::equals(char *a, int32_t length, char *a2, int32_t length2) {
    return equalsGeneric(a, length, a2, length2, equalsC, false);
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
bool Arrays::equals(double *a, int32_t length, double *a2, int32_t length2) {
    return equalsGeneric(a, length, a2, length2, equalsD, false);
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
bool Arrays::equals(float *a, int32_t length, float *a2, int32_t length2) {
    return equalsGeneric(a, length, a2, length2, equalsF, false);
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
bool Arrays::equals(int32_t *a, int32_t length, int32_t *a2, int32_t length2) {
    return equalsGeneric(a, length, a2, length2, equalsI, false);
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
bool Arrays::equals(int64_t *a, int32_t length, int64_t *a2, int32_t length2) {
    return equalsGeneric(a, length, a2, length2, equalsL, false);
}

/**
 * Returns true if the two specified arrays of Objects are equal to one
 * another.
 *
 * @param a one array to be tested for equality
 * @param length The array length
 * @param a2 the other array to be tested for equality
 * @param length2 The other array length
 * @return true if the two arrays are equal
 */
bool Arrays::equals(Object **a, int32_t length, Object **a2, int32_t length2) {
    return equalsGeneric(a, length, a2, length2, equalsObj, true);
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
bool Arrays::equals(int16_t *a, int32_t length, int16_t *a2, int32_t length2) {
    return equalsGeneric(a, length, a2, length2, equalsS, false);
}

/**
 * Assigns the specified boolean value to each element of the specified
 * array of booleans.
 *
 * @param a the array to be filled
 * @param length The array length
 * @param val the value to be stored in all elements of the array
 */
void Arrays::fill(bool *a, int32_t length, bool val) {
    fillGeneric(a, 0, length, val);
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
void Arrays::fill(bool *a, int32_t fromIndex, int32_t toIndex, bool val) {
    fillGeneric(a, fromIndex, toIndex, val);
}

/**
 * Assigns the specified byte value to each element of the specified array
 * of bytes.
 *
 * @param a the array to be filled
 * @param length The array length
 * @param val the value to be stored in all elements of the array
 */
void Arrays::fill(int8_t *a, int32_t length, int8_t val) {
    fillGeneric(a, 0, length, val);
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
void Arrays::fill(int8_t *a, int32_t fromIndex, int32_t toIndex, int8_t val) {
    fillGeneric(a, fromIndex, toIndex, val);
}

/**
 * Assigns the specified char value to each element of the specified array
 * of chars.
 *
 * @param a the array to be filled
 * @param length The array length
 * @param val the value to be stored in all elements of the array
 */
void Arrays::fill(char *a, int32_t length, char val) {
    fillGeneric(a, 0, length, val);
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
void Arrays::fill(char *a, int32_t fromIndex, int32_t toIndex, char val) {
    fillGeneric(a, fromIndex, toIndex, val);
}

/**
 * Assigns the specified double value to each element of the specified array
 * of doubles.
 *
 * @param a the array to be filled
 * @param length The array length
 * @param val the value to be stored in all elements of the array
 */
void Arrays::fill(double *a, int32_t length, double val) {
    fillGeneric(a, 0, length, val);
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
void Arrays::fill(double *a, int32_t fromIndex, int32_t toIndex, double val) {
    fillGeneric(a, fromIndex, toIndex, val);
}

/**
 * Assigns the specified float value to each element of the specified array
 * of floats.
 *
 * @param a the array to be filled
 * @param length The array length
 * @param val the value to be stored in all elements of the array
 */
void Arrays::fill(float *a, int32_t length, float val) {
    fillGeneric(a, 0, length, val);
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
void Arrays::fill(float *a, int32_t fromIndex, int32_t toIndex, float val) {
    fillGeneric(a, fromIndex, toIndex, val);
}

/**
 * Assigns the specified int value to each element of the specified array of
 * ints.
 *
 * @param a the array to be filled
 * @param length The array length
 * @param val the value to be stored in all elements of the array
 */
void Arrays::fill(int32_t *a, int32_t length, int32_t val) {
    fillGeneric(a, 0, length, val);
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
void Arrays::fill(int32_t *a, int32_t fromIndex, int32_t toIndex, int32_t val) {
    fillGeneric(a, fromIndex, toIndex, val);
}

/**
 * Assigns the specified long value to each element of the specified array
 * of longs.
 *
 * @param a the array to be filled
 * @param length The array length
 * @param val the value to be stored in all elements of the array
 */
void Arrays::fill(int64_t *a, int32_t length, int64_t val) {
    fillGeneric(a, 0, length, val);
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
void Arrays::fill(int64_t *a, int32_t fromIndex, int32_t toIndex, int64_t val) {
    fillGeneric(a, fromIndex, toIndex, val);
}

/**
 * Assigns the specified Object pointer to each element of the specified
 * array of Objects.
 *
 * @param a the array to be filled
 * @param length The array length
 * @param val the value to be stored in all elements of the array
 */
void Arrays::fill(Object **a, int32_t length, Object *val) {
    fillGeneric(a, 0, length, val);
}

/**
 * Assigns the specified Object pointer to each element of the specified
 * range of the specified array of Objects.
 *
 * @param a the array to be filled
 * @param fromIndex the index of the first element (inclusive) to be filled
 * with the specified value
 * @param toIndex the index of the last element (exclusive) to be filled
 * with the specified value
 * @param val the value to be stored in all elements of the array
 */
void Arrays::fill(Object **a, int32_t fromIndex, int32_t toIndex, Object *val) {
    fillGeneric(a, fromIndex, toIndex, val);
}

/**
 * Assigns the specified short value to each element of the specified array
 * of shorts.
 *
 * @param a the array to be filled
 * @param length The array length
 * @param val the value to be stored in all elements of the array
 */
void Arrays::fill(int16_t *a, int32_t length, int16_t val) {
    fillGeneric(a, 0, length, val);
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
void Arrays::fill(int16_t *a, int32_t fromIndex, int32_t toIndex, int16_t val) {
    fillGeneric(a, fromIndex, toIndex, val);
}

/**
 * Sorts the specified array into ascending numerical order.
 *
 * @param a the array to be sorted
 * @param length The array length
 */
void Arrays::sort(int8_t *a, int32_t length) {
    sortGeneric(a, 0, length, compareB);
}

/**
 * Sorts the specified range of the array into ascending order.
 *
 * @param a the array to be sorted
 * @param fromIndex the index of the first element (inclusive) to be sorted
 * @param toIndex the index of the last element (exclusive) to be sorted
 */
void Arrays::sort(int8_t *a, int32_t fromIndex, int32_t toIndex) {
    sortGeneric(a, fromIndex, toIndex, compareB);
}

/**
 * Sorts the specified array into ascending numerical order.
 *
 * @param a the array to be sorted
 * @param length The array length
 */
void Arrays::sort(char *a, int32_t length) {
    sortGeneric(a, 0, length, compareC);
}

/**
 * Sorts the specified range of the array into ascending order.
 *
 * @param a the array to be sorted
 * @param fromIndex the index of the first element (inclusive) to be sorted
 * @param toIndex the index of the last element (exclusive) to be sorted
 */
void Arrays::sort(char *a, int32_t fromIndex, int32_t toIndex) {
    sortGeneric(a, fromIndex, toIndex, compareC);
}

/**
 * Sorts the specified array into ascending numerical order.
 *
 * @param a the array to be sorted
 * @param length The array length
 */
void Arrays::sort(double *a, int32_t length) {
    sortGeneric(a, 0, length, compareD);
}

/**
 * Sorts the specified range of the array into ascending order.
 *
 * @param a the array to be sorted
 * @param fromIndex the index of the first element (inclusive) to be sorted
 * @param toIndex the index of the last element (exclusive) to be sorted
 */
void Arrays::sort(double *a, int32_t fromIndex, int32_t toIndex) {
    sortGeneric(a, fromIndex, toIndex, compareD);
}

/**
 * Sorts the specified array into ascending numerical order.
 *
 * @param a the array to be sorted
 * @param length The array length
 */
void Arrays::sort(float *a, int32_t length) {
    sortGeneric(a, 0, length, compareF);
}

/**
 * Sorts the specified range of the array into ascending order.
 *
 * @param a the array to be sorted
 * @param fromIndex the index of the first element (inclusive) to be sorted
 * @param toIndex the index of the last element (exclusive) to be sorted
 */
void Arrays::sort(float *a, int32_t fromIndex, int32_t toIndex) {
    sortGeneric(a, fromIndex, toIndex, compareF);
}

/**
 * Sorts the specified array into ascending numerical order.
 *
 * @param a the array to be sorted
 * @param length The array length
 */
void Arrays::sort(int32_t *a, int32_t length) {
    sortGeneric(a, 0, length, compareI);
}

/**
 * Sorts the specified range of the array into ascending order.
 *
 * @param a the array to be sorted
 * @param fromIndex the index of the first element (inclusive) to be sorted
 * @param toIndex the index of the last element (exclusive) to be sorted
 */
void Arrays::sort(int32_t *a, int32_t fromIndex, int32_t toIndex) {
    sortGeneric(a, fromIndex, toIndex, compareI);
}

/**
 * Sorts the specified array into ascending numerical order.
 *
 * @param a the array to be sorted
 * @param length The array length
 */
void Arrays::sort(int64_t *a, int32_t length) {
    sortGeneric(a, 0, length, compareL);
}

/**
 * Sorts the specified range of the array into ascending order.
 *
 * @param a the array to be sorted
 * @param fromIndex the index of the first element (inclusive) to be sorted
 * @param toIndex the index of the last element (exclusive) to be sorted
 */
void Arrays::sort(int64_t *a, int32_t fromIndex, int32_t toIndex) {
    sortGeneric(a, fromIndex, toIndex, compareL);
}

/**
 * Sorts the specified array of objects into ascending order, according to
 * the natural ordering of its elements.
 *
 * @param a the array to be sorted
 * @param length The array length
 */
void Arrays::sort(Object **a, int32_t length) {
    sortGeneric(a, 0, length, compareObj);
}

/**
 * Sorts the specified range of the specified array of objects into
 * ascending order, according to the natural ordering of its elements.
 *
 * @param a the array to be sorted
 * @param fromIndex the index of the first element (inclusive) to be sorted
 * @param toIndex the index of the last element (exclusive) to be sorted
 */
void Arrays::sort(Object **a, int32_t fromIndex, int32_t toIndex) {
    sortGeneric(a, fromIndex, toIndex, compareObj);
}

/**
 * Sorts the specified array into ascending numerical order.
 *
 * @param a the array to be sorted
 * @param length The array length
 */
void Arrays::sort(int16_t *a, int32_t length) {
    sortGeneric(a, 0, length, compareS);
}

/**
 * Sorts the specified range of the array into ascending order.
 *
 * @param a the array to be sorted
 * @param fromIndex the index of the first element (inclusive) to be sorted
 * @param toIndex the index of the last element (exclusive) to be sorted
 */
void Arrays::sort(int16_t *a, int32_t fromIndex, int32_t toIndex) {
    sortGeneric(a, fromIndex, toIndex, compareS);
}

/**
 * Sorts the specified array of objects according to the order induced by
 * the specified comparator.
 *
 * @param a the array to be sorted
 * @param length The array length
 * @param c the comparator to determine the order of the array. A null value
 * indicates that the elements' natural ordering should be used.
 */
void Arrays::sort(Object **a, int32_t length, Comparator *c) {
    // setting the comparator used by the specified comparison function
    currentComparator = c;
    sortGeneric(a, 0, length, compareObjComp, true);
}

/**
 * Sorts the specified range of the specified array of objects according to
 * the order induced by the specified comparator.
 *
 * @param a the array to be sorted
 * @param fromIndex the index of the first element (inclusive) to be sorted
 * @param toIndex the index of the last element (exclusive) to be sorted
 * @param c the comparator to determine the order of the array. A null value
 * indicates that the elements' natural ordering should be used.
 */
void Arrays::sort(Object **a, int32_t fromIndex, int32_t toIndex, Comparator *c) {
    // setting the comparator used by the specified comparison function
    currentComparator = c;
    sortGeneric(a, fromIndex, toIndex, compareObjComp, true);
}

/**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @param length The array length
 * @return a string representation of a
 */
String *Arrays::toString(bool *a, int32_t length) {
    return toStringGeneric(a, length, Boolean::toString, false);
}

/**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @param length The array length
 * @return a string representation of a
 */
String *Arrays::toString(int8_t *a, int32_t length) {
    return toStringGeneric(a, length, Byte::toString, false);
}

/**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @param length The array length
 * @return a string representation of a
 */
String *Arrays::toString(char *a, int32_t length) {
    return toStringGeneric(a, length, Character::toString, false);
}

/**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @param length The array length
 * @return a string representation of a
 */
String *Arrays::toString(double *a, int32_t length) {
    return toStringGeneric(a, length, Double::toString, false);
}

/**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @param length The array length
 * @return a string representation of a
 */
String *Arrays::toString(float *a, int32_t length) {
    return toStringGeneric(a, length, Float::toString, false);
}

/**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @param length The array length
 * @return a string representation of a
 */
String *Arrays::toString(int32_t *a, int32_t length) {
    return toStringGeneric(a, length, Integer::toString, false);
}

/**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @param length The array length
 * @return a string representation of a
 */
String *Arrays::toString(int64_t *a, int32_t length) {
    return toStringGeneric(a, length, Long::toString, false);
}

/**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @param length The array length
 * @return a string representation of a
 */
String *Arrays::toString(Object **a, int32_t length) {
    return toStringGeneric(a, length, toStringObj, true);
}

/**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @param length The array length
 * @return a string representation of a
 */
String *Arrays::toString(int16_t *a, int32_t length) {
    return toStringGeneric(a, length, Short::toString, false);
}
