/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treeator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:39:29 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/27 10:00:58 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "avl_tree.hpp"
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
    iter = next_largest(iter);
   
    return tree_iterator(iter);
  }
  tree_iterator operator++(int)
   {
    
    // std::cout << "iter.first; " << iter->value.first << std::endl;
    tree_iterator tmp(*this);
    ++(*this);
    // std::cout << "iter.first; " << iter->value.first << std::endl;
    return tmp;
  }

NODE_PTR next_largest(NODE_PTR root)
{
   NODE_PTR is_greater = NULL;
   NODE_PTR tmp  = root->parent;

   if(root->right == NULL)
   {
        std::cout  <<"tmp->right == NULL) "<<std::endl; 
        tmp  = root->parent;
      return tmp;
   }
   else if(root->right != NULL)
   {
        std::cout  <<"tmp->right not NULL) "<<std::endl; 
      //   tmp  = root->parent;
      // return tmp;
    //  tmp =   next_largest(root->right);
     tmp =   root->right;
     return tmp;
    
   }
  //  while (root != NULL)
  //  {
  //    if(tmp->value.first >= root->value.first)
  //   {
        std::cout  <<"here "<< root->value.first <<std::endl  <<std::endl; 
        std::cout  <<"tmp  "<<tmp->value.first << std::endl; 
  //     root = root->right;
  //   }
  //   else
  //   {
  //       std::cout  <<"here "<< root->value.first << std::endl; 
  //       std::cout  <<"tmp  "<<tmp->value.first << std::endl; 
  //     is_greater = root;
  //     root = root->left;
  //   }
     
  //  }
  
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
