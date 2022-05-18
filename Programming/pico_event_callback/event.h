#ifndef PICO_EVENT_CALLBACK_EVENT_H
#define PICO_EVENT_CALLBACK_EVENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Assign an ID to each event */
#define EVENT_1_ID      1001
#define EVENT_2_ID      1002
#define EVENT_3_ID      1003

/* Total number of events */
#define NUM_EVENTS      3

/* Callback function type for event handling */
typedef void (*p_event_handler)(const char *p_str);

/* Each event has an ID and a handler (callback) */
typedef struct {
    uint16_t id;
    p_event_handler handler;
} event_t;

/* Function prototypes */
event_t *get_events(void);
void event_1_handler(const char *p_str);
void event_2_handler(const char *p_str);
void event_3_handler(const char *p_str);
void register_event(uint16_t event_id, p_event_handler p_handler);
uint16_t read_event(char *p_msg);

#endif //PICO_EVENT_CALLBACK_EVENT_H
