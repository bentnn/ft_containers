cmake_minimum_required(VERSION 3.20)
project(ft_containers)

set(CMAKE_CXX_STANDARD 98)

add_executable(ft_containers main.cpp vector/vector.hpp iterators/iterators.hpp stack/stack.hpp utils/utils.hpp)
