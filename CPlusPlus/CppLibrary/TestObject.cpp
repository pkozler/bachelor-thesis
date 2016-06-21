#include "TestObject.h"

#include <string>
#include "System.h"

/**
 * Creates a new object.
 *
 * @param str string value
 * @param i integer value
 */
TestObject::TestObject(String *str, int32_t i) {
    this->str = str;
    this->i = i;
}

/*
 Destructs a TestObject.
 */
TestObject::~TestObject() {
    delete str;
}

/**
 * Returns a value of the string field.
 *
 * @return string value
 */
String *TestObject::getStr() {
    return str;
}

/**
 * Changes a value of the string field.
 *
 * @param str string value
 */
void TestObject::setStr(String *str) {
    this->str = str;
}

/**
 * Returns a value of the integer field.
 *
 * @return integer value
 */
int32_t TestObject::getI() {
    return i;
}

/**
 * Changes a value of the integer field.
 *
 * @param i integer value
 */
void TestObject::setI(int32_t i) {
    this->i = i;
}

/**
 * Indicates whether some other object is equal to this one.
 *
 * @param obj another object
 * @return TRUE if objects are equal, FALSE otherwise
 */
bool TestObject::equals(Object *obj) {
    if (obj == nullptr) {
        return false;
    }

    if (sizeof(this) != sizeof(*obj)) {
        return false;
    }

    TestObject *other = (TestObject *) obj;

    return i == other->i;
}

/**
 * Returns a string representation of the object.
 *
 * @return string representation
 */
String *TestObject::toString() {
    return new String("TestObject [str=" + str->_s() + ", i=" + std::to_string(i) + "]");
}

/**
 * Compares this object with the specified object for order.
 *
 * @param o another object
 * @return comparison result
 */
int32_t TestObject::compareTo(Object *o) {
    return i - ((TestObject *)o)->getI();
}
