#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/gpio.h"

/* Number of empty for loops corresponding time in ms.
 * Shall be tuned for a given system. */
#define LOOP_COUNT_400MS        3100000U
#define LOOP_COUNT_500MS        3850000U
#define LOOP_COUNT_600MS        4600000U
#define LOOP_COUNT_700MS        5350000U

#define TASK_1_GPIO             2
#define TASK_1_PERIOD_MS        1000
#define TASK_1_EXEC_MS          LOOP_COUNT_500MS

#define TASK_2_GPIO             4
#define TASK_2_PERIOD_MS        2000
#define TASK_2_EXEC_MS          LOOP_COUNT_700MS

#define TASK_3_GPIO             5
#define TASK_3_PERIOD_MS        4000
#define TASK_3_EXEC_MS          LOOP_COUNT_700MS


/* Task 1 routine */
void task_1(void *pvParameter) {
    TickType_t las_wakeup;
    volatile uint32_t itr;
    BaseType_t is_scheduled;
    const TickType_t period_ticks = pdMS_TO_TICKS(TASK_1_PERIOD_MS);
    
    gpio_pad_select_gpio(TASK_1_GPIO);
    gpio_set_direction(TASK_1_GPIO, GPIO_MODE_OUTPUT);
    
    las_wakeup = xTaskGetTickCount();
    for(;;) {
        is_scheduled = xTaskDelayUntil(&las_wakeup, period_ticks);
        if (pdTRUE == is_scheduled) {
            printf("Task_1 scheduled successfully.\n");
        } else {
            printf("Task_1 is starving.\n");
        }
        gpio_set_level(TASK_1_GPIO, 1);
        /* A for loop resembling a dummy task */
        for (itr = 0; itr < TASK_1_EXEC_MS; itr++) { }
        gpio_set_level(TASK_1_GPIO, 0);
    }
}

/* Task 2 routine */
void task_2(void *pvParameter) {
    volatile uint32_t itr;
    TickType_t las_wakeup;
    BaseType_t is_scheduled;
    const TickType_t period_ticks = pdMS_TO_TICKS(TASK_2_PERIOD_MS);
    
    gpio_pad_select_gpio(TASK_2_GPIO);
    gpio_set_direction(TASK_2_GPIO, GPIO_MODE_OUTPUT);
    
    las_wakeup = xTaskGetTickCount();
    for(;;) {
        is_scheduled = xTaskDelayUntil(&las_wakeup, period_ticks);
        if (pdTRUE == is_scheduled) {
            printf("Task_2 scheduled successfully.\n");
        } else {
            printf("Task_2 is starving.\n");
        }        
        gpio_set_level(TASK_2_GPIO, 1);
        /* A for loop resembling a dummy task */
        for (itr = 0; itr < TASK_2_EXEC_MS; itr++) { }
        gpio_set_level(TASK_2_GPIO, 0);
    }
}

/* Task 3 routine */
void task_3(void *pvParameter) {
    volatile uint32_t itr;
    TickType_t las_wakeup;
    BaseType_t is_scheduled;
    const TickType_t period_ticks = pdMS_TO_TICKS(TASK_3_PERIOD_MS);
    
    gpio_pad_select_gpio(TASK_3_GPIO);
    gpio_set_direction(TASK_3_GPIO, GPIO_MODE_OUTPUT);
    
    las_wakeup = xTaskGetTickCount();
    for(;;) {
        is_scheduled = xTaskDelayUntil(&las_wakeup, period_ticks);
        if (pdTRUE == is_scheduled) {
            printf("Task_3 scheduled successfully.\n");
        } else {
            printf("Task_3 is starving.\n");
        }
        gpio_set_level(TASK_3_GPIO, 1);
        /* A for loop resembling a dummy task */
        for (itr = 0; itr < TASK_3_EXEC_MS; itr++) { }
        gpio_set_level(TASK_3_GPIO, 0);
    }
}


void app_main() {
    xTaskCreate(&task_1, "task_1", 1024, NULL, 5, NULL);
    xTaskCreate(&task_2, "task_2", 1024, NULL, 4, NULL );
    xTaskCreate(&task_3, "task_3", 1024, NULL, 3, NULL );
}
