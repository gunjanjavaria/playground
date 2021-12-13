# Part of build system for Playground module
#

# Specify the name of the current binary
set(APP_NAME app)
set(APP_NAME_TEST app_test)

#
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
option(BUILD_TESTING "Build unit tests" ON)

## custom settings #############################################################
file(TO_CMAKE_PATH "$ENV{EXTRA_INCLUDE_PATHS}" EXTRA_INCLUDE_PATHS)
file(TO_CMAKE_PATH "$ENV{EXTRA_LIB_PATHS}" EXTRA_LIB_PATHS)

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to RelWithDebInfo")
    set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE)
endif()

set(CMAKE_DEBUG_POSTFIX "_d")
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/dist")

## other settings
cmake_policy(SET CMP0020 NEW)
 
#
# custom includes
include_directories(
    SYSTEM
    ${EXTRA_INCLUDE_PATHS}
)

# custom link folders
link_directories(
    ${EXTRA_LIB_PATHS}
)

find_package(GTest REQUIRED)
#
# Extract working copy information for versioning
execute_process(
  COMMAND git rev-parse --abbrev-ref HEAD
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE GIT_BRANCH
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process(
  COMMAND git log -1 --format=%h
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE GIT_COMMIT_HASH
  OUTPUT_STRIP_TRAILING_WHITESPACE
)
add_definitions( -DZN_SVNREVISION="${GIT_COMMIT_HASH}")
message(STATUS "Building from commit: ${GIT_COMMIT_HASH} @${GIT_BRANCH}")

# the build time macro
string(TIMESTAMP BUILDTIME "%Y%m%dT%H%M")
add_definitions( -DZN_BUILDTIME="${BUILDTIME}")

# enable cppcheck static analysis
#set( CMAKE_CXX_CPPCHECK cppcheck )

## Setup the Source Files
set( PRJ_SRC
    main.cpp
    calculate.cpp
)

set( PRJ_TEST_SRC 
    calculate.cpp
    test.cpp
)

## Setup the Executable
add_executable( ${APP_NAME} ${PRJ_SRC} )

if( BUILD_TESTING )
    enable_testing()

    add_executable( ${APP_NAME_TEST} ${PRJ_TEST_SRC} )
    add_test( ${APP_NAME_TEST} 
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${APP_NAME_TEST})
    target_link_libraries(
        ${APP_NAME_TEST}
       -lgtest -lgtest_main -lpthread
    )
endif()
                   
#
# compiler options
target_compile_options( ${APP_NAME} PUBLIC -Wall -Wextra -Wduplicated-cond
        -Wnull-dereference -Wold-style-cast -Wuseless-cast -Wshadow -Wpedantic 
        -Wno-deprecated-declarations )

target_link_libraries(
    ${APP_NAME}
)

