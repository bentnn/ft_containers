#ifndef VECTOR_ITERATORS_HPP
#define VECTOR_ITERATORS_HPP

#include <iostream>
#include "../vector/vector.hpp"

namespace ft
{
	template<typename T>class ConstRanIt;
	template<typename T>
	class RanIt {
	public:
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef ptrdiff_t difference_type;
		typedef std::random_access_iterator_tag iterator_category;
		template <class _Tp, class _Alloc> friend class  vector;
	private:
		pointer _ptr;

		RanIt(pointer a)  {
			_ptr = a;
		}
	public:
		// constructors
		RanIt() {
			_ptr = 0;
		}

		RanIt(const RanIt<value_type>& other) {
			this->_ptr = other._ptr;
		}

		// operators
		RanIt& operator=(const RanIt<value_type>& other) {
			this->_ptr = other._ptr;
			return *this;
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
			_ptr--;
			return temp;
		}

		reference operator*() {
			return *_ptr;
		}

		pointer operator->() {
			return _ptr;
		}

		pointer base() const {
			return _ptr;
		}

		reference operator[](int val) {
			return (*(_ptr + val));
		}

		bool operator==(const RanIt<value_type> &other) const {
			return this->_ptr == other.base();
		}

		bool operator==(const ConstRanIt<value_type> &other) const {
			return this->_ptr == other.base();
		}

		bool operator!=(const RanIt<value_type> &other) const {
			return this->_ptr != other.base();
		}

		bool operator!=(const ConstRanIt<value_type> &other) const {
			return this->_ptr != other.base();
		}

		bool operator<(const RanIt<value_type> &other) const {
			return this->_ptr < other.base();
		}

		bool operator<(const ConstRanIt<value_type> &other) const {
			return this->_ptr < other.base();
		}

		bool operator>(const RanIt<value_type> &other) const {
			return this->_ptr > other.base();
		}

		bool operator>(const ConstRanIt<value_type> &other) const {
			return this->_ptr > other.base();
		}

		bool operator<=(const RanIt<value_type> &other) const {
			return this->_ptr <= other.base();
		}

		bool operator<=(const ConstRanIt<value_type> &other) const {
			return this->_ptr <= other.base();
		}

		bool operator>=(const RanIt<value_type> &other) const {
			return this->_ptr >= other.base();
		}

		bool operator>=(const ConstRanIt<value_type> &other) const {
			return this->_ptr >= other.base();
		}

		difference_type operator-(const RanIt<value_type> &other) {
			return this->_ptr - other.base();
		}

		difference_type operator-(const ConstRanIt<value_type> &other) {
			return this->_ptr - other.base();
		}

		difference_type operator+(const RanIt<value_type> &other) {
			return this->_ptr + other.base();
		}

		difference_type operator+(const ConstRanIt<value_type> &other) {
			return this->_ptr + other.base();
		}

		RanIt operator+(const difference_type &a) {
			return RanIt(_ptr + a);
		}

		RanIt operator-(const difference_type &a) {
			return RanIt(_ptr - a);
		}

		RanIt & operator+=(const difference_type &a) {
			_ptr += a;
			return *this;
		}

		RanIt & operator-=(const difference_type &a) {
			_ptr -= a;
			return *this;
		}
	};

	template<typename T>class RanIt;
	template<typename T>
	class ConstRanIt {
	public:
		typedef T value_type;
		typedef const T* pointer;
		typedef const T& reference;
		typedef ptrdiff_t difference_type;
		typedef std::random_access_iterator_tag iterator_category;
		template <class _Tp, class _Alloc> friend class  vector;
	private:
		pointer _ptr;

		ConstRanIt(pointer a)  {
			_ptr = a;
		}
	public:
		// constructors
		ConstRanIt() {
			_ptr = 0;
		}

		ConstRanIt(const ConstRanIt<value_type>& other) {
			this->_ptr = other._ptr;
		}

		ConstRanIt(const RanIt<value_type> & other) {
			this->_ptr = other.base();
		}

		// operators
		ConstRanIt& operator=(const ConstRanIt<value_type>& other) {
			this->_ptr = other._ptr;
			return *this;
		}

		ConstRanIt& operator=(const RanIt<value_type>& other) {
			this->_ptr = other.base();
			return *this;
		}

		ConstRanIt& operator++() {
			_ptr++;
			return *this;
		}

		ConstRanIt& operator--() {
			_ptr--;
			return *this;
		}

		ConstRanIt operator++(int) {
			ConstRanIt<value_type> temp = *this;
			_ptr++;
			return temp;
		}

		ConstRanIt operator--(int) {
			ConstRanIt<value_type> temp = *this;
			_ptr--;
			return temp;
		}

		reference operator*() {
			return *_ptr;
		}

		pointer operator->() {
			return _ptr;
		}

		pointer base() const {
			return _ptr;
		}

		reference operator[](int val) {
			return (*(_ptr + val));
		}

		bool operator==(const RanIt<value_type> &other) const {
			return this->_ptr == other.ptr;
		}

		bool operator==(const ConstRanIt<value_type> &other) const {
			return this->_ptr == other.base();
		}

		bool operator!=(const RanIt<value_type> &other) const {
			return this->_ptr != other.base();
		}

		bool operator!=(const ConstRanIt<value_type> &other) const {
			return this->_ptr != other.base();
		}

		bool operator<(const RanIt<value_type> &other) const {
			return this->_ptr < other.base();
		}

		bool operator<(const ConstRanIt<value_type> &other) const {
			return this->_ptr < other.base();
		}

		bool operator>(const RanIt<value_type> &other) const {
			return this->_ptr > other.base();
		}

		bool operator>(const ConstRanIt<value_type> &other) const {
			return this->_ptr > other.base();
		}

		bool operator<=(const RanIt<value_type> &other) const {
			return this->_ptr <= other.base();
		}

		bool operator<=(const ConstRanIt<value_type> &other) const {
			return this->_ptr <= other.base();
		}

		bool operator>=(const RanIt<value_type> &other) const {
			return this->_ptr >= other.base();
		}

		bool operator>=(const ConstRanIt<value_type> &other) const {
			return this->_ptr >= other.base();
		}

		difference_type operator-(const RanIt<value_type> &other) {
			return this->_ptr - other.base();
		}

		difference_type operator-(const ConstRanIt<value_type> &other) {
			return this->_ptr - other.base();
		}

		difference_type operator+(const RanIt<value_type> &other) {
			return this->_ptr + other.base();
		}

		difference_type operator+(const ConstRanIt<value_type> &other) {
			return this->_ptr + other.base();
		}

		ConstRanIt operator+(const difference_type &a) {
			return ConstRanIt(_ptr + a);
		}

		ConstRanIt operator-(const difference_type &a) {
			return ConstRanIt(_ptr - a);
		}

		ConstRanIt & operator+=(const difference_type &a) {
			_ptr += a;
			return *this;
		}

		ConstRanIt & operator-=(const difference_type &a) {
			_ptr -= a;
			return *this;
		}
	};
}


#endif
