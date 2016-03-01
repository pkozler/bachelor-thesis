#ifndef STRINGBUILDER_INCLUDED
#define	STRINGBUILDER_INCLUDED

#include "String.h"

class StringBuilder {
    std::ostringstream oss;
public:
    StringBuilder();
    ~StringBuilder();
    StringBuilder *append(String *str);
    String *toString();
};

#endif	// STRINGBUILDER_INCLUDED
