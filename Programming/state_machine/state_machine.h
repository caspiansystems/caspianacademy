#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#define NUM_SYS_SATETS		4		/* Total number of system states */


/* System states enumeration */
typedef enum {
	STATE_START,
	STATE_STOP,
	STATE_SLOW,
	STATE_FAST
} sys_state_t;

/* System state requests */
typedef enum {
	STATE_START_REQ,
	STATE_STOP_REQ,
	STATE_SLOW_REQ,
	STATE_FAST_REQ
} sys_state_req_t;

/* System state control structure */
typedef struct {
	sys_state_req_t state_req;
	sys_state_t state;
} sys_state_ctl_t;

/* State callback function type */
typedef void (*p_state_callback)(sys_state_ctl_t *p_state_ctl);


/* Function prototypes */
void run_system_state_machine(sys_state_ctl_t *p_state_ctl);

#endif /* STATE_MACHINE_H */

