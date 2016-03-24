#include "ArrayList.h"

#include "StringBuilder.h"
#include <stdlib.h>
#include <string.h>

#define _DEFAULT_CAPACITY 10
#define _RESIZE_COEF 2

/**
 * Constructs an empty list with an initial capacity of ten.
 */
ArrayList *new_ArrayList() {
    ArrayList *list = malloc(sizeof (ArrayList));
    list->count = 0;
    list->capacity = _DEFAULT_CAPACITY;
    list->dynamicArray = malloc(list->capacity * sizeof (void *));

    return list;
}

/**
 * Constructs a list containing the elements of the specified collection, in
 * the order they are returned by the collection's iterator.
 *
 * @param c the collection whose elements are to be placed into this list
 */
ArrayList *new_ArrayListAddAll(ArrayList *c) {
    ArrayList *list = malloc(sizeof (ArrayList));
    list->count = c->count;
    list->capacity = c->capacity;
    list->dynamicArray = malloc(list->capacity * sizeof (void *));

    int32_t i;
    for (i = 0; i < list->count; i++) {
        list->dynamicArray[i] = c->dynamicArray[i];
    }

    return list;
}

void delete_ArrayList(ArrayList *ptr) {
    clearAl(ptr);
    free(ptr);
}

void _expandList(ArrayList *ptr) {
    ptr->count++;

    if (ptr->count == ptr->capacity) {
        ptr->capacity *= _RESIZE_COEF;
        ptr->dynamicArray = realloc(ptr->dynamicArray, ptr->capacity);
    }
}

void _shrinkList(ArrayList *ptr) {
    ptr->count--;

    if (ptr->count < ptr->capacity / _RESIZE_COEF
            && ptr->capacity >= _DEFAULT_CAPACITY * _RESIZE_COEF) {
        ptr->capacity /= _RESIZE_COEF;
        ptr->dynamicArray = realloc(ptr->dynamicArray, ptr->capacity);
    }
}

/**
 * Appends the specified element to the end of this list.
 *
 * @param e element to be appended to this list
 * @return true (as specified by Collection.add(E))
 */
bool addAl(ArrayList *ptr, void *e) {
    ptr->dynamicArray[ptr->count] = e;
    _expandList(ptr);

    return true;
}

/**
 * Inserts the specified element at the specified position in this list.
 *
 * @param index index at which the specified element is to be inserted
 * @param element element to be inserted
 */
void addAtAl(ArrayList *ptr, int32_t index, void *element) {
    int32_t i;

    for (i = ptr->count; i > index; i--) {
        ptr->dynamicArray[i] = ptr->dynamicArray[i - 1];
    }

    ptr->dynamicArray[index] = element;
    _expandList(ptr);
}

/**
 * Returns the element at the specified position in this list.
 *
 * @param index index of the element to return
 * @return the element at the specified position in this list
 */
void *getAl(ArrayList *ptr, int32_t index) {
    return ptr->dynamicArray[index];
}

/**
 * Replaces the element at the specified position in this list with the
 * specified element.
 *
 * @param index index of the element to replace
 * @param element element to be stored at the specified position
 * @return the element previously at the specified position
 */
void *setAl(ArrayList *ptr, int32_t index, void *element) {
    void *original = ptr->dynamicArray[index];
    ptr->dynamicArray[index] = element;

    return original;
}

/**
 * Removes the element at the specified position in this list.
 *
 * @param index the index of the element to be removed
 * @return the element that was removed from the list
 */
void *removeAl(ArrayList *ptr, int32_t index) {
    void *removed = ptr->dynamicArray[index];
    int32_t i;

    for (i = index; i < ptr->count - 1; i++) {
        ptr->dynamicArray[i] = ptr->dynamicArray[i + 1];
    }

    _shrinkList(ptr);
    return removed;
}

/**
 * Returns the number of elements in this list.
 *
 * @return the number of elements in this list
 */
int32_t sizeAl(ArrayList *ptr) {
    return ptr->count;
}

/**
 * Returns true if this list contains no elements.
 *
 * @return true if this list contains no elements
 */
bool isEmptyAl(ArrayList *ptr) {
    return (ptr->count == 0);
}

/**
 * Removes all of the elements from this list.
 */
void clearAl(ArrayList *ptr) {
    free(ptr->dynamicArray);

    ptr->count = 0;
    ptr->capacity = _DEFAULT_CAPACITY;
    ptr->dynamicArray = malloc(ptr->capacity * sizeof (void *));
}

/**
 * Returns a string representation of the object.
 *
 * @return a string representation of the object.
 */
String *toStringAl(ArrayList *ptr, String *(*toString)(void *)) {
    int32_t length = ptr->count;
    StringBuilder *sb = new_StringBuilder();
    String *str = new_String("[");
    append(sb, str);
    delete_String(str);

    if (length > 0) {
        str = toString(ptr->dynamicArray[0]);
        append(sb, str);
        delete_String(str);
    }

    int32_t i;
    for (i = 1; i < length; i++) {
        str = new_String(", ");
        append(sb, str);
        delete_String(str);
        str = toString(ptr->dynamicArray[i]);
        append(sb, str);
        delete_String(str);
    }

    str = new_String("]");
    append(sb, str);
    delete_String(str);
    str = toStringSb(sb);
    delete_StringBuilder(sb);

    return str;
}
