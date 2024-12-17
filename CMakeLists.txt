cmake_minimum_required(VERSION 3.28)
project(executor)
set(CMAKE_CXX_STANDARD 17)

enable_testing()

option(BUILD_DEBUG "Builds debug!!!" OFF)
if(BUILD_DEBUG)
    add_compile_options("-g")
endif()

set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(BIN_ROOT ${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(src)
add_subdirectory(lib/googletest-1.15.2)

add_executable(main main.cpp)
add_executable(
        test_executor test/test.cpp
)
add_executable(TestForRoadster test/TestForRoadster.cpp)
add_executable(TestForBus test/TestForBus.cpp)

target_include_directories(main PUBLIC src)
target_link_libraries(main PUBLIC ExecutorLib)

target_include_directories(test_executor PUBLIC src)
target_include_directories(test_executor PUBLIC ${GTEST_INCLUDE_DIRS})
target_link_libraries(test_executor PUBLIC ExecutorLib GTest::gtest GTest::gtest_main)

target_include_directories(TestForRoadster PUBLIC src)
target_include_directories(TestForRoadster PUBLIC ${GTEST_INCLUDE_DIRS})
target_link_libraries(TestForRoadster PUBLIC ExecutorLib GTest::gtest GTest::gtest_main)

target_include_directories(TestForBus PUBLIC src)
target_include_directories(TestForBus PUBLIC ${GTEST_INCLUDE_DIRS})
target_link_libraries(TestForBus PUBLIC ExecutorLib GTest::gtest GTest::gtest_main)

add_test(NAME test_executor COMMAND test_executor)
add_test(NAME TestForRoadster COMMAND TestForRoadster)
add_test(NAME TestForBus COMMAND TestForBus)

# 设置 编译测试选项
option(BUILD_TEST "Builds test!!!" OFF)
if(BUILD_TEST)
    add_subdirectory(tests)
endif()
