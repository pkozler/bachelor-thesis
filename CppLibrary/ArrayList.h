#ifndef ARRAYLIST_INCLUDED
#define	ARRAYLIST_INCLUDED

#include <vector>
#include "String.h"

template <class E>
class ArrayList {
    static const int DEFAULT_CAPACITY;
    std::vector<E> v;
public:
    ArrayList();
    ArrayList(ArrayList<E> *c);
    ~ArrayList();
    std::vector<E> getVector();
    bool add(E e);
    void add(int index, E element);
    E get(int index);
    E set(int index, E element);
    E remove(int index);
    int size();
    bool isEmpty();
    void clear();
    String *toString();
    friend std::ostream &operator<<(std::ostream &s, ArrayList<E> &obj);
};

template <class E> const int ArrayList<E>::DEFAULT_CAPACITY = 10;

template <class E> ArrayList<E>::ArrayList() {
    v(DEFAULT_CAPACITY);
}

template <class E> ArrayList<E>::ArrayList(ArrayList<E> *c) {
    v(c->v);
}

template <class E> ArrayList<E>::~ArrayList() {
    v.clear();
}

template <class E> std::vector<E> ArrayList<E>::getVector() {
    return v;
}

template <class E> bool ArrayList<E>::add(E e) {
    v.push_back(e);

    return true;
}

template <class E> void ArrayList<E>::add(int index, E element) {
    v[index] = element;
}

template <class E> E ArrayList<E>::get(int index) {
    return v[index];
}

template <class E> E ArrayList<E>::set(int index, E element) {
    E original = v[index];
    v[index] = element;

    return original;
}

template <class E> E ArrayList<E>::remove(int index) {
    E removed = v[index];
    v.erase(index);

    return removed;
}

template <class E> int ArrayList<E>::size() {
    return v.size();
}

template <class E> bool ArrayList<E>::isEmpty() {
    return v.empty();
}

template <class E> void ArrayList<E>::clear() {
    v.clear();
}

template <class E> String *ArrayList<E>::toString() {
    std::string s = "[";
    int len = v.size();

    if (len > 0) {
        s += v[0].toString();
    }

    for (int i = 1; i < len; i++) {
        s += ", " + v[i].toString();
    }

    s += "]";

    return s;
}

template <class E> std::ostream &operator<<(std::ostream &s, ArrayList<E> &obj) {
    return s << obj.toString()->toString().c_str();
}

#endif	// ARRAYLIST_INCLUDED
