# CMake generated Testfile for 
# Source directory: /home/athadebesh/projects/motor-control
# Build directory: /home/athadebesh/projects/motor-control/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(Test_Jitter "sudo" "-S" "./jitter-test")
set_tests_properties(Test_Jitter PROPERTIES  WORKING_DIRECTORY "/home/athadebesh/projects/motor-control/build" _BACKTRACE_TRIPLES "/home/athadebesh/projects/motor-control/CMakeLists.txt;39;add_test;/home/athadebesh/projects/motor-control/CMakeLists.txt;0;")
