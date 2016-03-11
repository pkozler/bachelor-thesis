#include "Collections.h"

#include "System.h"
#include <stdlib.h>

/**
 * Searches the specified list for the specified object using the binary
 * search algorithm.
 *
 * @param list the list to be searched.
 * @param key the key to be searched for.
 * @return the index of the search key, if it is contained in the list;
 * otherwise, (-(insertion point) - 1). The insertion point is defined as
 * the point at which the key would be inserted into the list: the index of
 * the first element greater than the key, or list.size() if all elements in
 * the list are less than the specified key. Note that this guarantees that
 * the return value will be >= 0 if and only if the key is found.
 */
int32_t Collections_binarySearch(ArrayList *list, void *key, int32_t (*c)(const void *, const void *)) {
    void *i = bsearch(key, list->dynamicArray, list->count, sizeof(void **), c);
    
    if (i == NULL) {
        return -1;
    }
    else {
        return (i - (void *) list->dynamicArray) / sizeof(void **);
    }
}

/**
 * Copies all of the elements from one list into another.
 *
 * @param dest The destination list.
 * @param src The source list.
 */
void Collections_copy(ArrayList *dest, ArrayList *src) {
    void **destList = dest->dynamicArray;
    void **srcList = src->dynamicArray;
    int32_t count = src->count;

    int32_t i;
    for (i = 0; i < count; i++) {
        destList[i] = srcList[i];
    }
}

/**
 * Replaces all of the elements of the specified list with the specified
 * element.
 *
 * @param list the list to be filled with the specified element.
 * @param obj The element with which to fill the specified list.
 */
void Collections_fill(ArrayList *list, void *obj) {
    void **l = list->dynamicArray;
    int32_t count = list->count;

    int32_t i;
    for (i = 0; i < count; i++) {
        l[i] = obj;
    }
}

/**
 * Sorts the specified list into ascending order, according to the natural
 * ordering of its elements.
 *
 * @param list the list to be sorted.
 */
void Collections_sort(ArrayList *list, int32_t (* c)(const void *, const void *)) {
    void **aux = malloc(sizeof(void *) * list->count);
    _mergeSort(list->dynamicArray, aux, 0, list->count - 1, c);
    free(aux);
}
