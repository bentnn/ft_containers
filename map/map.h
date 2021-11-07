#ifndef MAP_H
#define MAP_H

#include <iostream>
#include "RBTree.hpp"

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
				typedef typename Compare::template rebind<value_type>::other node_compare;

				typedef RBTree<value_type, node_compare, allocator_type> tree_type;
//				typedef typename Allocator::template rebind<tree_type>::other tree_allocator;

			private:
				allocator_type _alloc;
//				tree_allocator _tree_alloc;
				tree_type _tree;
				key_compare _cmp;

			public:
				// constructors and destructors

				explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
					_alloc(alloc), _tree(tree_type(comp, alloc)), _cmp(comp) {}

//				template< class InputIt >
//				map(InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator());

//				map( const map& other );

				// getters

				allocator_type get_allocator() const {
					return _tree.get_allocator();
				}

				size_type size() const {
					return _tree.size();
				}



			};
}


#endif
