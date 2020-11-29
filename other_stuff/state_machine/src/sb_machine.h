#include <stdlib.h>
#include <stdio.h>

#ifndef _SB_MACHINE
#define _SB_MACHINE

typedef enum {
    sb_STATE_SWITCH_ERR,
    sb_STATE_INTERNAL_ERR,
    sb_STATE_RESET_ERR,
    sb_SUCCESS,
    sb_ERROR_HANDLER
}sb_state_err;

typedef enum {
    sb_IDLE,
    sb_SELF_CHECK,
    sb_STARTUP,
    sb_FLIGHT_START,
    sb_ASCEND,
    sb_DESCEND,
    sb_RECOVERY,
    sb_ERROR
}sb_state;

sb_state set_state(sb_state new_state);

//char sb_states[9][255] = {"IDLE", "SELF_CHECK", "STARTUP", "PRE_FLIGHT_CHECK", "FLIGHT_START", "ASCEND", "DESCEND", "RECOVERY", "ERROR"};

sb_state_err sbIdleStateHandler(sb_state *state, char* mode);
sb_state_err sbSelfCheckStateHandler(sb_state *state);
sb_state_err sbStartupStateHandler(sb_state *state);
sb_state_err sbFlightStartStateHandler(sb_state *state);
sb_state_err sbAscendStateHandler(sb_state *state);
sb_state_err sbDescendStateHandler(sb_state *state);
sb_state_err sbRecoveryStateHandler(sb_state *state);
sb_state_err sbErrorHandler(sb_state *state);

#endif
