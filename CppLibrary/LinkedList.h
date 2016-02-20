#ifndef LINKEDLIST_INCLUDED
#define LINKEDLIST_INCLUDED

#include <list>
#include "String.h"

template <class E>
class LinkedList {
    std::list<E> l;
public:
    LinkedList();
    LinkedList(LinkedList<E> *c);
    ~LinkedList();
    std::list<E> getList();
    bool add(E e);
    void add(int index, E element);
    E get(int index);
    E set(int index, E element);
    E remove(int index);
    int size();
    bool isEmpty();
    void clear();
    String *toString();
    friend std::ostream &operator<<(std::ostream &s, LinkedList<E> &obj);
};

template <class E> LinkedList<E>::LinkedList() {
    l;
}

template <class E> LinkedList<E>::LinkedList(LinkedList<E> *c) {
    l(c->l);
}

template <class E> LinkedList<E>::~LinkedList() {
    l.clear();
}

template <class E> std::list<E> LinkedList<E>::getList() {
    return l;
}

template <class E> bool LinkedList<E>::add(E e) {
    l.push_back(e);

    return true;
}

template <class E> void LinkedList<E>::add(int index, E element) {
    l.insert(index, element);
}

template <class E> E LinkedList<E>::get(int index) {
    auto it = l.begin();
    std::advance(it, index);

    return *it;
}

template <class E> E LinkedList<E>::set(int index, E element) {
    E original;
    auto it = l.begin();
    std::advance(it, index);
    original = *it;
    *it = element;

    return original;
}

template <class E> E LinkedList<E>::remove(int index) {
    E removed;
    auto it = l.begin();
    std::advance(it, index);
    removed = *it;
    l.erase(index);

    return removed;
}

template <class E> int LinkedList<E>::size() {
    return l.size();
}

template <class E> bool LinkedList<E>::isEmpty() {
    return l.empty();
}

template <class E> void LinkedList<E>::clear() {
    l.clear();
}

template <class E> String *LinkedList<E>::toString() {
    std::string s = "[";
    int len = l.size();

    if (len > 0) {
        s += l.begin().toString();
    }

    for (int i = 1; i < len; i++) {
        auto it = l.begin();
        std::advance(it, i);
        s += ", " + it.toString();
    }

    s += "]";

    return s;
}

template <class E> std::ostream &operator<<(std::ostream &s, LinkedList<E> &obj) {
    return s << obj.toString()->toString().c_str();
}

#endif // LINKEDLIST_INCLUDED
