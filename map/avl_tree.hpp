/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:08:00 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/18 09:30:23 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
/* AVL trees are binary search trees in which the difference between the height of the left and right subtree is either -1, 0, or +1.*/
#define MAX_difference  1
namespace ft
{

/* linked list : node */
template <class T>
class nodes
{
    public:   
    T data;
    nodes *next;
    nodes(T  insert_it)
    {
        data  =  insert_it;
        next = NULL;   
    }
friend std::ostream& operator<<(std::ostream& os, const nodes& dt)
{
    os  << dt.data;
    return os;
}
};


template <class T>
class linked_list
{
    nodes<T> *head;
    nodes<T> *tail;
    public:
};

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