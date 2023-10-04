cmake_minimum_required(VERSION 3.14)
project(LUCID)

set(CMAKE_CXX_STANDARD 11)
if (POLICY CMP0135)
    cmake_policy(SET CMP0135 NEW)
    set(CMAKE_POLICY_DEFAULT_CMP0135 NEW)
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_subdirectory(include)

add_executable(main src/main.cc)

target_link_libraries(main libraries)
include_directories(usr/include)


enable_testing()
add_executable(testing_all
  tests/sampleTest.cc
)

target_link_libraries(testing_all
    GTest::gtest_main
    libraries
)

include(GoogleTest)
gtest_discover_tests(testing_all)