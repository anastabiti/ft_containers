/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:59:18 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/15 09:22:34 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_type_traits.hpp"
# include <iterator>
# include "iterator.hpp"
# include <stddef.h>



namespace ft
{
    
template <class Iterator>
class reverse_iterator 
{
  protected:
	Iterator current;

  public:
	typedef Iterator iterator_type;
	typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
	typedef typename ft::iterator_traits<Iterator>::reference reference;
	typedef typename ft::iterator_traits<Iterator>::pointer pointer;
	reverse_iterator()
		: current()
	{
	}
	explicit reverse_iterator(Iterator x)
	{
		current = x;
	}

	reverse_iterator &operator=(const reverse_iterator &__x)
	{
		current = __x.current;
		return (*this);
	}

	iterator_type base() const
	{
		return (current);
	}
	reference operator*() const
	{
		Iterator __tmp = current;
		return (*--__tmp);
	}

	pointer operator->() const
	{
		return (&(this->operator*()));
	}

	reverse_iterator &operator++()
	{
		--current;
		return (*this);
	}
	reverse_iterator operator++(int)
	{
		reverse_iterator tmp(*this);
		--current;
		return (tmp);
	}
	reverse_iterator &operator--()
	{
		++current;
		return (*this);
	}
	reverse_iterator operator--(int)
	{
		reverse_iterator tmp(*this);

		++current;
		return (tmp);
	}
	reverse_iterator operator+(difference_type n) const
	{
		return (reverse_iterator(current - n));
	}
	reverse_iterator &operator+=(difference_type n)
	{
		current = current - n;
		return (*this);
	}
	reverse_iterator &operator-=(difference_type n)
	{
		current = current + n;
		return (*this);
	}

	reference operator[](difference_type n) const
	{
		// return (*(*this + n));
		return (current[n]); // will call iterator  operator[]
	}
	reverse_iterator operator-(difference_type n) const
	{
		return (reverse_iterator(current + n));
	}
};
/* relational operators */
template <typename Iterator> // change typename to class
bool operator==(const reverse_iterator<Iterator> &lhs,
				const reverse_iterator<Iterator> &rhs)
{
	return (lhs.base() == rhs.base());
}
template <typename Iterator>
bool operator!=(const reverse_iterator<Iterator> &lhs,
				const reverse_iterator<Iterator> &rhs)
{
	return (lhs.base() != rhs.base());
}
template <typename Iterator>
bool operator<(const reverse_iterator<Iterator> &lhs,
				const reverse_iterator<Iterator> &rhs)
{
	return (lhs.base() > rhs.base()); // reverse here
}
template <typename Iterator>
bool operator<=(const reverse_iterator<Iterator> &lhs,
				const reverse_iterator<Iterator> &rhs)
{
	return (lhs.base() >= rhs.base()); // reverse here
}
template <typename Iterator>
bool operator>(const reverse_iterator<Iterator> &lhs,
				const reverse_iterator<Iterator> &rhs)
{
	return (lhs.base() < rhs.base());
	// reverse here
}
template <typename Iterator>
bool operator>=(const reverse_iterator<Iterator> &lhs,
				const reverse_iterator<Iterator> &rhs)
{
	return (lhs.base() <= rhs.base());
	// reverse here
}

template <class Iterator>
typename reverse_iterator<Iterator>::difference_type operator-( const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
{
	return x.base() - y.base();
}


template <class Iterator>
reverse_iterator<Iterator> operator+( typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& x)
{
	return x.base() - n;
	
}

    
}
