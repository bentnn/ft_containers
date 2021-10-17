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

template<class T, class Allocator = std::allocator<T> >
void output_vector(const ft::vector<T, Allocator> &v) {
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}



int main() {
	ft::vector<int> v(5);
	ft::vector<int> v2(5);

	for (int i = 0; i < v.size(); i++) {
		v[i] = i + 1;
		v2[i] = i;
		//stdv[i] = i + 1;
	}
	//ft::vector<int> vec (2, 1);
	try {
		ft::vector<int> vec;
		vec.assign(v.begin() + 22, v.end());
		std::cout << vec.capacity() << std::endl;
//		for (int i = 0; i < 10; i++)
//			vec.push_back(i);
		output_vector(vec);
//		for (size_t i = 0; i < vec.size(); i++)
//			std::cout << vec[i] << std::endl;


	} catch (std::exception &e) {
		std::cout << "error: " << e.what() << std::endl;
	}
}
