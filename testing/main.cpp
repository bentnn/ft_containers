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

bool operator<( const OnHeap& lhs, const OnHeap& rhs ) {
	return lhs.get_val() < rhs.get_val();
}

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

template <class T>
std::vector<int> comparator_test1() {
	std::set<int> st;
	std::vector<int> v;
	fillSet(st);
	for (typename std::set<T>::iterator it = st.begin(); it != st.end(); it++) { v.push_back(*it); }
	for (typename std::set<T>::iterator it = --st.end(); it != st.begin(); it--) { v.push_back(*it); }
	std::set<int, std::greater<int> > st1;
	fillSet(st1);
	v.push_back(*(st1.begin()));
	st1.erase(41);
	v.push_back(*(st1.begin()));
	st1.erase(29);
	v.push_back(*(st1.begin()));
	std::set<int, std::greater<int> > st2;
	st2.insert(3);
	v.push_back(*(st2.begin()));
	st2.erase(3);
	if (st2.begin() == st2.end())
		v.push_back(1);
	std::set<int, std::plus<int> > st3;
	fillSet(st3);
	for (typename std::set<T>::iterator it = st3.begin(); it != st3.end(); it++) { v.push_back(*it); }
	for (typename std::set<T>::iterator it = --st3.end(); it != st3.begin(); it--) { v.push_back(*it); }
	std::set<int, std::minus<int> > st4;
	fillSet(st4);
	for (typename std::set<T>::iterator it = st4.begin(); it != st4.end(); it++) { v.push_back(*it); }
	for (typename std::set<T>::iterator it = --st4.end(); it != st4.begin(); it--) { v.push_back(*it); }
	std::set<int, std::greater_equal<int> > st5;
	fillSet(st5);
	for (typename std::set<T>::iterator it = st5.begin(); it != st5.end(); it++) { v.push_back(*it); }
	for (typename std::set<T>::iterator it = --st5.end(); it != st5.begin(); it--) { v.push_back(*it); }
	std::set<int, std::multiplies<int> > st6;
	fillSet(st6);
	for (typename std::set<T>::iterator it = st6.begin(); it != st6.end(); it++) { v.push_back(*it); }
	for (typename std::set<T>::iterator it = --st6.end(); it != st6.begin(); it--) { v.push_back(*it); }
	std::set<int, std::bit_xor<int> > st7;
	fillSet(st7);
	for (typename std::set<T>::iterator it = st7.begin(); it != st7.end(); it++) { v.push_back(*it); }
	for (typename std::set<T>::iterator it = --st7.end(); it != st7.begin(); it--) { v.push_back(*it); }
	std::set<int, std::logical_and<int> > st8;
	fillSet(st8);
	for (typename std::set<T>::iterator it = st8.begin(); it != st8.end(); it++) { v.push_back(*it); }
	for (typename std::set<T>::iterator it = --st8.end(); it != st8.begin(); it--) { v.push_back(*it); }
	v.push_back(st1.size());
	return v;
}

template <class T>
std::vector<int> comparator_test2() {
	ft::set<int> st;
	std::vector<int> v;
	fillSet(st);
	for (typename ft::set<T>::iterator it = st.begin(); it != st.end(); it++) { v.push_back(*it); }
	for (typename ft::set<T>::iterator it = --st.end(); it != st.begin(); it--) { v.push_back(*it); }
	ft::set<int, std::greater<int> > st1;
	fillSet(st1);
	v.push_back(*(st1.begin()));
	st1.erase(41);
	v.push_back(*(st1.begin()));
	st1.erase(29);
	v.push_back(*(st1.begin()));
	ft::set<int, std::greater<int> > st2;
	st2.insert(3);
	v.push_back(*(st2.begin()));
	st2.erase(3);
	if (st2.begin() == st2.end())
		v.push_back(1);
	ft::set<int, std::plus<int> > st3;
	fillSet(st3);
	for (typename ft::set<T>::iterator it = st3.begin(); it != st3.end(); it++) { v.push_back(*it); }
	for (typename ft::set<T>::iterator it = --st3.end(); it != st3.begin(); it--) { v.push_back(*it); }
	ft::set<int, std::minus<int> > st4;
	fillSet(st4);
	for (typename ft::set<T>::iterator it = st4.begin(); it != st4.end(); it++) { v.push_back(*it); }
	for (typename ft::set<T>::iterator it = --st4.end(); it != st4.begin(); it--) { v.push_back(*it); }
	ft::set<int, std::greater_equal<int> > st5;
	fillSet(st5);
	for (typename ft::set<T>::iterator it = st5.begin(); it != st5.end(); it++) { v.push_back(*it); }
	for (typename ft::set<T>::iterator it = --st5.end(); it != st5.begin(); it--) { v.push_back(*it); }
	ft::set<int, std::multiplies<int> > st6;
	fillSet(st6);
	for (typename ft::set<T>::iterator it = st6.begin(); it != st6.end(); it++) { v.push_back(*it); }
	for (typename ft::set<T>::iterator it = --st6.end(); it != st6.begin(); it--) { v.push_back(*it); }
	ft::set<int, std::bit_xor<int> > st7;
	fillSet(st7);
	for (typename ft::set<T>::iterator it = st7.begin(); it != st7.end(); it++) { v.push_back(*it); }
	for (typename ft::set<T>::iterator it = --st7.end(); it != st7.begin(); it--) { v.push_back(*it); }
	std::set<int, std::logical_and<int> > st8;
	fillSet(st8);
	for (typename std::set<T>::iterator it = st8.begin(); it != st8.end(); it++) { v.push_back(*it); }
	for (typename std::set<T>::iterator it = --st8.end(); it != st8.begin(); it--) { v.push_back(*it); }
	v.push_back(st1.size());

	return v;
}

int main() {
//	std::vector<int> v1(1, 100);
//	std::vector<int> v2(5, 200);
//	v1.swap(v2);
//	std::cout << v2.size();
	std::vector<int> v1 =  comparator_test1<int>();
	std::vector<int> v2 =  comparator_test2<int>();
	for (size_t i = 0; i < v1.size(); ++i)
		std::cout << v1[i] << " ";
	std::cout << std::endl;

	for (size_t i = 0; i < v2.size(); ++i)
		std::cout << v2[i] << " ";
	std::cout << std::endl;
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
