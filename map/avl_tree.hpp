/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:08:00 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/24 09:02:54 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
/* AVL trees are binary search trees in which the difference between the height
   of the left and right subtree is either -1, 0, or +1.*/
#define MAX_difference 1
#define SPACE 4

namespace ft {
/* linked list : node */
template <class T> class nodes {
public:
  //   typedef std::pair<const Key , T>
  int balance_height;
  T value;
  nodes *right;
  nodes *left;

  nodes() : value(), right(NULL), left(NULL) {}

  nodes(T insert_it) : value(insert_it) {
    // value = insert_it;
    right = NULL;
    left = NULL;
  }
  friend std::ostream &operator<<(std::ostream &os, const nodes &dt) {
    os << dt.value;
    return (os);
  }
};

template <class T, class Compare, class Allocator> class avl_tree {
public:
  typedef typename Allocator::template rebind<nodes<T> >::other rebind_allocator;
  rebind_allocator alloc_it;
  typedef Compare compare_type;
  typedef nodes<T> node_type;
  typedef node_type *node_p;
  node_p root;

public:
  avl_tree() : root(NULL) {
    // this->root  = alloc_it.allocate(1) ;

    // std::cout << "d.c is called" << std::endl;
  }

  int get_balance_height(nodes<T> *r) {
    int i = 0;
    if (r == NULL)
      return (-1);
    else {
      int rr = get_balance_height(r->right);
      int l = get_balance_height(r->left);
      // std::cout << "right : " <<rr<< std::endl;
      // // std::cout << "______________________" <<rr<< std::endl;

      // std::cout << "left : " <<l<< std::endl;
      // // std::cout << "______________________" <<rr<< std::endl;
      if (rr > l)
        return (rr + 1);
      else
        return (l + 1);
    }
  }
  nodes<T> *left_Rotation(nodes<T> *x) {
    nodes<T> *y = x->right;
    nodes<T> *T2 = y->left;
    y->left = x;
    x->right = T2;
    return (y);
  }
  nodes<T> *right_Rotation(nodes<T> *x) {
    nodes<T> *y = x->left;
    nodes<T> *T2 = y->right;
    y->right = x;
    x->left = T2;
    return (y);
  }

	node_p min_node(node_p node)
	{
		node_p current = node;
    
		while (current->left != NULL)
		{
			current = current->left;
		}
		return (current);
	}












  
  
  node_p remove_a_node(node_p root_node, T x) 
  {
    if (root_node == NULL)
      return (NULL);
      // return (root_node);

    else if (x.first < root_node->value.first) 
    {
      root_node->left = remove_a_node(root_node->left, x);
    } 
    else if (x.first > root_node->value.first) 
    {
      root_node->right = remove_a_node(root_node->right, x);

    } 
    else 
    {
      if (root_node->left == NULL) 
      {
        node_p tmp = root_node->right;
        alloc_it.destroy(root_node);
        return tmp;

      }
       else if (root_node->right == NULL) 
      {
        node_p tmp = root_node->left;

        alloc_it.destroy(root_node);
        return tmp;
      }
      else
      {
        node_p tmp = min_node(root_node->right);
          root_node->right = tmp;
          root_node->right = remove_a_node(root_node->right, x);
          
      }
      
      
    }

    
    int left_balance = get_balance_height(root->left);
    int right_balance = get_balance_height(root->right);
    int sum = left_balance - right_balance; 
    /* if you reomve a node from the right the balance factor will be always 2 */
    /* if you reomve a node from the left the balance factor will be always - 2 */
    /*
    case 1
    
            [30]                            [30]                                  [2]  
          /     \                            /                                    /   \
        [2]      [40] <- to remove         [2]      -> right_Rotation          [1]   [30]
        /                                  /
      [1]                                [1]

    case 2
    
            [30]                              [30]                                   [20]  
          /     \                            /                                      /   \
        [20]      [40] <- to remove         [20]      -> right_Rotation           [10]   [30]
        /   \                               /   \
      [10]  [25]                          [10]  [25]


    */
     if(root_node->left != NULL && sum == 2 && get_balance_height(root_node->left) >= 0)
    {
      std::cout << "root_node->left " << root_node->left->value.first << std::endl;
      std::cout << "case 1 " << std::endl;
      return right_Rotation(root_node);
    }
    

   
    //  else if(root_node->left != NULL && sum == 2 && get_balance_height(root_node->left) == -1)
    // {
    //   std::cout << " case  2" << std::endl;
    //   root_node->left = left_Rotation(root_node->left); 
    //   return right_Rotation(root_node);
    // }
    
       

       
    // else if(root_node->right != NULL && sum == -2 && get_balance_height(root_node->right) <= -0 )
    // {
    //   std::cout << " case  3" << std::endl;
    //   return left_Rotation(root_node);
    // }
    
 

    // else  if( sum == -2 && get_balance_height(root_node->right) == 1)
    // {
    //   std::cout << "case  4 " << std::endl; 
    //   std::cout <<" value  =" << x.first  <<std::endl;
    //   root_node->right = right_Rotation(root_node->right); 
    //   return left_Rotation(root_node);
    // }

    
  
    return root_node;
  }


























  node_p insert_a_node(node_p root_node, T x) {

    if (root_node == NULL) {
      node_p new_node = alloc_it.allocate(1);
      alloc_it.construct(new_node, x);
      // alloc_it.construct(new_node , x);

      // std::cout  << root_node->value.first << std::endl;
      // std::cout  <<"(root_node == NULL)" << std::endl;
      // std::cout  << root_node.value->second << std::endl;
      root_node = new_node;
      // std::cout << root->value.first << std::endl;
      return (root_node);
    }
    // std::cout  << root_node->value.first << std::endl;

    if (x.first < root_node->value.first) {
      root_node->left = insert_a_node(root_node->left, x);
      // std::cout  <<"( left x.first < root_node->value.first)" << std::endl;

      // std::cout << root_node->value.first << std::endl;

    }

    else if (x.first > root_node->value.first) {
      // std::cout  <<"right (x.first > root_node->value.first)" << std::endl;
      root_node->right = insert_a_node(root_node->right, x);
    } else {
      return (root_node);
    }

    int left_balance = get_balance_height(root->left);
    int right_balance = get_balance_height(root->right);
    int sum = left_balance - right_balance;

    if (sum > 1) {

      if (root_node->left != NULL) {

        if (x.first < root_node->left->value.first) {
          std::cout << "right rotation" << std::endl;
          std::cout << "x.first " << x.first << std::endl;
          std::cout << "root_node->left->value.first  "
                    << root_node->left->value.first << std::endl;
          // std::cout << " root : "<< *root << std::endl;
          return (right_Rotation(root_node));
        }

        if (x.first > root_node->left->value.first) {
          std::cout << "left . right rotation" << sum << std::endl;
          root_node->left = left_Rotation(root_node->left);
          return (right_Rotation(root_node));
        }
      }
    }
    if (sum < -1) {
      if (root_node->right != NULL) {

        if (x.first > root_node->right->value.first) {
          std::cout << "left rotation" << std::endl;
          // std::cout << " root : "<< *root << std::endl;
          return (left_Rotation(root_node));
        }
      }

      if (root_node->right != NULL) {

        if (x.first < root_node->right->value.first) {
          std::cout << " right . left rotation" << std::endl;

          root_node->right = right_Rotation(root_node->right);
          return (left_Rotation(root_node));
        }
      }
    }

    return root_node;
  }

  void insert(T x) { this->root = insert_a_node(this->root, x); }

  void print2D(node_p r, int space) {
    if (r == NULL)
      return;
    space += SPACE;           // Increase distance between levels   2
    print2D(r->right, space); // Process right child first 3
    std::cout << std::endl;
    for (int i = SPACE; i < space; i++)  // 5
      std::cout << " ";                  // 5.1
    std::cout << r->value.first << "\n"; // 6
    print2D(r->left, space);             // Process left child  7
  }
};

} // namespace ft
