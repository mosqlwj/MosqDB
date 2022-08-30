cmake_minimum_required(VERSION 3.23)
project(MosqDB)

set(CMAKE_CXX_STANDARD 14)
set(DEMO_DIR ${PROJECT_SOURCE_DIR}/src/include/demo)
include_directories(${DEMO_DIR})

set(MOSQDB_DIR ${PROJECT_SOURCE_DIR}/src/include/mosqdb)
include_directories(${MOSQDB_DIR})

add_subdirectory(src)
add_subdirectory(test)

enable_testing()