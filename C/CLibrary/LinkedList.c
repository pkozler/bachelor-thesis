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
    // setting the empty nodes
    list->first = NULL;
    list->last = NULL;

    return list;
}

/**
 * Constructs a list containing the elements of the specified linked list, in
 * the order they are returned by the iteration over the list.
 *
 * @param c the linked list whose elements are to be placed into the specified list
 */
LinkedList *new_LinkedListAddAll(LinkedList *c) {
    LinkedList *list = new_LinkedList();
    LinkedListNode *node = c->first;

    // copying all elements from the specified list
    while (node != NULL) {
        addLl(list, node->value);
        node = node->next;
    }

    return list;
}

/*
    Destructs the LinkedList.
 */
void delete_LinkedList(LinkedList *ptr) {
    clearLl(ptr);
    free(ptr);
}

/*
    Adds the new node after the specified existing node in the list and updates the pointers.
 */
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

/*
    Adds the new node before the specified existing node in the list and updates the pointers.
 */
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

/*
    Adds the new node to the beginning of the list and updates the pointers.
 */
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

/*
    Adds the new node to the end of the list and updates the pointers.
 */
void _addLast(LinkedList *ptr, LinkedListNode *newNode) {
    if (ptr->last == NULL) {
        _addFirst(ptr, newNode);
    }
    else {
        _addAfter(ptr, ptr->last, newNode);
    }
}

/*
    Removes the specified existing node from the list and updates the pointers.
 */
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
 * Appends the specified element to the end of the specified list.
 *
 * @param ptr The allocated structure
 * @param e element to be appended to the specified list
 * @return true
 */
bool addLl(LinkedList *ptr, void *e) {
    // creating the node for storing the element
    LinkedListNode *newNode = malloc(sizeof(LinkedListNode));
    newNode->value = e;
    // adding as the last node of the list
    _addLast(ptr, newNode);
    ptr->count++;

    return true;
}

/**
 * Inserts the specified element at the specified position in the specified list.
 *
 * @param ptr The allocated structure
 * @param index index at which the specified element is to be inserted
 * @param element element to be inserted
 */
void addAtLl(LinkedList *ptr, int32_t index, void *element) {
    // creating the node for storing the element
    LinkedListNode *newNode = malloc(sizeof(LinkedListNode));
    newNode->value = element;
    
    // adding as the first node of the list if the list is currently empty
    if (ptr->count < 1) {
        _addFirst(ptr, newNode);
    }
    else {
        LinkedListNode *node = ptr->first;
    
        // adding before the first node of the list if the index is 0
        if (index < 1) {
            _addBefore(ptr, node, newNode);
        }
        else {
            
            int32_t i;
            for (i = 1; i < index; i++) {
                node = node->next;
            }

            // adding after the node found on the specified position, if the index is not 0
            _addAfter(ptr, node, newNode);
        }
    }
    
    ptr->count++;
}

/**
 * Returns the element at the specified position in the specified list.
 *
 * @param ptr The allocated structure
 * @param index index of the element to return
 * @return the element at the specified position in the specified list
 */
void *getLl(LinkedList *ptr, int32_t index) {
    LinkedListNode *node = ptr->first;

    // iterating over the list to the node on the specified position
    int32_t i;
    for (i = 0; i < index; i++) {
        node = node->next;
    }

    return node->value;
}

/**
 * Replaces the element at the specified position in the specified list with the
 * specified element.
 *
 * @param ptr The allocated structure
 * @param index index of the element to replace
 * @param element element to be stored at the specified position
 * @return the element previously at the specified position
 */
void *setLl(LinkedList *ptr, int32_t index, void *element) {
    LinkedListNode *original;

    // setting the first node if the index is 0
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

        // setting the node on the specified position
        original = node->value;
        node->value = element;
    }

    return original;
}

/**
 * Removes the element at the specified position in the specified list.
 *
 * @param ptr The allocated structure
 * @param index the index of the element to be removed
 * @return the element previously at the specified position
 */
void *removeLl(LinkedList *ptr, int32_t index) {
    LinkedListNode *removed;
    LinkedListNode *node;

    // removing the first node if the index is 0
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

        // removing the node on the specified position
        removed = node->value;
        _removeNode(ptr, node);
        free(node);
    }

    ptr->count--;

    return removed;
}

/**
 * Returns the number of elements in the specified list.
 *
 * @param ptr The allocated structure
 * @return the number of elements in the specified list
 */
int32_t sizeLl(LinkedList *ptr) {
    return ptr->count;
}

/**
 * Returns true if the specified list contains no elements.
 *
 * @param ptr The allocated structure
 * @return true if the specified list contains no elements
 */
bool isEmptyLl(LinkedList *ptr) {
    return (ptr->count == 0);
}

/**
 * Removes all of the elements from the specified list.
 *
 * @param ptr The allocated structure
 */
void clearLl(LinkedList *ptr) {
    LinkedListNode *node;
    ptr->count = 0;

    // deallocating the memory of the each list node after removing it
    while (ptr->first != NULL) {
        node = ptr->first;
        _removeNode(ptr, node);
        free(node);
    }
}

/**
 * Returns a string representation of the structure.
 *
 * @param ptr The allocated structure
 * @param toString The list element toString function
 * @return a string representation of the structure.
 */
String *toStringLl(LinkedList *ptr, String *(*toString)(void *)) {
    // create StringBuilder for appending the text
    StringBuilder *sb = new_StringBuilder();
    String *str = new_String("[");
    append(sb, str);
    delete_String(str);
    LinkedListNode *node = ptr->first;

    // append first element string representation
    if (node != NULL) {
        str = node->value == NULL ? new_String("null") : toString(node->value);
        append(sb, str);
        delete_String(str);
        node = node->next;
    }

    // append another elements string representation
    while (node != NULL) {
        str = new_String(", ");
        append(sb, str);
        delete_String(str);
        str = node->value == NULL ? new_String("null") : toString(node->value);
        append(sb, str);
        delete_String(str);
        node = node->next;
    }

    // create Java-like string
    str = new_String("]");
    append(sb, str);
    delete_String(str);
    str = toStringSb(sb);
    delete_StringBuilder(sb);

    return str;
}
