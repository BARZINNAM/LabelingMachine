cmake_minimum_required(VERSION 3.14)
project(LabelingMachine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(include)

# Add a shared or static library
add_library(LabelingMachineLib
    src/Controller.cpp
    src/Conveyor.cpp
    src/Printer.cpp
    src/Scale.cpp
    src/ThermalDirectStrategy.cpp
    src/ThermalTransferStrategy.cpp
)

# Main app
add_executable(LabelingMachine src/main.cpp)

target_link_libraries(LabelingMachine 
    PRIVATE pthread
    LabelingMachineLib)



# ---- Unit Testing ----
enable_testing()

# Add GoogleTest from local folder
add_subdirectory(Third-party/googletest)

include_directories(
    ${gtest_SOURCE_DIR}/include
    ${gmock_SOURCE_DIR}/include
)

add_executable(LabelingMachineTests 
    tests/test_labeling_machine.cpp
    tests/mock_printer.h
)

target_link_libraries(LabelingMachineTests
    LabelingMachineLib
    gmock
    gtest
    gtest_main
    pthread
)

add_test(NAME LabelingMachineTests COMMAND LabelingMachineTests)