#include "Collections.h"

#include "System.h"
#include <stdlib.h>

int32_t Collections_binarySearch(ArrayList *list, void *key, int32_t (*c)(const void *, const void *)) {
    void *i = bsearch(key, list->dynamicArray, list->count, sizeof(void **), c);
    
    if (i == NULL) {
        return -1;
    }
    else {
        return (i - (void *) list->dynamicArray) / sizeof(void **);
    }
}

void Collections_copy(ArrayList *dest, ArrayList *src) {
    void **destList = dest->dynamicArray;
    void **srcList = src->dynamicArray;
    int32_t count = src->count;

    int32_t i;
    for (i = 0; i < count; i++) {
        destList[i] = srcList[i];
    }
}

void Collections_fill(ArrayList *list, void *obj) {
    void **l = list->dynamicArray;
    int32_t count = list->count;

    int32_t i;
    for (i = 0; i < count; i++) {
        l[i] = obj;
    }
}

void Collections_sort(ArrayList *list, int32_t (* c)(const void *, const void *)) {
    void **aux = malloc(sizeof(void *) * list->count);
    _mergeSort(list->dynamicArray, aux, 0, list->count - 1, c);
    free(aux);
}
