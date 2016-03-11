#ifndef COLLECTIONS_INCLUDED
#define	COLLECTIONS_INCLUDED

#include "ArrayList.h"
#include <stdint.h>

/**
 * This class consists exclusively of static methods that operate on or return collections.
 *
 * @author Petr Kozler (A13B0359P)
 */

int32_t Collections_binarySearch(ArrayList *list, void *key, int32_t (*c)(const void *, const void *));
void Collections_copy (ArrayList *dest, ArrayList *src);
void Collections_fill (ArrayList *list, void *obj);
void Collections_sort(ArrayList *list, int32_t (* c)(const void *, const void *));

#endif	/* COLLECTIONS_INCLUDED */

