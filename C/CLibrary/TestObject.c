#include "TestObject.h"

#include <stdlib.h>
#include <stdio.h>

#define _MAX_TO_STRLEN 256

/**
 * Creates a new structure.
 *
 * @param str string value
 * @param i integer value
 */
TestObject *new_TestObject(String *str, int32_t i) {
    TestObject *ptr = malloc(sizeof(TestObject));
    ptr->str = str;
    ptr->i = i;
    
    return ptr;
}

/**
 * Returns a value of the string struct member.
 *
 * @return string value
 */
String *getStr(TestObject *ptr) {
    return ptr->str;
}

/**
 * Changes a value of the string struct member.
 *
 * @param str string value
 */
void setStr(TestObject *ptr, String *str) {
    ptr->str = str;
}

/**
 * Returns a value of the integer struct member.
 *
 * @return integer value
 */
int32_t getI(TestObject *ptr) {
    return ptr->i;
}

/**
 * Changes a value of the integer struct member.
 *
 * @param i integer value
 */
void setI(TestObject *ptr, int32_t i) {
    ptr->i = i;
}

/**
 * Indicates whether some other structure is equal to this one.
 *
 * @param obj another structure
 * @return TRUE if structure instances are equal, FALSE otherwise
 */
bool equalsTo(TestObject *ptr, TestObject *obj) {
    if (ptr == NULL || obj == NULL) {
        return false;
    }

    if (sizeof(*ptr) != sizeof(*obj)) {
        return false;
    }

    return ptr->i == obj->i;
}

/**
 * Returns a string representation of the structure.
 *
 * @return string representation
 */
String *toStringTo(TestObject *ptr) {
    char *buf = calloc(_MAX_TO_STRLEN, sizeof(char));
    sprintf(buf, "TestObject [str=%s, i=%d]", ptr->str, ptr->i);
    
    return new_String(buf);
}

/**
 * Compares this structure with the specified structure for order.
 *
 * @param o another structure
 * @return comparison result
 */
int32_t compareToTo(TestObject *ptr, TestObject *o) {
    return ptr->i - o->i;
}
