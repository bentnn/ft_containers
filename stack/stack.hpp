#ifndef STACK_HPP
#define STACK_HPP

#include "../vector/vector.hpp"
#include <iostream>
#include <vector>

namespace ft {

	template<class T, class Container = ft::vector<T> >
	class stack {
	public:
		// def
		typedef Container container_type;
		typedef T value_type;
		typedef typename Container::size_type size_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;

	protected:
		container_type _container;

	public:
		explicit stack(const container_type& cont = container_type()): _container(cont) {}

		stack(const stack& other): _container(other._container) {}

		stack& operator=( const stack& other ) {
			this->_container = other._container;
			return *this;
		}

		reference top() {
			return this->_container.back();
		}

		const_reference top() const {
			return this->_container.back();
		}

		bool empty() const {
			return this->_container.empty();
		}

		size_type size() const {
			return this->_container.size();
		}

		void push( const value_type& value ) {
			this->_container.push_back(value);
		}

		void pop() {
			this->_container.pop_back();
		}

		template< class A, class Cont >
		friend bool operator==( const stack<A,Cont>& lhs, const stack<A,Cont>& rhs );

		template< class A, class Cont >
		friend bool operator!=( const stack<A,Cont>& lhs, const stack<A,Cont>& rhs );

		template< class A, class Cont >
		friend bool operator<( const stack<A,Cont>& lhs, const stack<A,Cont>& rhs );

		template< class A, class Cont >
		friend bool operator<=( const stack<A,Cont>& lhs, const stack<A,Cont>& rhs );

		template< class A, class Cont >
		friend bool operator>( const stack<A,Cont>& lhs, const stack<A,Cont>& rhs );

		template< class A, class Cont >
		friend bool operator>=( const stack<A,Cont>& lhs, const stack<A,Cont>& rhs );
	};

	template< class A, class Cont >
	bool operator==( const ft::stack<A,Cont>& lhs, const ft::stack<A,Cont>& rhs ) {
		return lhs._container == rhs._container;
	}

	template< class A, class Cont >
	bool operator!=( const ft::stack<A,Cont>& lhs, const ft::stack<A,Cont>& rhs ) {
		return lhs._container != rhs._container;
	}

	template< class A, class Cont >
	bool operator<( const ft::stack<A,Cont>& lhs, const ft::stack<A,Cont>& rhs ) {
		return lhs._container < rhs._container;
	}

	template< class A, class Cont >
	bool operator<=( const ft::stack<A,Cont>& lhs, const ft::stack<A,Cont>& rhs ) {
		return lhs._container <= rhs._container;
	}

	template< class A, class Cont >
	bool operator>( const ft::stack<A,Cont>& lhs, const ft::stack<A,Cont>& rhs ) {
		return lhs._container > rhs._container;
	}

	template< class A, class Cont >
	bool operator>=( const stack<A,Cont>& lhs, const stack<A,Cont>& rhs ) {
		return lhs._container >= rhs._container;
	}
}

#endif
