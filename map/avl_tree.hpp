/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:08:00 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/18 14:39:38 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
/* AVL trees are binary search trees in which the difference between the height of the left and right subtree is either
	-1, 0, or +1.*/
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

	nodes()
		: data(), next_right(NULL), next_left(NULL)
	{
	}

	nodes(T insert_it)
	{
		data = insert_it;
		next_right = NULL;
		next_left = NULL;
	}
	friend std::ostream &operator<<(std::ostream &os, const nodes &dt)
	{
		os << dt.data;
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
		std::cout << "d is called" << std::endl;
	}

	nodes<T> *insert(nodes<T> *r, nodes<T> *new_to_add)
	{
		if (r == NULL)
		{
			r = new_to_add;
			r->next_left = r->next_right = NULL;
			std::cout << "insert root sucessfully" << std::endl;
			return (r);
		}  
        if(new_to_add->data < r->data)
        {
            insert(r->next_left, new_to_add);
        }
        else if(new_to_add->data > r->data)
        {
            insert(r->next_right, new_to_add);
        }           
		return (r);
	}
};

} // namespace ft
