#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char* data;
    int length;
}String;

String *newString(char* new_str);

char *getString(String *data);

