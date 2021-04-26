cmake_minimum_required(VERSION 3.16)
project(StegoLib)

set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
set(DATASET_DIR "${PROJECT_SOURCE_DIR}/dataset")
set(TESTS_DIR "${PROJECT_SOURCE_DIR}/tests")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

include_directories(${SOURCE_DIR})

add_subdirectory(${SOURCE_DIR})
add_subdirectory(${DATASET_DIR})
add_subdirectory(${TESTS_DIR})
