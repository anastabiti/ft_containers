/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:08:00 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/22 09:44:45 by atabiti          ###   ########.fr       */
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

template <class T, class Compare, class Allocator >
class avl_tree
{
  public:
	nodes<T*> root;

	Allocator alloc_it;
	typedef Compare compare_type; 

  public:
	avl_tree()
		: root(NULL)
	{
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

	nodes<T*> insert(nodes<T*> root, T x)
	{

		nodes<T*>  new_node = alloc_it.allocate(1);
		alloc_it.construct(new_node.value , x);
		std::cout  << new_node.value->first << std::endl;
		
		if (root.value == NULL)
		{
			root = new_node;
			return (root);
		}

		// if (new_node->value < root->value)
		// {
		// 	root->left = insert(root->left, new_node,x);
		// }
		// else if (new_node->value > root->value)
		// {
		// 	root->right = insert(root->right, new_node,x);
		// }
		// else
		// {
		// 	return (root);
		// }
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
