#include "Boolean.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _MAX_BOOL_STRLEN 5

Boolean *new_Boolean(bool value) {
    Boolean *b = malloc(sizeof(Boolean));
    b->v = value;

    return b;
}

bool booleanValue(Boolean *ptr) {
    return ptr->v;
}

int32_t compareToBool(Boolean *ptr, Boolean *anotherBoolean) {
    return Boolean_compare(ptr->v, anotherBoolean->v);
}

int32_t Boolean_compare(bool x, bool y) {
    return (x == y) ? 0 : (x ? 1 : -1);
}

bool equalsBool(Boolean *ptr, Boolean *obj) {
    if (ptr == obj) {
        return true;
    }
    
    if (ptr == NULL || obj == NULL) {
        return false;
    }
    
    if (sizeof(*ptr) != sizeof(*obj)) {
        return false;
    }

    return (ptr->v == obj->v);
}

String *toStringBool(Boolean *ptr) {
    return Boolean_toString(ptr->v);
}

String *Boolean_toString(bool b) {
    char *str = malloc(_MAX_BOOL_STRLEN + 1);
    char buf[_MAX_BOOL_STRLEN];

    str[0] = '\0';
    sprintf(buf, "%s", b ? "true" : "false");
    strcat(str, buf);

    return new_String(str);
}

bool Boolean_parseBoolean(String *s) {
    String *trueStr = new_String("true");
    String *falseStr = new_String("false");
    bool value = false;

    if (equals(toLowerCase(s), trueStr)) {
        value = true;
    }
    else if (equals(toLowerCase(s), falseStr)) {
        value = false;
    }

    free(trueStr);
    free(falseStr);

    return value;
}
