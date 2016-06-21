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
    /*
     * default values used for copying one array to the another with greater length:
     */
    static bool defaultBool;
    static int8_t defaultByte;
    static char defaultChar;
    static double defaultDouble;
    static float defaultFloat;
    static int32_t defaultInt;
    static int64_t defaultLong;
    static Object *defaultPointer;
    static int16_t defaultShort;
    // hack to make the Comparator compare function call work
    static void *currentComparator;
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

/*
    Represents the type-agnostic function for binary searching
    in the specified sorted part of any array according to a specified compare function.
 */
template <typename T> int32_t Arrays::binarySearchGeneric(T *a, int32_t fromIndex, int32_t toIndex, T key, int32_t (*c)(T, T)) {
    // initial lower index
    int32_t lower = fromIndex;
    // initial upper index
    int32_t upper = toIndex - 1;

    while (lower <= upper) {
        // middle index
        int32_t middle = ((uint32_t)lower + (uint32_t)upper) >> 1;
        T middleValue = a[middle];

        // middle index is the new lower index if the key is greater than middle value
        if (c(middleValue, key) < 0) {
            lower = middle + 1;
        }
        // middle index is the new upper index if the key is greater than middle value
        else if (c(middleValue, key) > 0) {
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
template <typename T> T *Arrays::copyOfRangeGeneric(T *original, int32_t length, int32_t from, int32_t to, T defaultValue) {
    // a new array with the length equal to the difference of boundaries of the original array
    T *a = new T[to - from]();

    // the specified upper boundary if greater than the original array length
    if (to > length) {
        // copying the values from the original array to its last element
        for (int32_t i = from; i < length; i++) {
            a[i - from] = original[i];
        }

        // filling the rest of the new array with the default value of the given type
        for (int32_t i = length; i < to; i++) {
            a[i - from] = defaultValue;
        }
    }
    // the specified upper boundary is less then the original array length
    else {
        // copying the values from the original array to the element on the specified upper boundary
        for (int32_t i = from; i < to; i++) {
            a[i - from] = original[i];
        }
    }

    return a;
}

/*
    Represents the type-agnostic function for testing if two
    specified arrays are equal.
 */
template <typename T> bool Arrays::equalsGeneric(T *a, int32_t length, T *a2, int32_t length2, bool (*equals)(T, T), bool isObjectArray) {
    // comparing pointers
    if (a == a2) {
        return true;
    }

    // testing the references for a NULL value
    if (a == nullptr || a2 == nullptr) {
        return false;
    }

    // comparing the array lengths
    if (length2 != length) {
        return false;
    }

    // comparing corresponding elements of arrays
    for (int32_t i = 0; i < length; i++) {
        bool e;
        
        // checking NULL values for object pointers
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

/*
    Represents the type-agnostic function for filling
    the specified part of any array with the specified value.
 */
template <typename T> void Arrays::fillGeneric(T *a, int32_t fromIndex, int32_t toIndex, T val) {
    // setting each element to the value
    for (int32_t i = fromIndex; i < toIndex; i++) {
        a[i] = val;
    }
}

/*
    Represents the type-agnostic function for sorting
    the specified part of any array according to a specified compare function.
 */
template <typename T> void Arrays::sortGeneric(T *a, int32_t fromIndex, int32_t toIndex, bool (*c)(T, T), bool isObjectArray) {
    // unstable sort for primitive values
    if (!isObjectArray) {
        std::sort(a + fromIndex, a + toIndex, c);
    }
    // stable sort for object pointers
    else {
        std::stable_sort(a + fromIndex, a + toIndex, c);
    }
}

/*
    Represents the type-agnostic function for creating
    the string representation of any array.
 */
template <typename T> String *Arrays::toStringGeneric(T *a, int32_t length, String *(*toString)(T), bool isObjectArray) {
    // create ostringstream for appending the text
    std::ostringstream oss("");
    oss << "[";
    String *str;

    // append first element string representation
    if (length > 0) {
        // checking NULL values for object pointers
        if (isObjectArray) {
            str = a[0] == 0 ? new String("null") : toString(a[0]);
        }
        else  {
            str = toString(a[0]);
        }
        
        oss << str->_s();
        delete str;
    }

    // append another elements string representation
    for (int32_t i = 1; i < length; i++) {
        // checking NULL values for object pointers
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

    // create Java-like string
    return new String(oss.str());
}

#endif	// ARRAYS_INCLUDED
