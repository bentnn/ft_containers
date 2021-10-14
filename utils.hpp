#ifndef UTILS_HPP
#define UTILS_HPP

// enable_if
template<bool B, class T = void>
struct enable_if {};

template<class T>
struct enable_if<true, T> { typedef T type; };


// is_integral
template< class T >
struct is_integral { static const bool value = false; };



#endif
