#ifndef COLLECTIONS_INCLUDED
#define	COLLECTIONS_INCLUDED

#include "ArrayList.h"
#include <algorithm>
#include <vector>

class Collections {
    Collections();
    ~Collections();
public:
    template <class T, class Comparator> static int binarySearch (ArrayList<T> *list, T key, Comparator c);
    template <class T> static void copy (ArrayList<T> *dest, ArrayList<T> *src);
    template <class T> static void fill (ArrayList<T> *list, T obj);
    template <class T, class Comparator> static void sort(ArrayList<T> *list, Comparator c);
};

template <class T, class Comparator> int binarySearch (ArrayList<T> *list, T key, Comparator c) {
    T *i = std::lower_bound(
        list->getVector().begin(), list->getVector().end(), key, c);

    if (i != list->getVector().end() && !(key < *i)) {
        return (int) (i - list->getVector().begin());
    }
    else {
        return -1;
    }
}

template <class T> void copy (ArrayList<T> *dest, ArrayList<T> *src) {
    std::vector<T> destList = dest->getVector();
    std::vector<T> srcList = src->getVector();

    for (int i = 0; i < srcList.size(); i++) {
        destList[i] = srcList[i];
    }
}

template <class T> void fill (ArrayList<T> *list, T obj) {
    std::vector<T> v = list->getVector();

    for (int i = 0; i < v.size(); i++) {
        v[i] = obj;
    }
}

template <class T, class Comparator> void Collections::sort(ArrayList<T> *list, Comparator c) {
    std::vector<T> v = list->getVector();
    std::stable_sort(v.begin(), v.end(), c);
}

#endif	// COLLECTIONS_INCLUDED

