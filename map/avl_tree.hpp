/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:08:00 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/19 13:07:44 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
/* AVL trees are binary search trees in which the difference between the height of the left and right subtree is either
	-1, 0, or +1.*/
#define MAX_difference 1
#define SPACE 4

namespace ft
{
/* linked list : node */
template <class T>
class nodes
{
  public:
	int balance_height;
	T value;
	nodes *right;
	nodes *left;

	nodes()
		: value(), right(NULL), left(NULL)
	{
	}

	nodes(T insert_it)
	{
		value = insert_it;
		right = NULL;
		left = NULL;
	}
	friend std::ostream &operator<<(std::ostream &os, const nodes &dt)
	{
		os << dt.value;
		return (os);
	}
};

template <class T, class Compare, class Allocator = std::allocator<T> >
class avl_tree
{
  public:
	nodes<T> *root;

	Allocator alloc_it;
	typedef Compare compare_type;

  public:
	avl_tree()
		: root(NULL)
	{
		std::cout << "d.c is called" << std::endl;
	}

	int get_balance_height(nodes<T> *r)
	{
		int i = 0;
		if (r == NULL)
			return (-1);
		else
		{
      
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
 	nodes<T> *left_Rotation(	nodes<T> *x)
	{
			nodes<T>  *y = x->right;
			nodes<T>  *T2 = y->left;
    std::cout << "root :" << *x<< std::endl;
    std::cout << "y :" << *y<< std::endl;
    // std::cout << "T2 :" << *T2<< std::endl;
    
		// Perform rotation
		y->left = x;
		x->right = T2;

		return (y);
	}
 	nodes<T> *right_Rotation(	nodes<T> *x)
	{
			nodes<T>  *y = x->left;
			nodes<T>  *T2 = y->right;


      
    std::cout << "root :" << *x<< std::endl;
    std::cout << "y :" << *y<< std::endl;
    // std::cout << "T2 :" << *T2<< std::endl;
    
		// Perform rotation
		y->right = x;
		x->left = T2;

		return (y);
	}
  
	nodes<T> *insert(nodes<T> *root, nodes<T> *new_node)
	{
		if (root == NULL)
		{
			root = new_node;
			return (root);
		}

		if (new_node->value < root->value)
		{
			root->left = insert(root->left, new_node);
		}
		else if (new_node->value > root->value)
		{
			root->right = insert(root->right, new_node);
		}
		else //duplicate
		{
			return (root);
		}
    int left_balance   = get_balance_height(root->left);
    int right_balance   = get_balance_height(root->right);
    int sum = left_balance - right_balance;
    
    // std::cout << "sum  = "<< sum << std::endl;
    
    if ( sum > 1 && new_node->value < root->left->value) 
    {
      std::cout << "right rotation"<< std::endl;  
      // std::cout << " root : "<< *root << std::endl;  
      		return (right_Rotation(root));
    } 

    if ( sum < -1  && new_node->value > root->right->value) 
    {
      std::cout << "left rotation" << std::endl;  
      // std::cout << " root : "<< *root << std::endl;  
      return left_Rotation(root);
    } 

    if ( sum  > 1  && new_node->value > root->left->value) 
    {
      std::cout << "left . right rotation"<< sum << std::endl; 
      root -> left = left_Rotation(root->left);
		  return (right_Rotation(root));
            
    } 

    if ( sum  < -1  && new_node->value < root->right->value) 
    {
      std::cout << " ( sum  < -1  && new_node->value < root->right->value)  "<< sum << std::endl;      
      root -> right = right_Rotation(root->right);
		  return (left_Rotation(root));
    } 

    
		// int bf = getBalanceFactor(r);
		// // Left Left Case
		// if (bf > 1 && new_node -> value < r -> left -> value)
		//   return (right_Rotation(r));

		// // Right Right Case
		// if (bf < -1 && new_node -> value > r -> right -> value)
		//   return (left_Rotation(r));

		// // Left Right Case
		// if (bf > 1 && new_node -> value > r -> left -> value) {
		//   r -> left = left_Rotation(r -> left);
		//   return (right_Rotation(r));
		// }

		// // Right Left Case
		// if (bf < -1 && new_node -> value < r -> right -> value) {
		//   r -> right = right_Rotation(r -> right);
		//   return (left_Rotation(r));
		// }

		/* return the (unchanged) node pointer */
		return (root);
	}
  

	void print2D(nodes<T> *r, int space)
	{
		if (r == NULL) // Base case  1
			return ;
		space += SPACE;           // Increase distance between levels   2
		print2D(r->right, space); // Process right child first 3
		std::cout << std::endl;
		for (int i = SPACE; i < space; i++) // 5
			std::cout << " ";               // 5.1
		std::cout << r->value << "\n";      // 6
		print2D(r->left, space);            // Process left child  7
	}
};

} // namespace ft
