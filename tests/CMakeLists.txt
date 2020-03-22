add_subdirectory(/usr/src/gtest
                 ${PROJECT_BINARY_DIR}/gtest)

include(CTest)

add_executable(laby_test laby_test.cpp)

include_directories(${PROJECT_SOURCE_DIR}/src/labyrinth)

target_link_libraries(laby_test laby gtest gtest_main)

add_test(
    NAME laby_test
    COMMAND ${EXECUTABLE_OUTPUT_PATH}/laby_test
)

