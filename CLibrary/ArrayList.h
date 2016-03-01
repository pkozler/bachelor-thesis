#ifndef ARRAYLIST_INCLUDED
#define	ARRAYLIST_INCLUDED

#include "String.h"
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    int32_t count;
    int32_t capacity;
    void **dynamicArray;
} ArrayList;

ArrayList *new_ArrayList();
ArrayList *new_ArrayListAddAll(ArrayList *c);
void delete_ArrayList(ArrayList *ptr);
bool add(ArrayList *ptr, void *e);
void addAt(ArrayList *ptr, int32_t index, void *element);
void *get(ArrayList *ptr, int32_t index);
void *set(ArrayList *ptr, int32_t index, void *element);
void *removeAt(ArrayList *ptr, int32_t index);
int32_t size(ArrayList *ptr);
bool isEmpty(ArrayList *ptr);
void clear(ArrayList *ptr);
String *toStringAl(ArrayList *ptr, int32_t size, String *(*toString)(void *));

#endif	/* ARRAYLIST_INCLUDED */

