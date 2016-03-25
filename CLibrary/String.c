#include "String.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * Constructs a new String by decoding the specified array of bytes using
 * the platform's default charset.
 *
 * @param bytes The bytes to be decoded into characters
 */
String *new_StringB(int8_t *value, int32_t length) {
    return new_StringRangeB(value, 0, length);
}

/**
 * Constructs a new String by decoding the specified subarray of bytes using
 * the platform's default charset.
 *
 * @param bytes The bytes to be decoded into characters
 * @param offset The index of the first byte to decode
 * @param length The number of bytes to decode
 */
String *new_StringRangeB(int8_t *value, int32_t offset, int32_t length) {
    String *str = malloc(sizeof(String));
    str->s[0] = '\0';
    strncat(str->s, (char *) value + offset, length);

    return str;
}

/**
 * Initializes a newly created String object so that it represents the same
 * sequence of characters as the argument; in other words, the newly created
 * string is a copy of the argument string. Unless an explicit copy of
 * original is needed, use of this constructor is unnecessary since Strings
 * are immutable.
 *
 * @param original A String
 */
String *new_String(char *original) {
    String *str = malloc(sizeof(String));
    str->s = strdup(original);
    str->len = strlen(str->s);

    return str;
}

void delete_String(String *ptr) {
    free(ptr->s);
    free(ptr);
}

/**
 * Compares two strings lexicographically.
 *
 * @param anotherString the String to be compared.
 * @return the value 0 if the argument string is equal to this string; a
 * value less than 0 if this string is lexicographically less than the
 * string argument; and a value greater than 0 if this string is
 * lexicographically greater than the string argument.
 */
int32_t compareTo(String *ptr, String *anotherString) {
    return strcmp(ptr->s, anotherString->s);
}

/**
 * Compares this string to the specified object.
 *
 * @param anObject The object to compare this String against
 * @return true if the given object represents a String equivalent to this
 * string, false otherwise
 */
bool equals(String *ptr, String *anObject) {
    if (anObject == NULL || anObject == NULL) {
        return false;
    }

    if (sizeof(*ptr) != sizeof(*anObject)) {
        return false;
    }

    return !strcmp(ptr->s, anObject->s);
}

/**
 * Returns a new string that is a substring of this string.
 * 
 * @param beginIndex the beginning index, inclusive.
 * @return the specified substring.
 */
String *substring(String *ptr, int32_t beginIndex) {
    return substringTo(ptr, 0, strlen(ptr->s) - 1);
}

/**
 * Returns a new string that is a substring of this string.
 *
 * @param beginIndex the beginning index, inclusive.
 * @param endIndex the ending index, exclusive.
 * @return the specified substring.
 */
String *substringTo(String *ptr, int32_t beginIndex, int32_t endIndex) {
    int32_t len = endIndex - beginIndex;
    char *to = (char*) malloc(len);
    strncpy(to, ptr->s + beginIndex, (size_t) endIndex - beginIndex);

    String *str = new_String(to);
    free(to);

    return str;
}

/**
 * Returns the index within this string of the first occurrence of the
 * specified character.
 *
 * @param ch a character (Unicode code point).
 * @return the index of the first occurrence of the character in the
 * character sequence represented by this object, or -1 if the character
 * does not occur.
 */
int32_t indexOfC(String *ptr, int32_t ch) {
    return indexOfFromC(ptr, ch, 0);
}

/**
 * Returns the index within this string of the first occurrence of the
 * specified character, starting the search at the specified index.
 *
 * @param ch a character (Unicode code point).
 * @param fromIndex the index to start the search from.
 * @return the index of the first occurrence of the character in the
 * character sequence represented by this object that is greater than or
 * equal to fromIndex, or -1 if the character does not occur.
 */
int32_t indexOfFromC(String *ptr, int32_t ch, int32_t fromIndex) {
    char* str = ptr->s + fromIndex;

    char* c = strchr(str, ch);
    int32_t index = (int32_t)(c - str);

    return index;
}

/**
 * Returns the index within this string of the first occurrence of the
 * specified substring.
 *
 * @param str the substring to search for.
 * @return the index of the first occurrence of the specified substring, or
 * -1 if there is no such occurrence.
 */
int32_t indexOfStr(String *ptr, String *str) {
    return indexOfFromStr(ptr, str, 0);
}

/**
 * Returns the index within this string of the first occurrence of the
 * specified substring, starting at the specified index.
 *
 * @param str the substring to search for.
 * @param fromIndex the index from which to start the search.
 * @return the index of the first occurrence of the specified substring,
 * starting at the specified index, or -1 if there is no such occurrence.
 */
int32_t indexOfFromStr(String *ptr, String *str, int32_t fromIndex) {
    char* str0 = ptr->s + fromIndex;
    int32_t index = (int32_t) strcspn(str0, str->s);

    return index;
}

/**
 * Returns the length of this string.
 *
 * @return the length of the sequence of characters represented by this
 * object.
 */
int32_t length(String *ptr) {
    return ptr->len;
}

/**
 * Returns a copy of the string, with leading and trailing whitespace
 * omitted.
 *
 * @return A copy of this string with leading and trailing white space
 * removed, or this string if it has no leading or trailing white space.
 */
String *trim(String *ptr) {
    int32_t i, j;

    for (i = 0; isspace(ptr->s[i]); i++);
    for (j = ptr->len - 1; isspace(ptr->s[j]); j--);
    int32_t num = j - i + 1;

    char *str = (char *) malloc(num + 1);
    strncpy(str, ptr->s + i, num);
    str[num] = '\0';

    String *changedStr = new_String(str);
    free(str);

    return changedStr;
}

/**
 * Converts all of the characters in this String to lower case using the
 * rules of the default locale.
 *
 * @return the String, converted to lowercase.
 */
String *toLowerCase(String *ptr) {
    char *str = (char*) malloc(ptr->len);

    int32_t i = 0;
    char c;
    while (ptr->s[i]) {
        c = ptr->s[i];
        str[i] = tolower((int32_t)c);
        i++;
    }
    str[i] = '\0';

    String *changedStr = new_String(str);
    free(str);

    return changedStr;
}

/**
 * Converts all of the characters in this String to upper case using the
 * rules of the default locale.
 *
 * @return the String, converted to uppercase.
 */
String *toUpperCase(String *ptr) {
    char *str = (char*) malloc(ptr->len);

    int32_t i = 0;
    char c;
    while (ptr->s[i]) {
        c = ptr->s[i];
        str[i] = toupper((int32_t)c);
        i++;
    }
    str[i] = '\0';

    String *changedStr = new_String(str);
    free(str);

    return changedStr;
}

/**
 * Returns the char value at the specified index.
 *
 * @param index the index of the char value.
 * @return the char value at the specified index of this string. The first
 * char value is at index 0.
 */
char charAt(String *ptr, int32_t index) {
    return ptr->s[index];
}

/**
 * Returns a new string resulting from replacing all occurrences of oldChar
 * in this string with newChar.
 *
 * @param oldChar the old character.
 * @param newChar the new character.
 * @return a string derived from this string by replacing every occurrence
 * of oldChar with newChar.
 */
String *replace(String *ptr, char oldChar, char newChar) {
    char *str = (char*) malloc(ptr->len);
    int32_t i;

    for (i = 0; ptr->s[i]; i++) {
        if (ptr->s[i] == oldChar) {
            ptr->s[i] = newChar;
        }
    }

    String *changedStr = new_String(str);
    free(str);

    return changedStr;
}

/**
 * Tests if this string starts with the specified prefix.
 *
 * @param prefix the prefix.
 * @return true if the character sequence represented by the argument is a
 * prefix of the character sequence represented by this string; false
 * otherwise. Note also that true will be returned if the argument is an
 * empty string or is equal to this String object as determined by the
 * equals(Object) method.
 */
bool startsWith(String *ptr, String *prefix) {
    return ptr->len < prefix->len ? false
            : strncmp(prefix->s, ptr->s, prefix->len) == 0;
}

/**
 * Tests if this string ends with the specified suffix.
 *
 * @param suffix the suffix.
 * @return true if the character sequence represented by the argument is a
 * suffix of the character sequence represented by this object; false
 * otherwise. Note that the result will be true if the argument is the empty
 * string or is equal to this String object as determined by the
 * equals(Object) method.
 */
bool endsWith(String *ptr, String *suffix) {
    return ptr->len < suffix->len ? false
            : strncmp(suffix->s, ptr->s + (ptr->len - suffix->len), suffix->len) == 0;
}

/**
 * Returns true if, and only if, length() is 0.
 *
 * @return true if length() is 0, otherwise false
 */
bool isEmptyStr(String *ptr) {
    return ptr->len == 0;
}

/**
 * This object (which is already a string!) is itself returned.
 *
 * @return the string itself.
 */
String *toString(String *ptr) {
    return new_String(ptr->s);
}
