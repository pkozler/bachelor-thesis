#ifndef ARRAYS_INCLUDED
#define	ARRAYS_INCLUDED

#include "String_.h"
#include "System.h"
#include <algorithm>
#include <sstream>
#include <cstdint>

/**
 * This class contains various methods for manipulating arrays (such as sorting and searching).
 *
 * @author Petr Kozler (A13B0359P)
 */
class Arrays {
    static bool defaultBool;
    static int8_t defaultByte;
    static char defaultChar;
    static double defaultDouble;
    static float defaultFloat;
    static int32_t defaultInt;
    static int64_t defaultLong;
    static Object *defaultPointer;
    static int16_t defaultShort;
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
    static bool compareObjComp(Object *a, Object *b);
    static int32_t compareBI(int8_t a, int8_t b);
    static int32_t compareCI(char a, char b);
    static int32_t compareDI(double a, double b);
    static int32_t compareFI(float a, float b);
    static int32_t compareII(int32_t a, int32_t b);
    static int32_t compareLI(int64_t a, int64_t b);
    static int32_t compareSI(int16_t a, int16_t b);
    static int32_t compareObjI(Object *a, Object *b);
    static int32_t compareObjCompI(Object *a, Object *b);
    template <typename T> static int32_t binarySearchGeneric(T *a, int32_t fromIndex, int32_t toIndex, T key, int32_t (*c)(T, T));
    template <typename T> static T *copyOfRangeGeneric(T *original, int32_t length, int32_t from, int32_t to, T defaultValue);
    template <typename T> static bool equalsGeneric(T *a, int32_t length, T *a2, int32_t length2, bool (*equals)(T, T), bool isObjectArray);
    template <typename T> static void fillGeneric(T *a, int32_t fromIndex, int32_t toIndex, T val);
    template <typename T> static void sortGeneric(T *a, int32_t fromIndex, int32_t toIndex, bool (*c)(T, T), bool isObjectArray = false);
    template <typename T> static String *toStringGeneric(T *a, int32_t length, String *(*toString)(T), bool isObjectArray);
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
    static int32_t binarySearch(Object **a, int32_t length, Object *key, Comparator *c);
    static int32_t binarySearch(Object **a, int32_t fromIndex, int32_t toIndex, Object *key, Comparator *c);
    static bool *copyOf(bool *original, int32_t length, int32_t newLength);
    static int8_t *copyOf(int8_t *original, int32_t length, int32_t newLength);
    static char *copyOf(char *original, int32_t length, int32_t newLength);
    static double *copyOf(double *original, int32_t length, int32_t newLength);
    static float *copyOf(float *original, int32_t length, int32_t newLength);
    static int32_t *copyOf(int32_t *original, int32_t length, int32_t newLength);
    static int64_t *copyOf(int64_t *original, int32_t length, int32_t newLength);
    static int16_t *copyOf(int16_t *original, int32_t length, int32_t newLength);
    static Object **copyOf(Object **original, int32_t length, int32_t newLength);
    static bool *copyOfRange(bool *original, int32_t length, int32_t from, int32_t to);
    static int8_t *copyOfRange(int8_t *original, int32_t length, int32_t from, int32_t to);
    static char *copyOfRange(char *original, int32_t length, int32_t from, int32_t to);
    static double *copyOfRange(double *original, int32_t length, int32_t from, int32_t to);
    static float *copyOfRange(float *original, int32_t length, int32_t from, int32_t to);
    static int32_t *copyOfRange(int32_t *original, int32_t length, int32_t from, int32_t to);
    static int64_t *copyOfRange(int64_t *original, int32_t length, int32_t from, int32_t to);
    static int16_t *copyOfRange(int16_t *original, int32_t length, int32_t from, int32_t to);
    static Object **copyOfRange(Object **original, int32_t length, int32_t from, int32_t to);
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
    static void sort(Object **a, int32_t length, Comparator *c);
    static void sort(Object **a, int32_t fromIndex, int32_t toIndex, Comparator *c);
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

template <typename T> int32_t Arrays::binarySearchGeneric(T *a, int32_t fromIndex, int32_t toIndex, T key, int32_t (*c)(T, T)) {
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

template <typename T> T *Arrays::copyOfRangeGeneric(T *original, int32_t length, int32_t from, int32_t to, T defaultValue) {
    T *a = new T[to - from]();

    if (to > length) {
        for (int32_t i = from; i < length; i++) {
            a[i - from] = original[i];
        }

        for (int32_t i = length; i < to; i++) {
            a[i - from] = defaultValue;
        }
    }
    else {
        for (int32_t i = from; i < to; i++) {
            a[i - from] = original[i];
        }
    }

    return a;
}

template <typename T> bool Arrays::equalsGeneric(T *a, int32_t length, T *a2, int32_t length2, bool (*equals)(T, T), bool isObjectArray) {
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
        bool e;
        
        if (isObjectArray) {
            e = a[i] == 0 ? a2[i] == 0 : equals(a[i], a2[i]);
        }
        else {
            e = equals(a[i], a2[i]);
        }
        
        if (!e) {
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

template <typename T> void Arrays::sortGeneric(T *a, int32_t fromIndex, int32_t toIndex, bool (*c)(T, T), bool isObjectArray) {
    if (c == nullptr) {
        std::sort(a + fromIndex, a + toIndex, c);
    }
    else {
        if (!isObjectArray) {
            std::sort(a + fromIndex, a + toIndex, c);
        }
        else {
            std::stable_sort(a + fromIndex, a + toIndex, c);
        }
    }
}

template <typename T> String *Arrays::toStringGeneric(T *a, int32_t length, String *(*toString)(T), bool isObjectArray) {
    std::ostringstream oss("");
    oss << "[";
    String *str;

    if (length > 0) {
        if (isObjectArray) {
            str = a[0] == 0 ? new String("null") : toString(a[0]);
        }
        else  {
            str = toString(a[0]);
        }
        
        oss << str->_s();
        delete str;
    }

    for (int32_t i = 1; i < length; i++) {
        if (isObjectArray) {
            str = a[i] == 0 ? new String("null") : toString(a[i]);
        }
        else  {
            str = toString(a[i]);
        }
        
        oss << ", " << str->_s();
        delete str;
    }

    oss << "]";

    return new String(oss.str());
}

#endif	// ARRAYS_INCLUDED
