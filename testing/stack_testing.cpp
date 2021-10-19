#include "../stack/stack.hpp"
#include <stack>
#include <vector>

template<class A, class B>
void compare_assert(A stdv1, A stdv2, B v1, B v2, std::string name) {
	assert((stdv1 == stdv2) == (v1 == v2) && (stdv1 != stdv2) == (v1 != v2));
	assert((stdv1 > stdv2) == (v1 > v2) && (stdv1 < stdv2) == (v1 < v2));
	//assert((stdv1 >= stdv2) == (v1 >= v2) && (stdv1 <= stdv2) == (v1 <= v2));
	std::cout << "'" << name << "' is ok\n";
}


void test_stack_comparison() {
	std::stack<int> stdv1;
	std::stack<int> stdv2;
	ft::stack<int> v1;
	ft::stack<int> v2;

	compare_assert(stdv1, stdv2, v1, v2, "all is empty");

	ft::vector<int> vec1(10, 2);
	std::vector<int> vec2(10, 2);

	//stdv1 = std::stack<int>(vec2);
	//stdv2 = std::stack<int>(vec2);
	//v1 = ft::stack<int>(vec1);
	//v2 = ft::stack<int>(vec1);

	compare_assert(stdv1, stdv2, v1, v2, "all is not empty but is equal");

	for (int i = 3; i < 10; i++) {
		stdv1.push(i);
		v1.push(i);
	}

	compare_assert(stdv1, stdv2, v1, v2, "all is not empty and is not equal");

	std::cout << "Comparison is ok\n";
}


void stack_testing() {
	//test_stack_comparison();
}
