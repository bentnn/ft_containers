cmake_minimum_required(VERSION 3.20)
project(ft_containers)

set(CMAKE_CXX_STANDARD 98)

add_executable(ft_containers testing/main.cpp vector/vector.hpp iterators/vector_iterators.hpp stack/stack.hpp utils/utils.hpp testing/testing.hpp testing/stack_testing.cpp
        map/map.hpp utils/pair.hpp tree/RBTree.hpp iterators/tree_iterator.hpp
        map/node.hpp testing/vector_testing.cpp)
