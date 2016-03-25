#ifndef LINKEDLIST_INCLUDED
#define LINKEDLIST_INCLUDED

#include "String.h"
#include <stdbool.h>
#include <stdint.h>

/**
 * Doubly-linked list implementation of the List and Deque interfaces.
 *
 * @author Petr Kozler (A13B0359P)
 */

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
