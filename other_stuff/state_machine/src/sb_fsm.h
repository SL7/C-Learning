#ifndef _SB_FSM
#define _SB_FSM

/**
 * Transition codes
 * used to navigate from current to the next state
 */
typedef enum {
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
} sbTransition;
/**
 * State Definitions
 */
typedef enum {
    sbIdle,
    sbSelfTest,
    sbStartup,
    sbFlightStart,
    sbAscend,
    sbDescend,
    sbRecovery,
    sbError,
    sbEnd,
    sbStatesSize
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
typedef struct {
    char *name;
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
static const sbStateDef states[] = {
    [sbIdle] = {"Idle", sbIdleState,                {{sbStartupTrans, sbStartup}, {sbSelfTestTrans, sbSelfTest}}},
    [sbSelfTest] = {"Self Test", sbSelfTestState,       {{sbStartupTrans, sbStartup}, {sbErr, sbIdle}}},
    [sbStartup] = {"Startup", sbStartupState,          {{sbStartupOK, sbFlightStart}, {sbErr, sbIdle}}},
    [sbFlightStart] = {"Flight Start", sbFlightStartState, {{sbFlightStartOK, sbAscend}, {sbErr, sbError}}},
    [sbAscend] = {"Ascend", sbAscendState,            {{sbAscendOK, sbDescend}, {sbErr, sbError}, {sbRepeat, sbAscend}}},
    [sbDescend] = {"Descend", sbDescendState,          {{sbDescendOK, sbRecovery}, {sbErr, sbError}, {sbRepeat, sbDescend}}},
    [sbRecovery] = {"Recovery", sbRecoveryState,        {{sbRecoveryOK, sbEnd}, {sbErr, sbError}, {sbRepeat, sbRecovery}}},
    [sbError] = {"Error", sbErrorState,              {{sbRepeat, sbError}}},
    [sbEnd] = {"End", sbEndState,                  {}}
};


#endif
