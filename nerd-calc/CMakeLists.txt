cmake_minimum_required(VERSION 3.10)
project(NerdCalc)

include_directories(src)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/src_build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/src_build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(SOURCES src/main.c src/util.c src/calc.c)

set(TEST_SOURCES tests/test_main.c tests/test_util.c tests/test_calc.c)

add_executable(nerd_calc ${SOURCES})

add_executable(nerd_calc_test ${SOURCES} ${TEST_SOURCES})

enable_testing()
add_test(NAME RunTests COMMAND nerd_calc_test)
