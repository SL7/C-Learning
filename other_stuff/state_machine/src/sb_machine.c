#include "sb_machine.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

sb_state set_state(sb_state new_state) {
    return new_state;
}

/**
 * Handler for Idle State
 * @param mode -> idle state mode
 */
sb_state_err sbIdleStateHandler(sb_state *state, char* mode) {
    char *test = malloc(255 * sizeof(char));
    while (1) {
        printf("> "); 
        scanf("%s", test);
        fgetc(stdin); 
        if (strcmp(test, "self-check") == 0) {
            *state = set_state(sb_SELF_CHECK);
            break;
        } else if (strcmp(test, "exit") == 0) {
            exit(1);
        } else if (strcmp(test, "help") == 0) {
            printf("self-check:  self check the sensors and other serial devices\n");
        } else {
            printf("type 'help' to get all command\n");
            continue;
        }

    }
    return sb_SUCCESS;
}

/**
 * Handler for self check state
 */
sb_state_err sbSelfCheckStateHandler(sb_state *state) {
    printf("Self Check\n");
    return sb_SUCCESS;
}

/**
 * Handler for startup sequence state
 */
sb_state_err sbStartupStateHandler(sb_state *state) {
    return sb_SUCCESS;
}

/**
 * Handler for pre flight check state
 */
sb_state_err sbPreFlightCheckStateHandler(sb_state *state) {
    return sb_SUCCESS;
}

/**
 * Handler for flight start state
 */
sb_state_err sbFlightStartStateHandler(sb_state *state) {
    return sb_SUCCESS;
}

/**
 * Handler for ascend flight state
 */
sb_state_err sbAscendStateHandler(sb_state *state) {
    return sb_SUCCESS;
}

/**
 * Handler for descend flight state
 */
sb_state_err sbDescendStateHandler(sb_state *state) {
    return sb_SUCCESS;
}

/**
 * Handler for awaiting recovery state
 */
sb_state_err sbRecoveryStateHandler(sb_state *state) {
    return sb_SUCCESS;
}

/**
 * Hander for error state
 */
sb_state_err sbErrorHandler(sb_state *state) {
    return sb_ERROR_HANDLER;
}
