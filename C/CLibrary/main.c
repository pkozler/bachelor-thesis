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
#include "TestObject.h"

int main(int argc, char** argv) {
    Scanner *sc = new_Scanner(System_in);
    printlnStr(System_out, next(sc));
    printlnStr(System_out, nextLine(sc));
    
    /*StringBuilder *sb = new_StringBuilder();
    append(sb, new_String("Příliš "));
    append(sb, new_String("žluťoučký "));
    append(sb, new_String("kůň "));
    append(sb, new_String("úpěl "));
    append(sb, new_String("ďábelské "));
    append(sb, new_String("ódy."));
    
    printlnStr(System_out, toStringSb(sb));*/
    
    return (EXIT_SUCCESS);
}
