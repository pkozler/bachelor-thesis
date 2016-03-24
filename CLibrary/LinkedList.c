#include "LinkedList.h"

#include "StringBuilder.h"
#include <stdlib.h>
#include <string.h>

/**
 * Constructs an empty list.
 */
LinkedList *new_LinkedList() {
    LinkedList *list = malloc(sizeof(LinkedList));
    list->count = 0;
    list->first = NULL;
    list->last = NULL;

    return list;
}

/**
 * Constructs a list containing the elements of the specified collection, in
 * the order they are returned by the collection's iterator.
 *
 * @param c the collection whose elements are to be placed into this list
 */
LinkedList *new_LinkedListAddAll(LinkedList *c) {
    LinkedList *list = new_LinkedList();
    LinkedListNode *node = c->first;

    while (node != NULL) {
        addLl(list, node->value);
        node = node->next;
    }

    return list;
}

void delete_LinkedList(LinkedList *ptr) {
    clearLl(ptr);
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

/**
 * Appends the specified element to the end of this list.
 *
 * @param e element to be appended to this list
 * @return true (as specified by Collection.add(E))
 */
bool addLl(LinkedList *ptr, void *e) {
    LinkedListNode *newNode = malloc(sizeof(LinkedListNode));
    newNode->value = e;
    _addLast(ptr, newNode);
    ptr->count++;

    return true;
}

/**
 * Inserts the specified element at the specified position in this list.
 *
 * @param index index at which the specified element is to be inserted
 * @param element element to be inserted
 */
void addAtLl(LinkedList *ptr, int32_t index, void *element) {
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

/**
 * Returns the element at the specified position in this list.
 *
 * @param index index of the element to return
 * @return the element at the specified position in this list
 */
void *getLl(LinkedList *ptr, int32_t index) {
    LinkedListNode *node = ptr->first;

    int32_t i;
    for (i = 0; i < index; i++) {
        node = node->next;
    }

    return node->value;
}

/**
 * Replaces the element at the specified position in this list with the
 * specified element.
 *
 * @param index index of the element to replace
 * @param element element to be stored at the specified position
 * @return the element previously at the specified position
 */
void *setLl(LinkedList *ptr, int32_t index, void *element) {
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

/**
 * Removes the element at the specified position in this list.
 *
 * @param index the index of the element to be removed
 * @return the element previously at the specified position
 */
void *removeLl(LinkedList *ptr, int32_t index) {
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

/**
 * Returns the number of elements in this list.
 *
 * @return the number of elements in this list
 */
int32_t sizeLl(LinkedList *ptr) {
    return ptr->count;
}

/**
 * Returns true if this list contains no elements.
 *
 * @return true if this list contains no elements
 */
bool isEmptyLl(LinkedList *ptr) {
    return (ptr->count == 0);
}

/**
 * Removes all of the elements from this list.
 */
void clearLl(LinkedList *ptr) {
    LinkedListNode *node;
    
    while (ptr->first != NULL) {
        node = ptr->first;
        _removeNode(ptr, node);
        free(node);
    }
}

/**
 * Returns a string representation of the object.
 *
 * @return a string representation of the object.
 */
String *toStringLl(LinkedList *ptr, String *(*toString)(void *)) {
    StringBuilder *sb = new_StringBuilder();
    String *str = new_String("[");
    append(sb, str);
    delete_String(str);
    LinkedListNode *node = ptr->first;
    
    if (node != NULL) {
        str = toString(node->value);
        append(sb, str);
        delete_String(str);
        node = node->next;
    }

    while (node != NULL) {
        str = new_String(", ");
        append(sb, str);
        delete_String(str);
        str = toString(node->value);
        append(sb, str);
        delete_String(str);
        node = node->next;
    }

    str = new_String("]");
    append(sb, str);
    delete_String(str);
    str = toStringSb(sb);
    delete_StringBuilder(sb);

    return str;
}
