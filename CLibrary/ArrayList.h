#ifndef ARRAYLIST_INCLUDED
#define	ARRAYLIST_INCLUDED

#include "String.h"
#include <stdbool.h>
#include <stdint.h>

/**
 * Resizable-array implementation of the List interface.
 *
 * @author Petr Kozler (A13B0359P)
 */

typedef struct {
    int32_t count;
    int32_t capacity;
    void **dynamicArray;
} ArrayList;

ArrayList *new_ArrayList();
ArrayList *new_ArrayListAddAll(ArrayList *c);
void delete_ArrayList(ArrayList *ptr);
bool addAl(ArrayList *ptr, void *e);
void addAtAl(ArrayList *ptr, int32_t index, void *element);
void *getAl(ArrayList *ptr, int32_t index);
void *setAl(ArrayList *ptr, int32_t index, void *element);
void *removeAl(ArrayList *ptr, int32_t index);
int32_t sizeAl(ArrayList *ptr);
bool isEmptyAl(ArrayList *ptr);
void clearAl(ArrayList *ptr);
String *toStringAl(ArrayList *ptr, String *(*toString)(void *));

#endif	/* ARRAYLIST_INCLUDED */

