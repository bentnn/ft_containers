#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "../utils/pair.hpp"
#include "../utils/iterator_traits.hpp"
#include "../utils/remove_const.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../utils/lexicographical_compare.hpp"

template< class Content, class Compare = std::less<Content>, class Allocator = std::allocator<Content> >
class RBTree {

private:
	template< class Cont >
	struct node {
	public:
		bool is_black;
		bool is_nil;
		Cont *content;
		node *father;
		node *right;
		node *left;

		explicit node(Cont *val = 0): is_black(false),
									  is_nil(false),
									  content(val),
									  father(0),
									  right(0),
									  left(0) {}

		node (node const & src):	is_black(src.is_black), is_nil(src.is_nil), content(src.content), father(src.father), right(src.right), left(src.left) {}
//		node (node const & src) {
//			*this = src;
//		}
		node& operator=(const node& other) {
			this->is_black = other.is_black;
			this->is_nil = other.is_nil;
			this->content = other.content;
			this->father = other.father;
			this->right = other.right;
			this->left = other.left;
			return *this;
		}
		virtual ~node(){}
	};

private:

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

		TreeIter(const TreeIter<typename ft::remove_const<value_type>::type > & other) {
			*this = other;
		}

		TreeIter& operator=(const TreeIter<typename ft::remove_const<value_type>::type>& other) {
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

public:
	typedef Allocator allocator_type;
	typedef Content value_type;
	typedef typename allocator_type::pointer con_pointer;
	typedef typename allocator_type::const_pointer const_con_pointer;
	typedef Compare value_compare;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef typename Allocator::template rebind<node<Content> >::other node_allocator;
	typedef typename node_allocator::pointer node_pointer;
	typedef TreeIter<Content> iterator;
	typedef TreeIter<const Content> const_iterator;
	typedef ft::reverse_iterator<iterator> reverse_iterator;
	typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

private:

	node_pointer _root;
	allocator_type _con_alloc;
	node_allocator _node_alloc;
	value_compare _cmp;
	size_type _size;
	node_pointer _nil;
	node_pointer _header;

	bool is_nil(node_pointer node) const {
		return node == _nil || node == _header;
	}

	node_pointer tree_min(node_pointer n) const {
		while (n->left != _nil)
			n = n->left;
		return n;
	}

	node_pointer tree_max(node_pointer n) const {
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

	node_pointer insert_into_tree(node_pointer new_node, node_pointer where) {
		if (_root == _header)
			_root = new_node;
		else
			insert_to_node(where, new_node);
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

	node_pointer search(const value_type &value, node_pointer node) const {
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
	// constructors and destructor

	RBTree(const value_compare& comp, const allocator_type& a = allocator_type()):
			_root(0), _con_alloc(a), _node_alloc(node_allocator()), _cmp(comp), _size(0){
		create_nil_and_header();
		_root = _header;
	}

	RBTree() : _root(0), _con_alloc(allocator_type()), _node_alloc(node_allocator()), _cmp(value_compare()), _size(0) {
		create_nil_and_header();
		_root = _header;
	}

	template<class InputIt>
	RBTree(typename ft::enable_if< !ft::is_integral<InputIt>::value, InputIt >::type first, InputIt last,
		   const value_compare& comp, const allocator_type& alloc = allocator_type()):	_con_alloc(alloc),
		   																				_node_alloc(node_allocator()),
																						_cmp(comp), _size(0) {
		create_nil_and_header();
		_root = _header;
		for ( ; first != last; ++first)
			insert(*first);
	}

	RBTree( const RBTree& other ): _root(0), _cmp(other._cmp) {
		*this = other;
	}

	~RBTree() {
		clear_node(_root);
		_con_alloc.destroy(_header->content);
		_con_alloc.deallocate(_header->content, 1);
		_node_alloc.deallocate(_nil, 1);
		_node_alloc.deallocate(_header, 1);
	}

	// operators

	RBTree& operator=( const RBTree& other ) {
		if (this == &other)
			return *this;
		this->_node_alloc = other._node_alloc;
		this->_con_alloc = other._con_alloc;
		this->_cmp = other._cmp;
		if (this->_root == NULL)
			create_nil_and_header();
		else
            clear_node(_root);
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

	value_compare value_comp() const {
		return _cmp;
	}

	// insert

	ft::pair<iterator, bool> insert(const value_type &value) {
		node_pointer find_res = search(value, _root);
		if (find_res)
			return ft::pair<iterator, bool>(iterator(find_res), false);
		node_pointer new_node = _node_alloc.allocate(1);
		_node_alloc.construct(new_node, node<value_type>(create_content(value)));
		new_node->left = _nil;
		new_node->right = _nil;
		insert_into_tree(new_node, _root);
		ft::pair<iterator, bool> res(iterator(new_node), true);
		insert_fuxup(new_node);
		_size++;
		new_node = tree_max(_root);
		new_node->right = _header;
		_header->father = new_node;
		return res;
	}

	iterator insert (iterator position, const value_type& value) {
		node_pointer new_node = search(value, _root);
		if (new_node)
			return iterator(new_node);
		new_node = _node_alloc.allocate(1);
		_node_alloc.construct(new_node, node<value_type>(create_content(value)));
		new_node->left = _nil;
		new_node->right = _nil;
		if (position == begin()) {
			if (position != end() && _cmp(value, *position))
				insert_into_tree(new_node, tree_min(_root));
			else
				insert_into_tree(new_node, _root);
		}
		else if (position == end()) {
			if (position != begin() && _cmp(*(--position), value))
				insert_into_tree(new_node, _header->father);
			else
				insert_into_tree(new_node, _root);
		}
		else
			insert_into_tree(new_node, _root);
		insert_fuxup(new_node);
		_size++;
		node_pointer max_of_tree = tree_max(_root);
		max_of_tree->right = _header;
		_header->father = max_of_tree;
		return iterator(new_node);
	}

	template<class InputIt>
	void insert(typename ft::enable_if< !ft::is_integral<InputIt>::value, InputIt >::type first,
				InputIt last) {
		for (; first != last; ++first)
			insert(*first);
	}

	// erase

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

	size_type erase(const value_type& value) {
		node_pointer find_res = search(value, _root);
		if (find_res)
			erase(iterator(find_res));
		return (find_res != NULL);
	}

	void erase(iterator first, iterator last) {
		while (first != last)
			erase(first++);
	}

	//iterators

	iterator begin() {
		return (iterator(_size == 0 ? _header : iterator(tree_min(_root))));
	}

	const_iterator begin() const {
		return (const_iterator(_size == 0 ? _header : const_iterator(tree_min(_root))));
	}

	iterator end() {
		return (iterator(_header));
	}

	const_iterator end() const {
		return (const_iterator(_header));
	}

	reverse_iterator rbegin() {
		return reverse_iterator(end());
	}

	const_reverse_iterator rbegin() const {
		return const_reverse_iterator(end());
	}

	reverse_iterator rend() {
		return reverse_iterator(begin());
	}

	const_reverse_iterator rend() const {
		return const_reverse_iterator(begin());
	}

	// basic functions

	iterator find(const value_type& value) {
		node_pointer find_res = search(value, _root);
		return (find_res == NULL ? end() : iterator(find_res));
	}

	const_iterator find(const value_type& value) const {
		node_pointer find_res = search(value, _root);
		return (find_res == NULL ? end() : const_iterator(find_res));
	}

	size_type count(const value_type& value) const {
		return (find(value) != end());
	}

	void clear() {
		clear_node(_root);
		_root = _header;
		_header->father = NULL;
		_size = 0;
	}

	void swap(RBTree &other) {
//		std::swap(this->_root, other._root);
//		std::swap(this->_nil, other._nil);
//		std::swap(this->_header, other._header);
//		std::swap(this->_size, other._size);
//		std::swap(this->_node_alloc, other._node_alloc);
//		std::swap(this->_con_alloc, other._con_alloc);
//		std::swap(this->_cmp, other._cmp);
		std::swap(other, *this);
	}

	// bounds

	iterator lower_bound(const value_type& value) {
		iterator last = end();
		for (iterator first = begin(); first != last; ++first) {
			if (!_cmp(*first, value))
				return first;
		}
		return last;
	}

	const_iterator lower_bound(const value_type& value) const {
		const_iterator last = end();
		for (const_iterator first = begin(); first != last; ++first) {
			if (!_cmp(*first, value))
				return first;
		}
		return last;
	}

	iterator upper_bound(const value_type& value) {
		iterator last = end();
		for (iterator first = begin(); first != last; ++first) {
			if (_cmp(value, *first))
				return first;
		}
		return last;
	}

	const_iterator upper_bound(const value_type& value) const {
		const_iterator last = end();
		for (const_iterator first = begin(); first != last; ++first) {
			if (_cmp(value, *first))
				return first;
		}
		return last;
	}

	ft::pair<iterator,iterator> equal_range(const value_type& value) {
		return ft::make_pair(lower_bound(value), upper_bound(value));
	}

	ft::pair<const_iterator,const_iterator> equal_range(const value_type& value) const {
		return ft::make_pair(lower_bound(value), upper_bound(value));
	}

	template<typename A, typename B>
	friend bool operator==(const RBTree::template TreeIter<A> & lhs, const RBTree::template TreeIter<B> & rhs) {
		return lhs.node() == rhs.node();
	}

	template<typename A, typename B>
	friend bool operator!=(const RBTree::template TreeIter<A> & lhs, const RBTree::template TreeIter<B> & rhs) {
		return lhs.node() != rhs.node();
	}
};

template<class Content, class Compare, class Alloc>
bool operator==(const RBTree<Content, Compare, Alloc>& lhs,
				const RBTree<Content, Compare, Alloc>& rhs) {
	if (lhs.size() != rhs.size())
		return false;
	typename RBTree<Content, Compare, Alloc>::const_iterator first1 = lhs.begin();
	typename RBTree<Content, Compare, Alloc>::const_iterator first2 = rhs.begin();
	for ( ; first1 != lhs.end(); ++first1, ++first2) {
		if (*first1 != *first2)
			return false;
	}
	return true;
}

template<class Content, class Compare, class Alloc>
bool operator!=(const RBTree<Content, Compare, Alloc>& lhs,
				const RBTree<Content, Compare, Alloc>& rhs) {
	return !(lhs == rhs);
}

template<class Content, class Compare, class Alloc>
bool operator<(const RBTree<Content, Compare, Alloc>& lhs,
				const RBTree<Content, Compare, Alloc>& rhs) {
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template<class Content, class Compare, class Alloc>
bool operator>(const RBTree<Content, Compare, Alloc>& lhs,
			   const RBTree<Content, Compare, Alloc>& rhs) {
	return rhs < lhs;
}

template<class Content, class Compare, class Alloc>
bool operator<=(const RBTree<Content, Compare, Alloc>& lhs,
			   const RBTree<Content, Compare, Alloc>& rhs) {
	return !(lhs > rhs);
}

template<class Content, class Compare, class Alloc>
bool operator>=(const RBTree<Content, Compare, Alloc>& lhs,
				const RBTree<Content, Compare, Alloc>& rhs) {
	return !(lhs < rhs);
}

template<class Content, class Compare, class Alloc>
void swap(const RBTree<Content, Compare, Alloc>& lhs,
		  const RBTree<Content, Compare, Alloc>& rhs) {
	lhs.swap(rhs);
}


#endif
