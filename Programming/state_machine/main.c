#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <windows.h>
#include "state_machine.h"


sys_state_req_t gen_random_state_req(void);


int main() {
    sys_state_ctl_t state_ctl;

    /* Init state machine */
    state_ctl.state = STATE_START;
    state_ctl.state_req = STATE_START_REQ;

    for (;;) {
        state_ctl.state_req = gen_random_state_req();
        run_system_state_machine(&state_ctl);
        Sleep(1000);
    }

    return 0;
}


/* Random state request generation */
sys_state_req_t gen_random_state_req(void) {
    sys_state_req_t state_req;
    uint32_t rand_num = (rand() % NUM_SYS_SATETS);     /* Random event number between 0-3 */
    switch (rand_num)
    {
    case 0:
        state_req = STATE_START_REQ;
        break;
    case 1:
        state_req = STATE_STOP_REQ;
        break;
    case 2:
        state_req = STATE_SLOW_REQ;
        break;
    case 3:
        state_req = STATE_FAST_REQ;
        break;
    default:
        state_req = STATE_START_REQ;
        break;
    }
    return state_req;
}