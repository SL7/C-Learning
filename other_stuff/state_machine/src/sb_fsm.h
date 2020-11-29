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

typedef struct state_def {
    char name[255];
    sbTransition (*func)(void);
    sbTransition accepts[16]; 
}sbStateDef;

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

sbTransition sbIdleState(void);
sbTransition sbSelfTestState(void);
sbTransition sbStartupState(void);
sbTransition sbFlightStartState(void);
sbTransition sbAscendState(void);
sbTransition sbDescendState(void);
sbTransition sbRecoveryState(void);
sbTransition sbErrorState(void);

int fetchTransition(

sbStateDef states[8] {
    {"Idle", sbIdleState, {sbAny}},
    {"Self Test", sbSelfTestState, {sbSelfTestTrans}},
    {"Startup", sbStartupState, {sbStartupTrans}},
    {"Flight Start", sbFlightStartState, {sbStartupOK}},
    {"Ascend", sbAscendState, {sbFlightStartOK}},
    {"Descend", sbDescendState, {sbAscendOK}},
    {"Recovery", sbRecoveryState, {sbDescendOK}},
    {"Error", sbErrorState, {sbErr}}
};



#endif
