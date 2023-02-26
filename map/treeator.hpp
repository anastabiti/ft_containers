/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treeator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:39:29 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/26 08:38:07 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


namespace ft
{
  
template <class T, class NODE_T> class 
tree_iterator {

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
  tree_iterator(NODE_T a) : iter(a) {}
  NODE_T base() const { return this->iter; }
  reference operator*() const { return iter->value; }
  pointer operator->() const { return (&iter->value); };
};

}
