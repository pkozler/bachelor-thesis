#include "StringBuilder.h"
#include "String.h"

#include <stdlib.h>

#define _STR_DEFAULT_CAPACITY 16
#define _STR_RESIZE_COEF 2

StringBuilder *new_StringBuilder() {
    StringBuilder *sb = (StringBuilder *) malloc(sizeof(StringBuilder));
    // inicializace vnitřního bufferu, nastavení počáteční kapacity a počtu znaků
    sb->count = 1;
    sb->capacity = _STR_DEFAULT_CAPACITY;
    sb->buffer = (char *) malloc(sb->capacity * sizeof(char));
    sb->buffer[0] = '\0';
    
    return sb;
}

void delete_StringBuilder(StringBuilder *ptr) {
    // uvolnění paměti pro strukturu builderu a vnitřní řetězec
    free(ptr->buffer);
    free(ptr);
}

StringBuilder *append(StringBuilder *ptr, String *str) {
    // zvětšení kapacity bufferu, pokud se nový řetězec nevejde (o dvojnásobek délky nového řetězce)
    if (ptr->count + str->len >= ptr->capacity) {
        ptr->capacity += str->len * _STR_RESIZE_COEF;
        ptr->buffer = realloc(ptr->buffer, ptr->capacity);
    }
    
    // připojení nového řetězce a přičtení počtu znaků
    strcat(ptr->buffer, str->s);
    ptr->count += str->len;
    
    return ptr;
}

String *toStringSb(StringBuilder *ptr) {
    return new_String(ptr->buffer);
}
