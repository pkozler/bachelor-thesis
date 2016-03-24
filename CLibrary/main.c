#include <stdio.h>
#include <stdlib.h>

#include "ArrayList.h";
#include "Arrays.h";
#include "Boolean.h";
#include "Byte.h";
#include "Character.h";
#include "Collections.h";
#include "Double.h";
#include "Float.h";
#include "Integer.h";
#include "LinkedList.h";
#include "List.h"
#include "Long.h";
#include "Math.h";
#include "Scanner.h";
#include "Short.h";
#include "String.h";
#include "StringBuilder.h";
#include "StringTokenizer.h";
#include "System.h";

int main(int argc, char** argv) {
    String *s1 = new_String("zeroth");
    
    printlnStr(System_out, s1);
    
    Scanner *sc = new_Scanner(System_in);
    nextLine(sc);
    
    return (EXIT_SUCCESS);
}
