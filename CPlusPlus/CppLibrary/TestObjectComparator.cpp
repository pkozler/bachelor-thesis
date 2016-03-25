#include "TestObjectComparator.h"

/**
 * Compares its two arguments for order.
 *
 * @param o1 first object
 * @param o2 second object
 * @return comparison result
 */
int32_t TestObjectComparator::compare(TestObject *o1, TestObject *o2) {
    return ((TestObject *) o1)->getI() - ((TestObject *) o2)->getI();
}
