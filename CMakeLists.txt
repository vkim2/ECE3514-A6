cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(dsac)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(dsac src/main.cpp)

add_executable(my_test 
                tests/test_vector.cpp 
                #tests/test_vector_iterator.cpp
                #tests/test_vector_const_iterator.cpp
                #tests/test_vector_rule_of_five.cpp
                )

enable_testing()
add_test(NAME my_test COMMAND my_test)