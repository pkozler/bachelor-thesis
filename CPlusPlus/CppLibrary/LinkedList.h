#ifndef LINKEDLIST_INCLUDED
#define LINKEDLIST_INCLUDED

#include "List.h"
#include "String_.h"
#include <list>
#include <cstdint>
#include <sstream>

/**
 * Doubly-linked list implementation of the List abstract class.
 *
 * @author Petr Kozler (A13B0359P)
 */
template <class E> class LinkedList : public List<E> {
    // inner list for storing the elements
    std::list<E *> l;
public:
    LinkedList();
    LinkedList(LinkedList<E> *c);
    ~LinkedList();
    bool add(E *e);
    void add(int32_t index, E *element);
    E *get(int32_t index);
    E *set(int32_t index, E *element);
    E *remove(int32_t index);
    int32_t size();
    void clear();
    String *toString();
};

/**
 * Constructs an empty list.
 */
template <class E> LinkedList<E>::LinkedList() {}

/**
 * Constructs a list containing the elements of the specified collection, in
 * the order they are returned by the collection's iterator.
 *
 * @param c the collection whose elements are to be placed into this list
 */
template <class E> LinkedList<E>::LinkedList(LinkedList<E> *c) {
    l = c->l;
}

/*
 Destructs a LinkedList.
 */
template <class E> LinkedList<E>::~LinkedList() {
    l.clear();
}

/**
 * Appends the specified element to the end of this list.
 *
 * @param e element to be appended to this list
 * @return true
 */
template <class E> bool LinkedList<E>::add(E *e) {
    l.push_back(e);

    return true;
}

/**
 * Inserts the specified element at the specified position in this list.
 *
 * @param index index at which the specified element is to be inserted
 * @param element element to be inserted
 */
template <class E> void LinkedList<E>::add(int32_t index, E *element) {
    auto it = l.begin();
    // moving to the specified index
    std::advance(it, index);
    l.insert(it, element);
}

/**
 * Returns the element at the specified position in this list.
 *
 * @param index index of the element to return
 * @return the element at the specified position in this list
 */
template <class E> E *LinkedList<E>::get(int32_t index) {
    auto it = l.begin();
    // moving to the specified index
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
template <class E> E *LinkedList<E>::set(int32_t index, E *element) {
    E *original;
    auto it = l.begin();
    // moving to the specified index
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
template <class E> E *LinkedList<E>::remove(int32_t index) {
    E *removed;
    auto it = l.begin();
    // moving to the specified index
    std::advance(it, index);
    removed = *it;
    l.erase(it);

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
template <class E> String *LinkedList<E>::toString() {
    int32_t length = l.size();
    // create ostringstream for appending the text
    std::ostringstream oss("");
    oss << "[";

    // append first element string representation
    if (length > 0) {
        String *str = *l.begin() == nullptr ? new String("null") : ((Object *) *l.begin())->toString();
        oss << str->_s();
        delete str;
    }

    // append another elements string representation
    for (int32_t i = 1; i < length; i++) {
        auto it = l.begin();
        std::advance(it, i);
        String *str = *it == nullptr ? new String("null") : ((Object *) *it)->toString();
        oss << ", " << str->_s();
        delete str;
    }

    oss << "]";

    // create Java-like string
    return new String(oss.str());
}

#endif // LINKEDLIST_INCLUDED
