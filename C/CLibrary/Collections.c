#include "Collections.h"

#include "System.h"
#include <stdlib.h>

/**
 * Searches the specified list for the specified structure using the binary
 * search algorithm.
 *
 * @param list the list to be searched.
 * @param key the key to be searched for.
 * @param c The structure compare function
 * @return the index of the search key, if it is contained in the list;
 * otherwise, (-(insertion point) - 1). The insertion point is defined as
 * the point at which the key would be inserted into the list: the index of
 * the first element greater than the key, or list.size() if all elements in
 * the list are less than the specified key. Note that this guarantees that
 * the return value will be >= 0 if and only if the key is found.
 */
int32_t Collections_binarySearch(ArrayList *list, void *key, int32_t (*c)(const void *, const void *)) {
    int32_t lower = 0;
    int32_t upper = sizeAl(list) - 1;

    while (lower <= upper) {
        int32_t middle = ((uint32_t)lower + (uint32_t)upper) >> 1;
        
        void *o1 = getAl(list, middle);
        void *o2 = key;
        int32_t cmp = c(o1, o2);

        if (cmp < 0) {
            lower = middle + 1;
        }
        else if (cmp > 0) {
            upper = middle - 1;
        }
        else {
            return middle;
        }
    }

    return -(lower + 1);
}

/**
 * Copies all of the elements from one list into another.
 *
 * @param dest The destination list.
 * @param src The source list.
 * @param srcSize The source list size function.
 * @param destSet The destination list set function.
 * @param srcGet The source list get function.
 */
void Collections_copy(void *dest, void *src, int32_t (*srcSize)(void *),
        void *(*destSet)(void *, int32_t, void *), void *(*srcGet)(void *, int32_t)) {
    int32_t length = srcSize(src);

    int32_t i;
    for (i = 0; i < length; i++) {
        destSet(dest, i, srcGet(src, i));
    }
}

/**
 * Replaces all of the elements of the specified list with the specified
 * element.
 *
 * @param list the list to be filled with the specified element.
 * @param obj The element with which to fill the specified list.
 * @param listSize The list size function.
 * @param listSet The list set function.
 */
void Collections_fill(void *list, void *obj, int32_t (*listSize)(void *),
        void *(*listSet)(void *, int32_t, void *)) {
    int32_t length = listSize(list);

    int32_t i;
    for (i = 0; i < length; i++) {
        listSet(list, i, obj);
    }
}

/**
 * Sorts the specified list into ascending order, according to the natural
 * ordering of its elements.
 *
 * @param list the list to be sorted.
 * @param c The structure compare function
 */
void Collections_sort(ArrayList *list, int32_t (* c)(const void *, const void *)) {
    void **aux = malloc(sizeof(void *) * list->count);
    _mergeSort(list->dynamicArray, aux, 0, list->count - 1, c);
    free(aux);
}
