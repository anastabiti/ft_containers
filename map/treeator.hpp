/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treeator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:39:29 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/26 10:19:22 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


namespace ft
{
  
template <class T, class NODE_T> class 
tree_iterator :std::iterator<std::bidirectional_iterator_tag, T>
{

public:
  typedef T value_type;
  typedef typename ft::iterator_traits<T>::pointer pointer;
  typedef typename ft::iterator_traits<T>::reference reference;
  typedef std::bidirectional_iterator_tag iterator_category;
  typedef ptrdiff_t difference_type;
private:
  NODE_T iter;

public:
  tree_iterator() : iter() {}
  explicit tree_iterator(NODE_T a) : iter(a) {}
  
  tree_iterator &operator=(tree_iterator const &  rhs)
  {
    if(this == &rhs)
      return *this;
      this->iter = rhs.iter;
      return *this;
      std::cout << "&operator= is called"<< std::endl;
  }
  
  NODE_T base() const { return this->iter; }
  reference operator*() const { return iter->value; }
  pointer operator->() const 
  {
     return (&iter->value); 
  }
  
    
  
  tree_iterator operator--()
  {
        --iter;
      return (*this);
  }
  tree_iterator operator--(int)
  {
    tree_iterator tmp (*this);
    --(*this);
    return tmp;
    
  }
};

template <class tree_iterator>
  bool operator==(const tree_iterator &first,const  tree_iterator &second)
  {
    return (first.base() == second.base());
  }

}
