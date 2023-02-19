/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:08:00 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/19 08:56:58 by atabiti          ###   ########.fr       */
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

		// int bf = getBalanceFactor(r);
		// // Left Left Case
		// if (bf > 1 && new_node -> value < r -> left -> value)
		//   return (rightRotate(r));

		// // Right Right Case
		// if (bf < -1 && new_node -> value > r -> right -> value)
		//   return (leftRotate(r));

		// // Left Right Case
		// if (bf > 1 && new_node -> value > r -> left -> value) {
		//   r -> left = leftRotate(r -> left);
		//   return (rightRotate(r));
		// }

		// // Right Left Case
		// if (bf < -1 && new_node -> value < r -> right -> value) {
		//   r -> right = rightRotate(r -> right);
		//   return (leftRotate(r));
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
