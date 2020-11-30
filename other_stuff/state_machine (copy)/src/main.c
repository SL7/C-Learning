#include <stdio.h>
#include <stdlib.h>
#include "sb_fsm.h"

int main(void) {
    
    sbState curr_state = sbIdle;  
    
    sbTransition (*run_func)(void);

    while (1) {
        sbTransition ret = states[curr_state].func(); 

        curr_state = fetchNextState(curr_state, ret);
        for(int j = 10000000; j > 0; j--); 
    }

    return 0;
}
