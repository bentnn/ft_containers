cmake_minimum_required(VERSION 3.17)
project(ft_containers)

set(CMAKE_CXX_STANDARD 98)

add_executable(ft_containers testing/main.cpp vector/vector.hpp stack/stack.hpp testing/testing.hpp testing/stack_testing.cpp
        map/map.hpp utils/pair.hpp tree/RBTree.hpp
        testing/vector_testing.cpp set/set.hpp)
