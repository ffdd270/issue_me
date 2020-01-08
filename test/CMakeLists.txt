cmake_minimum_required(VERSION 3.15)
project(issue_me_test)

set(TEST_SRC_FILES
        ${SRC_PATH}/test/test_main.cpp
        )

add_executable(issue_me_test ${SRC_FILES} ${TEST_SRC_FILES})