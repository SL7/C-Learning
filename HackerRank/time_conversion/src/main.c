#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *time_conversion(char *time);

int main(void) {
    printf("%s\n", time_conversion("07:01:11AM"));

    return 0;
}

char *time_conversion(char *time) {
    char *out = malloc(sizeof(time) + 1);
    int hh, mm, ss;
    char tt[3];
    sscanf(time, "%d:%d:%d%s", &hh,&mm,&ss,tt);
    if (strcmp(tt, "PM") == 0 && hh!=12) {
        hh += 12;
    }
    if (strcmp(tt, "AM") == 0 && hh==12) {
        hh = 0;
    }
    sprintf(out, "%02d:%02d:%02d", hh, mm, ss);
    return out;
}