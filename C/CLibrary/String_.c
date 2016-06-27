#include "String_.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <wchar.h>

/**
 * Constructs a new String by decoding the specified array of bytes using
 * the ANSI charset.
 *
 * @param bytes The bytes to be decoded into characters
 * @param length The array length
 */
String *new_StringB(int8_t *value, int32_t length) {
    return new_StringRangeB(value, 0, length);
}

/**
 * Constructs a new String by decoding the specified subarray of bytes using
 * the ANSI charset.
 *
 * @param bytes The bytes to be decoded into characters
 * @param offset The index of the first byte to decode
 * @param length The number of bytes to decode
 */
String *new_StringRangeB(int8_t *value, int32_t offset, int32_t length) {
    String *str = malloc(sizeof(String));
    str->s = malloc(sizeof(char) * (length + 1));
    str->s[0] = '\0';
    // adding the terminator after the byte array to create a string
    strncat(str->s, (char *) value + offset, length);
    str->len = strlen(str->s);

    return str;
}

/**
 * Initializes a newly created String structure so that it represents the same
 * sequence of characters as the argument; in other words, the inner null terminated
 * char array of the newly created String structure instance is a copy of the argument array.
 *
 * @param original A String
 */
String *new_String(char *original) {
    String *str = malloc(sizeof(String));
    // copying the string so the original one will not be affected
    str->s = strdup(original);
    str->len = strlen(str->s);

    return str;
}

/*
    Destructs the String.
 */
void delete_String(String *ptr) {
    free(ptr->s);
    free(ptr);
}

/**
 * Compares two strings lexicographically.
 *
 * @param ptr The allocated structure
 * @param anotherString the String to be compared.
 * @return the value 0 if the first string is equal to the second string; a
 * value less than 0 if the first string is lexicographically less than the
 * second string; and a value greater than 0 if the first string is
 * lexicographically greater than the second string.
 */
int32_t compareToStr(String *ptr, String *anotherString) {
    return strcmp(ptr->s, anotherString->s);
}

/**
 * Compares the one specified string to the other.
 *
 * @param ptr The allocated structure
 * @param anObject The String to compare the first one against
 * @return true if the second given String represents a String equivalent to the first
 * string, false otherwise
 */
bool equalsStr(String *ptr, String *anObject) {
    // testing another object reference for a NULL value
    if (ptr == NULL || anObject == NULL) {
        return false;
    }

    // testing object class equality
    if (sizeof(*ptr) != sizeof(*anObject)) {
        return false;
    }
    
    // testing object fields equality
    return !strcmp(ptr->s, anObject->s);
}

/**
 * Returns a new string that is a substring of the specified string.
 *
 * @param ptr The allocated structure
 * @param beginIndex the beginning index, inclusive.
 * @return the specified substring.
 */
String *substring(String *ptr, int32_t beginIndex) {
    return substringTo(ptr, beginIndex, ptr->len);
}

/**
 * Returns a new string that is a substring of the specified string.
 *
 * @param ptr The allocated structure
 * @param beginIndex the beginning index, inclusive.
 * @param endIndex the ending index, exclusive.
 * @return the specified substring.
 */
String *substringTo(String *ptr, int32_t beginIndex, int32_t endIndex) {
    int32_t len = endIndex - beginIndex;
    char *to = (char*) malloc(len * sizeof(char));
    to[0] = '\0';
    
    // copy the calculated count of characters beginning on the specified offset
    strncat(to, ptr->s + beginIndex, (size_t) len);

    String *str = new_String(to);
    free(to);

    return str;
}

/**
 * Returns the index within the specified string of the first occurrence of the
 * specified character.
 *
 * @param ptr The allocated structure
 * @param ch a character (Unicode code point).
 * @return the index of the first occurrence of the character in the
 * character sequence represented by the specified string, or -1 if the character
 * does not occur.
 */
int32_t indexOfC(String *ptr, int32_t ch) {
    return indexOfFromC(ptr, ch, 0);
}

/**
 * Returns the index within the specified string of the first occurrence of the
 * specified character, starting the search at the specified index.
 *
 * @param ptr The allocated structure
 * @param ch a character (Unicode code point).
 * @param fromIndex the index to start the search from.
 * @return the index of the first occurrence of the character in the
 * character sequence represented by the specified string that is greater than or
 * equal to fromIndex, or -1 if the character does not occur.
 */
int32_t indexOfFromC(String *ptr, int32_t ch, int32_t fromIndex) {
    char* str = ptr->s + fromIndex;
    // finding the pointer to char in the char array
    char* c = strchr(str, ch);
    
    if (c == NULL) {
        return -1;
    }
    
    // calculating the array index from the pointer
    size_t index = (size_t)(c - ptr->s);

    return (int32_t) index;
}

/**
 * Returns the index within the specified string of the first occurrence of the
 * specified substring.
 *
 * @param ptr The allocated structure
 * @param str the substring to search for.
 * @return the index of the first occurrence of the specified substring, or
 * -1 if there is no such occurrence.
 */
int32_t indexOfStr(String *ptr, String *str) {
    return indexOfFromStr(ptr, str, 0);
}

/**
 * Returns the index within the specified string of the first occurrence of the
 * specified substring, starting at the specified index.
 *
 * @param ptr The allocated structure
 * @param str the substring to search for.
 * @param fromIndex the index from which to start the search.
 * @return the index of the first occurrence of the specified substring,
 * starting at the specified index, or -1 if there is no such occurrence.
 */
int32_t indexOfFromStr(String *ptr, String *str, int32_t fromIndex) {
    char* str0 = ptr->s + fromIndex;
    // finding the pointer to the beginning of substring in the char array
    char* s = strstr(str0, str->s);

    if (s == NULL) {
        return -1;
    }
    
    // calculating the array index from the pointer
    size_t index = (size_t)(s - ptr->s);

    return (int32_t) index;
}

/**
 * Returns the length of the specified string.
 *
 * @param ptr The allocated structure
 * @return the length of the sequence of characters represented by the specified
 * string.
 */
int32_t length(String *ptr) {
    return ptr->len;
}

/**
 * Returns a copy of the string, with leading and trailing whitespace
 * omitted.
 *
 * @param ptr The allocated structure
 * @return A copy of the specified string with leading and trailing white space
 * removed, or the specified string if it has no leading or trailing white space.
 */
String *trim(String *ptr) {
    int32_t i, j;

    // get the index of the first non-white character in the string
    for (i = 0; isspace(ptr->s[i]); i++);
    // get the index of the last non-white character in the string
    for (j = ptr->len - 1; isspace(ptr->s[j]); j--);
    int32_t num = j - i + 1;

    char *str = (char *) malloc(num + 1);
    // copy the non-white substring
    strncpy(str, ptr->s + i, num);
    str[num] = '\0';

    String *changedStr = new_String(str);
    free(str);

    return changedStr;
}

/**
 * Converts all of the characters in the specified String to lower case using the
 * rules of the default locale.
 *
 * @param ptr The allocated structure
 * @return the String, converted to lowercase.
 */
String *toLowerCase(String *ptr) {
    char *str = (char*) malloc(ptr->len);

    int32_t i = 0;
    char c;
    // calling the "tolower" function over the each character of the string
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
 * Converts all of the characters in the specified String to upper case using the
 * rules of the default locale.
 *
 * @param ptr The allocated structure
 * @return the String, converted to uppercase.
 */
String *toUpperCase(String *ptr) {
    char *str = (char*) malloc(ptr->len);

    int32_t i = 0;
    char c;
    // calling the "toupper" function over the each character of the string
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
 * @param ptr The allocated structure
 * @param index the index of the char value.
 * @return the char value at the specified index of the specified string. The first
 * char value is at index 0.
 */
char charAt(String *ptr, int32_t index) {
    return ptr->s[index];
}

/**
 * Returns a new string resulting from replacing all occurrences of oldChar
 * in the specified string with newChar.
 *
 * @param ptr The allocated structure
 * @param oldChar the old character.
 * @param newChar the new character.
 * @return a string derived from the specified string by replacing every occurrence
 * of oldChar with newChar.
 */
String *replace(String *ptr, char oldChar, char newChar) {
    // copying the string
    char *str = strdup(ptr->s);
    int32_t i;

    // replacing the old char with the new one
    for (i = 0; str[i]; i++) {
        if (str[i] == oldChar) {
            str[i] = newChar;
        }
    }

    String *replacedStr = new_String(str);
    free(str);

    return replacedStr;
}

/**
 * Tests if the specified string starts with the specified prefix.
 *
 * @param ptr The allocated structure
 * @param prefix the prefix.
 * @return true if the character sequence represented by the second string is a
 * prefix of the character sequence represented by the first string; false
 * otherwise. Note also that true will be returned if the second string is an
 * empty string or is equal to the first String structure as determined by the
 * equalsStr(String *, String *) function.
 */
bool startsWith(String *ptr, String *prefix) {
    // test if the string is longer and the prefix index is on the beginning of the string
    return ptr->len < prefix->len ? false
            : strncmp(prefix->s, ptr->s, prefix->len) == 0;
}

/**
 * Tests if the specified string ends with the specified suffix.
 *
 * @param ptr The allocated structure
 * @param suffix the suffix.
 * @return true if the character sequence represented by the second string is a
 * suffix of the character sequence represented by the first string; false
 * otherwise. Note that the result will be true if the second string is the empty
 * string or is equal to the first String structure as determined by the
 * equalsStr(String *, String *) function.
 */
bool endsWith(String *ptr, String *suffix) {
    // test if the string is longer and the suffix index is on the end of the string (minus suffix size)
    return ptr->len < suffix->len ? false
            : strncmp(suffix->s, ptr->s + (ptr->len - suffix->len), suffix->len) == 0;
}

/**
 * Returns true if, and only if, length() is 0.
 *
 * @param ptr The allocated structure
 * @return true if length() is 0, otherwise false
 */
bool isEmptyStr(String *ptr) {
    return ptr->len == 0;
}

/**
 * The specified structure (which is already a string!) is itself returned.
 *
 * @param ptr The allocated structure
 * @return the string itself.
 */
String *toStringStr(String *ptr) {
    return new_String(ptr->s);
}
