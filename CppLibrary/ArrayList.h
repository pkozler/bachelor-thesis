#ifndef ARRAYLIST_INCLUDED
#define	ARRAYLIST_INCLUDED

#include "List.h"
#include "String.h"
#include <vector>
#include <cstdint>
#include <sstream>

/**
 * Resizable-array implementation of the List interface.
 *
 * @author Petr Kozler (A13B0359P)
 */
template <class E> class ArrayList : public List<E> {
    static const int32_t DEFAULT_CAPACITY;
    std::vector<E *> v;
public:
    const std::vector<E> _v() const { return v; }
    ArrayList();
    ArrayList(ArrayList<E> *c);
    ~ArrayList();
    bool add(E *e);
    void add(int32_t index, E *element);
    E *get(int32_t index);
    E *set(int32_t index, E *element);
    E *remove(int32_t index);
    int32_t size();
    void clear();
    String *toString();
};

template <class E> const int32_t ArrayList<E>::DEFAULT_CAPACITY = 10;

/**
 * Constructs an empty list with an initial capacity of ten.
 */
template <class E> ArrayList<E>::ArrayList() {
    v(DEFAULT_CAPACITY);
}

/**
 * Constructs a list containing the elements of the specified collection, in
 * the order they are returned by the collection's iterator.
 *
 * @param c the collection whose elements are to be placed into this list
 */
template <class E> ArrayList<E>::ArrayList(ArrayList<E> *c) {
    v(c->v);
}

template <class E> ArrayList<E>::~ArrayList() {
    v.clear();
}

/**
 * Appends the specified element to the end of this list.
 *
 * @param e element to be appended to this list
 * @return true (as specified by Collection.add(E))
 */
template <class E> bool ArrayList<E>::add(E *e) {
    v.push_back(e);

    return true;
}

/**
 * Inserts the specified element at the specified position in this list.
 *
 * @param index index at which the specified element is to be inserted
 * @param element element to be inserted
 */
template <class E> void ArrayList<E>::add(int32_t index, E *element) {
    v[index] = element;
}

/**
 * Returns the element at the specified position in this list.
 *
 * @param index index of the element to return
 * @return the element at the specified position in this list
 */
template <class E> E *ArrayList<E>::get(int32_t index) {
    return v[index];
}

/**
 * Replaces the element at the specified position in this list with the
 * specified element.
 *
 * @param index index of the element to replace
 * @param element element to be stored at the specified position
 * @return the element previously at the specified position
 */
template <class E> E *ArrayList<E>::set(int32_t index, E *element) {
    E original = v[index];
    v[index] = element;

    return original;
}

/**
 * Removes the element at the specified position in this list.
 *
 * @param index the index of the element to be removed
 * @return the element that was removed from the list
 */
template <class E> E *ArrayList<E>::remove(int32_t index) {
    E removed = v[index];
    v.erase(index);

    return removed;
}

/**
 * Returns the number of elements in this list.
 *
 * @return the number of elements in this list
 */
template <class E> int32_t ArrayList<E>::size() {
    return v.size();
}

/**
 * Removes all of the elements from this list.
 */
template <class E> void ArrayList<E>::clear() {
    v.clear();
}

/**
 * Returns a string representation of the object.
 *
 * @return a string representation of the object.
 */
template <class E> String *ArrayList<E>::toString() {
    int32_t length = v.size();
    std::ostringstream oss("[");

    if (length > 0) {
        String *str = toString(v[0]);
        oss << str;
        delete str;
    }

    for (int32_t i = 1; i < length; i++) {
        String *str = toString(v[i]);
        oss << ", " << str;
        delete str;
    }

    oss << "]";

    return new String(oss.str());
}

#endif	// ARRAYLIST_INCLUDED
