#include "List.h"

#include <stddef.h>

/**
 * Compares the one specified list with another for equality.
 *
 * @param ptr The one list to be compared for equality
 * @param sizePtr The list size function
 * @param getPtr The list get function
 * @param o The other list to be compared for equality
 * @param sizeO The other list size function
 * @param getO The other list get function
 * @param equals The list element equals function
 * @return true if the one specified list is equal to the other
 */
bool equalsList(void *ptr, int32_t (*sizePtr)(void *), void *(*getPtr)(void *, int32_t), 
        void *o, int32_t (*sizeO)(void *), void *(*getO)(void *, int32_t), 
        bool (*equals)(const void *, const void *)) {
    if (ptr == o) {
        return true;
    }
    
    if (o == NULL) {
        return false;
    }
    
    int length = sizePtr(ptr);
    
    if (sizeO(o) != length) {
        return false;
    }
    
    int i;
    for (i = 0; i < length; i++) {
        void *o1 = getPtr(ptr, i);
        void *o2 = getO(o, i);
        bool e = o1 == NULL ? o2 == NULL : equals(o1, o2);
        
        if (!e) {
            return false;
        }
    }
    
    return true;
}