#ifndef VECTOR_ITERATORS_HPP
#define VECTOR_ITERATORS_HPP

#include <iostream>
#include "../vector/vector.hpp"
#include "../utils/iterator_traits.hpp"
#include "../utils/remove_const.hpp"
#include "../utils/make_const.hpp"

namespace ft {
	template< typename T>class RanIt
	{
	public:
		typedef	typename ft::iterator_traits<T*>::value_type 	value_type;
		typedef	typename ft::iterator_traits<T*>::pointer	pointer;
		typedef	typename ft::iterator_traits<T*>::reference	reference;
		typedef	typename ft::iterator_traits<T*>::difference_type	difference_type;
		//this is for std::functions
		typedef	std::random_access_iterator_tag iterator_category;

		//maybe protected???
	private:
		typedef	typename ft::make_const<T> 	const_type;
		pointer _ptr;
		//CONSTRUCTORS
	public:
		RanIt() : _ptr() {}

		RanIt(pointer a) : _ptr(a) {}

		virtual ~RanIt() {}

		RanIt(const RanIt<typename ft::remove_const<T>::type > & src) : _ptr(src.base()) {}

		pointer base(void) const{
			return _ptr;
		}

		RanIt<T> & operator=(RanIt<typename ft::remove_const<T>::type > const & src) {
			_ptr = src.base();
			return (*this);
		}

		//COMPARISON OPERATORS
		bool operator==(RanIt<typename ft::remove_const<T>::type > const & rhs) const {
			return _ptr == rhs.base();
		}

		bool operator==(RanIt<const_type > const & rhs) const {
			return _ptr == rhs.base();
		}

		bool operator!=(const RanIt<typename ft::remove_const<T>::type > & rhs) const {
			return _ptr != rhs.base();
		}

		bool operator!=(const RanIt<const_type > & rhs) const {
			return _ptr != rhs.base();
		}

		bool operator>(const RanIt<typename ft::remove_const<T>::type > & rhs) const {
			return _ptr > rhs.base();
		}

		bool operator>(const RanIt<const_type > & rhs) const {
			return _ptr > rhs.base();
		}

		bool operator<(const RanIt<typename ft::remove_const<T>::type > & rhs) const {
			return _ptr < rhs.base();
		}

		bool operator<(const RanIt<const_type > & rhs) const {
			return _ptr < rhs.base();
		}

		bool operator<=(const RanIt<typename ft::remove_const<T>::type > & rhs) const{
			return _ptr <= rhs.base();
		}

		bool operator<=(const RanIt<const_type > & rhs) const{
			return _ptr <= rhs.base();
		}

		bool operator>=(const RanIt<typename ft::remove_const<T>::type > & rhs) const{
			return _ptr >= rhs.base();
		}

		bool operator>=(const RanIt<const_type > & rhs) const{
			return _ptr >= rhs.base();
		}

		//OPERATORS
		RanIt & operator++(){
			++_ptr;
			return *this;
		}

		RanIt operator++(int){
			RanIt tmp(*this);
			++_ptr;
			return tmp;
		}

		RanIt & operator--(){
			--_ptr;
			return *this;
		}

		RanIt  operator--(int){
			RanIt tmp = *this;
			--_ptr;
			return tmp;
		}
		RanIt operator+(const difference_type & a) const{
			return _ptr + a;
		}

		RanIt operator-(const difference_type & a) const{
			return _ptr - a;
		}

		difference_type operator-(const RanIt<typename ft::remove_const<T>::type > & b){
			return(_ptr - b.base());
		}

		difference_type operator-(const RanIt<const_type > & b){
			return(_ptr - b.base());
		}

		difference_type operator+(const RanIt<typename ft::remove_const<T>::type > & b){
			return(_ptr + b.base());
		}

		difference_type operator+(const RanIt<const_type > & b){
			return(_ptr + b.base());
		}

		RanIt & operator+=(const difference_type & a){
			_ptr += a;
			return (*this);
		}
		RanIt & operator-=(const difference_type & a){
			_ptr -= a;
			return (*this);
		}
		pointer operator->(){
			return(_ptr);
		}
		value_type & operator*(){
			return(*_ptr);
		}
		reference operator[](difference_type n) const{
			return(*(_ptr + n));
		}
	};

	template<typename L>
	RanIt<L> operator +(const typename RanIt<L>::difference_type & a, const RanIt<L> & iter){
		return	(iter + a);
	}

	template<typename L>
	RanIt<L> operator -(const typename RanIt<L>::difference_type & a, const RanIt<L> & iter){
		return	(iter - a);
	}
}




//namespace ft
//{
//	template<typename T>class ConstRanIt;
//	template<typename T>
//	class RanIt {
//	public:
//		typedef T value_type;
//		typedef T* pointer;
//		typedef T& reference;
//		typedef ptrdiff_t difference_type;
//		typedef std::random_access_iterator_tag iterator_category;
//		template <class _Tp, class _Alloc> friend class  vector;
//	private:
//		pointer _ptr;
//
//		RanIt(pointer a)  {
//			_ptr = a;
//		}
//	public:
//		// constructors
//		RanIt() {
//			_ptr = 0;
//		}
//
//		RanIt(const RanIt<value_type>& other) {
//			this->_ptr = other._ptr;
//		}
//
//		// operators
//		RanIt& operator=(const RanIt<value_type>& other) {
//			this->_ptr = other._ptr;
//			return *this;
//		}
//
//		RanIt& operator++() {
//			_ptr++;
//			return *this;
//		}
//
//		RanIt& operator--() {
//			_ptr--;
//			return *this;
//		}
//
//		RanIt operator++(int) {
//			RanIt<value_type> temp = *this;
//			_ptr++;
//			return temp;
//		}
//
//		RanIt operator--(int) {
//			RanIt<value_type> temp = *this;
//			_ptr--;
//			return temp;
//		}
//
//		reference operator*() {
//			return *_ptr;
//		}
//
//		pointer operator->() {
//			return _ptr;
//		}
//
//		pointer base() const {
//			return _ptr;
//		}
//
//		reference operator[](int val) {
//			return (*(_ptr + val));
//		}
//
//		bool operator==(const RanIt<value_type> &other) const {
//			return this->_ptr == other.base();
//		}
//
//		bool operator==(const ConstRanIt<value_type> &other) const {
//			return this->_ptr == other.base();
//		}
//
//		bool operator!=(const RanIt<value_type> &other) const {
//			return this->_ptr != other.base();
//		}
//
//		bool operator!=(const ConstRanIt<value_type> &other) const {
//			return this->_ptr != other.base();
//		}
//
//		bool operator<(const RanIt<value_type> &other) const {
//			return this->_ptr < other.base();
//		}
//
//		bool operator<(const ConstRanIt<value_type> &other) const {
//			return this->_ptr < other.base();
//		}
//
//		bool operator>(const RanIt<value_type> &other) const {
//			return this->_ptr > other.base();
//		}
//
//		bool operator>(const ConstRanIt<value_type> &other) const {
//			return this->_ptr > other.base();
//		}
//
//		bool operator<=(const RanIt<value_type> &other) const {
//			return this->_ptr <= other.base();
//		}
//
//		bool operator<=(const ConstRanIt<value_type> &other) const {
//			return this->_ptr <= other.base();
//		}
//
//		bool operator>=(const RanIt<value_type> &other) const {
//			return this->_ptr >= other.base();
//		}
//
//		bool operator>=(const ConstRanIt<value_type> &other) const {
//			return this->_ptr >= other.base();
//		}
//
//		difference_type operator-(const RanIt<value_type> &other) const {
//			return this->_ptr - other.base();
//		}
//
//		difference_type operator-(const ConstRanIt<value_type> &other) const {
//			return this->_ptr - other.base();
//		}
//
//		difference_type operator+(const RanIt<value_type> &other) const {
//			return this->_ptr + other.base();
//		}
//
//		difference_type operator+(const ConstRanIt<value_type> &other) const {
//			return this->_ptr + other.base();
//		}
//
//		RanIt operator+(const difference_type &a) const {
//			return RanIt(_ptr + a);
//		}
//
//		RanIt operator-(const difference_type &a) const {
//			return RanIt(_ptr - a);
//		}
//
//		RanIt & operator+=(const difference_type &a) {
//			_ptr += a;
//			return *this;
//		}
//
//		RanIt & operator-=(const difference_type &a) {
//			_ptr -= a;
//			return *this;
//		}
//	};
//
//	template<typename L>
//	RanIt<L> operator +(const typename RanIt<L>::difference_type & a, const RanIt<L> & iter){
//		return	(iter + a);
//	}
//
//	template<typename L>
//	RanIt<L> operator -(const typename RanIt<L>::difference_type & a, const RanIt<L> & iter) {
//		return (iter - a);
//	}
//
//
//		template<typename T>class RanIt;
//	template<typename T>
//	class ConstRanIt {
//	public:
//		typedef T value_type;
//		typedef const T* pointer;
//		typedef const T& reference;
//		typedef ptrdiff_t difference_type;
//		typedef std::random_access_iterator_tag iterator_category;
//		template <class _Tp, class _Alloc> friend class  vector;
//	private:
//		pointer _ptr;
//
//		ConstRanIt(pointer a)  {
//			_ptr = a;
//		}
//	public:
//		// constructors
//		ConstRanIt() {
//			_ptr = 0;
//		}
//
//		ConstRanIt(const ConstRanIt<value_type>& other) {
//			this->_ptr = other._ptr;
//		}
//
//		ConstRanIt(const RanIt<value_type> & other) {
//			this->_ptr = other.base();
//		}
//
//		// operators
//		ConstRanIt& operator=(const ConstRanIt<value_type>& other) {
//			this->_ptr = other._ptr;
//			return *this;
//		}
//
//		ConstRanIt& operator=(const RanIt<value_type>& other) {
//			this->_ptr = other.base();
//			return *this;
//		}
//
//		ConstRanIt& operator++() {
//			_ptr++;
//			return *this;
//		}
//
//		ConstRanIt& operator--() {
//			_ptr--;
//			return *this;
//		}
//
//		ConstRanIt operator++(int) {
//			ConstRanIt<value_type> temp = *this;
//			_ptr++;
//			return temp;
//		}
//
//		ConstRanIt operator--(int) {
//			ConstRanIt<value_type> temp = *this;
//			_ptr--;
//			return temp;
//		}
//
//		reference operator*() {
//			return *_ptr;
//		}
//
//		pointer operator->() {
//			return _ptr;
//		}
//
//		pointer base() const {
//			return _ptr;
//		}
//
//		reference operator[](int val) {
//			return (*(_ptr + val));
//		}
//
//		bool operator==(const RanIt<value_type> &other) const {
//			return this->_ptr == other.ptr;
//		}
//
//		bool operator==(const ConstRanIt<value_type> &other) const {
//			return this->_ptr == other.base();
//		}
//
//		bool operator!=(const RanIt<value_type> &other) const {
//			return this->_ptr != other.base();
//		}
//
//		bool operator!=(const ConstRanIt<value_type> &other) const {
//			return this->_ptr != other.base();
//		}
//
//		bool operator<(const RanIt<value_type> &other) const {
//			return this->_ptr < other.base();
//		}
//
//		bool operator<(const ConstRanIt<value_type> &other) const {
//			return this->_ptr < other.base();
//		}
//
//		bool operator>(const RanIt<value_type> &other) const {
//			return this->_ptr > other.base();
//		}
//
//		bool operator>(const ConstRanIt<value_type> &other) const {
//			return this->_ptr > other.base();
//		}
//
//		bool operator<=(const RanIt<value_type> &other) const {
//			return this->_ptr <= other.base();
//		}
//
//		bool operator<=(const ConstRanIt<value_type> &other) const {
//			return this->_ptr <= other.base();
//		}
//
//		bool operator>=(const RanIt<value_type> &other) const {
//			return this->_ptr >= other.base();
//		}
//
//		bool operator>=(const ConstRanIt<value_type> &other) const {
//			return this->_ptr >= other.base();
//		}
//
//		difference_type operator-(const RanIt<value_type> &other) const {
//			return this->_ptr - other.base();
//		}
//
//		difference_type operator-(const ConstRanIt<value_type> &other) const {
//			return this->_ptr - other.base();
//		}
//
//		difference_type operator+(const RanIt<value_type> &other) const {
//			return this->_ptr + other.base();
//		}
//
//		difference_type operator+(const ConstRanIt<value_type> &other) const {
//			return this->_ptr + other.base();
//		}
//
//		ConstRanIt operator+(const difference_type &a) const {
//			return ConstRanIt(_ptr + a);
//		}
//
//		ConstRanIt operator-(const difference_type &a) const {
//			return ConstRanIt(_ptr - a);
//		}
//
//		ConstRanIt & operator+=(const difference_type &a) {
//			_ptr += a;
//			return *this;
//		}
//
//		ConstRanIt & operator-=(const difference_type &a) {
//			_ptr -= a;
//			return *this;
//		}
//	};
//
//	template<typename L>
//	ConstRanIt<L> operator +(const typename ConstRanIt<L>::difference_type & a, const ConstRanIt<L> & iter){
//		return	(iter + a);
//	}
//
//	template<typename L>
//	ConstRanIt<L> operator -(const typename ConstRanIt<L>::difference_type & a, const ConstRanIt<L> & iter) {
//		return (iter - a);
//	}
//}


#endif
