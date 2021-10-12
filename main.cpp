#include <iostream>

#include <vector>
#include <stack>
#include <iterator>
#include <map>
#include <set>

//#include "iterators.hpp"
#include "stack.hpp"
#include "vector.hpp"

struct test {
	int a;
};

int main() {
	std::vector<int> v(4, 1);
	v[3] = 11;
	std::vector<int>::iterator it(v.begin());
	std::vector<int>::const_iterator it2 (v.end());

	std::cout << (it.base() < it2.base());

//	ft::vector<int>::const_iterator it  = v.begin();
//	std::cout << it[2] << std::endl;

//	}
//	catch (std::exception e) {
//		std::cout << e.what() << std::endl;
//	}
	//std::cout << v2[0] << std::endl;
//	ft::vector<int> v(3);
//	v[1] = 1;
//	v[2] = 2;
//	ft::vector<int>::const_iterator it = v.begin();
//	it++;
//	std::cout << *it << std::endl;

//	std::cout << v[0] << std::endl;
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
