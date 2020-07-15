# Sample square root application

#cmake_minimum_required(VERSION 2.6)

# Locate GTest
#find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
#add_executable(runTests SquareRootTest.cpp)
#target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)





#Sample with parameterized example

cmake_minimum_required(VERSION 3.5)
project(runTests)

enable_testing()
find_package(GTest)

include(ExternalProject)
if(NOT ${GTEST_FOUND}) # Download gtest if not installed
    message("No system gtest use external project")
    ExternalProject_Add(googletest
            GIT_REPOSITORY    https://github.com/google/googletest.git
            GIT_TAG           master
            SOURCE_DIR        "${CMAKE_BINARY_DIR}/googletest-src"
            BINARY_DIR        "${CMAKE_BINARY_DIR}/googletest-build"
            CONFIGURE_COMMAND ""
            BUILD_COMMAND     ""
            INSTALL_COMMAND   ""
            TEST_COMMAND      ""
            )
    add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
            ${CMAKE_BINARY_DIR}/googletest-build
            EXCLUDE_FROM_ALL)
    set(GTEST_BOTH_LIBRARIES gtest gtest_main)
endif()

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${CMAKE_BINARY_DIR}/test)
include_directories(include)


set(CMAKE_CXX_STANDARD 14)

add_executable(runTests test/main.cpp include/LeapYear.h
        src/LeapYear.cpp test/LeapYearStandaloneTests.cpp)
target_link_libraries(runTests ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
add_test(NAME runTests COMMAND runTests)

if( CMAKE_BUILD_TYPE STREQUAL "Coverage" )
message(STATUS "Coverage: Enabled")
SET(GCC_COVERAGE_COMPILE_FLAGS "-g -O0 -coverage -fprofile-arcs -ftest-coverage")
SET(GCC_COVERAGE_LINK_FLAGS    "-coverage -lgcov")
SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
SET( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}" )
endif()


