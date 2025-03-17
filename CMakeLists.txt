cmake_minimum_required(VERSION 3.00)
project(KnapsackProblem)

set(CMAKE_CXX_STANDARD 14)

find_package(GTest REQUIRED)

include_directories(include)

set(SOURCE_FILES
        src/main.cpp
)

set(TEST_FILES
        tests/UnboundedKnapsackTests.cpp
)

set(TEST_FILES
        tests/ZeroOneKnapsackTests.cpp
)

set(TEST_FILES
        tests/BoundedKnapsackTests.cpp
)


add_executable(KnapsackProblem ${SOURCE_FILES})

add_executable(Tests ${TEST_FILES})

target_link_libraries(Tests PRIVATE GTest::GTest GTest::Main pthread)

add_test(NAME UnboundedKnapsackTests COMMAND Tests)
add_test(NAME ZeroOneKnapsackTests COMMAND Tests)
add_test(NAME BoundedKnapsackTests COMMAND Tests)
