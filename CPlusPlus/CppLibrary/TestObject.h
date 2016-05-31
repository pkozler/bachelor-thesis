#ifndef TESTOBJECT_INCLUDED
#define	TESTOBJECT_INCLUDED

#include "String_.h"

/**
 * The {@code TestObject} class represents a simple object that serves
 * for demonstration the functionality of libraries working with objects.
 *
 * @author Petr Kozler
 */
class TestObject : public Comparable<TestObject> {
    String *str;
    int32_t i;
public:
    TestObject(String *str, int32_t i);
    ~TestObject();
    String *getStr();
    void setStr(String *str);
    int32_t getI();
    void setI(int32_t i);
    bool equals(Object *obj);
    String *toString();
    int32_t compareTo(TestObject *o);
};

#endif	// TESTOBJECT_INCLUDED
