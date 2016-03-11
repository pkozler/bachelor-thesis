#include "Scanner.h"

#include "String.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * Finds and returns the next complete token from this scanner.
 *
 * @return the next token
 */
String *next() {
    char *s;
    scanf("%s", s);

    return new_String(s);
}

/**
 * Scans the next token of the input into a boolean value and returns that
 * value.
 *
 * @return the boolean scanned from the input
 */
bool nextBoolean() {
    char *b;
    scanf("%s", b);
    String *str = new_String(b);
    String *trueStr = new_String("true");
    String *falseStr = new_String("false");
    bool value = false;

    if (equals(toLowerCase(str), trueStr)) {
        value = true;
    }
    else if (equals(toLowerCase(str), falseStr)) {
        value = false;
    }

    free(str);
    free(trueStr);
    free(falseStr);

    return value;
}

/**
 * Scans the next token of the input as a byte.
 *
 * @return the byte scanned from the input
 */
int8_t nextByte() {
    int32_t b;
    scanf("%hd", &b);

    return (int8_t) b;
}

/**
 * Scans the next token of the input as a short.
 *
 * @return the short scanned from the input
 */
int16_t nextShort() {
    int16_t s;
    scanf("%hd", &s);

    return s;
}

/**
 * Scans the next token of the input as an int.
 *
 * @return the int scanned from the input
 */
int32_t nextInt() {
    int32_t i;
    scanf("%d", &i);

    return i;
}

/**
 * Scans the next token of the input as a long.
 * 
 * @return the long scanned from the input
 */
int64_t nextLong() {
    int64_t l;
    scanf("%ld", &l);

    return l;
}

/**
 * Scans the next token of the input as a float.
 * 
 * @return the float scanned from the input
 */
float nextFloat() {
    float f;
    scanf("%f", &f);

    return f;
}

/**
 * Scans the next token of the input as a double.
 * 
 * @return the double scanned from the input
 */
double nextDouble() {
    double d;
    scanf("%lf", &d);

    return d;
}

/**
 * Advances this scanner past the current line and returns the input that was skipped.
 * 
 * @return the line that was skipped
 */
String *nextLine() {
    char * line = malloc(100);
    char * linep = line;
    size_t lenmax = 100, len = lenmax;
    int32_t c;

    if(line == NULL)
        return NULL;

    for(;;) {
        c = fgetc(stdin);
        if(c == EOF)
            break;

        if(--len == 0) {
            len = lenmax;
            char * linen = realloc(linep, lenmax *= 2);

            if(linen == NULL) {
                free(linep);
                return NULL;
            }
            line = linen + (line - linep);
            linep = linen;
        }

        if((*line++ = c) == '\n')
            break;
    }
    *line = '\0';
    String *str = new_String(linep);
    return str;
}
