#ifndef STRING_INCLUDED
#define STRING_INCLUDED

#include <stdbool.h>
#include <stdint.h>

/**
 * The String struct represents character strings.
 *
 * @author Petr Kozler (A13B0359P)
 */

typedef struct {
    // an inner string
    char *s;
    // inner string length
    int32_t len;
} String;

String *new_StringB(int8_t *value, int32_t length);
String *new_StringRangeB(int8_t *value, int32_t offset, int32_t length);
String *new_String(char *original);
void delete_String(String *ptr);
int32_t compareToStr(String *ptr, String *anotherString);
bool equalsStr(String *ptr, String *anObject);
String *substring(String *ptr, int32_t beginIndex);
String *substringTo(String *ptr, int32_t beginIndex, int32_t endIndex);
int32_t indexOfC(String *ptr, int32_t ch);
int32_t indexOfFromC(String *ptr, int32_t ch, int32_t fromIndex);
int32_t indexOfStr(String *ptr, String *str);
int32_t indexOfFromStr(String *ptr, String *str, int32_t fromIndex);
int32_t length(String *ptr);
String *trim(String *ptr);
String *toLowerCase(String *ptr);
String *toUpperCase(String *ptr);
char charAt(String *ptr, int32_t index);
String *replace(String *ptr, char oldChar, char newChar);
bool startsWith(String *ptr, String *prefix);
bool endsWith(String *ptr, String *suffix);
bool isEmptyStr(String *ptr);
String *toStringStr(String *ptr);

#endif	/* STRING_INCLUDED */
