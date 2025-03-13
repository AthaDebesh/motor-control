cmake_minimum_required(VERSION 3.10)
project(TemperatureMonitoring)

set(CMAKE_CXX_STANDARD 17)

# Add main system executable
add_executable(system
    src/main.cpp
    src/sensor.cpp
    src/motor.cpp
    src/realtime.cpp
)
target_link_libraries(system pthread rt)

# Include directories
target_include_directories(system PRIVATE include)

# Add jitter-test executable
add_executable(test_jitter
    tests/test_jitter.cpp
    src/sensor.cpp
    src/realtime.cpp
)
target_link_libraries(test_jitter pthread rt)

# Include directories for jitter-test
target_include_directories(test_jitter PRIVATE include)

# Link necessary libraries (if needed)
# target_link_libraries(jitter-test pthread)

# Install both executables
install(TARGETS system test_jitter RUNTIME DESTINATION /usr/local/bin)

# Enable testing
enable_testing()

# Register jitter-test as the test executable
add_test(NAME Test_Jitter
        COMMAND sudo -S ./jitter-test
         WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
