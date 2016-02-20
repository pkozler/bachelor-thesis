#ifndef ARRAYLIST_INCLUDED
#define	ARRAYLIST_INCLUDED

#include "String.h"
#include <stdbool.h>

typedef struct {
    int count;
    int capacity;
    void **dynamicArray;
} ArrayList;

ArrayList *new_ArrayList();
ArrayList *new_ArrayListAddAll(ArrayList *c);
void delete_ArrayList(ArrayList *ptr);
bool add(ArrayList *ptr, void *e);
void addAt(ArrayList *ptr, int index, void *element);
void *get(ArrayList *ptr, int index);
void *set(ArrayList *ptr, int index, void *element);
void *removeAt(ArrayList *ptr, int index);
int size(ArrayList *ptr);
bool isEmpty(ArrayList *ptr);
void clear(ArrayList *ptr);
String *toStringAl(ArrayList *ptr, int size, char *(*toString)(void *));

#endif	/* ARRAYLIST_INCLUDED */

