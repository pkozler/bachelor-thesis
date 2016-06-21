#ifndef TESTOBJECTCOMPARATOR_INCLUDED
#define	TESTOBJECTCOMPARATOR_INCLUDED

#include "TestObject.h"
#include "String_.h"

/**
 * The TestObjectComparator class represents a comparator
 * for the TestObject class instances.
 *
 * @author Petr Kozler
 */
class TestObjectComparator : public Comparator {
public:
    int32_t compare(Object *o1, Object *o2);
};

#endif	// TESTOBJECTCOMPARATOR_INCLUDED
