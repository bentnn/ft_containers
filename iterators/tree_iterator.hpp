#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

#include "../utils/remove_const.hpp"
#include "../utils/iterator_traits.hpp"
#include "../utils/node.hpp"

template<typename T>
class TreeIter {
public:
	typedef std::bidirectional_iterator_tag iterator_category;
	typedef typename ft::iterator_traits<T*>::value_type 		value_type;
	typedef typename ft::iterator_traits<T*>::reference 		reference;
	typedef typename ft::iterator_traits<T*>::pointer			pointer;
	typedef typename ft::iterator_traits<T*>::difference_type	difference_type;

//		template <class _Cont, class _Comp, class _Alloc> friend class  RBTree;

	typedef node<typename ft::remove_const<value_type>::type >* node_pointer;

private:
	node_pointer _node;

	node_pointer tree_min(node_pointer n) const {
		while (n->left != NULL && !n->left->is_nil)
			n = n->left;
		return n;
	}

	node_pointer tree_max(node_pointer n) const {
		while (!n->right->is_nil)
			n = n->right;
		return n;
	}

public:
	TreeIter() {}

	TreeIter(void *node): _node(static_cast<node_pointer>(node)) {}

	TreeIter(const TreeIter<typename ft::remove_const<value_type>::type> & other) {
		*this = other;
	}

	TreeIter& operator=(const TreeIter<typename ft::remove_const<value_type>::type> & other) {
		this->_node = other.node();
		return *this;
	}

	reference operator*() const {
		return *(_node->content);
	}

	pointer operator->() const {
		return _node->content;
	}

	TreeIter& operator++() {
		if (_node->right && !_node->right->is_nil) {
			_node = tree_min(_node->right);
		}
		else {
			node_pointer y = _node->father;
			while (y != NULL && _node == y->right) {
				_node = y;
				y = y->father;
			}
			_node = y;
		}
		return *this;
	}

	TreeIter operator++(int) {
		TreeIter<value_type> temp = *this;
		if (_node->right && !_node->right->is_nil) {
			_node = tree_min(_node->right);
		}
		else {
			node_pointer y = _node->father;
			while (y != NULL && _node == y->right) {
				_node = y;
				y = y->father;
			}
			_node = y;
		}
		return temp;
	}

	TreeIter& operator--() {
		if (_node->left && !_node->left->is_nil) {
			_node = tree_max(_node->left);
		}
		else {
			node_pointer y = _node->father;
			while (y != NULL && _node == y->left) {
				_node = y;
				y = y->father;
			}
			_node = y;
		}
		return *this;
	}

	TreeIter operator--(int) {
		TreeIter<value_type> temp = *this;
		if (_node->left && !_node->left->is_nil) {
			_node = tree_max(_node->left);
		}
		else {
			node_pointer y = _node->father;
			while (y != NULL && _node == y->left) {
				_node = y;
				y = y->father;
			}
			_node = y;
		}
		return temp;
	}

	node_pointer node() const {
		return _node;
	}
};

template<typename A, typename B>
bool operator==(const TreeIter<A> & lhs, const TreeIter<B> & rhs) {
	return lhs.node() == rhs.node();
}

template<typename A, typename B>
bool operator!=(const TreeIter<A> & lhs, const TreeIter<B> & rhs) {
	return lhs.node() != rhs.node();
}

#endif
