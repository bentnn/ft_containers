#include "testing.hpp"

//class A {
//private:
//	int n;
//public:
//	explicit A (int n): n(n) {}
//};

//template<class T, class Allocator = std::allocator<T> >
//void output_vector(const ft::vector<T, Allocator> &v) {
//	for (size_t i = 0; i < v.size(); i++)
//		std::cout << v[i] << " ";
//	std::cout << std::endl;
//}

//
//void test_push_back() {
//	std::vector<int> v1;
//	ft::vector<int> v2;
//	std::chrono::time_point<std::chrono::steady_clock, std::chrono::duration<double> > start, end;
//
//	start = std::chrono::high_resolution_clock::now();
//	for (int i = 0; i < 40; i++)
//		v1.push_back(i);
//	end = std::chrono::high_resolution_clock::now();
//	std::chrono::duration<double> stl_duration = end - start;
//
//	start = std::chrono::high_resolution_clock::now();
//	for (int i = 0; i < 40; i++)
//		v2.push_back(i);
//	end = std::chrono::high_resolution_clock::now();
//	std::chrono::duration<double> my_duration = end - start;
//
//	who_won("PUSH_BACK TEST" , my_duration, stl_duration);
//}
//
//void test_pop_back() {
//	std::vector<int> v1(50, 2);
//	ft::vector<int> v2(50, 2);
//	std::chrono::time_point<std::chrono::steady_clock, std::chrono::duration<double> > start, end;
//
//	start = std::chrono::high_resolution_clock::now();
//	for (int i = 0; i < 40; i++)
//		v1.pop_back();
//	end = std::chrono::high_resolution_clock::now();
//	std::chrono::duration<double> stl_duration = end - start;
//
//	start = std::chrono::high_resolution_clock::now();
//	for (int i = 0; i < 40; i++)
//		v2.pop_back();
//	end = std::chrono::high_resolution_clock::now();
//	std::chrono::duration<double> my_duration = end - start;
//
//	who_won("POP_BACK TEST" , my_duration, stl_duration);
//}
//
//void test_reserve() {
//	std::vector<int> v1(50, 2);
//	ft::vector<int> v2(50, 2);
//	std::chrono::time_point<std::chrono::steady_clock, std::chrono::duration<double> > start, end;
//
//	start = std::chrono::high_resolution_clock::now();
//	v1.reserve(100);
//	end = std::chrono::high_resolution_clock::now();
//	std::chrono::duration<double> stl_duration = end - start;
//
//	start = std::chrono::high_resolution_clock::now();
//	v2.reserve(100);
//	end = std::chrono::high_resolution_clock::now();
//	std::chrono::duration<double> my_duration = end - start;
//
//	who_won("RESERVE TEST" , my_duration, stl_duration);
//}


class OnHeap{
	public:
		OnHeap(){
			values = new int[4];
		}

		OnHeap & operator=(OnHeap const & src) {
			delete[] values;
			values = new int[4];
			return (*this);
		}
		OnHeap(OnHeap const & src){
			values = new int[4];
		}
		~OnHeap(){
			delete [] values;
		}

	private:
		int *values;
};

int main() {
	RBTree<int> tree;
	int *cont = new int(2);
	tree.insert(cont);
	cont = new int(3);
	tree.insert(cont);
	cont = new int(4);
	tree.insert(cont);
	RBTree<int>::iterator it(tree.begin());
//	while (1) {
//		std::cout << *it << std::endl;
//		++it;
//	}

//	std::map<int, int> m;
//	for (int i = 0; i < 5; i++)
//		m[i] = i;
//	std::map<int, int>::iterator it = m.end();
//	std::map<int, int>::iterator::
//	vector_insert_test();
//	ft::vector<OnHeap> onheap;
//	for (int i = 0; i < 10; i++){
//		onheap.insert(onheap.begin(), OnHeap());
//	}
}



//void test_vec_comparison() {
//	std::vector<int> stdv1;
//	std::vector<int> stdv2;
//	ft::vector<int> v1;
//	ft::vector<int> v2;
//
//	compare_assert(stdv1, stdv2, v1, v2, "all is empty");
//
//	stdv1 = std::vector<int>(3, 4);
//	stdv2 = std::vector<int>(stdv1.begin(), stdv1.end());
//	v1 = ft::vector<int>(stdv1.begin(), stdv1.end());
//	v2 = ft::vector<int>(stdv1.begin(), stdv1.end());
//
//	compare_assert(stdv1, stdv2, v1, v2, "all is not empty but is equal");
//
//	stdv2.insert(stdv2.end(), stdv1.begin(), stdv1.end());
//	v2.assign(stdv2.begin(), stdv2.end());
//
//	compare_assert(stdv1, stdv2, v1, v2, "all is not empty and is not equal");
//
//	std::cout << "Comparison is ok\n";
//}


//int main() {
//	std::pair<int, int> pa = std::make_pair(2, 2);
//	std::pair<int, int> pa2 = std::make_pair(2, 33);
//	std::cout << (pa < pa2) << std::endl;
////	ft::vector<int> v(5);
////	ft::vector<int> v2(5);
////	for (int i = 0; i < v.size(); i++) {
////		v[i] = i + 1;
////		v2[i] = i;
////	}
////	try {
////		ft::vector<int> vec;
////		vec.assign(v.begin() + 22, v.end());
////		std::cout << vec.capacity() << std::endl;
////		output_vector(vec);
////	} catch (std::exception &e) {
////		std::cout << "error: " << e.what() << std::endl;
////	}
//}
