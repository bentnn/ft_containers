#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "../iterators.hpp"

namespace ft
{
	template<typename T>class ConstRanIt;
	template<typename T>class RanIt;
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
		typedef ft::ConstRanIt<value_type> const_iterator;

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

//		template<class InputIt>
//		vector(InputIt first, InputIt last, const Allocator& alloc = Allocator()): _allocator(alloc) {
//
//		}

		vector( const vector& other ) {
			*this = other;
		}

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

		iterator end() {
			return iterator(_array + _size);
		}

		size_type size() const {
			return _size;
		}

		size_type capacity() const {
			return _capacity;
		}

		bool empty() const {
			return (_size == 0);
		}

		void reserve(size_type new_cap) {
			if (new_cap <= _capacity)
				return;
			pointer new_arr = _allocator.allocate(new_cap);
			try {
				std::uninitialized_copy(_array, _array + _size, new_arr);
			} catch (std::exception &e) {
				_allocator.deallocate(new_arr, new_cap);
				throw;
			}
			for (size_type i = 0; i < _size; i++)
				_allocator.destroy(_array + i);
			if (_capacity)
				_allocator.deallocate(_array, _capacity);
			_capacity = new_cap;
			_array = new_arr;
		}

		void resize(size_type count, value_type value = T()) {
			if (count < _size) {
				for (size_type i = count; i < _size; i++)
					_allocator.destroy(_array + i);
				_size = count;
			}
			else if (count > _size) {
				if (_capacity < count)
					this->reserve(_capacity * 2 > count ? _capacity * 2 : count);
				for (size_type i = _size; i < count; i++) {
					_allocator.construct(this->_array + i, value);
					_size++;
				}
			}
		}

		reference at(size_type pos) {
			if (pos >= _size)
				throw std::out_of_range("vector: pos is out of range");
			return *(_array + pos);
		}

		const_reference at(size_type pos) const {
			if (pos >= _size)
				throw std::out_of_range("vector: pos is out of range");
			return *(_array + pos);
		}

		reference front() {
			return *_array;
		}

		const_reference front() const {
			return *_array;
		}

		reference back() {
			return *(_array + _size - 1);
		}

		const_reference back() const {
			return *(_array + _size - 1);
		}

		allocator_type get_allocator() const {
			return _allocator;
		}

		size_type max_size() const {
			return _allocator.max_size();
		}

		void clear() {
			for (size_type i = 0; i < _size; i++)
				_allocator.destroy(_array + i);
			_size = 0;
		}

//		void pop_back() {
//
//		}

//		iterator erase(iterator pos) {
//
//		}

//		iterator insert(iterator pos, const T& value) {
//			if ()
//			if (_size == _capacity)
//				reserve(_capacity * 2);
//			_allocator.construct(this->_array + _size, value);
//			_size++;
//		}
	};	
}


#endif
