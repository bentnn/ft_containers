#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

#include "../map/RBTree.hpp"


template<typename T>
class TreeIter {
public:
//	template< class Content, class Compare = std::less<Content>, class Allocator = std::allocator<Content> > class RBTree;

	typedef ptrdiff_t difference_type;
	typedef std::bidirectional_iterator_tag iterator_category;
	typedef T								value_type;
	typedef T&								reference;
	typedef T*								pointer;

	typedef node<T>* node_pointer;

private:
//	typedef RBTree<T> tree_type;

	node_pointer _node;

	node_pointer tree_min(node_pointer n) {
		while (n->left != NULL && !n->left->is_nil)
			n = n->left;
		return n;
	}

	node_pointer tree_max(node_pointer n) {
		while (!n->right->is_nil)
			n = n->right;
		return n;
	}


public:
	TreeIter() {}

	TreeIter(void *node): _node(static_cast<node_pointer>(node)) {}

	TreeIter(const TreeIter<value_type> & other) {
		this->_node = other._node;
	}

	TreeIter& operator=(const TreeIter<value_type>& other) {
		this->_node = other._node;
		return *this;
	}

	reference operator*() const {
		return *(_node->content);
	}

	pointer operator->() const {
		return _node->val;
	}

	TreeIter& operator++() {
		if (!_node->right->is_nil) {
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
		if (!_node->right->is_nil) {
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
		if (!_node->left->is_nil) {
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
		if (!_node->left->is_nil) {
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

	bool operator==(const TreeIter<value_type> &other) const {
		return this->_node == other._node;
	}

	bool operator!=(const TreeIter<value_type> &other) const {
		return this->_node != other._node;
	}
};


#endif
