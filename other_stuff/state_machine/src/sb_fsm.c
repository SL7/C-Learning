#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sb_fsm.h"

/*
 * Author: SL7
 * Version: v1.1
 * 
 * Changelog:
 *  |
 *  |__v1.0:
 *  |    |__ inital commit
 *  |
 *  |__v1.1:
 *       |__ changed transition array structure
 *       |__ added command line
 *       |__ changed states
 *       |__ added states
 */

/**
 * Idle state to take commands
 * @returns sbTransition - Transition code
 */
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

/**
 * Self Test or Self Diagnosis Check to test if all the 
 * components are working well
 * <br>
 * Returns <sbSelfTestOK> on success,
 * <sbErr> on failure
 * @returns sbTransition - Transition code
 */
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
    printf("Ascend State\n");
    if (err == 0) {
        return sbAscendOK;
    } else if (err == 1) {
        return sbRepeat;
    } else {
        return sbErr;
    }
}

sbTransition sbDescendState(void) {
    int err = 0;
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

sbTransition sbEndState(void) {
    printf("Accepted\n");
    char *input = malloc(255 * sizeof(char));
    while(1) {
        printf("> ");
        scanf("%s", input);
        getc(stdin); 
        if (strcmp(input, "restart") == 0) {
            return sbEndOK;
        }
    }
    return sbErr;
}


sbState fetchNextState(sbState state, sbTransition ret) {
    
    int i,j;
    i = 0;
    while (i < sizeof(states[state].transitions)/sizeof(sbStateTrans)) {
        if (ret == states[state].transitions[i].trans) {
            return states[state].transitions[i].state;
        }
        i++;
    }
    return sbError;
}
