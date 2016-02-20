#ifndef STRING_INCLUDED
#define	STRING_INCLUDED

#include <iostream>

class String {
    std::string s;
public:
    String(char *value);
    String(char *value, int offset, int count);
    String(std::string original);
    ~String();
    int compareTo(String *anotherString);
    bool equals(String *anObject);
    String *substring(int beginIndex);
    String *substring(int beginIndex, int endIndex);
    int indexOf(int ch);
    int indexOf(int ch, int fromIndex);
    int indexOf(String *str);
    int indexOf(String *str, int fromIndex);
    int length();
    String *trim();
    String *toLowerCase();
    String *toUpperCase();
    char charAt(int index);
    String *replace(char oldChar, char newChar);
    bool startsWith(String *prefix);
    bool endsWith(String *suffix);
    bool isEmpty();
    std::string toString();
    friend std::ostream &operator<<(std::ostream &s, String &str);
    friend String *operator+(String &s1, String &s2);
    String *operator=(String &s);
};

#endif	// STRING_INCLUDED
