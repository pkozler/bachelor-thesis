#include "Collections.h"

void *Collections::currentComparator = nullptr;

/*
 * methods for comparing the two specified values:
 */

int32_t Collections::compareObjI(Object *a, Object *b) {
    Comparable *x = ((Comparable *) a);
    Comparable *y = ((Comparable *) b);
    
    return x->compareTo(y);
}

int32_t Collections::compareObjCompI(Object *a, Object *b) {
    return ((Comparator *) currentComparator)->compare(a, b);
}

bool Collections::compareObj(Object *a, Object *b) {
    return compareObjI(a, b) < 0;
}

bool Collections::compareObjComp(Object *a, Object *b) {
    return compareObjCompI(a, b) < 0;
}
