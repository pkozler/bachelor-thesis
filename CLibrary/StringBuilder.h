#ifndef STRINGBUILDER_INCLUDED
#define	STRINGBUILDER_INCLUDED

typedef struct {
    char *buffer;
    int32_t count;
    int32_t capacity;
} StringBuilder;

StringBuilder *new_StringBuilder();
void delete_StringBuilder(StringBuilder *ptr);
StringBuilder *append(StringBuilder *ptr, String *str);
String *toStringSb(StringBuilder *ptr);

#endif	/* STRINGBUILDER_INCLUDED */