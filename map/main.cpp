/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:29:31 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/26 10:50:42 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <map>
#include <vector>
#include <string>
#include <iostream>
// #include "../vector/vector.hpp"
#include "map.hpp"
#include "avl_tree.hpp"
int main()
{
  // std::map<char,int> m1ymap;

  // m1ymap['b'] = 100;
  // m1ymap['a'] = 200;
  // m1ymap['c'] = 300;

  // // show content:
  // for (std::map<char,int>::iterator it=m1ymap.begin(); it!=m1ymap.end(); ++it)
  //   std::cout << it->first << " => " << it->second << '\n';



    std::map<int, int> real_one;
    real_one.insert(std::pair< int , int> (200, 42) );
    real_one.insert(std::pair< int , int> (100, 4132) );
    real_one.insert(std::pair< int , int> (300, 4132) );

    
    std::map<int, int>::iterator it1 =real_one.begin() ;
    std::map<int, int>::iterator it2 =real_one.end();
    it2--;
    std::cout  << "real_one->first " << it1->first << std::endl;
    std::cout  << "end real " << it2->first << std::endl;

    if(it1 == it2)
    {
    std::cout  << "equal"<< std::endl;
      
    }
    ft::map<int, int> mymap;
    mymap.insert(std::pair< int , int> (200, 42) );
    mymap.insert(std::pair< int , int> (100, 4132) );
    mymap.insert(std::pair< int , int> (300, 4132) );
    // mymap.insert(std::pair< int , int> (1, 42) );
    // mymap.insert(std::pair< int , int> (3, 4132) );
    // mymap.insert(std::pair< int , int> (2, 4132) );
    // mymap.insert(std::pair< int , int> (53, 4132) );
    // mymap.insert(std::pair< int , int> (52, 4132) );
    
    // mymap.insert(std::pair< int , int> (30, 4132) );
    // mymap.insert(std::pair< int , int> (20, 4132) );
    // mymap.insert(std::pair< int , int> (40, 4132) );
    // mymap.insert(std::pair< int , int> (1330, 4132) );
    // mymap.insert(std::pair< int , int> (1, 4132) );
    // mymap.insert(std::pair< int , int> (4, 4132) );
    // mymap.insert(std::pair< int , int> (432, 4132) );
    // mymap.insert(std::pair< int , int> (30, 4132) );
    // mymap.insert(std::pair< int , int> (20, 4132) );
    // mymap.insert(std::pair< int , int> (40, 4132) );
    // mymap.insert(std::pair< int , int> (25, 4132) );
    
    // std::cout  << "empty or not " << mymap.empty() << std::endl;
    ft::map<int, int>::iterator it =mymap.begin() ;
    ft::map<int, int>::iterator end_it =mymap.end() ;
    end_it--;
    std::cout  << "it mine " << it->first << std::endl;
    std::cout  << "end_it mine  " << end_it->first << std::endl;
    
    if(it == end_it)
    {
    std::cout  << "equal"<< std::endl;
      
    }
    
    // mymap.insert(std::pair< int , int> (10, 4132) );

    
    // mymap.a_tree.print2D( mymap.a_tree.root_parent , 6);
    // std::cout  << "before ______________________________" << std::endl;

    // mymap.a_tree.remove(mymap.a_tree.root_parent ,std::pair< int , int>         (40, 42) ); 
    // mymap.a_tree.remove(mymap.a_tree.root_parent ,std::pair< int , int> (30, 42) );
    // mymap.a_tree.remove(mymap.a_tree.root_parent ,std::pair< int , int> (10, 42) );
    // mymap.a_tree.remove(mymap.a_tree.root_parent ,std::pair< int , int>         (4, 42) ); 
    


    
    // mymap.a_tree.remove(mymap.a_tree.root_parent ,std::pair< int , int> (20, 42) );
    // mymap.a_tree.remove(mymap.a_tree.root_parent ,std::pair< int , int> (3, 42) );
    // mymap.a_tree.remove(mymap.a_tree.root_parent ,std::pair< int , int> (2, 42) );
    // mymap.a_tree.remove(mymap.a_tree.root_parent ,std::pair< int , int> (1, 42) );
    //
    mymap.a_tree.print2D( mymap.a_tree.root_parent , 6);
    // mymap.erase
    		//  a_tree.print2D(a_tree.root_parent,6);		 

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