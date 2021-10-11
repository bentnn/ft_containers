#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

#include "iterators.hpp"

namespace ft
{
	template<class T, class Allocator = std::allocator<T> >
	class vector {
	public:
		// def
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
		typedef ft::RanIt<value_type> iterator;
		typedef ft::RanIt<value_type const> const_iterator;

	private:
		pointer		_array;			// array of T
		size_type 	_size;			// how much T vector has
		size_type _capacity;		// how much allocated memory vector has
		allocator_type _allocator;	// allocator for allocating and deallocating memory

	public:
		// constructors
		explicit vector(const Allocator& alloc = allocator_type()): _array(0), _size(0),
				_capacity(0), _allocator(alloc) {}

		explicit vector(size_type n, const T& value = T(),
						 const Allocator& alloc = Allocator()): _size(n), _capacity(n), _allocator(alloc) {
			this->_array = this->_allocator.allocate(n);
			for (size_type i = 0; i < n; i++)
				this->_allocator.construct(this->_array + i, value);
		}

		template<class InputIt>
		vector(InputIt first, InputIt last, const Allocator& alloc = Allocator()): _allocator(alloc) {

		}

		vector( const vector& other );

		// destructor
		~vector() {
			for (size_type i = 0; i < _size; i++)
				_allocator.destroy(_array + i);
			if (_capacity)
				_allocator.deallocate(_array, _capacity);
		}


		vector& operator= (const vector& x) {
			this->_capacity = x._capacity;
			this->_size = x._size;
			this->_allocator = x._allocator;
			this->_array = this->_allocator.allocate(this->_capacity);
			for (size_type i = 0; i < this->_size; i++)
				this->_array[i] = this->_allocator.construct(this->_array + i, x[i]);
			return *this;
		}

		reference operator[] (size_type n) {
			return *(this->_array + n);
		}

		const_reference operator[] (size_type n) const {
			return *(this->_array + n);
		}

		iterator begin() {
			return iterator(_array);
		}

		const_iterator begin() const{
			return const_iterator(_array);
		}
	};	
}


#endif
