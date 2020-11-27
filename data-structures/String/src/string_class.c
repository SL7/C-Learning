#include "string_class.h"

String *newString(char* new_str) {
    String *temp = malloc(sizeof(String));
    temp->data = new_str;
    temp->length = strlen(new_str);
    return temp;
}

char *getString(String *data) {
    return data->data;
}

int lengthString(String *data) { 
    return data->length;
}
