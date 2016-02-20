#ifndef ARRAYS_INCLUDED
#define	ARRAYS_INCLUDED

#include "String.h"
#include <sstream>
#include <algorithm>

class Arrays {
    Arrays();
    ~Arrays();
    static int compareC(char a, char b);
    static int compareD(double a, double b);
    static int compareF(float a, float b);
    static int compareI(int a, int b);
    static int compareL(long a, long b);
    static int compareS(short a, short b);
    static bool equalsBool(bool a, bool b);
    static bool equalsC(char a, char b);
    static bool equalsD(double a, double b);
    static bool equalsF(float a, float b);
    static bool equalsI(int a, int b);
    static bool equalsL(long a, long b);
    static bool equalsS(short a, short b);
    template <class T> static int binarySearchGeneric(T *a, int fromIndex, int toIndex, T key, int (*c)(T, T));
    template <class T> static T *copyOfRangeGeneric(T *original, int length, int from, int to);
    template <class T> static bool equalsGeneric(T *a, int length, T *a2, int length2, bool (*equals)(T, T));
    template <class T> static void fillGeneric(T *a, int fromIndex, int toIndex, T val);
    template <class T> static void sortGeneric(T *a, int fromIndex, int toIndex, int (*c)(T, T), bool stable = false);
    template <class T> static String *toStringGeneric(T *a, int length, String *(*toString)(T));
public:
    static int binarySearch(char *a, int length, char key);
    static int binarySearch(char *a, int fromIndex, int toIndex, char key);
    static int binarySearch(double *a, int length, double key);
    static int binarySearch(double *a, int fromIndex, int toIndex, double key);
    static int binarySearch(float *a, int length, float key);
    static int binarySearch(float *a, int fromIndex, int toIndex, float key);
    static int binarySearch(int *a, int length, int key);
    static int binarySearch(int *a, int fromIndex, int toIndex, int key);
    static int binarySearch(long *a, int length, long key);
    static int binarySearch(long *a, int fromIndex, int toIndex, long key);
    static int binarySearch(void **a, int length, void *key, int (*c)(void *, void *));
    static int binarySearch(void **a, int fromIndex, int toIndex, void *key, int (*c)(void *, void *));
    static int binarySearch(short *a, int length, short key);
    static int binarySearch(short *a, int fromIndex, int toIndex, short key);
    template <class T> static int binarySearch(T *a, int length, T key, int (*c)(T, T));
    template <class T> static int binarySearch(T *a, int fromIndex, int toIndex, T key, int (*c)(T, T));
    static bool *copyOf(bool *original, int length, int newLength);
    static char *copyOf(char *original, int length, int newLength);
    static double *copyOf(double *original, int length, int newLength);
    static float *copyOf(float *original, int length, int newLength);
    static int *copyOf(int *original, int length, int newLength);
    static long *copyOf(long *original, int length, int newLength);
    static short *copyOf(short *original, int length, int newLength);
    template <class T> static T *copyOf(T *original, int length, int newLength);
    static bool *copyOfRange(bool *original, int length, int from, int to);
    static char *copyOfRange(char *original, int length, int from, int to);
    static double *copyOfRange(double *original, int length, int from, int to);
    static float *copyOfRange(float *original, int length, int from, int to);
    static int *copyOfRange(int *original, int length, int from, int to);
    static long *copyOfRange(long *original, int length, int from, int to);
    static short *copyOfRange(short *original, int length, int from, int to);
    template <class T> static T *copyOfRange(T *original, int length, int from, int to);
    static bool equals(bool *a, int length, bool *a2, int length2);
    static bool equals(char *a, int length, char *a2, int length2);
    static bool equals(double *a, int length, double *a2, int length2);
    static bool equals(float *a, int length, float *a2, int length2);
    static bool equals(int *a, int length, int *a2, int length2);
    static bool equals(long *a, int length, long *a2, int length2);
    static bool equals(void **a, int length, void **a2, int length2, bool (*equals)(void *, void *));
    static bool equals(short *a, int length, short *a2, int length2);
    static void fill(bool *a, int length, bool val);
    static void fill(bool *a, int fromIndex, int toIndex, bool val);
    static void fill(char *a, int length, char val);
    static void fill(char *a, int fromIndex, int toIndex, char val);
    static void fill(double *a, int length, double val);
    static void fill(double *a, int fromIndex, int toIndex, double val);
    static void fill(float *a, int length, float val);
    static void fill(float *a, int fromIndex, int toIndex, float val);
    static void fill(int *a, int length, int val);
    static void fill(int *a, int fromIndex, int toIndex, int val);
    static void fill(long *a, int length, long val);
    static void fill(long *a, int fromIndex, int toIndex, long val);
    static void fill(void **a, int length, void *val);
    static void fill(void **a, int fromIndex, int toIndex, void *val);
    static void fill(short *a, int length, short val);
    static void fill(short *a, int fromIndex, int toIndex, short val);
    static void sort(char *a, int length);
    static void sort(char *a, int fromIndex, int toIndex);
    static void sort(double *a, int length);
    static void sort(double *a, int fromIndex, int toIndex);
    static void sort(float *a, int length);
    static void sort(float *a, int fromIndex, int toIndex);
    static void sort(int *a, int length);
    static void sort(int *a, int fromIndex, int toIndex);
    static void sort(long *a, int length);
    static void sort(long *a, int fromIndex, int toIndex);
    static void sort(void **a, int length, int (*c)(void *, void *));
    static void sort(void **a, int fromIndex, int toIndex, int (*c)(void *, void *));
    static void sort(short *a, int length);
    static void sort(short *a, int fromIndex, int toIndex);
    template <class T> static void sort(T *a, int length, int (*c)(T, T));
    template <class T> static void sort(T *a, int fromIndex, int toIndex, int (*c)(T, T));
    static String *toString(bool *a, int length);
    static String *toString(char *a, int length);
    static String *toString(double *a, int length);
    static String *toString(float *a, int length);
    static String *toString(int *a, int length);
    static String *toString(long *a, int length);
    static String *toString(void **a, int length, String *(*toString)(void *));
    static String *toString(short *a, int length);
};

template <class T> int Arrays::binarySearchGeneric(T *a, int fromIndex, int toIndex, T key, int (*c)(T, T)) {
    T *i;
    
    if (c == nullptr) {
        i = std::lower_bound(a + fromIndex, a + toIndex, key);
    }
    else {
        i = std::lower_bound(a + fromIndex, a + toIndex, key, c);
    }
    
    if (i != a + toIndex && !(key < *i)) {
        return (int) (i - a);
    }
    else {
        return -1;
    }
}

template <class T> T *Arrays::copyOfRangeGeneric(T *original, int length, int from, int to) {
    T *a = new T[to - from];

    if (to > length) {
        for (int i = from; i < length; i++) {
            a[i - from] = original[i];
        }

        for (int i = length; i < to; i++) {
            a[i - from] = 0;
        }
    }
    else {
        for (int i = from; i < to; i++) {
            a[i - from] = original[i];
        }
    }

    return a;
}

template <class T> bool Arrays::equalsGeneric(T *a, int length, T *a2, int length2, bool (*equals)(T, T)) {
    if (a == a2) {
        return true;
    }

    if (a == nullptr || a2 == nullptr) {
        return false;
    }

    if (length2 != length) {
        return false;
    }

    for (int i = 0; i < length; i++) {
        if (!equals(a[i], a2[i])) {
            return false;
        }
    }

    return true;
}

template <class T> void Arrays::fillGeneric(T *a, int fromIndex, int toIndex, T val) {
    for (int i = fromIndex; i < toIndex; i++) {
        a[i] = val;
    }
}

template <class T> void Arrays::sortGeneric(T *a, int fromIndex, int toIndex, int (*c)(T, T), bool stable) {
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

template <class T> String *Arrays::toStringGeneric(T *a, int length, String *(*toString)(T)) {
    std::ostringstream oss("[");

    if (length > 0) {
        oss << toString(a[0])->toString();
    }

    for (int i = 1; i < length; i++) {
        oss << ", " << toString(a[i])->toString();
    }

    oss << "]";

    return new String(oss.str());
}

template <class T> int Arrays::binarySearch(T *a, int length, T key, int (*c)(T, T)) {
    return binarySearchGeneric(a, 0, length, key, c);
}

template <class T> int Arrays::binarySearch(T *a, int fromIndex, int toIndex, T key, int (*c)(T, T)) {
    return binarySearchGeneric(a, fromIndex, toIndex, key, c);
}

template <class T> T *Arrays::copyOf(T *original, int length, int newLength) {
    return copyOfRangeGeneric(original, length, 0, newLength);
}

template <class T> T *Arrays::copyOfRange(T *original, int length, int from, int to) {
    return copyOfRangeGeneric(original, length, from, to);
}

template <class T> void Arrays::sort(T *a, int length, int (*c)(T, T)) {
    sortGeneric(a, 0, length, c, true);
}

template <class T> void Arrays::sort(T *a, int fromIndex, int toIndex, int (*c)(T, T)) {
    sortGeneric(a, fromIndex, toIndex, c, true);
}

#endif	// ARRAYS_INCLUDED
