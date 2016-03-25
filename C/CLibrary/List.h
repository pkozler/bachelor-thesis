#ifndef LIST_INCLUDED
#define LIST_INCLUDED

#include <stdbool.h>
#include <stdint.h>

/**
 * An ordered collection (also known as a sequence).
 *
 * @author Petr Kozler (A13B0359P)
 */

bool equalsList(void *ptr, void *o, int32_t (*sizePtr)(void *), int32_t (*sizeO)(void *),
        void *(*getPtr)(void *, int32_t), void *(*getO)(void *, int32_t), bool (*equals)(const void *, const void *));

#endif	/* LIST_INCLUDED */

