/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:03:41 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/24 20:46:23 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma  once
#include "../vector/ft_type_traits.hpp"
#include <iostream>
#include <iterator>
#include <stddef.h>
namespace ft {

template <class T, class node_p> 
class tree_iterator {
public:
  typedef node_p  node_ptr;
  typedef T  iterator_type;
  typedef typename ft::iterator_traits<T>::value_type value_type;
  typedef typename ft::iterator_traits<T>::pointer pointer;
  typedef typename ft::iterator_traits<T>::reference reference;
  typedef typename ft::iterator_traits<T>::difference_type difference_type;
  typedef std::bidirectional_iterator_tag tree_iterator_category;

private:
  node_ptr ptr;

public:
/*default constructor,*/
  tree_iterator() : ptr() {}
  /*
  	constructor 
   that takes a pointer :
  std::vector<int>::tree_iterator it2 = std::vector<int>::tree_iterator(&vec[0]);
  */
  explicit tree_iterator(node_ptr vec) { ptr = vec;}

/*
	 a copy constructor for a class template tree_iterator<T>.
  	The constructor takes a const reference to another tree_iterator object U
	 that has a different template parameter U
	 to solve  	ft::vector<int>::const_tree_iterator it_foo =foo.begin()
*/
  template <class U>
  tree_iterator(const tree_iterator<U, node_ptr> &u)  : ptr(u.base())  {}
  

/* Destructor */
  ~tree_iterator() {} 
/*
______________________________________________
The purpose of the base() function is to provide access to the underlying tree_iterator
 or pointer that is stored in the tree_iterator
 _______________________________________________
 The const qualifier at the end of a member function declaration indicates that the 
 function can be called on objects which are themselves const. const member functions
  promise not to change the state of any non-mutable data members 
*/
  node_ptr base() const{
    return (ptr);           }

/* 	dereference operator :
	The dereference operator is represented by the * symbol and is 
	used to access the value pointed to by the tree_iterator or pointer.
	tree_iterator<int> it;
	int x = *it;
	
*/
  reference operator*() const
   { 
	    return (reference(ptr->value.first)); 
  }

};
}