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

//void who_won(std::string name_of_test, std::chrono::duration<double> my_dur, std::chrono::duration<double> stl_dur) {
//	std::cout << name_of_test << "!!!!!!!!!!!" << std::endl;
//	std::cout << std::fixed << "stl vector: " << stl_dur.count() << std::endl;
//	std::cout << std::fixed << "your vector: " << my_dur.count() << std::endl;
//	double res = my_dur / stl_dur;
//	std::cout << std::fixed << "your_res = " << res << " stl_res, ";
//	if (res <= 1)
//		std::cout << "you won :-)\n";
//	else
//		std::cout << "stl won :-(\n";
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


int main() {

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
