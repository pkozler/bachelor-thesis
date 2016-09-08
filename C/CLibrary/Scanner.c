#include "Scanner.h"

#include "StringBuilder.h"
#include "Boolean.h"
#include "Byte.h"
#include "Short.h"
#include "Integer.h"
#include "Long.h"
#include "Float.h"
#include "Double.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <wchar.h>
#include <stdbool.h>

/*
    Reads the line from the standard input.
*/
String *_readLine() {
    StringBuilder *sb = new_StringBuilder();
    String *line;
    char c;
    
    // reading characters until newline/EOF
    while (scanf("%c", &c) != EOF) {
        // returning the scanned characters as the new line string
        if (c == '\n') {
            line = toStringSb(sb);
            delete_StringBuilder(sb);
            
            return line;
        }
        
        // converting the char to string
        char *s = malloc(sizeof(char) * 2);
        s[0] = c;
        s[1] = '\0';
        
        // appending the char to the scanned line string
        String *str = new_String(s);
        append(sb, str);
        delete_String(str);
        free(s);
    }
    
    line = toStringSb(sb);
    delete_StringBuilder(sb);

    return line;
}

/*
    Returns TRUE if and only if there is only the white-space characters
    left in the line or if the current scanned line is already empty.
*/
bool _isEmptyOrWhiteSpace(char *line) {
    int32_t i;
    
    // finding the first non-whitespace character
    for (i = 0; line[i]; i++) {
        if (!isspace((int) line[i])) {
            return false;
        }
    }
    
    // returning TRUE if there are only whitespaces in the line
    return true;
}

/*
    Removes all leading white-space characters from the line.
*/
char *_trimStart(char *line) {
    int32_t i;
    
    // finding the first non-whitespace character
    for (i = 0; line[i]; i++) {
        if (!isspace((int) line[i])) {
            break;
        }
    }
    
    // returning the substring without the leading whitespaces
    return strdup(line + i);
}

/*
    Removes the part of the current line to the first white-space character
    after the first sequence of non-whitespace characters and returns this
    part as the scanned token.
*/
char *_removeLineToWhiteSpace(Scanner *ptr) {
    int32_t i;
    char *line;
    char *token;
    
    // removing all leading whitespaces from the line
    ptr->line = _trimStart(ptr->line);
    
    // finding the first whitespace in the trimmed line
    for (i = 0; ptr->line[i]; i++) {
        if (isspace((int) ptr->line[i])) {
            break;
        }
    }
    
    token = malloc(sizeof(char) * i);
    token[0] = '\0';
    
    // getting the next token
    strncat(token, ptr->line, (size_t) i);
    line = strdup(ptr->line + i);
    // removing the token from the current line
    free(ptr->line);
    ptr->line = line;
    
    return token;
}

/*
    Returns the next token of the current line or reads the new line
    from the standard input if the current line has been scanned completely.
*/
String *_getNextToken(Scanner *ptr) {
    // reading the next line if the current line is empty
    while (_isEmptyOrWhiteSpace(ptr->line)) {
        free(ptr->line);
        String *line = _readLine();
        // removing all leading whitespaces
        ptr->line = _trimStart(line->s);
        delete_String(line);
    }
    
    // returning the next scanned token
    return new_String(_removeLineToWhiteSpace(ptr));
}

/**
 * Constructs a new Scanner that produces values scanned from the specified
 * input stream.
 *
 * @param source An input stream to be scanned
 */
Scanner *new_Scanner(InputStream *source) {
    Scanner *sc = malloc(sizeof(Scanner));
    sc->line = malloc(sizeof(char));
    sc->line[0] = '\0';
    
    return sc;
}

/*
    Destructs the StringTokenizer.
 */
void delete_Scanner(Scanner *ptr) {
    free(ptr->line);
    free(ptr);
}

/**
 * Finds and returns the next complete token from the specified scanner.
 *
 * @param ptr The allocated structure
 * @return the next token
 */
String *next(Scanner *ptr) {
    return _getNextToken(ptr);
}

/**
 * Scans the next token of the input into a boolean value and returns that
 * value.
 *
 * @param ptr The allocated structure
 * @return the boolean scanned from the input
 */
bool nextBoolean(Scanner *ptr) {
    return Boolean_parseBoolean(_getNextToken(ptr));
}

/**
 * Scans the next token of the input as a byte.
 *
 * @param ptr The allocated structure
 * @return the byte scanned from the input
 */
int8_t nextByte(Scanner *ptr) {
    return Byte_parseByte(_getNextToken(ptr));
}

/**
 * Scans the next token of the input as a short.
 *
 * @param ptr The allocated structure
 * @return the short scanned from the input
 */
int16_t nextShort(Scanner *ptr) {
    return Short_parseShort(_getNextToken(ptr));
}

/**
 * Scans the next token of the input as an int.
 *
 * @param ptr The allocated structure
 * @return the int scanned from the input
 */
int32_t nextInt(Scanner *ptr) {
    return Integer_parseInt(_getNextToken(ptr));
}

/**
 * Scans the next token of the input as a long.
 *
 * @param ptr The allocated structure
 * @return the long scanned from the input
 */
int64_t nextLong(Scanner *ptr) {
    return Long_parseLong(_getNextToken(ptr));
}

/**
 * Scans the next token of the input as a float.
 *
 * @param ptr The allocated structure
 * @return the float scanned from the input
 */
float nextFloat(Scanner *ptr) {
    return Float_parseFloat(_getNextToken(ptr));
}

/**
 * Scans the next token of the input as a double.
 *
 * @param ptr The allocated structure
 * @return the double scanned from the input
 */
double nextDouble(Scanner *ptr) {
    return Double_parseDouble(_getNextToken(ptr));
}

/**
 * Advances the specified scanner past the current line and returns the input that was skipped.
 *
 * @param ptr The allocated structure
 * @return the line that was skipped
 */
String *nextLine(Scanner *ptr) {
    // reading the next line if the current is empty
    if (strlen(ptr->line) == 0) {
        return _readLine();
    }
    
    // returning the rest of the current line if not empty
    String *str = new_String(ptr->line);
    free(ptr->line);
    ptr->line = malloc(sizeof(char));
    ptr->line[0] = '\0';

    return str;
}