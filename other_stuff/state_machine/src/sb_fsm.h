#ifndef _SB_FSM
#define _SB_FSM

/**
 * Transition codes
 * used to navigate from current to the next state
 */
typedef enum state_transitions {
    sbStartupTrans,
    sbSelfTestTrans,
    sbStartupOK,
    sbErr,
    sbSelfTestOK,
    sbFlightStartOK,
    sbAscendOK,
    sbDescendOK,
    sbRecoveryOK,
    sbEndOK,
    sbAny,
    sbRepeat
}sbTransition;
/**
 * State Definitions
 */
typedef enum states {
    sbIdle,
    sbSelfTest,
    sbStartup,
    sbFlightStart,
    sbAscend,
    sbDescend,
    sbRecovery,
    sbError,
    sbEnd,
} sbState;

/**
 * State Transition definitions
 * when it encounter <trans> move to <state> State
 */
typedef struct state_trans {
    sbTransition trans;
    sbState state;
}sbStateTrans;

/**
 * State Definition
 * @param name - Name of the State
 * @param func - Function Handler of the State
 * @param transitions - Allowed Transition definitions 
 */
typedef struct state_def {
    char name[255];
    sbTransition (*func)(void);
    sbStateTrans transitions[16];
}sbStateDef;

sbTransition sbIdleState(void);
sbTransition sbSelfTestState(void);
sbTransition sbStartupState(void);
sbTransition sbFlightStartState(void);
sbTransition sbAscendState(void);
sbTransition sbDescendState(void);
sbTransition sbRecoveryState(void);
sbTransition sbErrorState(void);
sbTransition sbEndState(void);

sbState fetchNextState(sbState, sbTransition);

/**
 * Structure: {<state name>, <function pointer> , transitions{{<encounters> -> <state>}}
 */
static sbStateDef states[9] = {
    {"Idle", sbIdleState,                {{sbStartupTrans, sbStartup}, {sbSelfTestTrans, sbSelfTest}}},
    {"Self Test", sbSelfTestState,       {{sbStartupTrans, sbStartup}, {sbErr, sbIdle}}},
    {"Startup", sbStartupState,          {{sbStartupOK, sbFlightStart}, {sbErr, sbIdle}}},
    {"Flight Start", sbFlightStartState, {{sbFlightStartOK, sbAscend}, {sbErr, sbError}}},
    {"Ascend", sbAscendState,            {{sbAscendOK, sbDescend}, {sbErr, sbError}, {sbRepeat, sbAscend}}},
    {"Descend", sbDescendState,          {{sbDescendOK, sbRecovery}, {sbErr, sbError}, {sbRepeat, sbDescend}}},
    {"Recovery", sbRecoveryState,        {{sbRecoveryOK, sbEnd}, {sbErr, sbError}, {sbRepeat, sbRecovery}}},
    {"Error", sbErrorState,              {{sbRepeat, sbError}}},
    {"End", sbEndState,                  {}}
};


#endif
