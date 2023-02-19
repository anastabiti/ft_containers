/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:29:31 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/19 12:00:00 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "../vector/vector.hpp"
// #include "map.hpp"
#include "avl_tree.hpp"
int main()
{
    ft::avl_tree<int, std::less<int> , std::allocator<int> > tree_avl;
    int val;
    int i   = 0 ;
    // while (i < 5)
    // {

      val = 21;
      ft::nodes<int> * new_node = new ft::nodes<int>();
      new_node->value = val;
      tree_avl.root = tree_avl.insert(tree_avl.root, new_node);      
      val = 0;
      ft::nodes<int> * tr = new ft::nodes<int>();
      tr->value = val;
      tree_avl.root = tree_avl.insert(tree_avl.root, tr);      
      val = 1;
      ft::nodes<int> * tr1 = new ft::nodes<int>();
      tr1->value = val;
      tree_avl.root = tree_avl.insert(tree_avl.root, tr1);      
      
      // val = 4;
      // ft::nodes<int> * node1 = new ft::nodes<int>();
      // node1->value = val;
      // tree_avl.root = tree_avl.insert(tree_avl.root, node1);      
      
      // val = 14;
      // ft::nodes<int> * node2 = new ft::nodes<int>();
      // node2->value = val;
      // tree_avl.root = tree_avl.insert(tree_avl.root, node2);      
      
      // val = 44;
      // ft::nodes<int> * node3 = new ft::nodes<int>();
      // node3->value = val;
      // tree_avl.root = tree_avl.insert(tree_avl.root, node3);      


      
      // i++;
    // }


    tree_avl.print2D(tree_avl.root, 5);
    // int he = tree_avl.get_balance_height(tree_avl.root);

}