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
	node_pointer _nil;
	node_pointer _header;

	void tree_min(node_pointer n) {
		while (n->left != _nil)
			n = n->left;
		return n;
	}

	void tree_max(node_pointer n) {
		while (n->right != _nil)
			n = n->right;
		return n;
	}

	void clear_node(node_pointer node) {
		if (node && node != _nil) {
			clear_node(node->right);
			clear_node(node->left);
			_con_alloc.destroy(node->content);
			_con_alloc.deallocate(node->content, 1);
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

	void transplant(node_pointer where, node_pointer what) {
		if (where == _root)
			_root = what;
		else if (where == where->father->left)
			where->father->left = what;
		else
			where->father->right = what;
		what->father = where->father;
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

	node_pointer insert_to_node(node_pointer root, node_pointer new_node) {
		if (_cmp(*new_node->content, *root->content)) {
			if (root->left != _nil)
				return insert_to_node(root->left, new_node);
			root->left = new_node;
		}
		else {
			if (root->right != _nil)
				return insert_to_node(root->right, new_node);
			root->right = new_node;
		}
		new_node->father = root;
		return new_node;
	}

	node_pointer insert_into_tree(node_pointer new_node) {
		if (!_root)
			_root = new_node;
		else
			insert_to_node(_root, new_node);
		return new_node;
	}

	void insert_fuxup(node_pointer cur_node) {
		if (cur_node != _root && cur_node->father != _root) {
			while (!cur_node->father->is_black) {
				if (cur_node->father == cur_node->father->father->left) {
					node_pointer uncle = cur_node->father->father->right;
					if (!uncle->is_black) {
						cur_node->father->is_black = true;
						uncle->is_black = true;
						cur_node->father->father->is_black = false;
						cur_node = cur_node->father->father;
					}
					else {
						if (cur_node == cur_node->father->right) {
							cur_node = cur_node->father;
							left_rotate(cur_node);
						}
						cur_node->father->is_black = true;
						cur_node->father->father->is_black = false;
						right_rotate(cur_node->father->father);
					}
				}
				else {
					node_pointer uncle = cur_node->father->father->left;
					if (!uncle->is_black) {
						cur_node->father->is_black = true;
						uncle->is_black = true;
						cur_node->father->father->is_black = false;
						cur_node = cur_node->father->father;
					}
					else {
						if (cur_node == cur_node->father->left) {
							cur_node = cur_node->father;
							right_rotate(cur_node);
						}
						cur_node->father->is_black = true;
						cur_node->father->father->is_black = false;
						left_rotate(cur_node->father->father);
					}
				}
			}
		}
		_root->is_black = true;
	}

public:
	// constructors and destructors

	RBTree(const Compare& comp, const allocator_type& a = allocator_type()):
	_root(0), _con_alloc(a), _node_alloc(node_allocator()), _cmp(comp), _size(0){
		_nil = _node_alloc.allocate(1);
		_node_alloc.construct(_nil, node<Content>());
		_nil->is_black = true;
		_header = _node_alloc.allocate(1);
		_node_alloc.construct(_header, node<Content>());
	}

	RBTree() : _root(0), _con_alloc(allocator_type()), _node_alloc(node_allocator()), _cmp(key_compare()), _size(0) {
		_nil = _node_alloc.allocate(1);
		_node_alloc.construct(_nil, node<Content>());
		_nil->is_black = true;
		_header = _node_alloc.allocate(1);
		_node_alloc.construct(_header, node<Content>());
	}

//	RBTree(const allocator_type& alloc = allocator_type()):
//					_root(0),
//					_con_alloc(alloc),
//					_node_alloc(node_allocator()),
//					_cmp(key_compare()) {}


	~RBTree() {
		clear_node(_root);
		_node_alloc.deallocate(_nil, 1);
		_node_alloc.deallocate(_header, 1);
	}

	// getters

	allocator_type get_allocator() const {
		return _con_alloc;
	}

	size_type size() const {
		return _size;
	}

	void insert(content_type *value) {
		node_pointer new_node = _node_alloc.allocate(1);
		_node_alloc.construct(new_node, node<content_type>(value));
		new_node->left = _nil;
		new_node->right = _nil;
		insert_into_tree(new_node);
		insert_fuxup(new_node);
		_size++;
	}

	void erase(content_type &value) {

	}
};

#endif
