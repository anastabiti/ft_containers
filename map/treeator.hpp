/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treeator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:39:29 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/26 12:26:09 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft {

template <class T, class NODE_PTR> class tree_iterator {

public:
  typedef T value_type;
  typedef typename ft::iterator_traits<T>::pointer pointer;
  typedef typename ft::iterator_traits<T>::reference reference;
  typedef std::bidirectional_iterator_tag iterator_category;
  typedef ptrdiff_t difference_type;

private:
  NODE_PTR iter;

public:
  tree_iterator() : iter() {}
  explicit tree_iterator(NODE_PTR a) : iter(a) {}

  tree_iterator &operator=(tree_iterator const &rhs) {
    if (this == &rhs)
      return *this;
    this->iter = rhs.iter;
    return *this;
    std::cout << "&operator= is called" << std::endl;
  }

  NODE_PTR base() const { return this->iter; }
  reference operator*() const { return iter->value; }
  pointer operator->() const { return (&iter->value); }

  tree_iterator operator--() {
    --iter;
    return (*this);
  }
  tree_iterator operator--(int) {
    tree_iterator tmp(*this);
    --(*this);
    // std::cout << "iter.first; " << iter->value.first << std::endl;
    return tmp;
  }
  tree_iterator operator++() 
  {
    // std::cout << "iter.first; " << iter->value.first << std::endl;
    ++iter;
    return (*this);
  }
  tree_iterator operator++(int)
   {
    
    // std::cout << "iter.first; " << iter->value.first << std::endl;
    tree_iterator tmp(*this);
    ++(*this);
    // std::cout << "iter.first; " << iter->value.first << std::endl;
    return tmp;
  }
  
};

template <class tree_iterator>
bool operator==( tree_iterator const &first,  tree_iterator const &second) {
  return (first.base() == second.base());
}
template <class tree_iterator>
bool operator!=( tree_iterator const &first,  tree_iterator const & second)
{
  return  (!(first == second));
}

} // namespace ft
