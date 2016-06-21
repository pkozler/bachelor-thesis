#ifndef TESTOBJECT_INCLUDED
#define	TESTOBJECT_INCLUDED

#include "String.h"
#include <stdbool.h>
#include <stdint.h>

/**
 * The TestObject struct represents a simple structure that serves
 * for demonstration the functionality of libraries working with structures.
 *
 * @author Petr Kozler
 */
typedef struct {
    // string value
    String *str;
    // integer value
    int32_t i;
} TestObject;

TestObject *new_TestObject(String *str, int32_t i);
String *getStr(TestObject *ptr);
void setStr(TestObject *ptr, String *str);
int32_t getI(TestObject *ptr);
void setI(TestObject *ptr, int32_t i);
bool equalsTo(TestObject *ptr, TestObject *obj);
String *toStringTo(TestObject *ptr);
int32_t compareToTo(TestObject *ptr, TestObject *o);

#endif	/* TESTOBJECT_INCLUDED */