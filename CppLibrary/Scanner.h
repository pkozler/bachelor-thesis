#ifndef SCANNER_INCLUDED
#define	SCANNER_INCLUDED

#include "String.h"
#include <cstdint>

class Scanner {
public:
    Scanner(void *source);
    Scanner();
    ~Scanner();
    String *next();
    bool nextBoolean();
    int8_t nextByte();
    int16_t nextShort();
    int32_t nextInt();
    int64_t nextLong();
    float nextFloat();
    double nextDouble();
    String *nextLine();
};

#endif	// SCANNER_INCLUDED
