#ifndef STRINGTOKENIZER_INCLUDED
#define	STRINGTOKENIZER_INCLUDED

#include "String_.h"
#include <cstdint>

/**
 * The string tokenizer class allows an application to break a string into tokens.
 *
 * @author Petr Kozler (A13B0359P)
 */
class StringTokenizer : public Object {
    std::string str;
    std::string delim;
public:
    StringTokenizer(String *str);
    StringTokenizer(String *str, String *delim);
    ~StringTokenizer();
    int32_t countTokens();
    bool hasMoreTokens();
    String *nextToken();
};

#endif	// STRINGTOKENIZER_INCLUDED

