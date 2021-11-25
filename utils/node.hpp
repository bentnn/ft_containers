#ifndef NODE_HPP
#define NODE_HPP

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

	node (node const & src):	is_black(src.is_black),
								is_nil(src.is_nil),
								content(src.content),
								father(src.father),
								right(src.right),
								left(src.left) {}

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

#endif
