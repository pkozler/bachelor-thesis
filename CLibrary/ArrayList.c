#include "ArrayList.h"

#include <stdlib.h>
#include <string.h>

#define _DEFAULT_CAPACITY 10
#define _RESIZE_COEF 2
#define _LIST_DELIM_STRLEN 2

ArrayList *new_ArrayList() {
    // alokace paměti pro strukturu seznamu a vnitřní pole ukazatelů
    ArrayList *list = malloc(sizeof(ArrayList));
    list->count = 0;
    list->capacity = _DEFAULT_CAPACITY;
    list->dynamicArray = malloc(list->capacity * sizeof(void *));

    return list;
}

ArrayList *new_ArrayListAddAll(ArrayList *c) {
    ArrayList *list = malloc(sizeof(ArrayList));
    list->count = c->count;
    list->capacity = c->capacity;
    list->dynamicArray = malloc(list->capacity * sizeof(void *));

    int i;
    for (i = 0; i < list->count; i++) {
        list->dynamicArray[i] = c->dynamicArray[i];
    }

    return list;
}

void delete_ArrayList(ArrayList *ptr) {
    // uvolnění paměti pro strukturu seznamu a vnitřní pole
    free(ptr->dynamicArray);
    free(ptr);
}

void _expandList(ArrayList *ptr) {
    ptr->count++;

    // zvětšení kapacity pole, pokud počet prvků dosáhl stávající kapacity
    if (ptr->count == ptr->capacity) {
        ptr->capacity *= _RESIZE_COEF;
        ptr->dynamicArray = realloc(ptr->dynamicArray, ptr->capacity);
    }
}

void _shrinkList(ArrayList *ptr) {
    ptr->count--;

    // zmenšení kapacity pole, pokud počet prvků dosáhl méně než poloviny kapacity a ta je větší než počáteční
    if (ptr->count < ptr->capacity / _RESIZE_COEF
        && ptr->capacity >=  _DEFAULT_CAPACITY * _RESIZE_COEF) {
        ptr->capacity /= _RESIZE_COEF;
        ptr->dynamicArray = realloc(ptr->dynamicArray, ptr->capacity);
    }
}

bool add(ArrayList *ptr, void *e) {
    ptr->dynamicArray[ptr->count] = e;
    _expandList(ptr);

    return true;
}

void addAt(ArrayList *ptr, int index, void *element) {
    int i;

    // přesun prvků od požadovaného indexu o jednu pozici dále
    for (i = ptr->count; i > index; i--) {
        ptr->dynamicArray[i] = ptr->dynamicArray[i - 1];
    }

    // vložení nového prvku na požadovaný index
    ptr->dynamicArray[index] = element;
    _expandList(ptr);
}

void *get(ArrayList *ptr, int index) {
    return ptr->dynamicArray[index];
}

void *set(ArrayList *ptr, int index, void *element) {
    void *original = ptr->dynamicArray[index];
    // nastavení nového prvku
    ptr->dynamicArray[index] = element;

    return original;
}

void *removeAt(ArrayList *ptr, int index) {
    void *removed = ptr->dynamicArray[index];
    int i;

    // přesun prvků za indexem o jednu pozici k počátku seznamu
    for (i = index; i < ptr->count - 1; i++) {
        ptr->dynamicArray[i] = ptr->dynamicArray[i + 1];
    }

    _shrinkList(ptr);
    return removed;
}

int size(ArrayList *ptr) {
    return ptr->count;
}

bool isEmpty(ArrayList *ptr) {
    return (ptr->count == 0);
}

void clear(ArrayList *ptr) {
    // uvolnění paměti pro vnitřní pole
    free(ptr->dynamicArray);

    // nastavení počátečních hodnot seznamu a opětovná alokace
    ptr->count = 0;
    ptr->capacity = _DEFAULT_CAPACITY;
    ptr->dynamicArray = malloc(ptr->capacity * sizeof(void *));
}

String *toStringAl(ArrayList *ptr, int size, char *(*toString)(void *)) {
    void **a = ptr->dynamicArray;
    int length = ptr->count;
    char *s = malloc((size + _LIST_DELIM_STRLEN) * length + 1);
    int i;
    s[0] = '\0';
    strcat(s, "[");

    if (length > 0) {
        strcat(s, toString(a[0]));
    }

    for (i = 1; i < length; i++) {
        strcat(s, ", ");
        strcat(s, toString(a[i]));
    }

    strcat(s, "]");

    return new_String(s);
}
