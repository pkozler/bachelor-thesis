#ifndef STRINGTOKENIZER_INCLUDED
#define	STRINGTOKENIZER_INCLUDED

#include "String.h"
#include <cstdint>

class StringTokenizer {
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

