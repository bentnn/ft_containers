#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "../iterators/reverse_iterator.hpp"
#include "../utils/enable_if.hpp"
#include "../utils/iterator_traits.hpp"
#include "../utils/remove_const.hpp"
#include "../utils/is_integral.hpp"
#include "../utils/lexicographical_compare.hpp"
#include <cstring>

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector {

	private:

	template< typename L>class RanIt
	{
	public:
		typedef	typename ft::iterator_traits<L*>::value_type 	value_type;
		typedef	typename ft::iterator_traits<L*>::pointer	pointer;
		typedef	typename ft::iterator_traits<L*>::reference	reference;
		typedef	typename ft::iterator_traits<L*>::difference_type	difference_type;
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
		typedef RanIt<value_type> iterator;
		typedef RanIt<const value_type> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;


	private:
		pointer		_array;			// array of T
		size_type 	_size;			// how much T vector has
		size_type _capacity;		// how much allocated memory vector has
		allocator_type _allocator;	// allocator for allocating and deallocating memory

//		template<class InputIt>
//		void uninitialized_copy_from_end(iterator first, iterator last, iterator dist) {
//			last--;
//			dist += last - first;
//
//			while (last >= first) {
//				//_allocator.destroy(dist.base());
//				_allocator.construct(dist.base(), *last);
//				last--;
//				dist--;
//			}
//		}

	public:
		// constructors
		explicit vector(const allocator_type& alloc = allocator_type()): _array(0), _size(0),
																		 _capacity(0), _allocator(alloc) {}

		explicit vector(size_type n, const T& value = T(),
						const allocator_type& alloc = allocator_type()): _size(n), _capacity(n), _allocator(alloc) {
			this->_array = this->_allocator.allocate(n);
			for (size_type i = 0; i < n; i++)
				this->_allocator.construct(this->_array + i, value);
		}

		template<class InputIt>
		vector(typename ft::enable_if< !ft::is_integral<InputIt>::value, InputIt >::type first, InputIt last,
			   const allocator_type& alloc = allocator_type()): _allocator(alloc) {
			if (first > last)
				throw std::length_error("vector");
			_size = last - first;
			_capacity = _size;
			_array = _allocator.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
				_allocator.construct(_array + i, *(first + i));
		}

		vector(const vector& other): _capacity(0) {
			*this = other;
		}

		// destructor
		~vector() {
			for (size_type i = 0; i < _size; i++)
				_allocator.destroy(_array + i);
			if (_capacity)
				_allocator.deallocate(_array, _capacity);
		}

		vector& operator=(const vector& x) {
			if (this == &x)
				return *this;
			if (this->_capacity != 0) {
				for (size_type i = 0; i < _size; i++)
					_allocator.destroy(_array + i);
				this->_allocator.deallocate(this->_array, this->_capacity);
			}
			this->_capacity = x._capacity;
			this->_size = x._size;
			this->_allocator = x._allocator;
			this->_array = this->_allocator.allocate(this->_capacity);
			for (size_type i = 0; i < this->_size; i++)
				this->_allocator.construct(this->_array + i, x[i]);
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

		const_iterator begin() const {
			return const_iterator(_array);
		}

		iterator end() {
			return iterator(_array + _size);
		}

		const_iterator end() const {
			return const_iterator(_array + _size);
		}

		reverse_iterator rbegin() {
			return reverse_iterator(end());
		}

		const_reverse_iterator rbegin() const {
			return const_reverse_iterator(end());
		}

		reverse_iterator rend() {
			return reverse_iterator(begin());
		}

		const_reverse_iterator rend() const {
			return const_reverse_iterator(begin());
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

		pointer data() {
			return _array;
		}

		const_pointer data() const {
			return _array;
		}

		size_type max_size() const {
			return _allocator.max_size();
		}

		void clear() {
			for (size_type i = 0; i < _size; i++)
				_allocator.destroy(_array + i);
			_size = 0;
		}

		void pop_back() {
			_allocator.destroy(_array + _size - 1);
			_size--;
		}

		void push_back(const T& value) {
			if (_size == _capacity)
				reserve(_capacity == 0 ? 1 : _capacity * 2);
			_allocator.construct(_array + _size, value);
			_size++;
		}

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
				_allocator.destroy(&(*first));
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
			if (_size + count > _capacity) {
				size_type new_cap = _capacity * 2 >= _size + count ? _capacity * 2 : _size + count;
				pointer new_arr = _allocator.allocate(new_cap);
				std::uninitialized_copy(begin(), pos, iterator(new_arr));
				for (size_type i = 0; i < count; i++)
					_allocator.construct(new_arr + start + i, value);
				std::uninitialized_copy(pos, end(), iterator(new_arr + start + count));
				for (size_type i = 0; i < _size; i++)
					_allocator.destroy(_array + i);
				_allocator.deallocate(_array, _capacity);
				_size += count;
				_capacity = new_cap;
				_array = new_arr;
			}
			else {
				for (size_type i = _size; i > start; i--) {
					_allocator.destroy(_array + i + count - 1);
					_allocator.construct(_array + i + count - 1, *(_array + i - 1));
				}
				for (size_type i = 0; i < count; i++) {
					_allocator.destroy(_array + i + start);
					_allocator.construct(_array + start + i, value);
				}
				_size += count;
			}
		}

		iterator insert(iterator pos, const T& value) {
			if (pos < begin() || pos > end())
				throw std::logic_error("vector");
			difference_type start = pos - begin();
			if (_size == _capacity) {
				_capacity = _capacity * 2 + (_capacity == 0);
				pointer new_arr = _allocator.allocate(_capacity);
				std::uninitialized_copy(begin(), pos, iterator(new_arr));
				_allocator.construct(new_arr + start, value);
				std::uninitialized_copy(pos, end(), iterator(new_arr + start + 1));
				for (size_t i = 0; i < _size; i++)
					_allocator.destroy(_array + i);
				_allocator.deallocate(_array, _size);
				_size++;
				_array = new_arr;
			}
			else {
				for (size_type i = _size; i > start; i--) {
					_allocator.destroy(_array + i);
					_allocator.construct(_array + i, *(_array + i - 1));
				}
				_allocator.destroy(&(*pos));
				_allocator.construct(&(*pos), value);
				_size++;
			}
			return begin() + start;
		}

		template<class InputIt>
		void insert(iterator pos,
					typename ft::enable_if< !ft::is_integral<InputIt>::value, InputIt >::type first,
					InputIt last) {
			if (pos < begin() || pos > end() || first > last)
				throw std::logic_error("vector");
			difference_type start = pos - begin();
			difference_type count = last - first;
			if (_size + count > _capacity) {
				size_type new_cap = _capacity * 2 >= _size + count ? _capacity * 2 : _size + count;
				pointer new_arr = _allocator.allocate(new_cap);
				std::uninitialized_copy(begin(), pos, iterator(new_arr));
				for (size_type i = 0; i < count; i++, first++)
					_allocator.construct(new_arr + start + i, *first);
				std::uninitialized_copy(pos, end(), iterator(new_arr + start + count));
				for (size_type i = 0; i < _size; i++)
					_allocator.destroy(_array + i);
				_allocator.deallocate(_array, _capacity);
				_size += count;
				_capacity = new_cap;
				_array = new_arr;
			}
			else {
				for (size_type i = _size; i > start; i--) {
					_allocator.destroy(_array + i + count - 1);
					_allocator.construct(_array + i + count - 1, *(_array + i - 1));
				}
				for (size_type i = 0; i < count; i++, first++) {
					_allocator.destroy(_array + i + count);
					_allocator.construct(_array + start + i, *first);
				}
				_size += count;
			}
		}

		void swap(vector& other) {
//			pointer tmp = this->_array;
//			this->_array = other._array;
//			other._array = tmp;
//			size_t tmp = this->_size;
//			this->_size = other.size();
//			other._size = tmp;
//			tmp = this->_capacity;
//			this->_capacity = other._capacity;
//			other._capacity = tmp;
//			allocator_type tmp_alloc = this->_allocator;
			std::swap(other, *this);
		}

		void assign(size_type count, const T& value) {
			clear();
			if (count > capacity()) {
				_allocator.deallocate(_array, _capacity);
				_array = _allocator.allocate(count);
				_capacity = count;
			}
			for (size_type i = 0; i < count; i++)
				_allocator.construct(_array + i, value);
			_size = count;
		}

		template< class InputIt >
		void assign(typename ft::enable_if< !ft::is_integral<InputIt>::value, InputIt >::type first,
					InputIt last) {
			if (first > last)
				throw std::logic_error("vector");
			difference_type count = last - first;
			clear();
			if (count > static_cast<difference_type>(capacity())) {
				_allocator.deallocate(_array, _capacity);
				_array = _allocator.allocate(count);
				_capacity = count;
			}
			iterator pos = begin();
			while (first < last)
			{
				_allocator.construct(&(*pos), *first);
				pos++;
				first++;
			}
			_size = count;
		}

		template<typename A, typename B>
		friend bool operator==(const vector::template RanIt<A> & lhs, const vector::template RanIt<B> & rhs){
			return &(*lhs) == &(*rhs);
		}

		template<typename A, typename B>
		friend bool operator!=(const vector::template RanIt<A> & lhs, const vector::template RanIt<B> & rhs) {
			return &(*lhs) != &(*rhs);
		}

		template<typename A, typename B>
		friend bool operator>(const vector::template RanIt<A> & lhs, const vector::template RanIt<B> & rhs) {
			return &(*lhs) > &(*rhs);
		}

		template<typename A, typename B>
		friend bool operator<(const vector::template RanIt<A> & lhs, const vector::template RanIt<B> & rhs) {
			return &(*lhs) < &(*rhs);
		}

		template<typename A, typename B>
		friend bool operator<=(const vector::template RanIt<A> & lhs, const vector::template RanIt<B> & rhs) {
			return &(*lhs) <= &(*rhs);
		}


		template<typename A, typename B>
		friend bool operator>=(const vector::template RanIt<A> & lhs, const vector::template RanIt<B> & rhs) {
			return &(*lhs) >= &(*rhs);
		}

		template<typename A, typename B>
		friend typename vector::template RanIt<A>::difference_type operator-(const vector::template RanIt<A> & lhs, const vector::template RanIt<B> & rhs){
			return &(*lhs) - &(*rhs);
		}

		template<typename A, typename B>
		friend typename vector::template RanIt<A>::difference_type operator+(const vector::template RanIt<A> & lhs, const vector::template RanIt<B> & rhs){
			return &(*lhs) + &(*rhs);
		}

		template<typename L>
		friend vector::template RanIt<L> operator +(const typename vector::template RanIt<L>::difference_type & a, const vector::template RanIt<L> & iter){
			return	(iter + a);
		}

		template<typename L>
		friend vector::template RanIt<L> operator -(const typename vector::template RanIt<L>::difference_type & a, const vector::template RanIt<L> & iter){
			return	(iter - a);
		}
	};

	template< class A, class Alloc>
	bool operator==(const ft::vector<A, Alloc> &lhs,
					const ft::vector<A, Alloc> &rhs) {
		if (lhs.size() != rhs.size())
			return false;
		for (size_t i = 0; i < rhs.size(); i++)
			if (lhs[i] != rhs[i])
				return false;
		return true;
	}

	template< class A, class Alloc>
	bool operator!=(const ft::vector<A, Alloc> &lhs,
					const ft::vector<A, Alloc> &rhs) {
		return !(lhs == rhs);
	}

	template< class A, class Alloc>
	bool operator<(const ft::vector<A, Alloc> &lhs,
				   const ft::vector<A, Alloc> &rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template< class A, class Alloc>
	bool operator>(const ft::vector<A, Alloc> &lhs,
				   const ft::vector<A, Alloc> &rhs) {
		return rhs < lhs;
	}

	template< class A, class Alloc>
	bool operator<=(const ft::vector<A, Alloc> &lhs,
					const ft::vector<A, Alloc> &rhs) {
		return !(lhs > rhs);
	}

	template< class A, class Alloc>
	bool operator>=(const ft::vector<A, Alloc> &lhs,
					const ft::vector<A, Alloc> &rhs) {
		return !(lhs < rhs);
	}

	template< class T, class Alloc >
	void swap(std::vector<T,Alloc>& lhs, std::vector<T,Alloc>& rhs) {
		lhs.swap(rhs);
	}

	template<typename A, typename B>
	bool operator==(const typename vector<A>::template RanIt<A> &lhs, const typename vector<B>::template RanIt<B> &rhs) {
		return &(*lhs) == &(*rhs);
	}

	template<typename A, typename B>
	bool operator!=(const typename vector<A>::template RanIt<A> &lhs, const typename vector<B>::template RanIt<B> &rhs) {
		return !(lhs == rhs);
	}


	template<typename A, typename B>
	bool operator>(const typename ft::vector<A>::iterator  & lhs, const typename ft::vector<B>::iterator  & rhs) {
		return &(*lhs) > &(*rhs);
	}

	template<typename A, typename B>
	bool operator<(const typename ft::vector<A>::iterator  & lhs, const typename ft::vector<B>::iterator  & rhs) {
		return &(*lhs) < &(*rhs);
	}

	template<typename A, typename B>
	bool operator<=(const typename ft::vector<A>::iterator  & lhs, const typename ft::vector<B>::iterator  & rhs) {
		return &(*lhs) <= &(*rhs);
	}


	template<typename A, typename B>
	bool operator>=(const typename ft::vector<A>::iterator  & lhs, const typename ft::vector<B>::iterator  & rhs) {
		return &(*lhs) >= &(*rhs);
	}

	template<typename A, typename B>
	typename ft::vector<A>::iterator::difference_type operator-(const typename ft::vector<A>::iterator  & lhs, const typename ft::vector<B>::iterator  & rhs){
		return &(*lhs) - &(*rhs);
	}

	template<typename A, typename B>
	typename ft::vector<A>::iterator::difference_type operator+(const typename ft::vector<A>::iterator  & lhs, const typename ft::vector<B>::iterator  & rhs){
		return &(*lhs) + &(*rhs);
	}

	template<typename L>
	typename ft::vector<L>::iterator operator +(const typename ft::vector<L>::iterator::difference_type & a, const typename ft::vector<L>::iterator & iter){
		return	(iter + a);
	}

	template<typename L>
	typename ft::vector<L>::iterator operator -(const typename ft::vector<L>::iterator::difference_type & a, const typename ft::vector<L>::iterator & iter){
		return	(iter - a);
	}
}
#endif
