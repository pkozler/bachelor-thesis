#ifndef LIST_INCLUDED
#define LIST_INCLUDED

#include <stdbool.h>
#include <stdint.h>

/**
 * Functions, which are common for all types of lists.
 *
 * @author Petr Kozler (A13B0359P)
 */

bool equalsList(void *ptr, int32_t (*sizePtr)(void *), void *(*getPtr)(void *, int32_t), 
        void *o, int32_t (*sizeO)(void *), void *(*getO)(void *, int32_t), 
        bool (*equals)(const void *, const void *));

#endif	/* LIST_INCLUDED */

