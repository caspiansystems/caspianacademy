#include "event.h"

/* Array of events */
static event_t events[NUM_EVENTS];

/* Providing access to events array */
event_t *get_events(void) {
    return &events[0];
}

/* Event handlers
 * Each handler receives a message from the event and print it in the terminal. */
void event_1_handler(const char *p_str) {
    printf("Event %d message: ", (uint16_t)EVENT_1_ID);
    printf(p_str);
}

void event_2_handler(const char *p_str) {
    printf("Event %d message: ", (uint16_t)EVENT_2_ID);
    printf(p_str);
}

void event_3_handler(const char *p_str) {
    printf("Event %d message: ", (uint16_t)EVENT_3_ID);
    printf(p_str);
}

/* Registering each event by assigning relevant ID and handler */
void register_event(uint16_t event_id, p_event_handler p_handler) {
    static uint16_t event_num = 0;
    events[event_num].id = event_id;
    events[event_num].handler = p_handler;
    event_num++;
}

/* A dummy event generator. It triggers a random event and returns the event ID.
 * It also creates a message for the corresponding event */
uint16_t read_event(char *p_msg) {
    const uint16_t id[NUM_EVENTS] = {EVENT_1_ID, EVENT_2_ID, EVENT_3_ID};
    uint32_t event_num = (rand() % NUM_EVENTS) + 1;     /* Random event number between 1-3 */
    char p_str[64];

    strcpy(p_msg, "Event ");
    itoa(event_num, p_str, 10);
    strcat(p_msg, p_str);
    strcpy(p_str, " is triggered.\n");
    strcat(p_msg, p_str);

    return id[--event_num];
}
