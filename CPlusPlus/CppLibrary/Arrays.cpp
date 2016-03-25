#include "Arrays.h"

#include "Boolean.h"
#include "Byte.h"
#include "Character.h"
#include "Double.h"
#include "Float.h"
#include "Integer.h"
#include "Long.h"
#include "Short.h"

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

int32_t Arrays::compareObj(Object *a, Object *b) {
    Comparable<Object> *x = (Comparable<Object> *) a;
    Comparable<Object> *y = (Comparable<Object> *) b;
    
    return x->compareTo(y);
}

bool Arrays::equalsObj(Object *a, Object *b) {
    return a->equals(b);
}

String *Arrays::toStringObj(Object *a) {
    return a->toString();
}

/**
 * Searches the specified array of bytes for the specified value using the
 * binary search algorithm
 *
 * @param a the array to be searched
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array;
 * otherwise, (-(insertion point) - 1). The insertion point is defined as
 * the point at which the key would be inserted into the array: the index of
 * the first element greater than the key, or a.length if all elements in
 * the array are less than the specified key. Note that this guarantees that
 * the return value will be >= 0 if and only if the key is found.
 */
int32_t Arrays::binarySearch(int8_t *a, int32_t length, int8_t key) {
    return binarySearchGeneric(a, 0, length, key, Byte::compare);
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
    return binarySearchGeneric(a, fromIndex, toIndex, key, Byte::compare);
}

/**
 * Searches the specified array of chars for the specified value using the
 * binary search algorithm.
 *
 * @param a the array to be searched
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array;
 * otherwise, (-(insertion point) - 1). The insertion point is defined as
 * the point at which the key would be inserted into the array: the index of
 * the first element greater than the key, or a.length if all elements in
 * the array are less than the specified key. Note that this guarantees that
 * the return value will be >= 0 if and only if the key is found.
 */
int32_t Arrays::binarySearch(char *a, int32_t length, char key) {
    return binarySearchGeneric(a, 0, length, key, Character::compare);
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
    return binarySearchGeneric(a, fromIndex, toIndex, key, Character::compare);
}

/**
 * Searches the specified array of doubles for the specified value using the
 * binary search algorithm.
 *
 * @param a the array to be searched
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array;
 * otherwise, (-(insertion point) - 1). The insertion point is defined as
 * the point at which the key would be inserted into the array: the index of
 * the first element greater than the key, or a.length if all elements in
 * the array are less than the specified key. Note that this guarantees that
 * the return value will be >= 0 if and only if the key is found.
 */
int32_t Arrays::binarySearch(double *a, int32_t length, double key) {
    return binarySearchGeneric(a, 0, length, key, Double::compare);
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
    return binarySearchGeneric(a, fromIndex, toIndex, key, Double::compare);
}

/**
 * Searches the specified array of floats for the specified value using the
 * binary search algorithm.
 *
 * @param a the array to be searched
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array;
 * otherwise, (-(insertion point) - 1). The insertion point is defined as
 * the point at which the key would be inserted into the array: the index of
 * the first element greater than the key, or a.length if all elements in
 * the array are less than the specified key. Note that this guarantees that
 * the return value will be >= 0 if and only if the key is found.
 */
int32_t Arrays::binarySearch(float *a, int32_t length, float key) {
    return binarySearchGeneric(a, 0, length, key, Float::compare);
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
    return binarySearchGeneric(a, fromIndex, toIndex, key, Float::compare);
}

/**
 * Searches the specified array of ints for the specified value using the
 * binary search algorithm.
 *
 * @param a the array to be searched
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array;
 * otherwise, (-(insertion point) - 1). The insertion point is defined as
 * the point at which the key would be inserted into the array: the index of
 * the first element greater than the key, or a.length if all elements in
 * the array are less than the specified key. Note that this guarantees that
 * the return value will be >= 0 if and only if the key is found.
 */
int32_t Arrays::binarySearch(int32_t *a, int32_t length, int32_t key) {
    return binarySearchGeneric(a, 0, length, key, Integer::compare);
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
    return binarySearchGeneric(a, fromIndex, toIndex, key, Integer::compare);
}

/**
 * Searches the specified array of longs for the specified value using the
 * binary search algorithm.
 *
 * @param a the array to be searched
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array;
 * otherwise, (-(insertion point) - 1). The insertion point is defined as
 * the point at which the key would be inserted into the array: the index of
 * the first element greater than the key, or a.length if all elements in
 * the array are less than the specified key. Note that this guarantees that
 * the return value will be >= 0 if and only if the key is found.
 */
int32_t Arrays::binarySearch(int64_t *a, int32_t length, int64_t key) {
    return binarySearchGeneric(a, 0, length, key, Long::compare);
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
    return binarySearchGeneric(a, fromIndex, toIndex, key, Long::compare);
}

/**
 * Searches the specified array for the specified object using the binary
 * search algorithm.
 *
 * @param a the array to be searched
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array;
 * otherwise, (-(insertion point) - 1). The insertion point is defined as
 * the point at which the key would be inserted into the array: the index of
 * the first element greater than the key, or a.length if all elements in
 * the array are less than the specified key. Note that this guarantees that
 * the return value will be >= 0 if and only if the key is found.
 */
int32_t Arrays::binarySearch(Object **a, int32_t length, Object *key) {
    return binarySearchGeneric(a, 0, length, key, compareObj);
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
    return binarySearchGeneric(a, fromIndex, toIndex, key, compareObj);
}

/**
 * Searches the specified array of shorts for the specified value using the
 * binary search algorithm.
 *
 * @param a the array to be searched
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array;
 * otherwise, (-(insertion point) - 1). The insertion point is defined as
 * the point at which the key would be inserted into the array: the index of
 * the first element greater than the key, or a.length if all elements in
 * the array are less than the specified key. Note that this guarantees that
 * the return value will be >= 0 if and only if the key is found.
 */
int32_t Arrays::binarySearch(int16_t *a, int32_t length, int16_t key) {
    return binarySearchGeneric(a, 0, length, key, Short::compare);
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
    return binarySearchGeneric(a, fromIndex, toIndex, key, Short::compare);
}

/**
 * Copies the specified array, truncating or padding with false (if
 * necessary) so the copy has the specified length.
 *
 * @param original the array to be copied
 * @param newLength the length of the copy to be returned
 * @return a copy of the original array, truncated or padded with false
 * elements to obtain the specified length
 */
bool *Arrays::copyOf(bool *original, int32_t length, int32_t newLength) {
    return copyOfRangeGeneric(original, length, 0, newLength);
}

/**
 * Copies the specified array, truncating or padding with zeros (if
 * necessary) so the copy has the specified length.
 *
 * @param original the array to be copied
 * @param newLength the length of the copy to be returned
 * @return a copy of the original array, truncated or padded with zeros to
 * obtain the specified length
 */
int8_t *Arrays::copyOf(int8_t *original, int32_t length, int32_t newLength) {
    return copyOfRangeGeneric(original, length, 0, newLength);
}

/**
 * Copies the specified array, truncating or padding with null characters
 * (if necessary) so the copy has the specified length.
 *
 * @param original the array to be copied
 * @param newLength the length of the copy to be returned
 * @return a copy of the original array, truncated or padded with null
 * characters to obtain the specified length
 */
char *Arrays::copyOf(char *original, int32_t length, int32_t newLength) {
    return copyOfRangeGeneric(original, length, 0, newLength);
}

/**
 * Copies the specified array, truncating or padding with zeros (if
 * necessary) so the copy has the specified length.
 *
 * @param original the array to be copied
 * @param newLength the length of the copy to be returned
 * @return a copy of the original array, truncated or padded with zeros to
 * obtain the specified length
 */
double *Arrays::copyOf(double *original, int32_t length, int32_t newLength) {
    return copyOfRangeGeneric(original, length, 0, newLength);
}

/**
 * Copies the specified array, truncating or padding with zeros (if
 * necessary) so the copy has the specified length.
 *
 * @param original the array to be copied
 * @param newLength the length of the copy to be returned
 * @return a copy of the original array, truncated or padded with zeros to
 * obtain the specified length
 */
float *Arrays::copyOf(float *original, int32_t length, int32_t newLength) {
    return copyOfRangeGeneric(original, length, 0, newLength);
}

/**
 * Copies the specified array, truncating or padding with zeros (if
 * necessary) so the copy has the specified length.
 *
 * @param original the array to be copied
 * @param newLength the length of the copy to be returned
 * @return a copy of the original array, truncated or padded with zeros to
 * obtain the specified length
 */
int32_t *Arrays::copyOf(int32_t *original, int32_t length, int32_t newLength) {
    return copyOfRangeGeneric(original, length, 0, newLength);
}

/**
 * Copies the specified array, truncating or padding with zeros (if
 * necessary) so the copy has the specified length.
 *
 * @param original the array to be copied
 * @param newLength the length of the copy to be returned
 * @return a copy of the original array, truncated or padded with zeros to
 * obtain the specified length
 */
int64_t *Arrays::copyOf(int64_t *original, int32_t length, int32_t newLength) {
    return copyOfRangeGeneric(original, length, 0, newLength);
}

/**
 * Copies the specified array, truncating or padding with zeros (if
 * necessary) so the copy has the specified length.
 *
 * @param original the array to be copied
 * @param newLength the length of the copy to be returned
 * @return a copy of the original array, truncated or padded with zeros to
 * obtain the specified length
 */
int16_t *Arrays::copyOf(int16_t *original, int32_t length, int32_t newLength) {
    return copyOfRangeGeneric(original, length, 0, newLength);
}

/**
 * Copies the specified range of the specified array into a new array.
 *
 * @param original the array from which a range is to be copied
 * @param from the initial index of the range to be copied, inclusive
 * @param to the final index of the range to be copied, exclusive. (This
 * index may lie outside the array.)
 * @return a new array containing the specified range from the original
 * array, truncated or padded with false elements to obtain the required
 * length
 */
bool *Arrays::copyOfRange(bool *original, int32_t length, int32_t from, int32_t to) {
    return copyOfRangeGeneric(original, length, from, to);
}

/**
 * Copies the specified range of the specified array into a new array.
 *
 * @param original the array from which a range is to be copied
 * @param from the initial index of the range to be copied, inclusive
 * @param to the final index of the range to be copied, exclusive. (This
 * index may lie outside the array.)
 * @return a new array containing the specified range from the original
 * array, truncated or padded with zeros to obtain the required length
 */
int8_t *Arrays::copyOfRange(int8_t *original, int32_t length, int32_t from, int32_t to) {
    return copyOfRangeGeneric(original, length, from, to);
}

/**
 * Copies the specified range of the specified array into a new array.
 *
 * @param original the array from which a range is to be copied
 * @param from the initial index of the range to be copied, inclusive
 * @param to the final index of the range to be copied, exclusive. (This
 * index may lie outside the array.)
 * @return a new array containing the specified range from the original
 * array, truncated or padded with null characters to obtain the required
 * length
 */
char *Arrays::copyOfRange(char *original, int32_t length, int32_t from, int32_t to) {
    return copyOfRangeGeneric(original, length, from, to);
}

/**
 * Copies the specified range of the specified array into a new array.
 *
 * @param original the array from which a range is to be copied
 * @param from the initial index of the range to be copied, inclusive
 * @param to the final index of the range to be copied, exclusive. (This
 * index may lie outside the array.)
 * @return a new array containing the specified range from the original
 * array, truncated or padded with zeros to obtain the required length
 */
double *Arrays::copyOfRange(double *original, int32_t length, int32_t from, int32_t to) {
    return copyOfRangeGeneric(original, length, from, to);
}

/**
 * Copies the specified range of the specified array into a new array.
 *
 * @param original the array from which a range is to be copied
 * @param from the initial index of the range to be copied, inclusive
 * @param to the final index of the range to be copied, exclusive. (This
 * index may lie outside the array.)
 * @return a new array containing the specified range from the original
 * array, truncated or padded with zeros to obtain the required length
 */
float *Arrays::copyOfRange(float *original, int32_t length, int32_t from, int32_t to) {
    return copyOfRangeGeneric(original, length, from, to);
}

/**
 * Copies the specified range of the specified array into a new array.
 *
 * @param original the array from which a range is to be copied
 * @param from the initial index of the range to be copied, inclusive
 * @param to the final index of the range to be copied, exclusive. (This
 * index may lie outside the array.)
 * @return a new array containing the specified range from the original
 * array, truncated or padded with zeros to obtain the required length
 */
int32_t *Arrays::copyOfRange(int32_t *original, int32_t length, int32_t from, int32_t to) {
    return copyOfRangeGeneric(original, length, from, to);
}

/**
 * Copies the specified range of the specified array into a new array.
 *
 * @param original the array from which a range is to be copied
 * @param from the initial index of the range to be copied, inclusive
 * @param to the final index of the range to be copied, exclusive. (This
 * index may lie outside the array.)
 * @return a new array containing the specified range from the original
 * array, truncated or padded with zeros to obtain the required length
 */
int64_t *Arrays::copyOfRange(int64_t *original, int32_t length, int32_t from, int32_t to) {
    return copyOfRangeGeneric(original, length, from, to);
}

/**
 * Copies the specified range of the specified array into a new array.
 *
 * @param original the array from which a range is to be copied
 * @param from the initial index of the range to be copied, inclusive
 * @param to the final index of the range to be copied, exclusive. (This
 * index may lie outside the array.)
 * @return a new array containing the specified range from the original
 * array, truncated or padded with zeros to obtain the required length
 */
int16_t *Arrays::copyOfRange(int16_t *original, int32_t length, int32_t from, int32_t to) {
    return copyOfRangeGeneric(original, length, from, to);
}

/**
 * Returns true if the two specified arrays of booleans are equal to one
 * another.
 *
 * @param a one array to be tested for equality
 * @param a2 the other array to be tested for equality
 * @return true if the two arrays are equal
 */
bool Arrays::equals(bool *a, int32_t length, bool *a2, int32_t length2) {
    return equalsGeneric(a, length, a2, length2, equalsBool);
}

/**
 * Returns true if the two specified arrays of bytes are equal to one
 * another.
 *
 * @param a one array to be tested for equality
 * @param a2 the other array to be tested for equality
 * @return true if the two arrays are equal
 */
bool Arrays::equals(int8_t *a, int32_t length, int8_t *a2, int32_t length2) {
    return equalsGeneric(a, length, a2, length2, equalsB);
}

/**
 * Returns true if the two specified arrays of chars are equal to one
 * another.
 *
 * @param a one array to be tested for equality
 * @param a2 the other array to be tested for equality
 * @return true if the two arrays are equal
 */
bool Arrays::equals(char *a, int32_t length, char *a2, int32_t length2) {
    return equalsGeneric(a, length, a2, length2, equalsC);
}

/**
 * Returns true if the two specified arrays of doubles are equal to one
 * another.
 *
 * @param a one array to be tested for equality
 * @param a2 the other array to be tested for equality
 * @return true if the two arrays are equal
 */
bool Arrays::equals(double *a, int32_t length, double *a2, int32_t length2) {
    return equalsGeneric(a, length, a2, length2, equalsD);
}

/**
 * Returns true if the two specified arrays of floats are equal to one
 * another.
 *
 * @param a one array to be tested for equality
 * @param a2 the other array to be tested for equality
 * @return true if the two arrays are equal
 */
bool Arrays::equals(float *a, int32_t length, float *a2, int32_t length2) {
    return equalsGeneric(a, length, a2, length2, equalsF);
}

/**
 * Returns true if the two specified arrays of ints are equal to one
 * another.
 *
 * @param a one array to be tested for equality
 * @param a2 the other array to be tested for equality
 * @return true if the two arrays are equal
 */
bool Arrays::equals(int32_t *a, int32_t length, int32_t *a2, int32_t length2) {
    return equalsGeneric(a, length, a2, length2, equalsI);
}

/**
 * Returns true if the two specified arrays of longs are equal to one
 * another.
 *
 * @param a one array to be tested for equality
 * @param a2 the other array to be tested for equality
 * @return true if the two arrays are equal
 */
bool Arrays::equals(int64_t *a, int32_t length, int64_t *a2, int32_t length2) {
    return equalsGeneric(a, length, a2, length2, equalsL);
}

/**
 * Returns true if the two specified arrays of Objects are equal to one
 * another.
 *
 * @param a one array to be tested for equality
 * @param a2 the other array to be tested for equality
 * @return true if the two arrays are equal
 */
bool Arrays::equals(Object **a, int32_t length, Object **a2, int32_t length2) {
    return equalsGeneric(a, length, a2, length2, equalsObj);
}

/**
 * Returns true if the two specified arrays of shorts are equal to one
 * another.
 *
 * @param a one array to be tested for equality
 * @param a2 the other array to be tested for equality
 * @return true if the two arrays are equal
 */
bool Arrays::equals(int16_t *a, int32_t length, int16_t *a2, int32_t length2) {
    return equalsGeneric(a, length, a2, length2, equalsS);
}

/**
 * Assigns the specified boolean value to each element of the specified
 * array of booleans.
 *
 * @param a the array to be filled
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
 * Assigns the specified Object reference to each element of the specified
 * array of Objects.
 *
 * @param a the array to be filled
 * @param val the value to be stored in all elements of the array
 */
void Arrays::fill(Object **a, int32_t length, Object *val) {
    fillGeneric(a, 0, length, val);
}

/**
 * Assigns the specified Object reference to each element of the specified
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
 */
void Arrays::sort(int8_t *a, int32_t length) {
    sortGeneric(a, 0, length, Byte::compare);
}

/**
 * Sorts the specified range of the array into ascending order.
 *
 * @param a the array to be sorted
 * @param fromIndex the index of the first element (inclusive) to be sorted
 * @param toIndex the index of the last element (exclusive) to be sorted
 */
void Arrays::sort(int8_t *a, int32_t fromIndex, int32_t toIndex) {
    sortGeneric(a, fromIndex, toIndex, Byte::compare);
}

/**
 * Sorts the specified array into ascending numerical order.
 *
 * @param a the array to be sorted
 */
void Arrays::sort(char *a, int32_t length) {
    sortGeneric(a, 0, length, Character::compare);
}

/**
 * Sorts the specified range of the array into ascending order.
 *
 * @param a the array to be sorted
 * @param fromIndex the index of the first element (inclusive) to be sorted
 * @param toIndex the index of the last element (exclusive) to be sorted
 */
void Arrays::sort(char *a, int32_t fromIndex, int32_t toIndex) {
    sortGeneric(a, fromIndex, toIndex, Character::compare);
}

/**
 * Sorts the specified array into ascending numerical order.
 *
 * @param a the array to be sorted
 */
void Arrays::sort(double *a, int32_t length) {
    sortGeneric(a, 0, length, Double::compare);
}

/**
 * Sorts the specified range of the array into ascending order.
 *
 * @param a the array to be sorted
 * @param fromIndex the index of the first element (inclusive) to be sorted
 * @param toIndex the index of the last element (exclusive) to be sorted
 */
void Arrays::sort(double *a, int32_t fromIndex, int32_t toIndex) {
    sortGeneric(a, fromIndex, toIndex, Double::compare);
}

/**
 * Sorts the specified array into ascending numerical order.
 *
 * @param a the array to be sorted
 */
void Arrays::sort(float *a, int32_t length) {
    sortGeneric(a, 0, length, Float::compare);
}

/**
 * Sorts the specified range of the array into ascending order.
 *
 * @param a the array to be sorted
 * @param fromIndex the index of the first element (inclusive) to be sorted
 * @param toIndex the index of the last element (exclusive) to be sorted
 */
void Arrays::sort(float *a, int32_t fromIndex, int32_t toIndex) {
    sortGeneric(a, fromIndex, toIndex, Float::compare);
}

/**
 * Sorts the specified array into ascending numerical order.
 *
 * @param a the array to be sorted
 */
void Arrays::sort(int32_t *a, int32_t length) {
    sortGeneric(a, 0, length, Integer::compare);
}

/**
 * Sorts the specified range of the array into ascending order.
 *
 * @param a the array to be sorted
 * @param fromIndex the index of the first element (inclusive) to be sorted
 * @param toIndex the index of the last element (exclusive) to be sorted
 */
void Arrays::sort(int32_t *a, int32_t fromIndex, int32_t toIndex) {
    sortGeneric(a, fromIndex, toIndex, Integer::compare);
}

/**
 * Sorts the specified array into ascending numerical order.
 *
 * @param a the array to be sorted
 */
void Arrays::sort(int64_t *a, int32_t length) {
    sortGeneric(a, 0, length, Long::compare);
}

/**
 * Sorts the specified range of the array into ascending order.
 *
 * @param a the array to be sorted
 * @param fromIndex the index of the first element (inclusive) to be sorted
 * @param toIndex the index of the last element (exclusive) to be sorted
 */
void Arrays::sort(int64_t *a, int32_t fromIndex, int32_t toIndex) {
    sortGeneric(a, fromIndex, toIndex, Long::compare);
}

/**
 * Sorts the specified array of objects into ascending order, according to
 * the natural ordering of its elements.
 *
 * @param a the array to be sorted
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
 */
void Arrays::sort(int16_t *a, int32_t length) {
    sortGeneric(a, 0, length, Short::compare);
}

/**
 * Sorts the specified range of the array into ascending order.
 *
 * @param a the array to be sorted
 * @param fromIndex the index of the first element (inclusive) to be sorted
 * @param toIndex the index of the last element (exclusive) to be sorted
 */
void Arrays::sort(int16_t *a, int32_t fromIndex, int32_t toIndex) {
    sortGeneric(a, fromIndex, toIndex, Short::compare);
}

/**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @return a string representation of a
 */
String *Arrays::toString(bool *a, int32_t length) {
    return toStringGeneric(a, length, Boolean::toString);
}

/**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @return a string representation of a
 */
String *Arrays::toString(int8_t *a, int32_t length) {
    return toStringGeneric(a, length, Byte::toString);
}

/**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @return a string representation of a
 */
String *Arrays::toString(char *a, int32_t length) {
    return toStringGeneric(a, length, Character::toString);
}

/**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @return a string representation of a
 */
String *Arrays::toString(double *a, int32_t length) {
    return toStringGeneric(a, length, Double::toString);
}

/**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @return a string representation of a
 */
String *Arrays::toString(float *a, int32_t length) {
    return toStringGeneric(a, length, Float::toString);
}

/**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @return a string representation of a
 */
String *Arrays::toString(int32_t *a, int32_t length) {
    return toStringGeneric(a, length, Integer::toString);
}

/**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @return a string representation of a
 */
String *Arrays::toString(int64_t *a, int32_t length) {
    return toStringGeneric(a, length, Long::toString);
}

/**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @return a string representation of a
 */
String *Arrays::toString(Object **a, int32_t length) {
    return toStringGeneric(a, length, toStringObj);
}

/**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @return a string representation of a
 */
String *Arrays::toString(int16_t *a, int32_t length) {
    return toStringGeneric(a, length, Short::toString);
}
