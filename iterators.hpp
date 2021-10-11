#ifndef FT_CONTAINERS_ITERATORS_HPP
#define FT_CONTAINERS_ITERATORS_HPP

#include <iostream>

namespace ft
{
	//template<typename T>class const_iterator;
	template<typename T>
	class RanIt {
	public:
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef ptrdiff_t difference_type;
		typedef std::random_access_iterator_tag iterator_category;
	private:
		pointer _ptr;
	public:
		// constructors
		RanIt() {
			_ptr = 0;
		}

		RanIt(pointer a)  {
			_ptr = a;
		}

		RanIt(reference a) {
			_ptr = *a;
		}

		RanIt(const RanIt& other) {
			this->_ptr = other._ptr;
		}

		// operators
		RanIt& operator=(const RanIt& other) {
			this->_ptr = other._ptr;
		}

		RanIt& operator++() {
			_ptr++;
			return *this;
		}

		RanIt& operator--() {
			_ptr--;
			return *this;
		}

		RanIt operator++(int) {
			RanIt<value_type> temp = *this;
			_ptr++;
			return temp;
		}

		RanIt operator--(int) {
			RanIt<value_type> temp = *this;
			_ptr++;
			return temp;
		}

		reference operator*() {
			return *_ptr;
		}

		pointer operator->() {
			return _ptr;
		}

		bool operator==(const RanIt &other) const {
			return this->_ptr == other.ptr;
		}

		bool operator!=(const RanIt &other) const {
			return this->_ptr != other.ptr;
		}

		bool operator<(const RanIt &other) const {
			return this->_ptr < other.ptr;
		}

		bool operator>(const RanIt &other) const {
			return this->_ptr > other.ptr;
		}

		bool operator<=(const RanIt &other) const {
			return this->_ptr <= other.ptr;
		}

		bool operator>=(const RanIt &other) const {
			return this->_ptr >= other.ptr;
		}

		RanIt operator+(const difference_type &a) {
			return _ptr + a;
		}

		RanIt operator-(const difference_type &a) {
			return _ptr - a;
		}

		RanIt & operator+=(const difference_type &a) {
			_ptr += a;
			return *this;
		}

		RanIt & operator-=(const difference_type &a) {
			_ptr -= a;
			return *this;
		}

		difference_type operator-(const RanIt &other) {
			return this->ptr - other.ptr;
		}

		difference_type operator+(const RanIt &other) {
			return this->ptr + other.ptr;
		}
	};
}


#endif
