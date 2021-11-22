#ifndef TESTING_HPP
#define TESTING_HPP

#include <iostream>
#include <vector>
#include <map>
#include <stack>
//#include <chrono>
#include <cstdlib>
#include "../stack/stack.hpp"
#include "../tree/RBTree.hpp"
#include "../map/map.hpp"
#include "../set/set.hpp"


void test_stack_comparison();

template<class A, class B>
void compare_assert(A stdv1, A stdv2, B v1, B v2, std::string name);
void stack_testing();
void vector_insert_test();

#endif
