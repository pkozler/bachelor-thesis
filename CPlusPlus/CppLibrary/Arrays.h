#ifndef ARRAYS_INCLUDED
#define	ARRAYS_INCLUDED

#include "String_.h"
#include <algorithm>
#include <sstream>
#include <cstdint>

/**
 * This class contains various methods for manipulating arrays (such as sorting and searching).
 *
 * @author Petr Kozler (A13B0359P)
 */
class Arrays {
    static void *currentComparator; // hack to make the Comparator compare function call work
    static bool equalsBool(bool a, bool b);
    static bool equalsB(int8_t a, int8_t b);
    static bool equalsC(char a, char b);
    static bool equalsD(double a, double b);
    static bool equalsF(float a, float b);
    static bool equalsI(int32_t a, int32_t b);
    static bool equalsL(int64_t a, int64_t b);
    static bool equalsS(int16_t a, int16_t b);
    static bool equalsObj(Object *a, Object *b);
    static String *toStringObj(Object *a);
    static bool compareB(int8_t a, int8_t b);
    static bool compareC(char a, char b);
    static bool compareD(double a, double b);
    static bool compareF(float a, float b);
    static bool compareI(int32_t a, int32_t b);
    static bool compareL(int64_t a, int64_t b);
    static bool compareS(int16_t a, int16_t b);
    static bool compareObj(Object *a, Object *b);
    template <class T> static bool compareObjComp(T *a, T *b);
    template <typename T> static int32_t binarySearchGeneric(T *a, int32_t fromIndex, int32_t toIndex, T key, bool (*c)(T, T));
    template <typename T> static T *copyOfRangeGeneric(T *original, int32_t length, int32_t from, int32_t to);
    template <typename T> static bool equalsGeneric(T *a, int32_t length, T *a2, int32_t length2, bool (*equals)(T, T));
    template <typename T> static void fillGeneric(T *a, int32_t fromIndex, int32_t toIndex, T val);
    template <typename T> static void sortGeneric(T *a, int32_t fromIndex, int32_t toIndex, bool (*c)(T, T), bool stable = false);
    template <typename T> static String *toStringGeneric(T *a, int32_t length, String *(*toString)(T));
public:
    static int32_t binarySearch(int8_t *a, int32_t length, int8_t key);
    static int32_t binarySearch(int8_t *a, int32_t fromIndex, int32_t toIndex, int8_t key);
    static int32_t binarySearch(char *a, int32_t length, char key);
    static int32_t binarySearch(char *a, int32_t fromIndex, int32_t toIndex, char key);
    static int32_t binarySearch(double *a, int32_t length, double key);
    static int32_t binarySearch(double *a, int32_t fromIndex, int32_t toIndex, double key);
    static int32_t binarySearch(float *a, int32_t length, float key);
    static int32_t binarySearch(float *a, int32_t fromIndex, int32_t toIndex, float key);
    static int32_t binarySearch(int32_t *a, int32_t length, int32_t key);
    static int32_t binarySearch(int32_t *a, int32_t fromIndex, int32_t toIndex, int32_t key);
    static int32_t binarySearch(int64_t *a, int32_t length, int64_t key);
    static int32_t binarySearch(int64_t *a, int32_t fromIndex, int32_t toIndex, int64_t key);
    static int32_t binarySearch(Object **a, int32_t length, Object *key);
    static int32_t binarySearch(Object **a, int32_t fromIndex, int32_t toIndex, Object *key);
    static int32_t binarySearch(int16_t *a, int32_t length, int16_t key);
    static int32_t binarySearch(int16_t *a, int32_t fromIndex, int32_t toIndex, int16_t key);
    template <class T> static int32_t binarySearch(T **a, int32_t length, T *key, Comparator<T> *c);
    template <class T> static int32_t binarySearch(T **a, int32_t fromIndex, int32_t toIndex, T *key, Comparator<T> *c);
    static bool *copyOf(bool *original, int32_t length, int32_t newLength);
    static int8_t *copyOf(int8_t *original, int32_t length, int32_t newLength);
    static char *copyOf(char *original, int32_t length, int32_t newLength);
    static double *copyOf(double *original, int32_t length, int32_t newLength);
    static float *copyOf(float *original, int32_t length, int32_t newLength);
    static int32_t *copyOf(int32_t *original, int32_t length, int32_t newLength);
    static int64_t *copyOf(int64_t *original, int32_t length, int32_t newLength);
    static int16_t *copyOf(int16_t *original, int32_t length, int32_t newLength);
    template <class T> static T **copyOf(T **original, int32_t length, int32_t newLength);
    static bool *copyOfRange(bool *original, int32_t length, int32_t from, int32_t to);
    static int8_t *copyOfRange(int8_t *original, int32_t length, int32_t from, int32_t to);
    static char *copyOfRange(char *original, int32_t length, int32_t from, int32_t to);
    static double *copyOfRange(double *original, int32_t length, int32_t from, int32_t to);
    static float *copyOfRange(float *original, int32_t length, int32_t from, int32_t to);
    static int32_t *copyOfRange(int32_t *original, int32_t length, int32_t from, int32_t to);
    static int64_t *copyOfRange(int64_t *original, int32_t length, int32_t from, int32_t to);
    static int16_t *copyOfRange(int16_t *original, int32_t length, int32_t from, int32_t to);
    template <class T> static T **copyOfRange(T **original, int32_t length, int32_t from, int32_t to);
    static bool equals(bool *a, int32_t length, bool *a2, int32_t length2);
    static bool equals(int8_t *a, int32_t length, int8_t *a2, int32_t length2);
    static bool equals(char *a, int32_t length, char *a2, int32_t length2);
    static bool equals(double *a, int32_t length, double *a2, int32_t length2);
    static bool equals(float *a, int32_t length, float *a2, int32_t length2);
    static bool equals(int32_t *a, int32_t length, int32_t *a2, int32_t length2);
    static bool equals(int64_t *a, int32_t length, int64_t *a2, int32_t length2);
    static bool equals(Object **a, int32_t length, Object **a2, int32_t length2);
    static bool equals(int16_t *a, int32_t length, int16_t *a2, int32_t length2);
    static void fill(bool *a, int32_t length, bool val);
    static void fill(bool *a, int32_t fromIndex, int32_t toIndex, bool val);
    static void fill(int8_t *a, int32_t length, int8_t val);
    static void fill(int8_t *a, int32_t fromIndex, int32_t toIndex, int8_t val);
    static void fill(char *a, int32_t length, char val);
    static void fill(char *a, int32_t fromIndex, int32_t toIndex, char val);
    static void fill(double *a, int32_t length, double val);
    static void fill(double *a, int32_t fromIndex, int32_t toIndex, double val);
    static void fill(float *a, int32_t length, float val);
    static void fill(float *a, int32_t fromIndex, int32_t toIndex, float val);
    static void fill(int32_t *a, int32_t length, int32_t val);
    static void fill(int32_t *a, int32_t fromIndex, int32_t toIndex, int32_t val);
    static void fill(int64_t *a, int32_t length, int64_t val);
    static void fill(int64_t *a, int32_t fromIndex, int32_t toIndex, int64_t val);
    static void fill(Object **a, int32_t length, Object *val);
    static void fill(Object **a, int32_t fromIndex, int32_t toIndex, Object *val);
    static void fill(int16_t *a, int32_t length, int16_t val);
    static void fill(int16_t *a, int32_t fromIndex, int32_t toIndex, int16_t val);
    static void sort(int8_t *a, int32_t length);
    static void sort(int8_t *a, int32_t fromIndex, int32_t toIndex);
    static void sort(char *a, int32_t length);
    static void sort(char *a, int32_t fromIndex, int32_t toIndex);
    static void sort(double *a, int32_t length);
    static void sort(double *a, int32_t fromIndex, int32_t toIndex);
    static void sort(float *a, int32_t length);
    static void sort(float *a, int32_t fromIndex, int32_t toIndex);
    static void sort(int32_t *a, int32_t length);
    static void sort(int32_t *a, int32_t fromIndex, int32_t toIndex);
    static void sort(int64_t *a, int32_t length);
    static void sort(int64_t *a, int32_t fromIndex, int32_t toIndex);
    static void sort(Object **a, int32_t length);
    static void sort(Object **a, int32_t fromIndex, int32_t toIndex);
    static void sort(int16_t *a, int32_t length);
    static void sort(int16_t *a, int32_t fromIndex, int32_t toIndex);
    template <class T> static void sort(T **a, int32_t length, Comparator<T> *c);
    template <class T> static void sort(T **a, int32_t fromIndex, int32_t toIndex, Comparator<T> *c);
    static String *toString(bool *a, int32_t length);
    static String *toString(int8_t *a, int32_t length);
    static String *toString(char *a, int32_t length);
    static String *toString(double *a, int32_t length);
    static String *toString(float *a, int32_t length);
    static String *toString(int32_t *a, int32_t length);
    static String *toString(int64_t *a, int32_t length);
    static String *toString(Object **a, int32_t length);
    static String *toString(int16_t *a, int32_t length);
};

template <class T> bool Arrays::compareObjComp(T *a, T *b) {
    return ((Comparator<Object> *) currentComparator)->compare(a, b) < 0;
}

template <typename T> int32_t Arrays::binarySearchGeneric(T *a, int32_t fromIndex, int32_t toIndex, T key, bool (*c)(T, T)) {
    int32_t lower = fromIndex;
    int32_t upper = toIndex - 1;

    while (lower <= upper) {
        int32_t middle = ((uint32_t)lower + (uint32_t)upper) >> 1;
        T middleValue = a[middle];

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

template <typename T> T *Arrays::copyOfRangeGeneric(T *original, int32_t length, int32_t from, int32_t to) {
    T *a = new T[to - from];

    if (to > length) {
        for (int32_t i = from; i < length; i++) {
            a[i - from] = original[i];
        }

        for (int32_t i = length; i < to; i++) {
            a[i - from] = 0;
        }
    }
    else {
        for (int32_t i = from; i < to; i++) {
            a[i - from] = original[i];
        }
    }

    return a;
}

template <typename T> bool Arrays::equalsGeneric(T *a, int32_t length, T *a2, int32_t length2, bool (*equals)(T, T)) {
    if (a == a2) {
        return true;
    }

    if (a == nullptr || a2 == nullptr) {
        return false;
    }

    if (length2 != length) {
        return false;
    }

    for (int32_t i = 0; i < length; i++) {
        if (!equals(a[i], a2[i])) {
            return false;
        }
    }

    return true;
}

template <typename T> void Arrays::fillGeneric(T *a, int32_t fromIndex, int32_t toIndex, T val) {
    for (int32_t i = fromIndex; i < toIndex; i++) {
        a[i] = val;
    }
}

template <typename T> void Arrays::sortGeneric(T *a, int32_t fromIndex, int32_t toIndex, bool (*c)(T, T), bool stable) {
    if (c == nullptr) {
        std::sort(a + fromIndex, a + toIndex, c);
    }
    else {
        if (!stable) {
            std::sort(a + fromIndex, a + toIndex, c);
        }
        else {
            std::stable_sort(a + fromIndex, a + toIndex, c);
        }
    }
}

template <typename T> String *Arrays::toStringGeneric(T *a, int32_t length, String *(*toString)(T)) {
    std::ostringstream oss("[");

    if (length > 0) {
        String *str = toString(a[0]);
        oss << str;
        delete str;
    }

    for (int32_t i = 1; i < length; i++) {
        String *str = toString(a[i]);
        oss << ", " << str;
        delete str;
    }

    oss << "]";

    return new String(oss.str());
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
template <class T> int32_t Arrays::binarySearch(T **a, int32_t length, T *key, Comparator<T> *c) {
    currentComparator = c;
    return binarySearchGeneric(a, 0, length, key, compareObjComp);
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
template <class T> int32_t Arrays::binarySearch(T **a, int32_t fromIndex, int32_t toIndex, T *key, Comparator<T> *c) {
    currentComparator = c;
    return binarySearchGeneric(a, fromIndex, toIndex, key, compareObjComp);
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
template <class T> T **Arrays::copyOf(T **original, int32_t length, int32_t newLength) {
    return copyOfRangeGeneric(original, length, 0, newLength);
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
template <class T> T **Arrays::copyOfRange(T **original, int32_t length, int32_t from, int32_t to) {
    return copyOfRangeGeneric(original, length, from, to);
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
template <class T> void Arrays::sort(T **a, int32_t length, Comparator<T> *c) {
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
template <class T> void Arrays::sort(T **a, int32_t fromIndex, int32_t toIndex, Comparator<T> *c) {
    currentComparator = c;
    sortGeneric(a, fromIndex, toIndex, compareObjComp, true);
}

#endif	// ARRAYS_INCLUDED
