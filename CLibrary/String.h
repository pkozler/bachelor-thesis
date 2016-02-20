#ifndef STRING_INCLUDED
#define	STRING_INCLUDED

#include <stdbool.h>

typedef struct {
    char *s;
    int len;
} String;

String *new_String(char *original);
String *new_StringRange(char *value, int offset, int count);
void delete_String(String *ptr);
int compareTo(String *ptr, String *anotherString);
bool equals(String *ptr, String *anObject);
String *substring(String *ptr, int beginIndex);
String *substringTo(String *ptr, int beginIndex, int endIndex);
int indexOfC(String *ptr, int ch);
int indexOfFromC(String *ptr, int ch, int fromIndex);
int indexOfStr(String *ptr, String *str);
int indexOfFromStr(String *ptr, String *str, int fromIndex);
int length(String *ptr);
String *trim(String *ptr);
String *toLowerCase(String *ptr);
String *toUpperCase(String *ptr);
char charAt(String *ptr, int index);
String *replace(String *ptr, char oldChar, char newChar);
bool startsWith(String *ptr, String *prefix);
bool endsWith(String *ptr, String *suffix);
bool isEmptyStr(String *ptr);
char *toString(String *ptr);

#endif	/* STRING_INCLUDED */
