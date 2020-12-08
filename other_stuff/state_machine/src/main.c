#include <stdio.h>
#include <stdlib.h>
#include "sb_fsm.h"
#include <unistd.h>
#include <assert.h>

void delay(unsigned long ms);

int main(void) {
    
    assert(sizeof(states)/sizeof(*states) == sbStatesSize);
    sbState curr_state = sbIdle;  
    
    sbTransition (*run_func)(void);
    while (1) {
        sbTransition ret = states[curr_state].func();

        curr_state = fetchNextState(curr_state, ret);
        delay(500);
    }

    return 0;
}
void delay(unsigned long ms) {
    usleep(ms * 1000);
}
