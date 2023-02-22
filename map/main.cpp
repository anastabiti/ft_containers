/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:29:31 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/22 22:20:19 by atabiti          ###   ########.fr       */
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

    ft::map<int, int> mymap;
    mymap.insert(std::pair< int , int> (1337, 42) );
    mymap.insert(std::pair< int , int> (111, 4132) );
    // mymap.insert(std::pair< int , int> (65, 423111) );
    // std::map<int, int> myma2p;
    // myma2p.insert(std::pair< int , int> (1337, 42) );
    // myma2p.insert(std::pair< int , int> (1337, 42) );
  
    // ft::map<int, std::less<int> , std::allocator<int> > test;
    // ft::avl_tree<int, std::less<int> , std::allocator<int> > tree_avl;
    // int val;
    // int i   = 0 ;
    // // while (i < 5)
    // // {

      // val = 33;
      // ft::nodes<int> * new_node = new ft::nodes<int>();
      // new_node->value = val;
      // tree_avl.root = tree_avl.insert(tree_avl.root, new_node);      
      // val = 43;
      // ft::nodes<int> * tr = new ft::nodes<int>();
      // tr->value = val;
      // tree_avl.root = tree_avl.insert(tree_avl.root, tr);      
      // val = 34;
      // ft::nodes<int> * tr0 = new ft::nodes<int>();
      // tr0->value = val;
      // tree_avl.root = tree_avl.insert(tree_avl.root, tr0);      
      
  

    /*   g*/  
    // tree_avl.print2D(tree_avl.root, 5) ;
    // tree_avl.print2D(tree_avl.root, 5);
    

}