#ifndef LINKEDLIST_INCLUDED
#define LINKEDLIST_INCLUDED

#include "String.h"
#include <stdbool.h>
#include <stdint.h>

/**
 * Struct definition for the doubly-linked list implementation of the list data structure.
 *
 * @author Petr Kozler (A13B0359P)
 */

/*
    LinkedListNode structure represents the node in the doubly-linked list
    containing the element and the pointers to the next and the previous node in the list.
 */
typedef struct LINKED_LIST_NODE {
    // stored element
    void *value;
    // next node in the list
    struct LINKED_LIST_NODE *next;
    // previous node in the list
    struct LINKED_LIST_NODE *previous;
} LinkedListNode;

typedef struct {
    // list element count
    int32_t count;
    // first node in the list
    LinkedListNode *first;
    // last node in the list
    LinkedListNode *last;
} LinkedList;

LinkedList *new_LinkedList();
LinkedList *new_LinkedListAddAll(LinkedList *c);
void delete_LinkedList(LinkedList *ptr);
bool addLl(LinkedList *ptr, void *e);
void addAtLl(LinkedList *ptr, int32_t index, void *element);
void *getLl(LinkedList *ptr, int32_t index);
void *setLl(LinkedList *ptr, int32_t index, void *element);
void *removeLl(LinkedList *ptr, int32_t index);
int32_t sizeLl(LinkedList *ptr);
bool isEmptyLl(LinkedList *ptr);
void clearLl(LinkedList *ptr);
String *toStringLl(LinkedList *ptr, String *(*toString)(void *));

#endif /* LINKEDLIST_INCLUDED */
