#ifndef STRINGBUILDER_INCLUDED
#define	STRINGBUILDER_INCLUDED

#include "String_.h"
#include <sstream>

/**
 * A mutable sequence of characters.
 *
 * @author Petr Kozler (A13B0359P)
 */
class StringBuilder : public Object {
    std::ostringstream oss;
public:
    StringBuilder();
    StringBuilder *append(String *str);
    String *toString();
};

#endif	// STRINGBUILDER_INCLUDED
