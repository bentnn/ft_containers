#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include "../utils/iterator_traits.hpp"
#include "../utils/remove_const.hpp"

template< typename L>class RanIt
{
public:
	typedef	typename ft::iterator_traits<L*>::value_type 	value_type;
	typedef	typename ft::iterator_traits<L*>::pointer	pointer;
	typedef	typename ft::iterator_traits<L*>::reference	reference;
	typedef	typename ft::iterator_traits<L*>::difference_type	difference_type;
	typedef pointer									iterator_type;
	//this is for std::functions
	typedef	std::random_access_iterator_tag iterator_category;

	//maybe protected???
private:
	pointer _ptr;

public:

	// CONSTRUCTORS
	RanIt() : _ptr() {}

	RanIt(pointer a) : _ptr(a) {}

	RanIt(const RanIt<typename ft::remove_const<value_type>::type > & src) : _ptr(&(*src)) {}

	virtual ~RanIt() {}

	RanIt<value_type> & operator=(RanIt<typename ft::remove_const<value_type>::type > const & src) {
		_ptr = &(*src);
		return *this;
	}

	//OPERATORS
	RanIt & operator++() {
		++_ptr;
		return *this;
	}

	RanIt operator++(int) {
		RanIt tmp(*this);
		++_ptr;
		return tmp;
	}

	RanIt & operator--() {
		--_ptr;
		return *this;
	}

	RanIt  operator--(int) {
		RanIt tmp = *this;
		--_ptr;
		return tmp;
	}
	RanIt operator+(const difference_type & a) const {
		return _ptr + a;
	}

	RanIt operator-(const difference_type & a) const {
		return _ptr - a;
	}

	RanIt & operator+=(const difference_type & a) {
		_ptr += a;
		return (*this);
	}

	RanIt & operator-=(const difference_type & a) {
		_ptr -= a;
		return (*this);
	}

	pointer operator->() const {
		return _ptr;
	}

	reference operator*() const {
		return *_ptr;
	}

	reference operator[](difference_type n) const {
		return *(_ptr + n);
	}
};

template<typename A, typename B>
bool operator==(const RanIt<A> & lhs, const RanIt<B> & rhs){
	return &(*lhs) == &(*rhs);
}

template<typename A, typename B>
bool operator!=(const RanIt<A> & lhs, const RanIt<B> & rhs) {
	return &(*lhs) != &(*rhs);
}

template<typename A, typename B>
bool operator>(const RanIt<A> & lhs, const RanIt<B> & rhs) {
	return &(*lhs) > &(*rhs);
}

template<typename A, typename B>
bool operator<(const RanIt<A> & lhs, const RanIt<B> & rhs) {
	return &(*lhs) < &(*rhs);
}

template<typename A, typename B>
bool operator<=(const RanIt<A> & lhs, const RanIt<B> & rhs) {
	return &(*lhs) <= &(*rhs);
}


template<typename A, typename B>
bool operator>=(const RanIt<A> & lhs, const RanIt<B> & rhs) {
	return &(*lhs) >= &(*rhs);
}

template<typename A, typename B>
typename RanIt<A>::difference_type operator-(const RanIt<A> & lhs, const RanIt<B> & rhs){
	return &(*lhs) - &(*rhs);
}

template<typename A, typename B>
typename RanIt<A>::difference_type operator+(const RanIt<A> & lhs, const RanIt<B> & rhs){
	return &(*lhs) + &(*rhs);
}

template<typename L>
RanIt<L> operator +(const typename RanIt<L>::difference_type & a, RanIt<L> & iter){
	return	(iter + a);
}

template<typename L>
RanIt<L> operator -(const typename RanIt<L>::difference_type & a, const RanIt<L> & iter){
	return	(iter - a);
}

#endif
