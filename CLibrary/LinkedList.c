#include "LinkedList.h"

#include <stdlib.h>
#include <string.h>

#define _LLIST_DELIM_STRLEN 2

LinkedList *new_LinkedList() {
    LinkedList *list = malloc(sizeof(LinkedList));
    list->count = 0;
    list->first = NULL;
    list->last = NULL;

    return list;
}

LinkedList *new_LinkedListAddAll(LinkedList *c) {
    LinkedList *list = new_LinkedList();
    LinkedListNode *node = c->first;

    while (node != NULL) {
        addL(list, node->value);
        node = node->next;
    }

    return list;
}

void delete_LinkedList(LinkedList *ptr) {
    clearL(ptr);
    free(ptr);
}

void _addAfter(LinkedList *ptr, LinkedListNode *node, LinkedListNode *newNode) {
    newNode->previous = node;
    newNode->next = node->next;

    if (node->next == NULL) {
        ptr->last = newNode;
    }
    else {
        node->next->previous = newNode;
    }

    node->next = newNode;
}

void _addBefore(LinkedList *ptr, LinkedListNode *node, LinkedListNode *newNode) {
    newNode->previous = node->previous;
    newNode->next = node;

    if (node->previous == NULL) {
        ptr->first = newNode;
    }
    else {
        node->previous->next = newNode;
    }

    node->previous = newNode;
}

void _addFirst(LinkedList *ptr, LinkedListNode *newNode) {
    if (ptr->first == NULL) {
        ptr->first = newNode;
        ptr->last = newNode;
        newNode->previous = NULL;
        newNode->next = NULL;
    }
    else {
        _addBefore(ptr, ptr->first, newNode);
    }
}

void _addLast(LinkedList *ptr, LinkedListNode *newNode) {
    if (ptr->last == NULL) {
        _addFirst(ptr, newNode);
    }
    else {
        _addAfter(ptr, ptr->last, newNode);
    }
}

void _removeNode(LinkedList *ptr, LinkedListNode *node) {
    if (node->previous == NULL) {
        ptr->first = node->next;
    }
    else {
        node->previous->next = node->next;
    }

    if (node->next == NULL) {
        ptr->last = node->previous;
    }
    else {
        node->next->previous = node->previous;
    }
}

bool addL(LinkedList *ptr, void *e) {
    LinkedListNode *newNode = malloc(sizeof(LinkedListNode));
    newNode->value = e;
    _addLast(ptr, newNode);
    ptr->count++;

    return true;
}

void addAtL(LinkedList *ptr, int32_t index, void *element) {
    LinkedListNode *newNode = malloc(sizeof(LinkedListNode));
    newNode->value = element;

    if (index < 1) {
        _addFirst(ptr, newNode);
    }
    else {
        LinkedListNode *node = ptr->first;

        int32_t i;
        for (i = 0; i < index; i++) {
            node = node->next;
        }

        _addBefore(ptr, node, newNode);
    }

    ptr->count++;
}

void *getL(LinkedList *ptr, int32_t index) {
    LinkedListNode *node = ptr->first;

    int32_t i;
    for (i = 0; i < index; i++) {
        node = node->next;
    }

    return node->value;
}

void *setL(LinkedList *ptr, int32_t index, void *element) {
    LinkedListNode *original;

    if (index < 1) {
        original = ptr->first->value;
        ptr->first->value = element;
    }
    else {
        LinkedListNode *node = ptr->first;

        int32_t i;
        for (i = 0; i < index; i++) {
            node = node->next;
        }

        original = node->value;
        node->value = element;
    }

    return original;
}

void *removeAtL(LinkedList *ptr, int32_t index) {
    LinkedListNode *removed;
    LinkedListNode *node;

    if (index < 1) {
        node = ptr->first;
        removed = node->value;
        _removeNode(ptr, node);
        free(node);
    }
    else {
        node = ptr->first;

        int32_t i;
        for (i = 0; i < index; i++) {
            node = node->next;
        }

        removed = node->value;
        _removeNode(ptr, node);
        free(node);
    }

    ptr->count--;

    return removed;
}

int32_t sizeL(LinkedList *ptr) {
    return ptr->count;
}

bool isEmptyL(LinkedList *ptr) {
    return (ptr->count == 0);
}

void clearL(LinkedList *ptr) {
    while (ptr->first != NULL) {
        removeAtL(ptr, 0);
    }
}

String *toStringLl(LinkedList *ptr, int32_t size, char *(*toString)(void *)) {
    int32_t length = ptr->count;
    char *s = malloc((size + _LLIST_DELIM_STRLEN) * length + 1);
    s[0] = '\0';
    strcat(s, "[");

    if (ptr->first != NULL) {
        LinkedListNode *node = ptr->first;
        strcat(s, toString(node->value));
        node = node->next;

        while (node != NULL) {
            strcat(s, ", ");
            strcat(s, toString(node->value));
            node = node->next;
        }
    }

    strcat(s, "]");
    String *str = new_String(s);

    return str;
}
