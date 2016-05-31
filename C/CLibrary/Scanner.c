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

String *_readLine() {
    StringBuilder *sb = new_StringBuilder();
    char c;
    
    while (true) {
        scanf("%c", &c);
        
        if (c == '\n') {
            String *line = toStringSb(sb);
            delete_StringBuilder(sb);
            
            return line;
        }
        
        char *s = malloc(sizeof(char) * 2);
        s[0] = c;
        s[1] = '\0';
        
        String *str = new_String(s);
        append(sb, str);
        delete_String(str);
        free(s);
    }
}

bool _isEmptyOrWhiteSpace(char *line) {
    int32_t i;
    
    for (i = 0; line[i]; i++) {
        if (!isspace((int) line[i])) {
            return false;
        }
    }
    
    return true;
}

char *_trimStart(char *line) {
    int32_t i;
    
    for (i = 0; isspace((int) line[i]); i++);
    
    return strdup(line + i);
}

char *_removeLineToWhiteSpace(Scanner *ptr) {
    int32_t i;
    char *line;
    char *token;
    
    ptr->line = _trimStart(ptr->line);
    
    for (i = 0; !isspace((int) ptr->line[i]); i++);
    
    token = malloc(sizeof(char) * i);
    token[0] = '\0';
    
    strncat(token, ptr->line, (size_t) i);
    line = strdup(ptr->line + i);
    free(ptr->line);
    ptr->line = line;
    
    return token;
}

String *_getNextToken(Scanner *ptr) {
    while (_isEmptyOrWhiteSpace(ptr->line)) {
        free(ptr->line);
        String *line = _readLine();
        ptr->line = _trimStart(line->s);
        delete_String(line);
    }
    
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
    if (strlen(ptr->line) == 0) {
        return _readLine();
    }
    
    String *str = new_String(ptr->line);
    free(ptr->line);
    ptr->line = malloc(sizeof(char));
    ptr->line[0] = '\0';

    return str;
}