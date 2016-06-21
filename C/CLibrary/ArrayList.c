#include "ArrayList.h"

#include "StringBuilder.h"
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

// initial capacity for the inner dynamically resized array
#define _DEFAULT_CAPACITY 10
// coefficient for increasing or decreasing the capacity of inner array
#define _RESIZE_COEF 2

/**
 * Constructs an empty list with an initial capacity of ten.
 */
ArrayList *new_ArrayList() {
    ArrayList *list = malloc(sizeof (ArrayList));
    list->count = 0;
    list->capacity = _DEFAULT_CAPACITY;
    // allocating the inner array to the default capacity
    list->dynamicArray = malloc(list->capacity * sizeof (void *));

    return list;
}

/**
 * Constructs a list containing the elements of the specified array list, in
 * the order they are returned by the iteration over the list.
 *
 * @param c the array list whose elements are to be placed into the specified list
 */
ArrayList *new_ArrayListAddAll(ArrayList *c) {
    ArrayList *list = malloc(sizeof (ArrayList));
    list->count = c->count;
    list->capacity = c->capacity;
    // allocating the inner array to the specified list capacity
    list->dynamicArray = malloc(list->capacity * sizeof(void *));

    // copying all elements from the specified list
    int32_t i;
    for (i = 0; i < list->count; i++) {
        list->dynamicArray[i] = c->dynamicArray[i];
    }

    return list;
}

/*
    Destructs the ArrayList.
 */
void delete_ArrayList(ArrayList *ptr) {
    clearAl(ptr);
    free(ptr);
}

/*
    Increases the capacity of the inner array if the element count
    reaches the current capacity.
 */
void _expandList(ArrayList *ptr) {
    ptr->count++;

    if (ptr->count == ptr->capacity) {
        ptr->capacity *= _RESIZE_COEF;
        // reallocating the memory (expanding the allocated memory by the resize coefficient)
        ptr->dynamicArray = realloc(ptr->dynamicArray, ptr->capacity * sizeof(void *));
    }
}

/*
    Decreases the capacity of the inner array if the element count reaches the half
    of the current capacity (and the current capacity is greater than the default capacity).
 */
void _shrinkList(ArrayList *ptr) {
    ptr->count--;

    if (ptr->count < ptr->capacity / _RESIZE_COEF
            && ptr->capacity >= _DEFAULT_CAPACITY * _RESIZE_COEF) {
        ptr->capacity /= _RESIZE_COEF;
        // reallocating the memory (shrinking the allocated memory by the resize coefficient)
        ptr->dynamicArray = realloc(ptr->dynamicArray, ptr->capacity * sizeof(void *));
    }
}

/**
 * Appends the specified element to the end of the specified list.
 *
 * @param ptr The allocated structure
 * @param e element to be appended to the specified list
 * @return true
 */
bool addAl(ArrayList *ptr, void *e) {
    // storing the element on the index specified by the current element count
    ptr->dynamicArray[ptr->count] = e;
    _expandList(ptr);

    return true;
}

/**
 * Inserts the specified element at the specified position in the specified list.
 *
 * @param ptr The allocated structure
 * @param index index at which the specified element is to be inserted
 * @param element element to be inserted
 */
void addAtAl(ArrayList *ptr, int32_t index, void *element) {
    int32_t i;

    // moving the elements with greater index than specified by 1 away from the beginning of array
    for (i = ptr->count; i > index; i--) {
        ptr->dynamicArray[i] = ptr->dynamicArray[i - 1];
    }

    // storing the element on the specified index
    ptr->dynamicArray[index] = element;
    _expandList(ptr);
}

/**
 * Returns the element at the specified position in the specified list.
 *
 * @param ptr The allocated structure
 * @param index index of the element to return
 * @return the element at the specified position in the specified list
 */
void *getAl(ArrayList *ptr, int32_t index) {
    return ptr->dynamicArray[index];
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
void *setAl(ArrayList *ptr, int32_t index, void *element) {
    void *original = ptr->dynamicArray[index];
    ptr->dynamicArray[index] = element;

    return original;
}

/**
 * Removes the element at the specified position in the specified list.
 *
 * @param ptr The allocated structure
 * @param index the index of the element to be removed
 * @return the element that was removed from the list
 */
void *removeAl(ArrayList *ptr, int32_t index) {
    void *removed = ptr->dynamicArray[index];
    int32_t i;

    // moving the elements with greater index than removed by 1 towards the beginning of array
    for (i = index; i < ptr->count - 1; i++) {
        ptr->dynamicArray[i] = ptr->dynamicArray[i + 1];
    }

    _shrinkList(ptr);
    return removed;
}

/**
 * Returns the number of elements in the specified list.
 *
 * @param ptr The allocated structure
 * @return the number of elements in the specified list
 */
int32_t sizeAl(ArrayList *ptr) {
    return ptr->count;
}

/**
 * Returns true if the specified list contains no elements.
 *
 * @param ptr The allocated structure
 * @return true if the specified list contains no elements
 */
bool isEmptyAl(ArrayList *ptr) {
    return (ptr->count == 0);
}

/**
 * Removes all of the elements from the specified list.
 *
 * @param ptr The allocated structure
 */
void clearAl(ArrayList *ptr) {
    free(ptr->dynamicArray);

    ptr->count = 0;
    ptr->capacity = _DEFAULT_CAPACITY;
    // allocating the array with the default capacity
    ptr->dynamicArray = malloc(ptr->capacity * sizeof (void *));
}

/**
 * Returns a string representation of the structure.
 *
 * @param ptr The allocated structure
 * @param toString The list element toString function
 * @return a string representation of the structure.
 */
String *toStringAl(ArrayList *ptr, String *(*toString)(void *)) {
    int32_t length = ptr->count;
    
    // create StringBuilder for appending the text
    StringBuilder *sb = new_StringBuilder();
    String *str = new_String("[");
    append(sb, str);
    delete_String(str);

    // append first element string representation
    if (length > 0) {
        str = ptr->dynamicArray[0] == NULL ? new_String("null") : toString(ptr->dynamicArray[0]);
        append(sb, str);
        delete_String(str);
    }
    
    // append another elements string representation
    int32_t i;
    for (i = 1; i < length; i++) {
        str = new_String(", ");
        append(sb, str);
        delete_String(str);
        str = ptr->dynamicArray[i] == NULL ? new_String("null") : toString(ptr->dynamicArray[i]);
        append(sb, str);
        delete_String(str);
    }

    // create Java-like string
    str = new_String("]");
    append(sb, str);
    delete_String(str);
    str = toStringSb(sb);
    delete_StringBuilder(sb);

    return str;
}
