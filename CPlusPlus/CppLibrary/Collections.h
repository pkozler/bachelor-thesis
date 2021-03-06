#ifndef COLLECTIONS_INCLUDED
#define	COLLECTIONS_INCLUDED

#include "List.h"
#include "ArrayList.h"
#include <algorithm>
#include <vector>
#include <cstdint>

/**
 * This class consists exclusively of static methods that operate on or return collections.
 *
 * @author Petr Kozler (A13B0359P)
 */
class Collections {
    // hack to make the Comparator compare function call work
    static void *currentComparator;
    static bool compareObj(Object *a, Object *b);
    static bool compareObjComp(Object *a, Object *b);
    static int32_t compareObjI(Object *a, Object *b);
    static int32_t compareObjCompI(Object *a, Object *b);
    template <class T> static int32_t binarySearchGeneric(ArrayList<T> *list, T *key, int32_t (*c)(Object *, Object *));
    template <class T> static void sortGeneric(ArrayList<T> *list, bool (*c)(Object *, Object *));
public:
    template <class T> static int32_t binarySearch (ArrayList<T> *list, T *key);
    template <class T> static int32_t binarySearch (ArrayList<T> *list, T *key, Comparator *c);
    template <class T> static void copy (List<T> *dest, List<T> *src);
    template <class T> static void fill (List<T> *list, T *obj);
    template <class T> static void sort(ArrayList<T> *list);
    template <class T> static void sort(ArrayList<T> *list, Comparator *c);
};

template <class T> int32_t Collections::binarySearchGeneric(ArrayList<T> *list, T *key, int32_t (*c)(Object *, Object *)) {
    // initial lower list position
    int32_t lower = 0;
    // initial upper list position
    int32_t upper = list->size() - 1;
    
    while (lower <= upper) {
        // middle list position
        int32_t middle = ((uint32_t)lower + (uint32_t)upper) >> 1;
        Object *middleValue = (Object *) list->get(middle);
        Object *k = (Object *) key;
        
        // middle list position is the new lower index if the key object is greater than middle value object
        if (c(middleValue, k) < 0) {
            lower = middle + 1;
        }
        // middle list position is the new upper index if the key object is greater than middle value object
        else if (c(middleValue, k) > 0) {
            upper = middle - 1;
        }
        // returning the element if middle list position object is equal to the key object
        else {
            return middle;
        }
    }
    
    // returning the negative list position if element not found
    return -(lower + 1);
}

template <class T> void Collections::sortGeneric(ArrayList<T> *list, bool (*c)(Object *, Object *)) {
    int32_t length = list->size();
    Object **a = new Object*[length];
    
    // copying the elements of the list to the auxilliary array - hack to make the sort function work
    for (int32_t i = 0; i < length; i++) {
        a[i] = ((Object *) list->get(i));
    }
    
    // sorting the elements using the stable sort
    std::stable_sort(a, a + length, c);
    
    // copying the elements from the the auxilliary array back to the list
    for (int32_t i = 0; i < length; i++) {
        list->set(i, (T *)a[i]);
    }
}

/**
 * Searches the specified list for the specified object using the binary
 * search algorithm.
 *
 * @param list the list to be searched.
 * @param key the key to be searched for.
 * @return the index of the search key, if it is contained in the list;
 * otherwise, (-(insertion point) - 1). The insertion point is defined as
 * the point at which the key would be inserted into the list: the index of
 * the first element greater than the key, or list.size() if all elements in
 * the list are less than the specified key. Note that this guarantees that
 * the return value will be >= 0 if and only if the key is found.
 */
template <class T> int32_t Collections::binarySearch (ArrayList<T> *list, T *key) {
    return binarySearchGeneric(list, key, compareObjI);
}

/**
 * Searches the specified list for the specified object using the binary
 * search algorithm.
 *
 * @param list the list to be searched.
 * @param key the key to be searched for.
 * @param c the comparator by which the list is ordered. A null value
 * indicates that the elements' natural ordering should be used.
 * @return the index of the search key, if it is contained in the list;
 * otherwise, (-(insertion point) - 1). The insertion point is defined as
 * the point at which the key would be inserted into the list: the index of
 * the first element greater than the key, or list.size() if all elements in
 * the list are less than the specified key. Note that this guarantees that
 * the return value will be >= 0 if and only if the key is found.
 */
template <class T> int32_t Collections::binarySearch (ArrayList<T> *list, T *key, Comparator *c) {
    // setting the comparator used by the specified comparison function
    currentComparator = c;
    return binarySearchGeneric(list, key, compareObjCompI);
}

/**
 * Copies all of the elements from one list into another.
 *
 * @param dest The destination list.
 * @param src The source list.
 */
template <class T> void Collections::copy (List<T> *dest, List<T> *src) {
    int32_t length = src->size();
    
    // replacing the elements of the destination list with the elements of the source list
    for (int32_t i = 0; i < length; i++) {
        dest->set(i, src->get(i));
    }
}

/**
 * Replaces all of the elements of the specified list with the specified
 * element.
 *
 * @param list the list to be filled with the specified element.
 * @param obj The element with which to fill the specified list.
 */
template <class T> void Collections::fill (List<T> *list, T *obj) {
    int32_t length = list->size();
    
    // replacing the elements of the list with the specified value
    for (int32_t i = 0; i < length; i++) {
        list->set(i, obj);
    }
}

/**
 * Sorts the specified list into ascending order, according to the natural
 * ordering of its elements.
 *
 * @param list the list to be sorted.
 */
template <class T> void Collections::sort(ArrayList<T> *list) {
    sortGeneric(list, compareObj);
}

/**
 * Sorts the specified list according to the order induced by the specified
 * comparator
 *
 * @param list the list to be sorted.
 * @param c the comparator to determine the order of the list. A null value
 * indicates that the elements' natural ordering should be used.
 */
template <class T> void Collections::sort(ArrayList<T> *list, Comparator *c) {
    // setting the comparator used by the specified comparison function
    currentComparator = c;
    sortGeneric(list, compareObjComp);
}

#endif	// COLLECTIONS_INCLUDED
