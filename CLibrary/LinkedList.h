#ifndef LINKEDLIST_INCLUDED
#define LINKEDLIST_INCLUDED

#include "String.h"
#include <stdbool.h>
#include <stdint.h>

typedef struct LINKED_LIST_NODE {
    void *value;
    struct LINKED_LIST_NODE *next;
    struct LINKED_LIST_NODE *previous;
} LinkedListNode;

typedef struct {
    int32_t count;
    LinkedListNode *first;
    LinkedListNode *last;
} LinkedList;

LinkedList *new_LinkedList();
LinkedList *new_LinkedListAddAll(LinkedList *c);
void delete_LinkedList(LinkedList *ptr);
bool addL(LinkedList *ptr, void *e);
void addAtL(LinkedList *ptr, int32_t index, void *element);
void *getL(LinkedList *ptr, int32_t index);
void *setL(LinkedList *ptr, int32_t index, void *element);
void *removeAtL(LinkedList *ptr, int32_t index);
int32_t sizeL(LinkedList *ptr);
bool isEmptyL(LinkedList *ptr);
void clearL(LinkedList *ptr);
String *toStringLl(LinkedList *ptr, String *(*toString)(void *));

#endif /* LINKEDLIST_INCLUDED */
