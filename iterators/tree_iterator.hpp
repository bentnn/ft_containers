#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

#include "../map/RBTree.hpp"


template<typename T>
class TreeIter {
public:
	template< class Content, class Compare = std::less<Content>, class Allocator = std::allocator<Content> > class RBTree;

	typedef ptrdiff_t difference_type;
	typedef std::bidirectional_iterator_tag iterator_category;
	typedef T								value_type;
	typedef T&								reference;
	typedef T*								pointer;

	typedef node<T>* node_pointer;

private:
	typedef RBTree<T> tree_type;

	node_pointer _node;


public:
	TreeIter(void *node): _node(static_cast<node_pointer>(node)) {}

	reference operator*() const {
		return *(_node->content);
	}

	TreeIter& operator++() {
		if (!_node->right->is_nil) {
			_node = tree_type::tree_min(_node);
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

	TreeIter& operator--() {
		if (!_node->left->is_nil) {
			_node = tree_type::tree_max(_node);
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
};


#endif
