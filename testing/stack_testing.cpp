//#include "testing.hpp"
//
//void write_gren_str(std::string str) {
//	std::cout << "\033[0;0;32m" << str << "\033[0m";
//}
//
//void tell_them_that_it_is_ok(std::string str) {
//	std::cout << "'" << str << "' ";
//	write_gren_str("is ok\n");
//}
//
//template<class A, class B>
//void compare_assert(A stdv1, A stdv2, B v1, B v2, std::string name) {
//	assert((stdv1 == stdv2) == (v1 == v2) && (stdv1 != stdv2) == (v1 != v2));
//	assert((stdv1 > stdv2) == (v1 > v2) && (stdv1 < stdv2) == (v1 < v2));
//	assert((stdv1 >= stdv2) == (v1 >= v2) && (stdv1 <= stdv2) == (v1 <= v2));
//	tell_them_that_it_is_ok(name);
//}
//
//
//void test_stack_comparison() {
//	std::stack<int> stdv1;
//	std::stack<int> stdv2;
//	ft::stack<int> v1;
//	ft::stack<int> v2;
//
//	compare_assert(stdv1, stdv2, v1, v2, "all is empty");
//
//	for (int i = -5; i < 3; i++){
//		stdv1.push(i);
//		stdv2.push(i);
//		v1.push(i);
//		v2.push(i);
//	}
//
//	compare_assert(stdv1, stdv2, v1, v2, "all is not empty but is equal");
//
//	for (int i = 3; i < 10; i++) {
//		stdv1.push(i);
//		v1.push(i);
//	}
//
//	compare_assert(stdv1, stdv2, v1, v2, "all is not empty and is not equal");
//
//	write_gren_str("Comparison is ok\n");
//}
//
//
//void stack_testing() {
//	std::cout << "__Comparison's operators stack testing__\n";
//	test_stack_comparison();
//
//	std::cout << "\n__Main stack testing__\n";
//	ft::stack<int> st;
//	std::stack<int> stdst;
//
//	assert(st.size() == stdst.size());
//	assert(st.empty() == stdst.empty());
//	//assert(st.top() == stdst.top()); // Must be Seg
//
//	tell_them_that_it_is_ok("Basic constructor");
//
//	for (int i = 0; i < 25; i++) {
//		st.push(i);
//		stdst.push(i);
//		assert(st.size() == stdst.size());
//		assert(st.top() == stdst.top());
//		assert(st.empty() == stdst.empty());
//	}
//	tell_them_that_it_is_ok("Push");
//
//	ft::stack<int> st2(st);
//	std::stack<int> stdst2(stdst);
//
//	assert(st2.size() == stdst2.size());
//	assert(st2.empty() == stdst2.empty());
//	assert(st2.top() == stdst2.top());
//
//	compare_assert(stdst, stdst2, st, st2, "Copy constructor");
//
//	for (int i = 0; i < 20; i++) {
//		st.pop();
//		stdst.pop();
//		assert(st.size() == stdst.size());
//		assert(st.top() == stdst.top());
//		assert(st.empty() == stdst.empty());
//	}
//
//	tell_them_that_it_is_ok("Pop");
//	st = st2;
//	stdst = stdst2;
//
//	assert((stdst == stdst2) == (st == st2) && (stdst != stdst2) == (st != st2));
//
//	stdst = std::stack<int>();
//	st = ft::stack<int>();
//	assert(st.size() == 0);
//	assert(st.empty() == true);
//
//	compare_assert(stdst, stdst2, st, st2, "Operator '='");
//	write_gren_str("All is ok!!!!");
//	std::cout << "at least i think so...\n";
//}
