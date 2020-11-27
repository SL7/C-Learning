#include <stdio.h>
#include <stdlib.h>

typedef enum {
    STATE_SWITCH_ERR,
    STATE_RESET_ERR
}STATE_ERR;

typedef enum {
    IDLE,
    SELF_CHECK,
    STARTUP,
    COMMAND,
    PRE_FLIGHT_CHECK,
    ASCEND,
    DESCEND,
    RECOVERY,
    ERROR
}STATES;

STATES set_state(STATES new_state);

char states[9][255] = {"IDLE", "SELF_CHECK", "STARTUP", "COMMAND", "PRE_FLIGHT_CHECK", "ASCEND", "DESCEND", "RECOVERY", "ERROR"};
char **test_states = malloc(9 * 255 * sizeof(char));


int main() {
    STATES state = IDLE;
    switch(state) {
        case IDLE:
            printf("%s\n", states[IDLE]);  
            break;
        default:
            printf("no matching state\n");
    }
}


STATES set_state(STATES new_state) {
    return new_state;
}

