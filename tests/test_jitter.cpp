#include <iostream>
#include <fstream>
#include <ctime>
#include <cassert>
#include "sensor.hpp"
#include "realtime.hpp"

#define TARGET_INTERVAL_NS 100000000L // 100 ms in nanoseconds
#define JITTER_THRESHOLD_NS 100000L   // 0.1 ms (100 µs) in nanoseconds

int main() {
    setRealTimePriority();

    TemperatureSensor sensor("ABC123");

    struct timespec next, now;
    clock_gettime(CLOCK_MONOTONIC, &next);

    long min_jitter = 999999999, max_jitter = 0;

    for (int i = 0; i < 100; i++) {
        next.tv_nsec += TARGET_INTERVAL_NS;
        if (next.tv_nsec >= 1000000000) {  
            next.tv_sec += next.tv_nsec / 1000000000;
            next.tv_nsec %= 1000000000;
        }

        clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &next, nullptr);

        clock_gettime(CLOCK_MONOTONIC, &now);
        long actual_ns = now.tv_sec * 1000000000L + now.tv_nsec;
        long expected_ns = next.tv_sec * 1000000000L + next.tv_nsec;
        long jitter_ns = actual_ns - expected_ns;

        if (jitter_ns < min_jitter) min_jitter = jitter_ns;
        if (jitter_ns > max_jitter) max_jitter = jitter_ns;

        assert(min_jitter <= JITTER_THRESHOLD_NS && "❌ Min jitter exceeded limit!");
        assert(max_jitter <= JITTER_THRESHOLD_NS && "❌ Max jitter exceeded limit!");
    }

    return 0;
}
