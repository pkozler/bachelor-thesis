#ifndef COLLECTIONS_INCLUDED
#define	COLLECTIONS_INCLUDED

#include "ArrayList.h"
#include <stdint.h>

/**
 * This module consists exclusively of functions that operate on or return lists
 * or any other type of a non-built-in data structure.
 *
 * @author Petr Kozler (A13B0359P)
 */

int32_t Collections_binarySearch(ArrayList *list, void *key, int32_t (*c)(const void *, const void *));
void Collections_copy(void *dest, void *src, int32_t (*srcSize)(void *), 
        void *(*destSet)(void *, int32_t, void *), void *(*srcGet)(void *, int32_t));
void Collections_fill(void *list, void *obj, int32_t (*listSize)(void *), 
        void *(*listSet)(void *, int32_t, void *));
void Collections_sort(ArrayList *list, int32_t (* c)(const void *, const void *));

#endif	/* COLLECTIONS_INCLUDED */

