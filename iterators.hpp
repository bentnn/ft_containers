#ifndef FT_CONTAINERS_ITERATORS_HPP
#define FT_CONTAINERS_ITERATORS_HPP

#include <iostream>

namespace ft
{
	template<typename T>class const_iterator;
	template<typename T>
	class iterator {
	public:
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef ptrdiff_t difference_type;
	private:
		pointer _ptr;
	public:
		iterator() { this->_ptr = 0;}
		iterator(pointer a);
		iterator(reference a);
		~iterator() {}
		iterator& operator++();
		iterator& operator--();
		iterator operator++(int);
		iterator operator--(int);
	};
}


#endif
