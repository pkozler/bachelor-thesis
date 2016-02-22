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

void System_out_printB(bool b) {
    printf("%s", b ? "true" : "false");
}

void System_out_printC(char c) {
    printf("%c", c);
}

void System_out_printS(char *s) {
    printf("%s", s);
}

void System_out_printD(double d) {
    printf("%lf", d);
}

void System_out_printF(float f) {
    printf("%f", f);
}

void System_out_printI(int32_t i) {
    printf("%d", i);
}

void System_out_printL(int64_t l) {
    printf("%lld", l);
}

void System_out_printStr(String *s) {
    printf("%s", s->s);
}

void System_out_println() {
    printf("\n");
}

void System_out_printlnB(bool b) {
    printf("%s\n", b ? "true" : "false");
}

void System_out_printlnC(char c) {
    printf("%c\n", c);
}

void System_out_printlnS(char *s) {
    printf("%s\n", s);
}

void System_out_printlnD(double d) {
    printf("%lf\n", d);
}

void System_out_printlnF(float f) {
    printf("%f\n", f);
}

void System_out_printlnI(int32_t i) {
    printf("%d\n", i);
}

void System_out_printlnL(int64_t l) {
    printf("%lld\n", l);
}

void System_out_printlnStr(String *s) {
    printf("%s\n", s->s);
}
