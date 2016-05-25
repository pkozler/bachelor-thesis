#include <iostream>

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
#include "Long.h";
#include "Math_.h";
#include "Scanner.h";
#include "Short.h";
#include "String.h";
#include "StringBuilder.h";
#include "StringTokenizer.h";
#include "System.h";
#include "TestObject.h"
#include "TestObjectComparator.h"

using namespace std;

int main(int argc, char** argv) {
    String *s1 = new String("zeroth");
    Object *o1 = new Object();
    
    System::out->println(s1);
    System::out->println(o1);
    
    Scanner *sc = new Scanner(System::in);
    sc->nextLine();
    
    return 0;
}