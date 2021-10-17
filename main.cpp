#include <iostream>

#include <vector>
#include <stack>
//#include <iterator>
#include <map>
#include <set>

//#include "iterators.hpp"
#include "stack/stack.hpp"
#include "vector/vector.hpp"

class A {
private:
	int n;
public:
	explicit A (int n): n(n) {}
};




int main() {

	std::vector<int> stdv(5);
	ft::vector<int> v(2);
	for (int i = 0; i < v.size(); i++) {
		v[i] = i + 1;
		stdv[i] = i + 1;
	}
	//size_t l = -1;
//	std::cout << l  << "\n" << stdv.max_size()<< std::endl;
	//assert(*v.erase(v.begin()) == *stdv.erase(stdv.begin()));
	try {
//		stdv.insert(stdv.end(), stdv.max_size() - 5, 3);
		//std::vector<int>::iterator it = stdv.erase(stdv.begin(), stdv.end() + 1);
//		stdv.insert(stdv.end() + 2, 2, 1);
//		stdv.insert(stdv.end() - 2, 1, 1);
//		stdv[5] = 2;
//		stdv[6] = 3;
		//v.reserve(15);
//		std::cout << v.size() << std::endl;
		//v.insert(v.begin(), 1, 11);
		//v.erase(v.begin() + 1, v.end() - 1);
		//std::cout << v.size() << std::endl;
//		ft::vector<int>::iterator it = v.erase(v.begin() , v.begin());
//		std::cout << (it == v.end()) << std::endl;-
//		std::cout << *it << std::endl;
//		std::cout << v.size() << std::endl;
//		v.pop_back();
		v.insert(v.end() - 1,11);
		//v[5] = 2;
		//std::cout << v.size() << std::endl;
		for (size_t i = 0; i < v.size(); i++)
			std::cout << v[i] << std::endl;

//		std::cout << (it == stdv.end()) << std::endl;
//		std::cout << *it << std::endl;
//		std::cout << stdv.size() << std::endl;
	} catch (std::exception &e) {
		std::cout << "error: " << e.what() << std::endl;
	}
	//v.resize(3);
	//std::cout << v.front() << std::endl;
//	try {
//		v.reserve(1111);
//	} catch (std::exception &e) {
//		std::cout << e.what() << std::endl;
//	}

//	std::vector<int, test> v(3, 3, a);
//	for (int i = 0; i < v.size(); i++)
//		std::cout << v[i] << std::endl;
//	std::vector<int>::iterator it(v.begin());
//	std::vector<int>::const_iterator it2 (v.end());
//	std::cout << (it.base() < it2.base());

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
