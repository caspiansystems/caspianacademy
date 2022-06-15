# Real-Time Embedded Systems: Utilization Upper Bounds
One important factor in task scheduling is to calculate the upper bound on CPU utilization depending on the scheduling policy. In this repo example, we investigate the rate-monotonic scheduling where real-time tasks have static (fixed) priorities, and a task with higher rate (shorter scheduling period) has higher priority. 
The example software is implemented using freeRTOS on an ESP32 hardware platform.  The configuration is done such that all tasks are running on a single core (CPU 0).


https://www.caspiansystems.dk/