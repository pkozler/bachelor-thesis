#ifndef LINKEDLIST_INCLUDED
#define LINKEDLIST_INCLUDED

#include "String.h"
#include <list>
#include <cstdint>
#include <sstream>

/**
 * Doubly-linked list implementation of the List and Deque interfaces.
 *
 * @author Petr Kozler (A13B0359P)
 */
template <class E>
class LinkedList {
    std::list<E> l;
public:
    LinkedList();
    LinkedList(LinkedList<E> *c);
    ~LinkedList();
    std::list<E> getList();
    bool add(E e);
    void add(int32_t index, E element);
    E get(int32_t index);
    E set(int32_t index, E element);
    E remove(int32_t index);
    int32_t size();
    bool isEmpty();
    void clear();
    String *toString(String *(*toString)(E));
};

template <class E> std::ostream &operator<<(std::ostream &s, LinkedList<E> &obj);

/**
 * Constructs an empty list.
 */
template <class E> LinkedList<E>::LinkedList() {
    l;
}

/**
 * Constructs a list containing the elements of the specified collection, in
 * the order they are returned by the collection's iterator.
 *
 * @param c the collection whose elements are to be placed into this list
 */
template <class E> LinkedList<E>::LinkedList(LinkedList<E> *c) {
    l(c->l);
}

template <class E> LinkedList<E>::~LinkedList() {
    l.clear();
}

template <class E> std::list<E> LinkedList<E>::getList() {
    return l;
}

/**
 * Appends the specified element to the end of this list.
 *
 * @param e element to be appended to this list
 * @return true (as specified by Collection.add(E))
 */
template <class E> bool LinkedList<E>::add(E e) {
    l.push_back(e);

    return true;
}

/**
 * Inserts the specified element at the specified position in this list.
 *
 * @param index index at which the specified element is to be inserted
 * @param element element to be inserted
 */
template <class E> void LinkedList<E>::add(int32_t index, E element) {
    l.insert(index, element);
}

/**
 * Returns the element at the specified position in this list.
 *
 * @param index index of the element to return
 * @return the element at the specified position in this list
 */
template <class E> E LinkedList<E>::get(int32_t index) {
    auto it = l.begin();
    std::advance(it, index);

    return *it;
}

/**
 * Replaces the element at the specified position in this list with the
 * specified element.
 *
 * @param index index of the element to replace
 * @param element element to be stored at the specified position
 * @return the element previously at the specified position
 */
template <class E> E LinkedList<E>::set(int32_t index, E element) {
    E original;
    auto it = l.begin();
    std::advance(it, index);
    original = *it;
    *it = element;

    return original;
}

/**
 * Removes the element at the specified position in this list.
 *
 * @param index the index of the element to be removed
 * @return the element previously at the specified position
 */
template <class E> E LinkedList<E>::remove(int32_t index) {
    E removed;
    auto it = l.begin();
    std::advance(it, index);
    removed = *it;
    l.erase(index);

    return removed;
}

/**
 * Returns the number of elements in this list.
 *
 * @return the number of elements in this list
 */
template <class E> int32_t LinkedList<E>::size() {
    return l.size();
}

/**
 * Returns true if this list contains no elements.
 *
 * @return true if this list contains no elements
 */
template <class E> bool LinkedList<E>::isEmpty() {
    return l.empty();
}

/**
 * Removes all of the elements from this list.
 */
template <class E> void LinkedList<E>::clear() {
    l.clear();
}

/**
 * Returns a string representation of the object.
 *
 * @return a string representation of the object.
 */
template <class E> String *LinkedList<E>::toString(String *(*toString)(E)) {
    int32_t length = l.size();
    std::ostringstream oss("[");

    if (length > 0) {
        String *str = toString(l.begin());
        oss << str->toString();
        delete str;
    }

    for (int32_t i = 1; i < length; i++) {
        auto it = l.begin();
        std::advance(it, i);
        String *str = toString(it);
        oss << ", " << str->toString();
        delete str;
    }

    oss << "]";

    return new String(oss.str());
}

template <class E> std::ostream &operator<<(std::ostream &s, LinkedList<E> &obj) {
    return s << obj.toString()->toString().c_str();
}

#endif // LINKEDLIST_INCLUDED
