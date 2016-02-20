#include "System.h"
#include "Scanner.h"
#include "Math.h"
#include "String.h"
#include "Integer.h"
#include "Character.h"
#include "StringTokenizer.h"
#include "Arrays.h"
#include "ArrayList.h"
#include "Collections.h"

#include <stdio.h>
#include <stdlib.h>

#define ARR_LEN 6

typedef struct {
    int value;
    int anotherValue;
} Object;

int compare (const void * a, const void * b) {
  return ( ((Object*)a)->value - ((Object*)b)->value );
}

char *cToStr(void *s) {
    return (char *) s;
}

/*
 *
 */
int main(int argc, char** argv) {
    int keys[] = {7, 5, 7, 3, 5, 3};
    int values[] = {1, 2, 3, 4, 5, 6};

    Object **arr = malloc(sizeof(Object *) * ARR_LEN);

    int i;
    for(i = 0; i < ARR_LEN; i++) {
        arr[i] = malloc(sizeof(Object));
        arr[i]->value = keys[i];
        arr[i]->anotherValue = values[i];
    }

    Arrays_sortObj(arr, ARR_LEN, compare);

    for (i = 0; i < ARR_LEN; i++) {
        System_out_printI(arr[i]->value);
        System_out_printS(", ");
        System_out_printI(arr[i]->anotherValue);
        System_out_println();
    }

    char *a = "aaa";
    char *b = "bbb";
    char *c = "ccc";

    ArrayList *al = new_ArrayList();

    add(al, a);
    add(al, b);
    add(al, c);

    char *d = get(al, 0);
    char *e = get(al, 1);
    char *f = get(al, 2);

    System_out_printlnS(d);
    System_out_printlnS(e);
    System_out_printlnS(f);

    System_out_printlnStr(toStringAl(al, 7, cToStr));

    return (EXIT_SUCCESS);
}
