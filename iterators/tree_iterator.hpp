#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

#include "../map/RBTree.hpp"

namespace ft {
	template<typename T>
	class TreeIter {
	public:
		typedef ptrdiff_t difference_type;
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef node<T>* node_pointer;

	private:
		node_pointer _node;

	public:
		TreeIter(node_pointer *node): _node(node) {}

		TreeIter& operator++() {

			return *this;
		}
	};
}

#endif
