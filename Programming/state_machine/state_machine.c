#include <stdio.h>
#include "state_machine.h"

/* Function prototypes */
static void sys_start(sys_state_ctl_t *p_state_ctl);
static void sys_stop(sys_state_ctl_t *p_state_ctl);
static void sys_slow(sys_state_ctl_t *p_state_ctl);
static void sys_fast(sys_state_ctl_t *p_state_ctl);

static void start_exec(void);
static void stop_exec(void);
static void slow_exec(void);
static void fast_exec(void);

static void start_to_stop(void);
static void start_to_slow(void);
static void stop_to_start(void);
static void slow_to_fast(void);
static void slow_to_stop(void);
static void fast_to_slow(void);

/* File scope variables */
static sys_state_req_t g_state_req = STATE_START_REQ;

/* Put state callbacks in a table (shall follow the same order as system state enumeration) */
p_state_callback g_sys_state_callbacks_table[NUM_SYS_SATETS] = {sys_start, sys_stop, sys_slow, sys_fast};


/************************** System state callbacks **************************/
static void sys_start(sys_state_ctl_t *p_state_ctl) {
	start_exec();

	if (p_state_ctl->state_req == STATE_STOP_REQ) {
		start_to_stop();
		p_state_ctl->state = STATE_STOP;
	} 
	else if (p_state_ctl->state_req == STATE_SLOW_REQ) {
		start_to_slow();
		p_state_ctl->state = STATE_SLOW;
	}
	else {
		p_state_ctl->state = STATE_START;
	}
}

static void sys_stop(sys_state_ctl_t *p_state_ctl) {
	stop_exec();

	if (p_state_ctl->state_req == STATE_START_REQ) {
		stop_to_start();
		p_state_ctl->state = STATE_START;
	}
}

static void sys_slow(sys_state_ctl_t *p_state_ctl) {
	slow_exec();

	if (p_state_ctl->state_req == STATE_STOP_REQ) {
		slow_to_stop();
		p_state_ctl->state = STATE_STOP;
	}
	else if (p_state_ctl->state_req == STATE_FAST_REQ) {
		slow_to_fast();
		p_state_ctl->state = STATE_FAST;
	}
	else {
		p_state_ctl->state = STATE_SLOW;
	}
}

static void sys_fast(sys_state_ctl_t* p_state_ctl) {
	fast_exec();

	if (p_state_ctl->state_req == STATE_SLOW_REQ) {
		fast_to_slow();
		p_state_ctl->state = STATE_SLOW;
	}
}


/*************************** State function calls ***************************/
static void start_exec(void) {
	/* Execution code while in START state */
	printf("START state is executing.\n");
}

static void stop_exec(void) {
	/* Execution code while in STOP state */
	printf("STOP state is executing.\n");
}

static void slow_exec(void) {
	/* Execution code while in SLOW state */
	printf("SLOW state is executing.\n");
}

static void fast_exec(void) {
	/* Execution code while in FAST state */
	printf("FAST state is executing.\n");
}


/********************** State transition function calls *********************/
static void start_to_stop(void) {
	/* Required operation when leaving the START state */
	printf("Leaving START state to STOP state ...\n");

	/* Required operation when entering the STOP state */
	printf("Entering STOP state from START state ...\n");
}

static void start_to_slow(void) {
	/* Required operation when leaving the START state */
	printf("Leaving START state to SLOW state ...\n");

	/* Required operation when entering the SLOW state */
	printf("Entering SLOW state from START state ...\n");
}

static void stop_to_start(void) {
	/* Required operation when leaving the STOP state */
	printf("Leaving STOP state to START state ...\n");

	/* Required operation when entering the START state */
	printf("Entering START state from STOP state ...\n");
}

static void slow_to_stop(void) {
	/* Required operation when leaving the SLOW state */
	printf("Leaving SLOW state to STOP state ...\n");

	/* Required operation when entering the STOP state */
	printf("Entering STOP state from SLOW state ...\n");
}

static void slow_to_fast(void) {
	/* Required operation when leaving the SLOW state */
	printf("Leaving SLOW state to FAST state ...\n");

	/* Required operation when entering the FAST state */
	printf("Entering FAST state from SLOW state ...\n");
}

static void fast_to_slow(void) {
	/* Required operation when leaving the FAST state */
	printf("Leaving FAST state to SLOW state ...\n");

	/* Required operation when entering the SLOW state */
	printf("Entering SLOW state from FAST state ...\n");
}


/*********************** System state machine routine ***********************/
void run_system_state_machine(sys_state_ctl_t *p_state_ctl) {	
	g_sys_state_callbacks_table[p_state_ctl->state](p_state_ctl);
}