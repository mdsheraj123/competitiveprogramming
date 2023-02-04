cmake_minimum_required(VERSION 3.0.0)
project(cp VERSION 0.1.0)

include(CTest)
enable_testing()

# Comment this for binary outputs
add_definitions(-DI_AM_DEBUGGING)

add_executable(cp main.cpp)

add_executable(cpCtest testing/cpCtest.cpp)
add_test(
  NAME Test0
  COMMAND $<TARGET_FILE:cp> OUTPUT_TO_FILE
  )
add_test(
  NAME Test1
  COMMAND $<TARGET_FILE:cpCtest>
  )
set_property(TEST Test1 APPEND PROPERTY DEPENDS Test0)

target_compile_features(cp PRIVATE cxx_std_17)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
