/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:08:00 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/17 11:13:09 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
namespace ft
{
    
class avl_tree
{
    private:
    size_t  height;
    avl_tree * left;
    avl_tree * right;
    public:
    avl_tree() : left(), right() ,height(0)
    {
        std::cout << " avl_tree is called " <<std::endl;
    }
};

}