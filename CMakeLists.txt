cmake_minimum_required(VERSION 3.1)
project(issue_me)

set(CMAKE_CXX_STANDARD 17)

# Define Paths.
set ( ISSUE_ROOT ${CMAKE_CURRENT_SOURCE_DIR} )
set ( SRC_PATH ${ISSUE_ROOT}/src )

# Define Sources
set(SRC_FILES

        # Models
        ${SRC_PATH}/model/model.h
        ${SRC_PATH}/model/document.cpp
        ${SRC_PATH}/model/document.h
)


set(MAIN_SRC_FILES
        ${SRC_PATH}/main.cpp
        )

# Define Include Directory
include_directories ( .
        ${SRC_PATH}
        ${ISSUE_ROOT}/include
        )

# Add Sub Directory
add_subdirectory( test )

# Make Executable
add_executable(issue_me ${SRC_FILES} ${MAIN_SRC_FILES})
