#ifndef STRING_INCLUDED
#define	STRING_INCLUDED

#include <iostream>
#include <cstdint>

class String {
    std::string s;
public:
    String(char *value);
    String(char *value, int32_t offset, int32_t count);
    String(std::string original);
    ~String();
    int32_t compareTo(String *anotherString);
    bool equals(String *anObject);
    String *substring(int32_t beginIndex);
    String *substring(int32_t beginIndex, int32_t endIndex);
    int32_t indexOf(int32_t ch);
    int32_t indexOf(int32_t ch, int32_t fromIndex);
    int32_t indexOf(String *str);
    int32_t indexOf(String *str, int32_t fromIndex);
    int32_t length();
    String *trim();
    String *toLowerCase();
    String *toUpperCase();
    char charAt(int32_t index);
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
