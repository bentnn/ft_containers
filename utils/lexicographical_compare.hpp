#ifndef LEXICOGRAPHICAL_COMPARE_HPP
#define LEXICOGRAPHICAL_COMPARE_HPP

namespace ft {
	template<class InputIt1, class InputIt2>
	bool lexicographical_compare(typename ft::enable_if< !ft::is_integral<InputIt1>::value, InputIt1 >::type first1, InputIt1 last1,
								 typename ft::enable_if< !ft::is_integral<InputIt2>::value, InputIt2 >::type first2, InputIt2 last2) {
		while (first1 != last1 && first2 != last2) {
			if (*first1 < *first2)
				return true;
			if (*first2 < *first1)
				return false;
			++first1;
			++first2;
		}
		return (first1 == last1) && (first2 != last2);
	}

	template<class InputIt1, class InputIt2, class Comp>
	bool lexicographical_compare(typename ft::enable_if< !ft::is_integral<InputIt1>::value, InputIt1 >::type first1, InputIt1 last1,
								 typename ft::enable_if< !ft::is_integral<InputIt2>::value, InputIt2 >::type first2, InputIt2 last2,
								 Comp cmp) {
		while (first1 != last1 && first2 != last2) {
			if (cmp(*first1, first2))
				return true;
			if (cmp(*first2, first1))
				return false;
			++first1;
			++first2;
		}
		return (first1 == last1) && (first2 != last2);
	}
}

#endif
