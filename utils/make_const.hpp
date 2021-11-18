#ifndef MAKE_CONST_HPP
#define MAKE_CONST_HPP

namespace ft {
	template<class T> struct make_const { typedef const T type; };

	template<class T> struct make_const <const T> { typedef T type; };
}

#endif
