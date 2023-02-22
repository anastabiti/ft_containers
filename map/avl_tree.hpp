/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:08:00 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/22 22:22:52 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
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
//   typedef std::pair<const Key , T>
	int balance_height;
	T value;
	nodes *right;
	nodes *left;

	nodes()
		: value(), right(NULL), left(NULL)
	{
	}

	nodes(T insert_it): value(insert_it)
	{
		// value = insert_it;
		right = NULL;
		left = NULL;
	}
	friend std::ostream &operator<<(std::ostream &os, const nodes &dt)
	{
		os << dt.value;
		return (os);
	}
};

template <class T, class Compare, class Allocator >
class avl_tree
{
  public:
  
	typedef typename Allocator::template rebind<nodes<T> >::other	rebind_allocator;
	rebind_allocator alloc_it;
	typedef Compare compare_type; 
	typedef nodes<T> node_type; 
	typedef node_type * node_p; 
	node_p  root;


  public:
	avl_tree(): root(NULL)
	{
		// this->root  = alloc_it.allocate(1) ;
		
		// std::cout << "d.c is called" << std::endl;
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
	nodes<T> *left_Rotation(nodes<T> *x)
	{
		nodes<T> *y = x->right;
		nodes<T> *T2 = y->left;
		// std::cout << "root :" << *x << std::endl;
		// std::cout << "y :" << *y << std::endl;
		y->left = x;
		x->right = T2;

		return (y);
	}
	nodes<T> *right_Rotation(nodes<T> *x)
	{
		nodes<T> *y = x->left;
		nodes<T> *T2 = y->right;

		// std::cout << "root :" << *x << std::endl;
		// std::cout << "y :" << *y << std::endl;
		y->right = x;
		x->left = T2;

		return (y);
	}

	node_p insert_a_node(node_p root_node , T x)
	{
		
		if (root_node == NULL)
		{
			node_p new_node = alloc_it.allocate(1);
			alloc_it.construct(&new_node->value , x);
			// alloc_it.construct(new_node , x);
		
			// std::cout  << root_node->value.first << std::endl;
			// std::cout  <<"i am here" << std::endl;
			// std::cout  << root_node.value->second << std::endl;
			root_node = new_node;
			// std::cout << root->value.first << std::endl;
			return (root_node);
		}
		// std::cout  << root_node->value.first << std::endl;

		if (x.first < root_node->value.first)
		{
			root_node->left = insert_a_node(root_node->left,x);
			// std::cout  <<"i am here" << std::endl;
			
			// std::cout << root_node->value.first << std::endl;

		}
		
		else if  (x.first > root_node->value.first)
		{
			// std::cout  <<"i am here" << std::endl;
			root_node->right = insert_a_node(root_node->right,x);
		}
		else
		{
			return (root_node);
		}
	/*
		
		// int left_balance = get_balance_height(root->left);
		// int right_balance = get_balance_height(root->right);
		// int sum = left_balance - right_balance;

		// // std::cout << "sum  = "<< sum << std::endl;

		// if (sum > 1 && new_node->value < root->left->value)
		// {
		// 	// std::cout << "right rotation" << std::endl;
		// 	// std::cout << " root : "<< *root << std::endl;
		// 	return (right_Rotation(root));
		// }

		// if (sum < -1 && new_node->value > root->right->value)
		// {
		// 	// std::cout << "left rotation" << std::endl;
		// 	// std::cout << " root : "<< *root << std::endl;
		// 	return (left_Rotation(root));
		// }

		// if (sum > 1 && new_node->value > root->left->value)
		// {
		// 	// std::cout << "left . right rotation" << sum << std::endl;
		// 	root->left = left_Rotation(root->left);
		// 	return (right_Rotation(root));
		// }

		// if (sum < -1 && new_node->value < root->right->value)
		// {
		// 	// std::cout << " right . left rotation" << sum << std::endl;
		// 	root->right = right_Rotation(root->right);
		// 	return (left_Rotation(root));
		// }
	*/

return root_node;
	}
	
	void insert(T x)
	{
		this->root = insert_a_node(this->root,x);
print2D(root , 5);
	}

	void print2D(node_p r, int space)
	{
		if (r  == NULL) // Base case  1
			return ;
		space += SPACE;           // Increase distance between levels   2
		print2D(r->right, space); // Process right child first 3
		std::cout << std::endl;
		for (int i = SPACE; i < space; i++) // 5
			std::cout << " ";               // 5.1
		std::cout << r->value.first  << "\n";      // 6
		print2D(r->left, space);            // Process left child  7
	}
};

} // namespace ft
