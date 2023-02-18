/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:08:00 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/18 11:47:27 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
/* AVL trees are binary search trees in which the difference between the height of the left and right subtree is either -1, 0, or +1.*/

/* //    else if(beg->next_left == NULL && data_to_add < end_last->data)
            //    {
            //         std::cout << "left is NULL  <  data is "<< end_last->data<<  std::endl;
            //         beg->next_left = new_node;
            //         end_last = new_node;
            //    }
            //    else  if(beg->next_right == NULL && data_to_add > end_last->data)
            //    {
            //         std::cout << "beg->next_right == NULL  >  data is "<< end_last->data<< std::endl;
            //         end_last->next_right = new_node;
            //         end_last = new_node;
            //    }
            
*/
#define MAX_difference 1
namespace ft
{

    /* linked list : node */
    template <class T>
    class nodes
    {
    public:
        int balance_height;
        T data;
        nodes *next_right;
        nodes *next_left;

        nodes() : data(), next_right(NULL), next_left(NULL) {}

        nodes(T insert_it)
        {
            data = insert_it;
            next_right = NULL;
            next_left = NULL;
        }
        friend std::ostream &operator<<(std::ostream &os, const nodes &dt)
        {
            os << dt.data;
            return os;
        }
    };

    template <class T, class Compare, class Allocator = std::allocator<T> >
    class avl_tree
    {
        nodes<T> *beg;
        nodes<T> *end_last;
        Allocator alloc_it;
        typedef Compare compare_type;

    public:
        avl_tree() : beg(NULL), end_last(NULL) {}
        void add(T data_to_add)
        {

            nodes<T> *new_node = new nodes<T>;

            new_node->data = data_to_add;
            new_node->next_right = NULL;
            new_node->next_left = NULL;

            if (beg == NULL) // root nodes
            {
                beg = new_node;
                end_last = new_node;
                return ;
            }
           
            nodes<T> *iter = beg;
            while (iter != NULL)
            {
                if (beg->next_left == NULL && data_to_add < iter->data)
                {
                    std::cout << "left is NULL  <  data is " << iter->data << std::endl;
                    beg->next_left = new_node;
                    end_last = new_node;
                    return;
                }
                else if (beg->next_right == NULL && data_to_add > iter->data)
                {
                    std::cout << "beg->next_right == NULL  >  data is " << iter->data << std::endl;
                    end_last->next_right = new_node;
                    end_last = new_node;
                    return;
                }
                if(data_to_add > iter->data)
                iter  =  new_node->next_left;
    
                if(data_to_add < iter->data)
                iter  =  new_node->next_left;
            }
        }

        void printer()
        {
            nodes<T> *iter = beg;

            while (iter != NULL)
            {

                std::cout << iter->data << " left" << std::endl;
                iter = iter->next_left;
            }

            iter = beg;

            while (iter != NULL)
            {

                std::cout << iter->data << " right" << std::endl;
                iter = iter->next_right;
            }
        }
    };

    // template <class T, class Compare, class Allocator>
    // class avl_tree
    // {
    //     private:
    //     size_t  height;
    //     avl_tree * left;
    //     avl_tree * right;
    //     public:
    //     typedef T value_type;
    //     typedef Compare compare_type;
    //     typedef Allocator  allocator_type;

    //     public:
    //     avl_tree() : left(), right() ,height(0)
    //     {
    //         std::cout << " avl_tree is called " <<std::endl;
    //     }
    // };

}