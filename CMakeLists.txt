cmake_minimum_required(VERSION 3.20)
project(ft_containers)

set(CMAKE_CXX_STANDARD 98)

add_executable(ft_containers testing/main.cpp vector/vector.hpp stack/stack.hpp testing/testing.hpp testing/stack_testing.cpp iterators/reverse_iterator.hpp
        map/map.hpp utils/pair.hpp testing/vector_testing.cpp tree/RBTree.hpp set/set.hpp utils/utility.hpp iterators/tree_iterator.hpp utils/node.hpp)
