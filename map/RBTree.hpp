#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "node.hpp"
#include "../map/pair.hpp"
#include "../iterators/tree_iterator.hpp"

template<typename T> class TreeIter;

template< class Content, class Compare = std::less<Content>, class Allocator = std::allocator<Content> >
class RBTree {
public:
	typedef Allocator allocator_type;
	typedef Content value_type;
	typedef typename Allocator::template rebind<node<Content> >::other node_allocator;
	typedef typename node_allocator::pointer node_pointer;
	typedef typename allocator_type::pointer con_pointer;
	typedef typename allocator_type::const_pointer const_con_pointer;
	typedef Compare value_compare;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef TreeIter<Content> iterator;

private:
	node_pointer _root;
	allocator_type _con_alloc;
	node_allocator _node_alloc;
	value_compare _cmp;
	size_type _size;
	node_pointer _nil;
	node_pointer _header;

	bool is_nil(node_pointer node) {
		return node == _nil || node == _header;
	}

	node_pointer tree_min(node_pointer n) {
		while (n->left != _nil)
			n = n->left;
		return n;
	}

	node_pointer tree_max(node_pointer n) {
		while (!is_nil(n->right))
			n = n->right;
		return n;
	}

	void free_node(node_pointer node) {
		_con_alloc.destroy(node->content);
		_con_alloc.deallocate(node->content, 1);
		_node_alloc.deallocate(node, 1);
	}

	void clear_node(node_pointer node) {
		if (node && !is_nil(node)) {
			clear_node(node->right);
			clear_node(node->left);
			free_node(node);
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

	con_pointer create_content(const value_type &value) {
		con_pointer new_con = _con_alloc.allocate(1);
		_con_alloc.construct(new_con, value);
		return new_con;
	}

	void right_rotate(node_pointer top) {
		node_pointer y = top->left;
		top->left = y->right;
		if (!is_nil(y->right))
			y->right->father = top;
		y->father = top->father;
		if (top->father == NULL)
			_root = y;
		else if (top == top->father->left)
			top->father->left = y;
		else
			top->father->right = y;
		y->right = top;
		top->father = y;
	}

	void left_rotate(node_pointer top) {
		node_pointer y = top->right;
		top->right = y->left;
		if (!is_nil(y->left))
			y->left->father = top;
		y->father = top->father;
		if (top->father == NULL)
			_root = y;
		else if (top == top->father->left)
			top->father->left = y;
		else
			top->father->right = y;
		y->left = top;
		top->father = y;
	}

	node_pointer insert_to_node(node_pointer root, node_pointer new_node) {
		if (_cmp(*new_node->content, *root->content)) {
			if (!is_nil(root->left))
				return insert_to_node(root->left, new_node);
			root->left = new_node;
		}
		else {
			if (!is_nil(root->right))
				return insert_to_node(root->right, new_node);
			root->right = new_node;
		}
		new_node->father = root;
		return new_node;
	}

	node_pointer insert_into_tree(node_pointer new_node) {
		if (_root == _header)
			_root = new_node;
		else
			insert_to_node(_root, new_node);
		return new_node;
	}

	void insert_fuxup(node_pointer cur_node) {
		if (cur_node != _root && cur_node->father != _root) {
			while (cur_node != _root && !cur_node->father->is_black) {
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

	void erase_fixup(node_pointer x) {
		node_pointer w; //brother
		while (x != _root && x->is_black) {
			if (x == x->father->left) {
				w = x->father->right;
				if (!w->is_black) { // 1 case
					w->is_black = true;
					x->father->is_black = false;
					left_rotate(x->father);
					w = x->father->right;
				}
				if (w->left->is_black && w->right->is_black) { // 2 case
					w->is_black = false;
					x = x->father;
				}
				else {
					if (w->right->is_black) { // 3 case
						w->left->is_black = true;
						w->is_black = false;
						right_rotate(w);
						w = x->father->right;
					}
					// 4 case
					w->is_black = x->father->is_black;
					x->father->is_black = true;
					w->right->is_black = true;
					left_rotate(x->father);
					x = _root;
				}
			}
			else {
				w = x->father->left;
				if (!w->is_black) { // 1 case
					w->is_black = true;
					x->father->is_black = false;
					right_rotate(x->father);
					w = x->father->left;
				}
				if (w->right->is_black && w->left->is_black) { // 2 case
					w->is_black = false;
					x = x->father;
				}
				else {
					if (w->left->is_black) { // 3 case
						w->right->is_black = true;
						w->is_black = false;
						left_rotate(w);
						w = x->father->left;
					}
					// 4 case
					w->is_black = x->father->is_black;
					x->father->is_black = true;
					w->left->is_black = true;
					right_rotate(x->father);
					x = _root;
				}
			}
		}
		x->is_black = true;
	}

	void create_nil_and_header() {
		_nil = _node_alloc.allocate(1);
		_node_alloc.construct(_nil, node<Content>());
		_nil->is_black = true;
		_nil->is_nil = true;
		_header = _node_alloc.allocate(1);
		_node_alloc.construct(_header, node<Content>());
		_header->content = _con_alloc.allocate(1);
		_con_alloc.construct(_header->content, Content());
		_header->is_black = true;
	}

	node_pointer copy_node(node_pointer other) {
		node_pointer new_node = _node_alloc.allocate(1);
		_node_alloc.construct(new_node, node<Content>());
		new_node->is_black = other->is_black;
		new_node->is_nil = other->is_nil;
		if (other->content) {
			new_node->content = _con_alloc.allocate(1);
			_con_alloc.construct(new_node->content, *other->content);
		}
		return new_node;
	}

	node_pointer search(const value_type &value, node_pointer node) {
		if (!node || is_nil(node))
			return NULL;
		if (_cmp(value, *node->content))
			return search(value, node->left);
		if (_cmp(*node->content, value))
			return search(value, node->right);
		return node;
	}

	void copy_child(node_pointer my_node, node_pointer other) {
		if (other->left->is_nil)
			my_node->left = _nil;
		else {
			my_node->left = copy_node(other->left);
			my_node->left->father = my_node;
			copy_child(my_node->left, other->left);
		}
		if (other->right->is_nil)
			my_node->right = _nil;
		else if (other->right->right == NULL) {
			my_node->right = _header;
			_header->father = my_node;
		}
		else {
			my_node->right = copy_node(other->right);
			my_node->right->father = my_node;
			copy_child(my_node->right, other->right);
		}
	}

public:
	// constructors and destructors

	RBTree(const Compare& comp, const allocator_type& a = allocator_type()):
			_root(0), _con_alloc(a), _node_alloc(node_allocator()), _cmp(comp), _size(0){
		create_nil_and_header();
		_root = _header;
	}

	RBTree() : _root(0), _con_alloc(allocator_type()), _node_alloc(node_allocator()), _cmp(value_compare()), _size(0) {
		create_nil_and_header();
		_root = _header;
	}

//	RBTree(const allocator_type& alloc = allocator_type()):
//					_root(0),
//					_con_alloc(alloc),
//					_node_alloc(node_allocator()),
//					_cmp(value_compare()) {}

	RBTree( const RBTree& other ): _cmp(other._cmp) {
		*this = other;
	}

	~RBTree() {
		clear_node(_root);
		_con_alloc.destroy(_header->content);
		_con_alloc.deallocate(_header->content, 1);
		_node_alloc.deallocate(_nil, 1);
		_node_alloc.deallocate(_header, 1);
	}

	RBTree& operator=( const RBTree& other ) {
		this->_node_alloc = other._node_alloc;
		this->_con_alloc = other._con_alloc;
		this->_cmp = other._cmp;
		clear_node(_root);
		if (this->_nil == NULL)
			create_nil_and_header();
		if (other._size == 0)
			this->_root = this->_header;
		else {
			this->_root = copy_node(other._root);
			copy_child(this->_root, other._root);
		}
		this->_size = other._size;
		return *this;
	}

	// getters

	allocator_type get_allocator() const {
		return _con_alloc;
	}

	size_type size() const {
		return _size;
	}

	size_type max_size() const {
		return _con_alloc.max_size();
	}

	bool empty() const {
		return _size == 0;
	}

	ft::pair<iterator, bool> insert(const value_type &value) {
		node_pointer find_res = search(value, _root);
		if (find_res)
			return ft::pair<iterator, bool>(iterator(find_res), false);
		node_pointer new_node = _node_alloc.allocate(1);
		_node_alloc.construct(new_node, node<value_type>(create_content(value)));
		new_node->left = _nil;
		new_node->right = _nil;
		insert_into_tree(new_node);
		ft::pair<iterator, bool> res(iterator(new_node), true);
		insert_fuxup(new_node);
		_size++;
		new_node = tree_max(_root);
		new_node->right = _header;
		_header->father = new_node;
		return res;
	}

	void erase(iterator pos) {
		node_pointer y = pos.node(), x, for_free = y;
		bool y_original_is_black = y->is_black;
		if (is_nil(y->left)) {
			x = y->right;
			transplant(y, y->right);
		}
		else if (is_nil(y->right)) {
			x = y->left;
			transplant(y, y->left);
		}
		else {
			node_pointer z = y;
			y = tree_min(z->right);
			y_original_is_black = y->is_black;
			x = y->right;
			if (y->father != z) {
				transplant(y, y->right);
				y->right = z->right;
				y->right->father = y;
			}
			transplant(z, y);
			y->left = z->left;
			y->left->father = y;
			y->is_black = z->is_black;
		}
		free_node(for_free);
		if (y_original_is_black)
			erase_fixup(x);
		_size--;
		_nil->father = NULL;
		if (_size == 0)
			_root = _header;
		else {
			if (_size != 1)
				x = tree_max(_root);
			else
				x = _root;
			x->right = _header;
			_header->father = x;
		}
	}

	iterator begin() {
		return (iterator(tree_min(_root)));
	}

	iterator end() {
		return (iterator(_header));
	}

	iterator find(const value_type& value) {
		node_pointer find_res = search(value, _root);
		return (find_res == NULL ? end() : iterator(find_res));
	}

	void clear() {
		clear_node(_root);
		_root = _header;
		_size = 0;
	}

	void swap(RBTree &other) {
		std::swap(this->_root, other._root);
		std::swap(this->_nil, other._nil);
		std::swap(this->_header, other._header);
		std::swap(this->_size, other._size);
		std::swap(this->_node_alloc, other._node_alloc);
		std::swap(this->_con_alloc, other._con_alloc);
		std::swap(this->_cmp, other._cmp);
	}
};

#endif
