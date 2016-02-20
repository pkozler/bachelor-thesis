#ifndef INTEGER_INCLUDED
#define	INTEGER_INCLUDED

#include <iostream>
#include <sstream>
#include "String.h"

class Integer {
    int v;
public:
    static const int MIN_VALUE;
    static const int MAX_VALUE;
    Integer(int value);
    ~Integer();
    int intValue();
    int compareTo(Integer *anotherInteger);
    bool equals(Integer *obj);
    String *toString();
    static String *toString(int i);
    static int parseInt(String *s);
    friend std::ostream &operator<<(std::ostream &s, Integer &obj);
};

#endif	// INTEGER_INCLUDED
