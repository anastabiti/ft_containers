/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:10:35 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/26 12:32:03 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <map>
#include <memory>
// #include <__config>
#include "avl_tree.hpp"
namespace ft {
template <class Key, class T, class Compare = std::less<Key>,
          class Allocator = std::allocator<std::pair<const Key, T> > > //or use  greater

class map {

public:
  typedef Key key_type;
  typedef T mapped_type;
  typedef std::pair<const Key, T> value_type;
  typedef Compare key_compare;
  typedef Allocator allocator_type;
  /*_______________________________________________*/
  typedef ft::avl_tree<value_type, Compare, Allocator> tree_type;
  ft::avl_tree<value_type, Compare, Allocator> a_tree;
  typedef typename tree_type::iterator iterator;

  Allocator M_alloc;
  class value_compare
      : public std::binary_function<value_type, value_type, bool> {
    friend class map;

  protected:
    Compare comp;
    value_compare(Compare c) : comp(c) {}

  public:
    bool operator()(const value_type &x, const value_type &y) const {
      return (comp(x.first, y.first));
    }
  };

  /* Constructs an empty map using the specified comparison object and
   * allocator.  */
  // explicit map(const Compare &comp = Compare(), const Allocator & =
  // Allocator())
  // {
  // 	// std::cout << "map con is called" << std::endl;
  // }

  // std::pair<iterator, bool> insert(const value_type &x)

  void insert(const value_type &x) 
  {
      a_tree.insert(x);
  }

  bool empty() const {
    if (a_tree.root_parent == NULL)
      return true;
    else
      return false;
  }
  void clear() {

    // a_tree.root_parent = NULL;
  }
  iterator begin( ){return a_tree.begin(); }
  // const_iterator begin() const;
  iterator end( ) {return a_tree.end();}
  // const_iterator end() const;

};

} // namespace ft
