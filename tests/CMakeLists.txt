##
## Cmake
##

cmake_minimum_required(VERSION 3.16)

# standard version cpp
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

# project name
project(unit_tests)

# move executable to root
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

#include dirs
include_directories(../include/)

# Fetchcontent is used to download libs (dependencies)
include(FetchContent)

# download google test
FetchContent_Declare(
    googletest
    GIT_REPOSITORY "https://github.com/google/googletest.git"
    GIT_TAG "v1.14.x"
    OVERRIDE_FIND_PACKAGE
)

FetchContent_MakeAvailable(googletest)

enable_testing()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")

add_executable(
    unit_tests

    ../src/Components/Gates/4001.cpp
    ../src/Components/Gates/4011.cpp
    ../src/Components/Gates/4030.cpp
    ../src/Components/Gates/4069.cpp
    ../src/Components/Gates/4071.cpp
    ../src/Components/Gates/4081.cpp
    ../src/Components/TristatesOperators.cpp
    ../src/Components/Elementary/AndComponent.cpp
    ../src/Components/Elementary/NandComponent.cpp
    ../src/Components/Elementary/NorComponent.cpp
    ../src/Components/Elementary/NotComponent.cpp
    ../src/Components/Elementary/OrComponent.cpp
    ../src/Components/Elementary/XorComponent.cpp
    ../src/Components/Specials/Clock.cpp
    ../src/Components/Specials/False.cpp
    ../src/Components/Specials/Input.cpp
    ../src/Components/Specials/Output.cpp
    ../src/Components/Specials/True.cpp
    ../src/Components/Advanced/4008.cpp
    ../src/Components/Advanced/4013.cpp
    ../src/Components/Advanced/4512.cpp
    ../src/Components/Advanced/4514.cpp
    ../src/Components/Advanced/4040.cpp
    ../src/Components/Advanced/4017.cpp
    ../src/Components/Advanced/logger.cpp
    ../src/Components/Advanced/4094.cpp
    ../src/AComponent.cpp
    ../src/Exceptions.cpp
    ../src/Shell.cpp
    ../src/tekspice.cpp
    ../src/Circuit.cpp
    ../src/Factory.cpp
    ../src/Parser.cpp

    test_tekspice.cpp
    test_gates.cpp
    test_advanced.cpp
    )

target_link_libraries(
    unit_tests PRIVATE
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(unit_tests)
