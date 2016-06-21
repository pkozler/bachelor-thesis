#ifndef STRING_INCLUDED
#define	STRING_INCLUDED

#include <iostream>
#include <cstdint>

class String;

/**
 * Class Object is the root of the class hierarchy.
 */
class Object {
public:
    virtual bool equals(Object *obj);
    virtual String *toString();
    friend std::ostream &operator<<(std::ostream &s, Object &o);
};

/**
 * This abstract class imposes a total ordering on the objects of each class that implements it.
 */
class Comparable : public Object {
public:
    /**
     * Compares this object with the specified object for order.
     *
     * @param o the object to be compared.
     * @return a negative integer, zero, or a positive integer as this object
     * is less than, equal to, or greater than the specified object.
     */
    virtual int32_t compareTo(Object *o) = 0;
};

/**
 * A comparison function, which imposes a total ordering on some collection of objects.
 */
class Comparator : public Object {
public:
    /**
     * Compares its two arguments for order.
     *
     * @param o1 the first object to be compared.
     * @param o2 the second object to be compared.
     * @return a negative integer, zero, or a positive integer as the
     * first argument is less than, equal to, or greater than the second.
     */
    virtual int32_t compare(Object *o1, Object *o2) = 0;
};

/**
 * The String class represents character strings.
 *
 * @author Petr Kozler (A13B0359P)
 */
class String : public Comparable {
    // an inner string
    std::string s;
    void init(int8_t *value, int32_t offset, int32_t length);
public:
    const std::string _s() const { return s; }
    String(int8_t *value, int32_t length);
    String(int8_t *value, int32_t offset, int32_t length);
    String(std::string original);
    int32_t compareTo(Object *anotherString);
    bool equals(Object *anObject);
    String *substring(int32_t beginIndex);
    String *substring(int32_t beginIndex, int32_t endIndex);
    int32_t indexOf(int32_t ch);
    int32_t indexOf(int32_t ch, int32_t fromIndex);
    int32_t indexOf(String *str);
    int32_t indexOf(String *str, int32_t fromIndex);
    int32_t length();
    String *trim();
    String *toLowerCase();
    String *toUpperCase();
    char charAt(int32_t index);
    String *replace(char oldChar, char newChar);
    bool startsWith(String *prefix);
    bool endsWith(String *suffix);
    bool isEmpty();
    String *toString();
    String *operator=(std::string &s);
};

#endif	// STRING_INCLUDED
