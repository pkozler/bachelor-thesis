#include "ArrayList.h"

#include "StringBuilder.h"
#include <stdlib.h>
#include <string.h>

#define _DEFAULT_CAPACITY 10
#define _RESIZE_COEF 2

ArrayList *new_ArrayList() {
    ArrayList *list = malloc(sizeof (ArrayList));
    list->count = 0;
    list->capacity = _DEFAULT_CAPACITY;
    list->dynamicArray = malloc(list->capacity * sizeof (void *));

    return list;
}

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
    free(ptr->dynamicArray);
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

bool add(ArrayList *ptr, void *e) {
    ptr->dynamicArray[ptr->count] = e;
    _expandList(ptr);

    return true;
}

void addAt(ArrayList *ptr, int32_t index, void *element) {
    int32_t i;

    for (i = ptr->count; i > index; i--) {
        ptr->dynamicArray[i] = ptr->dynamicArray[i - 1];
    }

    ptr->dynamicArray[index] = element;
    _expandList(ptr);
}

void *get(ArrayList *ptr, int32_t index) {
    return ptr->dynamicArray[index];
}

void *set(ArrayList *ptr, int32_t index, void *element) {
    void *original = ptr->dynamicArray[index];
    ptr->dynamicArray[index] = element;

    return original;
}

void *removeAt(ArrayList *ptr, int32_t index) {
    void *removed = ptr->dynamicArray[index];
    int32_t i;

    for (i = index; i < ptr->count - 1; i++) {
        ptr->dynamicArray[i] = ptr->dynamicArray[i + 1];
    }

    _shrinkList(ptr);
    return removed;
}

int32_t size(ArrayList *ptr) {
    return ptr->count;
}

bool isEmpty(ArrayList *ptr) {
    return (ptr->count == 0);
}

void clear(ArrayList *ptr) {
    free(ptr->dynamicArray);

    ptr->count = 0;
    ptr->capacity = _DEFAULT_CAPACITY;
    ptr->dynamicArray = malloc(ptr->capacity * sizeof (void *));
}

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
