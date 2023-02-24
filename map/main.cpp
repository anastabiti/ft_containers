/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:29:31 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/24 09:03:52 by atabiti          ###   ########.fr       */
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
    // mymap.insert(std::pair< int , int> (44, 42) );
    // mymap.insert(std::pair< int , int> (3, 4132) );
    // mymap.insert(std::pair< int , int> (4, 4132) );
    // mymap.insert(std::pair< int , int> (1, 42) );
    // mymap.insert(std::pair< int , int> (3, 4132) );
    // mymap.insert(std::pair< int , int> (2, 4132) );
    // mymap.insert(std::pair< int , int> (53, 4132) );
    // mymap.insert(std::pair< int , int> (52, 4132) );
    //
    mymap.insert(std::pair< int , int> (30, 4132) );
    mymap.insert(std::pair< int , int> (20, 4132) );
    mymap.insert(std::pair< int , int> (40, 4132) );
    mymap.insert(std::pair< int , int> (10, 4132) );
    
    mymap.a_tree.print2D( mymap.a_tree.root , 6);
    std::cout  << "before ______________________________" << std::endl;
    // mymap.a_tree.remove_a_node(mymap.a_tree.root ,std::pair< int , int> (53, 42) );
    // mymap.a_tree.remove_a_node(mymap.a_tree.root ,std::pair< int , int> (3, 42) );
    // mymap.a_tree.remove_a_node(mymap.a_tree.root ,std::pair< int , int> (2, 42) );
    // mymap.a_tree.remove_a_node(mymap.a_tree.root ,std::pair< int , int> (1, 42) );
    //
    // mymap.a_tree.print2D( mymap.a_tree.root , 6);
    // mymap.erase
    		//  a_tree.print2D(a_tree.root,6);		 

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