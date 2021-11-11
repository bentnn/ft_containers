//#include "testing.hpp"
//
//class NonCopyable{
//public:
//	NonCopyable(){}
//	NonCopyable(NonCopyable & src);
//
//};
//
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
//
//template<class A, class B>
//void check_equal(A &v1, B &v2) {
//	assert(v1.size() == v2.size());
//	//std::cout << v1.capacity() << " " << v2.capacity() << std::endl;
//	assert(v1.capacity() == v2.capacity());
//	for (size_t i = 0; i < v1.size(); i++)
//		assert(v1[i] == v2[i]);
//}
//
////void test_push_back() {
////	std::vector<int> v1;
////	ft::vector<int> v2;
////	std::chrono::time_point<std::chrono::steady_clock, std::chrono::duration<double> > start, end;
////
////	start = std::chrono::high_resolution_clock::now();
////	for (int i = 0; i < 40; i++)
////		v1.push_back(i);
////	end = std::chrono::high_resolution_clock::now();
////	std::chrono::duration<double> stl_duration = end - start;
////
////	start = std::chrono::high_resolution_clock::now();
////	for (int i = 0; i < 40; i++)
////		v2.push_back(i);
////	end = std::chrono::high_resolution_clock::now();
////	std::chrono::duration<double> my_duration = end - start;
////
////	who_won("PUSH_BACK TEST" , my_duration, stl_duration);
////}
//
//void vector_insert_test() {
//	std::vector<int> stdv;
//	ft::vector<int> vec;
//	std::chrono::time_point<std::chrono::steady_clock, std::chrono::duration<double> > start, end;
//
//	check_equal(stdv, vec);
//
//	start = std::chrono::high_resolution_clock::now();
//
//	for (int i = 0; i < 40000; i++) {
//		stdv.insert(stdv.begin(), i);
//	}
//
//	end = std::chrono::high_resolution_clock::now();
//	std::chrono::duration<double> stl_duration = end - start;
//
//	start = std::chrono::high_resolution_clock::now();
//
//	for (int i = 0; i < 40000; i++)
//		vec.insert(vec.begin(), i);
//
//	end = std::chrono::high_resolution_clock::now();
//	std::chrono::duration<double> my_duration = end - start;
//	check_equal(stdv, vec);
//
//	who_won("Insert to begin" , my_duration, stl_duration);
//	std::cout << "-----------------\n";
//
//	stdv.~vector<int>();
//	new (&stdv) (std::vector<int>) ();
//	vec.~vector<int>();
//	new (&vec) (ft::vector<int>) ();
//
// 	check_equal(stdv, vec);
//
//	start = std::chrono::high_resolution_clock::now();
//
//	for (int i = 0; i < 10000; i++) {
//		stdv.insert(stdv.end(), i);
//	}
//
//	end = std::chrono::high_resolution_clock::now();
//	stl_duration = end - start;
//
//	start = std::chrono::high_resolution_clock::now();
//
//	for (int i = 0; i < 10000; i++)
//		vec.insert(vec.end(), i);
//
//	end = std::chrono::high_resolution_clock::now();
//	my_duration = end - start;
//	check_equal(stdv, vec);
//
//	who_won("Insert to end" , my_duration, stl_duration);
//
//	std::cout << "-----------------\n";
//
//	stdv.~vector<int>();
//	new (&stdv) (std::vector<int>) ();
//	vec.~vector<int>();
//	new (&vec) (ft::vector<int>) ();
//
//	check_equal(stdv, vec);
//
//	start = std::chrono::high_resolution_clock::now();
//
//	for (int i = 0; i < 10000; i++) {
//		stdv.insert(stdv.begin(), 10, i);
//	}
//
//
//	end = std::chrono::high_resolution_clock::now();
//	stl_duration = end - start;
//
//	start = std::chrono::high_resolution_clock::now();
//
//	for (int i = 0; i < 10000; i++) {
//		vec.insert(vec.begin(), 10, i);
//	}
//
//	end = std::chrono::high_resolution_clock::now();
//	my_duration = end - start;
//	check_equal(stdv, vec);
//
//	who_won("Insert ten to begin" , my_duration, stl_duration);
//}
