cmake_minimum_required(VERSION 3.0.0)
project(cp VERSION 0.1.0)

include(CTest)
enable_testing()

add_definitions(-DI_AM_DEBUGGING)

add_executable(cp main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
