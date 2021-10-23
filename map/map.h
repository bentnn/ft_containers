#ifndef MAP_H
#define MAP_H

#include <iostream>

namespace ft {
	template<
	        class Key,
			class T,
			class Compare = std::less<Key>,
			class Allocator = std::allocator<std::pair<const Key, T> > >

			class map {

			public:
				typedef Key key_type;
				typedef T mapped_type;
				typedef std::size_t size_type;
				typedef std::ptrdiff_t difference_type;
			};
}


#endif
