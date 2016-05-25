#include "List.h"

#include <stddef.h>

/**
 * Compares the specified structure with this list for equality.
 *
 * @param o the structure to be compared for equality with this list
 * @return true if the specified structure is equal to this list
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