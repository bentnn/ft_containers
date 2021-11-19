#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

#include "remove_const.hpp"

namespace ft {

	template<class T> struct is_integral_type { static const bool value = false; };

	template<> struct is_integral_type<bool> { static const bool value = true; };

	template<> struct is_integral_type<char> { static const bool value = true; };

	template<> struct is_integral_type<char16_t> { static const bool value = true; };

	template<> struct is_integral_type<char32_t> { static const bool value = true; };

	template<> struct is_integral_type<wchar_t> { static const bool value = true; };

	template<> struct is_integral_type<short> { static const bool value = true; };

	template<> struct is_integral_type<int> { static const bool value = true; };

	template<> struct is_integral_type<long> { static const bool value = true; };

	template<> struct is_integral_type<long long> { static const bool value = true; };


	template<typename T>
	struct is_integral {
		static const bool value = is_integral_type< typename ft::remove_const<T>::type >::value;
	};
}

#endif
