#ifndef COLLECTIONS_INCLUDED
#define	COLLECTIONS_INCLUDED

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
    Collections();
    ~Collections();
public:
    template <class T, class Comparator> static int32_t binarySearch (ArrayList<T> *list, T key, Comparator c);
    template <class T> static void copy (ArrayList<T> *dest, ArrayList<T> *src);
    template <class T> static void fill (ArrayList<T> *list, T obj);
    template <class T, class Comparator> static void sort(ArrayList<T> *list, Comparator c);
};

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
template <class T, class Comparator> int32_t binarySearch (ArrayList<T> *list, T key, Comparator c) {
    T *i = std::lower_bound(
        list->getVector().begin(), list->getVector().end(), key, c);

    if (i != list->getVector().end() && !(key < *i)) {
        return (int32_t) (i - list->getVector().begin());
    }
    else {
        return -1;
    }
}

/**
 * Copies all of the elements from one list into another.
 *
 * @param dest The destination list.
 * @param src The source list.
 */
template <class T> void copy (ArrayList<T> *dest, ArrayList<T> *src) {
    std::vector<T> destList = dest->getVector();
    std::vector<T> srcList = src->getVector();

    for (int32_t i = 0; i < srcList.size(); i++) {
        destList[i] = srcList[i];
    }
}

/**
 * Replaces all of the elements of the specified list with the specified
 * element.
 *
 * @param list the list to be filled with the specified element.
 * @param obj The element with which to fill the specified list.
 */
template <class T> void fill (ArrayList<T> *list, T obj) {
    std::vector<T> v = list->getVector();

    for (int32_t i = 0; i < v.size(); i++) {
        v[i] = obj;
    }
}

/**
 * Sorts the specified list according to the order induced by the specified
 * comparator
 *
 * @param list the list to be sorted.
 * @param c the comparator to determine the order of the list. A null value
 * indicates that the elements' natural ordering should be used.
 */
template <class T, class Comparator> void Collections::sort(ArrayList<T> *list, Comparator c) {
    std::vector<T> v = list->getVector();
    std::stable_sort(v.begin(), v.end(), c);
}

#endif	// COLLECTIONS_INCLUDED

