/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:45:02 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/14 11:39:57 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP
# include "ft_type_traits.hpp"
# include <iterator>
# include <stddef.h>
#include "reverse_iterator.hpp" 
/*: Iterators are used by algorithms to move through containers. T*/
namespace ft
{
	
template <class T>
class iterator
{
  public:
	typedef T iterator_type;
	typedef typename ft::iterator_traits<T>::value_type value_type;
	typedef typename ft::iterator_traits<T>::pointer pointer;
	typedef typename ft::iterator_traits<T>::reference reference;
	typedef ptrdiff_t difference_type;
	typedef std::random_access_iterator_tag iterator_category;

  private:
	iterator_type ptr;

  public:
	iterator()
		: ptr()
	{
		// ptr = NULL;
	}

	explicit iterator(pointer vec)
	{
		ptr = vec;
	}

	iterator(const iterator &rhs) // copy
	{
		// ptr = rhs.ptr;
		*this = rhs;
	}
	iterator &operator=(const iterator &rhs)
	{
		if (this == &rhs)
			return (*this);
		this->ptr = rhs.ptr;
		return (*this);
	}
	~iterator()
	{
	}

	iterator_type base() const

	{
		return (ptr);
	}

	reference operator*() const
	{
		return (reference(*ptr));
	}

	pointer operator->() const
	{
		return (&ptr);
	}

	/*
				Pre-increment, called for ++ptr
			*/
	iterator &operator++()
	{
		++ptr;
		return (*this);
	}
	/*
					Post-increment
			*/
	iterator operator++(int)
	{
		iterator tmp = *this;
		++ptr;
		return (tmp);
	}
	/*
				Pre-decrement, called for --ptr
			*/
	iterator &operator--()
	{
		--ptr;
		return (*this);
	}
	/*
					Post-decrement
			*/
	iterator operator--(int)
	{
		iterator tmp(*this);
		--(*this);
		return (tmp);
	}
	reference operator[](difference_type n) const
	{
		return (ptr[n]);
	}

	iterator operator+(difference_type n) const // add const so rend() works ?!
	{
		return (iterator(ptr + n));
	}
	iterator operator-(difference_type n) const // not working
	{
		return (iterator(ptr - n));
	}
	// iterator operator-(difference_type n) const // not working
	// {
	// 	return (iterator(ptr - n));
	// }

	iterator operator+=(difference_type n)
	{
		ptr = ptr + n;
		return (*this);
	}
	iterator &operator-=(difference_type n)
	{
		ptr = ptr - n;
		return (*this);
	}
};
template <class iterator>
bool operator==(iterator const &x, iterator const &y)
{
	return (x.base() == y.base());
}
template <class iterator>
bool operator!=(iterator const &x, iterator const &y)
{
	return (x.base() != y.base());
}
template <class iterator>
bool operator<(iterator const &x, iterator const &y)
{
	return (x.base() < y.base());
}

template <class iterator>
bool operator<=(iterator const &x, iterator const &y)
{
	return (x.base() <= y.base());
}
template <class iterator>
bool operator>(iterator const &x, iterator const &y)
{
	return (x.base() > y.base());
}
template <class iterator>
bool operator>=(iterator const &x, iterator const &y)
{
	return (x.base() >= y.base());
}



} // namespace ft

#endif
