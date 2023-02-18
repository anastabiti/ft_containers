/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:29:31 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/18 10:48:27 by atabiti          ###   ########.fr       */
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
    // ft::vector< std::pair <int, int> > vecc;
    // std::vector< int > vecc;
    // size_t  i = 0 ;
    // while (i< 10000000)
    // {
    //     vecc.push_back( i*3);
    //     // vecc.push_back( std::make_pair(i,i*3));
    //     i++;
    // }
    
    // ft::avl_tree<int, std::less<int>, std::allocator<int> > tes;
    // // std::map< int, int> mapp;
    // ft::map< int, int> mapp;
    // size_t x = 0;


    // ft::nodes<int> ff(1212);
    
    // ft::nodes<int> ff1(122);
    
    ft::avl_tree<int, std::less<int> , std::allocator<int> > lst;
    lst.add(32);
    lst.add(2);
    lst.add(3122);
    lst.add(43122);
    lst.printer();
    
    // int f = x;
    // while (x < 10000000)
    // {
        
    //      mapp[f] = f;
    //     x++;
    // }

    // std::cout << "found " << mapp.find(121311)->second<< std::endl;
    
}