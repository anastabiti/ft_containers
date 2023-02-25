/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:45:02 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/25 13:15:24 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include "ft_type_traits.hpp"
#include "reverse_iterator.hpp"
#include <iostream>
#include <iterator>
#include <stddef.h>
/*: Iterators are used by algorithms to move through containers. T*/
namespace ft {

template <class T> 
class iterator {
public:
  typedef T iterator_type;
  typedef typename ft::iterator_traits<T>::value_type value_type;
  typedef typename ft::iterator_traits<T>::pointer pointer;
  typedef typename ft::iterator_traits<T>::reference reference;
  typedef ptrdiff_t difference_type;
  typedef std::random_access_iterator_tag iterator_category;

private:
  pointer ptr;

public:
/*default constructor,*/
  iterator() : ptr() {}
  /*
  	constructor 
   that takes a pointer :
  std::vector<int>::iterator it2 = std::vector<int>::iterator(&vec[0]);
  */
  explicit iterator(pointer vec) { ptr = vec;}

/*
	 a copy constructor for a class template iterator<T>.
  	The constructor takes a const reference to another iterator object U
	 that has a different template parameter U
	 to solve  	ft::vector<int>::const_iterator it_foo =foo.begin()
*/
  template <class U>
  iterator(const iterator<U> &u)  : ptr(u.base())  {}

/* copy assignment operator
	it1 = it2;
*/
  // iterator &operator=(const iterator &rhs) {
  //   if (this == &rhs)
  //     return (*this);
  //   this->ptr = rhs.ptr;
  //   return (*this);
  // }

/* Destructor */
  ~iterator() {} 
/*
______________________________________________
The purpose of the base() function is to provide access to the underlying iterator
 or pointer that is stored in the iterator
 _______________________________________________
 The const qualifier at the end of a member function declaration indicates that the 
 function can be called on objects which are themselves const. const member functions
  promise not to change the state of any non-mutable data members 
*/
  iterator_type base() const{
    return (ptr);           }

/* 	dereference operator :
	The dereference operator is represented by the * symbol and is 
	used to access the value pointed to by the iterator or pointer.
	iterator<int> it;
	int x = *it;
	
*/
  reference operator*() const { 
	return (reference(*ptr)); }

/*
 overloaded operator->() for the iterator class template. 
 The -> operator is used to access the member variables or member functions of an object 
 through a pointer or an iterator.
  It first takes the address of the ptr member variable 
  using the & operator, and then returns
   that address as a pointer using the pointer typedef.
 */
  pointer operator->() const {
	return (&ptr);           }

/*
                          Pre-increment, 
	calle/
};
// template <class iterator>
// bool operator==(iterator const &x, iterator const &y) {
//   return (x.base() == y.base());
// }


// template <class iterator>
// bool operator!=(iterator const &x, iterator const &y) {
//   return (x.base() != y.base());
// }
// template <class iterator> bool operator<(iterator const &x, iterator const &y) {
//   return (x.base() < y.base());
// }

// template <class iterator>
// bool operator<=(iterator const &x, iterator const &y) {
//   return (x.base() <= y.base());
// }
// template <class iterator> bool operator>(iterator const &x, iterator const &y) {
//   return (x.base() > y.base());
// }
// template <class iterator>
// bool operator>=(iterator const &x, iterator const &y) {
//   return (x.base() >= y.base());
// }
// template <class Iterator>
// typename iterator<Iterator>::difference_type
// operator-(const iterator<Iterator> &x, const iterator<Iterator> &y) {
//   return x.base() - y.base();
// }

// /*  it = it + 3;*/
// template <class Iterator>
// iterator<Iterator> operator+(typename iterator<Iterator>::difference_type n,
//                              const iterator<Iterator> &x) {
//  return iterator<Iterator>(x.base() + n);}

// } // namespace ft
};

}

#endif
