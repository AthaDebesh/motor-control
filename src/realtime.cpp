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

void setCPUAffinity() {
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(2, &cpuset);  // Run on CPU Core 2

    if (sched_setaffinity(0, sizeof(cpu_set_t), &cpuset) != 0) {
        std::cerr << "Failed to set CPU affinity!\n";
    } else {
        std::cout << "CPU Affinity set to Core 2\n";
    }
}

