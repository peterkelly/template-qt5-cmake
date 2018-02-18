cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)
project(sample-app)

# General setup for CMake directories
message("Source directory is " ${CMAKE_SOURCE_DIR})
message("Build directory is " ${CMAKE_BINARY_DIR})

# Make sure we're not building in the root of the source tree
if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR
    "
    Building in the source directory is not supported. Instead, you should
    create another directory specifically for the build. For example:

    mkdir ${CMAKE_SOURCE_DIR}/build
    cd ${CMAKE_SOURCE_DIR}/build
    cmake -G \"${CMAKE_GENERATOR}\" ${CMAKE_SOURCE_DIR}

    Before this will work, you should delete CMakeCache.txt and
    the CMakeFiles directory that were just generated in the source
    directory.")
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)

# Find dependencies and set include/link paths
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Concurrent REQUIRED)

# Settings required for Qt
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

# Define the main executable to be compiled and the source files used
set(MainSources
    src/main.cpp
)

include_directories(../src/analysis)
add_executable(sample-app ${MainSources})
source_group(src FILES ${MainSources})
target_link_libraries(sample-app Qt5::Widgets)
target_link_libraries(sample-app Qt5::Concurrent)
