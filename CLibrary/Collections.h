#ifndef COLLECTIONS_INCLUDED
#define	COLLECTIONS_INCLUDED

#include "ArrayList.h"

int Collections_binarySearch(ArrayList *list, void *key, int (*c)(const void *, const void *));
void Collections_copy (ArrayList *dest, ArrayList *src);
void Collections_fill (ArrayList *list, void *obj);
void Collections_sort(ArrayList *list, int (* c)(const void *, const void *));

#endif	/* COLLECTIONS_INCLUDED */

