#ifndef ARRAYS_INCLUDED
#define	ARRAYS_INCLUDED

#include "String.h"
#include <sstream>
#include <algorithm>
#include <cstdint>

class Arrays {
    Arrays();
    ~Arrays();
    static bool equalsBool(bool a, bool b);
    static bool equalsB(int8_t a, int8_t b);
    static bool equalsC(char a, char b);
    static bool equalsD(double a, double b);
    static bool equalsF(float a, float b);
    static bool equalsI(int32_t a, int32_t b);
    static bool equalsL(int64_t a, int64_t b);
    static bool equalsS(int16_t a, int16_t b);
    template <class T> static int32_t binarySearchGeneric(T *a, int32_t fromIndex, int32_t toIndex, T key, int32_t (*c)(T, T));
    template <class T> static T *copyOfRangeGeneric(T *original, int32_t length, int32_t from, int32_t to);
    template <class T> static bool equalsGeneric(T *a, int32_t length, T *a2, int32_t length2, bool (*equals)(T, T));
    template <class T> static void fillGeneric(T *a, int32_t fromIndex, int32_t toIndex, T val);
    template <class T> static void sortGeneric(T *a, int32_t fromIndex, int32_t toIndex, int32_t (*c)(T, T), bool stable = false);
    template <class T> static String *toStringGeneric(T *a, int32_t length, String *(*toString)(T));
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
    static int32_t binarySearch(void **a, int32_t length, void *key, int32_t (*c)(void *, void *));
    static int32_t binarySearch(void **a, int32_t fromIndex, int32_t toIndex, void *key, int32_t (*c)(void *, void *));
    static int32_t binarySearch(int16_t *a, int32_t length, int16_t key);
    static int32_t binarySearch(int16_t *a, int32_t fromIndex, int32_t toIndex, int16_t key);
    template <class T> static int32_t binarySearch(T *a, int32_t length, T key, int32_t (*c)(T, T));
    template <class T> static int32_t binarySearch(T *a, int32_t fromIndex, int32_t toIndex, T key, int32_t (*c)(T, T));
    static bool *copyOf(bool *original, int32_t length, int32_t newLength);
    static int8_t *copyOf(int8_t *original, int32_t length, int32_t newLength);
    static char *copyOf(char *original, int32_t length, int32_t newLength);
    static double *copyOf(double *original, int32_t length, int32_t newLength);
    static float *copyOf(float *original, int32_t length, int32_t newLength);
    static int32_t *copyOf(int32_t *original, int32_t length, int32_t newLength);
    static int64_t *copyOf(int64_t *original, int32_t length, int32_t newLength);
    static int16_t *copyOf(int16_t *original, int32_t length, int32_t newLength);
    template <class T> static T *copyOf(T *original, int32_t length, int32_t newLength);
    static bool *copyOfRange(bool *original, int32_t length, int32_t from, int32_t to);
    static int8_t *copyOfRange(int8_t *original, int32_t length, int32_t from, int32_t to);
    static char *copyOfRange(char *original, int32_t length, int32_t from, int32_t to);
    static double *copyOfRange(double *original, int32_t length, int32_t from, int32_t to);
    static float *copyOfRange(float *original, int32_t length, int32_t from, int32_t to);
    static int32_t *copyOfRange(int32_t *original, int32_t length, int32_t from, int32_t to);
    static int64_t *copyOfRange(int64_t *original, int32_t length, int32_t from, int32_t to);
    static int16_t *copyOfRange(int16_t *original, int32_t length, int32_t from, int32_t to);
    template <class T> static T *copyOfRange(T *original, int32_t length, int32_t from, int32_t to);
    static bool equals(bool *a, int32_t length, bool *a2, int32_t length2);
    static bool equals(int8_t *a, int32_t length, int8_t *a2, int32_t length2);
    static bool equals(char *a, int32_t length, char *a2, int32_t length2);
    static bool equals(double *a, int32_t length, double *a2, int32_t length2);
    static bool equals(float *a, int32_t length, float *a2, int32_t length2);
    static bool equals(int32_t *a, int32_t length, int32_t *a2, int32_t length2);
    static bool equals(int64_t *a, int32_t length, int64_t *a2, int32_t length2);
    static bool equals(void **a, int32_t length, void **a2, int32_t length2, bool (*equals)(void *, void *));
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
    static void fill(void **a, int32_t length, void *val);
    static void fill(void **a, int32_t fromIndex, int32_t toIndex, void *val);
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
    static void sort(void **a, int32_t length, int32_t (*c)(void *, void *));
    static void sort(void **a, int32_t fromIndex, int32_t toIndex, int32_t (*c)(void *, void *));
    static void sort(int16_t *a, int32_t length);
    static void sort(int16_t *a, int32_t fromIndex, int32_t toIndex);
    template <class T> static void sort(T *a, int32_t length, int32_t (*c)(T, T));
    template <class T> static void sort(T *a, int32_t fromIndex, int32_t toIndex, int32_t (*c)(T, T));
    static String *toString(bool *a, int32_t length);
    static String *toString(int8_t *a, int32_t length);
    static String *toString(char *a, int32_t length);
    static String *toString(double *a, int32_t length);
    static String *toString(float *a, int32_t length);
    static String *toString(int32_t *a, int32_t length);
    static String *toString(int64_t *a, int32_t length);
    static String *toString(void **a, int32_t length, String *(*toString)(void *));
    static String *toString(int16_t *a, int32_t length);
};

template <class T> int32_t Arrays::binarySearchGeneric(T *a, int32_t fromIndex, int32_t toIndex, T key, int32_t (*c)(T, T)) {
    T *i;
    
    if (c == nullptr) {
        i = std::lower_bound(a + fromIndex, a + toIndex, key);
    }
    else {
        i = std::lower_bound(a + fromIndex, a + toIndex, key, c);
    }
    
    if (i != a + toIndex && !(key < *i)) {
        return (int32_t) (i - a);
    }
    else {
        return -1;
    }
}

template <class T> T *Arrays::copyOfRangeGeneric(T *original, int32_t length, int32_t from, int32_t to) {
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

template <class T> bool Arrays::equalsGeneric(T *a, int32_t length, T *a2, int32_t length2, bool (*equals)(T, T)) {
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

template <class T> void Arrays::fillGeneric(T *a, int32_t fromIndex, int32_t toIndex, T val) {
    for (int32_t i = fromIndex; i < toIndex; i++) {
        a[i] = val;
    }
}

template <class T> void Arrays::sortGeneric(T *a, int32_t fromIndex, int32_t toIndex, int32_t (*c)(T, T), bool stable) {
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

template <class T> String *Arrays::toStringGeneric(T *a, int32_t length, String *(*toString)(T)) {
    std::ostringstream oss("[");

    if (length > 0) {
        String *str = toString(a[0]);
        oss << str->toString();
        delete str;
    }

    for (int32_t i = 1; i < length; i++) {
        String *str = toString(a[i]);
        oss << ", " << str->toString();
        delete str;
    }

    oss << "]";

    return new String(oss.str());
}

template <class T> int32_t Arrays::binarySearch(T *a, int32_t length, T key, int32_t (*c)(T, T)) {
    return binarySearchGeneric(a, 0, length, key, c);
}

template <class T> int32_t Arrays::binarySearch(T *a, int32_t fromIndex, int32_t toIndex, T key, int32_t (*c)(T, T)) {
    return binarySearchGeneric(a, fromIndex, toIndex, key, c);
}

template <class T> T *Arrays::copyOf(T *original, int32_t length, int32_t newLength) {
    return copyOfRangeGeneric(original, length, 0, newLength);
}

template <class T> T *Arrays::copyOfRange(T *original, int32_t length, int32_t from, int32_t to) {
    return copyOfRangeGeneric(original, length, from, to);
}

template <class T> void Arrays::sort(T *a, int32_t length, int32_t (*c)(T, T)) {
    sortGeneric(a, 0, length, c, true);
}

template <class T> void Arrays::sort(T *a, int32_t fromIndex, int32_t toIndex, int32_t (*c)(T, T)) {
    sortGeneric(a, fromIndex, toIndex, c, true);
}

#endif	// ARRAYS_INCLUDED
