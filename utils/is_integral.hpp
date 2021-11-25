#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

#include "remove_const.hpp"

namespace ft {

//	template<class T> struct is_integral_type { static const bool value = false; };
//
//	template<> struct is_integral_type<bool> { static const bool value = true; };
//
//	template<> struct is_integral_type<char> { static const bool value = true; };
//
//	template<> struct is_integral_type<char16_t> { static const bool value = true; };
//
//	template<> struct is_integral_type<char32_t> { static const bool value = true; };
//
//	template<> struct is_integral_type<wchar_t> { static const bool value = true; };
//
//	template<> struct is_integral_type<short> { static const bool value = true; };
//
//	template<> struct is_integral_type<int> { static const bool value = true; };
//
//	template<> struct is_integral_type<long> { static const bool value = true; };
//
//	template<> struct is_integral_type<long long> { static const bool value = true; };
//
//
//	template<typename T>
//	struct is_integral {
//		static const bool value = is_integral_type< typename ft::remove_const<T>::type >::value;
//	};

	template<class T, bool v>
	struct integral_constant {
		static const bool value = v;
		typedef T value_type;
		typedef integral_constant type;
		operator value_type() const { return value; }
	};
	template <class T> struct is_integral				: public ft::integral_constant<T, false> {};
	template <> struct is_integral<bool>				: public ft::integral_constant<bool, true> {};
	template <> struct is_integral<char>				: public ft::integral_constant<bool, true> {};
	template <> struct is_integral<signed char>			: public ft::integral_constant<bool, true> {};
	template <> struct is_integral<unsigned char>		: public ft::integral_constant<bool, true> {};
	template <> struct is_integral<wchar_t>				: public ft::integral_constant<bool, true> {};
	template <> struct is_integral<char16_t>			: public ft::integral_constant<bool, true> {};
	template <> struct is_integral<short>				: public ft::integral_constant<bool, true> {};
	template <> struct is_integral<unsigned short>		: public ft::integral_constant<bool, true> {};
	template <> struct is_integral<int>					: public ft::integral_constant<bool, true> {};
	template <> struct is_integral<unsigned int>		: public ft::integral_constant<bool, true> {};
	template <> struct is_integral<long>				: public ft::integral_constant<bool, true> {};
	template <> struct is_integral<unsigned long> 		: public ft::integral_constant<bool, true> {};
	template <> struct is_integral<long long>			: public ft::integral_constant<bool, true> {};
	template <> struct is_integral<unsigned long long>	: public ft::integral_constant<bool, true> {};
}

#endif
