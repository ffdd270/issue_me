cmake_minimum_required(VERSION 3.1)
project(issue_me_test)


set(TEST_SRC_FILES
        ${SRC_PATH}/test/test_main.cpp
        ../src/test/model/test_document.cpp)

include_directories ( .
        ${SRC_PATH}
        ${ISSUE_ROOT}/include
        )


add_executable(issue_me_test ${SRC_FILES} ${TEST_SRC_FILES})
