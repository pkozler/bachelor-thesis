#ifndef LINKEDLIST_INCLUDED
#define LINKEDLIST_INCLUDED

#include "String.h"
#include <list>
#include <cstdint>

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

template <class E> void LinkedList<E>::add(int32_t index, E element) {
    l.insert(index, element);
}

template <class E> E LinkedList<E>::get(int32_t index) {
    auto it = l.begin();
    std::advance(it, index);

    return *it;
}

template <class E> E LinkedList<E>::set(int32_t index, E element) {
    E original;
    auto it = l.begin();
    std::advance(it, index);
    original = *it;
    *it = element;

    return original;
}

template <class E> E LinkedList<E>::remove(int32_t index) {
    E removed;
    auto it = l.begin();
    std::advance(it, index);
    removed = *it;
    l.erase(index);

    return removed;
}

template <class E> int32_t LinkedList<E>::size() {
    return l.size();
}

template <class E> bool LinkedList<E>::isEmpty() {
    return l.empty();
}

template <class E> void LinkedList<E>::clear() {
    l.clear();
}

template <class E> String *LinkedList<E>::toString(String *(*toString)(E)) {
    int32_t length = l.size();
    std::ostringstream oss("[");

    if (length > 0) {
        String *str = toString(l.begin())->toString();
        oss << str->toString();
        delete str;
    }

    for (int32_t i = 1; i < length; i++) {
        auto it = l.begin();
        std::advance(it, i);
        String *str = toString(it)->toString();
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
