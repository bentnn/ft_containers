#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "node.hpp"

template< class Content, class Compare = std::less<Content>, class Allocator = std::allocator<Content> > >
class RBTree {
public:
	typedef Allocator allocator_type;
	typedef Content content_type;
	typedef typename Allocator::template rebind<node<Content> >::other node_allocator;
	typedef node_allocator::pointer node_pointer;
	typedef Allocator::const_pointer node_const_pointer;
	typedef Compare key_compare;

private:
	node_pointer _root;
	allocator_type _con_alloc;
	node_allocator _node_alloc;
	key_compare _cmp;

public:
	RBTree(const allocator_type& alloc = allocator_type()):
					_root(0),
					_con_alloc(alloc),
					_node_alloc(node_allocator()),
					_cmp(key_compare()){}

	~RBTree() {

	}
};
#endif
