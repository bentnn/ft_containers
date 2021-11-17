#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "RBTree.hpp"
#include "../iterators/reverse_iterator.hpp"

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
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
//				typedef typename Compare::template rebind<value_type>::other pair_compare;
	private:
		class pair_compare {
			key_compare _cmp;

		public:
			pair_compare(const key_compare & cmp) : _cmp(cmp) {}

			bool operator()(const value_type& x, const value_type& y) const {
				return _cmp(x.first, y.first);
			}
		};

	public:
		typedef RBTree<value_type, pair_compare, allocator_type> tree_type;
		typedef typename tree_type::iterator iterator;
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

		size_type max_size() const {
			return _tree.max_size();
		}

		bool empty() const {
			return _tree.empty();
		}

		// iterators

		iterator begin() {
			return _tree.begin();
		}

		iterator end() {
			return _tree.end();
		}

		// basic methods

		void clear() {
			_tree.clear();
		}

		ft::pair<iterator, bool> insert( const value_type& value ) {
			return _tree.insert(value);
		}

		void erase( iterator pos ) {
			_tree.erase(pos);
		}


		mapped_type& operator[]( const key_type& key ) {
				return _tree.insert(ft::make_pair(key, mapped_type())).first->second;
			}
	};
}


#endif