/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:45:02 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/11 09:46:59 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include "ft_type_traits.hpp"
#include <iterator>
#include <stddef.h>
/*: Iterators are used by algorithms to move through containers. T*/
namespace ft
{
	/*
				---------------------------- Category tags/Standard iterator tags----------------------------
			It is often desirable for a template function to find out what is the most specific category of its iterator argument,
			so that the function can select the most efficient algorithm at compile time. To facilitate this,
			the
			library introduces category tag classes which are used as compile time tags for algorithm selection. T
		*/

	/* The iterator type defined by an iterator tag of the most specific iterator
			behavior. These are the five iterator tags which represent the five types of

		*/
	// struct	input_iterator_tag{};
	// struct	output_iterator_tag{};
	// struct forward_iterator_tag : public input_iterator_tag{};
	// struct bidirectional_iterator_tag : public forward_iterator_tag{};
	// struct random_access_iterator_tag : public bidirectional_iterator_tag{};

	/* 								iterator_traits
			iterator_traits is a structure that contains basic information on iterators
			that can be used by generic algorithms to determine key attributes of an iterator
			so that the algorithms can use the iterator effectively.
			----------> why iterator_traits is required?
			If the iterator passed to a function is a an iterator rather than a pointer,
				the function can get the information directly from the iterator. If a pointer is passed,
			there is a problem with this technique since a pointer
			will not have a value_type or any of the other attributes associated with an iterator.
			1- It ensures that an iterator provides all type definitions.
			-> you can’t just do something like int*::value_type,
			since pointer don’t have nested types!
		*/

	template <typename Iterator> // the definition of iterator_traits for iterators
	struct iterator_traits
	{
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::iterator_category iterator_category;
	};

	template <typename T>
	struct iterator_traits<T *> // definitions that are appropriate for pointers.
	{
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;
		typedef std::random_access_iterator_tag iterator_category;
	};
	template <typename T>
	struct iterator_traits<const T *> // definitions that are appropriate for pointers.
	{
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	/*template <class Category, class T, class Distance = ptrdiff_t,class Pointer = T *, class Reference = T &>*/
	template <class T>
	class iterator
	{

	public:
		typedef T value_type;
		/*value _type is of type T,the class of objects that the iterator is pointing.*/
		typedef ptrdiff_t difference_type;
		// difference_type has a default value of ptrdiff_t which is used to represent the difference between two iterators.
		typedef T * pointer; // pointer has a default Pointer to type T.
		typedef T & reference;
		// reference has a default Reference to type T.
		typedef std::random_access_iterator_tag iterator_category;

	private:
		pointer ptr;
		
	public:
		iterator()
		{
			ptr = NULL;
		}

		explicit iterator(pointer vec)
		{
			ptr = vec;
		}

		iterator(const iterator &rhs) // copy
		{
			ptr = rhs.ptr;
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

		pointer base() const

		{
			return (ptr);
		}

		reference operator*() const
		{
			return (reference(*ptr));
		}

		pointer operator->() const
		{
			// return (&ptr);
			return (&(this->operator*()));
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
			// return (&(*ptr)+n);
		}
		iterator operator-(difference_type n) const // not working
		{
			
			return (iterator( ptr - n));        

		}

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
	template <class Iterator>
	class reverse_iterator : public iterator<Iterator>
	{
	protected:
		Iterator current;

	public:
		typedef Iterator iterator_type;
		typedef typename iterator_traits<Iterator>::difference_type difference_type;
		typedef typename iterator_traits<Iterator>::reference reference;
		typedef typename iterator_traits<Iterator>::pointer pointer;
		reverse_iterator()
			: current()
		{
		}
		explicit reverse_iterator(Iterator x)
		{
			current = x;
		}
		pointer base() const
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

	// ft_equal
	template <class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1,
			   InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
			{
				return (false);
			}
			first1++;
			first2++;
		}
		return (true);
	}
	/*if a < b returnn true*/
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
								 InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return (false);
			else if (*first1 < *first2)
				return (true);
			++first1;
			++first2;
		}
		return (first2 != last2);
	}
}; // namespace ft

#endif
