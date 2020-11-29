#include <stdio.h>
#include <stdlib.h>
#include "sb_machine.h"

int main() {
    sb_state state = set_state(sb_IDLE);

    while(1) {
        switch(state) {
            case sb_IDLE:
                sbIdleStateHandler(&state, "command");
                break;
            case sb_SELF_CHECK:
                sbSelfCheckStateHandler(&state);
                break;
            case sb_STARTUP:
                sbStartupStateHandler(&state);
                break;
            case sb_FLIGHT_START:
                sbFlightStartStateHandler(&state);
                break;
            case sb_ASCEND:
                sbAscendStateHandler(&state);
                break;
            case sb_DESCEND:
                sbDescendStateHandler(&state);
                break;
            case sb_RECOVERY:
                sbRecoveryStateHandler(&state);
                break;
            case sb_ERROR:
                sbErrorHandler(&state);
                break;
            default:
                printf("No matching State");
                exit(1);
        }
    }
}


