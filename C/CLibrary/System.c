#include <stdlib.h>
#include <wchar.h>

#include "System.h"

/*
    Merges the specified subarrays for Merge sort.
 */
void _merge(void **array, void **aux, int32_t left, int32_t right, int32_t (*compare)(const void *, const void *)) {
    int32_t middleIndex = (left + right) / 2;
    int32_t leftIndex = left;
    int32_t rightIndex = middleIndex + 1;
    int32_t auxIndex = left;

    // moving elements to the auxilliary array until one of the indices leaves the specified boundary
    while (leftIndex <= middleIndex && rightIndex <= right) {
        // comparing the struct pointer values and setting the less one as the auxilliary array element
        if (compare((void *) array[leftIndex], (void *) array[rightIndex]) <= 0) {
            aux[auxIndex] = array[leftIndex++];
        }
        else {
            aux[auxIndex] = array[rightIndex++];
        }

        // incrementing the auxilliary array index
        auxIndex++;
    }

    // setting the rest of the left subarray
    while (leftIndex <= middleIndex) {
        aux[auxIndex] = array[leftIndex++];
        auxIndex++;
    }

    // setting the rest of the right subarray
    while (rightIndex <= right) {
        aux[auxIndex] = array[rightIndex++];
        auxIndex++;
    }
}

/*
    Implements the recursive Mergesort stable sorting algorithm for the struct pointer arrays.
 */
void _mergeSort(void **array, void **aux, int32_t left, int32_t right, int32_t (*compare)(const void *, const void *)) {
    if (left == right) {
        return;
    }

    // setting the middle index for splitting the specified array into subarrays
    int32_t middleIndex = (left + right) / 2;

    // sorting the left subarray recursively
    _mergeSort(array, aux, left, middleIndex, compare);
    // sorting the right subarray recursively
    _mergeSort(array, aux, middleIndex + 1, right, compare);
    // merging the sorted subarrays back into one array
    _merge(array, aux, left, right, compare);

    // setting the values from the auxilliary array into original array
    int32_t i;
    for (i = left; i <= right; i++) {
        array[i] = aux[i];
    }
}

/**
 * Prints a boolean value.
 *
 * @param ptr The allocated structure
 * @param b The boolean to be printed
 */
void printBool(PrintStream *ptr, bool b) {
    printf("%s", b ? "true" : "false");
    fflush(stdout);
}

/**
 * Prints a character.
 *
 * @param ptr The allocated structure
 * @param c The char to be printed
 */
void printC(PrintStream *ptr, char c) {
    printf("%c", c);
    fflush(stdout);
}

/**
 * Prints an array of characters.
 *
 * @param ptr The allocated structure
 * @param s The array of chars to be printed
 * @param length The array length
 */
void printS(PrintStream *ptr, char *s, int32_t length) {
    int i;
    for (i = 0; i < length; i++) {
        printf("%c", s[i]);
    }

    fflush(stdout);
}

/**
 * Prints a double-precision floating-point number.
 *
 * @param ptr The allocated structure
 * @param d The double to be printed
 */
void printD(PrintStream *ptr, double d) {
    printf("%lG", d);
    fflush(stdout);
}

/**
 * Prints a floating-point number.
 *
 * @param ptr The allocated structure
 * @param f The float to be printed
 */
void printF(PrintStream *ptr, float f) {
    printf("%G", f);
    fflush(stdout);
}

/**
 * Prints an integer.
 *
 * @param ptr The allocated structure
 * @param i The int to be printed
 */
void printI(PrintStream *ptr, int32_t i) {
    printf("%d", i);
    fflush(stdout);
}

/**
 * Prints a long integer.
 *
 * @param ptr The allocated structure
 * @param l The long to be printed
 */
void printL(PrintStream *ptr, int64_t l) {
    printf("%lld", l);
    fflush(stdout);
}

/**
 * Prints a structure.
 *
 * @param ptr The allocated structure
 * @param obj The structure to be printed
 * @param toString The structure toString function
 */
void printObj(PrintStream *ptr, void *obj, String *(*toString)(void *)) {
    String *s = toString(obj);
    printf("%s", s->s);
    delete_String(s);
    fflush(stdout);
}

/**
 * Prints a string.
 *
 * @param ptr The allocated structure
 * @param s The String to be printed
 */
void printStr(PrintStream *ptr, String *s) {
    printf("%s", s->s);
    fflush(stdout);
}

/**
 * Terminates the current line by writing the line separator string.
 *
 * @param ptr The allocated structure
 */
void println(PrintStream *ptr) {
    printf("\n");
    fflush(stdout);
}

/**
 * Prints a boolean and then terminate the line.
 *
 * @param ptr The allocated structure
 * @param x The boolean to be printed
 */
void printlnBool(PrintStream *ptr, bool x) {
    printf("%s\n", x ? "true" : "false");
    fflush(stdout);
}

/**
 * Prints a character and then terminate the line.
 *
 * @param ptr The allocated structure
 * @param x The char to be printed.
 */
void printlnC(PrintStream *ptr, char x) {
    printf("%c\n", x);
    fflush(stdout);
}

/**
 * Prints an array of characters and then terminate the line.
 *
 * @param ptr The allocated structure
 * @param x an array of chars to print.
 * @param length The array length
 */
void printlnS(PrintStream *ptr, char *x, int32_t length) {
    int i;
    for (i = 0; i < length; i++) {
        printf("%c", x[i]);
    }

    printf("\n");
    fflush(stdout);
}

/**
 * Prints a double and then terminate the line.
 *
 * @param ptr The allocated structure
 * @param x The double to be printed.
 */
void printlnD(PrintStream *ptr, double x) {
    printf("%lG\n", x);
    fflush(stdout);
}

/**
 * Prints a float and then terminate the line.
 *
 * @param ptr The allocated structure
 * @param x The float to be printed.
 */
void printlnF(PrintStream *ptr, float x) {
    printf("%G\n", x);
    fflush(stdout);
}

/**
 * Prints an integer and then terminate the line.
 *
 * @param ptr The allocated structure
 * @param x The int to be printed.
 */
void printlnI(PrintStream *ptr, int32_t x) {
    printf("%d\n", x);
    fflush(stdout);
}

/**
 * Prints a long and then terminate the line.
 *
 * @param ptr The allocated structure
 * @param x The long to be printed.
 */
void printlnL(PrintStream *ptr, int64_t x) {
    printf("%lld\n", x);
    fflush(stdout);
}

/**
 * Prints a structure and then terminate the line.
 *
 * @param ptr The allocated structure
 * @param x The structure to be printed.
 * @param toString The structure toString function
 */
void printlnObj(PrintStream *ptr, void *obj, String *(*toString)(void *)) {
    String *s = toString(obj);
    printf("%s\n", s->s);
    delete_String(s);
    fflush(stdout);
}

/**
 * Prints a String and then terminate the line.
 *
 * @param ptr The allocated structure
 * @param x The String to be printed.
 */
void printlnStr(PrintStream *ptr, String *x) {
    printf("%s\n", x->s);
    fflush(stdout);
}

InputStream sysIn;
InputStream *System_in = &sysIn;
PrintStream sysOut;
PrintStream *System_out = &sysOut;