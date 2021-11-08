#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

namespace ft {

	template<typename It>
	class reverse_iterator {
	public:
		typedef It iterator_type;
		typedef typename iterator_type::value_type value_type;
		typedef typename iterator_type::pointer pointer;
		typedef typename iterator_type::reference reference;
		typedef typename iterator_type::difference_type difference_type;
		typedef typename iterator_type::iterator_category iterator_category;

	private:
		iterator_type _it;

	public:
		reverse_iterator(): _it() {}

		explicit reverse_iterator(iterator_type x): _it(x) {}

		template< class U >
		reverse_iterator( const reverse_iterator<U>& other ): _it(other.it) {}

		template< class U >
		reverse_iterator& operator=( const reverse_iterator<U>& other ) {
			this->it = other.it;
			return *this;
		}

		iterator_type base() const {
			return _it;
		}

		reference operator*() const {
			iterator_type temp = _it;
			return *--temp;
//			return *(_it - 1);
		}

		pointer operator->() const {
			iterator_type temp = _it;
			return &(*(--temp));
//			return _it.operator->();
		}

		reference operator[]( difference_type n ) const {
			return _it.base()[-n-1];
		}


		reverse_iterator& operator++() {
			_it--;
			return *this;
		}

		reverse_iterator& operator--() {
			_it++;
			return *this;
		}

		reverse_iterator operator++( int ) {
			reverse_iterator<iterator_type> temp = *this;
			_it--;
			return temp;
		}

		reverse_iterator operator--( int ) {
			reverse_iterator<iterator_type> temp = *this;
			_it++;
			return temp;
		}

		reverse_iterator operator+( difference_type n ) const {
			iterator_type temp = _it;
			temp -= n;
			return reverse_iterator(temp);
		}

		reverse_iterator operator-( difference_type n ) const {
			iterator_type temp = _it;
			temp += n;
			return reverse_iterator(temp);
		}

		reverse_iterator& operator+=( difference_type n ) {
			_it -= n;
			return *this;
		}

		reverse_iterator& operator-=( difference_type n ) {
			_it += n;
			return *this;
		}
	};

	template< class Iterator1, class Iterator2 >
	bool operator==( const reverse_iterator<Iterator1>& lhs,
					 const reverse_iterator<Iterator2>& rhs ) {
		return lhs.base() == rhs.base();
	}

	template< class Iterator1, class Iterator2 >
	bool operator!=( const reverse_iterator<Iterator1>& lhs,
					 const reverse_iterator<Iterator2>& rhs ) {
		return lhs.base() != rhs.base();
	}

	template< class Iterator1, class Iterator2 >
	bool operator>( const reverse_iterator<Iterator1>& lhs,
					 const reverse_iterator<Iterator2>& rhs ) {
		return lhs.base() > rhs.base();
	}

	template< class Iterator1, class Iterator2 >
	bool operator<( const reverse_iterator<Iterator1>& lhs,
					 const reverse_iterator<Iterator2>& rhs ) {
		return lhs.base() < rhs.base();
	}

	template< class Iterator1, class Iterator2 >
	bool operator>=( const reverse_iterator<Iterator1>& lhs,
					 const reverse_iterator<Iterator2>& rhs ) {
		return lhs.base() >= rhs.base();
	}

	template< class Iterator1, class Iterator2 >
	bool operator<=( const reverse_iterator<Iterator1>& lhs,
					 const reverse_iterator<Iterator2>& rhs ) {
		return lhs.base() <= rhs.base();
	}

	template< class Iter >
	reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it) {
		return reverse_iterator<Iter>(it.base() - n);
	}

	template< class Iterator >
	typename reverse_iterator<Iterator>::difference_type operator-( const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs ) {
		return lhs.base() - rhs.base();
	}
}

#endif
