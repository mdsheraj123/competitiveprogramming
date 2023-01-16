cmake_minimum_required(VERSION 3.0.0)
project(cp VERSION 0.1.0)

include(CTest)
enable_testing()

add_definitions(-DI_AM_DEBUGGING)

add_executable(cp main.cpp)

# testing binary
add_executable(cpCtest cpCtest.cpp)# define tests
add_test(
  NAME cpCtest
  COMMAND $<TARGET_FILE:cpCtest>
  )

target_compile_features(cp PRIVATE cxx_std_17)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
