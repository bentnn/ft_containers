#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "../tree/RBTree.hpp"
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
				//return _cmp(x.first, y.first) || (!_cmp(y.first, x.first) && x.second < y.second);
			}
		};

	public:
		typedef pair_compare value_compare;
		typedef RBTree<value_type, value_compare, allocator_type> tree_type;
		typedef typename tree_type::iterator iterator;
		typedef typename tree_type::const_iterator const_iterator;
		typedef typename tree_type::reverse_iterator reverse_iterator;
		typedef typename tree_type::const_reverse_iterator const_reverse_iterator;

	private:
		tree_type _tree;
		key_compare _cmp;

	public:
		// constructors and destructors

		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
			_tree(tree_type(value_compare(comp), alloc)), _cmp(comp){}

		template< class InputIt >
		map(InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator()):
																			_tree(tree_type(first, last, value_compare(comp), alloc)),
																			_cmp(comp) {}

		map(const map& other): _tree(tree_type(other._tree)), _cmp(other._cmp) {}

		// operators

		map& operator=(const map& other) {
			this->_tree = other._tree;
			this->_cmp = other._cmp;
			return *this;
		}

		mapped_type& operator[]( const key_type& key ) {
			return _tree.insert(ft::make_pair(key, mapped_type())).first->second;
		}

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

		value_compare value_comp() const {
			return _tree.value_comp();
		}

		key_compare key_comp() const {
			return _cmp;
		}

		// iterators

		iterator begin() {
			return _tree.begin();
		}

		const_iterator begin() const{
			return _tree.begin();
		}

		iterator end() {
			return _tree.end();
		}

		const_iterator end() const{
			return _tree.end();
		}

		reverse_iterator rbegin() {
			return _tree.rbegin();
		}

		const_reverse_iterator rbegin() const {
			return _tree.rbegin();
		}

		reverse_iterator rend() {
			return _tree.rend();
		}

		const_reverse_iterator rend() const {
			return _tree.rend();
		}

		// basic methods

		void clear() {
			_tree.clear();
		}

		T& at( const Key& key ) {
			iterator res = _tree.find(ft::make_pair(key, mapped_type()));
			if (res == _tree.end())
				throw std::out_of_range("map::at:  key not found");
			return res->second;
		}

		void swap(map& other) {
			std::swap(this->_cmp, other._cmp);
			_tree.swap(other._tree);
		}

		iterator find( const Key& key ) {
			return _tree.find(ft::make_pair(key, mapped_type()));
		}

		const_iterator find( const Key& key ) const {
			return _tree.find(ft::make_pair(key, mapped_type()));
		}

		size_type count( const Key& key ) const {
			return _tree.count(ft::make_pair(key, mapped_type()));
		}

		// bounds

		iterator lower_bound(const key_type& k) {
			return _tree.lower_bound(ft::make_pair(k, mapped_type()));
		}

		const_iterator lower_bound(const key_type& k) const {
			return _tree.lower_bound(ft::make_pair(k, mapped_type()));
		}

		iterator upper_bound(const key_type& k) {
			return _tree.upper_bound(ft::make_pair(k, mapped_type()));
		}

		const_iterator upper_bound(const key_type& k) const {
			return _tree.upper_bound(ft::make_pair(k, mapped_type()));
		}

		pair<iterator,iterator> equal_range(const key_type& k) {
			return _tree.equal_range(ft::make_pair(k, mapped_type()));
		}

		pair<const_iterator,const_iterator> equal_range(const key_type& k) const {
			return _tree.equal_range(ft::make_pair(k, mapped_type()));
		}

		// insert

		ft::pair<iterator, bool> insert( const value_type& value ) {
			return _tree.insert(value);
		}

		iterator insert(iterator hint, const value_type& value) {
			return _tree.insert(hint, value);
		}

		template<class InputIt>
		void insert(typename ft::enable_if< !ft::is_integral<InputIt>::value, InputIt >::type first,
					InputIt last) {
			_tree.insert(first, last);
		}

		// erase

		void erase( iterator pos ) {
			_tree.erase(pos);
		}

		size_type erase( const Key& key ) {
			return _tree.erase(ft::make_pair(key, mapped_type()));
		}

		void erase (iterator first, iterator last) {
			_tree.erase(first, last);
		}

        template<class _Key, class _T, class _Compare, class _Alloc>
        friend bool operator==(const map<_Key, _T, _Compare, _Alloc>& lhs,
                        const map<_Key, _T, _Compare, _Alloc>& rhs);

        template<class _Key, class _T, class _Compare, class _Alloc>
        friend bool operator<(const map<_Key, _T, _Compare, _Alloc>& lhs,
                       const map<_Key, _T, _Compare, _Alloc>& rhs);
	};

	template<class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key, T, Compare, Alloc>& lhs,
					const map<Key, T, Compare, Alloc>& rhs) {
		return lhs._tree == rhs._tree;
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key, T, Compare, Alloc>& lhs,
					const map<Key, T, Compare, Alloc>& rhs) {
		return !(lhs == rhs);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key, T, Compare, Alloc>& lhs,
					const map<Key, T, Compare, Alloc>& rhs) {
		return lhs._tree < rhs._tree;
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key, T, Compare, Alloc>& lhs,
					const map<Key, T, Compare, Alloc>& rhs) {
		return rhs < lhs;
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key, T, Compare, Alloc>& lhs,
					const map<Key, T, Compare, Alloc>& rhs) {
		return !(lhs > rhs);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc>& lhs,
					const map<Key, T, Compare, Alloc>& rhs) {
		return !(lhs < rhs);
	}
}

namespace std {
	template<class Key, class T, class Compare, class Alloc>
	void swap(const ft::map<Key, T, Compare, Alloc>& lhs,
			  const ft::map<Key, T, Compare, Alloc>& rhs) {
		lhs.swap(rhs);
	}
}

#endif
