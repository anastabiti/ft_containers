/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:08:00 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/18 12:44:00 by atabiti          ###   ########.fr       */
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

/*
    struct node* insert(struct node *r,int data){
        
        if(r==NULL){
            struct node *n;
            n = new struct node;
            n->data = data;
            r = n;
            r->left = r->right = NULL;
            r->height = 1; 
            return r;             
        }
        else{
            if(data < r->data)
            r->left = insert(r->left,data);
            else
            r->right = insert(r->right,data);
        }

        r->height = calheight(r);

        if(bf(r)==2 && bf(r->left)==1){
            r = llrotation(r);
        }
        else if(bf(r)==-2 && bf(r->right)==-1){
            r = rrrotation(r);
        }
        else if(bf(r)==-2 && bf(r->right)==1){
            r = rlrotation(r);
        }
        else if(bf(r)==2 && bf(r->left)==-1){
            r = lrrotation(r);
        }        

        return r;

        }
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
            public:

        nodes<T> *beg;
        nodes<T> *end_last;
        Allocator alloc_it;
        typedef Compare compare_type;

    public:
        avl_tree() : beg(NULL), end_last(NULL) {}
       nodes<T> * insert( nodes<T> *r,T data_to_add)
            {

            // nodes<T> *new_node = new nodes<T>;
            // new_node->data = data_to_add;
            // new_node->next_right = NULL;
            // new_node->next_left = NULL;
            
        if( r == NULL)
        {
            nodes<T> *new_node = new nodes<T>;
            new_node->data = data_to_add;
            r = new_node;
            r->next_left = r->next_right = NULL;
            beg = r;
            end_last = r;
            return r;             
        }
        else
        {
            
            if(data_to_add < r->data)
            {
                std::cout << "            if(data_to_add < r->data)"   << std::endl;
                r->next_left = insert(r->next_left,data_to_add);
            }
            else
            {
                std::cout << "            if(data_to_add > r->data)"   << std::endl;
                r->next_right = insert(r->next_right,data_to_add);
            }
        }

        
        }

        void printer()
        {
            nodes<T> *iter = beg;
            std::cout << beg->data   << std::endl;

            while (iter != NULL)
            {
                std::cout << iter->data   << std::endl;
                iter = iter->next_left;
            }
            iter = beg;

            while (iter != NULL)
            {

                std::cout << iter->data   << std::endl;
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