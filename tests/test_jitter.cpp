#include <iostream>
#include <ctime>
#include <vector>
#include <cmath>
#include <algorithm>
#include "sensor.hpp"
#include "realtime.hpp"

#define EXPECTED_INTERVAL_NS 100000000L
#define JITTER_THRESHOLD_NS  1000000L

int main() {

    setRealTimePriority();
    setCPUAffinity();

    Sensor TemperatureSensor("ABCDE12");

    Revisions* sensorRevision = &TemperatureSensor;

    sensorRevision->setRev("A");

    struct timespec start_time, end_time;
    std::vector<long> jitter_values;

    double temperature;

    clock_gettime(CLOCK_MONOTONIC_RAW, &start_time);

    for (int i = 0; i < 100; ++i)
    {
        temperature = TemperatureSensor.readTemperature();

        clock_gettime(CLOCK_MONOTONIC_RAW, &end_time);

        long actual_interval_ns = 
            (end_time.tv_sec - start_time.tv_sec) * 1e9 +
            (end_time.tv_nsec - start_time.tv_nsec);

        long jitter_ns = std::abs(actual_interval_ns - EXPECTED_INTERVAL_NS);
        jitter_values.push_back(jitter_ns);

        std::cout << "Iteration " << i+1 << " | Expected: 100ms | Actual: " << actual_interval_ns / 1e6 << " ms | Jitter: " << jitter_ns / 1e3 << " µs" << std::endl;

        start_time = end_time;
    }

    long min_jitter = *std::min_element(jitter_values.begin(), jitter_values.end());
    long max_jitter = *std::max_element(jitter_values.begin(), jitter_values.end());

    if (max_jitter <= JITTER_THRESHOLD_NS) {
        std::cout << "\n✅ Jitter test PASSED! (Min: " 
                  << min_jitter / 1e3 << " µs, Max: " << max_jitter / 1e3 << " µs)" << std::endl;
    } else {
        std::cout << "\n❌ Jitter test FAILED! (Min: " 
                  << min_jitter / 1e3 << " µs, Max: " << max_jitter / 1e3 << " µs)" << std::endl;
    }

    return 0;
}
