#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "../iterators/iterators.hpp"
#include "../utils/enable_if.hpp"
#include "../utils/is_integral.hpp"

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

//		template<class InputIt>
		void uninitialized_copy_from_end(iterator first, iterator last, iterator dist) {
			dist += last - first - 1;
			last--;
			while (last >= first) {
				//std::cout << *last << " " << (dist - begin()) << std::endl;
				_allocator.destroy(dist.base());
				_allocator.construct(dist.base(), *last);
				last--;
				dist--;
			}
		}

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
		vector(typename ft::enable_if< !ft::is_integral<InputIt>::value, InputIt >::type first, InputIt last,
			   const Allocator& alloc = Allocator()): _allocator(alloc) {
			if (first > last)
				throw std::length_error("vector");
			_size = last - first;
			_capacity = _size;
			_array = _allocator.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
				_allocator.construct(_array + i, *(first + i));
		}

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
				for (size_type i = 0; i < _size; i++)
					_allocator.construct(new_arr + i, *(_array + i));
			} catch (std::exception &e) {
				size_type i = 0;
				while (new_arr + i != NULL && i < _size) {
					_allocator.destroy(new_arr + i);
					i++;
				}
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
				throw std::out_of_range("vector");
			return *(_array + pos);
		}

		const_reference at(size_type pos) const {
			if (pos >= _size)
				throw std::out_of_range("vector");
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

		iterator erase(iterator pos) {
			difference_type d = std::distance(begin(), pos);
			std::copy(pos + 1, end(), pos);
			_size--;
			_allocator.destroy(_array + _size - 1);
			return d == _size ? end() : iterator(_array + d);
		}

		iterator erase(iterator first, iterator last) {
			difference_type start = std::distance(begin(), first);
			difference_type need_to_copy = std::distance(last, end());
			bool last_is_end = (last == end());
			while (first != last) {
				_allocator.destroy(first.base());
				first++;
			}
			size_type i = start;
			while (last < end()) {
				if (this->_array + start)
					_allocator.destroy(this->_array + i);
				_allocator.construct(this->_array + i, *last);
				i++;
				last++;
			}
			//std::uninitialized_copy(last.base(), end().base(), _array + start);
			for (size_type i = start + need_to_copy; i < _size; i++)
				_allocator.destroy(_array + i);
			_size = start + need_to_copy;
			return last_is_end ? end() : iterator(_array + start);
		}

		void insert(iterator pos, size_type count, const T& value) {
			if (count == 0)
				return;
			else if (max_size() - _size < count || pos < begin() || pos > end())
				throw std::length_error("vector");
			difference_type start = pos - begin();
			if (_size + count > _capacity)
				reserve(_capacity * 2 >= _size + count ? _capacity * 2 : _size + count);
			pos = begin() + start;
			uninitialized_copy_from_end(pos, end(), pos + count);
			for (size_type i = 0; i < count; i++) {
				if ((pos + i).base())
					_allocator.destroy((pos + i).base());
				_allocator.construct((pos + i).base(), value);
			}
			_size += count;
		}

		iterator insert(iterator pos, const T& value) {
			if (pos < begin() || pos > end())
				throw std::logic_error("vector");
			difference_type start = pos - begin();
			if (_size + 1 > _capacity)
				reserve(_capacity * 2);
			pos = begin() + start;
			uninitialized_copy_from_end(pos, end(), pos + 1);
			if (pos.base())
				_allocator.destroy(pos.base());
			_allocator.construct(pos.base(), value);
			_size++;
		}

		template<class InputIt>
		void insert( iterator pos, typename ft::enable_if< !ft::is_integral<InputIt>::value, InputIt >::type first, InputIt last ) {
			if (pos < begin() || pos > end() || first > last)
				throw std::logic_error("vector");
			difference_type start = pos - begin();
			difference_type count = last - first;
			if (_size + count > _capacity)
				reserve(_capacity * 2 >= _size + count ? _capacity * 2 : _size + count);
			pos = begin() + start;
			uninitialized_copy_from_end(pos, end(), pos + count);
			while (first < last) {
				if (pos.base())
					_allocator.destroy(pos.base());
				_allocator.construct(pos.base(), *first);
				pos++;
				first++;
			}
			_size += count;
		}

	};	
}


#endif
