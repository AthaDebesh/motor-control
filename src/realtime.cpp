#include "realtime.hpp"
#include <iostream>
#include <sched.h>
#include <unistd.h>
#include <sys/mman.h>
#include <cstdlib>

void setRealTimePriority()
{
    struct sched_param param;
    param.sched_priority = 99;

    if (sched_setscheduler(0, SCHED_FIFO, &param) == -1) {
        perror("sched_setscheduler failed");
        exit(EXIT_FAILURE);
    }

    if (mlockall(MCL_CURRENT | MCL_FUTURE) == -1) {
        perror("mlockall failed");
        exit(EXIT_FAILURE);
    }
}