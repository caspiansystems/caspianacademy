#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

#include "event.h"


static char p_msg[64];

int main() {
    uint16_t event_id;
    uint16_t itr;
    event_t *p_events;

    stdio_init_all();

    /* Register the events */
    register_event(EVENT_1_ID, event_1_handler);
    register_event(EVENT_2_ID, event_2_handler);
    register_event(EVENT_3_ID, event_3_handler);

    /* Get access to the events array */
    p_events = get_events();

    for (;;) {
        sleep_ms(1000);

        /* Read an event */
        event_id = read_event(&p_msg[0]);

        /* Check for the event ID and pass the event message to the corresponding handler. */
        for (itr = 0; itr < NUM_EVENTS; itr++) {
            if (p_events[itr].id == event_id) {
                p_events[itr].handler(&p_msg[0]);
            }
        }
    }
    return 0;
}
