#include "Scanner.h"

#include "String.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

String *next() {
    char *s;
    scanf("%s", s);

    return new_String(s);
}

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

char nextByte() {
    int b;
    scanf("%d", &b);

    return (char) b;
}

short nextShort() {
    short s;
    scanf("%hd", &s);

    return s;
}

int nextInt() {
    int i;
    scanf("%d", &i);

    return i;
}

long nextLong() {
    long l;
    scanf("%ld", &l);

    return l;
}

float nextFloat() {
    float f;
    scanf("%f", &f);

    return f;
}

double nextDouble() {
    double d;
    scanf("%lf", &d);

    return d;
}

String *nextLine() {
    char * line = malloc(100);
    char * linep = line;
    size_t lenmax = 100, len = lenmax;
    int c;

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
