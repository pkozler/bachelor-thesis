#ifndef STRINGTOKENIZER_INCLUDED
#define	STRINGTOKENIZER_INCLUDED

#include "String.h"

class StringTokenizer {
    std::string str;
    std::string delim;
public:
    StringTokenizer(String *str);
    StringTokenizer(String *str, String *delim);
    ~StringTokenizer();
    int countTokens();
    bool hasMoreTokens();
    String *nextToken();
};

#endif	// STRINGTOKENIZER_INCLUDED

