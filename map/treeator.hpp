/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treeator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:39:29 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/27 18:49:20 by atabiti          ###   ########.fr       */
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

  tree_iterator operator--() 
  {
     iter = next_smaller(iter);
    return tree_iterator(iter);
  }
  
  tree_iterator operator--(int) 
  {
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

    tree_iterator tmp(*this);
    ++(*this);
    return tmp;
  }
  
  NODE_PTR next_smaller(NODE_PTR root) 
  {

    if(root->left != NULL)
    {
      while (root->left->right != NULL)
      {
         root->left = root->left->right; 
      }
      
      return root->left ;  
    }


    
  // NODE_PTR tmp = root->parent;
  // while (tmp != NULL  && root == tmp->left)
  // {
  //  root = tmp;
  //   tmp = tmp->parent;
  // }
  //     return tmp;
   if (root == NULL)
      return root;
    while (root != NULL) {

      // std::cout << "value of root is  " << root->value.first << std::endl;
      // std::cout << "value of root parent is  " << root->parent->value.first << std::endl;
      // std::cout << "value of root is  " << root->value.first << std::endl;
      if(root->value.first  < root->parent->value.first)
      {
        
        root = root->parent->parent;
        return root;
      }
      if (root->left == NULL) 
      {
        root = root->parent;
        return root;
      } 
    }
    return root;
  }


  NODE_PTR next_largest(NODE_PTR root) 
  {


    if (root == NULL)
      return root;
    while (root != NULL) {

      // std::cout << "value of root is  " << root->value.first << std::endl;
      if (root->left != NULL &&
          root->left->value.first > root->value.first) {

        root = root->left;
        return root;
      }
      if (root->right == NULL) {
        if (root->parent->right != NULL) 
        {
          if (root->value.first < root->parent->value.first) {
            root = root->parent;
            return root;
          }
          if (root->value.first > root->parent->value.first) {
            root = root->parent->parent;
            return root;
          }
        }
        return root;
      } else if (root->right != NULL) {
        root = root->right;
      }
    }
    return root;
  }
};

template <class tree_iterator>
bool operator==(tree_iterator const &first, tree_iterator const &second) {
  return (first.base() == second.base());
}
template <class tree_iterator>
bool operator!=(tree_iterator const &first, tree_iterator const &second) {
  return (!(first == second));
}

} // namespace ft
