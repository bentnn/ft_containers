#ifndef MAP_H
#define MAP_H

#include <iostream>
#include "pair.hpp"

namespace ft {
	template<
	        class Key,
			class T,
			class Compare = std::less<Key>,
			class Allocator = std::allocator<ft::pair<const Key, T> > >

			class map {

			public:
				typedef Key key_type;
				typedef T mapped_type;
				typedef std::size_t size_type;
				typedef std::ptrdiff_t difference_type;
				typedef Compare key_compare;
				typedef ft::pair<const Key, T> value_type;
				typedef Allocator allocator_type;
				typedef value_type& reference;
				typedef const value_type& const_reference;
				typedef Allocator::pointer pointer;
				typedef Allocator::const_pointer const_pointer;

			private:
				allocator_type _allocator;

			};
}


#endif
