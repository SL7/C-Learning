#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sb_fsm.h"


sbTransition sbIdleState(void) {
    int err = 1;  
    while(1) {
        char *input = malloc(255 * sizeof(char));
        printf("Idle State\n");
        printf("> ");
        scanf("%s", input); 
        getc(stdin);
        if (strcmp(input, "startup") == 0){
            return sbStartupTrans;
        } else if (strcmp(input, "selftest") == 0) {
            return sbSelfTestTrans;
        } else if (strcmp(input, "help") == 0) {
            printf("<startup>   : Initialize the startup procedure\n");
            printf("<selftest>  : Initialize module check\n");
            continue;
        }
        printf("\ntype 'help' to get the commands\n");
    }
}

sbTransition sbSelfTestState(void) {
    int err = 0;
    while (1) {
        printf("Self Test\n");
        if (err == 0) {
            return sbStartupTrans;
        } else if (err == 1) {
            return sbErr;
        }
    }
}

sbTransition sbStartupState(void) {
    int err = 0;
    while (1) {
        printf("Startup State\n");
        if (err == 0) {
            return sbStartupOK;
        } else {
            return sbErr;
        }
    }
}

sbTransition sbFlightStartState(void) {
    int err = 0;
    while (1) {
        printf("Flight Start\n");
        if (err == 0) {
            return sbFlightStartOK;
        } else {
            return sbErr;
        }
    }
}

sbTransition sbAscendState(void) {
    int err = 0;
    while (1) {
        printf("Ascend State\n");
        if (err == 0) {
            return sbAscendOK;
        } else {
            return sbErr;
        }
    }
}

sbTransition sbDescendState(void) {
    int err = 1;
    while (1) {
        printf("Descend State\n");
        if (err == 0) {
            return sbDescendOK;
        } else {
            return sbErr;
        }
    }
}

sbTransition sbRecoveryState(void) {
    int err = 0;
    while (1) {
        printf("Recovery State\n");
        if (err == 0) {
            return sbRecoveryOK;
        } else {
            return sbErr;
        }
    }
}

sbTransition sbErrorState(void) {
    int err = 0;
    while (1) {
        printf("Error State\n");
        return sbAny;
    }
}

sbState fetchNextState(sbState state, sbTransition ret) {
    
    int i,j;
    i = 0;
    while (i < sizeof(states[state].transitions)) {
        if (ret == states[state].transitions[i].trans) {
            return states[state].transitions[i].state;
        }
        i++;
    }
    return sbError;
}
