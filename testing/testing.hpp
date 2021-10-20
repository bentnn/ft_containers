#ifndef TESTING_HPP
#define TESTING_HPP

#include <iostream>
#include <vector>
#include <stack>
#include <chrono>
#include <cstdlib>
#include "../stack/stack.hpp"

void test_stack_comparison();

template<class A, class B>
void compare_assert(A stdv1, A stdv2, B v1, B v2, std::string name);
void stack_testing();

#endif