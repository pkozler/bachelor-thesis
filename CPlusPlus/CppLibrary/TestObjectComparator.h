#ifndef TESTOBJECTCOMPARATOR_INCLUDED
#define	TESTOBJECTCOMPARATOR_INCLUDED

#include "TestObject.h"
#include "String_.h"

/**
 * The {@code TestObjectComparator} class represents a comparator
 * for the {@code TestObject} class instances.
 *
 * @author Petr Kozler
 */
class TestObjectComparator : public Comparator<TestObject> {
public:
    int32_t compare(TestObject *o1, TestObject *o2);
};

#endif	// TESTOBJECTCOMPARATOR_INCLUDED
