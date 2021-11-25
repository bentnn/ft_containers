#include "testing.hpp"

template<class T>
class myb : public ft::vector<T> {
public:
	myb(int a, int b) : ft::vector<T>(a, b){}

};


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
	OnHeap(int n = 0){
		values = new int(n);
	}

	OnHeap & operator=(OnHeap const & src) {
		delete values;
		values = new int(*src.values);
		return (*this);
	}
	OnHeap(OnHeap const & src){
		values = new int(*src.values);
	}
	~OnHeap(){
		delete values;
	}

	int get_val() const {
		return *values;
	}

private:
	int *values;
};

//bool operator<( const OnHeap& lhs, const OnHeap& rhs ) {
//	return lhs.get_val() < rhs.get_val();
//}

template <class T, class C>
void fillSet(std::set<T, C> &mp) {
	mp.insert(16);
	mp.insert(8);
	mp.insert(23);
	mp.insert(7);
	mp.insert(19);
	mp.insert(29);
	mp.insert(41);
	mp.insert(4);
	mp.insert(11);
}

template <class T, class C>
void fillSet(ft::set<T, C> &mp) {
	mp.insert(16);
	mp.insert(8);
	mp.insert(23);
	mp.insert(7);
	mp.insert(19);
	mp.insert(29);
	mp.insert(41);
	mp.insert(4);
	mp.insert(11);
}

class SetBoolTest {
public:
	std::set<int> s1, s2, s3, s4;
	std::set<std::string> s5, s6, s7, s8, s9;
	ft::set<int> st1, st2, st3, st4;
	ft::set<std::string> st5, st6, st7, st8, st9;

	SetBoolTest() {
		s1.insert(2); st1.insert(2);
		s2.insert(3); st2.insert(3);
		s3.insert(3); st3.insert(3);
		s4.insert(4); st4.insert(4);
		s4.insert(4); st4.insert(4);
		s5.insert("122"); st5.insert("122");
		s6.insert("123"); st6.insert("123");
		s7.insert("124"); st7.insert("124");
		s8.insert("12"); st8.insert("12");
		s9.insert("123"); st9.insert("123");
	}
};

class MapBoolTest {
public:
	std::map<int, int> m1, m2, m3, m4;
	std::map<std::string, std::string> m5, m6, m7, m8, m9;
	ft::map<int, int> mp1, mp2, mp3, mp4;
	ft::map<std::string, std::string> mp5, mp6, mp7, mp8, mp9;

	MapBoolTest() {
		m1.insert(std::make_pair(2, 3)); mp1.insert(ft::make_pair(2, 3));
		m2.insert(std::make_pair(3, 3)); mp2.insert(ft::make_pair(3, 3));
		m3.insert(std::make_pair(3, 4)); mp3.insert(ft::make_pair(3, 4));
		m4.insert(std::make_pair(4, 4)); mp4.insert(ft::make_pair(4, 4));
		m4.insert(std::make_pair(4, 5)); mp4.insert(ft::make_pair(4, 5));
		m5.insert(std::make_pair("123", "123")); mp5.insert(ft::make_pair("123", "123"));
		m6.insert(std::make_pair("123", "124")); mp6.insert(ft::make_pair("123", "124"));
		m7.insert(std::make_pair("124", "123")); mp7.insert(ft::make_pair("124", "123"));
		m8.insert(std::make_pair("12", "123")); mp8.insert(ft::make_pair("12", "123"));
		m9.insert(std::make_pair("123", "12")); mp9.insert(ft::make_pair("123", "12"));
	}
};


bool map_less_than_test() {
	std::vector<int> result, result2;
	MapBoolTest mt;

	result.push_back(mt.m1 < mt.m1); result.push_back(mt.m3 < mt.m3); result.push_back(mt.m5 < mt.m9);
	result.push_back(mt.m1 < mt.m2); result.push_back(mt.m3 < mt.m4); result.push_back(mt.m6 < mt.m6);
	result.push_back(mt.m1 < mt.m3); result.push_back(mt.m4 < mt.m4); result.push_back(mt.m6 < mt.m7);
	result.push_back(mt.m1 < mt.m4); result.push_back(mt.m5 < mt.m5); result.push_back(mt.m6 < mt.m8);
	result.push_back(mt.m2 < mt.m2); result.push_back(mt.m5 < mt.m6); result.push_back(mt.m6 < mt.m9);
	result.push_back(mt.m2 < mt.m3); result.push_back(mt.m5 < mt.m7); result.push_back(mt.m7 < mt.m7);
	result.push_back(mt.m2 < mt.m4); result.push_back(mt.m5 < mt.m8); result.push_back(mt.m7 < mt.m8);
	result.push_back(mt.m7 < mt.m9); result.push_back(mt.m8 < mt.m8); result.push_back(mt.m8 < mt.m9);
	result.push_back(mt.m9 < mt.m9);


	result2.push_back(mt.mp1 < mt.mp1); result2.push_back(mt.mp3 < mt.mp3); result2.push_back(mt.mp5 < mt.mp9);
	result2.push_back(mt.mp1 < mt.mp2); result2.push_back(mt.mp3 < mt.mp4); result2.push_back(mt.mp6 < mt.mp6);
	result2.push_back(mt.mp1 < mt.mp3); result2.push_back(mt.mp4 < mt.mp4); result2.push_back(mt.mp6 < mt.mp7);
	result2.push_back(mt.mp1 < mt.mp4); result2.push_back(mt.mp5 < mt.mp5); result2.push_back(mt.mp6 < mt.mp8);
	result2.push_back(mt.mp2 < mt.mp2); result2.push_back(mt.mp5 < mt.mp6); result2.push_back(mt.mp6 < mt.mp9);
	result2.push_back(mt.mp2 < mt.mp3); result2.push_back(mt.mp5 < mt.mp7); result2.push_back(mt.mp7 < mt.mp7);
	result2.push_back(mt.mp2 < mt.mp4); result2.push_back(mt.mp5 < mt.mp8); result2.push_back(mt.mp7 < mt.mp8);
	result2.push_back(mt.mp7 < mt.mp9); result2.push_back(mt.mp8 < mt.mp8); result2.push_back(mt.mp8 < mt.mp9);
	result2.push_back(mt.mp9 < mt.mp9);

	return result == result2;
}

#define _vector ft::vector

bool iterator_traits_test() {
	std::vector<std::string> res;
	std::vector<std::string> res2;

	res.push_back(typeid(std::vector<int>::iterator::iterator_category).name());
	res.push_back(typeid(std::vector<int>::iterator::value_type).name());
	res.push_back(typeid(std::vector<int>::iterator::difference_type).name());
	res.push_back(typeid(std::vector<int>::iterator::iterator_type).name());
	res.push_back(typeid(std::vector<int>::iterator::pointer).name());
	res.push_back(typeid(std::vector<int>::iterator::reference).name());
	res.push_back(typeid(std::vector<int>::reverse_iterator::iterator_category).name());
	res.push_back(typeid(std::vector<int>::reverse_iterator::value_type).name());
	res.push_back(typeid(std::vector<int>::reverse_iterator::difference_type).name());
	res.push_back(typeid(std::vector<int>::reverse_iterator::pointer).name());
	res.push_back(typeid(std::vector<int>::reverse_iterator::reference).name());

	res2.push_back(typeid(_vector<int>::iterator::iterator_category).name());
	res2.push_back(typeid(_vector<int>::iterator::value_type).name());
	res2.push_back(typeid(_vector<int>::iterator::difference_type).name());
	res2.push_back(typeid(_vector<int>::iterator::iterator_type).name());
	res2.push_back(typeid(_vector<int>::iterator::pointer).name());
	res2.push_back(typeid(_vector<int>::iterator::reference).name());
	res2.push_back(typeid(_vector<int>::reverse_iterator::iterator_category).name());
	res2.push_back(typeid(_vector<int>::reverse_iterator::value_type).name());
	res2.push_back(typeid(_vector<int>::reverse_iterator::difference_type).name());
	res2.push_back(typeid(_vector<int>::reverse_iterator::pointer).name());
	res2.push_back(typeid(_vector<int>::reverse_iterator::reference).name());

	for (size_t i = 0; i < res.size(); i++)
		std::cout << res[i] << "\t\t" << res2[i] << std::endl;
	return res == res2;
}

int main() {
	ft::vector<int> a;
	a.push_back(2);
	//std::vector<int> v2(5, 200);
//	v1.swap(v2);

//	std::map<int, OnHeap> m1;
//	std::map<int, OnHeap> m2;
//	m1.insert(std::make_pair(3, OnHeap()));
//	m2.insert(std::make_pair(3, OnHeap()));
//	std::cout << (m1 == m2);
//	std::cout << map_less_than_test();
//	std::cout << map_less_than_test();
//	std::__wrap_iter<int *> a;
//	std::vector<int> v1 =  erase_test_2<int>();
//	std::vector<int> v2 =  erase_test<int>();
//	for (size_t i = 0; i < v1.size(); ++i)
//		std::cout << v1[i] << " ";
//	std::cout << std::endl;
//
//	for (size_t i = 0; i < v2.size(); ++i)
//		std::cout << v2[i] << " ";
//	std::cout << std::endl;
//	std::cout << (v1 == v2) << " \n";
}

//	RBTree<int> tree;
//	for (int i=0; i < 5; i++) {
//		tree.insert(tree.begin(), i);
//	}
//	std::srand(std::time(NULL));
//	ft::map<int, int> m;
//	for (int i=0; i < 5; i++) {
//		m[i] = i;
////		m.insert(m.begin(), ft::pair<int, int> (i, i));
//	}
//	std::cout << m.count(11) << " aaa" << std::endl;
//	for (ft::map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
//		std::cout << it->first << std::endl;
//	}
////	for (int i=0; i < 2; i++) {
////		m.erase(m.begin());
////	}
//	std::cout << "end!" << std::endl;

//	ft::map<int, int> m;
//	for (int i = 0; i < 5; ++i)
//		m[i] = i;

//    m2.insert(m.begin(), m.end());

//    ft::map<int, int> m2(m);
//    m.erase(m.begin());
//    ft::map<int, int>::iterator it = m.lower_bound(3);
//    for (; it != m.end(); ++it)
//        std::cout << (m > m2) << std::endl;
//	m.erase(m.begin(), m.end());
//	for (int i = 0; i < m.size(); ++i)
//		std::cout << m[i] << std::endl;

//	ft::vector<int> v(5, 100);
//	ft::vector<int>::const_iterator it;
//	it = v.begin();
//	ft::vector<int>::const_iterator it2 = it;
//	ft::vector<int>::iterator it3 = v.begin();
//	it2 = it3;
//	for (it2; it2 != v.end(); it2++)
//		std::cout << (it2 == it) << std::endl;


//	int *cont = new int(2);
//	tree.insert(cont);
//	cont = new int(3);
//	tree.insert(cont);
//	cont = new int(4);
//	tree.insert(cont);
//	RBTree<int>::iterator it = tree.begin();
//	++it;
//	tree.erase(it);
//	it = tree.begin();
//	++it;
//	tree.erase(it);
	//tree.erase(tree.begin());
//	std::cout << tree.size();
//	RBTree<int>::iterator it = tree.begin();
//	while (it != tree.end()) {
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
