#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "node.hpp"

template< class Content, class Compare = std::less<Content>, class Allocator = std::allocator<Content> >
class RBTree {
public:
	typedef Allocator allocator_type;
	typedef Content content_type;
	typedef typename Allocator::template rebind<node<Content> >::other node_allocator;
	typedef typename node_allocator::pointer node_pointer;
	typedef typename Allocator::const_pointer node_const_pointer;
	typedef Compare key_compare;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;

private:
	node_pointer _root;
	allocator_type _con_alloc;
	node_allocator _node_alloc;
	key_compare _cmp;
	size_type _size;

	void clear_node(node_pointer node) {
		if (node) {
			clear_node(node->right);
			clear_node(node->left);
			_con_alloc.destroy(node->content);
			_con_alloc.deallocate(node->content, 1);
			_node_alloc.destroy(node);
			_node_alloc.deallocate(node, 1);
		}
	}

	void change_child(node_pointer old_child, node_pointer new_child) {
		if (old_child->father) {
			if (old_child->father->right == old_child)
				old_child->father->right = new_child;
			else
				old_child->father->left = new_child;
			new_child->father = old_child->father;
		}
		else {
			_root = new_child;
			new_child->father = NULL;
		}
	}

	void right_rotate(node_pointer top) {
		node_pointer left_right_child = top->left->right;
		top->left->right = top;
		change_child(top, top->left);
		top->father = top->left;
		top->left = left_right_child;
	}

	void left_rotate(node_pointer top) {
		node_pointer right_left_child = top->right->left;
		top->right->left = top;
		change_child(top, top->right);
		top->father = top->right;
		top->right = right_left_child;
	}

public:
	// constructors and destructors

	RBTree(const Compare& comp, const allocator_type& a = allocator_type()):
	_root(0), _con_alloc(a), _node_alloc(node_allocator()), _cmp(comp), _size(0) {}

	RBTree() : _root(0), _con_alloc(allocator_type()), _node_alloc(node_allocator()), _cmp(key_compare()), _size(0) {}

//	RBTree(const allocator_type& alloc = allocator_type()):
//					_root(0),
//					_con_alloc(alloc),
//					_node_alloc(node_allocator()),
//					_cmp(key_compare()) {}


	~RBTree() {
		clear_node(_root);
	}

	// getters

	allocator_type get_allocator() const {
		return _con_alloc;
	}

	size_type size() const {
		return _size;
	}
};

#endif
