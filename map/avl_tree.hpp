/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:08:00 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/17 11:17:42 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
namespace ft
{

template <class T, class Compare, class Allocator>
class avl_tree
{
    private:
    size_t  height;
    avl_tree * left;
    avl_tree * right;
    public:
    typedef T value_type;
    typedef Compare compare_type;
    typedef Allocator  allocator_type;
    
    public:
    avl_tree() : left(), right() ,height(0)
    {
        std::cout << " avl_tree is called " <<std::endl;
    }
};

}