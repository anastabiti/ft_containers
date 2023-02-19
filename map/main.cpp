/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:29:31 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/19 13:45:51 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "../vector/vector.hpp"
#include "map.hpp"
#include "avl_tree.hpp"
int main()
{
    ft::map<int, std::less<int> , std::allocator<int> > test;
    ft::avl_tree<int, std::less<int> , std::allocator<int> > tree_avl;
    int val;
    int i   = 0 ;
    // while (i < 5)
    // {

      val = 33;
      ft::nodes<int> * new_node = new ft::nodes<int>();
      new_node->value = val;
      tree_avl.root = tree_avl.insert(tree_avl.root, new_node);      
      val = 43;
      ft::nodes<int> * tr = new ft::nodes<int>();
      tr->value = val;
      tree_avl.root = tree_avl.insert(tree_avl.root, tr);      
      val = 34;
      ft::nodes<int> * tr0 = new ft::nodes<int>();
      tr0->value = val;
      tree_avl.root = tree_avl.insert(tree_avl.root, tr0);      
      
      val = 122;
      ft::nodes<int> * tr1 = new ft::nodes<int>();
      tr1->value = val;
      tree_avl.root = tree_avl.insert(tree_avl.root, tr1);      
      val = 120;
      ft::nodes<int> * tr11 = new ft::nodes<int>();
      tr11->value = val;
      tree_avl.root = tree_avl.insert(tree_avl.root, tr11);      
      val = 40;
      ft::nodes<int> * tr111 = new ft::nodes<int>();
      tr111->value = val;
      tree_avl.root = tree_avl.insert(tree_avl.root, tr111);      
      val = 200;
      ft::nodes<int> * tr1111 = new ft::nodes<int>();
      tr1111->value = val;
      tree_avl.root = tree_avl.insert(tree_avl.root, tr1111);      
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