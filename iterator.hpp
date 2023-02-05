/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:45:02 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/04 12:48:19 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP
#include <stddef.h>
# include <iterator>
#include "ft_type_traits.hpp"
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
struct	input_iterator_tag
{
};
struct	output_iterator_tag
{
};
struct forward_iterator_tag : public input_iterator_tag
{
};
struct bidirectional_iterator_tag : public forward_iterator_tag
{
};
struct random_access_iterator_tag : public bidirectional_iterator_tag
{
};

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

template <typename Iterator> //the definition of iterator_traits for iterators

struct	iterator_traits
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
	typedef ft::random_access_iterator_tag iterator_category;  
	// no type named 'iterator_category' in 'ft::iterator_traits<int *>'
	//     class reverse_iterator : public iterator<typename iterator_traits<Iterator>::iterator_category, 
                            
};






template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T *, class Reference = T &>
class iterator
//  : public std::iterator<std::random_access_iterator_tag, T>
{
  private:
	T *ptr;

  public:
	typedef T value_type;             //value _type is of type T, the class of objects that the iterator is pointing.
    typedef Distance difference_type; //difference_type has a default value of ptrdiff_t which is used to represent the difference between two iterators.
	typedef Pointer pointer;          //pointer has a default Pointer to type T.
	typedef Reference reference;     
	//reference has a default Reference to type T.
	typedef  Category iterator_category;

	iterator()
	{
		ptr = NULL;
	}


	explicit iterator(pointer vec)
	{
		ptr = vec;
		// std::cout << "    iterator(pointer vec) is called" << std::endl;
	}

	 iterator(const iterator &rhs)//copy
	{
		ptr = rhs.ptr;
	}
	 iterator &operator=(const iterator &rhs)
	{
		if(this == &rhs)
		return *this;
		this->ptr = rhs.ptr;
		return *this;

	}
	~iterator()
	{
	}


	pointer base() const

	{
		return ptr;
	}

	reference operator*() const
	{
		// std::cout <<"iterator operator* is called " << std::endl;
		return (*ptr);
	}

	pointer operator->() const
	{
		// return (&ptr);
		return &(this->operator*());
	}

	/*
        Pre-increment, called for ++ptr
    */
	iterator &operator++()
	{
		// std::cout << "Pre-increment,		called for ++ptr iterator &operator++()" << std::endl;
		++ptr;
		return (*this);
	}
	/*    
            Post-increment
    */
	iterator & operator++(int)
	{
		// std::cout << " Post-increment ,		called for      iterator operator++(int)" << std::endl;
		iterator tmp(*this);
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
		// std::cout << "   1 reference operator[](difference_type n) const  is called" << std::endl;
		return (ptr[n]);
	}

	iterator operator+(difference_type n) //not working
	{
		return (ptr+n);
		// return (&(*ptr)+n);
	}
	iterator operator-(difference_type n) //not working
	{
		// std::cout << "      iterator operator+ (difference_type n) is called" << std::endl;
		// iterator cp(*this);
		// cp -= n;
		// return (*this = *this + n); // cause infinit loop
		// return (*this += n); // cause infinit loop
		// return cp;
		return ptr - n;
	}

	iterator operator+=(difference_type n)
	{
		// std::cout << "	iterator operator+=(difference_type n) is called" << std::endl;
		ptr = ptr + n;
		return (*this);
	}
	iterator & operator-=(difference_type n)
	{
		// std::cout << "	iterator operator-=(difference_type n) is called" << std::endl;
		ptr = ptr - n;
		return (*this);
	}

	friend bool operator==(iterator const &x, iterator const &y)
	{
			std::cout <<" operator==(iterator) is called" << std::endl;

		if (*x == *y)
			return (true);
		else
			return (false);
		// return(x.ptr == y.ptr);
	}

	friend bool operator!=(iterator const &x, iterator const &y)
	{
		// if (*x == *y)
		// 	return (false);
		// else
		// 	return (true);
		return(x.base() != y.base());
	}
	/*relational operators  */
	// friend bool operator== (const iterator& lhs , const iterator& rhs)
	//  {
	// 	std::cout << " operator==  is called base" << std::endl;
	// 	return (lhs  == rhs);
		
	//  }
};





template <class Iterator>
class reverse_iterator : public iterator<typename iterator_traits<Iterator>::iterator_category,
						typename iterator_traits<Iterator>::value_type,
						typename iterator_traits<Iterator>::difference_type,
						typename iterator_traits<Iterator>::pointer,
						typename iterator_traits<Iterator>::reference>
{
  protected:
	Iterator current;

  public:
	typedef Iterator iterator_type;
	typedef typename iterator_traits<Iterator>::difference_type difference_type;
	typedef typename iterator_traits<Iterator>::reference reference;
	typedef typename iterator_traits<Iterator>::pointer pointer;
	reverse_iterator() : current() {}


	    		// std::cout << "    reverse_iterator() is called" << std::endl;
	//     current = NULL;
	// }

	explicit reverse_iterator(Iterator x)
	{
		// std::cout << "       explicit reverse_iterator(Iterator x)  is called" << std::endl;
		current = x;
	}

	// template <class U> reverse_iterator(const reverse_iterator<U>& u);
	// Iterator base() const; // explicit
	reference operator*() const
	{
		return (*current);
	}
	
	pointer operator->() const
	{
		// return &current;
		return current;
	}
	reverse_iterator &operator++()
	{
		// std::cout << "    reverse_iterator& operator++() is called" << std::endl;
		--current;
		return *this;
	}
	reverse_iterator operator++(int)
	{
		// // std::cout << "    reverse_iterator operator++(int)  is called" << std::endl;
		// current--;
		// return *this;
		reverse_iterator tmp(*this);
		++(*this);
		return tmp;
	}
	reverse_iterator &operator--()
	{
		// std::cout << "        reverse_iterator& operator--()  is called" << std::endl;
		++current;
		return *this;
	}
	reverse_iterator operator--(int)
	{
		// std::cout << "           reverse_iterator operator--(int)  is called" << std::endl;
		current++;
		return *this;
	}
	reverse_iterator operator+(difference_type n) const
	{
		// std::cout << "     reverse_iterator operator+ (difference_type n) const  is called" << std::endl;
		// reverse_iterator tmp(*this);
		// tmp = tmp + n;
		return *this +n;
	}
	reverse_iterator &operator+=(difference_type n)
	{
		// reverse_iterator tmp(*this);
		// tmp = tmp + n;
		// return tmp;
		current = current - n;
		return *this;
	}
	// reverse_iterator operator- (difference_type n) const;
	reverse_iterator &operator-=(difference_type n)
	{
		// reverse_iterator tmp(*this);
		// tmp = tmp - n;
		// return tmp;
		return (*this = *this- n);
	}
	reference operator[](difference_type n) const
	{
		// std::cout << "   2 reference operator[](difference_type n) const  is called" << std::endl;
		return current[n]; //will call iterator  operator[]
	}
	reverse_iterator operator- (difference_type n) const
	{
		reverse_iterator cp(*this);
		cp -= n;
		// return (*this = *this + n); // cause infinit loop
		// return (*this += n); // cause infinit loop
		return cp;
	}
};
	/* relational operators */
	template <typename Iterator>
	 bool operator== (const reverse_iterator<Iterator>& lhs , const reverse_iterator<Iterator>& rhs)
	 {
		// std::cout << " operator==  is called for reverse_iterator" << std::endl;
		std::cout <<  *lhs << std::endl;
		std::cout <<  *rhs << std::endl;
		if(&lhs == &rhs)
		{
		// std::cout << " operator==  is called for reverse_iterator" << std::endl;
			
		return true;
		}
			else
		return false;
		// return (&lhs == &rhs);
	 }
	 template <typename Iterator>
	 bool operator!= (const reverse_iterator<Iterator>& lhs , const reverse_iterator<Iterator>& rhs)
	 {
		return (lhs() != rhs());
	 }
	 template <typename Iterator>
	 bool operator< (const reverse_iterator<Iterator>& lhs , const reverse_iterator<Iterator>& rhs)
	 {
		return (lhs() > rhs());//reverse here
	 }
	 template <typename Iterator>
	 bool operator<= (const reverse_iterator<Iterator>& lhs , const reverse_iterator<Iterator>& rhs)
	 {
		return (lhs() >= rhs());//reverse here
	 }
	 template <typename Iterator>
	 bool operator> (const reverse_iterator<Iterator>& lhs , const reverse_iterator<Iterator>& rhs)
	 {
		return (lhs() < rhs());//reverse here
	 }
	 template <typename Iterator>
	 bool operator>= (const reverse_iterator<Iterator>& lhs , const reverse_iterator<Iterator>& rhs)
	 {
		return (lhs() <= rhs());//reverse here
	 }


}; // namespace ft

#endif