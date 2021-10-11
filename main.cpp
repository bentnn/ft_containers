#include <iostream>

#include <vector>
#include <stack>
#include <iterator>
#include <map>
#include <set>

#include "iterators.hpp"
#include "stack.hpp"
#include "vector.hpp"

int main() {
	ft::vector<int> v(3);
	v[0] = 2;
	std::cout << v[0] << std::endl;
//	ft::stack<int> s;
//	s.push(2);
//	s.push(32);
//	s.push(1);
//	std::cout << s.top() << std::endl;
//	std::cout << s.size() << std::endl;
//	s.pop();
//	std::cout << s.size() << std::endl;
//	std::stack<int> a;
//	std::stack<int> b;
//
//	b.push(2);
//	a.push(3);
//	b.push(2);
//	b.push(100);
//
//	std::cout << (b > a) << std::endl;
//	int a;
//	std::vector<int> v;
//	v.push_back(2);
//	v.push_back(1);
//	std::vector<int>::iterator it = v.begin();
//	std::vector<int>::reverse_iterator rit = v.rbegin();
//	std::map<int, int> m;
//	std::map<int, int>::iterator irm;
//	std::set<int> st;
//	std::set<int>::iterator sit;
//	std::cout << *it << std::endl;
//	it++;
//	std::cout << *it << std::endl;
//	it++;
//	std::cout << *it << std::endl;
//	it += 99;
//	std::cout << *it << std::endl;
//	return 0;
}
