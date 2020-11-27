#include <stdio.h>
#include <stdlib.h>
#include "string_class.h"

int main() {
    String *new_str;
    new_str = newString("Hello World");
    printf("%s\n", getString(new_str));
}

