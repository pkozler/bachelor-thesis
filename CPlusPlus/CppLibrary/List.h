#ifndef LIST_INCLUDED
#define LIST_INCLUDED

#include "String_.h"
#include <string>
#include "System.h"

/**
 * An ordered collection (also known as a sequence).
 *
 * @param E the type of elements in this list
 * @author Petr Kozler (A13B0359P)
 */
template <class E> class List : public Object {
public:
    virtual bool add(E *e) = 0;
    virtual void add(int32_t index, E *element) = 0;
    bool equals(Object *o);
    virtual E *get(int32_t index) = 0;
    virtual E *set(int32_t index, E *element) = 0;
    virtual E *remove(int32_t index) = 0;
    virtual int32_t size() = 0;
    virtual bool isEmpty();
    virtual void clear() = 0;
    virtual String *toString() = 0;
};

/**
 * Compares the specified object with this list for equality.
 *
 * @param o the object to be compared for equality with this list
 * @return true if the specified object is equal to this list
 */
template <class E> bool List<E>::equals(Object *o) {
    // comparing pointers
    if (this == o) {
        return true;
    }

    // testing the pointer for a NULL value
    if (o == nullptr) {
        return false;
    }

    List<E> *other = (List<E> *) o;
    int32_t length = size();

    // comparing the list sizes
    if (other->size() != length) {
        return false;
    }
    
    int32_t i;
    // comparing the corresponding elements of the lists
    for (i = 0; i < length; i++) {
        Object *o1 = (Object *) get(i);
        Object *o2 = (Object *) other->get(i);
        
        bool equals = o1 == nullptr ? o2 == nullptr : o1->equals(o2);

        if (!equals) {
            return false;
        }
    }

    return true;
}

/**
 * Returns true if this list contains no elements.
 *
 * @return true if this list contains no elements
 */
template <class E> bool List<E>::isEmpty() {
    return size() == 0;
}

#endif	// LIST_INCLUDED
