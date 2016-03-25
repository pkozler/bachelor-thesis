#ifndef SCANNER_INCLUDED
#define	SCANNER_INCLUDED

#include "System.h"
#include "String.h"
#include <cstdint>

/**
 * A simple text scanner which can parse primitive types and strings using regular expressions.
 *
 * @author Petr Kozler (A13B0359P)
 */
class Scanner : public Object {
public:
    Scanner(InputStream *source);
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
