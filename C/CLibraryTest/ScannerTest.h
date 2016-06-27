#ifndef SCANNERTEST_H
#define	SCANNERTEST_H

#include <stdint.h>

/**
 * A Scanner module test suite.
 *
 * @author Petr Kozler (A13B0359P)
 */

// error count for the current test function
extern int32_t errorsInFunction;

void scannerTest();
void nextTest();
void nextBooleanTest();
void nextByteTest();
void nextShortTest();
void nextIntTest();
void nextLongTest();
void nextFloatTest();
void nextDoubleTest();
void nextLineTest();

#endif	/* SCANNERTEST_H */

