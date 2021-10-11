#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

namespace ft
{
	template<class T, class Alocator = std::allocator<T>>
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

	private:
		pointer		_array;			// array of T
		size_type 	_size;			// how much T vector has
		size_type _capacity;		// how much allocated memory vector has
		allocator_type _allocator;	// allocator for allocating and deallocating memory

	public:
		// constructors
		vector(): _array(0), _size(0), _capacity(0),
				_allocator(allocator_type()) {}

		explicit vector(const Allocator& alloc): _array(0), _size(0),
				_capacity(0), _allocator(alloc) {}

		explicit vector(size_type n): _size(n), _capacity(n),
				_allocator(allocator_type()) {
			_array = _allocator.allocate(n);
			for (size_type i = 0; i < n; i++)
				_allocator.construct(_vec + i, T());
		}

		explicit vector(size_type count, const T& value = T(),
						 const Allocator& alloc = Allocator());

		template< class InputIt >
		vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() );

		vector( const vector& other );

		// destructor
		~vector();

	};	
}


#endif
