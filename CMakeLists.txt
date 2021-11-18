# Build file for Playground
#
# (C)2021 Zeus Numerix Pvt. Ltd.

#
# Please read the instructions in the comments and make requisite configurations
cmake_minimum_required(VERSION 3.2)

#
# Set the name of the project here as first argument.
project(playground)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

# Add the subdirectory where another cmakelist exists
add_subdirectory(src)