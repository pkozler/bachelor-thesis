#include <iostream>
#include "String.h"
#include "System.h"

using namespace std;

int main(int argc, char** argv) {
    String *str1 = new String("Something");
    String *str2 = new String(" Else");

    String *concatenated = *str1 + *str2;

    System::out->print(concatenated);

    delete str1, str2, concatenated;
    return 0;
}

