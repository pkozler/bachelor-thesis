#include <stdlib.h>

#include "System.h"

void _merge(void **array, void **aux, int32_t left, int32_t right, int32_t (*compare)(const void *, const void *)) {
    int32_t middleIndex = (left + right) / 2;
    int32_t leftIndex = left;
    int32_t rightIndex = middleIndex + 1;
    int32_t auxIndex = left;

    while (leftIndex <= middleIndex && rightIndex <= right) {
        if (compare((void *) array[leftIndex], (void *) array[rightIndex]) <= 0) {
            aux[auxIndex] = array[leftIndex++];
        } else {
            aux[auxIndex] = array[rightIndex++];
        }

        auxIndex++;
    }

    while (leftIndex <= middleIndex) {
        aux[auxIndex] = array[leftIndex++];
        auxIndex++;
    }

    while (rightIndex <= right) {
        aux[auxIndex] = array[rightIndex++];
        auxIndex++;
    }
}

void _mergeSort(void **array, void **aux, int32_t left, int32_t right, int32_t (*compare)(const void *, const void *)) {
    if (left == right) {
        return;
    }

    int32_t middleIndex = (left + right) / 2;

    _mergeSort(array, aux, left, middleIndex, compare);
    _mergeSort(array, aux, middleIndex + 1, right, compare);
    _merge(array, aux, left, right, compare);

    int32_t i;
    for (i = left; i <= right; i++) {
        array[i] = aux[i];
    }
}

/**
 * Prints a boolean value.
 *
 * @param b The boolean to be printed
 */
void printB(PrintStream *ptr, bool b) {
    printf("%s", b ? "true" : "false");
}

/**
 * Prints a character.
 *
 * @param c The char to be printed
 */
void printC(PrintStream *ptr, char c) {
    printf("%c", c);
}

/**
 * Prints an array of characters.
 *
 * @param s The array of chars to be printed
 */
void printS(PrintStream *ptr, char *s) {
    printf("%s", s);
}

/**
 * Prints a double-precision floating-point number.
 *
 * @param d The double to be printed
 */
void printD(PrintStream *ptr, double d) {
    printf("%lf", d);
}

/**
 * Prints a floating-point number.
 *
 * @param f The float to be printed
 */
void printF(PrintStream *ptr, float f) {
    printf("%f", f);
}

/**
 * Prints an integer.
 *
 * @param i The int to be printed
 */
void printI(PrintStream *ptr, int32_t i) {
    printf("%d", i);
}

/**
 * Prints a long integer.
 *
 * @param l The long to be printed
 */
void printL(PrintStream *ptr, int64_t l) {
    printf("%lld", l);
}

/**
 * Prints an object.
 *
 * @param obj The Object to be printed
 */
void printObj(PrintStream *ptr, void *obj, String *(*toString)(void *)) {
    String *s = toString(obj);
    printf("%s", s->s);
    delete_String(s);
}

/**
 * Prints a string.
 *
 * @param s The String to be printed
 */
void printStr(PrintStream *ptr, String *s) {
    printf("%s", s->s);
}

/**
 * Terminates the current line by writing the line separator string.
 */
void println(PrintStream *ptr) {
    printf("\n");
}

/**
 * Prints a boolean and then terminate the line.
 *
 * @param x The boolean to be printed
 */
void printlnB(PrintStream *ptr, bool x) {
    printf("%s\n", x ? "true" : "false");
}

/**
 * Prints a character and then terminate the line.
 *
 * @param x The char to be printed.
 */
void printlnC(PrintStream *ptr, char x) {
    printf("%c\n", x);
}

/**
 * Prints an array of characters and then terminate the line.
 *
 * @param x an array of chars to print.
 */
void printlnS(PrintStream *ptr, char *x) {
    printf("%s\n", x);
}

/**
 * Prints a double and then terminate the line.
 *
 * @param x The double to be printed.
 */
void printlnD(PrintStream *ptr, double x) {
    printf("%lf\n", x);
}

/**
 * Prints a float and then terminate the line.
 *
 * @param x The float to be printed.
 */
void printlnF(PrintStream *ptr, float x) {
    printf("%f\n", x);
}

/**
 * Prints an integer and then terminate the line.
 *
 * @param x The int to be printed.
 */
void printlnI(PrintStream *ptr, int32_t x) {
    printf("%d\n", x);
}

/**
 * Prints a long and then terminate the line.
 *
 * @param x The long to be printed.
 */
void printlnL(PrintStream *ptr, int64_t x) {
    printf("%lld\n", x);
}

/**
 * Prints an Object and then terminate the line.
 *
 * @param x The Object to be printed.
 */
void printlnObj(PrintStream *ptr, void *obj, String *(*toString)(void *)) {
    String *s = toString(obj);
    printf("%s\n", s->s);
    delete_String(s);
}

/**
 * Prints a String and then terminate the line.
 *
 * @param x The String to be printed.
 */
void printlnStr(PrintStream *ptr, String *x) {
    printf("%s\n", x->s);
}

PrintStream sysout;

/**
 * The "standard" input stream.
 */
void *System_in = NULL;
/**
 * The "standard" output stream.
 */
PrintStream *System_out = &sysout;