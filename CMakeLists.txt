cmake_minimum_required(VERSION 3.1)
project(robotElevator)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)

SET(CMAKE_CXX_FLAGS -pthread)

add_executable(robotElevator 
src/main.cpp
src/sensors/Button.cpp
src/sensors/Buttons.cpp
src/actors/PiServo.cpp
src/actors/ServoswitchedElevatorMotor.cpp
src/timers/Timer.cpp
src/statemachine/RobotelevatorStatemachine.cpp
src/statemachine/RobotelevatorStatemachine_sm.cpp)

target_include_directories(robotElevator PRIVATE ${CMAKE_SOURCE_DIR}/src/statemachine ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(robotElevator PRIVATE wiringPi)

