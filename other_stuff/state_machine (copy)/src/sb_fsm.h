#ifndef _SB_FSM
#define _SB_FSM

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
    sbAny
}sbTransition;

typedef enum states {
    sbIdle,
    sbSelfTest,
    sbStartup,
    sbFlightStart,
    sbAscend,
    sbDescend,
    sbRecovery,
    sbError
} sbState;

typedef struct state_trans {
    sbTransition trans;
    sbState state;
}sbStateTrans;

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

sbState fetchNextState(sbState, sbTransition);


static sbStateDef states[8] = {
    {"Idle", sbIdleState,               {{sbStartupTrans, sbStartup}, {sbSelfTestTrans, sbSelfTest}}},
    {"Self Test", sbSelfTestState,      {{sbStartupTrans, sbStartup}, {sbErr, sbIdle}}},
    {"Startup", sbStartupState,         {{sbStartupOK, sbFlightStart}, {sbErr, sbIdle}}},
    {"Flight Start", sbFlightStartState,{{sbFlightStartOK, sbAscend}, {sbErr, sbError}}},
    {"Ascend", sbAscendState,           {{sbAscendOK, sbDescend}, {sbErr, sbError}}},
    {"Descend", sbDescendState,         {{sbDescendOK, sbRecovery}, {sbErr, sbError}}},
    {"Recovery", sbRecoveryState,       {{sbRecoveryOK, sbIdle}, {sbErr, sbError}}},
    {"Error", sbErrorState,             {{sbAny, sbError}}}
};


#endif
