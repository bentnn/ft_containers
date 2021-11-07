#ifndef NODE_HPP
#define NODE_HPP

#include "pair.hpp"


template< class Content >
struct node {
public:
	bool is_black;
	Content *content;
	node *father;
	node *right;
	node *left;

	explicit node(Content *val = 0):	is_black(false),
										content(val),
										father(0),
										right(0),
									  	left(0) {}

	node& operator=(const node& other) {
		this->is_black = other.is_black;
		this->content = other.content;
		this->father = other.father;
		this->right = other.right;
		this->left = other.left;
		return *this;
	}
};


#endif
